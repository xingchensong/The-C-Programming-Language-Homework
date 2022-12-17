#include "utils/hash.h"

// 只有本文件内能访问hashtable
static struct nlist* hashtable[HASHSIZE];

unsigned hash(char* s) {
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31 * hashval;
  }
  return hashval % HASHSIZE;
}

struct nlist* lookup(char* s) {
  struct nlist* np;
  for (np = hashtable[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np;
    }
  }
  return NULL;
}

struct nlist* install(char* name, char* defn) {
  struct nlist* np = lookup(name);
  if (np == NULL) {
    np = (struct nlist*)malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL) {
      return NULL;
    }
    unsigned hashval = hash(name);
    // 头插法
    np->next = hashtable[hashval];
    hashtable[hashval] = np;
  } else {
    free((void*)np->defn);
  }
  if ((np->defn = strdup(defn)) == NULL) {
    return NULL;
  }
  return np;
}
