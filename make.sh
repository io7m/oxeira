#!/bin/sh -ex

which clang-format >/dev/null
which clang-tidy >/dev/null
which doxygen >/dev/null
which cppcheck >/dev/null

TESTS="
testBoundedArray0.cpp
testBoundedArray1.cpp
testBoundedArray2.cpp
testBoundedArray3.cpp
testBoundedArray4.cpp
testFormatU16.cpp
testFormatU32.cpp
testFormatU64.cpp
testFormatU8.cpp
"

SOURCES="
format16.cpp
format32.cpp
format64.cpp
format8.cpp
include/oxeira/boundedArray.h
include/oxeira/format.h
include/oxeira/invariants.h
include/oxeira/panic.h
include/oxeira/preconditions.h
invariants.cpp
panic.cpp
preconditions.cpp
${TESTS}
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

for TEST in ${TESTS}
do
  WITHOUT_SUFFIX=$(echo ${TEST} | sed 's/\.cpp//g')

./cxx-compile "build/${WITHOUT_SUFFIX}.o" "${WITHOUT_SUFFIX}.cpp"
./cxx-link "build/${WITHOUT_SUFFIX}" \
"build/${WITHOUT_SUFFIX}.o" \
build/liboxeira_format.a \
build/liboxeira_preconditions.a \
build/liboxeira_invariants.a \
build/liboxeira_panic.a
done

doxygen

