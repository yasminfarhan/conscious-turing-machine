#
# Makefile
# Author:

SYSTEMC = /opt/systemc
TARGET_ARCH = linux64
WAVE_VIEWER = simvision
CC = g++

LIBS   = -lsystemc
LIBDIR = -L. -L$(SYSTEMC)/lib-$(TARGET_ARCH)
INCDIR = -I../src -I../tb -I$(SYSTEMC)/include

TARGET = ctm
VPATH = ../src:../tb

.SUFFIXES: .cpp .o

SRCS = ctm.cpp ctm_tb.cpp sc_main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(LIBDIR) -o $@ $(OBJS) ${LIBS}

%.o: %.cpp
	$(CC) $(INCDIR) -c -o $@ $<

clean:
	rm -f *.o $(TARGET) *.dsn *.trn *.vcd -rf

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
