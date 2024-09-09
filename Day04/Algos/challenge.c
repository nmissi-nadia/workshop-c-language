#include <stdio.h>
#include <string.h>
#define Max 100

// Fonction qui échange deux éléments dans un tableau
void echanger(int T[], int i, int j) {
    int tempo;
    tempo = T[i];
    T[i] = T[j];
    T[j] = tempo;
}

// Challenge 1 : Tri à Bulles
void tri_bulle(int T[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (T[j] > T[j + 1]) {
                echanger(T, j, j + 1);
            }
        }
    }
}
// Challenge 2 : Tri par Insertion
void tri_insertion(int T[], int n) {
    int i, j, c;
    for (i = 1; i < n; i++) {
        c = T[i];
        j = i - 1;
        while (j >= 0 && T[j] > c) {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = c;
    }
}
//Challenge 3 : Tri par Sélection
void tri_selection(int T[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (T[j] < T[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = T[i];
            T[i] = T[min];
            T[min] = temp;
        }
    }
}
int recherche_binaire(int T[], int taille, int valeur) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;


        if (T[milieu] == valeur)
            return milieu;
        if (T[milieu] < valeur)
            debut = milieu + 1;

        else
            fin = milieu - 1;
    }

    return -1;
}



void main() {
    int T[Max];
    int taille,c,k, i;

    do {
        printf("Entrez la taille du tableau : ");
        scanf("%d", &taille);
    } while (taille >= Max);

    // Saisie du tableau
    for(i = 0; i < taille; i++) {
        printf("Entrez la valeur du tableau[%d] : ", i + 1);
        scanf("%d", &T[i]);
    }

    // Affichage du tableau avant tri
    printf("Tableau avant tri :\n");
    for(i = 0; i < taille; i++) {
        printf("La valeur du tableau[%d] = %d\n", i + 1, T[i]);
    }

    // Tri à bulles
    tri_bulle(T, taille);

    // Affichage du tableau après tri bulles
    printf("Tableau apres tri Bulles:\n");
    for (i = 0; i < taille; i++) {
        printf("La valeur du tableau[%d] = %d\n", i + 1, T[i]);
    }
    // Tri insertion
     tri_insertion(T, taille);

    // Affichage du tableau après tri insertion
    printf("Tableau apres tri insertion:\n");
    for (i = 0; i < taille; i++) {
        printf("La valeur du tableau[%d] = %d\n", i + 1, T[i]);
    }
    printf("entrez valeur a rechercher  :");
    scanf("%d",&c);
        k=recherche_binaire(T,taille,c);    
        if(k!=-1){
            printf("la valeur est trouver on position %d",k);
            
        }
        //Challenge 3 et 4 REcherge du max et min du tableu

}
