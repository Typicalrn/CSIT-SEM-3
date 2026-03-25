//TRANSLATION
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int tx=200;
int ty=110;


//for th rec func
int x1=100;
int y1=100;

int x2=200;
int y2=200;

//for matrix
int x3 = 200;
int y3 = 100;

int x4 = 100;
int y4 = 200;

int result[3][4];

int originalMatrix[3][4] = {
  {x1,x2,x3,x4},
  {y1,y2,y3,y4},
  {1,1,1,1}
};

int translationMatrix[3][3] = {
  {1,0,tx},
  {0,1,ty},
  {0,0,1}
};


void matrixmultiplication(int m1[3][3], int m2[3][4]){

   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j],i,j);
        }

        printf("\n");
    }
}

void translation2D(){
  
  matrixmultiplication(translationMatrix, originalMatrix);
  printf("\n%d, %d\n%d, %d",result[0][0], result[1][0], result[0][1], result[1][1]);
  rectangle(result[0][0], result[1][0], result[0][1], result[1][1]);

}

int main(){

  int wnd=initwindow(700,700,"Lab 5");

  rectangle(x1,y1,x2,y2);

  translation2D();

  getch();
  closegraph(wnd);
  return 0;
}
