#include "function_example.h"
#include "../generic/generic.h"
#include <stdint.h>
#include <stdlib.h>

T *add(T a, T b) {
  bool allowed = type_allowed((a.type >= u8 && a.type <= i64) &&
                                  (b.type >= u8 && b.type <= i64),
                              "All values must be a valid number.");
  if (!allowed) {
    return NULL;
  };

  int32_t res = cast(int32_t) a.value + cast(int32_t) b.value;
  int32_t *val = malloc(sizeof(int32_t));
  if (val == NULL)
    return NULL;
  *val = res;
  T *result = malloc(sizeof(T));
  if (result == NULL) {
    return NULL;
  }

  result->value = val;
  result->type = i32;
  return result;
}