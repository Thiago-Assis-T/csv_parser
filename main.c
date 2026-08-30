#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char line[1024];
  while (fgets(line, sizeof line, stdin)) {
    line[strcspn(line, "\n")] = '\0'; // Removing trailing new line characters

    char out[sizeof(line) * 3]; // Creating an output buffer
    char *ptrOut = out;         // Pointer to output buffer

    for (const char *ptrS = line; *ptrS; ++ptrS) {
      if (*ptrS == ',') {
        *ptrOut++ = ' ';
        *ptrOut++ = '|';
        *ptrOut++ = ' ';
      } else {
        *ptrOut++ = *ptrS;
      }
    }
    *ptrOut = '\0';
    printf("%s\n", out);
  }
  return EXIT_SUCCESS;
}
