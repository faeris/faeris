PROJECT=grlib
  
SRC= sl_simple_str.cc sl_single_quote_str.cc sl_double_quote_str.cc \
	 sl_white_space.cc sl_comment.cc sl_specific_symbol.cc xir_file.cc \
	 xir_scanner.cc sl_top.cc  xir_token.cc  xir_parser.cc \
	 xir_grammer.cc  xir_ast.cc


DEBUG=

BIN= scanner_test.cc  lexical_test.cc  parser_test.cc ast_test.cc



OBJ_NAME=$(SRC:%.cc=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix obj/,$(OBJ_NAME))

DEBUG_OBJ_NAME=$(DEBUG:%.cc=%.o) 
DEBUG_OBJ_NAME_WITH_PATH=$(addprefix obj/,$(DEBUG_OBJ_NAME))

ALL_OBJ=$(OBJ_NAME) $(DEBUG_OBJ_NAME)
ALL_OBJ_WITH_PATH= $(OBJ_NAME_WITH_PATH) $(DEBUG_OBJ_NAME_WITH_PATH)



BIN_NAME=$(BIN:%.cc=%.exe)
BIN_NAME_WITH_PATH=$(addprefix bin/,$(BIN_NAME))

BIN_OBJ_NAME=$(BIN:%.cc=%.o)
BIN_OBJ_NAME_WITH_PATH=$(addprefix obj/,$(BIN_OBJ_NAME))

CC=g++
FLAGS=-g -Wall  -Werror -include sys/types.h
INCLUDE=-I. -I./debug   -I../  
LIB=-Llib -L../lib -l$(PROJECT) -l$(PROJECT)debug  -lfyutil -lio




main: obj lib bin $(ALL_OBJ_WITH_PATH) $(BIN_OBJ_NAME_WITH_PATH) \
   	$(BIN_NAME_WITH_PATH)  lib/lib$(PROJECT).a

lib/lib$(PROJECT).a:$(OBJ_NAME_WITH_PATH) ../lib 
	ar cr $@ $(OBJ_NAME_WITH_PATH)
	cp $@ ../lib/

lib/lib$(PROJECT)debug.a:$(DEBUG_OBJ_NAME_WITH_PATH)
	ar cr $@ $(DEBUG_OBJ_NAME_WITH_PATH)


bin/%.exe:obj/%.o lib/lib$(PROJECT).a lib/lib$(PROJECT)debug.a 
	$(CC) $(FLAGS) -o $@ $< -Xlinker "-(" $(LIB) -Xlinker "-)"

obj/%.o:%.cc
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE) 

obj/%.o:debug/%.cc
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE) 
	
xir_grammer.cc:xir_grammer.y
	bison xir_grammer.y -o xir_grammer.cc
	
init:
	mkdir -p obj 
	mkdir -p bin
	mkdir -p lib
obj:
	mkdir -p obj
bin:
	mkdir -p bin
lib:
	mkdir -p lib 
../lib:
	mkdir -p ../lib 

rm:
	rm -f obj/*
	rm -f lib/*
	rm -f bin/*.exe
	rm -f ../lib/lib$(PROJECT).a
clear:
	rm -rf obj 
	rm -rf bin 
	rm -rf lib 


depend:
	echo -n >.$(PROJECT).dep
	for element in $(addprefix debug/,$(BIN)) $(SRC) $(addprefix debug/,$(DEBUG));do \
		file_name=`basename $$element`;\
		result=`echo $$file_name | sed -e 's/.c/.o/'`;\
		gcc -M -MT "obj/$$result" $$element $(INCLUDE) >>.$(PROJECT).dep ;\
	done

-include .$(PROJECT).dep

