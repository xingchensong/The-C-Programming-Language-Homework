// Copyright [2022-10-15] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 2000000
#define FIND 800

int bisearch(int* arr, int x, int len) {
  int low = 0, mid = 0, high = len - 1;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int bisearch_optimized(int* arr, int x, int len) {
  int low = 0, mid = 0, high = len - 1;
  // 111000
  while (low != high) {
    mid = (low + high + 1) >> 1;
    if (arr[mid] <= x) low = mid;
    else high = mid - 1;
  }
  return arr[low] == x ? low : -1;
}

int comp(const void*  a, const void* b) { return *(int*)a > *(int*)b; }

int main() {
  int arr[MAX];
  for (size_t i = 0; i < MAX; ++i) {
    arr[i] = i;
  }
  long start = clock();
  int idx = bisearch(arr, FIND, MAX);
  long end = clock();
  printf("original, num: %d, index: %d, duration: %ldms\n",
         arr[idx], idx, (end - start));
  start = clock();
  idx = bisearch_optimized(arr, FIND, MAX);
  end = clock();
  printf("optimized, num: %d, index: %d, duration: %ldms\n",
         arr[idx], idx, (end - start));
  return 0;
}
