    #include <graphics.h>
    #include <conio.h> // For getch()

    int main() {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, ""); // Initialize graphics
        circle(100, 100, 50);    // Draw a circle
        getch();                 // Wait for a key press
        closegraph();            // Close graphics
        return 0;
    }