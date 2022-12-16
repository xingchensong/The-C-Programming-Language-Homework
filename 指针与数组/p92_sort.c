#include "utils/p92_sort.h"

int main(int argc, char *argv[]) {
  // 一维数组和指针数组
  int A[13];    // A是个数组，包含13个int元素
  int *a[13];    // a是个数组，包含13个指向int类型的指针
  int (*b)[13];  // b是个指针，指向包含13个int的数组, b[i] == *(a[i])
  int* c;        // c是个指针，指向包含?个int的数组,  c[i] == b[i]
  // 二维数组和指针数组
  int D[13][14]; // D[3][4] 和 e[3][4] 都是对一个int对象的合法引用，
  int *e[13];    // 但D是个真正的二维数组, e中只是声明了13个指针，并没有分配
                 // 对应的空间，需要显示初始化. e相比D的优势是第二维长度不一定必须得是14
                 // 根据这个特性，指针数组通常用来存某些固定但长度不一的字符串

  int nlines;
  int numeric = 0;
  if (argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    // 这里对lineptr和numcmp都要做相应的指针类型转换
    // (void**) 将 lineptr 从 char** 转换为 void**
    // (int (*)(void*, void*)) 将 strcmp 从 (int (*)(char*, char*)) 转换为 (int (*)(void*, void*))
    my_qsort((void**) lineptr, 0, nlines - 1, (numeric ? numcmp : (int (*)(void*, void*))strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}
