.SUFFIXES: .cpp .o

CC=g++

SRCS1=src/client.cpp
SRCS2=src/service.cpp	
SRCS3=src/service1.cpp	
OBJS1=$(SRCS1:.cpp=.o)
OBJS2=$(SRCS2:.cpp=.o)
OBJS3=$(SRCS3:.cpp=.o)

EXE1=client
EXE2=service
EXE3=service1

all: $(OBJS1) $(OBJS2) $(OBJS3)
	$(CC) -o $(EXE1) $(OBJS1) 
	$(CC) -o $(EXE2) $(OBJS2) 
	$(CC) -o $(EXE3) $(OBJS3) 
	@echo '^_^ ^_^ ^_^ ^_^ ^_^ ^_^ OK ^_^ ^_^ ^_^ ^_^ ^_^ ^_^'

.cpp.o: 
	$(CC) -Wall -g -o $@ -c $<

clean:
	-rm -f $(OBJS1) $(OBJS2)
	-rm -f core*
