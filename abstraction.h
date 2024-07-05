#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct pieces_t {
  char type;
  char couleur;
  int pos_col;
  int pos_line;
  int shift[32][2];
  int nb_shift;
  bool en_vie;
  int place;
};

struct cases_t {
  int col;
  int line;
  bool use;
  struct pieces_t p;
};
typedef struct pieces_t pieces;
typedef struct cases_t cases;

struct parties_t {
  cases** plat;
  pieces** liste;
  int* liste_coups[2];
  int* valeur_coups;
  int* proba_coups;
  int nb_coups;
  int coup_depuis_pions;
  pieces* piece_coups;
};
typedef struct parties_t parties;

struct quants_t {
  parties partie;
  int coups[2];
  int valeur;
  int proba;
  pieces piece;
};
typedef struct quants_t quants;

#define NB_col 8
#define NB_line 8

cases **creer_plateau();
// creer un plateau remplie de piece en position de depart
// Entree: rien
// Sortie: matrice de l'echequier
pieces **liste_pieces(cases **plat);
// creer 2 listes des pieces
// Entree: plateau
// Sortie: 2 liste des pieces 1 par joueurs
// Edbord: remplis le plateau avec les pieces
void remplir_plateau(cases **plat, pieces **liste);
// remplie un tableau par les pieces
// Entree: plateau et liste de pieces
// Sortie: rien
// Edbord: remplis les cases du tableau avec les pieces
void coups_cavaliers(pieces *piece, cases **plat);
void coups_fous(pieces *piece, cases **plat);
void coups_tours(pieces *piece, cases **plat);
void coups_dame(pieces *piece, cases **plat);
void coups_roi(pieces *piece, cases **plat);
void coups_pions(pieces *piece, cases **plat);
// Entree: une pieces et le plateau
// Sortie: rien
// Edbord: change les mouvement possible et nombre de mouvement des pieces
void print_plateau(cases **plat);
// Entree: un plateau
// Sortie: rien
// Edbord: affiche le plateau
void affiche_deplacement(pieces piece);
// Entree: une pieces 
// Sortie: rien
// Edbord: affiche les deplacements de la piece possibles
bool deplace(cases **plat, pieces **liste, int joueur, int* coup_depuis_pion );
// Entree: un plateau, une liste de pieces et le joueur
// Sortie: true si le coup est effectué false sinon
// Edbord: deplace la piece
void affiche_pieces_deplacable (pieces** liste, int joueur,cases** plat);
// Entree: une liste de pieces et le joueur
// Sortie: rien
// Edbord: affiche les pieces qui peuvent être deplacé
int** liste_deplacement(pieces** liste, int joueur, int* nb_deplacement);
// Entree: une liste de pieces, le joueur et le nombre de deplacement (init à 0)
// Sortie: un tableau de tableau de déplacement
// Edbord: modifie la valeur de nb_deplacement 
void print_plateau_smoke (cases** plat, pieces** liste, int joueur);
// Entree: un plateau, une liste de pieces et le joueur
// Sortie: rien
// Edbord: affiche le plateau avec les pieces
void partie ();
// Entree: rien
// Sortie: rien
// Edbord: lance une partie


void deplace_quant(parties* partie, int coup[2], pieces piece, int joueur, int* coup_depuis_pion);
// Entree: une partie, un coup, une piece, le joueur et le nombre de coup depuis le dernier pion joué
// Sortie: rien
// Edbord: deplace la piece et met à jour la partie
int heuristique_aleatoire(pieces** liste, cases** plat,int coup_depuis_pions, int joueur);
// Entree: une liste de pieces, le plateau, le nombre de coup depuis le dernier pion joué et le joueur
// Sortie: -1, 0 ou 1 suivant le vainqueur en finissant la partie aléatoirement
// Edbord: rien
int* minimax (parties partie, int depth, int joueur, int jmax);
// Entree: une partie, la profondeur, le joueur et le joueur en train de joué (joueur max)
// Sortie: un tableau de valeur
// Edbord: modifie la variable partie en ajoutant les coups, leur valeur et leur probabilité d'être joué
parties meilleurs_coups_par_parties (parties partie, int joueur, int nb);
// Entree: une partie, le joueur et le nombre de meilleurs coups voulu
// Sortie: une partie composé d'un plateau et des meilleurs coups, leur valeurs et leur probabilité d'être joué
// Edbord: rien
void meilleurs_coups (parties* tab_partie, int joueur, int nb);
// Entree: un tableau de parties, le joueur et le nombre de partie
// Sortie: rien
// Edbord: joue le "meilleur coup" 
void partie_minimax();
// Entree: rien
// Sortie: rien
// Edbord: lance une partie entre 2 minimax



#endif
