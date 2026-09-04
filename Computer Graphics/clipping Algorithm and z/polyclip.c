//polygon clipping using Sutherland-Hodgman algorithm
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int xwmin = 200;
int ywmin = 200;
int xwmax = 500;
int ywmax = 500;

void sutherland_hodgman_clip(int x[], int y[], int n){
      
}

int main(){
  int n, x[20], y[20];
  printf("Enter the number of vertices of the polygon: ");
  scanf("%d", &n);
  printf("Enter the coordinates of the vertices:\n");
  for(int i=0; i<n; i++){
    scanf("%d %d", &x[i], &y[i]);
  }

  // Draw the clipping window
  rectangle(xwmin, ywmin, xwmax, ywmax);

  // Draw the original polygon
  for(int i=0; i<n; i++){
    line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
  }

  // Perform Sutherland-Hodgman polygon clipping
    sutherland_hodgman_clip(x, y, n);

  getch();
  return 0;
}
