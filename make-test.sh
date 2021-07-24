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

./make-test-one.sh testFormatU64 || fail
./make-test-one.sh testFormatU32 || fail
./make-test-one.sh testFormatU16 || fail
./make-test-one.sh testFormatU8 || fail

echo

if [ ${FAILED} -eq 1 ]
then
  fatal "one or more tests failed"
else
  echo "info: all tests passed"
fi

