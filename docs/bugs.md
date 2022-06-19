

1.  哪里emit ,哪里就是sender, 不管是发送的哪里的信号。 例如以下写法：
    
    ```c++
      emit A::sg_test();
      emit m_A->sg_test();
      emit m_A.sg_test();
    ```
    
     ❌不是表示**发送** A 里面的sg_test()信号！！！
     ✔️ 你可以理解为：**取**A 里面的sg_test()信号。
    ❗那么,在connect的时候，sender为emit所在的sender，而不是A为sender
    
    

