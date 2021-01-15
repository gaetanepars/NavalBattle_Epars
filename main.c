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
#include <windows.h>

#define SCORE_SIZE 1000

char usercoordinateX;
int usercoordinateY;

char username [20];


/** \brief realgrid - real map
 *
 *
 */
int realgrid[10][10] = {0};

/** \brief printgrid - Visible map
 *
 *
 */
char printgrid[10][10];

/** \brief attempts - Player's number of attempts
 *
 *
 */
int attempts = 0;

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

int ship1p1x = 0;
int ship1p1y = 0;
int ship1p2x = 0;
int ship1p2y = 1;

int ship2p1x = 1;
int ship2p1y = 0;
int ship2p2x = 1;
int ship2p2y = 1;
int ship2p3x = 1;
int ship2p3y = 2;

int ship3p1x = 2;
int ship3p1y = 0;
int ship3p2x = 2;
int ship3p2y = 1;
int ship3p3x = 2;
int ship3p3y = 2;
int ship3p4x = 2;
int ship3p4y = 3;

int ship4p1x = 3;
int ship4p1y = 0;
int ship4p2x = 3;
int ship4p2y = 1;
int ship4p3x = 3;
int ship4p3y = 2;
int ship4p4x = 3;
int ship4p4y = 3;
int ship4p5x = 3;
int ship4p5y = 4;

int ship5p1x = 4;
int ship5p1y = 0;
int ship5p2x = 4;
int ship5p2y = 1;

bool ship1sunk = false;
bool ship2sunk = false;
bool ship3sunk = false;
bool ship4sunk = false;
bool ship5sunk = false;
bool allshipsunk = false;

/** \brief emptyBuffer - This function empties the scanf buffer (not made by me)
 *
 *
 */
void emptyBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void Username(){
    printf("\nPlease choose a username: \n");
    scanf("%s", &username);
}

void Score(){
    FILE *fPtr;
    fPtr = fopen("scores.txt", "w");
    if(fPtr == NULL){
        printf("impossible de créer le fichier score.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; str[i] != '\n'; i++) {
        fputc(str[i], fptr);
    }
    fclose(fPtr);
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
            if (realgrid[row][column] == 0 || realgrid[row][column] == 1 || realgrid[row][column] == 2 ||
                realgrid[row][column] == 3 || realgrid[row][column] == 4 ||
                realgrid[row][column] == 5) { //fill the board with water without showing the ships
                printgrid[row][column] = '~';
            } else if (realgrid[row][column] == 6) {
                printgrid[row][column] = '=';
            } else if (realgrid[row][column] == 7) {
                printgrid[row][column] = '*';
            } else if (realgrid[row][column] == 8) {
                printgrid[row][column] = 'X';
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
    realgrid[ship1p1x][ship1p1y] = 1; //ship1             hit=1   missed shot=2 sunk ship=3   ship=4    damaged ship=5
    realgrid[ship1p2x][ship1p2y] = 1;

    realgrid[ship2p1x][ship2p1y] = 2; //ship2
    realgrid[ship2p2x][ship2p2y] = 2;
    realgrid[ship2p3x][ship2p3y] = 2;

    realgrid[ship3p1x][ship3p1y] = 3; //ship3
    realgrid[ship3p2x][ship3p2y] = 3;
    realgrid[ship3p3x][ship3p3y] = 3;
    realgrid[ship3p4x][ship3p4y] = 3;

    realgrid[ship4p1x][ship4p1y] = 4; //ship4
    realgrid[ship4p2x][ship4p2y] = 4;
    realgrid[ship4p3x][ship4p3y] = 4;
    realgrid[ship4p4x][ship4p4y] = 4;
    realgrid[ship4p5x][ship4p5y] = 4;

    realgrid[ship5p1x][ship5p1y] = 5; //ship5
    realgrid[ship5p2x][ship5p2y] = 5;


//do while that allows the game to continue until every ship is sunk
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

        if (realgrid[coordinateX][coordinateY] == 0) {
            realgrid[coordinateX][coordinateY] = 6;
            Mapgen();
            printf("\nRaté!\n");
            attempts++;
        }
//Mechanics ship1
        if (realgrid[coordinateX][coordinateY] == realgrid[ship1p1x][ship1p1y] && realgrid[ship1p1x][ship1p1y] == 1) {
            realgrid[ship1p1x][ship1p1y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship1p2x][ship1p2y] &&
                   realgrid[ship1p2x][ship1p2y] == 1) {
            realgrid[ship1p2x][ship1p2y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship1p1x][ship1p1y] &&
                   realgrid[ship1p1x][ship1p1y] == 7 && ship1sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship1p2x][ship1p2y] &&
                   realgrid[ship1p2x][ship1p2y] == 7 && ship1sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }

        if (realgrid[ship1p1x][ship1p1y] == 7 && realgrid[ship1p2x][ship1p2y] == 7) {
            ship1sunk = true;
            realgrid[ship1p1x][ship1p1y] = 8;
            realgrid[ship1p2x][ship1p2y] = 8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship1p1x][ship1p1y] && ship1sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship1p2x][ship1p2y] && ship1sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Mechanics ship2
        if (realgrid[coordinateX][coordinateY] == realgrid[ship2p1x][ship2p1y] && realgrid[ship2p1x][ship2p1y] == 2) {
            realgrid[ship2p1x][ship2p1y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p2x][ship2p2y] &&
                   realgrid[ship2p2x][ship2p2y] == 2) {
            realgrid[ship2p2x][ship2p2y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p3x][ship2p3y] &&
                   realgrid[ship2p3x][ship2p3y] == 2) {
            realgrid[ship2p3x][ship2p3y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p1x][ship2p1y] &&
                   realgrid[ship2p1x][ship2p1y] == 7 && ship2sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p2x][ship2p2y] &&
                   realgrid[ship2p2x][ship2p2y] == 7 && ship2sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p3x][ship2p3y] &&
                   realgrid[ship2p3x][ship2p3y] == 7 && ship2sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (realgrid[ship2p1x][ship2p1y] == 7 && realgrid[ship2p2x][ship2p2y] == 7 &&
            realgrid[ship2p3x][ship2p3y] == 7) {
            ship2sunk = true;
            realgrid[ship2p1x][ship2p1y] = 8;
            realgrid[ship2p2x][ship2p2y] = 8;
            realgrid[ship2p3x][ship2p3y] = 8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p1x][ship2p1y] &&
                   realgrid[ship2p1x][ship2p1y] == 8 && ship2sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p2x][ship2p2y] &&
                   realgrid[ship2p2x][ship2p2y] == 8 && ship2sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship2p3x][ship2p3y] &&
                   realgrid[ship2p3x][ship2p3y] == 8 && ship2sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }


