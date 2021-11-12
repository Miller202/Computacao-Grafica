#include <GL/glut.h>

// Generate square
void displaySquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 4.0, 0.0);
    glVertex3f(6.0, 4.0, 0.0);
    glVertex3f(6.0, 8.0, 0.0);
    glVertex3f(2.0, 8.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("square");

    glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(0.0, 8.0, 0.0, 12.0, -1.0, 1.0); // square position

    glutDisplayFunc(displaySquare);
    glutMainLoop();

    return 0;
}