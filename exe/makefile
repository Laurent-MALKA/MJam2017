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

CFLAGS=-Wall -Wextra -std=c++11 -Wreorder -g
      #-MMD -O2
      #-ansi -pedantic
      #-Wchar-subscripts -Wdouble-promotion
      #-Werror -Wcomment -Wformat
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf
INCLUDES=

OBJ=Animation.o BeerBar.o Biere.o Body.o Bonus.o Cola.o Display.o Grappin.o\
    Image.o Inputs.o Jeu.o main.o Map.o Moteur.o Obstacle.o Perso.o Touches.o\
	 Teleporteur.o
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

Animation.o: Animation.cpp Animation.hpp
BeerBar.o: BeerBar.cpp BeerBar.hpp Body.hpp
Biere.o: Biere.cpp Biere.hpp
Body.o: Body.cpp Body.hpp
Bonus.o: Bonus.cpp Bonus.hpp Body.hpp Perso.hpp
Cola.o: Cola.cpp Cola.hpp Bonus.hpp
Display.o: Display.cpp Display.hpp Image.hpp Perso.hpp Map.hpp Biere.hpp
Grappin.o: Grappin.cpp Grappin.hpp Body.hpp Perso.hpp
Image.o: Image.cpp Image.hpp
Inputs.o: Inputs.cpp Inputs.hpp Perso.hpp
Jeu.o: Jeu.cpp Jeu.hpp Inputs.hpp Display.hpp Moteur.hpp Map.hpp
main.o: main.cpp *.hpp
Map.o: Map.cpp Map.hpp Perso.hpp Obstacle.hpp
Moteur.o: Moteur.cpp Moteur.hpp Inputs.hpp
Obstacle.o: Obstacle.cpp Obstacle.hpp Body.hpp
Perso.o: Perso.cpp Perso.hpp Touches.hpp Bonus.hpp Body.hpp Animation.hpp
Teleporteur.o: Teleporteur.cpp Teleporteur.hpp Perso.hpp
Touches.o: Touches.cpp Touches.hpp

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
