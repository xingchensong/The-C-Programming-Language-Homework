// Copyright [2022-11-09] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char s[], int lim) {
  int c, i = 0;
  while ((c = getchar()) != EOF) {
    s[i++] = c;
    lim--;
    if (c == '\n' || lim == 0) break;
  }
  s[i] = '\0';  // 字符串末尾必须是\0表示结束
  return i;
}

int strindex(char source[], char searchfor[]) {
  for (int i = strlen(source) - 1; i >= 0; --i) {
    if (source[i] != searchfor[strlen(searchfor) - 1]) continue;
    for (int j = 0; j < strlen(searchfor); ++j) {
      if (source[i - j] != searchfor[strlen(searchfor) - 1 - j]) break;
      if (j == strlen(searchfor) - 1) return i;
    }
  }
  return -1;
}

char pattern[] = "OULD";

int main () {
  char line[MAXLINE];
  int found = 0;
  while (my_getline(line, MAXLINE) > 0) {
    int idx = strindex(line, pattern);
    if (idx >= 0) {
      printf("%s", line);
      for (int i = 0; i < strlen(line) - 1; ++i) {
        if (i != idx) printf("-");
        else printf("*");
      }
      printf("\n");
      found++;
    }
  }
  return found;
}
