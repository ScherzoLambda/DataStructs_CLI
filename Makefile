CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Nome do executável final
TARGET = DataStruct

# Arquivos-fonte do projeto 
SRCS =  src/main.c src/dstruct.c 

# Arquivos objeto que serão gerados
OBJS = main.o dstruct.o


# Regra padrão (quando você roda "make" sem argumentos)
all: $(TARGET)

# Gera o executável a partir dos objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	rm -f $(OBJS)

# compilar .c em .o
%.o: src/%.c include/*.h
	$(CC) $(CFLAGS) -c $<
	
run: $(TARGET)
	@echo "Compilação bem-sucedida! Executando o programa..."
	@./$(TARGET)


clean:
	rm -f $(OBJS) $(TARGET)
