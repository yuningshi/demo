CC = gcc
CFLAGS = -g -O0

SRCDIR = .
INCDIR = .

SRCS_ = demo.c

HEADERS_ =

EXECUTABLE = demo

LIBS = -lm
INCLUDES =
LFLAGS =

SRCS = $(patsubst %,$(SRCDIR)/%,$(SRCS_))
HEADERS = $(patsubst %,$(INCDIR)/%,$(HEADERS_))

OBJS = $(SRCS:.c=.o)

all:    $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@$(CC) $(CFLAGS) $(SFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS) $(LFLAGS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(SFLAGS) $(INCLUDES) -c $<  -o $@

.PHONY: clean

clean:
	$(RM) $(SRCDIR)/*.o $(EXECUTABLE)
