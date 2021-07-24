#!/bin/sh

fatal()
{
  echo "fatal: $1" 1>&2
  exit 1
}

if [ $# -ne 1 ]
then
  fatal "usage: test"
fi

TEST="$1"
shift

./build/${TEST} | tee "build/${TEST}.out"
cmp "${TEST}.exp" "build/${TEST}.out" || fatal "test ${TEST} failed"

