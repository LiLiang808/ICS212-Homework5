Homework5 : iofunctions.o driver.o
	cc -o Homework5 iofunctions.o driver.o

iofunctions.o : iofunctions.c account.h ioheader.h
	cc -c iofunctions.c

driver.o : driver.c
	cc -c driver.c

clean :
	rm Homework5 iofunctions.o driver.o test1rec.txt test5rec.txt InvalidTest.txt
