CC := g++
CFLAGS := -Wall -Werror -std=c++11
BIN := bin
SRC := src
OBJ := obj
SOURCES := $(wildcard $(SRC)/**/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

ifeq ($(OS),Windows_NT)
	TARGET=bin/dungeon-saga.exe
	LIBS=-L"C:/SFML/lib"
	INCLUDES=-I"C:/SFML/include"
	MKDIR=if not exist "$(1)" md "$(1)"
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
	$(call MKDIR,$(dir $@))
	$(CC) -I$(SRC) -c $< -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS)

make_directories:
	echo Test

clean:
	$(call RMDIR,bin)
	$(call RMDIR,out)
