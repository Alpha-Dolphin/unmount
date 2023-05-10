unmount.zip:	README makefile *.c *.h 
	zip $@ $^
	rm -rf install
	mkdir install
	unzip unmount.zip -d install
	make -C install unmount

all:  tags headers unmount

tags: *.c
	ctags -R .

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -Wconversion -g -c $< -o $@

LIB=-Lexplain/statfs
INC=-Iusr/share/man/man2/statfs.2.gz
unmount: unmount.o
	gcc -g -o $@ $^ -lncurses -L. $(LIB) $(INC) 
