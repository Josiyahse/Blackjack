#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void initialiser(int joueur[]) {
    
   

    //initialiser le jeux des joueurs
    for (int i = 0; i < 2; i++)
    {
        joueur[i] = rand() % 11 +1;
        
        
    }
}

void carte(int joueur[], int position) {


    joueur[position] = rand() % 11 + 1;
}

int somme(int joueur[], int taille) {
    int somme = 0;
    for (int i = 0; i < taille; i++)
    {
        somme = somme + joueur[i];
    }
    return somme;
}


void afficher(int tableau[], int taille) {
    // Affichage de ses valeurs pour vérifier
    for (int i = 0; i < taille; i++)
    {
        printf("%d", tableau[i]);
        printf(" ");
    }
    printf("\n");
}

void progression(int tab1[], int t1, int tab2[], int t2) {
    //Croupier
    int s1 = somme(tab1, t1);
    printf("Les Cartes du croupier ");
    afficher(tab1, t1);
    printf("Pour une somme total de  ");
    printf("sc=%d",s1);
    printf("\n");
  
   
    //Joueur
    int s2 = somme(tab2, t2);
    printf("Les Cartes du joueur ");
    afficher(tab2, t2);
    printf("Pour une somme total de  ");
    printf("sj=%d", s2);
    printf("\n");

   
}

int main(void)
{
    srand(time(NULL));

    int scoreC = 0;
    int scoreJ = 0;

    char relance = 'o';

    while (relance=='o') {

        int tailleCroupier = 2;
        int tailleJoueur = 2;
        // On definis des tableux qui coreponde a chacun des joueur

        int croupier[8];
        int joueur[8];


        
        initialiser(croupier);
        initialiser(joueur);
     

        printf("\n");
        progression(croupier, tailleCroupier, joueur, tailleJoueur);


        int sj = somme(joueur, tailleJoueur);
        int sc = somme(croupier, tailleCroupier);

        while (sj <= 21 && sc <= 21)
        {
            printf("\n");
            char choixJoueur;

            //Pour le joueur
            printf("Joueur vous piocher une carte ou vous passer ?(c/p)");
            choixJoueur = getchar();
            getchar();
            printf("\n");
            if (choixJoueur == 'c') {
                carte(joueur, tailleJoueur);
                tailleJoueur++;
                //Pour le croupier
                if (sc < 16)
                {
                    carte(croupier, tailleCroupier);
                    tailleCroupier++;
                }
                progression(croupier, tailleCroupier, joueur, tailleJoueur);
            }
            else if (choixJoueur == 'p')
            {
                //Pour le croupier
                if (sc < 16)
                {
                    carte(croupier, tailleCroupier);
                    tailleCroupier++;
                }
                progression(croupier, tailleCroupier, joueur, tailleJoueur);
                break;
            }

            sj = somme(joueur, tailleJoueur);
            sc = somme(croupier, tailleCroupier);

            printf("sc=%d", sc);
            printf("\n");
            printf("sj=%d", sj);
            printf("\n");

        }

        if ((sc < 21 && sc>sj) || (sj > 21))
        {
            printf("Victoire de la Banque");
            scoreC++;
            printf("\n");
        }
        else if ((sj<21 && sj>sc) || (sc > 21))
        {
            printf("Victoire du Joueur");
            scoreJ++;
            printf("\n");
        }
        else if (sc == sj)
        {
            printf("Egalite");
            printf("\n");
        }

        printf("\n");
        printf("Score Banque : ");
        printf("%d",scoreC);
        printf("\n");
        printf("Score Joueur : ");
        printf("%d", scoreJ);
        printf("\n");

        printf("\n");
        printf("Voulez vous relancer le jeu ?(o/n)");
        relance = getchar();
        getchar();
    }
   

    return 0;
}