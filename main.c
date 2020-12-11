#include <stdio.h>
int realgrid [10][10]={0};
char printgrid [10][10];

int coordinateX;
int coordinateY;

int Mapgen() {

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
            if (realgrid[row][column]==0 || realgrid[row][column]==4){ //fill the board with water without showing the ships
                printgrid[row][column]='~';
            }
            else if(realgrid[row][column]==1){
                printgrid[row][column]='*';
            }
            else if(realgrid[row][column]==2){
                printgrid[row][column]='=';
            }
            else if(realgrid[row][column]==3){
                printgrid[row][column]='X';
            }
            printf(" %3c", printgrid[row][column]);
        }
        printf("\n");
    }
}

int Play() {

    char usercoordinateX;
    char usercoordinateY;

    realgrid[0][0] = 4; //ship1             hit=1   missed shot=2 sunk ship=3   ship=4    damaged ship=5
    realgrid[0][1] = 4;

    realgrid[2][0] = 4; //ship2
    realgrid[2][1] = 4;

    realgrid[4][0] = 4; //ship3
    realgrid[4][1] = 4;

    realgrid[6][0] = 4; //ship4
    realgrid[6][1] = 4;

    realgrid[8][0] = 4; //ship5
    realgrid[8][1] = 4;

    int shipcount=0;

    //do while that allows the game to continue until every ship is sunk ==>shipcount=5
    do {
        printf("\nPlease choose a coordinate: ");

        scanf(" %c", &usercoordinateX);//-32
        scanf(" %c", &usercoordinateY);


        //if else loops to stop the user from using invalid X coordinate
        if (usercoordinateX>=0 && usercoordinateX<=64){
            printf("\nInvalid coordinates!\nPlease choose valid coordinates: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %c", &usercoordinateY);
        }
        else if (usercoordinateX>=91 && usercoordinateX<=96){
            printf("\nInvalid coordinates!\nPlease choose valid coordinates: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %c", &usercoordinateY);
        }
        else if (usercoordinateX>123){
            printf("\nInvalid coordinates!\nPlease choose valid coordinates: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %c", &usercoordinateY);
        }


        //if else loops to stop the user from using invalid Y coordinate
        if (usercoordinateY>=0 && usercoordinateY<=47){
            printf("\nInvalid coordinates!\nPlease choose valid coordinates: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %c", &usercoordinateY);
        }
        else if (usercoordinateY>58){
            printf("\nInvalid coordinates!\nPlease choose valid coordinates: ");
            scanf(" %c", &usercoordinateX);
            scanf(" %c", &usercoordinateY);
        }


        //user coordinates to real coordinates conversion
        if(usercoordinateY>=48 && usercoordinateY<=57){
            coordinateY = usercoordinateY - 49;
        }
        if (usercoordinateX >= 97 && usercoordinateX <= 122){
            coordinateX=usercoordinateX-97;                         //allow the user to use caps or not
        }
        if (usercoordinateX >=65 && usercoordinateX <=90) {
            coordinateX = usercoordinateX - 65;
        }

        //Checks if the coordinates corresponds to a ship and if it does sets the other part of the ship to 5 (damaged ship)
        if (realgrid[coordinateX][coordinateY] == 4) {
            realgrid[coordinateX][coordinateY] = 1;
            Mapgen();
            if (realgrid[coordinateX-1][coordinateY] == 4){
                realgrid[coordinateX-1][coordinateY] =5;
            }
            else if (realgrid[coordinateX+1][coordinateY] == 4){
                realgrid[coordinateX+1][coordinateY] =5;
            }
            if (realgrid[coordinateX][coordinateY-1] == 4){
                realgrid[coordinateX][coordinateY-1] =5;
            }
            if (realgrid[coordinateX][coordinateY+1] == 4){
                realgrid[coordinateX][coordinateY+1] =5;
            }
            printf("\nYou've hit a ship!\n");

            //checks if the coordinates correspond to water and if it does set the point to missed shot (2)
        } else if (realgrid[coordinateX][coordinateY] == 0) {
            realgrid[coordinateX][coordinateY] = 2;
            Mapgen();
            printf("\nYou missed!\n");
            printf("\n%d\n", coordinateX);
            printf("\n%d\n", coordinateY);

            //checks if the coordinates correspond to a damaged ship and if it does set the ship coordinates to sunk ship (3) and increments the shipcount
        } else if (realgrid[coordinateX][coordinateY] == 5){
            realgrid[coordinateX][coordinateY] = 3;
            if (realgrid[coordinateX-1][coordinateY] == 1){
                realgrid[coordinateX-1][coordinateY] =3;
            }
            else if (realgrid[coordinateX+1][coordinateY] == 1){
                realgrid[coordinateX+1][coordinateY] =3;
            }
            else if (realgrid[coordinateX][coordinateY-1] == 1){
                realgrid[coordinateX][coordinateY-1] =3;
            }
            else if (realgrid[coordinateX][coordinateY+1] == 1){
                realgrid[coordinateX][coordinateY+1] =3;
            }
            Mapgen();
            printf("\nYou've sunk a ship!\n");
            shipcount++;
        }

            //tells the player that it has already targeted the coordinate
        else if (realgrid[coordinateX][coordinateY] == 3) {
            printf("\nYou've already sunk that ship!\n");
        }else if (realgrid[coordinateX][coordinateY] == 1) {
            printf("\nYou've already hit that part of the ship!\n");
        }

    }while (shipcount != 5);
    printf("\nYou won !\n");
    printf("\nDo you want to go back to the menu?      (1=Yes 0=No)\n");
}




int Help(){                                //show rules and possibly tips

    printf("\nhelp1\n");
    printf("help2\n");
    printf("help3\n");
    printf("help4\n");
    printf("help5\n");
    printf("Menu=>1 Exit=>0\n");
}

int main() {                                //menu

    int usermenuchoice;
    int exitloop;

    //do while that allows the user to go back to the menu or exit the game
    do {
        printf("\nBattleship\n");

        printf("1.Play\n");
        printf("2.Help\n");
        printf("3.Exit\n");

        scanf("%d", &usermenuchoice);

        //switch that allows the user to choose between the different options in the menu
        switch (usermenuchoice) {
            case 1:
                Mapgen();
                Play();
                scanf("%d", &exitloop);
                break;
            case 2:
                Help();
                scanf("%d", &exitloop);
                break;
            case 3:
                printf("Are you sure you want to exit? (1=NO 0=YES)\n");
                scanf("%d", &exitloop);
                break;
            default:
                printf("Incorrect command\n");
                printf("Would you like to continue? (1=NO 0=YES)\n");
                scanf("%d", &exitloop);
        }

    } while (exitloop != 0);

    return 0;
}