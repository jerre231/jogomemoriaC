#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int matriz[4][4] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
int pos[4][4];

void shuffleMatrix(int matrix[][3], int rows, int cols) {
    srand(time(NULL));

    for (int i = rows - 1; i > 0; i--) {
        for (int j = cols - 1; j > 0; j--) {
            int randomRow = rand() % (i + 1);
            int randomCol = rand() % (j + 1);

            int temp = matrix[i][j];
            matrix[i][j] = matrix[randomRow][randomCol];
            matrix[randomRow][randomCol] = temp;
        }
    }
}

void printTable(){

    printf(" | 1 | 2 | 3 | 4 |\n");
    printf("-------------------\n");
    printf("1| %i | %i | %i | %i |\n", pos[0][0], pos[0][1], pos[0][2], pos[0][3]);
    printf("-------------------\n");
    printf("2| %i | %i | %i | %i |\n", pos[1][0], pos[1][1], pos[1][2], pos[1][3]);
    printf("-------------------\n");
    printf("3| %i | %i | %i | %i |\n", pos[2][0], pos[2][1], pos[2][2], pos[2][3]);
    printf("-------------------\n");
    printf("4| %i | %i | %i | %i |\n", pos[3][0], pos[3][1], pos[3][2], pos[3][3]);
    printf("-------------------\n");

}

int main(){

    int i, j, m, a, b, n, ped1, ped2;
    int pares = 0;

    shuffleMatrix(matriz, 4, 4);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            pos[i][j] = 0;
        }
    }

    system("cls");

    while(pares<8){
        printTable();

        printf("\nescolha a coordenada do primeiro:\n(x y)\n");
        scanf(" %i %i", &m, &n);

        m--;
        n--;

        pos[m][n] = matriz[m][n];
        ped1 = matriz[m][n];
        system("cls");
        printTable();

        printf("\nescolha a coordenada do segundo:\n(x y)\n");
        scanf(" %i %i", &a, &b);

        a--;
        b--;

        pos[a][b] = matriz[a][b];
        ped2 = matriz[a][b];
        
        system("cls");

        if(ped1 != ped2){
            printTable();
            sleep(2);
            system("cls");
            pos[m][n] = 0;
            pos[a][b] = 0;
            
        }
        else{
            pares++;
        }
    }

    printf("\nParabens, voce venceu!!\n");
    sleep(10);

return 0;
}