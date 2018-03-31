CC=g++
CFLAGS=-Wall -Werror -std=c++11
SOURCES=$(wildcard src/*.cpp)
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

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

default: install

install:
	$(call MKDIR,bin)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) $(INCLUDES) -o $(TARGET) $(LDFLAGS)

clean:
	$(call RMDIR,bin)
