// Copyright [2022-10-15] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>

void strcat(char* s, char* t) {
  size_t idx_s = 0, idx_t = 0;
  while (s[idx_s] != '\0') idx_s++;
  while (t[idx_t] != '\0') {
    s[idx_s++] = t[idx_t++];
  }
}

int main() {
  char s[10] = "12345";
  char t[5] = "9876";
  strcat(s, t);
  printf("12345 + %s = %s\n", t, s);
  return 0;
}
