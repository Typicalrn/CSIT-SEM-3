#include <graphics.h>
#include <conio.h>

//line 1
int a1=500;
int b1=400;

// line 2
int c1 = 200;
int d1 = 300;

// line3
int e1 = 400;
int f1 = 300;

float na1, nb1, nc1, nd1, ne1, nf1;

void DrawTriangle(int a, int b, int c, int d, int e, int f){
  line(a,b,c,d);
  line(a,b,e,f);
  line(c,d,e,f);
}

void CalculatePoints(float m, float c){

  //line 1
  na1  = (int) a1 - (2*m*(m*a1-b1+c))/(m*m+1);
  nb1  = (int) b1 - (2*(m*a1-b1+c))/(m*m+1);

  //line 2
  nc1  = (int) c1 - (2*m*(m*c1-d1+c))/(m*m+1);
  nd1  = (int) d1 - (2*(m*c1-d1+c))/(m*m+1);

  //line 2
  ne1  = (int) e1 - (2*m*(m*e1-f1+c))/(m*m+1);
  nf1  = (int) f1 - (2*(m*e1-f1+c))/(m*m+1);

  printf("%d %d\n",a1,b1);
  printf("%d %d\n",c1,d1);
  printf("%d %d\n",e1,f1);

  DrawTriangle(na1, nb1, nc1, nd1, ne1, nf1);
}

int main(){

  int wnd=initwindow(700,700,"2D reflection");

  DrawTriangle(a1,b1,c1,d1,e1,f1);
  CalculatePoints(1,0);

  getch();
  closegraph(wnd);

  return 0;
}
