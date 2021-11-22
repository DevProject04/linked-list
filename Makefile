cc = gcc
obj = main.o node.o
target = run.exe

$(target): $(obj)
	$(cc) -o $(target) $(obj)

main.o: main.c
	$(cc) -c -o main.o main.c

node.o: node.c
	$(cc) -c -o node.o node.c

clean:
	rm $(obj) $(target)