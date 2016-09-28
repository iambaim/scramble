LIMIT:=20000

all:
	gcc -o gen -DLIMIT=${LIMIT} -D_SEQ -D_FMOD scramblingtest.c
	./gen
	gcc -o gen -DLIMIT=${LIMIT} -D_SEQ -D_MULT scramblingtest.c
	./gen
	gcc -o gen -DLIMIT=${LIMIT} -D_SEQ -D_NONE scramblingtest.c
	./gen
	gcc -o gen -DLIMIT=${LIMIT} -D_RAND -D_FMOD scramblingtest.c
	./gen
	gcc -o gen -DLIMIT=${LIMIT} -D_RAND -D_MULT scramblingtest.c
	./gen
	gcc -o gen -DLIMIT=${LIMIT} -D_RAND -D_NONE scramblingtest.c
	./gen

clean:
	rm -f gen
	rm -f *.out
