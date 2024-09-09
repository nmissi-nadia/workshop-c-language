#include<stdio.h>
#include<string.h>
#include<time.h>
#define Max 1000

// Définition de la structure Contact
typedef struct {
    char nom[20];
    char num[20];
    char adresse[20];
} Contact;

// Définition de la tableau des contact

    Contact tab[100];
    int taille;


// Fonction pour ajouter un nouveau  contact 
void Ajouter() {
    printf("Entrez le nom du contact  : ");
    scanf("%s", tab[taille].nom);

    getchar();  // Vider le buffer

    printf("Entrez le numéro du contact  : ");
    fgets(tab[taille].num, sizeof(tab[taille].num), stdin);
    tab[taille].num[strcspn(tab[taille].num, "\n")] = '\0';  
    printf("Entrez l'adresse du contact : ");
    scanf("%s", tab[taille].adresse);
    
    taille++;
}

// Fonction pour ajouter plusieurs contacts 
void Ajout_multiple(int n) {
    while (n != 0) {
        Ajouter();
        n--;
    }
}

// Tri des contact par ordre alphabétique croissant du nom
void Trie_nom_Asc() {
    int i, j;
    Contact  temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = i + 1; j < taille; j++) {
            if (strcmp(tab[i].nom, tab[j].nom) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

// Tri des contact par ordre alphabétique descroissant du nom
void Trie_nom_Desc() {
    int i, j;
    Contact  temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = i + 1; j < taille; j++) {
            if (strcmp(tab[i].nom, tab[j].nom) < 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

// Afficher tous les contacts 
void Afficher_contacts() {
    int i;
    printf("****************** Liste des Contact  ******************\n");
    printf("Nom             Numéro              Adresse   \n");
    for (i = 0; i < taille; i++) {
        printf("%s    %s    %s\n", 
               tab[i].nom, tab[i].num, tab[i].adresse);
    }
}

// Rechercher un produit par nom
int Rechercher_nom(char nom[]) {
    int i;
    for (i = 0; i < taille; i++) {
        if (strcmp(tab[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Rechercher un produit par code
int Rechercher_num(char num[]) {
    int i;
    for (i = 0; i < taille; i++) {
        if (strcmp(tab[i].num, num) == 0) {
            return i;
        }
    }
    return -1;
}


// Supprimer un Contact par numéro
void supprimer_par_num(char num[]) {
    int i, index;
    index = Rechercher_num(num);
    if (index != -1) {
        for (i = index; i < taille - 1; i++) {
            tab[i] = tab[i + 1];
        }
        taille--;
        printf("Contact supprimé avec succès.\n");
    } else {
        printf("Contact non trouvé.\n");
    }
}
// Supprimer un Contact par numéro
void supprimer_par_nom(char nom[]) {
    int i, index;
    index = Rechercher_nom(nom);
    if (index != -1) {
        for (i = index; i < taille - 1; i++) {
            tab[i] = tab[i + 1];
        }
        taille--;
        printf("Contact supprimé avec succès.\n");
    } else {
        printf("Contact non trouvé.\n");
    }

}
//Modification des infos des contacts
void Modification(char nom[])
{
    int i;
    char adr[20],numero[20];
    printf("Entrez le nouveau numero :");
    scanf("%s",numero);
    printf("Entrez le nouveau numero :");
    scanf("%s",adr);
    for ( i = 0; i < taille; i++)
    {
        if(strcmp(tab[i].nom,nom)==0)
        {
            strcpy(tab[i].num,numero);
            strcpy(tab[i].adresse,adr);
        }
    }
    
}


// Fonction principale
int main() {
    int choix = -1, nombre,ch1,ch2,ch3,ch4,test,cf;
    char num[20], nom[30],nom_supprimer[30],nom_modifier[30];
    
    while (choix != 0) {
        printf("***Bienvenue dans votre éspaces de gestion des Contacts**\n");
        printf("***************************Menu:*********************\n");
        printf("1. Ajouter un nouveau Contact\n");
        printf("2. Afficher les Contacts\n");
        printf("3. Rechercher les Contacts\n");
        printf("4. Manipuler(Modification/Suppression) un Contact par code\n");
        printf("5. Nombre des Contacts\n");
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
                    printf("2. Affichage tri Asc .\n");
                    printf("3. Affichage tri Desc .\n");
                    printf("Votre choix : ");
                    scanf("%d", &ch2);
                    switch (ch2)
                    {
                    case 1:
                        Afficher_contacts();
                        break;
                    case 2:
                        Trie_nom_Asc();
                        Afficher_contacts();
                        break;
                    case 3:
                        Trie_nom_Desc();
                        Afficher_contacts();
                        break;
                    default:
                        Afficher_contacts();
                        break;
                    }
                break;
            case 3:
                printf("*******Menu de Recherche*******\n");
                    printf("1. Recherche Par Nom .\n");
                    printf("2. Recherche Par Numéro .\n");
                    printf("Votre choix : ");
                    scanf("%d", &ch3);
                
                switch (ch3)
                {
                case 1:
                    printf("Entrez Le nom recherché :\n");
                    scanf("%s",nom);
                    test=Rechercher_nom(nom);
                    if (test!=-1)
                    {
                        printf("Le contact a trouver dans position :%d.\n",test);
                    }else{
                        printf("Le contact n'est pas trouvé.\n");
                    }
                    
                    break;
                case 2:
                    printf("Entrez Le numéro recherché :\n");
                    scanf("%s",num);
                    test=Rechercher_num(nom);
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
                            printf("Entrer le nom du contact pour modifier :");
                            scanf("%s",nom_modifier);
                            Modification(nom_modifier);
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
