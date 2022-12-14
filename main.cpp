#include <GL/glut.h>
#include <stdlib.h> /* srand, rand */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>

float Random_number(float min, float max)
{
    return ((float(rand())) / (float(RAND_MAX)) * (max - min)) + min;
}
typedef struct food
{
    float x = Random_number(-1, 1);
    float y = Random_number(-1, 0.7);
} Food;

Food f[10];
Food stars[1000];

void drawCircle(float radius, float incrX, float incrY, int i, int iterator)
{
    // GLenum type,
    for (i; i < iterator; i++)
    {
        float angle = i * 3.14 / 180;
        glVertex2f(radius * cos(angle) + (incrX), radius * sin(angle) + (incrY));
    }
}

void topBody()
{

    glBegin(GL_POLYGON);
    glColor3f(0.690f, 0.425f, 0.0276f);
    glVertex2f(-0.4f, 0.8f); //
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f); //
    glEnd();

    // draw oultine
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.8f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f);
    glEnd();
}

void bottomBody()
{
    glBegin(GL_POLYGON);
    glColor3f(0.370f, 0.228f, 0.0148f);
    glVertex2f(-0.4f, 0.1f); //
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f); //
    glEnd();

    // draw outline
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f);
    glEnd();
}

void tail()
{
    glBegin(GL_POLYGON);
    glColor3f(0.370f, 0.228f, 0.0148f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.4f, -0.4f);
    glEnd();

    // black outline
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.4f, -0.4f);
    glEnd();
}

void downLines()
{
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.2f, -0.2f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.2f, -0.2f);
    glEnd();
}

void nose()
{
    glBegin(GL_POLYGON);
    glColor3f(0.940f, 0.564f, 0.00f);
    glVertex2f(-0.1f, 0.4f);
    drawCircle(0.1, 0.0, 0.4, 0, 180);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    // black outline
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.4f);
    glEnd();

    // curve on top
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.1, 0.0, 0.4, 0, 180);
    glEnd();
}

void leftEye()
{
    // outcircle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.14, -0.3, 0.5, 0, 135);
    drawCircle(0.14, -0.3, 0.5, 225, 360);
    glEnd();

    // outcircle border
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.14, -0.3, 0.5, 0, 135);
    drawCircle(0.14, -0.3, 0.5, 225, 360);
    glEnd();

    // innercircle
    glBegin(GL_POLYGON);
    glColor3f(0.370f, 0.228f, 0.0148f);
    drawCircle(0.06, -0.28, 0.5, 0, 360);
    glEnd();

    // Innercircle border
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.06, -0.28, 0.5, 0, 360);
    glEnd();
}

void rightEye()
{
    // outcircle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.14, 0.3, 0.5, 45, 315);
    glEnd();

    // outcircle border
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.14, 0.3, 0.5, 45, 315);
    glEnd();

    // innercircle
    glBegin(GL_POLYGON);
    glColor3f(0.370f, 0.228f, 0.0148f);
    drawCircle(0.06, 0.28, 0.5, 0, 360);
    glEnd();

    // Innercircle border
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.06, 0.28, 0.5, 0, 360);
    glEnd();
}

void leftLeg()
{
    glBegin(GL_POLYGON);
    glColor3f(0.940f, 0.564f, 0.00f);
    drawCircle(0.13, -0.16, -0.4, 0, 180);
    glEnd();

    // leg border
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.13, -0.16, -0.4, 0, 180);
    glEnd();
}

void rightLeg()
{
    glBegin(GL_POLYGON);
    glColor3f(0.940f, 0.564f, 0.00f);
    drawCircle(0.13, 0.16, -0.4, 0, 180);
    glEnd();

    // leg border
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.13, 0.16, -0.4, 0, 180);
    glEnd();
}

void foodTaker()
{
    glTranslatef(-0.3, -0.8, 0.0);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.6);
    glVertex2f(-0.2, 0.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.2, 0);
    glVertex2f(-0.4, 0.2);
    glEnd();
}

float tx = 0.7, ty = 0.2, sx = 0.4, sy = 0.8, foodx = 0.0001, foody = Random_number(-1, 1);
int score = 0, angle = 0, lives = 10;
void specialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void keys(unsigned char key, int x, int y);

void moveHawk()
{

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    topBody();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    bottomBody();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    tail();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    downLines();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    nose();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    leftEye();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    rightEye();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    leftLeg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    rightLeg();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(sx, sx, 1.0);
    glScalef(sy, sy, 1.0);
    glRotatef(angle, 0, 0, 1);
    foodTaker();
    glPopMatrix();
}


