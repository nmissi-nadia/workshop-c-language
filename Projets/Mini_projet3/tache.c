#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TACHES 100

// Structure pour représenter une date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour représenter une tâche
typedef struct {
    int id;
    char titre[100];
    char description[255];
    Date deadline;
    char statut[50]; // Exemple : "à réaliser", "en cours de réalisation", "finalisée"
} Tache;

// Tableau de tâches
Tache tab[MAX_TACHES];
int taille = 0; // Nombre de tâches

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

// Fonction pour calculer la différence en jours entre deux dates
int differenceJours(Date d) {
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    struct tm deadline = {0};
    deadline.tm_mday = d.jour;
    deadline.tm_mon = d.mois - 1; // Les mois commencent à 0 dans struct tm
    deadline.tm_year = d.annee - 1900;

    time_t deadline_time = mktime(&deadline);
    time_t now = mktime(&today);

    double difference = difftime(deadline_time, now) / (60 * 60 * 24); // Différence en jours
    return (int)difference;
}

// Fonction pour créer une nouvelle tâche
void creerTache() {
    if (taille < MAX_TACHES) {
        Tache t;
        t.id = taille + 1;
        printf("Entrez le titre de la tâche : ");
        getchar(); // Pour éviter les erreurs liées à la saisie
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
        getchar(); // Effacer le buffer
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

    // Calcul et affichage des jours restants jusqu'à la deadline
    int jours_restants = differenceJours(t.deadline);
    if (jours_restants > 0) {
        printf("Jours restants jusqu'au délai : %d jours\n", jours_restants);
    } else {
        printf("Délai dépassé de %d jours.\n", -jours_restants);
    }

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

// Fonction pour afficher des statistiques
void afficherStatistiques() {
    int completes = 0, incompletes = 0;

    for (int i = 0; i < taille; i++) {
        if (strcmp(tab[i].statut, "finalisée") == 0) {
            completes++;
        } else {
            incompletes++;
        }
    }

    printf("\n****** Statistiques ******\n");
    printf("Nombre total de tâches : %d\n", taille);
    printf("Nombre de tâches complètes : %d\n", completes);
    printf("Nombre de tâches incomplètes : %d\n", incompletes);
    printf("**************************\n");
}

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n********* Menu Principal *********\n");
    printf("1. Créer une tâche\n");
    printf("2. Afficher toutes les tâches\n");
    printf("3. Afficher les statistiques\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
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
                afficherStatistiques();
                break;
            case 4:
                printf("Fin de saisie ! Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
