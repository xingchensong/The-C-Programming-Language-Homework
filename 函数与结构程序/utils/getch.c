#include <stdio.h>
#include "utils/calc.h"

// 1. static表明buf和bufp只能被本文件中的getch 和 ungetch访问
//   从而达到在别的文件中隐藏这些变量的目的 (别的文件中的函数不应该有权限访问他俩)
// 2. 其他文件可以定义同名变量buf和bufp，因为其他文件反正也访问不了这里的buf bufp
// 3. static也可以用于声明函数getch，同理其他文件无法使用这个函数
// 4. static也可以用在声明函数内的内部变量，这时他和普通的局部变量相比不同点是
//    不管其所在的函数是否被调用，他一直存在，而不像自动变量哪样，随着所在函数
//    的被调用和退出而存在和消失。换句话说，被static修饰的内部变量是一种只能在
//    某个特定函数中使用但一直占据存储空间的变量,这常见于静态类成员函数/变量，
//    保证无论创建多少个类的对象，静态成员都只有一个副本。静态成员在类的所有对象中是共享的。
//    如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
//    我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
static char buf[BUFSIZE];
static int bufp = 0;

// 实际上getchar的返回值应该是 int (因为EOF是-1), 这里返回char不报错原因是char 是 signed (我的编译器认为是signed，换别人的可能就是unsigned)
// https://blog.csdn.net/lonfee88/article/details/7542641
// https://stackoverflow.com/questions/1437241/endoffile-in-c-eof
char getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
  if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
  else buf[bufp++] = c;
}
