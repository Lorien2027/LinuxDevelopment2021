#!/bin/bash
if [ -z "$1" ]
  then
    sleep_time=0.0
  else
    sleep_time=$1
fi

data=()
length=0
while IFS= read -r line; do
    for ((i = 0; i < ${#line}; i++)); do
        if ! [ -z ${line:i:1} ]
            then
                data+=(${line:i:1},$length,$i)
            fi
    done
    length=$((length+1))
done

tput clear
for i in $(shuf -e $(seq 0 $((${#data[@]}-1)))); do IFS="," read char height width <<<${data[$i]};
    tput cup $height $width
    sleep $sleep_time
    echo -e $char
done 
tput cup $length 0
