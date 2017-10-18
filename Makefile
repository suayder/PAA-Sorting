all: main

main: main.c
	gcc main.c -o main -Ofast

compile:
	./main

clean:
	rm main
