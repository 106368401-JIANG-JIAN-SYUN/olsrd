#!/bin/sh

sed -i 's/Andreas T.\{1,6\}nnesen/Andreas Tonnesen/g;s/Andreas T�nnesen/Andreas Tonnesen/g;s/Andreas Tønmnesen/Andreas Tonnesen/' $(find -type f -not -path "*/.hg*")
sed -i 's///g;s/[	 ]\+$//' $(find -name "*.[ch]" -not -path "*/.hg*")
indent -sob -nhnl -nut $(find -name "*.[ch]" -not -path "*/.hg*")
rm $(find -name "*~" -not -path "*/.hg*")
