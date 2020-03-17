build: so_stdio.o utils.o
	gcc -Wall -shared -o so_stdio.so so_stdio.o utils.o
so_stdio.o: so_stdio.c so_stdio.h
	gcc -Wall -fPIC -c so_stdio.c so_stdio.h
utils.o: utils.c utils.h
	gcc -Wall -fPIC -c utils.c utils.h
clean:
	rm *.o so_stdio.so