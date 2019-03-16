CC = gcc
DEPS = main.o chessboard_theme.o file_manager.o plot.o knight.o
TARGET = the-trapped-knight



all: $(TARGET)


$(TARGET): $(DEPS)
	$(CC) $(DEPS) -o $(TARGET)



.PHONY: clean
clean:
	-rm -rf $(DEPS)
	-rm -rf $(TARGET)
