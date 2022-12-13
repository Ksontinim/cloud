#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char plateau[3][3];
char joueur1 = 'X';
char joueur2 = 'O';
char joueur1_nom[20] = "Joueur 1";
char joueur2_nom[20] = "Joueur 2";

void initialiser_plateau();

void afficher_plateau();

int coup_possibles();

void role_joueur(char);

char verifier_gagnant();

void afficher_gagnant(char);


int main()
{
    char reponse;
    char gagnant = ' ';

    do
    {
        printf("Donner le nom du premier joueur: ");
        gets(joueur1_nom);
    }
    while (strlen(joueur1_nom)==0);

    do
    {
        printf("Donner le nom du deuxieme joueur: ");
        gets(joueur2_nom);
    }
    while (strlen(joueur2_nom)==0);

    do
    {
        reponse = ' ';
        gagnant = ' ';

        initialiser_plateau();

        while (gagnant==' ' && verifier_coups_possibles()!=0)
        {
            afficher_plateau();

            printf("%s joue !\n", joueur1_nom);
            role_joueur(joueur1);
            printf("\n");
            gagnant = verifier_gagnant();
            if (gagnant != ' ' || verifier_coups_possibles() == 0)
            {
                break;
            }

            afficher_plateau();

            printf("%s joue !\n", joueur2_nom);
            role_joueur(joueur2);
            printf("\n");
            gagnant = verifier_gagnant();
            if (gagnant != ' ' || verifier_coups_possibles() == 0)
            {
                break;
            }
        }

        afficher_plateau();

        afficher_gagnant(gagnant);

        printf("\n\nVoulez-vous rejouer ? (Y/N):\n");
        scanf("%c", &reponse);
        reponse = toupper(reponse);

    }
    while (reponse != 'N');

    printf("\nMerci d'avoir joue\n");

    return 0;
}

void initialiser_plateau()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            plateau[i][j]= ' ';
        }
    }
};

void afficher_plateau()
{
    printf("\t\t\t\t\t\t\t %c | %c | %c ", plateau[0][0], plateau[0][1], plateau[0][2]);
    printf("\n\t\t\t\t\t\t\t---|---|---\n");
    printf("\t\t\t\t\t\t\t %c | %c | %c ", plateau[1][0], plateau[1][1], plateau[1][2]);
    printf("\n\t\t\t\t\t\t\t---|---|---\n");
    printf("\t\t\t\t\t\t\t %c | %c | %c ", plateau[2][0], plateau[2][1], plateau[2][2]);
    printf("\n");
}

int verifier_coups_possibles()
{
    int coups_possibles = 9;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (plateau[i][j] != ' ')
            {
                coups_possibles--;
            }
        }
    }
    return coups_possibles;
}

void role_joueur(char joueur)
{
    int x,y;
    do
    {
        do
        {
            printf("Donner le numero de ligne (1-3) #");
            scanf("%d", &x);
            x--;
        }
        while (x<0 || x>2);

        do
        {
            printf("Entrer le numero de la colonne (1-3) #");
            scanf("%d", &y);
            y--;
        }
        while (y<0 || y>2);

        if (plateau[x][y] != ' ')
        {
            printf("Cellule occupe !\n");
        }
        else
        {
            plateau[x][y] = joueur;
            break;
        }
    }
    while (plateau[x][y] != ' ');
}

char verifier_gagnant()
{

    // verifier par ligne
    for(int i=0; i<3; i++)
    {
        if (plateau[i][0] == plateau[i][1] && plateau[i][0] == plateau[i][2])
        {
            return plateau[i][0];
        }
    }

    // verifier par colonne
    for(int j=0; j<3; j++)
    {
        if (plateau[0][j] == plateau[1][j] && plateau[0][j] == plateau[2][j])
        {
            return plateau[0][j];
        }
    }

    // verifier les diagonales
    if (plateau[0][0] == plateau[1][1] && plateau[0][0] == plateau[2][2])
    {
        return plateau[0][0];
    }
    if (plateau[0][2] == plateau[1][1] && plateau[0][2] == plateau[2][0])
    {
        return plateau[0][0];
    }

    return ' ';
}

void afficher_gagnant(char gagnant)
{
    if(gagnant == joueur1)
    {
        printf("%s a gagne !", joueur1_nom);
    }
    else if(gagnant == joueur2)
    {
        printf("%s a gagne !", joueur2_nom);
    }
    else
    {
        printf("Egalite !");
    }
}

