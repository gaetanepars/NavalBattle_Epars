/**
 * \file      main.c
 * \author    <GaetanEpars>
 * \version   <0.1>
 * \date      <17-12-2020>
 * \brief     <Simple game of battleship>
 *
 * \details    <In this version the user can play, get help, and leave in a bug free environment>
 */

#include <stdio.h>
#include <stdbool.h>
char usercoordinateX;
int usercoordinateY;

int ship1p1 = 1;
int ship1p2 = 1;

int ship2p1 = 2;
int ship2p2 = 2;
int ship2p3 = 2;

int ship3p1 = 3;
int ship3p2 = 3;
int ship3p3 = 3;
int ship3p4 = 3;

int ship4p1 = 4;
int ship4p2 = 4;
int ship4p3 = 4;
int ship4p4 = 4;
int ship4p5 = 4;

int ship5p1 = 5;
int ship5p2 = 5;
/** \brief realgrid - real map
 *
 *
 */
int realgrid [10][10]={0};

/** \brief printgrid - Visible map
 *
 *
 */
char printgrid [10][10];

/** \brief attempts - Player's number of attempts
 *
 *
 */
int attempts=0;

/** \brief coordinateX - Coordinate X
 *
 *
 */
int coordinateX;

/** \brief coordinateY - Coordinate Y
 *
 *
 */
int coordinateY;

bool ship1sunk=false;
bool ship2sunk=false;
bool ship3sunk=false;
bool ship4sunk=false;
bool ship5sunk=false;

/** \brief emptyBuffer - This function empties the scanf buffer (not made by me)
 *
 *
 */
void emptyBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/** \brief Mapgen - This function generates the real map and prints the visible map
 *
 *
 */
void Mapgen() {

    //real map of the game
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
        }
    }


    //prints the "visible map"
    char Aj = 65; //ascii for A
    printf("\n    1   2   3   4   5   6   7   8   9   10\n");
    for (int row = 0; row < 10; ++row) {
        printf("%c", Aj);
        Aj++; //increments the char which makes it move up the ascii table
        for (int column = 0; column < 10; ++column) {
            if (realgrid[row][column]==0 || realgrid[row][column]==1|| realgrid[row][column]==2|| realgrid[row][column]==3|| realgrid[row][column]==4|| realgrid[row][column]==5){ //fill the board with water without showing the ships
                printgrid[row][column]='~';
            }
            else if(realgrid[row][column]==6){
                printgrid[row][column]='=';
            }
            else if(realgrid[row][column]==7){
                printgrid[row][column]='*';
            }
            else if(realgrid[row][column]==8){
                printgrid[row][column]='X';
            }
            printf(" %3c", printgrid[row][column]);
        }
        printf("\n");
    }
}

/** \brief Play - This function sets the ships positions, asks the user coordinates and checks what is there
 *
 *
 */
