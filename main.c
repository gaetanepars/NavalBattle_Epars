#include <stdio.h>

char printgrid [10][10];
int  realgrid [10][10];

char usercoordinateX;
char usercoordinateY;

int coordinateX;
int coordinateY;

int row;
int column;

int shipcount=0;

int Fmapgen(){            //print a map and generate another grid for the position of the ships

    realgrid[0][0] = 2; //ship1
    realgrid[3][1] = 2; //ship2
    realgrid[7][2] = 2; //ship3
    realgrid[8][8] = 2; //ship4
    realgrid[7][9] = 2; //ship5

    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
            realgrid[row][column]= 0;
        }
    }

    char Aj = 65;
    printf("\n    1   2   3   4   5   6   7   8   9   10\n");
    for (row = 0; row < 10; ++row) {
        printf("%c", Aj);
        Aj++;
        for (column = 0; column < 10 ; ++column) {
            printgrid[row][column]='~';
            printf(" %3c", printgrid[row][column]);
        }
        printf("\n");
    }
}

int Fplay(){                     //function that asks for coordinates and then check if there is a boat

    do {
        printf("\nChoose a coordinate: ");

        scanf(" %c", &usercoordinateX);
        scanf(" %c", &usercoordinateY);

        coordinateX=usercoordinateX-65;        //translates the user coordinates into real coordinates
        coordinateY=usercoordinateY-1;

        if (realgrid[coordinateX][coordinateY] == 2){      //if there's a boat replace the wave with an X
            printgrid[coordinateX][coordinateY]='X';
            Fmapgen();
            printf("\nYou've sunk a ship!\n");
            shipcount++;

        } else if (realgrid[coordinateX][coordinateY] == 1){  //if there is no boat replaces the water with a "*"
            printgrid[coordinateX][coordinateY]='^';
            Fmapgen();
            printf("\nYou've hit a ship'!\n");

        }else {
            printgrid[coordinateX][coordinateY] = '*';
            Fmapgen();
            printf("\nYou missed!\n");
        }
    }while (shipcount!=5);                              //repeat the function until there are no ships left


}

int Fhelp(){                                //show tips

    printf("\nhelp1\n");
    printf("help2\n");
    printf("help3\n");
    printf("help4\n");
    printf("help5\n");
    printf("Menu=>1 Exit=>0\n");
}



int main() {                                //menu

    int usermenuchoice;
    int endwhile;

    do {
        printf("Battleship\n\n");

        printf("1.Play\n");
        printf("2.Help\n");
        printf("3.Exit\n");

        scanf("%d", &usermenuchoice);

        switch (usermenuchoice) {
            case 1:
                Fmapgen();
                Fplay();
                break;
            case 2:
                Fhelp();
                scanf("%d", &endwhile);
                break;
            case 3:
                printf("Are you sure you want to exit? (0=NO 1=YES)\n");
                scanf("%d", &endwhile);
                break;
            default:
                printf("Incorrect command\n");
                printf("Would you like to continue? (0=NO 1=YES)\n");
                scanf("%d", &endwhile);
        }

    } while (endwhile == 1);                    //Allow the user to go back to the menu

    return 0;
}