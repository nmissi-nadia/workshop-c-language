#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

// Structure pour représenter une date
typedef struct  {
    int jour;
    int mois;
    int annee;
}Date;

// Structure pour représenter une tâche
typedef struct  {
    int id;
    char titre[100];
    char description[255];
    Date deadline;
    char statut[50];  // Exemple : "à réaliser", "en cours de réalisation", "finalisée"
}Tache;

// Tableau de tâches
Tache tab[MAX_TACHES];
int taille = 0;  // Nombre de tâches

// Fonction pour valider une date
int dateValidee(int jour, int mois, int annee) {
    if (annee >= 0 && (mois >= 1 && mois <= 12) && (jour >= 1 && jour <= 31)) {
        if (mois == 2) {
            int estBissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
            return jour <= (estBissextile ? 29 : 28);
        } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
            return jour <= 30;
        } else {
            return jour <= 31;
        }
    }
    return 0; // Date invalide
}

// Fonction pour créer une nouvelle tâche
void creerTache() {
    if (taille < MAX_TACHES) {
        Tache t;
        t.id = taille + 1;
        printf("Entrez le titre de la tâche : ");
        getchar();  // Pour éviter les erreurs liées à la saisie
        fgets(t.titre, sizeof(t.titre), stdin);
        t.titre[strcspn(t.titre, "\n")] = 0;  

        printf("Entrez la description de la tâche : ");
        fgets(t.description, sizeof(t.description), stdin);
        t.description[strcspn(t.description, "\n")] = 0;

        printf("Entrez la deadline (jj mm aaaa) : ");
        scanf("%d %d %d", &t.deadline.jour, &t.deadline.mois, &t.deadline.annee);

        if (!dateValidee(t.deadline.jour, t.deadline.mois, t.deadline.annee)) {
            printf("Date invalide ! La tâche ne peut pas être créée.\n");
            return;
        }

        printf("Entrez le statut de la tâche : ");
        getchar();  // Effacer le buffer
        fgets(t.statut, sizeof(t.statut), stdin);
        t.statut[strcspn(t.statut, "\n")] = 0;

        tab[taille] = t;
        taille++;
        printf("Tâche créée avec succès.\n");
    } else {
        printf("Nombre maximal de tâches atteint !\n");
    }
}

// Fonction pour afficher une tâche
void afficherTache(Tache t) {
    printf("ID: %d\n", t.id);
    printf("Titre: %s\n", t.titre);
    printf("Description: %s\n", t.description);
    printf("Deadline: %02d/%02d/%04d\n", t.deadline.jour, t.deadline.mois, t.deadline.annee);
    printf("Statut: %s\n", t.statut);
    printf("---------------------------\n");
}

// Fonction pour afficher toutes les tâches
void afficherToutesTaches() {
    if (taille == 0) {
        printf("Aucune tâche à afficher.\n");
    } else {
        for (int i = 0; i < taille; i++) {
            afficherTache(tab[i]);
        }
    }
}

