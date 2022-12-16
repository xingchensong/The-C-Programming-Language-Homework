#include "utils/p92_sort.h"

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

void afree(char* p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;
  }
}

int my_getline(char s[], int lim) {
  int i = 0;
  char c;
  while (--lim > 0 && (c = getchar()) != EOF) {
    s[i++] = c;
    if (c == '\n') {
      break;
    }
  }
  s[i] = '\0';
  return i;
}

int readlines(char* lineptr[], int maxlines) {
  int len;
  char *p, line[MAXLEN];
  int nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0) {
    if (nlines >= MAXLINES || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char* lineptr[], int nlines) {
  for (int i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}
