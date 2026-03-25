#include <stdio.h>
#include <graphics.h>

typedef struct{
  float x,y,z;
} Point3D;


void project3D(Point3D p, int* x2d, int* y2d){
  *x2d = (int)(p.x + p.z * 0.5); 
  *y2d = (int)(p.y - p.z * 0.5); 
}

void drawCube(Point3D cube[8]){
    int x[8], y[8];

    for(int i = 0; i < 8; i++){
        project3D(cube[i], &x[i], &y[i]);
  }

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i = 0; i < 12; i++){
        line(x[edges[i][0]], y[edges[i][0]],
             x[edges[i][1]], y[edges[i][1]]);
  }
}


void translation3D(Point3D cube[8]){

  int tx = 180, ty = 180, tz = 180;

  for(int i=0; i<8; i++){
    cube[i].x = (int)(cube[i].x + tx);
    cube[i].y = (int)(cube[i].y + ty);
    cube[i].z = (int)(cube[i].z + tz);
  }

}

int main(){

  int wnd=initwindow(700,700,"3D Translation");

  int x2d, y2d;

  Point3D cube[8] = {
    {100, 100, 0},
    {200, 100, 0},
    {200, 200, 0},
    {100, 200, 0},
    {100, 100, 100},
    {200, 100, 100},
    {200, 200, 100},
    {100, 200, 100}
  };

  drawCube(cube);

  translation3D(cube);
  drawCube(cube);

  getch();
  closegraph(wnd);
  return 0;
}
