#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils/calc.h"

#define MAXTOKEN 100

enum {NAME, PARENS, OPTIONAL_SIZE};

// 下面的全局变量是gettoken dcl dirdcl 三个函数相互沟通的媒介和桥梁
int tokentype;
char optional_size[MAXTOKEN];  // [optional size]
char name[MAXTOKEN];  // var name
char out[1000];

int gettype(char* p) {
  int c = getch();
  while (isalpha(c)) {
    *p = c; c = getch(); p++;
  }
  *p = '\0';
  ungetch(c);
  return c;
}

void gettoken(void) {
  int c = getch();
  while (c == ' ' || c == '\t') c = getch();
  if (c == '(') {
    c = getch();
    if (c == ')') {
      tokentype = PARENS;
    } else {
      ungetch(c);
      tokentype = '(';
    }
  } else if (c == '[') {
    char* p = optional_size;
    while (c != ']') {
      *p = c; c = getch(); p++;
    }
    *p = c; p++; *p = '\0';
    tokentype = OPTIONAL_SIZE;
  } else if (isalpha(c)) {
    char* p = name;
    while (isalnum(c)) {
      *p = c; c = getch(); p++;
    }
    *p = '\0';
    ungetch(c);
    tokentype = NAME;
  } else {
    // EOF, '\n', *, ')'
    tokentype = c;
  }
  return;
}

// dcl:        optional *'s direct-dcl, 指前面带有多个*的direct-dcl
// direct-dcl: name
//             (dcl)
//             direct-dcl()
//             direct-dcl[optional size]
// 因为dcl和direct-dcl 你中有我我中有你，所以两者互相递归调用

void dcl(void);
void dirdcl(void);

void dcl(void) {
  int num_star = 0;
  gettoken();
  while (tokentype == '*') {
    num_star++;
    gettoken();
  }
  dirdcl();
  while (num_star > 0) {
    strcat(out, " pointer to");
    num_star--;
  }
}

void dirdcl(void) {
  if (tokentype == NAME) {
    // do nothing
  } else if (tokentype == '(') {
    dcl();
    // 处理完后 tokentype必是 ')'
    if (tokentype != ')') printf("error: missing )\n");
  } else {
    printf("error: expected name or (dcl)\n");
  }
  // get next token, 处理结尾部分的 () 或者 [optional size]
  // 这部分和dcl没关系，所以没有递归调用
  gettoken();
  while (tokentype == PARENS || tokentype == OPTIONAL_SIZE) {
    if (tokentype == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, optional_size);
      strcat(out, " of");
    }
    gettoken();
  }
}

int main() {
  // int, char, float ...
  char type[20] = "test";
  // start dcl
  while (gettype(type) != EOF) {
    out[0] = '\0';
    dcl();
    if (tokentype != '\n') printf("syntax error, tokentype: %c\n", tokentype);
    printf("%s: %s %s\n", name, out, type);
  }
  return 0;
}
