#include <GL/glut.h> 
#include <math.h> 
#include <stdio.h> 

void display(); 
float xmin = -40, ymin = -40, xmax = 40, ymax = 40; 
float X1, Y1, X2, Y2; 
void init() { 
    gluOrtho2D(-300, 300, -300, 300); 
} 

int REGION(float x, float y) //region code 
{ 
    int code = 0;  
    if (y > ymax) //above the rectangle 
    { 
        code = 8; 
    } 

    if (y < ymin) //below the rectangle 
    { 
        code = 4; 
    } 

    if (x > xmax) //right of rectangle 
    { 
        code |= 2; 
    } 

    if (x < xmin) //left of rectangle 
    { 
        code |= 1; 
    } 

    return code; 
} 

void CSL(float x1, float y1, float x2, float y2)   { 

    int code1 = REGION(x1, y1); //region code calculated   
    int code2 = REGION(x2, y2); 
    float slope = (y2 - y1) / (x2 - x1); 

    while ((code1 || code2) > 0)   { 
        if ((code1 & code2) > 0) 
        { 
            exit(0); 
        } 

        float helper1 = x1; 
        float helper2 = y1; 
        int flag = code1; 
        if (flag == 0) { 
            flag = code2; 
            helper1 = x2; 
            helper2 = y2; 
        } 

        float x, y; 
        if ((flag & 8) > 0) //Top  
        { 
            y = ymax; 
            x = helper1 + 1.0 / slope * (ymax - helper2); 
        } 

        else if ((flag & 4) > 0)  //Bottom
        {   
            y = ymin; 
            x = helper1 + 1.0 / slope * (ymin - helper2); 
        } 

        else if ((flag & 2) > 0) //right  
        { 
            x = xmax; 
            y = helper2 + slope * (xmax - helper1); 
        } 

        else if ((flag & 1) > 0) // left  
        { 
            x = xmin; 
            y = helper2 + slope * (xmin - helper1); 
        } 

        if (flag == code1)
        { 
            X1 = x; 
            Y1 = y; 
            code1 = REGION(X1, Y1); 
        }  

        if (flag == code2) 
        { 
            X2 = x; 
            Y2 = y; 
            code2 = REGION(X2, Y2); 
        } 
    } 
    display(); 
} 

void CLIP(unsigned char key, int x, int y) { 
    if (key == 'c' || key == 'C') 
    { 
        CSL(X1, Y1, X2, Y2); 
        glFlush(); 
    } 
} 

void display() { 

    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(xmin, ymin); 
    glVertex2i(xmin, ymax); 
    glVertex2i(xmax, ymax); 
    glVertex2i(xmax, ymin); 
    glEnd(); 
    // line 
    glColor3f(0.0, 1.0, 0.0); 
    glBegin(GL_LINES); 
    glVertex2i(X1, Y1); 
    glVertex2i(X2, Y2); 
    glEnd(); 
    glFlush(); 
} 

int main(int argc, char **argv) { 

    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); 
    printf("Enter co-ordinates of Line : "); 
    scanf("%f %f %f %f", &X1, &Y1, &X2, &Y2); 
    glutCreateWindow("Cohen-Sutherland-Line-Clipping"); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(CLIP); 
    init(); 
    glutMainLoop(); 
    return 0; 
} 

// Inside - 10 10 30 30
// Outside - 60 60 80 80
// Partial - 20 20 60 60