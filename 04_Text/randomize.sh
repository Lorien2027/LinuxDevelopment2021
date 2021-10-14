#!/bin/bash
if [ -z "$1" ]
  then
    sleep_time=0.0
  else
    sleep_time=$1
fi


length=0
while IFS= read -r line; do
    line=$(tr -d '\n' <<< $line)
    line=$(echo "$line" | cat -v | tr -d '_^H' )
    for ((i = 0; i < ${#line}; i++)); do
        if ! [ -z ${line:i:1} ]
            then
                data="$data ${line:i:1}\n$length\n$i"
            fi
    done
    length=$((length+1))
done

tput clear
for i in $(shuf -e $data); do
    i=$(echo -e "$i" | tr '\n' ' ')
    IFS=$" " read char height width <<< $i
    tput cup $height $width
    sleep $sleep_time
    echo -e "$char"
done 
tput cup $length 0
