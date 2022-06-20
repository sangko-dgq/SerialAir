

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

   

