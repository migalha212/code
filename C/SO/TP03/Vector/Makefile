all:
	gcc -c -Wall -fPIC vector_*.c
	gcc -shared -o libvector.so vector_*.c
	gcc -Wall use_vector.c -o use_vector -L. -lvector -lm

clean:
	rm -f *.o *.so use_vector