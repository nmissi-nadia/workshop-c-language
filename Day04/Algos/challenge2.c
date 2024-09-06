#include <stdio.h>
#include <string.h>

// Challenge 5 : Recherche d'une Sous-chaîne
int recherche_sous_chaine(char chaine[], char sous_chaine[]) {
    int longueur_chaine = strlen(chaine);
    int longueur_sous_chaine = strlen(sous_chaine);

    for (int i = 0; i <= longueur_chaine - longueur_sous_chaine; i++) {
        int j;
        for (j = 0; j < longueur_sous_chaine; j++) {
            if (chaine[i + j] != sous_chaine[j])
                break;
        }
        if (j == longueur_sous_chaine)
            return i;
    }
    return -1;
}

// Challenge 6 : Recherche de Duplication
int recherche_doublons(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (tableau[i] == tableau[j])
                return 1; // Doublon trouvé
        }
    }
    return 0; // Pas de doublon
}

// Challenge 7 : Recherche Binaire sur une Liste Chaînée simulée avec un tableau
int recherche_binaire(int tableau[], int taille, int valeur) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;

        if (tableau[milieu] == valeur)
            return milieu;

        if (tableau[milieu] < valeur)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1;
}

int main() {
    // Test pour Challenge 5
    char chaine[] = "Bonjour tout le monde";
    char sous_chaine[] = "tout";
    int resultat_sous_chaine = recherche_sous_chaine(chaine, sous_chaine);

    if (resultat_sous_chaine != -1)
        printf("Sous-chaine trouvee a l'indice %d\n", resultat_sous_chaine);
    else
        printf("Sous-chaine non trouvee\n");

    // Test pour Challenge 6
    int tableau[] = {1, 2, 3, 4, 5, 6, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int resultat_doublons = recherche_doublons(tableau, taille);

    if (resultat_doublons)
        printf("Doublons trouves\n");
    else
        printf("Pas de doublons\n");

    // Test pour Challenge 7
    int tableau_binaire[] = {1, 2, 3, 4, 5};
    int taille_binaire = 5;
    int valeur = 3;
    int resultat_binaire = recherche_binaire(tableau_binaire, taille_binaire, valeur);

    if (resultat_binaire != -1)
        printf("Element trouve a l'indice %d\n", resultat_binaire);
    else
        printf("Element non trouve\n");

    return 0;
}
