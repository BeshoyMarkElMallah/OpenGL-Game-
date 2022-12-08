#include <iostream>
#include <GL/glut.h>

class Planet
{
public:
    float radius, distance, orbit, orbitspeed;
    Planet(float _radius, float _distance, float _orbit, float _orbitSpeed)
    {
        radius = _radius;
        distance = _distance;
        orbit = _orbit;
        orbitspeed = _orbitSpeed;
    }

    void drawSmallOrbit(void)
    {
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutWireTorus(0.001, distance, 100.0, 100.0);
        glPopMatrix();
    }
    
    void drawMoon(void)
    {
        GLUquadricObj *quadric;
        quadric = gluNewQuadric();
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(orbit, 0.0, 1.0, 0.0);
        glTranslatef(distance, 0.0, 0.0);
        gluSphere(quadric, radius, 20.0, 20.0);
        glPopMatrix();
    }
};