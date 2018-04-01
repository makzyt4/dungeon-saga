CC := g++
CFLAGS := -Wall -Werror -std=c++11
BIN := bin
SRC := src
OBJ := obj
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(OS),Windows_NT)
	TARGET=bin/dungeon-saga.exe
	LIBS=-L"C:/Program Files/SFML/lib"
	INCLUDES=-I"C:/Program Files/SFML/include"
	MKDIR=if not exist "$(1)" mkdir $(1)
	RMDIR=rd /s /q "$(1)"
else
	TARGET=bin/dungeon-saga
	LIBS=
	INCLUDES=
	MKDIR=mkdir -p $(1)
	RMDIR=rm -rf $(1)
endif

all: $(OBJECTS)
	$(call MKDIR,bin)
	$(CC) $^ -o $(TARGET) $(INCLUDES) $(LIBS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	@ $(call MKDIR,$(OBJ))
	$(CC) -I$(SRC) -c $< -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS)

create_out_dir:
	$(call MKDIR,obj)

clean:
	$(call RMDIR,bin)
	$(call RMDIR,out)
