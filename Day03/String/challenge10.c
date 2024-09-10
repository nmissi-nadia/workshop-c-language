#include <stdio.h>
#include <string.h>
// Challenge 10 : Recherche d'une Sous-chaîne
int recherche_sous_chaine(char chaine[], char sous_chaine[]) {
    int longueur_chaine = strlen(chaine);
    int longueur_sous_chaine = strlen(sous_chaine);
    int i,j;
    for ( i = 0; i <= longueur_chaine - longueur_sous_chaine; i++) {
        
        for (j = 0; j < longueur_sous_chaine; j++) {
            if (chaine[i + j] != sous_chaine[j])
                break;
        }
        if (j == longueur_sous_chaine)
            return i;
    }
    return -1;
}
void main(){
    
    // Test pour Challenge 10
    char chaine[] = "Bonjour tout le monde";
    char sous_chaine[] = "monde";
    int resultat_sous_chaine = recherche_sous_chaine(chaine, sous_chaine);

    if (resultat_sous_chaine != -1)
        printf("Sous-chaine trouvee a l'indice %d\n", resultat_sous_chaine);
    else
        printf("Sous-chaine non trouvee\n");
}