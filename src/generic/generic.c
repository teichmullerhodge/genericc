
#include "generic.h"
#include <stdio.h>

bool is_generic(T v) { return v.type == generic; }
bool is_boolean(T v) { return v.type == boolean; }
bool is_number(T v) { return v.type >= u8 && v.type <= i64; }
bool is_number_unsigned(T v) { return v.type >= u8 && v.type <= u64; }
bool is_character(T v) { return v.type == character; }
bool is_string(T v) { return v.type == string; }
bool is_array(T v) {
  return v.type >= array_boolean && v.type <= array_generic;
}
bool is_boolean_array(T v) { return v.type == array_boolean; }
bool is_generic_array(T v) { return v.type == array_generic; }
bool is_number_array(T v) { return v.type >= array_u8 && v.type <= array_i64; }
bool is_number_unsigned_array(T v) {
  return v.type >= array_u8 && v.type <= array_u64;
}
bool is_character_array(T v) { return v.type == array_character; }
bool is_string_array(T v) { return v.type == array_string; }

bool type_allowed(bool expr, const char *err) {
  if (!expr) {
    printf("%s\n", err);
    return false;
  }

  return true;
}

void _typeof(enum Type t) {
  switch (t) {
  case generic:
    printf("generic\n");
    break;
  case boolean:
    printf("boolean\n");
    break;
  case u8:
    printf("unsigned 8-bit integer\n");
    break;
  case u16:
    printf("unsigned 16-bit integer\n");
    break;
  case u32:
    printf("unsigned 32-bit integer\n");
    break;
  case u64:
    printf("unsigned 64-bit integer\n");
    break;
  case i8:
    printf("signed 8-bit integer\n");
    break;
  case i16:
    printf("signed 16-bit integer\n");
    break;
  case i32:
    printf("signed 32-bit integer\n");
    break;
  case i64:
    printf("signed 64-bit integer\n");
    break;
  case character:
    printf("character\n");
    break;
  case string:
    printf("string\n");
    break;
  default:
    printf("unknown type\n");
  }
}