//Mechanics ship3
        if (realgrid[coordinateX][coordinateY] == realgrid[ship3p1x][ship3p1y] &&
                 realgrid[ship3p1x][ship3p1y] == 3) {
            realgrid[ship3p1x][ship3p1y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p2x][ship3p2y] &&
                   realgrid[ship3p2x][ship3p2y] == 3) {
            realgrid[ship3p2x][ship3p2y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p3x][ship3p3y] &&
                   realgrid[ship3p3x][ship3p3y] == 3) {
            realgrid[ship3p3x][ship3p3y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p4x][ship3p4y] &&
                   realgrid[ship3p4x][ship3p4y] == 3) {
            realgrid[ship3p4x][ship3p4y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p1x][ship3p1y] &&
                   realgrid[ship3p1x][ship3p1y] == 7 && ship3sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p2x][ship3p2y] &&
                   realgrid[ship3p2x][ship3p2y] == 7 && ship3sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p1x][ship3p1y] &&
                   realgrid[ship3p3x][ship3p3y] == 7 && ship3sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p1x][ship3p1y] &&
                   realgrid[ship3p4x][ship3p4y] == 7 && ship3sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (realgrid[ship3p1x][ship3p1y] == 7 && realgrid[ship3p2x][ship3p2y] == 7 &&
            realgrid[ship3p3x][ship3p3y] == 7 && realgrid[ship3p4x][ship3p4y] == 7) {
            ship3sunk = true;
            realgrid[ship3p1x][ship3p1y] = 8;
            realgrid[ship3p2x][ship3p2y] = 8;
            realgrid[ship3p3x][ship3p3y] = 8;
            realgrid[ship3p4x][ship3p4y] = 8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p1x][ship3p1y] &&
                   realgrid[ship3p1x][ship3p1y] == 8 && ship3sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p2x][ship3p2y] &&
                   realgrid[ship3p2x][ship3p2y] == 8 && ship3sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p3x][ship3p3y] &&
                   realgrid[ship3p3x][ship3p3y] == 8 && ship3sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship3p4x][ship3p4y] &&
                   realgrid[ship3p4x][ship3p4y] == 8 && ship3sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Mechanics ship4
        if (realgrid[coordinateX][coordinateY] == realgrid[ship4p1x][ship4p1y] &&
                 realgrid[ship4p1x][ship4p1y] == 4) {
            realgrid[ship4p1x][ship4p1y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p2x][ship4p2y] &&
                   realgrid[ship4p2x][ship4p2y] == 4) {
            realgrid[ship4p2x][ship4p2y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p3x][ship4p3y] &&
                   realgrid[ship4p3x][ship4p3y] == 4) {
            realgrid[ship4p3x][ship4p3y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p4x][ship4p4y] &&
                   realgrid[ship4p4x][ship4p4y] == 4) {
            realgrid[ship4p4x][ship4p4y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p5x][ship4p5y] &&
                   realgrid[ship4p5x][ship4p5y] == 4) {
            realgrid[ship4p5x][ship4p5y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p1x][ship4p1y] &&
                   realgrid[ship4p1x][ship4p1y] == 7 && ship4sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p2x][ship4p2y] &&
                   realgrid[ship4p2x][ship4p2y] == 7 && ship4sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p3x][ship4p3y] &&
                   realgrid[ship4p3x][ship4p3y] == 7 && ship4sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p4x][ship4p4y] &&
                   realgrid[ship4p4x][ship4p4y] == 7 && ship4sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p5x][ship4p5y] &&
                   realgrid[ship4p5x][ship4p5y] == 7 && ship4sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (realgrid[ship4p1x][ship4p1y] == 7 && realgrid[ship4p2x][ship4p2y] == 7 &&
            realgrid[ship4p3x][ship4p3y] == 7 && realgrid[ship4p4x][ship4p4y] == 7 &&
            realgrid[ship4p5x][ship4p5y] == 7) {
            ship4sunk = true;
            realgrid[ship4p1x][ship4p1y] = 8;
            realgrid[ship4p2x][ship4p2y] = 8;
            realgrid[ship4p3x][ship4p3y] = 8;
            realgrid[ship4p4x][ship4p4y] = 8;
            realgrid[ship4p5x][ship4p5y] = 8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p1x][ship4p1y] &&
                   realgrid[ship4p1x][ship4p1y] == 8 && ship4sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p2x][ship4p2y] &&
                   realgrid[ship4p2x][ship4p2y] == 8 && ship4sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p3x][ship4p3y] &&
                   realgrid[ship4p3x][ship4p3y] == 8 && ship4sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p4x][ship4p4y] &&
                   realgrid[ship4p4x][ship4p4y] == 8 && ship4sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship4p5x][ship4p5y] &&
                   realgrid[ship4p5x][ship4p5y] == 8 && ship4sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Mechanics ship5
        if (realgrid[coordinateX][coordinateY] == realgrid[ship5p1x][ship5p1y] && realgrid[ship5p1x][ship5p1y] == 5) {
            realgrid[ship5p1x][ship5p1y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship5p2x][ship5p2y] &&
                   realgrid[ship5p2x][ship5p2y] == 5) {
            realgrid[ship5p2x][ship5p2y] = 7;
            Mapgen();
            printf("\nTouché!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship5p1x][ship5p1y] &&
                   realgrid[ship5p1x][ship5p1y] == 7 && ship5sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship5p2x][ship5p2y] &&
                   realgrid[ship5p2x][ship5p2y] == 7 && ship5sunk == false) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (realgrid[ship5p1x][ship5p1y] == 7 && realgrid[ship5p2x][ship5p2y] == 7) {
            ship5sunk = true;
            realgrid[ship5p1x][ship5p1y] = 8;
            realgrid[ship5p2x][ship5p2y] = 8;
            Mapgen();
            printf("\nVous avez coulé un navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship5p1x][ship5p1y] &&
                   realgrid[ship5p1x][ship5p1y] == 8 && ship5sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        } else if (realgrid[coordinateX][coordinateY] == realgrid[ship5p2x][ship5p2y] &&
                   realgrid[ship5p2x][ship5p2y] == 8 && ship5sunk == true) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Verification that all ships are sunk
        if (ship1sunk == true && ship2sunk == true && ship3sunk == true && ship4sunk == true && ship5sunk == true) {
            allshipsunk = true;
        }

    } while (allshipsunk != true);
    printf("\nVous avez gagné !  (%d tentatives)\n", attempts);
    emptyBuffer();
    printf("\nDésirez-vous retourner au menu principal?     (1=Oui 0=Non)\n");
}

