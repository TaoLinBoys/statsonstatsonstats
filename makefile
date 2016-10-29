compile: stats.c
	gcc stats.c -o statspecs

run: statspecs
	./statspecs

clean:
	rm *~
