#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./proto
PBDST       = ./message

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

# is debug? (for development)
CDEBUG  = -g -DDEBUG -D_DUMP_OBJECT_INFO

# objects
OBJS    = 	rpc.o \
		\
		rpcStructure.o \
		rpcProcess.o \
		pugixml.o

# binary
BIN	    = rpc

# where are include files kept
INC	    = -I. -I./gen -I./obj -I./message -I./message/proto

# for Linker
LINK        = -lprotobuf -lpthread

# rock..
#all	: autocreatetags precompile_protobuf $(BIN)
all	: $(BIN)

autocreatetags:
	ctags *.h *.cpp *.hpp

precompile_protobuf	:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG)  -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~ logs .lock tags
