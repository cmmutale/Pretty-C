CC = cc

COFLAGS=
CWFLAGS=
CFLAGS= $(CWFLAGS) $(COFLAGS)

objects = lex.yy.o main.o init.o func.o symbol.o

all: output run

p2.o: p2.h
		$(CC) $(CFLAGS) -c p2.h

lex.yy.o: lex.yy.c p2.h
			$(CC) $(CFLAGS) -c lex.yy.c

symbol.c: symbol.c p2.h
			$(CC) $(CFLAGS) -c symbol.c

init.o: init.c p2.h
			$(CC) $(CFLAGS) -c init.c

func.o: func.c p2.h
			$(CC) $(CFLAGS) -c func.c

pretty: pretty.l
		:lex pretty.l

main: $(objects)
		$(CC) $(CFLAGS) -c main.c $(objects)

output: main
		./main < symbol.c > index.html
		main
		
