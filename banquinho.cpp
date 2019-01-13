// Andressa Oliveira

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <GL/glu.h>
#include <GL/glut.h>
#include <time.h>
#include <locale.h>
#include <iostream>



#define PI 3.14159265358979324
#define X 100
#define Y 100


using namespace std;

int isWire = 1;
float n = 0.01;
int gy, gx, gz;


void drawdisc(float x, float y, float r, int tam){
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(x, y);
        for( int n = 0; n <= tam; ++n ) {
            float const t = 2 * 3.14 * (float)n / (float)tam;
            glVertex2f(x + sin(t) * r, y + cos(t) * r/4);
        }
    glEnd();
}


void drawScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT, GL_FILL);

    (isWire) ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);(isWire) ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



    glPushMatrix();
    glRotatef(gx, 1, 0, 0); //x
    glRotatef(gy, 0, 1, 0); // y
    glRotatef(gz, 0, 0, 1); // z

    glColor3f(0.0, 0.0, 0.0);

    drawdisc(50, 50, 25, 15); // assento


    drawdisc(20, 95, 5, 15); // pés
    drawdisc(50, 80, 2.5, 15);
    drawdisc(80, 95, 5, 15);


    glBegin(GL_QUADS);        // pernas
        glVertex3f(15, 95, 0);
        glVertex3f(25, 50, 0);
        glVertex3f(30, 50, 0);
        glVertex3f(25, 95, 0);

        glVertex3f(47.5, 80, 0);
        glVertex3f(47.5, 50, 0);
        glVertex3f(52.5, 50, 0);
        glVertex3f(52.5, 80, 0);

        glVertex3f(75, 95, 0);
        glVertex3f(70, 50, 0);
        glVertex3f(75, 50, 0);
        glVertex3f(85, 95, 0);


    glEnd();
    glPopMatrix();

   glFlush();
}

void setup(void) {
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(200, 1, 1, 300);
    gluLookAt(0, 0, -20, 0, 0, 0, 0, 1, 0);
}

void keyInput(unsigned char key, int x, int y) {
    switch(key) {

        case 'z':
            gz-=5;
            glutPostRedisplay();
            break;
        case 'y':
            gy+=5;
            glutPostRedisplay();
            break;
        case 'x':
            gx+=5;
            glutPostRedisplay();
            break;
        case ' ':
            isWire = !isWire;
            glutPostRedisplay();
            break;
        default:
            glutPostRedisplay();
            break;
   }
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Banquinho");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);


   setup();

   glutMainLoop();
}
