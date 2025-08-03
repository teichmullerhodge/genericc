#include "../generic/generic.h"
#include <stdint.h>
#include <stdio.h>

void example() {

  T value0 = _bool(true);
  T value1 = _u8(41);
  T value2 = _u16(65535);
  T value3 = _u32(42949672);
  T value4 = _u64(184467440551615U);
  T value5 = _i8(-128);
  T value6 = _i16(-32768);
  T value7 = _i32(-2147483648);
  T value8 = _i64(-922337203685);

  T value10 = _string("Hello, World!");
  T value11 = _character('A');

  T value12 = _arrayBool(true, false, true);
  T value13 = _arrayU8(1, 2, 3);
  T value14 = _arrayU16(1000, 2000, 3000);
  T value15 = _arrayU32(100000, 200000, 300000);
  T value16 = _arrayU64(10000000000ULL, 20000000000ULL, 30000000000ULL);
  T value21 = _arrayCharacter('a', 'b', 'c');
  T value22 = _arrayString("Hello", "World", "!");

  T value17 = _arrayI8(-1, -2, -3);
  T value18 = _arrayI16(-1000, -2000, -3000);
  T value19 = _arrayI32(-100000, -200000, -300000);
  T value20 = _arrayI64(-10000000000LL, -20000000000LL, -30000000000000LL);

  if (is_boolean(value0)) {
    printf("Boolean value: %s\n", cast(bool) value0.value ? "true" : "false");
  }
  if (is_number_unsigned(value1)) {
    printf("Unsigned 8-bit integer value: %u\n", cast(uint8_t) value1.value);
  }
  if (is_number_unsigned(value2)) {
    printf("Unsigned 16-bit integer value: %u\n", cast(uint16_t) value2.value);
  }
  if (is_number_unsigned(value3)) {
    printf("Unsigned 32-bit integer value: %u\n", cast(uint32_t) value3.value);
  }
  if (is_number_unsigned(value4)) {
    printf("Unsigned 64-bit integer value: %llu\n",
           (unsigned long long)value4.value);
  }
  if (is_number(value5)) {
    printf("Signed 8-bit integer value: %d\n", cast(int8_t) value5.value);
  }
  if (is_number(value6)) {
    printf("Signed 16-bit integer value: %d\n", cast(int16_t) value6.value);
  }
  if (is_number(value7)) {
    printf("Signed 32-bit integer value: %d\n", cast(int32_t) value7.value);
  }
  if (is_number(value8)) {
    printf("Signed 64-bit integer value: %ld\n", cast(int64_t) value8.value);
  }
  if (is_string(value10)) {
    printf("String value: %s\n", cast(char *) value10.value);
  }
  if (is_character(value11)) {
    printf("Character value: %c\n", *(char *)value11.value);
  }

  if (is_boolean_array(value12)) {
    bool *arr = (bool *)value12.value;
    printf("Boolean array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%s ", arr[i] ? "true" : "false");
    }
    printf("\n");
  }

  if (is_number_unsigned_array(value13)) {
    uint8_t *arr = (uint8_t *)value13.value;
    printf("Unsigned 8-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%u ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value14)) {
    uint16_t *arr = (uint16_t *)value14.value;
    printf("Unsigned 16-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%u ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value15)) {
    uint32_t *arr = (uint32_t *)value15.value;
    printf("Unsigned 32-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%u ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value16)) {
    uint64_t *arr = (uint64_t *)value16.value;
    printf("Unsigned 64-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%ld ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value17)) {
    int8_t *arr = (int8_t *)value17.value;
    printf("Signed 8-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value18)) {
    int16_t *arr = (int16_t *)value18.value;
    printf("Signed 16-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value19)) {
    int32_t *arr = (int32_t *)value19.value;
    printf("Signed 32-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  if (is_number_array(value20)) {
    int64_t *arr = (int64_t *)value20.value;
    printf("Signed 64-bit integer array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%ld ", arr[i]);
    }
    printf("\n");
  }

  if (is_character_array(value21)) {
    char *arr = (char *)value21.value;
    printf("Character array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%c ", arr[i]);
    }
    printf("\n");
  }

  if (is_string_array(value22)) {
    char **arr = (char **)value22.value;
    printf("String array: ");
    for (size_t i = 0; i < 3; i++) {
      printf("%s ", arr[i]);
    }
    printf("\n");
  }
}
