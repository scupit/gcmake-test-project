#include <stdio.h>

int main(void) {
  FILE* fout = fopen("some-text.txt", "w");
  fputs("Some nice text", fout);
  fclose(fout);
  return 0;
}
