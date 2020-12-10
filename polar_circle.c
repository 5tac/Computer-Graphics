#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init()
{
    gluOrtho2D(-20,20,-20,20);
}
void display(void)
{
    float x,y,theta;
    int xc,yc,r,i;
    printf("Give the Center(x,y) coordinates : ");
    scanf("%d %d",&xc,&yc);
    printf("Radius of the circle : ");
    scanf("%d",&r);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    for(i=0; i<360; i++){
        theta = (3.14*i)/180;
        x = xc + (r*cos(theta));
        y = yc + (r*sin(theta));
        glVertex2d(x, y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("Circle Polar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// Centre - 0 0
// Radius - 10