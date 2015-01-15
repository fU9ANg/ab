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
CFLAGS  = 
#-Wall -Werror -Wno-unused-function

# is debug? (for development)
CDEBUG  = -g -DDEBUG

# objects

CLIEOBJS=Client.o \
		network/MsgReceiver.o \
		network/ODSocket.o \
		../client/CallBackFunctions.o \
		../client/LocalRpcHandlers.o \
		../client/ServerRpcFunctions.o \
		../message/proto/ChenyuanTypes.pb.o \
		../message/proto/Rpc.pb.o \
		../common.o \
		../gen/IntIntBase.o \
		../gen/ItemBase.o \
		../gen/PlayerBase.o \
		../gen/PosBase.o \
		../gen/ResourceBase.o \
		../gen/TalentNodeBase.o \
		../gen/TalentPropBase.o

# binary
BIN	    = Client

# where are include files kept
INC	    = -I. -I.. -I./network -I../client -I../message/proto -I../gen -I../message

# for Linker
LINK        = -lprotobuf -lpthread

# rock..
all	: $(BIN)

precompile_protobuf	:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

# how to compiling programs
$(BIN):$(CLIEOBJS)
	$(CPP) $(CFLAGS) $(CDEBUG)  -o $@ $(CLIEOBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG)  $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(CLIEOBJS) $(BIN) *~ logs .lock message/*
