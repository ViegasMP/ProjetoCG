

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

//Definir cores
#define BLUE        0.0, 0.0, 1.0, 1.0
#define RED         1.0, 0.0, 0.0, 1.0
#define YELLOW      1.0, 1.0, 0.0, 1.0
#define GREEN       0.0, 1.0, 0.0, 1.0
#define WHITE       1.0, 1.0, 1.0, 1.0
#define BLACK       0.0, 0.0, 0.0, 1.0
#define PI          3.14159

//Variaveis e constantes
static GLfloat vertices_traseira[] = {
    //Trás Esquerda

    0.3,  -2.0,   1.0,    // 8
    0.3,   3.0,   1.0,    // 9
    0.3,   3.0,   1.3,    // 10
    0.3,  -2.0,   1.3,    // 11

    0.0,  -2.0,   1.3,    // 4
    0.0,   3.0,   1.3,    // 5
    0.3,   3.0,   1.3,    // 6
    0.3,  -2.0,   1.3,    // 7

    0.0,  -2.0,   1.0,    // 0
    0.0,   3.0,   1.0,    // 1
    0.0,   3.0,   1.3,    // 2
    0.0,  -2.0,   1.3,    // 3

    0.0,  -2.0,   1.0,    // 12
    0.0,   3.0,   1.0,    // 13
    0.3,   3.0,   1.0,    // 14
    0.3,  -2.0,   1.0,    // 15



    //Trás Direita
    0.3,  -2.0,  -1.3,    // 16
    0.3,   3.0,  -1.3,    // 17
    0.3,   3.0,  -1.0,    // 18
    0.3,  -2.0,  -1.0,    // 19

    0.3,  -2.0,  -1.0,    // 20
    0.3,   3.0,  -1.0,    // 21
    0.0,   3.0,  -1.0,    // 22
    0.0,  -2.0,  -1.0,    // 23


    0.0,  -2.0,  -1.3,    // 24
    0.0,   3.0,  -1.3,    // 25
    0.0,   3.0,  -1.0,    // 26
    0.0,  -2.0,  -1.0,    // 27

    0.3,  -2.0,  -1.3,    // 28
    0.3,   3.0,  -1.3,    // 29
    0.0,   3.0,  -1.3,    // 30
    0.0,  -2.0,  -1.3,    // 31





    //assento
     0.3,   0.0,   1.0,    // 32
     0.3,   0.0,  -1.0,    // 33
     2.0,   0.0,  -1.0,    // 34
     2.0,   0.0,   1.0,    // 35

     0.3,  -0.3,   1.0,    // 36
     0.3,  -0.3,  -1.0,    // 37
     2.0,  -0.3,  -1.0,    // 38
     2.0,  -0.3,   1.0,    // 39

     2.0,   0.0,   1.0,    // 40
     2.0,   0.0,  -1.0,    // 41
     2.0,  -0.3,  -1.0,    // 42
     2.0,  -0.3,   1.0,    // 43
    
    
};

static GLfloat vertices_frontais[] = {
    //Frente Esquerda
        2.0,  -2.0,   1.0,    // 8
        2.0,   0.0,   1.0,    // 9
        2.0,   0.0,   0.7,    // 10
        2.0,  -2.0,   0.7,    // 11
    //Frente Direita
        2.0,  -2.0,  -0.7,    // 12
        2.0,   0.0,  -0.7,    // 13
        2.0,   0.0,  -1.0,    // 14
        2.0,  -2.0,  -1.0,    // 15
};

static GLfloat normais[] = {
    //(Esquerda)
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
        0.0,  0.0,  1.0,
    //Frente Esquerda
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
    //Frente Direita
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
        2.0,  0.0,  0.0,
    //(Cima)
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
        0.0,  1.0,  0.0,
};
//Cores
static GLfloat cor[] = {
    //Traseira - Red
        1.0,  0.0, 0.0,    // 0
        1.0,  0.0, 0.0,    // 1
        1.0,  1.0, 0.0,    // 2
        1.0,  1.0, 0.0,    // 3
    //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
    //(Cima) - Blue
        0.0,  0.0, 1.0,    // 16
        0.0,  0.0, 1.0,    // 17
        1.0,  0.0, 1.0,    // 18
        1.0,  0.0, 1.0,    // 19
        //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
    //Traseira - Red
        1.0,  0.0, 0.0,    // 0
        1.0,  0.0, 0.0,    // 1
        1.0,  1.0, 0.0,    // 2
        1.0,  1.0, 0.0,    // 3
    //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
    //(Cima) - Blue
        0.0,  0.0, 1.0,    // 16
        0.0,  0.0, 1.0,    // 17
        1.0,  0.0, 1.0,    // 18
        1.0,  0.0, 1.0,    // 19
        //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
    
    //Traseira - Red
        1.0,  0.0, 0.0,    // 0
        1.0,  0.0, 0.0,    // 1
        1.0,  1.0, 0.0,    // 2
        1.0,  1.0, 0.0,    // 3
    //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
    //(Cima) - Blue
        0.0,  0.0, 1.0,    // 16
        0.0,  0.0, 1.0,    // 17
        1.0,  0.0, 1.0,    // 18
        1.0,  0.0, 1.0,    // 19
        //Frontal - Green
        0.0,  1.0, 1.0,    // 8
        0.0,  1.0, 1.0,    // 9
        0.0,  1.0, 0.0,    // 10
        0.0,  1.0, 0.0,    // 11
};

