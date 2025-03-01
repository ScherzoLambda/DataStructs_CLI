CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Nome do executável final
TARGET = DataStruct

# Arquivos-fonte do projeto src/sdstruct.c
SRCS =  src/main.c src/dstruct.c 

# Arquivos objeto que serão gerados
OBJS = main.o dstruct.o

# Cabeçalhos dependentes (adicione outros se necessário)
#DEPS = dstruct.h utils.h

# Regra padrão (quando você roda "make" sem argumentos)
all: $(TARGET)

# Regra para gerar o executável a partir dos objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regra genérica para compilar arquivos .c em .o
# Usa a variável DEPS para garantir que recompile se os .h mudarem
%.o: src/%.c include/*.h
	$(CC) $(CFLAGS) -c $<
	
run: $(TARGET)
	@echo "Compilação bem-sucedida! Executando o programa..."
	@./$(TARGET)


clean:
	rm -f $(OBJS) $(TARGET)
