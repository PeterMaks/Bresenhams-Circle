#include <GL/glut.h>
#include <cmath>

void drawCircle(int centerX, int centerY, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    // Function to plot points in all octants
    auto plotPoints = [&](int x, int y) {
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY - x);
        };

    // Draw initial points
    plotPoints(x, y);

    // Loop until x > y
    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        }
        else {
            y--;
            p += 2 * x - 2 * y + 1;
        }
        plotPoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    drawCircle(0, 5, 3);  // Center at (0,5) with radius 3
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Circle ");
    gluOrtho2D(-10, 10, -10, 10); // Adjust the coordinate system
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}