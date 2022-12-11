// Copyright [2022-12-10] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#ifndef CALC_H_
#define CALC_H_

// 之所以要单抽出来一个头文件放全局共享变量/函数，是为了尽可能
// 把共享的部分集中在一起，这样只需include一次头文件，而不需要在不同文件中
// 多次进行某个函数的声明（注意不是定义）
//
// 对于某些中等规模的程序，最好只用一个头文件存放程序中各个部分共享的对象

#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100
void push(double);
double pop(void);
char getop(char []);
char getch(void);
void ungetch(char);

#endif  // CALC_H_
