SRCS := get_next_line.c get_next_line_utils.c

BUFFER_SIZE ?= 42

test:
	@echo "Running test"
	cc -Wall -Wextra -Werror $(SRCS) -D BUFFER_SIZE=$(BUFFER_SIZE)
	./a.out
	rm -f a.out
