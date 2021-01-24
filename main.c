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
#include <time.h>

char usercoordinateX;
int usercoordinateY;
char username [20];
char currentchar;
int currentint;
int i,j;
int boat1hit=0;
int boat2hit=0;
int boat3hit=0;
int boat4hit=0;
int boat5hit=0;

int realgrid[10][10];

char printgrid[10][10];

int attempts = 0;

int score = 0;

int logtype = 0;


int coordinateX;

int coordinateY;

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
/** \brief Username - This function asks for the user to input a username
 *
 *
 */
void Username(){
    printf("\nPlease choose a username: \n");
    scanf("%s", &username);
}
/** \brief Writescore - This function opens the score file and appends the current username and score
 *
 *
 */
void Writescore(){
    score=attempts;
    FILE *fPtr;
    fPtr = fopen("../Scores/scores.txt", "a");
    if(fPtr == NULL){
        printf("impossible de créer le fichier score.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr, "%s %d \n", username, score);
    fclose(fPtr);
    }
/** \brief Showscore - This function reads and displays the content of the score file
 *
 *
 */
void Showscore(){

        FILE* fptr = NULL;
        int actual_character = 0;

        fptr = fopen("../Scores/scores.txt", "r");

        if (fptr != NULL){
            do
            {
                actual_character = fgetc(fptr);
                printf("%c", actual_character);
            }
            while (actual_character != EOF);
            fclose(fptr);
        }
    }
/** \brief Clearscore - This function clears the content of the score file using the writing mode to overwrite it
 *
 *
 */
void Clearscore(){
        FILE* fptr = NULL;
        fptr = fopen("../Scores/scores.txt", "w");
        fclose(fptr);
}
/** \brief Log - This function uses a switch to input the correct data with date and time into the log file
 *
 *
 */
void Log(){
    time_t t;
    time(&t);
    FILE* fptr = NULL;
    fptr = fopen("../Logs/log.txt", "a");
    switch (logtype) {
        case 1:
            fprintf(fptr, "Game launched - %s\n", ctime(&t));
            break;
        case 2:
            fprintf(fptr, "User logged in as %s - %s\n", username, ctime(&t));
            break;

        case 3:
            fprintf(fptr, "%s launched an attack on coordinate %c%d - %s\n", username, usercoordinateX, usercoordinateY, ctime(&t));
            break;
        case 4:
            fprintf(fptr, "%s has hit a ship - %s\n", username, ctime(&t));
            break;
        case 5:
            fprintf(fptr, "%s missed a shot - %s\n", username, ctime(&t));
            break;

        case 6:
            fprintf(fptr, "%s sunk a ship - %s\n", username, ctime(&t));
            break;

        case 7:
            fprintf(fptr, "%s is victorious with a score of %d - %s\n", username, score, ctime(&t));
            break;
        case 8:
            fprintf(fptr, "Game closed - %s\n", ctime(&t));
            break;
    }

    fclose(fptr);
}
/** \brief Showlog - This function displays the content of the log file
 *
 *
 */
void Showlog(){
    FILE* fptr = NULL;
    int actual_character = 0;

    fptr = fopen("../Logs/log.txt", "r");

    if (fptr != NULL){
        do
        {
            actual_character = fgetc(fptr);
            printf("%c", actual_character);
        }
        while (actual_character != EOF);
        fclose(fptr);
    }
}
/** \brief Clearlog - This function clears the content of the log file using the writing mode to overwrite it
 *
 *
 */
void Clearlogs(){
    FILE* fptr = NULL;
    fptr = fopen("../Logs/log.txt", "w");
    fclose(fptr);
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
            } else if (realgrid[row][column] == 7 || realgrid[row][column] == 8 || realgrid[row][column] == 9 ||
                       realgrid[row][column] == 10 || realgrid[row][column] == 11) {
                printgrid[row][column] = '*';
            } else if (realgrid[row][column] == 12 || realgrid[row][column] == 13 || realgrid[row][column] == 14 ||
                       realgrid[row][column] == 15) {
                printgrid[row][column] = 'X';
            }
            printf(" %3c", printgrid[row][column]);
        }
        printf("\n");
    }
    }

void Txtfileconverter(){
    currentint = currentchar -'0';
    if(currentchar!='\n'){
        realgrid[i][j] = currentint;
        j++;
        if (j==10){
            j=0;
            i++;
        }
    }
}
/** \brief Mapselector - This function uses a random number switch to choose a map and then copies the content of the map file to the real grid
 *
 *
 */
