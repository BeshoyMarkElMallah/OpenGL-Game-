#include <GL/glut.h>
#include <iostream>
#include<math.h>

const move_increment = 10;
const starting_move_distance = 0.05;

class CarManager
{
public:
    float x_move = 0.01;
    float carSpeed = starting_move_distance;
    int[] cars = [];
    CarManager()
    {
    };

    void createCars(){
        int randomChance = rand(1,6);
        if(randomChance == 1){
            glPushMatrix();
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(0.1,0.1);
            glVertex2f(-0.1,0.1);
            glVertex2f(-0.1,-0.1);
            glVertex2f(0.1,-0.1);
            glEnd();
            glPopMatrix();
            float rand_y = rand(-250,250);
            
        }
    }


};
