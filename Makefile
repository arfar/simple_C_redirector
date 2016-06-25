##########################
# Makefile for linkredr  #
# Author: Arthur Roberts #
##########################

PROJECT_NAME	= linkredr

CC				= gcc
LIBS			= -lmicrohttpd

all: $(PROJECT_NAME)

$(PROJECT_NAME): link_redirects.h main.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

link_redirects.h:
	@echo "########################################################"
	@echo "  link_redirects.h doesn't exist, copying example file  "
	@echo "You'll need to edit this file and add your own redirects"
	@echo "########################################################"
	cp example_redirects.h link_redirects.h
	false

clean:
	rm -f *.o $(PROJECT_NAME)
