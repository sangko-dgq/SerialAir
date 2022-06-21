

1.  哪里emit ,哪里就是sender, 不管是发送的哪里的信号。 例如以下写法：
    
    ```c++
      emit A::sg_test();
      emit m_A->sg_test();
      emit m_A.sg_test();
    ```
    
     ❌不是表示**发送** A 里面的sg_test()信号！！！
     ✔️ 你可以理解为：**取**A 里面的sg_test()信号。
    ❗那么,在connect的时候，sender为emit所在的sender，而不是A为sender
    
    

2. connect SIGNAL(,.,) 写法。，可以根据sender自动找到信号。 emit地方才应写明从哪取的信号。

   ```
   // 错误写法
   connect(&Singleton<bridge>::getInstance(),
           SIGNAL(Singleton<bridge>::getInstance().sg_ui_openPortOK()),
           this,
           SLOT(st_ui_openPortOK()));
   //正确     
   connect(&Singleton<bridge>::getInstance(),
           SIGNAL(sg_ui_openPortOK()), //在this 和 &Singleton<bridge>::getInstance()里面自动寻找sg_ui_openPortOK()
           this,
           SLOT(st_ui_openPortOK()));  //在this里面寻找st_ui_openPortOK()
   ```

​    emit 

​    

```c++
emit Singleton<bridge>::getInstance().sg_ui_openPortOK();
```



3. 声明成员变量后要在cpp里面实例化（new），建议在构造函数里面实例化。

4. 报错：对非静态成员引用必须与特定对象相对

   意思就是引用非静态成员前应该先声明该类的对象。
   比如类A这样定义

   ```c++
   class A
   {
   private:
   int n;
   }
   ```

   要使用n就要先这样声明A的对象

   ```c++
   A a;
   a.n=1
   ```

   

5.报错：QObject::moveToThread: Widgets cannot be moved to a new thread

原因分析：UI控件不能移入新线程（继承了QWidgets）
只有继承QOject才能moveToThread，也就是说不能用子线程，要将其从QWidget改为变为QObject



6.

```
  /*当线程开启, 执行模型层的测试槽函数*/
    /*这里started信号参数和st_openPort不一致，不能绑定，需要再创建一个中间槽函数来实现*/
    /*
     * 中转方式-1
     * 线程started()信号触发model里的slot;
     * 注意：由于Strated无参数，基于Qt信号与槽绑定法则（信号参数个数 >= 槽参数个数）
     * 故该方式，仅仅适合无参数的槽函数
     *以下写法会报错
     */
    //    connect(m_openPortThread,
    //            SIGNAL(started()),
    //            m_serialModel,
    //            SLOT(st_openPort(QSerialPortInfo, int, QSerialPort::DataBits, QSerialPort::Parity, QSerialPort::StopBits)));

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
```
