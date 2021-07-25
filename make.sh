#!/bin/sh -ex

which clang-format >/dev/null
which doxygen >/dev/null

clang-format -i format16.cpp
clang-format -i format32.cpp
clang-format -i format64.cpp
clang-format -i format8.cpp
clang-format -i include/oxeira/format.h
clang-format -i include/oxeira/invariants.h
clang-format -i include/oxeira/panic.h
clang-format -i include/oxeira/preconditions.h
clang-format -i invariants.cpp
clang-format -i panic.cpp
clang-format -i preconditions.cpp
clang-format -i testFormatU16.cpp
clang-format -i testFormatU32.cpp
clang-format -i testFormatU64.cpp
clang-format -i testFormatU8.cpp

rm -rf build
mkdir -p build

./cxx-compile build/format16.o format16.cpp
./cxx-compile build/format32.o format32.cpp
./cxx-compile build/format64.o format64.cpp
./cxx-compile build/format8.o format8.cpp
./cxx-compile build/invariants.o invariants.cpp
./cxx-compile build/panic.o panic.cpp
./cxx-compile build/preconditions.o preconditions.cpp

./static-lib build/liboxeira_format.a build/format64.o build/format32.o build/format16.o build/format8.o
./static-lib build/liboxeira_invariants.a build/invariants.o
./static-lib build/liboxeira_panic.a build/panic.o
./static-lib build/liboxeira_preconditions.a build/preconditions.o

./cxx-compile build/testFormatU64.o testFormatU64.cpp
./cxx-compile build/testFormatU32.o testFormatU32.cpp
./cxx-compile build/testFormatU16.o testFormatU16.cpp
./cxx-compile build/testFormatU8.o testFormatU8.cpp

./cxx-link build/testFormatU64 \
build/testFormatU64.o \
build/liboxeira_format.a \
build/liboxeira_preconditions.a \
build/liboxeira_invariants.a \
build/liboxeira_panic.a

./cxx-link build/testFormatU32 \
build/testFormatU32.o \
build/liboxeira_format.a \
build/liboxeira_preconditions.a \
build/liboxeira_invariants.a \
build/liboxeira_panic.a

./cxx-link build/testFormatU16 \
build/testFormatU16.o \
build/liboxeira_format.a \
build/liboxeira_preconditions.a \
build/liboxeira_invariants.a \
build/liboxeira_panic.a

./cxx-link build/testFormatU8 \
build/testFormatU8.o \
build/liboxeira_format.a \
build/liboxeira_preconditions.a \
build/liboxeira_invariants.a \
build/liboxeira_panic.a

doxygen

