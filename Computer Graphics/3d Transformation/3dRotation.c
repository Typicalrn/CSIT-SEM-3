#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159

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

void rotation_about_Z(float deg, Point3D cube[8]){
  float rad = (float) deg * (PI/180); 
  Point3D rot_cube[8];

  for(int i=0; i<8; i++){
    rot_cube[i].x = cube[i].x * cos(rad) - cube[i].y * sin(rad);
    rot_cube[i].y = cube[i].x * sin(rad) + cube[i].y * cos(rad);
    rot_cube[i].z = cube[i].z;
  }

  drawCube(rot_cube);
}

void rotation_about_X(float deg, Point3D cube[8]){
  float rad = (float) deg * (PI/180); 
  Point3D rot_cube[8];

  for(int i=0; i<8; i++){
    rot_cube[i].z = cube[i].y * sin(rad) + cube[i].z * cos(rad);
    rot_cube[i].y = cube[i].y * cos(rad) - cube[i].z * sin(rad);
    rot_cube[i].x = cube[i].x;
  }

  drawCube(rot_cube);
}

void rotation_about_Y(float deg, Point3D cube[8]){
  float rad = (float) deg * (PI/180); 
  Point3D rot_cube[8];

  for(int i=0; i<8; i++){
    rot_cube[i].x = cube[i].z * sin(rad) + cube[i].x * cos(rad);
    rot_cube[i].z = cube[i].z * cos(rad) - cube[i].x * sin(rad);
    rot_cube[i].y = cube[i].y;
  }

  drawCube(rot_cube);
}

int main(){

  int wnd=initwindow(700,700,"3D Rotation");

  int x2d, y2d;

  Point3D cube[8] = {
    {200, 200, 10},
    {300, 200, 10},
    {300, 300, 10},
    {200, 300, 10},
    {200, 200, 200},
    {300, 200, 200},
    {300, 300, 200},
    {200, 300, 200}
  };

  drawCube(cube);

  //rotation_about_Z(30,cube);
   //rotation_about_X(30,cube);
  rotation_about_Y(30,cube);

  getch();
  closegraph(wnd);
  return 0;
}
