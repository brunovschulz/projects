#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

int matriz[9][9];

int isCompleted();
void printGrid();
bool isValid(int x, int y, int k);
bool solve(int x, int y);

int main(){

    FILE *arq;
    int num, x = 0 , y = 0;

    arq = fopen("C:\\bruno_vscode\\c\\projetos\\sudoku_solver\\sudoku.txt", "r");

    if(!arq){printf("Erro no arquivo.\n"); return -1;}

    for(int i=0; i<81; i++){
        fscanf(arq, "%d", &num);
        matriz[i/9][i%9] = num;
    }

    printGrid();

    if(solve(0,0)==false) printf("Não funcionou.\n");
    
    else printf("Funcionou!\n");

    printGrid();

    //while(!isCompleted(matriz)){}

    return 0;
}

bool isValid(int x, int y, int k){

    //checking row and column
    for(int i=0; i<9; i++){
        if(matriz[x][i]==k) return false;
        if(matriz[i][y]==k) return false;
    }

    //checking box
    int xa = x/3;
    int ya = y/3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[(3*xa)+i][(3*ya)+j] == k) return false;
        }
    }

    return true;
}

bool solve(int x, int y){

    if(y==9) return true;

    else if(x==9) return solve(0, y+1);

    if(matriz[x][y]!=0) return solve(x+1, y);

    else{ //matriz[x][y] equals to zero

        for(int k=1; k<=9; k++){

            if(isValid(x,y,k)){
                matriz[x][y] = k;
                
                if(solve(x+1, y)) return true;
                matriz[x][y] = 0; //else
            } 

        }

        return false;

    }

}

void printGrid(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){

            printf("%d ", matriz[i-1][j-1]);

        }
        printf("\n");
    }
    printf("\n");
}