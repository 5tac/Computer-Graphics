#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void display(void)
{
//SKY//
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-1.0f,1.0f);
	glVertex2f(1.0f,1.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(-1.0f,0.0f);
	glEnd();
//MOUNTAINS//
	glBegin(GL_TRIANGLES);
	glColor3f(0.4f,0.2f,0.1f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(-0.75f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.25f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4f,0.2f,0.1f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(0.25f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(0.75f,0.5f);
	glEnd();
	//FIELD//
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.99f, 0.0f);
	glVertex2f( -1.0f, 0.0f);
	glVertex2f( 1.0f, 0.0f);
	glVertex2f(1.0f,-0.7f);
	glVertex2f(-1.0f,-0.7f);
	glEnd();
	//River//
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(-1.0f,-0.7f);
	glVertex2f(1.0f,-0.7f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(-1.0f,-1.0f);
	glEnd();
	//HUT//
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.5f);
	glVertex2f(0.3f,-0.3f);
	glVertex2f(0.7f,-0.3f);
	glVertex2f(0.7f,-0.6f);
	glVertex2f(0.3f,-0.6f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.1f,0.1f,0.0f);
	glVertex2f(0.45f,-0.45f);
	glVertex2f(0.55f,-0.45f);
	glVertex2f(0.55f,-0.6f);
	glVertex2f(0.45f,-0.6f);
	glEnd();
	glFlush();
}
void my_key_events (unsigned char key,int x,int y)
{
	switch(key){
		case 't' : case 'T' :
		//BOAT//
		glBegin(GL_QUADS);
		glColor3f(0.1f, 0.1f, 0.0f);
		glVertex2f(-0.8f,-0.6f);
		glVertex2f(-0.2f,-0.6f);
		glVertex2f(-0.4f,-0.8f);
		glVertex2f(-0.6f,-0.8f);
		glEnd();
		glFlush();
		break;
	}
}
void my_mouse(int button, int state, int x, int y) {
	float x1,y1,x2,y2;
	float angle;
	double radius;
	switch(button){
	case GLUT_RIGHT_BUTTON: ;
	//SUN//
	radius = 0.25;
	x1 = 0,y1=0.7;
	glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for(angle=1.0f;angle<361.0f;angle+=0.2){
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
	glFlush();
	break;
//NIGHT//
case GLUT_LEFT_BUTTON: ;
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.1f, 0.1f);
	glVertex2f(-1.0f,1.0f);
	glVertex2f(1.0f,1.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(-1.0f,0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4f,0.2f,0.1f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(-0.75f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.25f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4f,0.2f,0.1f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(0.25f,0.5f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(0.75f,0.5f);
	glEnd();
	radius = 0.15;
	x1 = 0.6,y1=0.8;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for(angle=1.0f;angle<361.0f;angle+=0.2){
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
	glFlush();
	break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(400,400);
	glutCreateWindow("Scenery having keyboard and mouse event");
	glutDisplayFunc(display);
	glutKeyboardFunc(my_key_events);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}