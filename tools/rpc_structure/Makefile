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
CFLAGS  = -Wall -Werror -Wno-unused-function

# is debug? (for development)
CDEBUG  = -g -DDEBUG

# objects
OBJS    = 	test.o \
		\
		gen/PosBase.o \
		gen/TalentNodeBase.o \
		gen/TalentPropBase.o \
		gen/PlayerBase.o \
		gen/ResourceBase.o \
		gen/IntIntBase.o \
		gen/ItemBase.o \
		\
		obj/Pos.o \
		obj/TalentNode.o \
		obj/TalentProp.o \
		obj/Player.o \
		obj/Resource.o \
		obj/IntInt.o \
		obj/Item.o \
		\
		rpc/RpcFunctionBase.o \
		rpc/EquipEquipment.o \
		rpc/UnEquipEquipment.o \
		rpc/SortItems.o \
		rpc/ComposeItem.o \
		rpc/UseItem.o \
		rpc/SellItem.o \
		\
		ServerRpc.o \
		common.o \
		message/proto/ChenyuanTypes.pb.o \
		message/proto/Rpc.pb.o \
		\
		\
		\
		ClientRpc.o \
		client/ServerRpcFunctions.o \
		client/CallBackFunctions.o \
		client/LocalRpcHandlers.o


# binary
BIN	    = test

# where are include files kept
INC	    = -I. -I./gen -I./obj -I./rpc -I./message -I./message/proto -I./client

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
	-rm -rf $(OBJS) $(BIN) *~ logs .lock message/*
