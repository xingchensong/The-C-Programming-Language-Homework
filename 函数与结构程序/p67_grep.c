// Copyright [2022-11-09] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
  for (int i = 0; i < strlen(source); ++i) {
    if (source[i] != searchfor[0]) continue;
    for (int j = 0; j < strlen(searchfor); ++j) {
      if (source[i + j] != searchfor[j]) break;
      if (j == strlen(searchfor) - 1) return i;
    }
  }
  return -1;
}

// https://www.zhihu.com/question/21923021/answer/1032665486
int strindexKMP(char source[], char searchfor[]) {
  // build next
  int* next = (int *)malloc(sizeof(int) * strlen(searchfor));
  next[0] = 0;
  int p1, p2 = 1;  // assume p1 always == next[p2 - 1], 是为了方便递推
  p1 = next[p2 - 1];
  while (p2 < strlen(searchfor)) {
    if (searchfor[p1] == searchfor[p2]) {
      next[p2] = p1 + 1;
      p1++; p2++;
    } else if (p1 > 0) {
      p1 = next[p1 - 1]; // 缩小范围
    } else {
      next[p2] = 0;
      p1 = 0; p2++;
    }
  }
  // search
  int p_src = 0, p_search = next[p_src];
  while (p_src < strlen(source)) {
    if (source[p_src] == searchfor[p_search]) {
      if (p_search == strlen(searchfor) - 1) return p_src;
      p_src++; p_search++;
    } else if (p_search > 0) {
      p_search = next[p_search - 1];
    } else {
      p_src++; p_search = 0;
    }
  }
  return -1;
}

char pattern[] = "OULD";

int main () {
  char line[MAXLINE];
  int found = 0;
  while (my_getline(line, MAXLINE) > 0) {
    int idx = strindexKMP(line, pattern);
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
