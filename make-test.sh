#!/bin/sh

FAILED=0

fail()
{
  FAILED=1
}

fatal()
{
  echo "fatal: $1" 1>&2
  exit 1
}

./make-test-one.sh testFormatU64 success || fail
./make-test-one.sh testFormatU32 success || fail
./make-test-one.sh testFormatU16 success || fail
./make-test-one.sh testFormatU8 success || fail
./make-test-one.sh testBoundedArray0 success || fail
./make-test-one.sh testBoundedArray1 failure || fail
./make-test-one.sh testBoundedArray2 failure || fail
./make-test-one.sh testBoundedArray3 failure || fail
./make-test-one.sh testBoundedArray4 failure || fail

echo

if [ ${FAILED} -eq 1 ]
then
  fatal "one or more tests failed"
else
  echo "info: all tests passed"
fi

