# Nom de l'exécutable final :
EXEC = crashTech

# Liste des fichiers sources à compiler :
SRC = main.c csv.c annee.c 

# Compilateur ("gcc") :
CC = gcc

# Options de compilation :
CFLAGS = -Wall -Wextra -std=c11

# Crée l'exécutable final :
all: $(EXEC)

# Compile les fichiers sources en un seul programme :
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Supprime l'exécutable généré :
clean:
	rm -f $(EXEC)

# Nettoie tout et recompile :
re: clean all

