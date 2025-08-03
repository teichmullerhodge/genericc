#ifndef GENERIC_H
#define GENERIC_H

#include <stdbool.h>

enum Type {
  generic,
  boolean,
  u8,
  u16,
  u32,
  u64,

  i8,
  i16,
  i32,
  i64,

  character,
  string,
  array_boolean,
  array_u8,
  array_u16,
  array_u32,
  array_u64,

  array_i8,
  array_i16,
  array_i32,
  array_i64,

  array_character,
  array_string,
  array_generic,

};

typedef struct {

  void *value;
  enum Type type;

} T;

#define is(T, t) T.type == t

#define V(val) {(void *)val, generic}
#define _bool(v) {(void *)&(bool){v}, boolean}
#define _u8(val) {(void *)&(uint8_t){val}, u8}
#define _u16(val) {(void *)&(uint16_t){val}, u16}
#define _u32(val) {(void *)&(uint32_t){val}, u32}
#define _u64(val) {(void *)&(uint64_t){val}, u64}
#define _i8(val) {(void *)&(int8_t){val}, i8}
#define _i16(val) {(void *)&(int16_t){val}, i16}
#define _i32(val) {(void *)&(int32_t){val}, i32}
#define _i64(val) {(void *)&(int64_t){val}, i64}
#define _character(val) {(void *)&(char){val}, character}
#define _string(val) {(void *)&(char *){val}, string}
#define _arrayBool(...) {(void *)&(bool[]){__VA_ARGS__}, array_boolean}
#define _arrayU8(...) {(void *)&(uint8_t[]){__VA_ARGS__}, array_u8}
#define _arrayU16(...) {(void *)&(uint16_t[]){__VA_ARGS__}, array_u16}
#define _arrayU32(...) {(void *)&(uint32_t[]){__VA_ARGS__}, array_u32}
#define _arrayU64(...) {(void *)&(uint64_t[]){__VA_ARGS__}, array_u64}

#define _arrayI8(...) {(void *)&(int8_t[]){__VA_ARGS__}, array_i8}
#define _arrayI16(...) {(void *)&(int16_t[]){__VA_ARGS__}, array_i16}
#define _arrayI32(...) {(void *)&(int32_t[]){__VA_ARGS__}, array_i32}
#define _arrayI64(...) {(void *)&(int64_t[]){__VA_ARGS__}, array_i64}

#define _arrayCharacter(...) {(void *)&(char[]){__VA_ARGS__}, array_character}
#define _arrayString(...) {(void *)&(char *[]){__VA_ARGS__}, array_string}
#define _arrayGeneric(...) {(void *)&(void *[]){__VA_ARGS__}, array_generic}

#define cast(type) *(type *)

bool is_generic(T v);
bool is_boolean(T v);
bool is_number(T v);
bool is_number_unsigned(T v);
bool is_character(T v);
bool is_string(T v);
bool is_array(T v);
bool is_boolean_array(T v);
bool is_generic_array(T v);
bool is_number_array(T v);
bool is_number_unsigned_array(T v);
bool is_character_array(T v);
bool is_string_array(T v);
bool type_allowed(bool expr, const char *err);
void _typeof(enum Type t);
#endif
