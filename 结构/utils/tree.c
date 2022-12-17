#include "utils/tree.h"

struct tnode* talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

char* my_strdup(char* s) {
  char* p;
  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL) strcpy(p, s);
  return p;
}

struct tnode* addtree(struct tnode* p, char* w) {
  if (p == NULL) {
    p = talloc();
    p->word = my_strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
    return p;
  }
  int cond = strcmp(w, p->word);
  if (cond == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }
  return p;
}

void treeprint(struct tnode* p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}
