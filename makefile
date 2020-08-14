# ______________ parametres de compilation
CFLAGS= -Wall --pedantic

# ______________ excecutables
all: mastermind

# mastermind-demo
mastermind: main_vue_mastermind.o vue_mastermind.o mastermind.o stat-essai.o combinaison.o 
	gcc $^ -o $@ `pkg-config --cflags --libs gtk+-2.0`

mastermind-demo.o: src/mastermind-demo.c inc/mastermind.h inc/combinaison.h inc/stat-essai.h
	gcc -c $< -o $@ $(CFLAGS) 

# ______________ objets bibliothèque

# mastermind
mastermind.o: src/mastermind.c inc/mastermind.h inc/combinaison.h inc/stat-essai.h
	gcc -c $< -o $@ $(CFLAGS)

# combinaison
combinaison.o: src/combinaison.c inc/combinaison.h
	gcc -c $< -o $@ $(CFLAGS)

# stat-essai
stat-essai.o: src/stat-essai.c inc/stat-essai.h
	gcc -c $< -o $@ $(CFLAGS) 

vue_mastermind.o: src/vue_mastermind.c inc/vue_mastermind.h
	gcc -c $< -o $@ $(CFLAGS) `pkg-config --cflags --libs gtk+-2.0`

main_vue_mastermind.o: src/main_vue_mastermind.c inc/vue_mastermind.h
	gcc -c $< -o $@ $(CFLAGS) `pkg-config --cflags --libs gtk+-2.0`
# vue_mastermind


# ______________ nettoyage
clean:
	rm -rf *.o


