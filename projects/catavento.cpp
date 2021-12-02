#include <GL/glut.h>
#include <cmath>

// ALUNO: Michael Miller Rodrigues Cardoso
// COMANDOS DO TECLADO:
// Girar (esquerda e direita) - "x, c"
// Mudar velocidade (aumentar e diminuir) - "v, b"

float pi = 3.14;
float speed_angle = pi/4;
float sen_60 = 0.86;

typedef struct Vertex {
    GLfloat x, y;
} Vertex;

// Conjuntos para armazenar os vértices x, y das figuras

Vertex stick[] = {
        {-1.5, 0.0},
        {1.5, 0.0},
        {-1.5, -50.0},
        {1.5, -50.0}
};

Vertex flower[] = {
        {12.5, 25 * sen_60},
        {-12.5, 25 * sen_60},
        {25.0, 0.0},
        {12.5, 25 * (-sen_60)},
        {-25.0, 0.0},
        {-12.5, 25 * (-sen_60)}
};


// Girar flor (catavento)
void spinFlower(float angle)
{
    Vertex aux;

    for (int i = 0; i < 6; i += 2) {
        for (int j = i; j <= i+1; j++) {
            aux = flower[j];
            flower[j].x = (aux.x * std::cos(angle)) - (aux.y * std::sin(angle));
            flower[j].y = (aux.y * std::cos(angle)) + (aux.x * std::sin(angle));
        }
    }

    glutPostRedisplay();
}

// Renderizar flor de abril
void displayFlower()
{
    for (int i = 0; i < 6; i += 2) {
        glBegin(GL_TRIANGLES);

        glColor3f(0.0, 1.0, 0.5); // cor da flor de abril
        glVertex2f(0.0,0.0);

        for (int j = i; j <= i+1; j++) {
            GLfloat x = flower[j].x;
            GLfloat y = flower[j].y;
            glVertex2f(x,y);
        }

        glEnd();
    }
}

// Renderizar graveto da flor
void displayStick()
{
    for (int i=0; i<2; i++) {
        glBegin(GL_TRIANGLES);

        glColor3f(1.0, 0.5, 0.0); //cor do graveto

        for (int j = i; j <= i+2; j++) {
            GLfloat x = stick[j].x;
            GLfloat y = stick[j].y;
            glVertex2i(x, y);
        }

        glEnd();
    }
}

// Comandos do teclado
void keyboard(unsigned char key, int x, int y)
{
    float change;

    switch(key) {
        case 'x':
            spinFlower(speed_angle);
            break;
        case 'c':
            spinFlower(-speed_angle);
            break;
        case 'v':
            change = speed_angle + (1.0f * pi/16);
            speed_angle = change;
            break;
        case 'b':
            change = speed_angle - (1.0f * pi/16);
            speed_angle = change;
            break;
        default:
            break;
    }
}

// Renderizar figuras
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    displayStick();
    displayFlower();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(640, 480);
    glutCreateWindow("Flor de abril - Catavento");

    glClearColor(0.0, 0.05, 0.10, 1.0); // cor do background
    glOrtho(-100.0, 100.0, -100.0, 100.0, 1.0, -1.0); // projeção ortogonal
    glutReshapeWindow(640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
