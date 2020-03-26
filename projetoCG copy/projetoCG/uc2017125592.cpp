#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
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
static GLfloat vertices[] = {
    0.3, -2.0, 1.0, 0.3, 3.0, 1.0, 0.3, 3.0, 1.3, 0.3, -2.0, 1.3,
    0.0, -2.0, 1.3, 0.0, 3.0, 1.3, 0.3, 3.0, 1.3, 0.3, -2.0, 1.3,
    0.0, -2.0, 1.0, 0.0, 3.0, 1.0, 0.0, 3.0, 1.3, 0.0, -2.0, 1.3,
    0.3, -2.0, 1.0, 0.3, 3.0, 1.0, 0.0, 3.0, 1.0, 0.0, -2.0, 1.0,
    0.3, -2.0, -1.3, 0.3, 3.0, -1.3, 0.3, 3.0, -1.0, 0.3, -2.0, -1.0,
    0.3, -2.0, -1.0, 0.3, 3.0, -1.0, 0.0, 3.0, -1.0, 0.0, -2.0, -1.0,
    0.0, -2.0, -1.3, 0.0, 3.0, -1.3, 0.0, 3.0, -1.0, 0.0, -2.0, -1.0,
    0.3, -2.0, -1.3, 0.3, 3.0, -1.3, 0.0, 3.0, -1.3, 0.0, -2.0, -1.3,
    0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 2.0, 0.0, -1.0, 2.0, 0.0, 1.0,
    0.0, -0.3, 1.0, 0.0, -0.3, -1.0, 2.0, -0.3, -1.0, 2.0, -0.3, 1.0,
    2.0, 0.0, 1.0, 2.0, 0.0, -1.0, 2.0, -0.3, -1.0, 2.0, -0.3, 1.0,
    0.0, 0.0, 1.0, 2.0, 0.0, 1.0, 2.0, -0.3, 1.0, 0.0, -0.3, 1.0,
    0.0, 0.0, -1.0, 2.0, 0.0, -1.0, 2.0, -0.3, -1.0, 0.0, -0.3, -1.0,
    0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, -0.3, -1.0, 0.0, -0.3, 1.0,
    2.0, -2.0, 1.0, 2.0, 0.0, 1.0, 2.0, 0.0, 1.3, 2.0, -2.0, 1.3,
    1.7, -2.0, 1.0, 1.7, 0.0, 1.0, 1.7, 0.0, 1.3, 1.7, -2.0, 1.3,
    2.0, -2.0, 1.3, 2.0, 0.0, 1.3, 1.7, 0.0, 1.3, 1.7, -2.0, 1.3,
    2.0, -2.0, 1.0, 2.0, 0.0, 1.0, 1.7, 0.0, 1.0,1.7, -2.0, 1.0,
    2.0, 0.0, 1.3, 2.0, 0.0, 1.0, 1.7, 0.0, 1.0, 1.7, 0.0, 1.3,
    2.0, -2.0, 1.3, 2.0, -2.0, 1.0, 1.7, -2.0, 1.0, 1.7, -2.0, 1.3,
    2.0, -2.0, -1.0, 2.0, 0.0, -1.0, 2.0, 0.0, -1.3, 2.0, -2.0, -1.3,
    1.7, -2.0, -1.0, 1.7, 0.0, -1.0, 1.7, 0.0, -1.3, 1.7, -2.0, -1.3,
    2.0, -2.0, -1.3, 2.0, 0.0, -1.3, 1.7, 0.0, -1.3, 1.7, -2.0, -1.3,
    2.0, -2.0, -1.0, 2.0, 0.0, -1.0, 1.7, 0.0, -1.0, 1.7, -2.0, -1.0,
    2.0, 0.0, -1.3, 2.0, 0.0, -1.0, 1.7, 0.0, -1.0, 1.7, 0.0, -1.3,
    2.0, -2.0, -1.3, 2.0, -2.0, -1.0, 1.7, -2.0, -1.0, 1.7, -2.0, -1.3,
    0.3, 3.0, -1.3, 0.3, 3.0, -1.0, 0.0, 3.0, -1.0, 0.0, 3.0, -1.3,
    0.3, -2.0, -1.3, 0.3, -2.0, -1.0, 0.0, -2.0, -1.0, 0.0, -2.0, -1.3,
    0.3, 3.0, 1.3, 0.3, 3.0, 1.0, 0.0, 3.0, 1.0, 0.0, 3.0, 1.3,
    0.3, -2.0, 1.3, 0.3, -2.0, 1.0, 0.0, -2.0, 1.0, 0.0, -2.0, 1.3,
    0.3, 2.0, -1.0, 0.3, 2.5, -1.0, 0.3, 2.5, 1.0, 0.3, 2.0, 1.0,
    0.0, 2.0, -1.0, 0.0, 2.5, -1.0, 0.0, 2.5, 1.0, 0.0, 2.0, 1.0,
    
    -10.0, -2.0, -10.0, 10.0, -2.0, -10.0, 10.0, -2.0, 10.0, -10.0, -2.0, 10.0,
    -10.0, 15.0, -10.0, 10.0, 15.0, -10.0, 10.0, 15.0, 10.0,-10.0, 15.0, 10.0,
    -10.0, -2.0, -10.0, 10.0, -2.0, -10.0, 10.0, 15.0, -10.0, -10.0, 15.0, -10.0,
    -10.0, -2.0, -10.0, -10.0, -2.0, 10.0, -10.0, 15.0, 10.0, -10.0, 15.0, -10.0,
    10.0, -2.0, 10.0, -10.0, -2.0, 10.0, -10.0, 15.0, 10.0, 10.0, 15.0, 10.0,
    10.0, -2.0, -10.0, 10.0, -2.0, 10.0, 10.0, 15.0, 10.0, 10.0, 15.0, -10.0,
    
};

