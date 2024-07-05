#include "abstraction.h"

pieces NONE = {.type = '-',.couleur = 'R',.pos_col = -1,.pos_line = -1,.nb_shift = 0,.en_vie = false,.place=-1,};

cases **creer_plateau() {
  cases **plat = (cases **)malloc(8 * sizeof(cases *));
  for (int i = 0; i < 8; i += 1) {
    cases *col = (cases *)malloc(8 * sizeof(cases));
    for (int j = 0; j < 8; j += 1) {
      for (int i = 0; i < 32; i += 1) {
        NONE.shift[i][0] = -1;NONE.shift[i][1] = -1;
      }
      cases c;c.col = i;c.line = j;c.use = false;c.p = NONE;
      col[j] = c;
    }
    plat[i] = col;
  }
  for (int i = 0; i < 8; i += 1) {
    plat[i][0].use = true;
    plat[i][1].use = true;
    plat[i][0].p.couleur = 'B';
    plat[i][1].p.couleur = 'B';
  }
  for (int i = 0; i < 8; i += 1) {
    plat[i][6].use = true;
    plat[i][7].use = true;
    plat[i][6].p.couleur = 'N';
    plat[i][7].p.couleur = 'N';
  }
  return plat;
}

pieces **liste_pieces(cases **plat) {
  pieces **liste = malloc(2 * sizeof(pieces *));
  pieces *liste_Blanc = malloc(16 * sizeof(pieces));
  pieces *liste_Noir = malloc(16 * sizeof(pieces));
  // Blanc
  pieces tour_a1={.type = 'T',.couleur = 'B',.pos_col = 0,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=0};
  pieces tour_h1={.type = 'T',.couleur = 'B',.pos_col = 7,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=7};
  coups_tours(&tour_a1, plat);coups_tours(&tour_h1, plat);
  pieces cavalier_b1={.type = 'C',.couleur = 'B',.pos_col = 1,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=1};
  pieces cavalier_g1={.type = 'C',.couleur = 'B',.pos_col = 6,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=6};
  coups_cavaliers(&cavalier_b1, plat);coups_cavaliers(&cavalier_g1, plat);
  pieces fou_c1={.type = 'F',.couleur = 'B',.pos_col = 2,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=2};
  pieces fou_f1={.type = 'F',.couleur = 'B',.pos_col = 5,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=5};
  coups_fous(&fou_c1, plat);coups_fous(&fou_f1, plat);
  pieces roi_e1={.type = 'R',.couleur = 'B',.pos_col = 4,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=4};
  pieces dame_d1={.type = 'D',.couleur = 'B',.pos_col = 3,.pos_line = 0,.nb_shift = 0,.en_vie = true,.place=3};
  coups_roi(&roi_e1, plat);coups_dame(&dame_d1, plat);
  liste_Blanc[0] = tour_a1;liste_Blanc[7] = tour_h1;liste_Blanc[1] = cavalier_b1;liste_Blanc[6] = cavalier_g1;liste_Blanc[2] = fou_c1;liste_Blanc[5] = fou_f1;liste_Blanc[3] = dame_d1;liste_Blanc[4] = roi_e1;
  for (int i = 8; i < 16; i += 1) {
    pieces pion = {.type = 'P',.couleur = 'B',.pos_col = i-8,.pos_line =1,.nb_shift = 0,.en_vie = true,.place=i};
    coups_pions(&pion, plat);
    liste_Blanc[i] = pion;
  }
  // Noirs
  pieces tour_a8={.type = 'T',.couleur = 'N',.pos_col = 0,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=0};
  pieces tour_h8={.type = 'T',.couleur = 'N',.pos_col = 7,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=7};
  coups_tours(&tour_a8, plat);coups_tours(&tour_h8, plat);
  pieces cavalier_b8={.type = 'C',.couleur = 'N',.pos_col = 1,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=1};
  pieces cavalier_g8={.type = 'C',.couleur = 'N',.pos_col = 6,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=6};
  coups_cavaliers(&cavalier_b8, plat);coups_cavaliers(&cavalier_g8, plat);
  pieces fou_c8={.type = 'F',.couleur = 'N',.pos_col = 2,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=2};
  pieces fou_f8={.type = 'F',.couleur = 'N',.pos_col = 5,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=5};
  coups_fous(&fou_c8, plat);coups_fous(&fou_f8, plat);
  pieces roi_e8={.type = 'R',.couleur = 'N',.pos_col = 4,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=4};
  pieces dame_d8={.type = 'D',.couleur = 'N',.pos_col = 3,.pos_line = 7,.nb_shift = 0,.en_vie = true,.place=3};
  coups_roi(&roi_e8, plat);coups_dame(&dame_d8, plat);
  liste_Noir[0] = tour_a8;liste_Noir[7] = tour_h8;liste_Noir[1] = cavalier_b8;liste_Noir[6] = cavalier_g8;liste_Noir[2] = fou_c8;liste_Noir[5] = fou_f8;liste_Noir[3] = dame_d8;liste_Noir[4] = roi_e8;
  for (int i = 8; i < 16; i += 1) {
    pieces pion={.type = 'P',.couleur = 'N',.pos_col = i-8,.pos_line = 6,.nb_shift = 0,.en_vie = true,.place=i};
    coups_pions(&pion, plat);
    liste_Noir[i] = pion;
  }
  liste[0] = liste_Blanc;liste[1] = liste_Noir;
  return liste;
}

void remplir_plateau(cases **plat, pieces **liste) {
  for (int i = 0; i < 16; i += 1) {
    int c = liste[0][i].pos_col;
    int l = liste[0][i].pos_line;
    plat[c][l].p = liste[0][i];
    plat[c][l].use = true;
  }
  for (int i = 0; i < 16; i += 1) {
    int c = liste[1][i].pos_col;
    int l = liste[1][i].pos_line;
    plat[c][l].p = liste[1][i];
    plat[c][l].use = true;
  }
}

