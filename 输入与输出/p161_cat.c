#include <stdio.h>
#include <stdlib.h>

// 
void filecopy(FILE* ifp, FILE* ofp) {
  int c = getc(ifp);
  while (c != EOF) {
    putc(c, ofp);
    c = getc(ifp);
  }
}

int main(int argc, char *argv[]) {
  FILE* fp;
  char* prog = argv[0];
  if (argc == 1) {
    // stdin stdout stderr 可以认为是一种特殊的FILE*, 他们是常量，不是变量
    // 因此不能对他们赋值（而fp作为变量 FILE*，就是可以赋值的）
    filecopy(stdin, stdout);
  } else {
    while (--argc > 0) {
      // FILE* fopen(char* name, char* mode)
      // int fclose(FILE *fp)
      fp = fopen(*(++argv), "r");
      if (fp == NULL) {
        // int fscanf(FILE* fp, char* format, ...)
        // int fprintf(FILE* fp, char* format, ...)
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      } else {
        filecopy(fp, stdout);
        fclose(fp);
      }
    }
  }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}
