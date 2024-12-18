#include <stdio.h>
#include <string.h>

// Structure Adresse
struct Adresse {
    char rue[100];
    char ville[50];
    char code_postal[10];
};

// Structure Personne
struct Personne {
    char nom[50];
    int age;
    struct Adresse adresse;
};

// Déclaration globale
struct Personne liste_personnes[100]; // Tableau pour stocker les personnes
int nombre_personnes = 0;             // Compteur du nombre de personnes

// Fonction pour ajouter une personne
void ajouter_personne() {
    if (nombre_personnes < 100) {
        printf("Entrez le nom de la personne: ");
        scanf(" %[^\n]", liste_personnes[nombre_personnes].nom);

        printf("Entrez l'age de la personne: ");
        scanf("%d", &liste_personnes[nombre_personnes].age);

        printf("Entrez la rue: ");
        scanf(" %[^\n]", liste_personnes[nombre_personnes].adresse.rue);

        printf("Entrez la ville: ");
        scanf(" %[^\n]", liste_personnes[nombre_personnes].adresse.ville);

        printf("Entrez le code postal: ");
        scanf(" %[^\n]", liste_personnes[nombre_personnes].adresse.code_postal);

        nombre_personnes++; // Incrémenter le compteur
        printf("Personne ajouter avec succes !\n");
    } else {
        printf("Le tableau est plein.\n");
    }
}




void afficher_personne(){
    if(nombre_personnes == 0){
        printf("Aucune personnes a affiche .\n");
        return;
    }
    for (int i = 0; i < nombre_personnes; i++)
    {
        printf("\nPersonne %d:\n", i + 1);
        printf("Nom: %s\n", liste_personnes[i].nom);
        printf("Age: %d\n", liste_personnes[i].age);
        printf("Adresse: %s, %s, %s\n", liste_personnes[i].adresse.rue,
                                         liste_personnes[i].adresse.ville,
                                         liste_personnes[i].adresse.code_postal);


    }    }




 void modifier_personne(){
    int max ;
    printf("Enterz le numero de la personne a modifier (1-%d) : ",nombre_personnes);
    scanf("%d",&max);

    if (max >= 1 && max <= nombre_personnes)
    {
        max--;
        printf("Entrez le nouveau nom : ");
        scanf(" %[^\n]",liste_personnes[max].nom);
        printf("Entrez le nouveau age : ");
        scanf("%d",&liste_personnes[max].age);
        printf("Entrez le nouveau rue : ");
        scanf(" %[^\n]",liste_personnes[max].adresse.rue);
        printf("Entrez le nouveau ville : ");
        scanf(" %[^\n]",liste_personnes[max].adresse.ville);
        printf("Entrez le nouveau Code Postal : ");
        scanf(" %[^\n]",liste_personnes[max].adresse.code_postal);

   printf("Personne modifee avec succes \n");

    } else {
        printf("Numero invalide .\n");
    }

 }

 void supprimer_personne (){
    int max;
    printf("entrez la numero de personne a supprimer (1-%d) : " ,nombre_personnes);
    scanf("%d" ,&max);
    

     if (max >= 1 && max <= nombre_personnes){
        max--;

     for (int i = max ; i < nombre_personnes - 1; i++){
          liste_personnes[i] = liste_personnes[i + 1];
     }
      nombre_personnes--;
     printf("Personne supprimee avec succes");
    
    }else{
        printf("Numero invalide . \n");
    }

 }
 
// Fonction principale
int main() {
    int choix;
    do{
        printf("\nMenu:\n");
        printf("1. ajouter une personne\n");
        printf("2. afficher une personne\n");
        printf("3. modifier une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_personne();
                break;
            case 2:
                afficher_personne();
                break;
            case 3:
                modifier_personne();
                break;
            case 4:
                supprimer_personne();
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}
    