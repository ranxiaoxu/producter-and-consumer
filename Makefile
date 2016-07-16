my_cond:my_cond.c
	gcc -o my_cond list.c my_cond.c -lpthread
.PHONY:clean
clean:
	rm -f my_cond