//normais
static GLfloat normais[] = {
    1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
};

//Cores
static GLfloat cor[] = {
    0.45, 0.4, 0.13, 0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,0.45, 0.4, 0.13,
    
    0.4, 0.3, 0.2, 0.4, 0.3, 0.2, 0.4, 0.3, 0.2, 0.4, 0.3, 0.2,
    0.5, 0.7, 0.9, 0.5, 0.7, 0.9, 0.5, 0.7, 0.9, 0.5, 0.7, 0.9,
    0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9,
    0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9,
    0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9,
    0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9, 0.6, 0.8, 0.9,
};

// FACES DA CADEIRA
//traseira
static GLuint   traseira_esquerda1[] = {0, 1, 2, 3};
static GLuint   traseira_esquerda2[] = {4, 7, 6, 5};
static GLuint   traseira_esquerda3[] = {8, 11, 10, 9};
static GLuint   traseira_esquerda4[] = {12, 15, 14, 13};
static GLuint   traseira_esquerda5[] = {112, 113, 114, 115};
static GLuint   traseira_esquerda6[] = {116, 119, 118, 117};
static GLuint   traseira_direita1[] = {16, 17, 18, 19};
static GLuint   traseira_direita2[] = {20, 21, 22, 23};
static GLuint   traseira_direita3[] = {24, 27, 26, 25};
static GLuint   traseira_direita4[] = {28, 31, 30, 29};
static GLuint   traseira_direita5[] = {104, 107, 106, 105};
static GLuint   traseira_direita6[] = {108, 109, 110, 111};
//frontal
static GLuint   frontal_esquerda1[] = {56, 57, 58, 59};
static GLuint   frontal_esquerda2[] = {60, 63, 62, 61};
static GLuint   frontal_esquerda3[] = {64, 65, 66, 67};
static GLuint   frontal_esquerda4[] = {68, 71, 70, 69};
static GLuint   frontal_esquerda5[] = {72, 73, 74, 75};
static GLuint   frontal_esquerda6[] = {76, 79, 78, 77};
static GLuint   frontal_direita1[] = {80, 83, 82, 81};
static GLuint   frontal_direita2[] = {84, 85, 86, 87};
static GLuint   frontal_direita3[] = {88, 91, 90, 89};
static GLuint   frontal_direita4[] = {92, 93, 94, 95};
static GLuint   frontal_direita5[] = {96, 99, 98, 97};
static GLuint   frontal_direita6[] = {100, 101, 102, 103};
//assento
static GLuint   assento1[] = {32, 35, 34, 33};
static GLuint   assento2[] = {36, 37, 38, 39};
static GLuint   assento3[] = {40, 43, 42, 41};
static GLuint   assento4[] = {44, 47, 46, 45};
static GLuint   assento5[] = {48, 49, 50, 51};
static GLuint   assento6[] = {52, 53, 54, 55};
//encosto
static GLuint   encosto1[] = {120, 121, 122, 123};
static GLuint   encosto2[] = {124, 127, 126, 125};
//sala
static GLuint   chao[] = {128, 131, 130, 129};
static GLuint   teto[] = {132, 133, 134, 135};
static GLuint   parede1[] = {136, 137, 138, 139};
static GLuint   parede2[] = {140, 143, 142, 141};
static GLuint   parede3[] = {144, 145, 146, 147};
static GLuint   parede4[] = {148, 149, 150, 151};

