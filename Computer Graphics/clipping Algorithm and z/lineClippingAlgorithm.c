//Cohen Sutherland method
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int region_code[2][4] = {{0,0,0,0},{0,0,0,0}};
int fin_code[4] = {0,0,0,0};

//coords for clipping window
int xwmin = 200;
int ywmin = 500;

int xwmax = 500;
int ywmax = 200;

//coords for a line
int a1 = 400;
int b1 = 100;

int a2 = 80;
int b2 = 450;

float slope =(float) (b2-b1)/(float) (a2-a1); 

int set_region_code(int a, int b, int c, int d){

  int flag = 0;

  region_code[0][3] = (a < xwmin)? 1 : 0;
  region_code[0][2] = (a > xwmax)? 1 : 0;
  region_code[0][1] = (b > ywmin)? 1 : 0;
  region_code[0][0] = (b < ywmax)? 1 : 0;

  region_code[1][3] = (c < xwmin)? 1 : 0;
  region_code[1][2] = (c > xwmax)? 1 : 0;
  region_code[1][1] = (d > ywmin)? 1 : 0;
  region_code[1][0] = (d < ywmax)? 1 : 0;

  for(int i=0; i<2; i++){
    for(int j=0; j<4; j++){
      if(region_code[i][j] == 1){
        flag = 1;
      }
    }
  }

  if(!flag){
    printf("Line is completely inside.\n");
    return -1;
  }

  for(int i=0; i<4; i++){

    fin_code[i] = region_code[0][i] * region_code[1][i];

    if(fin_code[i] == 1){
      printf("Line is completely outside.\n");
      return -1;
    }
  }

  return 0;
}

void clip_line(){

  int x[2], y[2];
  int x1 = a1, y1 = b1;

  for(int i=0; i<2; i++){
    if(region_code[i][0]){
      x[i] = xwmin;
      y[i] = y1 + slope*(x[i]-x1);
    }else if(region_code[i][1]){
      x[i] = xwmax;
      y[i] = y1 + slope*(x[i]-x1);
    }else if(region_code[i][2]){
      y[i] = ywmin;
      x[i] = x1 + (1/slope)*(y[i] - y1);
    }else{
      y[i] = ywmax;
      x[i] = x1 + (1/slope)*(y[i] - y1);
    }

    x1 = a2;
    y1 = b2;
  }

  line(x[0],y[0],x[1],y[1]);
}

int main(){

  int wnd=initwindow(700,700,"Line Clipping");

  rectangle(xwmin, ywmin, xwmax, ywmax);
  // line(a1,b1,a2,b2);

  if(set_region_code(a1,b1,a2,b2) == -1){
    closegraph();
    return 0;
  }

  clip_line();

  getch();
  closegraph(wnd);

  return 0;
}
