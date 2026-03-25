#include <graphics.h>
#include <conio.h>

typedef struct{
  float x,y,z;
} Point3D;


void project3D(Point3D p, int* x2d, int* y2d){
  *x2d = (int)(p.x + p.z * 0.5); 
  *y2d = (int)(p.y - p.z * 0.5); 
}

void drawCube(Point3D cube[8]){
    int x[8], y[8];

    // Project all 8 points
    for(int i = 0; i < 8; i++){
        project3D(cube[i], &x[i], &y[i]);
  }

    // Cube edges (fixed)
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    // Draw edges
    for(int i = 0; i < 12; i++){
        line(x[edges[i][0]], y[edges[i][0]],
             x[edges[i][1]], y[edges[i][1]]);
  }
}

void shearZ(float sh, Point3D cube[8]){

  Point3D shear_cube[8];

  for(int i=0; i<8; i++){
    shear_cube[i].x = cube[i].x + sh * cube[i].z;
    shear_cube[i].y = cube[i].y + sh * cube[i].z;
    shear_cube[i].z = cube[i].z;
  }

  drawCube(shear_cube);
}

void shearX(float sh, Point3D cube[8]){

  Point3D shear_cube[8];

  for(int i=0; i<8; i++){
    shear_cube[i].z = cube[i].z + sh * cube[i].x;
    shear_cube[i].y = cube[i].y + sh * cube[i].x;
    shear_cube[i].x = cube[i].x;
  }

  drawCube(shear_cube);
}

void shearY(float sh, Point3D cube[8]){

  Point3D shear_cube[8];

  for(int i=0; i<8; i++){
    shear_cube[i].z = cube[i].z + sh * cube[i].y;
    shear_cube[i].x = cube[i].x + sh * cube[i].y;
    shear_cube[i].y = cube[i].y;
  }

  drawCube(shear_cube);
}

int main(){

  int wnd=initwindow(700,700,"3D Shearing");

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

  shearZ(0.5,cube);
  // shearX(0.5,cube);
  // shearY(0.5,cube);

  getch();
  closegraph(wnd);
  return 0;
}
