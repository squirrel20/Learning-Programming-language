#!/bin/sh

for file in $(ls *.sh)
do
    cat $file
done
exit 0
