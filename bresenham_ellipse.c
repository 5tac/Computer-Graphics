#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
 
float h, k, a, b;
 
void bresenham()
{
        float x = 0;
        float y = b;
        float d1 = b*b + a*a*(1/4-b);
        float tempx = 0.0; float tempy = b;
 
        while(x*b*b <= y*a*a)
        {
                if(d1 < 0)
                        d1 = d1 + b*b*(2*x+3);
                else
                {
                        d1 = d1 + b*b*(2*x+3) - a*a*2*(y-1);
                        y = y-1;
                }
                x = x+1;
 
                glBegin(GL_LINE_STRIP);
                        glVertex2f(tempx+h, tempy+k);
                        glVertex2f(x+h, y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(-tempx+h, tempy+k);
                        glVertex2f(-x+h, y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(tempx+h, -tempy+k);
                        glVertex2f(x+h, -y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(-tempx+h, -tempy+k);
                        glVertex2f(-x+h, -y+k);
                glEnd();
                tempx = x; tempy = y;
        }
        float d2 = b*b*pow((x+1/2),2) + a*a*pow((y-1),2) - a*a*b*b;
        while(y != 0)
        {
                if(d2 < 0)
                {
                        d2 = d2 + 2*b*b*(x+1) - a*a*(2*y-3);
                        x = x+1;
                }
                else
                        d2 = d2 + a*a*(3-2*y);
                y = y-1;
 
                glBegin(GL_LINE_STRIP);
                        glVertex2f(tempx+h, tempy+k);
                        glVertex2f(x+h, y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(-tempx+h, tempy+k);
                        glVertex2f(-x+h, y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(tempx+h, -tempy+k);
                        glVertex2f(x+h, -y+k);
                glEnd();
                glBegin(GL_LINE_STRIP);
                        glVertex2f(-tempx+h, -tempy+k);
                        glVertex2f(-x+h, -y+k);
                glEnd();
                tempx = x; tempy = y;
        }
}
 
void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0,1.0);
        bresenham();
        glFlush();
}
 
void main(int argc, char** argv)
{
        printf("Enter the Co-ordinates of the origin : ");
        scanf("%f%f", &h, &k);
        printf("Enter the radius of major axis : ");
        scanf("%f", &a);
        printf("Enter the radius of minor axis : ");
        scanf("%f", &b);
        glutInit(&argc,argv);//starts GLUT
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(900,900);
        glutInitWindowPosition(200,200);
        glutCreateWindow("Ellipse Bresenham");
        gluOrtho2D(-500, 500, -500, 500);
        glutDisplayFunc(display);
        glutMainLoop();
}

// Origin - 0 0
// Radius of major axis - 50
// Radius of minor axis - 100