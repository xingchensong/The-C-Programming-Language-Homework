#include "utils/tree.h"

int main() {
  struct tnode* root = NULL;
  char word[MAXWORD];
  while (getword(word) != EOF) {
    if (isalpha(word[0])) root = addtree(root, word);
  }
  treeprint(root);
  return 0;
}