// Objectos (sistema coordenadas)
GLint     wScreen = 800, hScreen = 600;        //janela (pixeis)
GLfloat     xC = 10.0, yC = 10.0, zC = 10.0;     //Mundo (unidades mundo)

// Visualizacao/Observador
GLfloat rVisao = 5.0, aVisao = 0.5 * PI, incVisao = 0.5;
GLfloat obsPini[] = { 5.0, 1.0, 0.5 * 20.0 };
GLfloat obsPfin[] = { obsPini[0] - rVisao * cos(aVisao), obsPini[1], obsPini[2] - rVisao * sin(aVisao) };

GLfloat angRot = 90;
GLfloat incRot = 10;
GLfloat ang = 0;
GLfloat angQ = 0;
GLfloat xObj = 0.0, incxObj = 0.45;
GLfloat yLegs = 0.0;
GLfloat xLegs = 2.0;
GLfloat agLig = 0, incAg = 5;
GLboolean frenteVisivel = 1;
GLint time0=0;
GLint second, minute;
int flag = 1;

// INIT
void inicializa(void)
{
    glClearColor(BLACK);        //Apagar
    glEnable(GL_DEPTH_TEST);    //Profundidade
    
    glEnable(GL_CULL_FACE);        //Faces visiveis
    glCullFace(GL_BACK);

    glVertexPointer(3, GL_FLOAT, 0, vertices); //VertexArrays: vertices + normais + cores
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normais);
    glEnableClientState(GL_NORMAL_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, cor);
    glEnableClientState(GL_COLOR_ARRAY);

}
void timer()
{
    struct tm *current_time;
    time_t timer = time(0);
    current_time = localtime(&timer);
    minute = current_time->tm_min;
    second = current_time->tm_sec;
    if(time0 < second+minute*60){
        //second0 = second - 1;
        if (angQ >= 25){
            flag = 1;
        }
        if(angQ == -25){
            flag = -1;
        }
        if (flag > 0){
            angQ -= 1;
        }
        if (flag < 0){
            angQ += 1;
        }

        glutPostRedisplay();
    }
}

void drawQuadros(float x0, float y0, float h, float z0, float l) {
    glPushMatrix();
    glColor4f(WHITE);
    glTranslatef(x0, y0+h, z0+l/2);
    glRotatef(angQ,0.1,0.0,0.0);
    glTranslatef(-x0, -(y0+h), -(z0+l/2));
    glBegin(GL_QUADS);
        glVertex3f(x0, y0, z0);
        glVertex3f(x0, y0+h, z0);
        glVertex3f(x0, y0+h, z0+l);
        glVertex3f(x0, y0, z0+l);
    glEnd();
    glPopMatrix();
    
}

void drawOrientacao()
{
    //OBSERVADOR: onde esta; para onde olha
    glPushMatrix();
        glColor4f(GREEN);
        glTranslatef(obsPini[0], obsPini[1], obsPini[2]);
        glPushMatrix();
        glBegin(GL_QUADS);
            glVertex3f(-0.5, 0.1, -0.5);
            glVertex3f(-0.5, 0.1, 0.5);
            glVertex3f( 0.5, 0.1, 0.5);
            glVertex3f( 0.5, 0.1, -0.5);
        glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glColor4f(BLUE);
        glTranslatef(obsPfin[0], obsPfin[1], obsPfin[2]);
        glPushMatrix();
        glBegin(GL_QUADS);
           glVertex3f(-0.5, 0.1, -0.5);
           glVertex3f(-0.5, 0.1, 0.5);
           glVertex3f( 0.5, 0.1, 0.5);
           glVertex3f( 0.5, 0.1, -0.5);
        glEnd();
       glPopMatrix();
    glPopMatrix();

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

void drawRoom()
{
    glPushMatrix();
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, chao);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, teto);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, parede1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, parede2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, parede3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, parede4);
    glPopMatrix();
    
}

void drawWindow()
{
    glPushMatrix();
    glColor4f(WHITE);
    glBegin(GL_QUADS);
        glVertex3f(9.75, 0.5, -3.0);
        glVertex3f(9.75, 0.5, 3.0);
        glVertex3f(9.75, 4.0, 3.0);
        glVertex3f(9.75, 4.0, -3.0);
    glEnd();
    glPopMatrix();
    
}

