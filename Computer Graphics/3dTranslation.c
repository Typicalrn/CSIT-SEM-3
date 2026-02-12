#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, k;
    float point[4], translated_point[4];
    float tx, ty, tz;
    float translation_matrix[4][4] = {  
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    
    // Get translation values
    printf("Enter translation values:\n");
    printf("Enter tx (translation in X-axis): ");
    scanf("%f", &tx);
    printf("Enter ty (translation in Y-axis): ");
    scanf("%f", &ty);
    printf("Enter tz (translation in Z-axis): ");
    scanf("%f", &tz);
    
    // Set up translation matrix
    // 3D Translation matrix in homogeneous coordinates
    translation_matrix[0][3] = tx;
    translation_matrix[1][3] = ty;
    translation_matrix[2][3] = tz;
    
    // Get point coordinates
    printf("\nEnter 3D point coordinates:\n");
    printf("Enter x coordinate: ");
    scanf("%f", &point[0]);
    printf("Enter y coordinate: ");
    scanf("%f", &point[1]);
    printf("Enter z coordinate: ");
    scanf("%f", &point[2]);
    point[3] = 1.0;  // Homogeneous coordinate
    
    // Apply translation: multiply translation matrix with point
    // translated_point = translation_matrix * point
    for(i = 0; i < 4; i++) {
        translated_point[i] = 0;
        for(j = 0; j < 4; j++) {
            translated_point[i] += translation_matrix[i][j] * point[j];
        }
    }
    
    // Display results
    printf("\nOriginal Point: (%.2f, %.2f, %.2f)\n", point[0], point[1], point[2]);
    printf("Translated Point: (%.2f, %.2f, %.2f)\n", 
           translated_point[0], translated_point[1], translated_point[2]);
    
    return 0;
}

    