// FACES DA MESA
//traseira
static GLuint     traseira_esquerda1[] = {0, 1, 2, 3};
static GLuint     traseira_esquerda2[] = {4, 7, 6, 5};
static GLuint     traseira_esquerda3[] = {8, 11, 10, 9};
static GLuint     traseira_esquerda4[] = {12, 15, 14, 14};
static GLuint     traseira_direita1[] = {16, 17, 18, 19};
static GLuint     traseira_direita2[] = {20, 21, 22, 23};
static GLuint     traseira_direita3[] = {24, 27, 26, 25};
static GLuint     traseira_direita4[] = {28, 31, 30, 29};
//frontal
//static GLuint     frontal_esquerda[] = {8, 11, 10, 9};
//static GLuint     frontal_direita[] = {12, 15, 14, 13};
//assento
static GLuint     assento1[] = {32, 35, 34, 33};
static GLuint     assento2[] = {36, 37, 38, 39};
static GLuint     assento3[] = {40, 43, 42, 41};


// Objectos (sistema coordenadas)
GLint        wScreen = 800, hScreen = 600;            //janela (pixeis)
GLfloat        xC = 10.0, yC = 10.0, zC = 10.0;        //Mundo  (unidades mundo)

// Visualizacao/Observador
GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { 10, 3.0, 10};
GLfloat  angZoom = 90;
GLfloat  incZoom = 3;
GLfloat  ang = 0;
GLfloat xObj = 0.0, incxObj = 0.45;
GLfloat yLegs = 0.0, incyLegs = 0.15;
GLfloat xLegs = 0.0, incxLegs = 0.15;
GLfloat agLig = 0, incAg = 10;
GLboolean   frenteVisivel = 1;

// INIT
void inicializa(void)
{
    glClearColor(BLACK);        //Apagar
    glEnable(GL_DEPTH_TEST);    //Profundidade
    
    glEnable(GL_CULL_FACE);        //ÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖÖFaces visiveis
    glCullFace(GL_BACK);

    glVertexPointer(3, GL_FLOAT, 0, vertices_traseira); //VertexArrays: vertices + normais + cores
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normais);
    glEnableClientState(GL_NORMAL_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, cor);
    glEnableClientState(GL_COLOR_ARRAY);

}



void drawEixos()
{
    //Eixo X
    glColor4f(RED);
    glBegin(GL_LINES);
        glVertex3i(0, 0, 0);
        glVertex3i(10, 0, 0);
    glEnd();
    //Eixo Y
    glColor4f(GREEN);
    glBegin(GL_LINES);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 10, 0);
    glEnd();
    //Eixo Z
    glColor4f(BLUE);
    glBegin(GL_LINES);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 0, 10);
    glEnd();

}
/*
void drawPernasTraseiras()
{
    //Esquerda
    glColor4f(RED);
    glBegin(GL_POLYGON);
        glVertex3i(0.0, -2.0, 1.0);
        glVertex3i(0.0, 3.0, 1.0);
        glVertex3i(0.0, 3.0, 1.3);
        glVertex3i(0.0, 2.0, 1.3);
    glEnd();
    //Eixo Y
    glColor4f(GREEN);
    glBegin(GL_POLYGON);
        glVertex3i(0.0, -2.0, 1.3);
        glVertex3i(0.0, 3.0, 1.3);
        glVertex3i(-0.3, 3.0, 1.3);
        glVertex3i(-0.3, -2.0, 1.3);
    glEnd();
    //Eixo Z
    glColor4f(BLUE);
    glBegin(GL_POLYGON);
        glVertex3i(-0.3,  -2.0,   1.0);
        glVertex3i(-0.3,   3.0,   1.0);
        glVertex3i( -0.3,   3.0,   1.3);
        glVertex3i(-0.3,  -2.0,   1.3);
    glEnd();
    glColor4f(GREEN);
    glBegin(GL_POLYGON);
        glVertex3i(-0.3,  -2.0,   1.0);
        glVertex3i(-0.3,   3.0,   1.0);
        glVertex3i(0.0,   3.0,   1.0);
        glVertex3i(0.0,  -2.0,   1.0);
    glEnd();
}
*/



