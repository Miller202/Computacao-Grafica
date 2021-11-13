#include <GL/glut.h>

// Renderizar quadrado
void displaySquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-2.5, -2.5);
    glVertex2f(2.5, -2.5);
    glVertex2f(2.5, 2.5);
    glVertex2f(-2.5, 2.5);
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

    glClearColor(0.0, 0.05, 0.10, 1.0); // cor de fundo

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);

    glutDisplayFunc(displaySquare);
    glutMainLoop();

    return 0;
}