// Copyright [2022-10-15] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>

int atoi(char* s) {
  int num = 0;
  for (size_t i = 0; s[i] <= '9' && s[i] >= '0'; ++i) {
    num = num * 10 + (s[i] - '0');
  }
  return num;
}

int main() {
  char s[10] = "987654321";
  printf("\"%s\": %d\n", s, atoi(s));
  return 0;
}
