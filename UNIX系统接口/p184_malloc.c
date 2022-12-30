#include <stdio.h>
#include <stddef.h>

#define NALLOC 1024

typedef long Align;
union header {
  struct {
    union header* ptr;
    unsigned size;
  } s;
  Align x;
};
typedef union header Header;

static Header base;
static Header* freep = NULL;

void my_free(void* ap) {
  Header* bp = (Header*)ap - 1;
  Header* p;
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
      break;
    }
  }
  if (bp + bp->s.size == p->s.ptr) {
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else {
    bp->s.ptr = p->s.ptr;
  }
  if (p + p->s.size == bp) {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else {
    p->s.ptr = bp;
  }
  freep = p;
}

static Header* morecore(unsigned nu) {
  if (nu < NALLOC) {
    nu = NALLOC;
  }
  char* sbrk(int);
  char* cp = sbrk(nu * sizeof(Header));
  if (cp == (char*)-1) {
    return NULL;
  }
  Header* up = (Header*)cp;
  up->s.size = nu;
  my_free((void*)(up + 1));
  return freep;
}

void* my_malloc(unsigned nbytes) {
  Header *p, *prevp;
  unsigned nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {
      if (p->s.size == nunits) {
        prevp->s.ptr = p->s.ptr;
      } else {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if (p == freep) {
      if ((p = morecore(nunits)) == NULL) {
        return NULL;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  printf("sizeof(int): %ld\n", sizeof(int));
  printf("sizeof(Header): %ld\n", sizeof(Header));

  int nbytes = 1 * sizeof(int);
  int* p = (int*)my_malloc(nbytes);
  if (p != NULL) {
    printf("(%d - 1) / %ld + 2 = %d\n", nbytes, sizeof(Header),
           ((Header*)p - 1)->s.size);
    my_free(p);
  }
  return 0;
}