void Mapselector(){
    FILE *fptr;
    srand(time(NULL));
    int r = rand()%3;
    i=0;
    j=0;


    switch (r) {
        case 1:
        fptr=fopen("../Maps/Map1.txt", "r");
            if (fptr != NULL){
                do {
                    currentchar=getc(fptr);
                    Txtfileconverter();
                } while (currentchar!=EOF);

            }
            else{
                printf("Impossible d'ouvrir le fichier\n");
            }
            fclose(fptr);
            break;
        case 2:
            fptr=fopen("../Maps/Map2.txt", "r");
            if (fptr != NULL){
                do {
                    currentchar=getc(fptr);
                    Txtfileconverter();
                } while (currentchar!=EOF);

            }
            else{
                printf("Impossible d'ouvrir le fichier\n");
            }
            fclose(fptr);
            break;
        case 3:
            fptr=fopen("../Maps/Map3.txt", "r");
            if (fptr != NULL){
                do {
                    currentchar=getc(fptr);
                    Txtfileconverter();
                } while (currentchar!=EOF);

            }
            else{
                printf("Impossible d'ouvrir le fichier\n");
            }
            fclose(fptr);
            break;

    }
}


/** \brief Play - This function sets the ships positions, asks the user coordinates and checks what is there
 *
 *
 */
void Play() {
//do while that allows the game to continue until every ship is sunk
    do {
        printf("\nVeuillez entrer des coordonnées: ");

        scanf(" %c", &usercoordinateX);//-32
        scanf(" %d", &usercoordinateY);

        logtype=3;
        Log();


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
            logtype=5;
            Log();
            attempts++;
        }
//Mechanics ship1
        if (realgrid[coordinateX][coordinateY] == 1) {
            realgrid[coordinateX][coordinateY] = 7;
            Mapgen();
            printf("\nTouché!\n");
            logtype=4;
            Log();
            attempts++;
            boat1hit++;
        } else if (realgrid[coordinateX][coordinateY]== 7) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (boat1hit==2) {
            ship1sunk = true;
            for(int i=0;i<10;i++){
                for (int j = 0; j < 10; ++j) {
                    if (realgrid[i][j] == 7) {
                        realgrid[i][j] = 12;
                    }
                }
                    Mapgen();
                    printf("\nVous avez coulé un navire!\n");
                    logtype=6;
                    Log();
                    attempts++;
                }
            } else if (realgrid[coordinateX][coordinateY] == 12) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Mechanics ship2
        if (realgrid[coordinateX][coordinateY]== 2) {
            realgrid[coordinateX][coordinateY] = 8;
            Mapgen();
            printf("\nTouché!\n");
            logtype=4;
            Log();
            attempts++;
            boat2hit++;
        } else if (realgrid[coordinateX][coordinateY]== 8) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (boat2hit==3) {
            ship2sunk = true;
            for(int i=0;i<10;i++) {
                for (int j = 0; j < 10; ++j) {
                    if (realgrid[i][j] == 8) {
                        realgrid[i][j] = 13;
                    }
                }
                Mapgen();
                printf("\nVous avez coulé un navire!\n");
                logtype = 6;
                Log();
                attempts++;
            }
        } else if (realgrid[coordinateX][coordinateY]== 13) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }


//Mechanics ship3
        if (realgrid[coordinateX][coordinateY]== 3) {
            realgrid[coordinateX][coordinateY] = 9;
            Mapgen();
            printf("\nTouché!\n");
            logtype=4;
            Log();
            attempts++;
            boat3hit++;
        } else if (realgrid[coordinateX][coordinateY]== 9) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (boat3hit==4) {
            ship3sunk = true;
            for(int i=0;i<10;i++) {
                for (int j = 0; j < 10; ++j) {
                    if (realgrid[i][j] == 9) {
                        realgrid[i][j] = 14;
                    }
                }
                Mapgen();
                printf("\nVous avez coulé un navire!\n");
                logtype = 6;
                Log();
                attempts++;
            }
        } else if (realgrid[coordinateX][coordinateY]== 14) {
            printf("\nVous avez déjà coulé ce navire!\n");
            attempts++;
        }

//Mechanics ship4
        if (realgrid[coordinateX][coordinateY]== 4) {
            realgrid[coordinateX][coordinateY] = 10;
            Mapgen();
            printf("\nTouché!\n");
            logtype=4;
            Log();
            attempts++;
            boat4hit++;
        } else if (realgrid[coordinateX][coordinateY]== 10) {
            printf("\nVous avez déjà endommagé cette partie du navire!\n");
            attempts++;
        }
        if (boat4hit==5) {
            ship4sunk = true;
            for(int i=0;i<10;i++) {
                for (int j = 0; j < 10; ++j) {
                    if (realgrid[i][j] == 10) {
                        realgrid[i][j] = 15;
                    }
                }
                Mapgen();
                printf("\nVous avez coulé un navire!\n");
                logtype = 6;
                Log();
                attempts++;
            }
                } else if (realgrid[coordinateX][coordinateY] == 15) {
                    printf("\nVous avez déjà coulé ce navire!\n");
                    attempts++;
                }

