#!/bin/sh

if [ -z "$1" ]; then
	echo "Error: No file provided."
	echo "Usage: $0 /path/to/file"
	exit 1
fi

FILEPATH=$(realpath $1)

cd "/home/shashank/Documents/linux&cpp/recat"

./a.out "$FILEPATH"