void coups_cavaliers(pieces *piece, cases **plat) {
  int tab[8][2] = {{piece->pos_col + 2, piece->pos_line + 1},
                   {piece->pos_col + 2, piece->pos_line - 1},
                   {piece->pos_col + 1, piece->pos_line - 2},
                   {piece->pos_col - 1, piece->pos_line - 2},
                   {piece->pos_col - 2, piece->pos_line - 1},
                   {piece->pos_col - 2, piece->pos_line + 1},
                   {piece->pos_col - 1, piece->pos_line + 2},
                   {piece->pos_col + 1, piece->pos_line + 2}};
  int j = 0;
  int shift[32][2];
  for (int i = 0; i < 8; i += 1) {
    if ((tab[i][0] >= 0) && (tab[i][1] >= 0) && (tab[i][0] < 8) &&
        (tab[i][1] < 8)) {
      if (plat[tab[i][0]][tab[i][1]].use == false) {
        shift[j][0] = tab[i][0];
        shift[j][1] = tab[i][1];
        j += 1;
      } else if (plat[tab[i][0]][tab[i][1]].p.couleur != piece->couleur) {
        shift[j][0] = tab[i][0];
        shift[j][1] = tab[i][1];
        j += 1;
      }
    }
  }
  piece->nb_shift = j;
  for (int i = 0; i < j; i += 1) {
    piece->shift[i][0] = shift[i][0];
    piece->shift[i][1] = shift[i][1];
  }
}

