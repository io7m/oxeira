#!/bin/sh

fatal()
{
  echo "fatal: $1" 1>&2
  exit 1
}

if [ $# -ne 2 ]
then
  fatal "usage: test expected-result"
fi

TEST="$1"
shift
EXPECTED_RESULT="$1"
shift

./build/${TEST} > "build/${TEST}.out"
RESULT=$?

case ${EXPECTED_RESULT} in
  success)
    if [ ${RESULT} -ne 0 ]
    then
      fatal "test ${TEST} crashed"
    fi
  ;;
  failure)
    if [ ${RESULT} -eq 0 ]
    then
      fatal "test ${TEST} was supposed to crash, but did not"
    fi
  ;;
esac

cmp "${TEST}.exp" "build/${TEST}.out" || fatal "test ${TEST} failed"
