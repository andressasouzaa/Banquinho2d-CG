# Quais objetos têm que ser compilados
OBJS = banquinho.cpp

# Qual compilador usar
CC = g++

# Flags para o compilador
COMPILER_FLAGS = -w

# aqui eu recebo o uname para depois usar sabendo de é mac ou linux. Windows não trabalho no momento
os = $(shell uname -s)

ifeq ($(os), Darwin)
	# Flags de linkagem de biblioteca
	LINKER_FLAGS = -framework GLUT -framework OpenGL
	
	# Caminhos de include que precisam
	INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include
	# Caminhos de bibliotecas que precisam
	LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib
else
	# Flags de linkagem de biblioteca
	LINKER_FLAGS = -lglut -lGLU -lGL -L/usr/X11R6/lib/ -lXmu -lXi -lXext -lX11 -lXt
endif

# Nome da saída
OUTPUT_NAME = test.out

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_NAME)

	@echo Pronto.
