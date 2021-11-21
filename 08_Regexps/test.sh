#!/bin/bash

if [ "$(echo '1a23b4' | sed -E 's/([0-9].[0-9])([0-9].[0-9])/\2 \\ \1/')" != "$(./esub '([0-9].[0-9])([0-9].[0-9])' '\2 \\ \1' '1a23b4')" ]; then
  echo "Test 1 failed"
  exit 1
fi
if [ "$(echo 'aaabbbccc' | sed -E 's/(a*(b*))/\2=\1=/')" != "$(./esub '(a*(b*))' '\2=\1=' 'aaabbbccc')" ]; then
  echo "Test 2 failed"
  exit 1
fi
