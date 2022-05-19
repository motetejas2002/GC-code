/**
 * @file draw_colourful_triangle.cpp
 * @author Tejas Dattatray Mote (https://github.com/motetejas2002)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * @copyright Copyright (c) 2022
 */

#include <GLUT/glut.h>

void Init(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);   // This is for setting-up background color white
    glMatrixMode(GL_PROJECTION);            // This is projection parameters
    gluOrtho2D(-400.0f, 400.0f, -400.0f, 400.0f);
}

void Draw_colourful_triangle(void) {
    glClear(GL_COLOR_BUFFER_BIT);           // Clearing canvus with color white

    glColor3f(0.0f, 0.7f, 0.3f);            // Setting colour of triangle
    glBegin(GL_TRIANGLES);                  // Starting point of triangle
        glVertex2i(-200, -200);
        glVertex2i(200, -200);
        glVertex2i(0, 150);
    glEnd();                                // Ending point of triangle

    glFlush();          // Process all OpenGL routines as quickly as possible.
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set Display Mode
    glutInitWindowPosition(50, 100);                // Initial window position
    glutInitWindowSize(800, 800);                   // Initial window size
    glutCreateWindow("A GLUT window canves for CG");// Title for window

    Init();                                         // Execute initialization procedure.
    glutDisplayFunc(Draw_colourful_triangle);
    glutMainLoop();
}