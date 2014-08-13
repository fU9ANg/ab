#
# makefile of chengyuan
#

# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./proto
PBDST       = ./message

# which c plus plus compiler
CPP         = ccache g++

# options for compiler
CFLAGS      = -Wall -Werror

# is debug? (for development)
CDEBUG      = -g

# libraries
LIB         = -lprotobuf

# objects

MESSAGEOBJS = message/proto/pbBuffer.pb.o \
              message/proto/pbCreate.pb.o \
              message/proto/pbCreature.pb.o \
              message/proto/pbSpell.pb.o

OBJS        = test.o \
              ccBuffer.o \
              ccCreate.o \
              ccCreature.o \
              ccSpell.o

# binary
BIN	        = chengyuan

# where are include files kept
INC	        = -I. -I./message -I./message/proto

# rock..
all: clean precompile_protobuf $(BIN)

precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

$(BIN):$(OBJS) $(MESSAGEOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS) $(MESSAGEOBJS) $(LIB)

%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) ./message/proto *~