void Init() {

    ship1sunk = false;
    ship2sunk = false;
    ship3sunk = false;
    ship4sunk = false;
    ship5sunk = false;
    allshipsunk = false;

    realgrid[ship1p1x][ship1p1y] = 1;
    realgrid[ship1p2x][ship1p2y] = 1;

    realgrid[ship2p1x][ship2p1y] = 2;
    realgrid[ship2p2x][ship2p2y] = 2;
    realgrid[ship2p3x][ship2p3y] = 2;

    realgrid[ship3p1x][ship3p1y] = 3;
    realgrid[ship3p2x][ship3p2y] = 3;
    realgrid[ship3p3x][ship3p3y] = 3;
    realgrid[ship3p4x][ship3p4y] = 3;

    realgrid[ship4p1x][ship4p1y] = 4;
    realgrid[ship4p2x][ship4p2y] = 4;
    realgrid[ship4p3x][ship4p3y] = 4;
    realgrid[ship4p4x][ship4p4y] = 4;
    realgrid[ship4p5x][ship4p5y] = 4;

    realgrid[ship5p1x][ship5p1y] = 5;
    realgrid[ship5p2x][ship5p2y] = 5;
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

    SetConsoleOutputCP(CP_UTF8);
    int usermenuchoice;
    int exitloop;

//do while that allows the user to go back to the menu or exit the game
    do {
        printf("\nBataille Navale\n");

        printf("1.Jouer\n");
        printf("2.Aide\n");
        printf("3.Score\n");
        printf("4.Quitter\n");


        scanf("%d", &usermenuchoice);

//switch that allows the user to choose between the different options in the menu
        switch (usermenuchoice) {
            case 1:
                emptyBuffer();
                Username();
                Init();
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
                //Score();
                scanf("%d", &exitloop);

                while (exitloop < 0 || exitloop > 1) {
                    emptyBuffer();
                    printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                    scanf("%d", &exitloop);
                }
                break;
            case 4:
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