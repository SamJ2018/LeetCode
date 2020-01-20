/*
1、C和C++ struct区别
C  无保护行为   不可定义函数，但有函数指针
C++  默认私有    

2、struct和class区别
 （1）默认继承权限 class是private继承  struct是public继承
 （2）class成员默认是private，struct是public权限
 其它本质一样

 3、判断程序c编译程序还是c++编译程序
    #ifdef __cplusplus
        cout<<"c++"
    #else
        cout<<" "
    #endif 

4、C++与C  ：结构化编程语言与面向对象编程语言

5、指针和引用：
    引用是变量的别名

    （1）引用一定要初始化，指针不必。
    （2）引用初始化以后不能被改变，指针可以改变所指的对象。
    （3）不存在指向空值的引用，但是存在指向空值的指针
*/