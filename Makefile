CC = g++
CPPFLAGS = -lm
EXE = main.exe
OBJS = main.o MSort.o LQSort.o HQSort.o DQSort.o HSort.o

$(EXE) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)