void Play() {
    int ship1x=0;
    int ship1y=0;
    realgrid[ship1x][ship1y] = ship1p1; //ship1             hit=1   missed shot=2 sunk ship=3   ship=4    damaged ship=5
    realgrid[0][1] = ship1p2;

    realgrid[1][0] = ship2p1; //ship2
    realgrid[1][1] = ship2p2;
    realgrid[1][2] = ship2p3;

    realgrid[2][0] = ship3p1; //ship3
    realgrid[2][1] = ship3p2;
    realgrid[2][2] = ship3p3;
    realgrid[2][3] = ship3p4;

    realgrid[3][0] = ship4p1; //ship4
    realgrid[3][1] = ship4p2;
    realgrid[3][2] = ship4p3;
    realgrid[3][3] = ship4p4;
    realgrid[3][4] = ship4p5;

    realgrid[4][0] = ship5p1; //ship5
    realgrid[4][1] = ship5p2;


    int shipcount = 0;

    //do while that allows the game to continue until every ship is sunk ==>shipcount=5
    do {
        printf("\nVeuillez entrer des coordonnées: ");

        scanf(" %c", &usercoordinateX);//-32
        scanf(" %d", &usercoordinateY);


        //if else loops to stop the user from using invalid X coordinate
        while (usercoordinateX >= 0 && usercoordinateX <= 64) {
            emptyBuffer();
            printf("\nCoordonnées non valides!\nVeuillez choisir des coordonnées correctes: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %d", &usercoordinateY);
        }
        while (usercoordinateX >= 91 && usercoordinateX <= 96) {
            emptyBuffer();
            printf("\nCoordonnées non valides!\nVeuillez choisir des coordonnées correctes: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %d", &usercoordinateY);
        }
        while (usercoordinateX > 123) {
            emptyBuffer();
            printf("\nCoordonnées non valides!\nVeuillez choisir des coordonnées correctes: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %d", &usercoordinateY);
        }


        //if else loops to stop the user from using invalid Y coordinate
        while (usercoordinateY < 0 || usercoordinateY > 10) {
            emptyBuffer();
            printf("\nCoordonnées non valides!\nVeuillez choisir des coordonnées correctes: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %d", &usercoordinateY);
        }

        //user coordinates to real coordinates conversion
        coordinateY = usercoordinateY - 1;
        if (usercoordinateX >= 97 && usercoordinateX <= 122) {
            coordinateX = usercoordinateX - 97;                         //allow the user to use caps or not
        }
        if (usercoordinateX >= 65 && usercoordinateX <= 90) {
            coordinateX = usercoordinateX - 65;
        }

        if(ship1sunk==true){
            ship1p1=8;
            ship1p2=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);
        }
        if(ship2sunk==true){
            ship2p1=8;
            ship2p2=8;
            ship2p3=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);
        }
        if(ship3sunk==true){
            ship3p1=8;
            ship3p2=8;
            ship3p3=8;
            ship3p4=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);
        }
        if(ship4sunk==true){
            ship4p1=8;
            ship4p2=8;
            ship4p3=8;
            ship4p4=8;
            ship4p5=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);
        }
        if (ship5sunk==true){
            ship5p1=8;
            ship5p2=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);
        }

        if (realgrid[coordinateX][coordinateY]==0){
            realgrid[coordinateX][coordinateY]=6;
            Mapgen();
            printf("\nRaté!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p1 && ship1p1==1){
            realgrid[coordinateX][coordinateY]=7;
            ship1p1=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
            if (ship1p1==7 && ship1p2==7){
                ship1sunk=true;
                ship1p1=8;
                ship1p2=8;
                Mapgen();
                printf("\nVous avez coulé un navire!\n");
                printf("%d  %d", realgrid[0][0], realgrid[0][1]);
                shipcount++;
                printf("\n%d navire(s) restant(s)\n", 5-shipcount);

            }
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p2 && ship1p2==1){
            realgrid[coordinateX][coordinateY]=7;
            ship1p2=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
            if (ship1p1==7 && ship1p2==7){
                ship1sunk=true;
                ship1p1=8;
                ship1p2=8;
                Mapgen();
                printf("\nVous avez coulé un navire!\n");
                printf("%d  %d", realgrid[0][0], realgrid[0][1]);
                shipcount++;
                printf("\n%d navire(s) restant(s)\n", 5-shipcount);

            }
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p1 && realgrid[coordinateX][coordinateY]==7 && ship1sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p2&& realgrid[coordinateX][coordinateY]==7 && ship1sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p1 && ship1sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship1p2 && ship1sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (ship1p1==7 && ship1p2==7){
            ship1sunk=true;
            ship1p1=8;
            ship1p2=8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            shipcount++;
            attempts++;
            printf("\n%d navire(s) restant(s)\n", 5-shipcount);

        }
        else if (realgrid[coordinateX][coordinateY]==ship2p1 && ship2p1==2){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p2 && ship2p2==2){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p3 && ship2p3==2){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p1 && ship2p1==7 && ship2sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p2 && ship2p2==7 && ship2sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p3 && ship2p3==7 && ship2sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p1 && ship2sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p2 && ship2sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship2p3 && ship2sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (ship2p1==7 && ship2p2==7 && ship2p3==7){
            ship2sunk=true;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p1 && ship3p1==3){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p2 && ship3p2==3){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p3 && ship3p3==3){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p4 && ship3p4==3){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p1&&ship3p1==7 && ship3sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p2&&ship3p2==7 && ship3sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p3&&ship3p3==7 && ship3sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p4&&ship3p4==7 && ship3sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p1 && ship3sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p2 && ship3sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p3 && ship3sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship3p4 && ship3sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (ship3p1==7 && ship3p2==7 && ship3p3==7 && ship3p4==7){
            ship3sunk=true;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p1 && ship4p1==4){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p2 && ship4p2==4){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p3 && ship4p3==4){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p4 && ship4p4==4){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p5 && ship4p5==4){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p1 && ship4p1==7 && ship4sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p2 && ship4p2==7 && ship4sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p3 && ship4p3==7 && ship4sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p4 && ship4p4==7 && ship4sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p5 && ship4p5==7 && ship4sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p1 && ship4sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p2 && ship4sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p3 && ship4sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p4 && ship4sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship4p5 && ship4sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (ship4p1==7 && ship4p2==7 && ship4p3==7 && ship4p4==7 && ship4p5==7){
            ship4sunk=true;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p1 && ship5p1==5){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p2 && ship5p2==5){
            realgrid[coordinateX][coordinateY]=7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p1&&ship5p1==7 && ship5sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p2&&ship5p2==7 && ship5sunk==false){
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p1 && ship5sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (realgrid[coordinateX][coordinateY]==ship5p2 && ship5sunk==true){
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }
        else if (ship5p1==7 && ship5p2==7){
            ship5sunk=true;
        }

    } while (shipcount != 5);
    printf("\nVous avez gagné !  (%d tentatives)\n", attempts);
    emptyBuffer();
    printf("\nDésirez-vous retourner au menu principal?     (1=Oui 0=Non)\n");
}




/** \brief Help - This function shows tips to the player
 *
 *
 */
    void Help() {                                //show rules and possibly tips

            printf("\nAIDE\n");
            printf("\nIl s'agit d'un simple jeu de bataille navale, vous jouez en entrant des coordonnées dans la console afin de couler les bateaux ennemis.");
            printf("\nPour couler un bateau il est nécessaire de toucher toutes ses parties.");
            printf("\nIl y a 5 bateaux et le jeu se termine lorsqu'ils sont tous coulés.");
            printf("\n'~' = Eau || '=' = Tire raté || '*' = Touché || 'X' = Coulé");
            printf("(Menu=1  Quitter=0)\n");
        }

/** \brief main - This function is the main menu and base of the program
 *\return int
 *
 */
int main() {                                //menu
        int usermenuchoice;
        int exitloop;

        //do while that allows the user to go back to the menu or exit the game
        do {
            printf("\nBataille Navale\n");

            printf("1.Jouer\n");
            printf("2.Aide\n");
            printf("3.Quitter\n");


            scanf("%d", &usermenuchoice);

            //switch that allows the user to choose between the different options in the menu
            switch (usermenuchoice) {
                case 1:
                    emptyBuffer();
                    Mapgen();
                    Play();
                    scanf("%d", &exitloop);

                    while (exitloop < 0 || exitloop > 1) {
                        emptyBuffer();
                        printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                        scanf("%d", &exitloop);
                    }
                    break;
                case 2:
                    emptyBuffer();
                    Help();
                    scanf("%d", &exitloop);

                    while (exitloop < 0 || exitloop > 1) {
                        emptyBuffer();
                        printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                        scanf("%d", &exitloop);
                    }
                    break;
                case 3:
                    emptyBuffer();
                    printf("Êtes-vous sûr de vouloir quitter? (1=Non 0=Oui)\n");
                    scanf("%d", &exitloop);

                    while (exitloop < 0 || exitloop > 1) {
                        emptyBuffer();
                        printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                        scanf("%d", &exitloop);
                    }
                    break;
                default:
                    emptyBuffer();
                    printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                    scanf("%d", &exitloop);

                    while (exitloop < 0 || exitloop > 1) {
                        emptyBuffer();
                        printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                        scanf("%d", &exitloop);
                    }
            }

        } while (exitloop != 0);


        return 0;
    }