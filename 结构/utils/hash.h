// Copyright [2022-12-17] <sxc19@mails.tsinghua.edu.cn, Xingchen Song>

#ifndef HASH_H_
#define HASH_H_

#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
  struct nlist* next;
  char* name;
  char* defn;
};

unsigned hash(char* s);
struct nlist* lookup(char* s);
struct nlist* install(char* name, char* defn);

#endif  // HASH_H_
