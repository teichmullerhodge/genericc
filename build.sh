#!/bin/bash
set -e

COMPILER=gcc
CXXFLAGS="-Wall -Wextra -Werror -O2"
LDFLAGS=""

SRC_DIR=src
BUILD_DIR=build
OUTPUT=$BUILD_DIR/genericc.elf

mkdir -p $BUILD_DIR

OBJ_FILES=""

for file in $(find $SRC_DIR -name '*.c'); do
  obj_file="$BUILD_DIR/$(basename "${file%.c}.o")"
  OBJ_FILES="$OBJ_FILES $obj_file"

  needs_recompile=false

  # Recompila se .o não existe ou .cpp foi modificado
  if [[ ! -f $obj_file || $file -nt $obj_file ]]; then
    needs_recompile=true
  else
    # Recompila se qualquer .hpp for mais novo que o .o
    for header in $(find $SRC_DIR -name '*.h'); do
      if [[ $header -nt $obj_file ]]; then
        needs_recompile=true
        break
      fi
    done
  fi

  if $needs_recompile; then
    echo "🔄 Compiling $file"
    $COMPILER -c $CXXFLAGS "$file" -o "$obj_file"
  fi
done

echo "🔗 Linking $OUTPUT"
$COMPILER $OBJ_FILES -o $OUTPUT $LDFLAGS

echo "✅ Build finished: $OUTPUT"