void drawScene()
{
    if (frenteVisivel)
        glCullFace(GL_BACK);  //.. o de tras È eliminado
    else
        glCullFace(GL_FRONT);  //.. o de frente È eliminado
    //CADEIRA
    glPushMatrix();
    glTranslatef(xObj, 0.0, 0.0);
    glRotatef(ang,0.0,1.0,0.0);
    glScalef(1, 1, 1);
    glPushMatrix();
        //parte traseira
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda5);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_esquerda6);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita5);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, traseira_direita6);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, encosto1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, encosto2);
    glPopMatrix();
    glPushMatrix();
        //cima
        glRotatef(agLig, 0.0, 0.0, 1.0);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento5);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, assento6);
    glPopMatrix();
    glPushMatrix();
        //pernas frontais
        glTranslatef(xLegs, yLegs, 0.0);
        glTranslatef(-2.0, 0.0, 0.0);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda5);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_esquerda6);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita1);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita2);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita3);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita4);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita5);
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frontal_direita6);
    glPopMatrix();
    glPopMatrix();

}

void display(void) {

    //Apaga ecran e lida com profundidade (3D)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Viewport1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, hScreen / 4, wScreen / 6, hScreen / 5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-xC, xC, -xC, xC, -zC, zC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, -1);
    //desenha objectos
    drawOrientacao();
    drawScene();
    
    glViewport(0, 0, wScreen, hScreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angRot, (float)wScreen / hScreen, 0.1, 3 * zC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsPini[0], obsPini[1], obsPini[2], obsPfin[0], obsPfin[1], obsPfin[2], 0, 1, 0);

    //Objectos
    drawRoom();
    drawEixos();
    drawScene();
    drawWindow();
    timer();
    drawQuadros(-9.95, 0.5, 3.5, -3.0, 2.0);
    drawQuadros(-9.95, 4.0, 6.0, 4.0, 3.0);
    drawQuadros(-9.95, 7.0, 3.0, -7.0, 4.0);
    
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
        if (xObj + incxObj + xLegs> xC){
            xObj = xC-xLegs;   // limita
        }else{
            xObj = xObj + incxObj;
        }
        glutPostRedisplay();
        break;
        
    case 'e':
    case 'E':
        //girar a cadeira no sentido anti-horário
        ang = ang + incRot;
        glutPostRedisplay();
        break;

    case 'd':
    case 'D':
        //girar a cadeira no sentido horário
        ang = ang - incRot;
        glutPostRedisplay();
        break;

    case 'f':
    case 'F':
        //fold - dobrar a cadeira
        if (agLig+incAg > 75){
            agLig = 75;   // limita
        }else{
            agLig = agLig+incAg;
            xLegs = cos(agLig*PI/180)*2;
            yLegs = sin(agLig*PI/180)*2;
        }
        glutPostRedisplay();
        break;
            
    case 'u':
    case 'U':
        //unfold - desdobrar a cadeira
        if(xObj + 2 < xC || abs(ang) > 89.9){
            if (agLig-incAg < 0){
                agLig = 0;// limita
            }else{
                agLig = agLig-incAg;
                xLegs = cos(agLig*PI/180)*2;
                yLegs = sin(agLig*PI/180)*2;
            }
        }

        glutPostRedisplay();
        break;

    //Escape
    case 27:
        exit(0);
        break;
    }

}

//andar com o observador nas setas do teclado
void teclasNotAscii(int key, int x, int y)
{
    if (key == GLUT_KEY_UP) {
        obsPini[0] = obsPini[0] + incVisao * cos(aVisao);
        obsPini[2] = obsPini[2] - incVisao * sin(aVisao);
    }
    if (key == GLUT_KEY_DOWN) {
        obsPini[0] = obsPini[0] - incVisao * cos(aVisao);
        obsPini[2] = obsPini[2] + incVisao * sin(aVisao);
    }
    if (key == GLUT_KEY_LEFT)
        aVisao = (aVisao + 0.1);
    if (key == GLUT_KEY_RIGHT)
        aVisao = (aVisao - 0.1);

    obsPfin[0] = obsPini[0] + rVisao * cos(aVisao);
    obsPfin[2] = obsPini[2] - rVisao * sin(aVisao);
    glutPostRedisplay();
}


//MAIN
int main(int argc, char** argv) {
    
    struct tm *current_time0;
    time_t timer0 = time(0);
    current_time0 = localtime(&timer0);
    GLint minute0, second0;
    minute0 = current_time0->tm_min;
    second0 = current_time0->tm_sec;
    time0 = minute0*60+second0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 300);
    glutCreateWindow("PROJETO - CADEIRA DOBRAVEL");

    inicializa();

    glutSpecialFunc(teclasNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}


