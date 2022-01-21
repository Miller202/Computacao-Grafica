#include <GL/freeglut.h>

// ALUNO: Michael Miller Rodrigues Cardoso
// COMANDOS DO TECLADO:
// Ativar translação (rotação dos planetas) - "y"

int year = 0, day = 0;

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define LARANJA  0.8, 0.5, 0.1
#define ROSE    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define MARROM    0.8, 0.4, 0.3


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double) w / h, 1, 20);
    glMatrixMode(GL_MODELVIEW);

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // camera pos
}

void scheduleUpdate(int value)
{
    glutTimerFunc(10, scheduleUpdate, 1);
    day++;
    year++;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'y':
            glutTimerFunc(10, scheduleUpdate, 1);
            break;
        case 27:
            exit(0);
        default:
            break;
    }
}

void displayPlanetWithMoon()
{
    // Planet
    glPushMatrix();
    glColor3f(AZUL);
    glRotatef(year, 0, 1, 0);
    glTranslatef(2, 0, 0);
    glRotatef(day, 0, 1, 0);
    glutSolidSphere(0.2, 100, 100); // Generate planet
    glPopMatrix();

    // Moon 1
    glPushMatrix();
    glColor3f(CINZA);
    glRotatef(1.5*day, 0, 1, 0);
    glTranslatef(0.45, 0.1, 0);
    glutSolidSphere(0.05, 100, 100); // Generate moon
    glPopMatrix();

    // Moon 2
    glPushMatrix();
    glColor3f(MARROM);
    glRotatef(1.75*day, 1, 1.2, 0);
    glTranslatef(0.35, 0, 0);
    glutSolidSphere(0.07, 100, 100); // Generate moon
    glPopMatrix();
}

void displaySun()
{
    // Sun
    glPushMatrix();
    glColor3f(LARANJA);
    glDisable(GL_LIGHTING);
    glutSolidSphere(0.5, 100, 100); // Generate sun
    glEnable(GL_LIGHTING); // lighting according to the sun
    glPopMatrix();
}

void displaySolarSystem()
{
    displaySun();

    displayPlanetWithMoon();

    // Planet 2
    glPushMatrix();
    glColor3f(AMARELO);
    glRotatef(2*year, 0, -1, 0);
    glTranslatef(-1, -0.05, 0);
    glRotatef(2*day, 0, 1, 0);
    glutSolidSphere(0.1, 100, 80); // Generate planet
    glPopMatrix();

    // Planet 3
    glPushMatrix();
    glColor3f(VERMELHO);
    glRotatef(3*year, 0, 1, 0);
    glTranslatef(1.1, 0.4, 1);
    glRotatef(2.5*day, 0, 1, 0);
    glutSolidSphere(0.1, 100, 70); // Generate planet
    glPopMatrix();

    // Planet 4
    glPushMatrix();
    glColor3f(ROSE);
    glRotatef(4*year, 0, -1, 0);
    glTranslatef(-2, -0.4, 0);
    glRotatef(3*day, 0, 1, 0);
    glutSolidSphere(0.2, 100, 90); // Generate planet
    glPopMatrix();

    // Planet 5
    glPushMatrix();
    glColor3f(VERDE);
    glRotatef(-0.5*year, 0, -1, 0);
    glTranslatef(-2.5, 0.4, -1);
    glRotatef(-1*day, 0, 1, 0);
    glutSolidSphere(0.15, 100, 50); // Generate planet
    glPopMatrix();
}

void displayLights(){
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 }; // light position
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    displayLights();
    displaySolarSystem();
    glPopMatrix();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.0, 0.05, 0.10, 1.0); // background color
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sistema Solar com Iluminacao");
    glutInitWindowPosition(100, 100);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}