void drawScene() {
    if (frenteVisivel)
        glCullFace(GL_BACK);  //.. o de tras È eliminado
    else
        glCullFace(GL_FRONT);  //.. o de frente È eliminado
    //CADEIRA
    glTranslatef(xObj, 0.0, 0.0);
    glRotatef(ang,0.0,1.0,0.0);
    glScalef(2, 2, 2);
    glPushMatrix();
        //parte traseira
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita4);

    glPopMatrix();
    glPushMatrix();
        //pernas frontais
        //glTranslatef(xLegs, yLegs, 0.0);
        glRotatef(agLig,0.0,0.0,1.0);
        //glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita);   // desenhar uma das faces da mesa
        //glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda);
    glPopMatrix();
    glPushMatrix();
        //cima
        glRotatef(agLig, 0.0, 0.0, 1.0);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento3);
    glPopMatrix();

}

void display(void) {

    //Apaga ecran e lida com profundidade (3D)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, wScreen, hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 3 * zC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);
       

    //Objectos
    drawEixos();
    drawScene();
    
    //Actualizacao
    glutSwapBuffers();
}

// EVENTOS
void keyboard(unsigned char key, int x, int y) {


    switch (key) {
    case 'T':
    case 't':
        frenteVisivel = !frenteVisivel;
        glutPostRedisplay();
        break;
    case 'A':
    case 'a':
        //andar para a direita no eixo x
        if (xObj - incxObj < -xC){
            xObj = -xC;   // limita
        }else{
            xObj = xObj - incxObj;
        }
        glutPostRedisplay();
        break;

    case 'S':
    case 's':
        //andar para a esqueda no eixo x
        if (xObj + incxObj > xC){
            xObj = xC;   // limita
        }else{
            xObj = xObj + incxObj;
        }
        glutPostRedisplay();
        break;
        
    case 'e':
    case 'E':
        //girar a cadeira no sentido anti-horário
        ang = ang + incZoom;
        glutPostRedisplay();
        break;

    case 'd':
    case 'D':
        //girar a cadeira no sentido horário
        ang = ang - incZoom;
        glutPostRedisplay();
        break;

    case 'f':
    case 'F':
        //fold - dobrar a cadeira
        if (agLig+incAg > 89.9){
            agLig = 89.9;   // limita
        }else{
            agLig = agLig+incAg;
            //xLegs = xLegs-incxLegs;
            //yLegs = yLegs+incyLegs;
        }
        glutPostRedisplay();
        break;
            
    case 'u':
    case 'U':
        //unfold - desdobrar a cadeira
        if (agLig-incAg < 0){
            agLig = 0;// limita
        }else{
            agLig = agLig-incAg;
            //xLegs = xLegs+incxLegs;
            //yLegs = yLegs-incyLegs;
        }
        glutPostRedisplay();
        break;

    //Escape
    case 27:
        exit(0);
        break;
    }

}


void teclasNotAscii(int key, int x, int y) {
    //.. observador pode andar em volta da cena  (setas esquerda / direita)
    //.. observador pode andar para cima e para baixo (setas cima / baixo )

    if (key == GLUT_KEY_UP)   obsP[1] = (obsP[1] + 0.1);
    if (key == GLUT_KEY_DOWN) obsP[1] = (obsP[1] - 0.1);
    if (key == GLUT_KEY_LEFT)  aVisao = (aVisao + 0.1);
    if (key == GLUT_KEY_RIGHT) aVisao = (aVisao - 0.1);
    
    if (obsP[1] >  yC)   obsP[1] = yC;   // limita altura
    if (obsP[1] < -yC)  obsP[1] = -yC;

    obsP[0] = rVisao * cos(aVisao);      // actualiza posicao (X,Z)
    obsP[2] = rVisao * sin(aVisao);
    
    glutPostRedisplay();
}


//MAIN
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 300);
    glutCreateWindow("PROJETO - CADEIRA DOBRAVEL ");

    inicializa();

    glutSpecialFunc(teclasNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}


