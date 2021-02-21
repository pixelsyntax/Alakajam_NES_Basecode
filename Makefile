.PHONY: all clean
BINDIR = Bin
SRCDIR = Src
NAME = $(BINDIR)/alakajam
MAP = $(BINDIR)/alakajam.map

# cl65 -t nes -Oisr -c crt0.s

CFLAGS =-t nes -Oisr -g --include-dir neslib
CC = cl65

SRC = $(wildcard $(SRCDIR)/*.c)
SRC += $(wildcard $(SRCDIR)/*.s)
SRC += $(wildcard neslib/*.s)

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)


all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ --listing $<.lst

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@ --listing $<.lst

$(NAME): $(OBJ) Src/nes.cfg
	mkdir -p Bin
	$(CC) -o $(NAME) -m $(MAP) $(CFLAGS) -C Src/nes.cfg  $(OBJ)

$(OBJ): $(wildcard *.h *.sinc)

test: $(NAME)
	fceux $(NAME)

clean:
	rm -f $(NAME) $(MAP) *.o
