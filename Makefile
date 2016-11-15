##########################
# Makefile for linkredr  #
# Author: Arthur Roberts #
##########################

PROJECT_NAME	= linkredr

CC		= gcc
LIBS		= -lmicrohttpd

all: $(PROJECT_NAME)

$(PROJECT_NAME): redirects.h main.o
	$(CC) -o $@ $^ $(LIBS)

main.o: main.c main.h
	$(CC) -o $@ -c $<

redirects.h:
	@echo "########################################################"
	@echo "  link_redirects.h doesn't exist, copying example file  "
	@echo "You'll need to edit this file and add your own redirects"
	@echo "########################################################"
	cp example_redirects.h redirects.h
	false

clean:
	rm -f *.o $(PROJECT_NAME)
