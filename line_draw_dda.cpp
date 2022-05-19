/**
 * @file line_draw_dda.cpp
 * @author Tejas Dattatray Mote (https://github.com/motetejas2002)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <GLUT/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>

void Init(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);   // This is for setting-up background color white
    glMatrixMode(GL_PROJECTION);            // This is projection parameters
    gluOrtho2D(-400.0f, 400.0f, -400.0f, 400.0f);
}

inline int round_of(const float a) {
    return int(a + 0.5);
}

void lineDDA(int x0, int y0, int xEnd, int yEnd) {
    int dx = xEnd - x0;
    int dy = yEnd - y0;
    int steps, k;

    float xIncrement, yIncrement;
    float x = x0;
    float y = y0;

    if(fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    }
    else {
        steps = fabs(dy);
    }

    xIncrement = float (dx) / float (steps);
    yIncrement = float (dy) / float (steps);

    glBegin(GL_POINTS);
        glVertex2i(round_of(x), round_of(y));
    glEnd();

    for(k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;

        glBegin(GL_POINTS);
            glVertex2i(round_of(x), round_of(y));
        glEnd();
    }

    glFlush();
}


void Draw(void) {
    int x0, y0, xEnd, yEnd;
    std::cout << "Enter x0, y0: ";
    std::cin >> x0 >> y0;

    std::cout << "Enter xEnd, yEnd: ";
    std::cin >> xEnd >> yEnd;

    lineDDA(x0, y0, xEnd, yEnd);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set Display Mode
    glutInitWindowPosition(50, 100);                // Initial window position
    glutInitWindowSize(800, 800);                   // Initial window size
    glutCreateWindow("A GLUT window canves for CG");// Title for window

    Init();                                         // Execute initialization procedure.
    glutDisplayFunc(Draw);
    glutMainLoop();
}
