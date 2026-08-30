#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void replaceComma(const char *input, char *output, size_t out_size) {
  char *ptrOut = output;
  const char *ptrIn = input;
  while ((size_t)(ptrOut - output) < out_size - 4 && *ptrIn) { // safety margin
    if (*ptrIn == ',') {
      *ptrOut++ = ' ';
      *ptrOut++ = '|';
      *ptrOut++ = ' ';
    } else {
      *ptrOut++ = *ptrIn;
    }
    ptrIn++;
  }
  *ptrOut = '\0';
}

int main(void) {
  char line[1024];
  while (fgets(line, sizeof line, stdin)) {
    // Remove trailing newline
    line[strcspn(line, "\n")] = '\0';

    char out[sizeof(line) * 3]; // guaranteed enough
    replaceComma(line, out, sizeof(out));
    printf("%s\n", out);
  }
  return EXIT_SUCCESS;
}
