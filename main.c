#include <stdio.h>

char grid [10][10];
int coordinateX;
int coordinateY;
int row;
int column;
int shipcount=0;

int Fplay(){
    char usercoordinateX;
    char usercoordinateY;

    grid[0][0] = 'X'; //ship1
    grid[3][1] = 'X'; //ship2
    grid[7][2] = 'X'; //ship3
    grid[8][8] = 'X'; //ship4
    grid[7][9] = 'X'; //ship5

    do {
        printf("\nChoose a coordinate: ");

        scanf("%c", &usercoordinateX);
        scanf("%c", &usercoordinateY);

        coordinateX=usercoordinateX-65;
        coordinateY=usercoordinateY-1;

        if (grid[coordinateX][coordinateY] == 'X'){
            printf("%3c", grid[row][column]);
            printf("You have sunk a ship!");
            shipcount++;
        } else if (grid[coordinateX][coordinateY] == '~'){
            printf("%3c", grid[row][column]);
            printf("\nYou missed!\n");
        }
    }while (shipcount!=5);


}

int Fhelp(){
    printf("\nhelp1\n");
    printf("help2\n");
    printf("help3\n");
    printf("help4\n");
    printf("help5\n");
    printf("Menu=>1 Exit=>0\n");
}

int Fmapgen(){
    char Aj = 65;
    printf("   1  2  3  4  5  6  7  8  9  10\n");
    for (row = 0; row < 10; ++row) {
        printf("%c", Aj);
        Aj++;
        for (column = 0; column < 10 ; ++column) {
            grid[row][column] = '~';
            printf("%3c", grid[row][column]);

        }
        printf("\n");
    }
}

int main() {

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

    } while (endwhile == 1);

    return 0;
}