#include <GL/glut.h>

// COMANDOS DO TECLADO:
// Subir quadrados da Ola: "a s d f g"
// Descer quadrados da Ola: "z x c v b"

static GLfloat v[10]={ // array do eixo y
        0,  2,
        0,  2,
        0,  2,
        0,  2,
        0,  2
};

// Renderizar quadrado
void displaySquare()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.5);
    glVertex2f(3, v[0]); // coordenadas
    glVertex2f(2, v[0]);
    glVertex2f(2,v[1]);
    glVertex2f(3, v[1]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.5, 0.0);
    glVertex2f(1, v[2]); // coordenadas
    glVertex2f(0, v[2]);
    glVertex2f(0,v[3]);
    glVertex2f(1, v[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.35);
    glVertex2f(-1, v[4]); // coordenadas
    glVertex2f(-2, v[4]);
    glVertex2f(-2,v[5]);
    glVertex2f(-1, v[5]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.3, 0.4);
    glVertex2f(-3, v[6]); // coordenadas
    glVertex2f(-4, v[6]);
    glVertex2f(-4,v[7]);
    glVertex2f(-3, v[7]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.3, 0.1);
    glVertex2f(-5, v[8]); // coordenadas
    glVertex2f(-6, v[8]);
    glVertex2f(-6,v[9]);
    glVertex2f(-5, v[9]);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'a':
            v[0] += 2;
            v[1] += 2;
            displaySquare();
            break;
        case 's':
            v[2] += 2;
            v[3] += 2;
            displaySquare();
            break;
        case 'd':
            v[4] += 2;
            v[5] += 2;
            displaySquare();
            break;
        case 'f':
            v[6] += 2;
            v[7] += 2;
            displaySquare();
            break;
        case 'g':
            v[8] += 2;
            v[9] += 2;
            displaySquare();
            break;
        case 'z':
            v[0] -= 2;
            v[1] -= 2;
            displaySquare();
            break;
        case 'x':
            v[2] -= 2;
            v[3] -= 2;
            displaySquare();
            break;
        case 'c':
            v[4] -= 2;
            v[5] -= 2;
            displaySquare();
            break;
        case 'v':
            v[6] -= 2;
            v[7] -= 2;
            displaySquare();
            break;
        case 'b':
            v[8] -= 2;
            v[9] -= 2;
            displaySquare();
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("square");

    glClearColor(0.0, 0.05, 0.10, 1.0); // cor de fundo
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0); // projeção ortogonal

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(displaySquare);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}