//Mechanics ship5
                if (realgrid[coordinateX][coordinateY] == 5) {
                    realgrid[coordinateX][coordinateY] = 11;
                    Mapgen();
                    printf("\nTouché!\n");
                    logtype = 4;
                    Log();
                    attempts++;
                    boat5hit++;
                } else if (realgrid[coordinateX][coordinateY] == 11) {
                    printf("\nVous avez déjà endommagé cette partie du navire!\n");
                    attempts++;
                }
                if (boat5hit == 2) {
                    ship5sunk = true;
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 10; ++j) {
                            if (realgrid[i][j] == 11) {
                                realgrid[i][j] = 16;
                            }
                        }
                        Mapgen();
                        printf("\nVous avez coulé un navire!\n");
                        logtype = 6;
                        Log();
                        attempts++;
                    }
                        } else if (realgrid[coordinateX][coordinateY] == 15) {
                            printf("\nVous avez déjà coulé ce navire!\n");
                            attempts++;
                        }

//Verification that all ships are sunk
                        if (ship1sunk == true && ship2sunk == true && ship3sunk == true && ship4sunk == true &&
                            ship5sunk == true) {
                            allshipsunk = true;
                        }

                    }
                    while (allshipsunk != true);
                    printf("\nVous avez gagné !  (%d tentatives)\n", attempts);
                    logtype = 7;
                    Log();
                    Writescore();
                    emptyBuffer();
                    printf("\nDésirez-vous retourner au menu principal?     (1=Oui 0=Non)\n");
                }
/** \brief Init - This function resets the booleans and the score/attempts
 *
 *
 */
void Init() {

    ship1sunk = false;
    ship2sunk = false;
    ship3sunk = false;
    ship4sunk = false;
    ship5sunk = false;
    allshipsunk = false;
    attempts=0;
    score=0;
}

/** \brief Help - This function shows tips to the player
 *
 *
 */
void Help() {                                //show rules and possibly tips

    printf("\nAIDE\n");
    printf("Il s'agit d'un simple jeu de bataille navale, vous jouez en entrant des coordonnées dans la console afin de couler les bateaux ennemis.\n");
    printf("Pour couler un bateau il est nécessaire de toucher toutes ses parties.\n");
    printf("Il y a 5 bateaux et le jeu se termine lorsqu'ils sont tous coulés.\n");
    printf("'~' = Eau || '=' = Tire raté || '*' = Touché || 'X' = Coulé\n");
    printf("\n(Menu=1  Quitter=0)\n");
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
        Init();
        logtype=1;
        Log();
        printf("\nBataille Navale\n");

        printf("1.Jouer\n");
        printf("2.Aide\n");
        printf("3.Score\n");
        printf("4.Effacer les scores\n");
        printf("5.Afficher les Logs\n");
        printf("6.Effacer les logs\n");
        printf("7.Quitter\n");


        scanf("%d", &usermenuchoice);

//switch that allows the user to choose between the different options in the menu
        switch (usermenuchoice) {
            case 1:
                emptyBuffer();
                Username();
                logtype=2;
                Log();
                Init();
                Mapgen();
                Mapselector();
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
                Showscore();
                printf("Voulez-vous retourner au menu?  (Menu=1  Quitter=0)\n");
                scanf("%d", &exitloop);

                while (exitloop < 0 || exitloop > 1) {
                    emptyBuffer();
                    printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                    scanf("%d", &exitloop);
                }
                break;
            case 4:
                emptyBuffer();
                Clearscore();
                printf("Tous les scores ont été effacés!\n");
                exitloop=1;
                break;
            case 5:
                emptyBuffer();
                Showlog();
                printf("Voulez-vous retourner au menu? (Menu=1 Quitter=0)\n");
                scanf("%d", &exitloop);

                while (exitloop < 0 || exitloop > 1) {
                    emptyBuffer();
                    printf("\nCommande invalide!  (Menu=1  Quitter=0)\nVeuillez entrer une commande valide: ");
                    scanf("%d", &exitloop);
                }
                break;
            case 6:
                emptyBuffer();
                Clearlogs();
                printf("Les logs ont été effacés!\n");
                exitloop=1;
                break;
            case 7:
                emptyBuffer();
                printf("Êtes-vous sûr de vouloir quitter? (Menu=1  Quitter=0)\n");
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

    logtype=8;
    Log();
    return 0;
}