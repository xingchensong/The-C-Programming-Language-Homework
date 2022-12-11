#include <stdio.h>
#include <ctype.h>
#include "utils/calc.h"

char getop(char s[]) {
  char c = getch(), op;
  // digit
  int idx = 0;
  int number = 0;
  while (isdigit(c) || c == '.') {
    s[idx++] = c;
    c = getch();
    number = 1;
  }
  s[idx++] = '\0';
  // op
  if (number) op = NUMBER;
  else {
    op = c;
    // 过滤衔接的space, 这里为了方便限定有且必须有一个空格，不能没有空格或者有多个空格
    c = getch();
    // 压回超前多读的字符, 主要是最后一个 \n, 方便上层的main退出
    // 遇到c == ' '不回退，因为目的就是为了过滤space
    // 在逆波兰表达式中，\n前面一定是一个算符，不可能是数字!
    if (c == '\n') ungetch(c);
  }
  return op;
}
