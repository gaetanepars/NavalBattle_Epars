#include <stdio.h>
int realgrid [10][10];
char printgrid [10][10];
int Play(){

}
int Mapgen() {
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 10; ++column) {
            realgrid[row][column] = 0;
        }
    }
    realgrid[0][0] = 4; //ship1             ship = 4 hit = 1 missed = 2 sunk = 3
    realgrid[0][1] = 4; //ship2             i need to make a function play that transform a 4 into 1 2 or 3
    realgrid[0][2] = 4; //ship3             depending on the situation
    realgrid[0][3] = 4; //ship4
    realgrid[0][4] = 4; //ship5

    char Aj = 65;
    printf("\n    1   2   3   4   5   6   7   8   9   10\n");
    for (int row = 0; row < 10; ++row) {
        printf("%c", Aj);
        Aj++;
        for (int column = 0; column < 10; ++column) {
            if (realgrid[row][column]==0 || realgrid[row][column]==4){
                printgrid[row][column]='~';
            }
            else if(realgrid[row][column]==1){
                printgrid[row][column]='*';
            }
            else if(realgrid[row][column]==2){
                printgrid[row][column]='-';
            }
            else if(realgrid[row][column]==3){
                printgrid[row][column]='X';
            }
            printf(" %3c", printgrid[row][column]);
        }
        printf("\n");
    }
}


int Help(){                                //show tips

    printf("\nhelp1\n");
    printf("help2\n");
    printf("help3\n");
    printf("help4\n");
    printf("help5\n");
    printf("Menu=>0 Exit=>1\n");
}

int main() {                                //menu

    int usermenuchoice;
    int exitloop;

    do {
        printf("Battleship\n\n");

        printf("1.Play\n");
        printf("2.Help\n");
        printf("3.Exit\n");

        scanf("%d", &usermenuchoice);

        switch (usermenuchoice) {
            case 1:
                Mapgen();
                //Play();
                break;
            case 2:
                Help();
                scanf("%d", &exitloop);
                break;
            case 3:
                printf("Are you sure you want to exit? (0=NO 1=YES)\n");
                scanf("%d", &exitloop);
                break;
            default:
                printf("Incorrect command\n");
                printf("Would you like to continue? (0=NO 1=YES)\n");
                scanf("%d", &exitloop);
        }

    } while (exitloop != 1);                    //Allow the user to go back to the menu

    return 0;
}