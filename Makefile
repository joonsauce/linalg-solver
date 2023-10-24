CC=g++
CFLAGS=-I.
OBJ = app.o
NAME = app
DEPS = circuit.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $(NAME) $^ $(CFLAGS)
	$(RM) *.o

run:
	./$(NAME)

clean:
	$(RM) *.o $(NAME).exe