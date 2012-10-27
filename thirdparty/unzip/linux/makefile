# Normal Information 
CC=g++
FLAGS= -g -Wall 
FILE_EXT=c

#Project infor 
PROJECT_PATH=../../..
PROJECT=unzip

# User Config Information 
LIB_DIR=$(PROJECT_PATH)/lib
OBJ_DIR=$(PROJECT_PATH)/obj
SRC_DIR=../src
INCLUDE_DIR=-I../src  -I./

#Source File 
SRC=  ioapi.c \
	  unzip.c \
	  zip.c \
#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.$(FILE_EXT)=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))




main:$(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/lib$(PROJECT).a: $(OBJ_NAME_WITH_PATH) 
	ar cr $@ $(OBJ_NAME_WITH_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE_DIR) 


