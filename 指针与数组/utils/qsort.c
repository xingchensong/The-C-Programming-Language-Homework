#include "utils/p92_sort.h"

int numcmp(void* s1, void* s2) {
  double v1, v2;
  v1 = atof((char*) s1);
  v2 = atof((char*) s2);
  if (v1 < v2) return -1;
  else if (v1 > v2) return 1;
  else return 0;
}

// 注意交换的是指针不是指针指向的内容
void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i]; v[i] = v[j]; v[j] = temp;
}

void my_qsort(void* v[], int left, int right, int (*comp)(void*, void*)) {
  if (left >= right) return;
  // 选取中间点作为比对值的基准，相比第一个点平均速度会更快
  // 将整个数组分为比基准小和比基准大两个分组
  swap(v, left, (left + right) / 2);
  int partition = left + 1;
  for (int i = left + 1; i <= right; ++i) {
    if ((*comp)(v[i], v[left]) < 0) {
      swap(v, partition, i);
      partition++;
    }
  }
  swap(v, left, partition - 1);
  my_qsort(v, left, partition - 2, comp);
  my_qsort(v, partition, right, comp);
}