void food()
{
    glScalef(0.3,0.3,1.0);
    // draw Big Cookie
    glColor3f(0.750, 0.471, 0.0525);
    glBegin(GL_POLYGON);
    drawCircle(0.2, 0, 0, 0, 360);
    glEnd();

    // draw small cookies
    glColor3f(0.510, 0.310, 0.0102);
    glBegin(GL_POLYGON);
    drawCircle(0.03861, -0.1, 0.1, 0, 360);
    glEnd();
    glColor3f(0.510, 0.310, 0.0102);
    glBegin(GL_POLYGON);
    drawCircle(0.03861, 0.1, 0.1, 0, 360);
    glEnd();
    glColor3f(0.510, 0.310, 0.0102);
    glBegin(GL_POLYGON);
    drawCircle(0.03861, 0.1, -0.1, 0, 360);
    glEnd();
    glColor3f(0.510, 0.310, 0.0102);
    glBegin(GL_POLYGON);
    drawCircle(0.03861, -0.1, -0.1, 0, 360);
    glEnd();
    glColor3f(0.510, 0.310, 0.0102);
    glBegin(GL_POLYGON);
    drawCircle(0.03861, 0, 0, 0, 360);
    glEnd();
}




void welcomeDisplay()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glRasterPos3f(-0.2, 0.8, 0);
    char msg1[] = "Hawk Eat";
    for (int i = 0; i < strlen(msg1); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);

    glRasterPos3f(-0.8, 0.7, 0);
    char msg2[] = "Submitted By : Beshoy El-Mallah";
    for (int i = 0; i < strlen(msg2); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg2[i]);

    glColor3f(0, 0, 1);

    glRasterPos3f(-0.8, -0.7, 0);
    char msg3[] = "PRESS s TO START THE GAME";
    for (int i = 0; i < strlen(msg3); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);
    glutSwapBuffers();
}

void ScoreDisplay(int score)
{
    glColor3f(1, 0, 0);
    glRasterPos3f(-0.8, 0.8, 0);
    char int_str[20];
    sprintf(int_str,"%d",score);
    char msg1[] = "Score: ";
    strcat(msg1,int_str);
    char *string = (msg1);

    while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
    }
}
void LivesDisplay(int lives)
{
    glColor3f(1, 0, 0);
    glRasterPos3f(0.4, 0.8, 0);
    char int_str[20];
    sprintf(int_str,"%d",lives);
    char msg1[] = "Lives: ";
    strcat(msg1,int_str);
    char *string = (msg1);

    while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
    }
}
void GameOverDisplay()
{
    glColor3f(1, 0, 0);
    glRasterPos3f(-0.5, 0, 0);
    char msg1[] = "GAME OVER ";
    for (int i = 0; i < strlen(msg1); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
    glRasterPos3f(0.0, 0.8, 0);
    char msg2 = 0;
    // for (int i = 0; i < strlen(msg1); i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, msg2);
    glutSwapBuffers();
}

void moveFood()
{
    
    for (int i = 0; i < 10; i++)
    {
        glPushMatrix();
        glTranslatef(f[i].x, f[i].y, 0.0);
        food();
        if (f[i].x > 1)
        {
            f[i].x = -1;
            printf("lives--");
            lives--;
        }
        if (f[i].x >= tx && f[i].y >= ty)
        {
            f[i].x = -1;
            printf("score++");
            score++;
        }

        glPopMatrix();
        f[i].x += 0.0001;
    }
}

void background()
{
    for (int i = 0; i < 1000; i++)
    {
        glPushMatrix();
        glTranslatef(stars[i].x, stars[i].y, 0.0);
        glColor3f(Random_number(-1, 1), Random_number(-1, 1), Random_number(-1, 1));
        glBegin(GL_POINTS);
        glVertex2f(stars[i].x, stars[i].y);
        glEnd();
        if (stars[i].x > 1)
        {
            stars[i].x = -1;
        }

        glPopMatrix();
        stars[i].x += 0.0001;
    }
    // glutPostRedisplay();
}

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // drawBitmapText((char)score,-0.9,0.9,0.0);
    glMatrixMode(GL_MODELVIEW);
    background();
    ScoreDisplay(score);
    LivesDisplay(lives);
    moveFood();

    moveHawk();
    if (lives == 0)
    {
        glutDisplayFunc(GameOverDisplay);
    }
    glFlush();
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 10; i++)
    {
        f[i].x = Random_number(-1, 1);
        f[i].y = Random_number(-1, 0.7);
    }

    for (int i = 0; i < 1000; i++)
    {
        stars[i].x = Random_number(-1, 1);
        stars[i].y = Random_number(-1,1 );
    }
    glutInit(&argc, argv);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Character");
    glutInitWindowPosition(0, 0);
    glutKeyboardFunc(keys);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);
    glutDisplayFunc(welcomeDisplay);
    glutMainLoop();
    return 0;
}

void keys(unsigned char key, int x, int y)
{
    if (key == 's')
    {
        glutDisplayFunc(display);
    }
    if (key == 'a')
    {
        angle += 10;
    }
    if (key == 'q')
    {
        angle -= 10;
    }

    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_DOWN)
    {
        ty -= 0.1;
    }
    if (key == GLUT_KEY_UP)
    {
        ty += 0.1;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        // tx += 0.1;
    }
    if (key == GLUT_KEY_LEFT)
    {
        // tx -= 0.1;
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    { // Pause/resume
        sy -= 0.1;
    }
    if (button == GLUT_RIGHT_BUTTON)
    { // Pause/resume
        sy += 0.1;
    }
    // printf("%d\t%d\n", x, y);
}
