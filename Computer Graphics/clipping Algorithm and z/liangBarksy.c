// wap to generate the line clipping using liang-barsky algorithm
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int xwmin = 200;
int ywmin = 200;
int xwmax = 500;
int ywmax = 500;

int a1 = 400;
int b1 = 100;
int a2 = 80;
int b2 = 450;

void liang_barsky(){
  float p[4], q[4];
  float u1 = 0.0f, u2 = 1.0f;

  p[0] = -(a2 - a1);
  p[1] = (a2 - a1);
  p[2] = -(b2 - b1);
  p[3] = (b2 - b1);

  q[0] = a1 - xwmin;
  q[1] = xwmax - a1;
  q[2] = b1 - ywmin;
  q[3] = ywmax - b1;

  for(int i = 0; i < 4; i++){
    if(p[i] == 0.0f){
      if(q[i] < 0.0f){
        printf("Line is parallel and outside the clipping window.\n");
        return;
      }
    }
    else{
      float u = q[i] / p[i];
      if(p[i] < 0.0f){
        if(u > u1) u1 = u;
      }
      else{
        if(u < u2) u2 = u;
      }
    }
  }

  if(u1 > u2){
    printf("Line is outside the clipping window.\n");
    setcolor(RED);
    line(a1, b1, a2, b2);
    setcolor(WHITE);
    return;
  }

  float xf1 = a1 + u1 * (a2 - a1);
  float yf1 = b1 + u1 * (b2 - b1);
  float xf2 = a1 + u2 * (a2 - a1);
  float yf2 = b1 + u2 * (b2 - b1);

  int x1_clip = (int)(xf1 + 0.5f);
  int y1_clip = (int)(yf1 + 0.5f);
  int x2_clip = (int)(xf2 + 0.5f);
  int y2_clip = (int)(yf2 + 0.5f);

  printf("Clipped line coordinates: (%d, %d) to (%d, %d)\n", x1_clip, y1_clip, x2_clip, y2_clip);

  // draw the inside segment in green
  setcolor(GREEN);
  line(x1_clip, y1_clip, x2_clip, y2_clip);

  // draw the outside parts in red
  setcolor(RED);
  if(u1 > 0.0f){
    line(a1, b1, x1_clip, y1_clip);
  }
  if(u2 < 1.0f){
    line(x2_clip, y2_clip, a2, b2);
  }
  setcolor(WHITE);
}

int main(){
  initwindow(700, 700, "Line Clipping (Liang-Barsky Algorithm)");

  rectangle(xwmin, ywmin, xwmax, ywmax);
  line(a1, b1, a2, b2);

  liang_barsky();

  getch();
  closegraph();
  return 0;
}
