cc = gcc
CFLAGS = -Wall -fsanitize=address
OBJS = CityDefender.o tablero.o cartas.o
TARGET = juego 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
CityDefender.o: CityDefender.c Tablero.h Cartas.h
	$(CC) $(CFLAGS) -c CityDefender.c
tablero.o: tablero.c Tablero.h
	$(CC) $(CFLAGS) -c tablero.c
cartas.o: cartas.c Cartas.h
	$(CC) $(CFLAGS) -c cartas.c
clean :
	rm -f  $(OBJS) $(TARGET)

