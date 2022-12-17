#include <ctype.h>

char getch(void);

int getword(char* word) {
  int c = getch();
  while (isspace(c)) c = getch();
  while (isalpha(c)) {
    *word = c;
    word++;
    c = getch();
  }
  *word = '\0';
  return c;  // space or EOF
}
