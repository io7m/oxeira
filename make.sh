#!/bin/sh -ex

which clang-format >/dev/null
which clang-tidy >/dev/null
which doxygen >/dev/null
which cppcheck >/dev/null

SOURCES="
format16.cpp
format32.cpp
format64.cpp
format8.cpp
include/oxeira/format.h
include/oxeira/invariants.h
include/oxeira/panic.h
include/oxeira/preconditions.h
invariants.cpp
panic.cpp
preconditions.cpp
testFormatU16.cpp
testFormatU32.cpp
testFormatU64.cpp
testFormatU8.cpp
"

for SOURCE in ${SOURCES}
do
  clang-format -i "${SOURCE}"
done

cppcheck \
--check-config \
--enable=all \
--suppress=unusedFunction \
--suppress=missingIncludeSystem \
--suppress=unmatchedSuppression \
--language=c++ \
--std=c++14 \
--error-exitcode=1 \
${SOURCES}

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

