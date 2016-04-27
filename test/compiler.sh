#!/bin/bash - 

sed -i 's/test.c/'"$1"'/' Makefile
make