void coups_fous(pieces *piece, cases **plat) {
  int shift[32][2];
  int x = piece->pos_col; int y = piece->pos_line; 
  int j = 0;
  int i = 1;
  while (x - i >= 0 && y - i >= 0) {
    if (plat[x - i][y - i].use == false) {
      shift[j][0] = x - i;
      shift[j][1] = y-i;
      j += 1;
    }
    if (plat[x - i][y - i].use) {
      if (plat[x - i][y - i].p.couleur != piece->couleur) {
        shift[j][0] = x - i;
        shift[j][1] = y-i;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  i = 1;
  while (x - i >= 0 && y + i < 8) {
    if (plat[x - i][y + i].use == false) {
      shift[j][0] = x - i;
      shift[j][1] = y+i;
      j += 1;
    }
    if (plat[x - i][y + i].use) {
      if (plat[x - i][y + i].p.couleur != piece->couleur) {
        shift[j][0] = x - i;
        shift[j][1] = y+i;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  i = 1;
  while (x + i < 8 && y + i < 8) {
    if (plat[x + i][y + i].use == false) {
      shift[j][0] = x + i;
      shift[j][1] = y+i;
      j += 1;
    }
    if (plat[x + i][y + i].use) {
      if (plat[x + i][y + i].p.couleur != piece->couleur) {
        shift[j][0] = x +i;
        shift[j][1] = y+i;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  while (x + i < 8 && y - i >= 0) {
    if (plat[x + i][y - i].use == false) {
      shift[j][0] = x + i;
      shift[j][1] = y-i;
      j += 1;
    }
    if (plat[x + i][y - i].use) {
      if (plat[x + i][y - i].p.couleur != piece->couleur) {
        shift[j][0] = x + i;
        shift[j][1] = y-i;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  piece->nb_shift = j;
  for (int i = 0; i < j; i += 1) {
    piece->shift[i][0] = shift[i][0];
    piece->shift[i][1] = shift[i][1];
  }
}

void coups_tours(pieces *piece, cases **plat) {
  int shift[32][2];
  int x = piece->pos_col; int y = piece->pos_line;
  int j = 0;
  int i = 1;
  while (x - i >= 0) {
    if (plat[x - i][y].use == false) {
      shift[j][0] = x - i;
      shift[j][1] = y;
      j += 1;
    }
    if (plat[x - i][y].use) {
      if (plat[x - i][y].p.couleur != piece->couleur) {
        shift[j][0] = x - i;
        shift[j][1] = y;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  i = 1;
  while (x + i < 8) {
    if (plat[x + i][y].use == false) {
      shift[j][0] = x + i;
      shift[j][1] = y;
      j += 1;
    }
    if (plat[x + i][y].use == true) {
      if (plat[x + i][y].p.couleur != piece->couleur) {
        shift[j][0] = x + i;
        shift[j][1] = y;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  i = 1;
  while (y - i >= 0) {
    if (plat[x][y - i].use == false) {
      shift[j][0] = x;
      shift[j][1] = y-i;
      j += 1;
    }
    if (plat[x][y - i].use) {
      if (plat[x][y - i].p.couleur != piece->couleur) {
        shift[j][0] = x ;
        shift[j][1] = y-i;
        j += 1;
      }
      break;
    }
    i += 1;
  }
  i = 1;
  while (y + i < 8) {
    if (plat[x][y + i].use == false) {
      shift[j][0] = x;
      shift[j][1] = y+i;
      j += 1;
    }
    if (plat[x][y + i].use) {
      if (plat[x][y + i].p.couleur != piece->couleur) {
        shift[j][0] = x;
        shift[j][1] = y+i;
        j += 1;
      }
      break;
    }
    i += 1;
  }

  piece->nb_shift = j;
  for (int i = 0; i < j; i += 1) {
    piece->shift[i][0] = shift[i][0];
    piece->shift[i][1] = shift[i][1];
  }
}

void coups_dame(pieces *piece, cases **plat) {
  pieces fou = {.type = 'F', .couleur = piece->couleur,.pos_col = piece->pos_col,.pos_line = piece->pos_line,.nb_shift = 0,.en_vie = true,.place=piece->place};
  pieces tour = {.type = 'T', .couleur = piece->couleur,.pos_col = piece->pos_col,.pos_line = piece->pos_line,.nb_shift = 0,.en_vie = true,.place=piece->place};
  
  coups_fous(&fou, plat);
  coups_tours(&tour, plat);
  int jf=fou.nb_shift;
  int jt=tour.nb_shift;
  int j = jf + jt;
  piece->nb_shift= j;
  for (int i = 0; i < jf; i += 1) {
    piece->shift[i][0] = fou.shift[i][0];
    piece->shift[i][1] = fou.shift[i][1];
  }
  for (int i = jf; i < j; i += 1) {
    piece->shift[i][0] = tour.shift[i-jf][0];
    piece->shift[i][1] = tour.shift[i-jf][1];
  }
}

void coups_roi(pieces *piece, cases **plat) {
  int tab[8][2] = {{piece->pos_col + 1, piece->pos_line + 1},
                   {piece->pos_col + 1, piece->pos_line},
                   {piece->pos_col + 1, piece->pos_line - 1},
                   {piece->pos_col, piece->pos_line - 1},
                   {piece->pos_col - 1, piece->pos_line - 1},
                   {piece->pos_col - 1, piece->pos_line},
                   {piece->pos_col - 1, piece->pos_line + 1},
                   {piece->pos_col, piece->pos_line + 1}};
  int j = 0;
  int shift[32][2];

  for (int i = 0; i < 8; i += 1) {
    if ((tab[i][0] >= 0) && (tab[i][1] >= 0) && (tab[i][0] < 8) &&
        (tab[i][1] < 8)) {
      if (plat[tab[i][0]][tab[i][1]].use == false) {
        shift[j][0] = tab[i][0];
        shift[j][1] = tab[i][1];
        j += 1;
      } else if ((plat[tab[i][0]][tab[i][1]].p.couleur != piece->couleur)) {
        shift[j][0] = tab[i][0];
        shift[j][1] = tab[i][1];
        j += 1;
      }
    }
  }
  piece->nb_shift = j;
  for (int i = 0; i < j; i += 1) {
    piece->shift[i][0] = shift[i][0];
    piece->shift[i][1] = shift[i][1];
  }
}

void coups_pions(pieces *piece, cases **plat) {
  int shift[32][2];
  int j = 0;
  if (piece->couleur == 'B') {
    if (piece->pos_line == 1 &&
        plat[piece->pos_col][piece->pos_line + 1].use == false &&
        plat[piece->pos_col][piece->pos_line + 2].use == false) {
      shift[j][0] = piece->pos_col;
      shift[j][1] = piece->pos_line + 2;
      j += 1;
    }
    if (plat[piece->pos_col][piece->pos_line + 1].use == false) {
      shift[j][0] = piece->pos_col;
      shift[j][1] = piece->pos_line + 1;
      j += 1;
    }
    if (piece->pos_col != 7 &&
        plat[piece->pos_col + 1][piece->pos_line + 1].use) {
      if (plat[piece->pos_col + 1][piece->pos_line + 1].p.couleur == 'N') {
        shift[j][0] = piece->pos_col + 1;
        shift[j][1] = piece->pos_line + 1;
        j += 1;
      }
    }
    if (piece->pos_col != 0 &&
        plat[piece->pos_col - 1][piece->pos_line + 1].use) {
      if (plat[piece->pos_col - 1][piece->pos_line + 1].p.couleur == 'N') {
        shift[j][0] = piece->pos_col - 1;
        shift[j][1] = piece->pos_line + 1;
        j += 1;
      }
    }
  }
  if (piece->couleur == 'N') {
    if (piece->pos_line == 6 &&
        plat[piece->pos_col][piece->pos_line - 1].use == false &&
        plat[piece->pos_col][piece->pos_line - 2].use == false) {
      shift[j][0] = piece->pos_col;
      shift[j][1] = piece->pos_line - 2;
      j += 1;
    }
    if (plat[piece->pos_col][piece->pos_line - 1].use == false) {
      shift[j][0] = piece->pos_col;
      shift[j][1] = piece->pos_line - 1;
      j += 1;
    }
    if (piece->pos_col != 7 &&
        plat[piece->pos_col + 1][piece->pos_line - 1].use) {
      if (plat[piece->pos_col + 1][piece->pos_line - 1].p.couleur == 'B') {
        shift[j][0] = piece->pos_col + 1;
        shift[j][1] = piece->pos_line - 1;
        j += 1;
      }
    }
    if (piece->pos_col != 0 &&
        plat[piece->pos_col - 1][piece->pos_line - 1].use) {
      if (plat[piece->pos_col - 1][piece->pos_line - 1].p.couleur == 'B') {
        shift[j][0] = piece->pos_col - 1;
        shift[j][1] = piece->pos_line - 1;
        j += 1;
      }
    }
  }
  piece->nb_shift = j;
  for (int i = 0; i < j; i += 1) {
    piece->shift[i][0] = shift[i][0];
    piece->shift[i][1] = shift[i][1];
  }
}

void print_plateau(cases **plat) {
  printf("\n\n");
  int T[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  for (int i = 7; i >= 0; i -= 1) {
    printf("%d  ", i + 1);
    for (int j = 0; j < 8; j += 1) {
      if (plat[j][i].p.couleur == 'B' && plat[j][i].p.en_vie) {
        printf("\033[0;34m");
        printf("%c ", plat[j][i].p.type);
        printf("\033[0m");
      } 
      else if (plat[j][i].p.couleur == 'N' && plat[j][i].p.en_vie) {
        printf("%c ", plat[j][i].p.type);
      }
      else{
        printf("%c ", '-');
      }
    }
    printf("\n");
  }
  printf("   ");
  for (int i = 0; i < 8; i += 1) {
    printf("%c ", T[i]);
  }
  printf("\n\n");
}

void affiche_deplacement(pieces piece) {
  if (piece.nb_shift == 0) {
    printf("pas de deplacement");
  }
  for (int i = 0; i < piece.nb_shift; i += 1) {
    printf("%c%d  ", (piece.shift[i][0] + 97), piece.shift[i][1] + 1);
  }
  printf("\n");
}

bool appartient_deplacement(int coup[2], pieces piece) {
  for (int i = 0; i < piece.nb_shift; i += 1) {
    if (coup[0] == piece.shift[i][0] && coup[1] == piece.shift[i][1]) {
      return true;
    }
  }
  return false;
}  

bool appartient_joueur(pieces piece, int joueur){
  if (piece.couleur == 'B' && joueur==0) {return true;}
  if (piece.couleur == 'N' && joueur==1) {return true;}
  return false;
}

bool deplace(cases** plat, pieces** liste, int joueur, int* coup_depuis_pion) {
  for (int i = 0; i < 32; i += 1) {
    NONE.shift[i][0] = -1;NONE.shift[i][1] = -1;
  }
  int ret;
  while (true){
    char c1;int v1;
    printf("piece a deplacer : ");
    ret=scanf(" %c%d", &c1, &v1);
    if(c1=='0'){affiche_pieces_deplacable(liste, joueur,plat);printf("\n");}
    else{
      pieces piece = plat[c1 - 'a'][v1 - 1].p;
      if (!appartient_joueur(piece,joueur)){printf("mauvaise piece\n");}
      else {
        affiche_deplacement(piece);
        printf("deplacement : ");
        char c2; int v2;
        ret=scanf(" %c%d", &c2, &v2);
        int coup[2]={c2-'a',v2-1};
        if (appartient_deplacement(coup, piece)) {
          *coup_depuis_pion+=1;
          if (piece.type=='P'){*coup_depuis_pion=0;}
          if (plat[coup[0]][coup[1]].use) {
            if (piece.couleur == 'B') {
              liste[1][plat[coup[0]][coup[1]].p.place].en_vie=false;
            }
            if (piece.couleur == 'N') {
              liste[0][plat[coup[0]][coup[1]].p.place].en_vie=false;
            }
          }
          if (piece.type=='P' && (coup[1]==0 || coup[1]==7)){
            printf("promotion: C F T D ?\n");
            scanf(" %c", &piece.type);
          }
          
          plat[coup[0]][coup[1]].p.en_vie = false ;
          plat[piece.pos_col][piece.pos_line].p = NONE;
          plat[piece.pos_col][piece.pos_line].use = false;
          piece.pos_col = coup[0];
          piece.pos_line = coup[1];
          liste[joueur][piece.place]=piece;
          plat[coup[0]][coup[1]].p = piece;
          plat[coup[0]][coup[1]].use=true;
          
          for (int i=0;i<16;i+=1){
            pieces* p = &liste[0][i];
            if (p->en_vie){
              if (p->type=='P'){coups_pions(p, plat);}
              if (p->type=='T'){coups_tours(p, plat);}
              if (p->type=='C'){coups_cavaliers(p, plat);}
              if (p->type=='F'){coups_fous(p, plat);}
              if (p->type=='D'){coups_dame(p, plat);}
              if (p->type=='R'){coups_roi(p, plat);}
              liste[0][p->place] = *p;
              plat[p->pos_col][p->pos_line].p = *p;
            }
          }
          for (int i=0;i<16;i+=1){
            pieces* p = &liste[1][i];
            if (p->en_vie){
              if (p->type=='P'){coups_pions(p, plat);}
              if (p->type=='T'){coups_tours(p, plat);}
              if (p->type=='C'){coups_cavaliers(p, plat);}
              if (p->type=='F'){coups_fous(p, plat);}
              if (p->type=='D'){coups_dame(p, plat);}
              if (p->type=='R'){coups_roi(p, plat);}
              liste[1][p->place] = *p;
              plat[p->pos_col][p->pos_line].p = *p;
            }
          }
          ret+=1;
          return true;
        } 
        else {printf("deplacement pas possible\n");}
      }
    }
  }
}

void affiche_pieces_deplacable (pieces** liste,int joueur,cases** plat){
  printf("\n");
  for (int i=0;i<16;i+=1){
    if (liste[joueur][i].en_vie && liste[joueur][i].nb_shift!=0){
      printf("%c%d  ", (liste[joueur][i].pos_col + 97), liste[joueur][i].pos_line + 1);
    }
  }
  char c1;int v1;
  printf("piece a deplacer : ");
  scanf(" %c%d", &c1, &v1);
  affiche_deplacement(liste[joueur][plat[c1 - 'a'][v1 - 1].p.place]);
}

bool appartient_liste (int** deplacement, int coup[2], int nb_deplacement){
  for (int i=0;i<nb_deplacement;i+=1){
    if (deplacement[i][0]==coup[0] && deplacement[i][1]==coup[1]){
      return true;
      }
    }
  return false;
}

int** liste_deplacement (pieces** liste, int joueur, int* nb_deplacement){
  int** deplacement = malloc(sizeof(int*)*64);
  *nb_deplacement=0;
  for (int i=0;i<16;i+=1){
    if (liste[joueur][i].en_vie) {
      for (int j=0;j<liste[joueur][i].nb_shift;j+=1){
        if (!appartient_liste(deplacement, liste[joueur][i].shift[j],*nb_deplacement)){
          deplacement[*nb_deplacement]=malloc(2*sizeof(int));
          deplacement[*nb_deplacement][0]=liste[joueur][i].shift[j][0];
          deplacement[*nb_deplacement][1]=liste[joueur][i].shift[j][1];
          *nb_deplacement+=1;
          }
        }
      }
    }
  return deplacement;
}

pieces* liste_pieces_deplacable (pieces** liste, int joueur, int* nb){
  pieces* pieces_deplacable = malloc(sizeof(pieces)*16);
  *nb=0;
  for (int i=0;i<16;i+=1){
    if (liste[joueur][i].en_vie && liste[joueur][i].nb_shift!=0){
      pieces_deplacable[*nb]=liste[joueur][i];
      *nb +=1;
    }
  }
  return pieces_deplacable;
}    

void print_plateau_smoke (cases** plat, pieces** liste, int joueur){
  int nb_deplacement=0;
  int** deplacement=liste_deplacement(liste, (joueur+1)%2, &nb_deplacement);
  printf("\n\n");
  int T[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  if (joueur==1){
    for (int i = 7; i >= 0; i -= 1) {
      printf("%d  ", i + 1);
      for (int j = 0; j < 8; j += 1) {
        int coup[2]= {j,i};
        if (plat[j][i].p.couleur == 'B' && plat[j][i].p.en_vie){
           printf("\033[0;34m");
           printf("%c ", plat[j][i].p.type);
           printf("\033[0m");
        }
        else if (appartient_liste(deplacement, coup, nb_deplacement)){
          if (plat[j][i].p.couleur == 'N' && plat[j][i].p.en_vie) {
            printf("%c ", plat[j][i].p.type);
          }
          else{
            printf("%c ", '-');
          }
        }
        else {
          printf("\033[0;31m");
          printf("%c ",'X');
          printf("\033[0m");
        }
      }
      printf("\n");
    }
  }
    
  else if (joueur==0){
    for (int i = 7; i >= 0; i -= 1) {
      printf("%d  ", i + 1);
      for (int j = 0; j < 8; j += 1) {
        int coup[2]= {j,i};
        if (plat[j][i].p.couleur == 'N' && plat[j][i].p.en_vie){
           printf("%c ", plat[j][i].p.type);
        }
        else if (appartient_liste(deplacement, coup, nb_deplacement)){
          if (plat[j][i].p.couleur == 'B' && plat[j][i].p.en_vie) {
            printf("\033[0;34m");
            printf("%c ", plat[j][i].p.type);
            printf(" \033[0m");
          }
          else{
            printf("%c ", '-');
          }
        }
        else {
          printf("\033[0;31m");
          printf("%c ",'X');
          printf("\033[0m");
        }
      }
            printf("\n");
    }
  }
  printf("   ");
  for (int i = 0; i < 8; i += 1) {
    printf("%c ", T[i]);
  }
  printf("\n\n");
}

void partie (){
  cases **plateau = creer_plateau();
  pieces **liste = liste_pieces(plateau);
  remplir_plateau(plateau, liste);
  print_plateau_smoke(plateau, liste, 1);
  int joueur = 0;
  int coup_depuis_pion=0;
  while (liste[0][4].en_vie && liste[1][4].en_vie){
    deplace(plateau, liste,joueur, &coup_depuis_pion);
    
    print_plateau_smoke(plateau, liste, joueur);
    joueur=(joueur+1)%2;
    if (coup_depuis_pion==50){printf("égalité");break;}
  }
  print_plateau(plateau);
}

bool deplace_aleatoire(cases** plat, pieces** liste, int joueur, int* coup_depuis_pion){
  for (int i = 0; i < 32; i += 1) {
      NONE.shift[i][0] = -1;NONE.shift[i][1] = -1;
    }
  int promotion[4] = {'D', 'T', 'C', 'F'};
  //char a;
  //scanf(" %c", &a);
  int nb_piece=0;
  pieces* pieces_deplacable = liste_pieces_deplacable(liste, joueur, &nb_piece);
  nb_piece =nb_piece -1;
  if (nb_piece==-1){return false;}
  while (true){
    srand(time(NULL));
    int indice_p = rand() % nb_piece;
    pieces piece = pieces_deplacable[indice_p];
    printf("%c%d -> ", piece.pos_col + 97, piece.pos_line + 1);
    int indice_d = rand() % piece.nb_shift;
    int c2 = piece.shift[indice_d][0]; 
    int v2 = piece.shift[indice_d][1];
    printf("%c%d\n", c2 + 97, v2 + 1);
    *coup_depuis_pion+=1;
    int coup[2]={c2,v2};
    if (piece.type=='P'){*coup_depuis_pion=0;}
    if (plat[coup[0]][coup[1]].use) {
       if (piece.couleur == 'B') {
          liste[1][plat[coup[0]][coup[1]].p.place].en_vie=false;
        }
        if (piece.couleur == 'N') {
          liste[0][plat[coup[0]][coup[1]].p.place].en_vie=false;
        }
    }
    if (piece.type=='P' && (coup[1]==0 || coup[1]==7)){
      int indice_prom = rand() % 4;
      piece.type=promotion[indice_prom];
    }
    
    plat[coup[0]][coup[1]].p.en_vie = false ;
    plat[piece.pos_col][piece.pos_line].p = NONE;
    plat[piece.pos_col][piece.pos_line].use = false;
    piece.pos_col = coup[0];
    piece.pos_line = coup[1];
    liste[joueur][piece.place]=piece;
    plat[coup[0]][coup[1]].p = piece;
    plat[coup[0]][coup[1]].use=true;

    for (int i=0;i<16;i+=1){
      pieces* p = &liste[0][i];
      if (p->en_vie){
        if (p->type=='P'){coups_pions(p, plat);}
        if (p->type=='T'){coups_tours(p, plat);}
        if (p->type=='C'){coups_cavaliers(p, plat);}
        if (p->type=='F'){coups_fous(p, plat);}
        if (p->type=='D'){coups_dame(p, plat);}
        if (p->type=='R'){coups_roi(p, plat);}
        liste[0][p->place] = *p;
        plat[p->pos_col][p->pos_line].p = *p;
      }
    }
    for (int i=0;i<16;i+=1){
      pieces* p = &liste[1][i];
      if (p->en_vie){
        if (p->type=='P'){coups_pions(p, plat);}
        if (p->type=='T'){coups_tours(p, plat);}
        if (p->type=='C'){coups_cavaliers(p, plat);}
        if (p->type=='F'){coups_fous(p, plat);}
        if (p->type=='D'){coups_dame(p, plat);}
        if (p->type=='R'){coups_roi(p, plat);}
        liste[1][p->place] = *p;
        plat[p->pos_col][p->pos_line].p = *p;
      }
    }
    return true;
  }
}

void partie_aleatoire_vs_aleatoire(){
  cases **plateau = creer_plateau();
  pieces **liste = liste_pieces(plateau);
  remplir_plateau(plateau, liste); 
  print_plateau_smoke(plateau, liste, 1);
  int coup_depuis_pion=0;
  int joueur = 0;
  while (liste[0][4].en_vie && liste[1][4].en_vie){
    deplace_aleatoire(plateau, liste,joueur,&coup_depuis_pion);
    //system("clear");
    print_plateau_smoke(plateau, liste, joueur);
    joueur=(joueur+1)%2;
    if (coup_depuis_pion==50){break;}
  }
  print_plateau(plateau);
  if (coup_depuis_pion!=50){  
    if (liste[0][4].en_vie){printf("le joueur 1 a gagné\n");}
    else {printf("le joueur 2 a gagné\n");}
  }
  else {printf("égalité\n");}
}

int heuristique_nb_deplacement(pieces** liste, int joueur){
  int* nb_deplacement=0;
  liste_deplacement(liste, joueur, nb_deplacement);
  return !nb_deplacement;
}




//////////////////////////// MINIMAX //////////////////////////////

void deplace_quant(parties* partie, int coup[2], pieces piece, int joueur, int* coup_depuis_pion){
  for (int i = 0; i < 32; i += 1) {
      NONE.shift[i][0] = -1;NONE.shift[i][1] = -1;
    }
  int promotion[4] = {'D', 'T', 'C', 'F'};
  while (true){
    pieces** liste = partie->liste;
    cases** plat = partie->plat;
    printf("%c%d\n", coup[0] + 97, coup[1] + 1);
    *coup_depuis_pion+=1;
    if (piece.type=='P'){*coup_depuis_pion=0;}
    if (plat[coup[0]][coup[1]].use) {
       if (piece.couleur == 'B') {
          liste[1][plat[coup[0]][coup[1]].p.place].en_vie=false;
        }
        if (piece.couleur == 'N') {
          liste[0][plat[coup[0]][coup[1]].p.place].en_vie=false;
        }
    }
    if (piece.type=='P' && (coup[1]==0 || coup[1]==7)){
      int indice_prom = rand() % 4;
      piece.type=promotion[indice_prom];
    }
    plat[coup[0]][coup[1]].p.en_vie = false ;
    plat[piece.pos_col][piece.pos_line].p = NONE;
    plat[piece.pos_col][piece.pos_line].use = false;
    piece.pos_col = coup[0];
    piece.pos_line = coup[1];
    liste[joueur][piece.place]=piece;
    plat[coup[0]][coup[1]].p = piece;
    plat[coup[0]][coup[1]].use=true;
     for (int i=0;i<16;i+=1){
      pieces* pi = &liste[0][i];
      if (pi->en_vie){
        if (pi->type=='P'){coups_pions(pi, plat);}
        if (pi->type=='T'){coups_tours(pi, plat);}
        if (pi->type=='C'){coups_cavaliers(pi, plat);}
        if (pi->type=='F'){coups_fous(pi, plat);}
        if (pi->type=='D'){coups_dame(pi, plat);}
        if (pi->type=='R'){coups_roi(pi, plat);}
        liste[0][pi->place] = *pi;
        plat[pi->pos_col][pi->pos_line].p = *pi;
      }
    }
    for (int i=0;i<16;i+=1){
      pieces* pi = &liste[1][i];
      if (pi->en_vie){
        if (pi->type=='P'){coups_pions(pi, plat);}
        if (pi->type=='T'){coups_tours(pi, plat);}
        if (pi->type=='C'){coups_cavaliers(pi, plat);}
        if (pi->type=='F'){coups_fous(pi, plat);}
        if (pi->type=='D'){coups_dame(pi, plat);}
        if (pi->type=='R'){coups_roi(pi, plat);}
        liste[1][pi->place] = *pi;
        plat[pi->pos_col][pi->pos_line].p = *pi;
      }
    }
    partie->coup_depuis_pions=*coup_depuis_pion;
    partie->liste=liste;
    partie->plat=plat;
  }
}

int** liste_deplacement_minimax (pieces** liste, int joueur, int* nb_deplacement, pieces* liste_pieces){
  printf("debut ldmini\n");
  int** deplacement = malloc(sizeof(int*)*64);
  *nb_deplacement=0;
  for (int i=0;i<16;i+=1){
    printf("boucle i ldmini %d\n",i);
    if (liste[joueur][i].en_vie) {
      printf("if entre boucle ldmini\n");
      for (int j=0;j<liste[joueur][i].nb_shift;j+=1){
        printf("boucle j ldmini %d\n",j);
        if (!appartient_liste(deplacement, liste[joueur][i].shift[j],*nb_deplacement)){
          liste_pieces[*nb_deplacement]=liste[joueur][i];
          deplacement[*nb_deplacement]=malloc(2*sizeof(int));
          deplacement[*nb_deplacement][0]=liste[joueur][i].shift[j][0];
          deplacement[*nb_deplacement][1]=liste[joueur][i].shift[j][1];
          *nb_deplacement+=1;
          }
        }
      }
    }
  return deplacement;
}

int* tri_liste (int* liste, int nb){
  int c;
  for (int i=0;i<nb;i+=1){
    for (int j=i+1;j<nb;j+=1){
      if (liste[i]>liste[j]){
        c=liste[i];
        liste[i]=liste[j];
        liste[j]=c;
      }
    }
  }
  return liste;
}

void tri_3_listes (int* liste_tri, int* liste_sup1, pieces* liste_sup2, int nb){
  int c_t, c_s1; pieces c_s2;
  for (int i=0;i<nb;i+=1){
    for (int j=i+1;j<nb;j+=1){
      if (liste_tri[i]>liste_tri[j]){
        c_t=liste_tri[i]; liste_tri[i]=liste_tri[j]; liste_tri[j]=c_t;
        c_s1=liste_sup1[i]; liste_sup1[i]=liste_sup1[j]; liste_sup1[j]=c_s1;
        c_s2=liste_sup2[i]; liste_sup2[i]=liste_sup2[j]; liste_sup2[j]=c_s2;
      }
    }
  }
}


int heuristique_aleatoire(pieces** liste, cases** plat,int coup_depuis_pions, int joueur){
  int gagnant;
  while (liste[0][4].en_vie && liste[1][4].en_vie){
    deplace_aleatoire(plat, liste,joueur,&coup_depuis_pions);
    joueur=1-joueur;
    if (coup_depuis_pions==50){break;}
  }
  if (coup_depuis_pions!=50){  
    if (liste[0][4].en_vie){if (joueur==0){gagnant=1;}else{gagnant=-1;}}
    else {if (joueur==0){gagnant=-1;}else{gagnant=1;}}
  }
  else {gagnant=0;}
  return gagnant;
}

int* minimax (parties partie, int depth, int joueur, int jmax){
  int score = 0;
  int cpt = 0;
  int nb_deplacement = 0;
  pieces* liste_pieces = malloc(sizeof(pieces)*64);
  int** liste_coup = liste_deplacement_minimax(partie.liste, joueur, &nb_deplacement, liste_pieces);
  if (depth==0){
    for (int i=0;i<nb_deplacement;i+=1){
      score=0;
      pieces piece = liste_pieces[i];
      int coup[2] = {liste_coup[i][0], liste_coup[i][1]};
      deplace_quant(&partie, coup, piece, joueur, &partie.coup_depuis_pions);
      for (int j=0;j<100;j+=1){
        score+=heuristique_aleatoire(partie.liste, partie.plat, partie.coup_depuis_pions, 1-joueur);
      }
      partie.liste_coups[i] = coup;
      partie.valeur_coups[i] = score;
      partie.piece_coups[i] = piece;
    }
  }
  for (int i=0;i<nb_deplacement;i+=1){
    int coup[2] = {liste_coup[i][0], liste_coup[i][1]};
    deplace_quant(&partie, coup, liste_pieces[i], joueur, 0);
    int* liste_score = minimax(partie, depth-1, 1-joueur, jmax);
    if (joueur==jmax){score = tri_liste(liste_score, nb_deplacement)[nb_deplacement-1];}
    if (joueur!=jmax){score = tri_liste(liste_score, nb_deplacement)[0];}
    partie.liste_coups[cpt] = coup;
    partie.valeur_coups[cpt] = score;
    cpt+=1;    
  }
  free(liste_pieces);
  partie.nb_coups=nb_deplacement;
  return partie.valeur_coups;
  }

int min(int a, int b){
  if (a<b){return a;}
  else {return b;}
}

parties meilleurs_coups_par_parties (parties partie, int joueur, int nb){
  printf("debut mcpp\n");
  parties p = partie;
  pieces* liste_pieces=malloc(64*sizeof(pieces));
  printf("pre appelle ldmnini \n");
  int** liste_coup = liste_deplacement_minimax(partie.liste, joueur, &partie.nb_coups, liste_pieces);
  printf("post appelle ldmini\n");
  int nb_meilleurs_coups = min(nb,partie.nb_coups);
  int* valeurs = minimax(partie, 5, joueur, joueur);
  tri_3_listes(valeurs,*liste_coup,liste_pieces,partie.nb_coups);  
  int somme=0;
  printf("post init mcpp\n");
  for (int i=0;i<nb_meilleurs_coups;i+=1){
    somme+=valeurs[i];
  }
  for (int i=partie.nb_coups-1;i>=partie.nb_coups-nb_meilleurs_coups;i-=1){
    p.liste_coups[partie.nb_coups-i] = liste_coup[i];
    p.valeur_coups[partie.nb_coups-i]=valeurs[i];
    p.proba_coups[partie.nb_coups-i]=valeurs[i]/somme;
    p.piece_coups[partie.nb_coups-i]=liste_pieces[i];
  }
  p.nb_coups=nb_meilleurs_coups;
  return p;
}

int indice_max_listes(int* liste, int nb){
  int max = liste[0];
  int indice = 0;
  for (int i=1;i<nb;i+=1){
    if (liste[i]>max){
      max = liste[i];
      indice = i;
    }
  }
  return indice;
}

void fus_et_tri(int** coups[2], int** valeurs, int** proba, int** pos_partie, pieces** piece, int nb, int* meilleurs_coups[2], int* meilleurs_valeurs, int* meilleurs_proba, int* meilleurs_pos_partie, pieces* meilleurs_pieces){
  for (int i=0;i<nb;i+=1){
    int v,p; int c[2]; pieces pp;
    for (int j=0;i<nb;i+=1){
      for (int k=i+1;j<nb;j+=1){
        if (valeurs[i][j]<valeurs[i][k]){
          v=valeurs[i][j]; valeurs[i][j]=valeurs[i][k]; valeurs[i][k]=v;
          c[0]=coups[i][j][0];c[1]=coups[i][j][1]; coups[i][j]=coups[i][k]; coups[i][k]=c;
          p=proba[i][j]; proba[i][j]=proba[i][k]; proba[i][k]=p;
          pp=piece[i][j]; piece[i][j]=piece[i][k]; piece[i][k]=pp;
        }
      }
    }
  }
  int* liste_valeurs = malloc(nb*sizeof(int));
  int i_max = 0;
  int* liste_cpt = malloc(nb*sizeof(int));
  for (int i=0;i<nb;i+=1){liste_cpt[i]=0;}
  for (int i=0;i<nb;i+=1){liste_valeurs[i]=valeurs[i][liste_cpt[i]];}
  for (int i=0;i<5;i+=1){
    i_max = indice_max_listes(liste_valeurs, nb);
    meilleurs_coups[i]=coups[i_max][liste_cpt[i_max]];
    meilleurs_valeurs[i]=valeurs[i_max][liste_cpt[i_max]];
    meilleurs_proba[i]=proba[i_max][liste_cpt[i_max]];
    meilleurs_pos_partie[i]=pos_partie[i_max][liste_cpt[i_max]];
    meilleurs_pieces[i]=piece[i_max][liste_cpt[i_max]];  
    liste_cpt[i_max]+=1;
  }
  free(liste_valeurs);
  free(liste_cpt);
}

void meilleurs_coups (parties* tab_partie, int joueur, int nb){
  quants* quant;
  int** coups[2];
  int** valeurs;
  int** proba;
  pieces** piece;
  int** pos_partie=malloc(sizeof(int*)*nb);
  printf("post init meilleurs_coups\n");
  for (int i=0;i<nb;i+=1){
    printf("pre appelle mcpp %d\n",i);
    parties p = meilleurs_coups_par_parties(tab_partie[i], joueur, nb); 
    printf("post appelle mcpp %d\n",i);
    coups[i] = p.liste_coups;
    valeurs[i] = p.valeur_coups;
    proba[i] = p.proba_coups;
    int* pos = malloc (sizeof(int)*p.nb_coups);
    for (int j=0;j<p.nb_coups;j+=1){
      pos[j]=i;
    }
    pos_partie[i]=pos;
    piece[i] = p.piece_coups;
  }
  printf("post boucle\n");
  int* meilleurs_coups[2];
  int* meilleurs_valeurs;
  int* meilleurs_proba;
  int* meilleurs_pos_partie;
  pieces* meilleurs_pieces;
  fus_et_tri(coups, valeurs, proba, pos_partie, piece, nb, meilleurs_coups, meilleurs_valeurs, meilleurs_proba,meilleurs_pos_partie, meilleurs_pieces);
  for (int i=0;i<5;i+=1){
    quant[i].coups[0]=meilleurs_coups[i][0];quant[i].coups[1]=meilleurs_coups[i][1];
    quant[i].valeur=meilleurs_valeurs[i];
    quant[i].proba=meilleurs_proba[i];
    quant[i].partie=tab_partie[meilleurs_pos_partie[i]];
    quant[i].piece=meilleurs_pieces[i];
  }
  for (int i=0;i<nb;i+=1){
    free(coups[i]);free(valeurs[i]);free(proba[i]);free(piece[i]);free(pos_partie[i]);
  }
  free(piece);free(valeurs);free(proba);free(pos_partie);
  srand(time(NULL));
  int indice = rand()%5;
  parties partie = quant[indice].partie;
  int coup[2] = {quant[indice].coups[0], quant[indice].coups[1]};
  pieces p = quant[indice].piece;
  deplace_quant(&partie, coup, p, joueur, &partie.coup_depuis_pions);
  free(quant);
}

void partie_minimax(){
  cases **plateau = creer_plateau();
  pieces **liste = liste_pieces(plateau);
  remplir_plateau(plateau, liste); 
  print_plateau_smoke(plateau,liste,1);
  int coup_depuis_pion=0;
  int joueur = 0;
  int nb=5;
  parties** tab_partie=malloc(2*sizeof(parties*));
  tab_partie[0]=malloc(sizeof(parties)*nb);
  tab_partie[1]=malloc(sizeof(partie)*nb);
  printf("13\n");
  int i=0;
  for (int i=0;i<nb;i+=1){
    printf("%d   ",i);
    for (int j=0;j<16;j+=1){
      tab_partie[0][i].liste[0][j]=liste[0][j];
      tab_partie[1][i].liste[1][j]=liste[1][j];
    }
  }
  printf("1\n");
  while (liste[0][4].en_vie && liste[1][4].en_vie){
    printf("2\n");
    meilleurs_coups(tab_partie[joueur], joueur, nb);
    printf("apres appelle meilleur_coups\n");
    scanf(" ");
    print_plateau_smoke(plateau, liste, joueur);
    joueur=(joueur+1)%2;
    if (coup_depuis_pion==50){break;}
  }
  print_plateau(plateau);
  if (coup_depuis_pion!=50){  
    if (liste[0][4].en_vie){printf("le joueur 1 a gagné\n");}
    else {printf("le joueur 2 a gagné\n");}
  }
  else {printf("égalité\n");}
}