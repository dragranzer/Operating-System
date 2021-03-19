#!/bin/bash

#kalau $# ganjil, tampilkan jumlah bilangan
#kalau $# genap, tulis 'Anda belum beruntung, coba lagi.'
arr=( "$@" )

let keganjilan=$#%2

if [ $keganjilan -eq 0 ]
then
    echo "Anda belum beruntung, coba lagi."
else
    for ((y=0; y<$#; y++))
    do
        let "val=val+${arr[$y]}"
    done
    echo "$val"
fi
