// Copyright [2022-12-17] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char* word;
  int count;
  struct tnode* left;
  struct tnode* right;
};

int getword(char *);
char* my_strdup(char* s);
struct tnode* talloc(void);
struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode* p);

#endif  // TREE_H_
