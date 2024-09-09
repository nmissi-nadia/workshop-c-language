#include <stdio.h>
#include <string.h>
#include <time.h>
#define Max 1000

// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Deadline;

// Structure pour la tâche
typedef struct {
    int id;
    char titre[20];
    char description[100];
    char statut[20];
    Deadline deadline;
} Tache;

// Déclaration d'un tableau de tâches
Tache tab[Max];
int taille = 0;

// Fonction pour vérifier si une année est bissextile
int estBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

// Fonction pour vérifier si une date est valide
int dateValidee(int jour, int mois, int annee) {
    if (annee < 1 || mois < 1 || mois > 12 || jour < 1) {
        return 0;
    }

    int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Vérifier les années bissextiles
    if (estBissextile(annee) && mois == 2) {
        joursParMois[1] = 29;
    }

    if (jour > joursParMois[mois - 1]) {
        return 0;
    }

    return 1;
}

// Fonction pour ajouter des jours à une date
Deadline ajouterJours(Deadline deadline, int jours) {
    int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (estBissextile(deadline.annee)) {
        joursParMois[1] = 29;
    }

    deadline.jour += jours;

    while (deadline.jour > joursParMois[deadline.mois - 1]) {
        deadline.jour -= joursParMois[deadline.mois - 1];
        deadline.mois++;

        if (deadline.mois > 12) {
            deadline.mois = 1;
            deadline.annee++;
            if (estBissextile(deadline.annee)) {
                joursParMois[1] = 29;
            } else {
                joursParMois[1] = 28;
            }
        }
    }

    return deadline;
}

// Fonction pour ajouter une deadline à une tâche
void ajouterDeadline(int index, int jour, int mois, int annee) {
    tab[index].deadline.jour = jour;
    tab[index].deadline.mois = mois;
    tab[index].deadline.annee = annee;
}

