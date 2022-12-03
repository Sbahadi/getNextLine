
all :
	gcc get_next_line.c get_next_line_utils.c
	./a.out

u :
	gcc get_next_line_utils.c
	./a.out