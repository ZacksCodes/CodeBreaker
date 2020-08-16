#ifndef COMBINAISON_H

#define COMBINAISON_H

enum e_couleur {
	COULEUR_INDETERMINEE = 0,
	COULEUR_ROUGE,
	COULEUR_VERT,
	COULEUR_BLEU,
	COULEUR_MAUVE,
	COULEUR_ORANGE,
	COULEUR_JAUNE,
	COULEUR_BLANC,
	COULEUR_NOIR
};

#define COULEUR_MIN (COULEUR_INDETERMINEE + 1)


typedef enum e_couleur couleur ;

#define TAILLE_COMBI 4

typedef couleur combinaison[TAILLE_COMBI];

/*	______________________________________
	Intialisation						*/

/* Cette fonction initialise toutes les composantes d'une combinaison à COULEUR_INDETERMINEE
	Pré-condition : c est bien un tableau de TAILLE_COMBI variables de type couleur
*/
void combinaison_initialiser(combinaison c);

/* Cette fonction attribue aléatoirement une couleur dans {COULEUR_MIN ,..., COULEUR_MAX} à chaque composante d'une combinaison
	Pré-conditions : 
	- c est bien un tableau de TAILLE_COMBI variables de type couleur;
	- pour obtenir des générations aléatoires d'une exécution à l'autre, la graine aléatoire doit avoir été préalablement initialisée par appel à srand()
*/
void combinaison_tirer_au_hasard(combinaison c, int nb);

/*	______________________________________
	Accesseurs en lecture / écriture		*/

/* Cette fonction affecte une couleur à une composante d'une combinaison
	Pré-conditions : c est bien un tableau de TAILLE_COMBI variables de type couleur, 1 <= cle <= TAILLE_COMBI 
	Post-condition : la composante n°cle de la combinaison est de couleur val
*/
void combinaison_set_couleur(combinaison c, int cle, couleur val);

/* Cette fonction renvoie la couleur d'une composante d'une combinaison
	Pré-conditions : c est bien un tableau de TAILLE_COMBI variables de type couleur, 1 <= cle <= TAILLE_COMBI 
	Valeur retournée : la couleur de la composante n°cle de la combinaison
*/
couleur combinaison_get_couleur(combinaison c, int cle);

/*	______________________________________
	Accesseurs en lecture avancés		*/

/* Cette fonction teste si toutes les couleurs d'une combinaison sont à valeur dans {COULEUR_MIN ,..., COULEUR_MAX}
	Pré-condition : c est bien un tableau de TAILLE_COMBI variables de type couleur
	Valeur retournée : 1 si le test est réussi, 0 sinon 
*/
int combinaison_est_valide(combinaison c);

/* Cette fonction compare la combinaison c_source à la combinaison c_cible en tenant compte de l'ordre des éléments
	Pré-condition : c est bien un tableau de TAILLE_COMBI variables de type couleur
	Valeur retournée : si l'on note n = TAILLE_COMBI, c_source est la combinaison (a_1 ,..., a_n) et c_cible est la combinaison (b_1 ,..., b_n), 
						alors la fonction renvoie le nombre d'indices r dans {1 ,..., n} pour lesquels a_r = b_r
*/
int combinaison_cmp_ordonnee(combinaison c_source, combinaison c_cible);

/* Cette fonction compare la restriction des combinaisons c_source et c_cible aux couleurs {COULEUR_MIN ,..., COULEUR_MAX} sans tenir compte de l'ordre des éléments
	Pré-condition : c est bien un tableau de TAILLE_COMBI variables de type couleur
	Valeur retournée : si l'on note n = NB_COULEURS et que l'on numérote les NB_COULEURS couleurs de 1 à n, 
						si l'on note encore pour r = 1 ,..., n par a_r et b_r le nombre d'occurrences de la couleur n°r dans respectivement c_source et c_cible,
						alors la fonction renvoie min{a_1, b_1} +...+ min{a_n, b_n} 
*/
int combinaison_cmp_ensembliste(combinaison c_source, combinaison c_cible);

#endif

