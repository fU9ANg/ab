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
CDEBUG  = -g -DDEBUG

# objects
OBJS    = 	test.o \
		\
		gen/PosBase.o \
		gen/TalentNodeBase.o \
		gen/TalentPropBase.o \
		gen/PlayerBase.o \
		\
		obj/Pos.o \
		obj/TalentNode.o \
		obj/TalentProp.o \
		obj/Player.o \
		\
		common.o \
		message/proto/ChenyuanTypes.pb.o

# binary
BIN	    = test

# where are include files kept
INC	    = -I. -I./gen -I./obj -I./message -I./message/proto

# for Linker
LINK        = -lprotobuf -lpthread

# rock..
all	: precompile_protobuf $(BIN)

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
	-rm -rf $(OBJS) $(BIN) *~ logs .lock
