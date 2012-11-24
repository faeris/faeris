# Normal Information 
CC=g++
FLAGS= -g -Wall  -DLINUX
FILE_EXT=cc

#Project infor 
PROJECT_PATH=../../build/
PROJECT=util

# User Config Information 
LIB_DIR=$(PROJECT_PATH)lib
OBJ_DIR=$(PROJECT_PATH)obj
SRC_DIR=./
INCLUDE_DIR=  -I./  -I../  -I../../thirdparty

#Source File 
SRC=  FsImgDecoder.cc \
	  FsLog.cc \
	  FsStringUtil.cc \
	  platform/FsLibPngDecoder.cc \
	  platform/FsTinyJpegDecoder.cc
	

#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.$(FILE_EXT)=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))




main:$(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/lib$(PROJECT).a: $(OBJ_NAME_WITH_PATH) 
	ar cr $@ $(addprefix $(OBJ_DIR)/,$(notdir $(OBJ_NAME_WITH_PATH)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o  $(OBJ_DIR)/$(notdir $@) $< $(INCLUDE_DIR) 



clean:
	rm -f $(OBJ_NAME_WITH_PATH)
	rm -f $(LIB_DIR)/lib$(Project).a 
