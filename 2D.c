#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
int choice = 0;
int xt = 0; int yt = 0;

struct point{
	int x;
	int y;
};
struct point result[4];

void input()
{
	printf("Enter vertices of Square : ");
	int t = 0;
	while(t < 4){
		scanf("%d%d", &result[t].x, &result[t].y);
		t++;
	}

	printf("1 for Translation\n2 for Rotation\n3 for Scaling\n4 for Reflection about x-axis, y-axis, y=x, y=-x and origin\n");
	printf("5 for Shearing about x-axis and y-axis\nEnter your choice : ");
	scanf("%d", &choice);
}

 
void translation(int xt, int yt)
{

	for(int i = 0; i < 4; i++)
	{
		result[i].x += xt;
		result[i].y += yt;
	}
}

 
void rotation(double theta, int flag)
{
	theta = theta*(3.14159265/180); // degree
	if(flag == 1){					// anticlockwise
		for(int i = 0; i < 4; i++)
		{
			int tx = result[i].x;
			int ty = result[i].y;
			result[i].x = tx*cos(theta) - ty*sin(theta);
			result[i].y = ty*cos(theta) + tx*sin(theta);
		}
	}
	else{							// clockwise
		for(int i = 0; i < 4; i++)
		{
			int tx = result[i].x;
			int ty = result[i].y;
			result[i].x = tx*cos(theta) + ty*sin(theta);
			result[i].y = ty*cos(theta) - tx*sin(theta);
		}
	}
}

 
void scaling(int sx, int sy)
{
	for(int i = 0; i < 4; i++)
	{
		result[i].x *= sx;
		result[i].y *= sy;
	}
}

 
void reflection1(int w)
{
	int i = 0;
	if(w == 1)
		for(i = 0; i < 4; i++)
			result[i].y = result[i].y*(-1);
	else if(w == 2)
		for(i = 0; i < 4; i++)
			result[i].x = result[i].x*(-1);
	else if(w == 3)
	{
		for(i = 0; i < 4; i++){
			int temp = result[i].x;
			result[i].x = result[i].y;
			result[i].y = temp;
		}
	}
	else if(w == 4)
	{
		for(i = 0; i < 4; i++){
			int temp = (-1)*result[i].x;
			result[i].x = (-1)*result[i].y;
			result[i].y = temp;
		}
	}
	else
	{
		for(i = 0; i < 4; i++){
			result[i].x = result[i].x*(-1);
			result[i].y = result[i].y*(-1);
		}
	}
}

 
void shearing(int shx, int shy)
{
	for(int i = 0; i < 4; i++)
	{
		result[i].x += result[i].y*shx;
		result[i].y += result[i].x*shy;
	}
}

 


void display()
{
	double theta = 0.0; int flag = 1;  
	int sx = 1; int sy = 1;  
	int w = 0;  
	int shx = 0; int shy = 0;  

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(0, 100);
	glVertex2d(0, -100);
	glVertex2d(100, 0);
	glVertex2d(-100, 0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
		for(int m = 0; m < 4; m++){
			glVertex2d(result[m].x, result[m].y);
		}
	glEnd();
	glFlush();

	switch(choice)
	{
		case 1:	printf("Enter value of x translation : ");
				scanf("%d", &xt);
				printf("Enter value of y translation : ");
				scanf("%d", &yt);
				translation(xt, yt);
				break;

		case 2:	printf("Enter reference point : ");
				scanf("%d%d", &xt, &yt);
				translation(-1*xt, -1*yt);
				printf("Enter angle of rotation : ");
				scanf("%lf", &theta);
				printf("Enter 1 for anticlockwise or 0 for clockwise : ");
				scanf("%d", &flag);
				if(theta != 0.0)
					rotation(theta, flag);
				translation(xt, yt);
				break;

		case 3:	printf("Enter scaling factor of x : ");
				scanf("%d", &sx);
				printf("Enter scaling factor of y : ");
				scanf("%d", &sy);
				scaling(sx, sy);
				break;

		case 4:	printf("1 for x-axis\n2 for y-axis\n3 for y=x\n4 for y=-x\n5 for origin\n");
				printf("Enter your choice : ");
				scanf("%d", &w);
				reflection1(w);
				break;

		case 5:	printf("Enter shearing factor for x : ");
				scanf("%d", &shx);
				printf("Enter shearing factor for y : ");
				scanf("%d", &shy);
				shearing(shx, shy);
				break;
	}

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		for(int m = 0; m < 4; m++){
			glVertex2d(result[m].x, result[m].y);
		}
	glEnd();

	glFlush();
}


int main(int argc, char** argv)
{
	input();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("2D Transformations");
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

// Vertices of square - 50 0 50 50 0 50 0 0

// Translation - x trans - 15, y trans - 15
// Rotation - Reference point - 0 , angle of rotation - 60
// Scaling - x scale - 2, y scale - 1
// Reflection(y=mx+c) - m - 1, c - 5
// Shearing - x shear - 2, y shear - 0   