// Fonction pour rechercher une tâche par son ID
int Rechercher_id(int id) {
    for (int i = 0; i < taille; i++) {
        if (tab[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

// Fonction pour rechercher une tâche par son titre
int Rechercher_titre(char titre[]) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(tab[i].titre, titre) == 0) {
            return i; 
        }
    }
    return -1; 
}

// Fonction pour modifier la description d'une tâche
void Modification_description(int id) {
    int index = Rechercher_id(id);
    if (index != -1) {
        printf("Entrez la nouvelle description : ");
        getchar(); // Pour effacer le retour à la ligne restant dans le buffer
        fgets(tab[index].description, sizeof(tab[index].description), stdin);
        printf("Description modifiée avec succès.\n");
    } else {
        printf("Tâche non trouvée.\n");
    }
}

// Fonction pour modifier le statut d'une tâche
void Modification_statut(int id) {
    int index = Rechercher_id(id);
    if (index != -1) {
        printf("Entrez le nouveau statut (à réaliser, en cours de réalisation, finalisée) : ");
        getchar(); 
        fgets(tab[index].statut, sizeof(tab[index].statut), stdin);
        printf("Statut modifié avec succès.\n");
    } else {
        printf("Tâche non trouvée.\n");
    }
}

// Fonction pour modifier la deadline d'une tâche
void Modification_deadline(int id) {
    int index = Rechercher_id(id);
    if (index != -1) {
        int jour, mois, annee;
        printf("Entrez la nouvelle deadline (jj mm aaaa) : ");
        scanf("%d %d %d", &jour, &mois, &annee);
        if (dateValidee(jour, mois, annee)) {
            tab[index].deadline.jour = jour;
            tab[index].deadline.mois = mois;
            tab[index].deadline.annee = annee;
            printf("Deadline modifiée avec succès.\n");
        } else {
            printf("Date invalide.\n");
        }
    } else {
        printf("Tâche non trouvée.\n");
    }
}

// Fonction pour supprimer une tâche par ID
void supprimer_par_id(int id) {
    int index = Rechercher_id(id);
    if (index != -1) {
       
        for (int i = index; i < taille - 1; i++) {
            tab[i] = tab[i + 1];
        }
        taille--; 
        printf("Tâche supprimée avec succès.\n");
    } else {
        printf("Tâche non trouvée.\n");
    }
}

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n********* Menu Principal *********\n");
    printf("1. Créer une tâche\n");
    printf("2. Afficher toutes les tâches\n");
    printf("3. Rechercher une tâche\n");
    printf("4. Modifier ou supprimer une tâche\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix, id, jour, mois, annee, ch4, md;
    char titre[100];
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                creerTache();
                break;
            
            case 2:
                afficherToutesTaches();
                break;
            
            case 3:
                printf("*******Menu de Recherche*******\n");
                printf("1. Rechercher par ID\n");
                printf("2. Rechercher par Titre\n");
                printf("Votre choix : ");
                scanf("%d", &ch4);
                
                if (ch4 == 1) {
                    printf("Entrez l'ID de la tâche à rechercher : ");
                    scanf("%d", &id);
                    int index = Rechercher_id(id);
                    if (index != -1) {
                        afficherTache(tab[index]);
                    } else {
                        printf("Tâche non trouvée.\n");
                    }
                } else if (ch4 == 2) {
                    printf("Entrez le titre de la tâche à rechercher : ");
                    getchar();
                    fgets(titre, sizeof(titre), stdin);
                    titre[strcspn(titre, "\n")] = 0;
                    int index = Rechercher_titre(titre);
                    if (index != -1) {
                        afficherTache(tab[index]);
                    } else {
                        printf("Tâche non trouvée.\n");
                    }
                } else {
                    printf("Choix invalide.\n");
                }
                break;
            
            case 4:
                printf("*******Menu de Manipulation*******\n");
                printf("1. Modification d'une tâche\n");
                printf("2. Suppression d'une tâche par ID\n");
                printf("Votre choix : ");
                scanf("%d", &ch4);
                
                switch (ch4) {
                    case 1:
                        printf("Entrez l'ID de la tâche à modifier : ");
                        scanf("%d", &id);
                        printf("1. Modifier la description\n");
                        printf("2. Modifier le statut\n");
                        printf("3. Modifier la deadline\n");
                        printf("Votre choix : ");
                        scanf("%d", &md);
                        
                        switch (md) {
                            case 1:
                                Modification_description(id);
                                break;
                            case 2:
                                Modification_statut(id);
                                break;
                            case 3:
                                Modification_deadline(id);
                                break;
                            default:
                                printf("Choix invalide.\n");
                        }
                        break;
                        
                    case 2:
                        printf("Entrez l'ID de la tâche à supprimer : ");
                        scanf("%d", &id);
                        supprimer_par_id(id);
                        break;
                        
                    default:
                        printf("Choix invalide.\n");
                }
                break;
            
            case 5:
                printf("fin de Saisie !!! Au revoir !\n");
                break;
            
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);
    
    return 0;
}
