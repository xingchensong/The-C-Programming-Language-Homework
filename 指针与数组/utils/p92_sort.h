// Copyright [2022-12-16] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#ifndef P92_SORT_H_
#define P92_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
// 使用void类型参数/指针是因为void*是通用类型指针
// 任何其他类型都可以转换为void*且不会丢失信息
// 这时候qsort可以处理任何类型的数据（int/float/double）
void my_qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(void *, void *);

#endif  // P92_SORT_H_
