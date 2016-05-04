#!/bin/bash - 

sed -i 's/aaaaaa/'"$1"'/' Makefile
make
sed -i 's/'"$1"'/aaaaaa/' Makefile