// Fonction pour ajouter une tâche
void ajouterTache() {
    tab[taille].id = taille + 1;
    printf("Entrez le titre de la tâche : ");
    fgets(tab[taille].titre, sizeof(tab[taille].titre), stdin);
    printf("Entrez la description de la tâche : ");
    fgets(tab[taille].description, sizeof(tab[taille].description), stdin);
    strcpy(tab[taille].statut, "à réaliser");

    int jour, mois, annee;
    printf("Entrez la deadline (jj mm aaaa) : ");
    scanf("%d %d %d", &jour, &mois, &annee);
    if (dateValidee(jour, mois, annee)) {
        ajouterDeadline(taille, jour, mois, annee);
    } else {
        printf("Date invalide. Veuillez réessayer.\n");
    }

    taille++;
}
// Fonction pour ajouter plusieurs produits
void Ajout_multiple(int n) {
    while (n != 0) {
        Ajouter();
        n--;
    }
}
// Trier les tâches par ordre alphabétique.
void Trie_nom() {
    int i, j;
    Tache temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = i + 1; j < taille; j++) {
            if (strcmp(tab[i].titre, tab[j].titre) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
//Trier les tâches par deadline.
int comparerDates(Deadline d1, Deadline d2) {
    if (d1.annee != d2.annee) {
        return d1.annee - d2.annee;
    } else if (d1.mois != d2.mois) {
        return d1.mois - d2.mois;
    } else {
        return d1.jour - d2.jour;
    }
}
void trierTachesParDeadline() {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - 1 - i; j++) {
            if (comparerDates(tab[j].deadline, tab[j + 1].deadline) > 0) {
                Tache temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

// Afficher les tâches dont le deadline est dans 3 jours ou moins.
// Fonction pour afficher les tâches dont le deadline est dans 3 jours ou moins
void Afficher_deadLine3jours() {
    int i;
    printf("****************** Liste des taches à faire ******************\n");
    printf("Id    Titre    Description               Deadline\n");

    time_t tm = time(NULL);
    struct tm date = *localtime(&tm);

    // Date actuelle
    Deadline dateActuelle = {date.tm_mday, date.tm_mon + 1, date.tm_year + 1900};

    // Date limite (3 jours plus tard)
    Deadline dateLimite = ajouterJours(dateActuelle, 3);

    for (i = 0; i < taille; i++) {
        Deadline deadlineTache = tab[i].deadline;

        // Comparer les dates
        if ((deadlineTache.annee < dateLimite.annee) ||
            (deadlineTache.annee == dateLimite.annee && deadlineTache.mois < dateLimite.mois) ||
            (deadlineTache.annee == dateLimite.annee && deadlineTache.mois == dateLimite.mois && deadlineTache.jour <= dateLimite.jour)) {
            printf("%d    %s    %s    %02d/%02d/%04d\n", 
                   tab[i].id, tab[i].titre, tab[i].description, 
                   tab[i].deadline.jour, tab[i].deadline.mois, tab[i].deadline.annee);
        }
    }
}
// Afficher tous les taches
void Afficher_tache() {
    int i;
    printf("****************** Liste des tache To do ******************\n");
    printf("Id    Titre    Descreption               DeadLine             \n");
    for (i = 0; i < taille; i++) {
        printf("%d    %s    %s    %d    %d    %d", 
               tab[i].id,tab[i].titre, tab[i].description, tab[i].deadline.jour, tab[i].deadline.mois, 
               tab[i].deadline.annee);
    }
}
//fonction de Recherche
//fonction des modification
//Modifier la description d'une tâche.
void Modification_desc(int i){

}
//Modifier la description d'une tâche.
void Modification_statut(int i){

}
//Modifier la description d'une tâche.
void modifierDeadline(int index, int jour, int mois, int annee) {
    if (index < 0 || index >= taille) {
        printf("Index de tâche invalide.\n");
        return;
    }

    if (dateValidee(jour, mois, annee)) {
        tab[index].deadline.jour = jour;
        tab[index].deadline.mois = mois;
        tab[index].deadline.annee = annee;
        printf("Deadline modifiée avec succès.\n");
    } else {
        printf("Date invalide. Veuillez réessayer.\n");
    }
}

// void main() {
//     ajouterTache();
//     printf("Tâche ajoutée : %s\n", tab[taille - 1].titre);
//     printf("Deadline : %02d/%02d/%04d\n", tab[taille - 1].deadline.jour, tab[taille - 1].deadline.mois, tab[taille - 1].deadline.annee);
    
// }
int main() {
    int choix = -1, nombre,ch1,ch2,ch3,ch4,test,cf,md,id,id_r;
    char num[20], nom[30],nom_supprimer[30],nom_modifier[30];
    
    while (choix != 0) {
        printf("***Bienvenue dans votre éspaces de gestion des Taches**\n");
        printf("***************************Menu:*********************\n");
        printf("1. Ajouter un nouveau Tache\n");
        printf("2. Afficher les Taches\n");
        printf("3. Rechercher les Contacts\n");
        printf("4. Manipuler(Modification/Suppression) un Contact par code\n");
        printf("5. StatistiqueS\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                printf("*******Menu d'ajout*******\n");
                printf("1. Ajout Simple .\n");
                printf("2. Ajout Multiple .\n");
                printf("Votre choix : ");
                scanf("%d", &ch1);
                switch(ch1){
                case 1:
                    Ajouter();
                break;
                case 2:
                    printf("Entrez le nombre de produits à ajouter : ");
                    scanf("%d", &nombre);
                    Ajout_multiple(nombre);
                    break;
                }
            break;
            case 2:
                    printf("*******Menu d'Affichage*******\n");
                    printf("1. Affichage Simple .\n");
                    printf("2. Affichage Trie des tâches par ordre alphabétique .\n");
                    printf("3. Affichage Trie des tâches par deadline.\n");
                    printf("4. Affichage des tâches dont le deadline est dans 3 jours ou moins.\n");
                    printf("Votre choix : ");
                    scanf("%d",&ch2);
                    switch (ch2)
                    {
                    case 1:
                        Afficher_tache();
                        break;
                    case 2:
                        Trie_nom();
                        Afficher_tache();
                        break;
                    case 3:
                        trierTachesParDeadline();
                        Afficher_tache();
                        break;
                    default:
                        Afficher_deadLine3jours();
                        break;
                    }
            break;
            case 3:
                printf("*******Menu de Recherche*******\n");
                    printf("1. Rechercher une tâche par son Identifiant. .\n");
                    printf("2. Rechercher une tâche par son Titre .\n");
                    printf("Votre choix : ");
                    scanf("%d", &ch3);
                
                switch (ch3)
                {
                case 1:
                    printf("Entrez Le id recherché :\n");
                    scanf("%d",id_r);
                    test=Rechercher_id(id_r);
                    if (test!=-1)
                    {
                        printf("La tache a trouver dans position :%d.\n",test);
                    }else{
                        printf("La tache n'est pas trouvé.\n");
                    }
                    
                    break;
                case 2:
                    printf("Entrez Le titre recherché :\n");
                    scanf("%s",num);
                    test=Rechercher_titre(num);
                    if (test!=-1)
                    {
                        printf("Le contact a trouver dans position :%d.\n",test);
                    }else{
                        printf("Le contact n'est pas trouvé.\n");
                    }
                    break;
                }
                break;
            case 4:
                printf("*******Menu de Manipulation*******\n");
                    printf("1. Modification des Contacts .\n");
                    printf("2. Supprimer un contacts  .\n");
                    printf("Votre choix : ");
                    scanf("%d", &ch4);
                    switch(ch4){
                    case 1:
                        printf("**Voulez vous vraiment Modifier ?**\n");
                        printf("1. Oui .\n");
                        printf("2. Non .\n");
                        printf("Votre choix : ");
                        scanf("%d", &cf);
                        switch (cf)
                        {
                        case 1:
                            printf("********Modifier une tâche:********\n");
                            printf("1. Modifier la description d'une tâche .\n");
                            printf("2. Modifier le statut d’une tâche. .\n");
                            printf("3. Modifier le deadline d’une tâche. .\n");
                            printf("Votre choix : ");
                            scanf("%d", &md);
                            switch (md)
                            {
                            case 1:
                                printf("Entrer le nom du contact pour modifier :");
                            scanf("%s",nom_modifier);
                            Modification_descreption(nom_modifier);
                                break;
                            
                            case 2:
                                break;
                            case 3:
                            break;
                            }
                            
                            break;
                        case 2:
                            break;
                        }
                        break;
                    case 2:
                         printf("**Voulez vous vraiment Supprimer ?**\n");
                        printf("1. Oui .\n");
                        printf("2. Non .\n");
                        printf("Votre choix : ");
                        scanf("%d", &cf);
                        switch (cf)
                        {
                            case 1:
                            printf("Entrer le nom du contact pour supprimer :");
                            scanf("%s",nom_supprimer);
                            supprimer_par_nom(nom_supprimer);
                            break;
                            case 2:
                                break;
                        }
                    }
                
                break;
            case 5:
                printf("Le nombre total des Contacts est :%d .\n",taille);
            
            case 0:
                printf("fin de saisie Au revoir!\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    }
    
    return 0;
}


