CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude -MMD

# Nome do executável final
TARGET = DataStruct

# Diretório para os arquivos objeto
OBJDIR = obj

# Encontra todos os arquivos .c nos diretórios src e src/menus.
SRCS := $(wildcard src/*.c src/menus/*.c)

# Automaticamente gera a lista de arquivos objeto (.o) a partir da lista de fontes.
OBJS := $(patsubst src/%.c,$(OBJDIR)/%.o,$(patsubst src/menus/%.c,$(OBJDIR)/%.o,$(SRCS)))

# Regra padrão: compila tudo
all: $(TARGET)

# Cria o diretório de objetos se ele não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Linka os arquivos objeto para criar o executável final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Inclui os arquivos de dependência gerados pelo -MMD
-include $(patsubst $(OBJDIR)/%.o, $(OBJDIR)/%.d, $(OBJS))

# Regra genérica para compilar qualquer arquivo .c em um .o,
# garantindo que o diretório 'obj' seja criado ANTES da compilação.
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
# Regra para compilar arquivos .c de 'src/menus'
$(OBJDIR)/%.o: src/menus/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
# Executa o programa
run: $(TARGET)
	@echo "Compilação bem-sucedida! Executando o programa..."
	@./$(TARGET)

# Limpa todos os arquivos gerados (executável, objetos e arquivos .d)
clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d $(TARGET)
	rmdir $(OBJDIR) 2>/dev/null || true
