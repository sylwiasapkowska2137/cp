include id

NAME = $(ID)zad

export CXXFLAGS = -Wall -O3 -std=c++11

.PHONY: clean clean_all test

all: prog test doc 

doc: doc/$(NAME).pdf

doc/$(NAME).pdf: doc/$(NAME).tex
	make -C doc
	make -C doc clean

prog: prog/$(NAME) prog/generator

prog/$(NAME): prog/$(NAME).cpp
	make -C prog $(NAME)

prog/generator: prog/generator.cpp
	make -C prog generator

test:
	cd prog && ./generator && cd ..

clean:
	rm -f "prog/$(NAME)" prog/generator "doc/$(NAME).pdf"
