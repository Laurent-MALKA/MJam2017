###  TODO  #####################################################################

# entrer les flags des biblioteques
# entrer les noms des fichiers objets
# entrer le nom de l'executable
# entrer les dependances
# changer CX ou CC pour compiler

# optionnel :
# changer les noms des repertoires

###  VARIABLES  ################################################################

CC=gcc
CX=g++

BLD_REP=../build/
SRC_REP=../src/
EXE_REP=./

CFLAGS=-Wall -Wextra
      #-MMD -O2
      #-ansi -pedantic
      #-Wchar-subscripts -Wdouble-promotion
      #-Werror -Wcomment -Wformat
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf
INCLUDES=

OBJ=
EXE=mJam


###  ADAPTATION  ###############################################################

BLD_O=$(addprefix $(BLD_REP),%.o)
SRC_O_CPP=$(addprefix $(SRC_REP),%.cpp)
SRC_O_CC=$(addprefix $(SRC_REP),%.cc)
SRC_O_C=$(addprefix $(SRC_REP),%.c)
BLD_OBJ=$(addprefix $(BLD_REP),$(OBJ))
EXEC=$(addprefix $(EXE_REP),$(EXE))


###  COMPILATION  ##############################################################

$(EXEC): $(BLD_OBJ)
	$(CX) $^ -o $@ $(LDFLAGS)
#	$(CC) $^ -o $@ $(LDFLAGS)


###  DEPENDANCES  ##############################################################



###  REGLES D'INFERENCES  ######################################################

$(BLD_O): $(SRC_O_CPP)
	$(CX) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BLD_O): $(SRC_O_CC)
	$(CX) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BLD_O): $(SRC_O_C)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<


###  COMMANDES  ################################################################

.PHONY: clean cleaner exec

exec:
	@$(EXEC)

clean:
	@rm -rf $(BLD_OBJ)
	@echo $(BLD_REP) :
	@ls $(BLD_REP)

cleaner: clean
	@rm -rf $(EXEC)
	@echo $(EXE_REP) :
	@ls $(EXE_REP)


###  AUTRES COMMENTAIRES  ######################################################

# $@    cible
# $<    premiere dependance
# $^    liste dependance
# $*    fichier sans suffixe

################################################################################
