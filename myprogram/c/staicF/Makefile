CC = cc -g
CFLAGS = -g
OBJS := main.o a.o



test: $(OBJS)
	${CC} -o $@ $(OBJS)

clean:
	rm -f *.o

%.o: %.c test.h
	${CC} -c $<

etags:
	etags *.c *.h
help: 
	-@echo "++++++++++++++++++++++++"
	-@echo "use make test to compile"
	-@echo "use make clean to cleanup"
	-@echo "++++++++++++++++++++++++"
