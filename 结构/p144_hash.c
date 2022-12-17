#include <stdio.h>
#include "utils/hash.h"

int main() {
  install("TMP", "1");
  struct nlist* p = lookup("TMP");
  if (p != NULL) {
    printf("name: %s, defn: %s\n", p->name, p->defn);
  }
  p = lookup("TMP2");
  if (p == NULL) {
    printf("name: TMP2, not found\n");
  }
  return 0;
}
