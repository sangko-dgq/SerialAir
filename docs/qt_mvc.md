1.  **Model 层应该足够纯净**。

   以下情况不纯净，得修改：

   model里面出现connect

   发送的信号依赖与别的层。

   ```
   emit Singleton<bridge>::getInstance().sg_done_model_openPort();
   ```

​        

2. 在开启线程函数中，connect应该放在前面初始化。防止先进入了model里面的槽函数，而model里的槽函数要发送回传信号，会导致无法接收，原因就是因为还没来得及connect该回传信号。

   **错误写法**，导致没有执行最后两个connect，从而导致model层的sg_done_model_openPort信号emit失败。

   ```c++
   /*串口线程*/
   void bridge::st_bridge_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
   {
       /*新建支线程*/
       m_openPortThread = new QThread;
       m_serialModel = new serialModel;
       m_serialModel->moveToThread(m_openPortThread);
   
       /*开启支线程*/
       qDebug() << "[Bridge] Start Serial Thread...";
       m_openPortThread->start();
   
       /*当线程开启, 跳到模型层执行模型层的测试槽函数*/
       /*
        * 中转方式-2
        * 如果判断线程是否Running（线程start成功就Running），来直接调用model里的slot;
        * 适合无参数/有参数的槽函数
        */
       if (!m_openPortThread->isRunning())
           return;
   
       qDebug() << "[Bridge] m_openPortThread is Running...";
   
       qDebug() << "[Bridge] Call model : openPort...";
       m_serialModel->openPort(portInfo, baudRate, dataBits, parity, stopBits);
       
       
       /*模型层的测试槽函数执行完成,执行退出线程槽函数*/
       connect(this, SIGNAL(sg_done_model_openPort(bool)), this, SLOT(st_bridge_returnOpenPortRes(bool)));
       /*当线程完成(已经完成退出线程),*/
       /*当线程完成(线程已经退出)-自动销毁线程*/
       connect(m_openPortThread, SIGNAL(finished()), m_openPortThread, SLOT(deleteLater()));
   
   }
   
   ```

正确写法：

```
/*串口线程*/
void bridge::st_bridge_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{


    /*------------------------------------------线程初始化和Connect----------------------------------------*/
    /*新建支线程*/
    m_openPortThread = new QThread;
    m_serialModel = new serialModel;
    m_serialModel->moveToThread(m_openPortThread);

    /*模型层的测试槽函数执行完成,执行退出线程槽函数*/
    connect(this, SIGNAL(sg_done_model_openPort(bool)), this, SLOT(st_bridge_returnOpenPortRes(bool)));
    
    /*当线程完成(已经完成退出线程),*/
    /*当线程完成(线程已经退出)-自动销毁线程*/
    connect(m_openPortThread, SIGNAL(finished()), m_openPortThread, SLOT(deleteLater()));


     /*-----------------------------------------线程开启----------------------------------------*/
    qDebug() << "[Bridge] Start Serial Thread...";
    m_openPortThread->start();

    /*当线程开启, 跳到模型层执行模型层的测试槽函数*/
    /*
     * 中转方式-2
     * 如果判断线程是否Running（线程start成功就Running），来直接调用model里的slot;
     * 适合无参数/有参数的槽函数
     */
    if (!m_openPortThread->isRunning())
        return;

    qDebug() << "[Bridge] m_openPortThread is Running...";

    qDebug() << "[Bridge] Call model : openPort...";
    m_serialModel->openPort(portInfo, baudRate, dataBits, parity, stopBits);

}

```