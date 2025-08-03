#include "examples/function_example.h"
#include "generic/generic.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  T a = _i32(10);
  T b = _string("Hello, world!");
  T c = _u8(200);
  T *d = add(a, b);
  T *e = add(a, c);

  if (e != NULL) {

    printf("Value at generic e is: %d\n", cast(int32_t) e->value);
    printf("Type of e is: ");
    _typeof(e->type);
  }

  if (d == NULL) {

    free(e->value);
    free(e);
    return -1;
  }

  return 0;
}
