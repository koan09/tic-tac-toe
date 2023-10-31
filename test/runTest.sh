#!/usr/bin/bash

if [ -z $1 ] ; then       # if first command is empty 
    echo arg 1 needs to be the programming runnning on the test files.
    exit 1 
fi

for file in $(dirname $0)/?.test ; do
        echo -n "$file: "; cat $file; cat $file | $1  
done

for file in $(dirname $0)/1?.test ; do
        echo -n "$file: "; cat $file; cat $file | $1  
done
