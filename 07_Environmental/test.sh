#!/bin/bash

if [ "$(echo -n "test1" | sha1sum | cut -f 1 -d " ")" != "$(echo -n "SHA1 \"test1" | ./rhasher | head -2 | tail -1)" ]; then
  echo "SHA1 test failed"
  exit 1
fi
if [ "$(echo -n "test1" | md5sum | cut -f 1 -d " ")" != "$(echo -n "MD5 \"test1" | ./rhasher | head -2 | tail -1)" ]; then
  echo "MD5 test failed"
  exit 1
fi
