all:
	rm -rf ./bin
	mkdir ./bin
	clang ./src/main.c -std=c99 -o ./bin/main -framework Carbon
