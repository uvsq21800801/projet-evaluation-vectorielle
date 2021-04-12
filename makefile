run: a.out affichage3D.py
	./a.out

a.out: main.c
	gcc main.c -I/usr/include/python2.7 -lpython2.7 -lcrypt -lpthread -ldl -lutil -lrt -lm 

clean: 
	rm -f a.out 
	rm -f affichage3D.pyc
