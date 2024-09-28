//mini projet//
#include <stdio.h>
#include <string.h>



int main() {
    char titres[100][100];
    char auteurs[100][100];
    float prix[100];
    int quantites[100];
    int totalLivres = 0;
    int choix;

    
    do {
        printf("\n--- Système de Gestion de Stock de Librairie ---\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre du stock\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
               if (totalLivres < 100) {
                    printf("Entrez le titre du livre : ");
                    scanf(" %[^\n]", titres[totalLivres]);
                    printf("Entrez l'auteur du livre : ");
                    scanf(" %[^\n]", auteurs[totalLivres]);
                    printf("Entrez le prix du livre : ");
                    scanf("%f", &prix[totalLivres]);
                    printf("Entrez la quantité en stock : ");
                    scanf("%d", &quantites[totalLivres]);
                    totalLivres++;
                    printf("Livre ajouté avec succès.\n");
                } else {
                    printf("Stock plein, impossible d'ajouter plus de livres.\n");
                }
                break;

            case 2:
                if (totalLivres > 0) {
                    printf("Liste des livres disponibles :\n");
                    for (int i = 0; i < totalLivres; i++) {
                        printf("Livre %d:\n", i + 1);
                        printf("Titre : %s\n", titres[i]);
                        printf("Auteur : %s\n", auteurs[i]);
                        printf("Prix : %.2f\n", prix[i]);
                        printf("Quantité : %d\n", quantites[i]);
                        printf("----------------------\n");
                    }
                } else {
                    printf("Aucun livre en stock.\n");
                }
                
                break;

            case 3: {
                char titreRecherche[100];
                printf("Entrez le titre du livre à rechercher : ");
                scanf(" %[^\n]", titreRecherche);
                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) {
                        printf("Livre trouvé :\n");
                        printf("Titre : %s\n", titres[i]);
                        printf("Auteur : %s\n", auteurs[i]);
                        printf("Prix : %.2f\n", prix[i]);
                        printf("Quantité : %d\n", quantites[i]);
                        trouve = 1;
                         break;
                    }
                }
                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                
                break;
            }

            case 4: {
                char titreRecherche[100];
                printf("Entrez le titre du livre dont vous voulez mettre à jour la quantité : ");
                scanf(" %[^\n]", titreRecherche);
                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) {
                        printf("Entrez la nouvelle quantité pour le livre '%s' : ", titres[i]);
                        scanf("%d", &quantites[i]);
                        printf("Quantité mise à jour avec succès.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                
                break;
            }

            case 5: {
                 char titreRecherche[100];
                printf("Entrez le titre du livre à supprimer : ");
                scanf(" %[^\n]", titreRecherche);
                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) {
                        for (int j = i; j < totalLivres - 1; j++) {
                            strcpy(titres[j], titres[j + 1]);
                            strcpy(auteurs[j], auteurs[j + 1]);
                            prix[j] = prix[j + 1];
                            quantites[j] = quantites[j + 1];
                        }
                        totalLivres--;
                        printf("Livre supprimé avec succès.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                
                break;
            }

            case 6: {
                int totalQuantites = 0;
                for (int i = 0; i < totalLivres; i++) {
                    totalQuantites += quantites[i];
                }
                printf("Nombre total de livres en stock : %d\n", totalQuantites);
                
                break;
            }

            case 7:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 7);

    return 0;
}