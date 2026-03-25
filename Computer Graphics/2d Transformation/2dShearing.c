#include <graphics.h>
#include <conio.h>

//line 1
int a1=300;
int b1=100;

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

void Xshear(float shx){
  float ad = a1 + shx * b1; 
  float cd = c1 + shx * d1;
  float ed = e1 + shx * f1;

  DrawTriangle(ad,b1,cd,d1,ed,f1);
}

void Yshear(float shy){
  float bd = a1 * shy + b1; 
  float dd = c1 * shy + d1;
  float fd = e1 * shy + f1;

  DrawTriangle(a1,bd,c1,dd,e1,fd);
}

void YshearWithRef(float shy, float xref){
  float bd = (a1 - xref) * shy + b1; 
  float dd = (c1 - xref) * shy + d1;
  float fd = (e1 - xref) * shy + f1;

  DrawTriangle(a1,bd,c1,dd,e1,fd);
}

void XshearWithRef(float shx, float yref){
  float ad = a1 + shx * (b1 - yref); 
  float cd = c1 + shx * (d1 - yref);
  float ed = e1 + shx * (f1 - yref);

  DrawTriangle(ad,b1,cd,d1,ed,f1);
}

int main(){

  int wnd=initwindow(1000,1000,"2D Shearing");

  DrawTriangle(a1,b1,c1,d1,e1,f1);

  Xshear(1);
  Yshear(1);
  YshearWithRef(0.5,300);
  XshearWithRef(0.5,200);

  getch();
  closegraph(wnd);
  return 0;
}
