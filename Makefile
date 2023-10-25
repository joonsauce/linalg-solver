CC=g++
CFLAGS=-I.
OBJ = test.o fractions.o imaginary.o linalg.o
DEPS = *.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	$(RM) *.o

run:
	./$(NAME)

.PHONY: clean

clean:
	$(RM) *.o $(NAME).exe