# Directorios
SRC_DIR = source
BIN_DIR = bin

# Compilador y banderas
CC = g++
CFLAGS = -g -Wall

# Archivos fuente y ejecutable
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Ordenador.cpp $(SRC_DIR)/Controlador.cpp
EXECUTABLE = $(BIN_DIR)/main

# Regla principal
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(SOURCES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

# Regla para ejecutar el programa
run: all
	$(EXECUTABLE)

# Regla para limpiar los archivos generados
clean:
	rm -rf $(BIN_DIR)