#include<stdio.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
float x[100], y[100];
float a,b;
void init(){
    gluOrtho2D(-100,100,-100,100);
}
//------------Factorial--------------------
int factorial(int n){
    if(n<=1){
        return(1);
    }
    else{
        n=n*factorial(n-1);
    }
    return(n);
}
//----------Binomial Coefficient----------
float bincof(float n,float k){
    float a;
    a=factorial(n)/(factorial(k)*factorial(n-k));
    return(a);
}
void display(){
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1.0f,0.0f,0.0f);
        for(int i=0;i<n;i++){
            glVertex2f(x[i],y[i]);
        }
    glEnd();
    //------------Convex Hull------------------
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
        for(int i=0;i<n;i++){
            glVertex2f(x[i],y[i]);
            if(i!=0 && i!=n-1){
                glVertex2f(x[i],y[i]);
            }
        }
    glEnd();
    //------------Bezier Curve-----------------
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f,1.0f,0.0f);
        for(float t=0;t<1.0;t+=0.01){
            a=0;b=0;
            for(int k=0;k<n;k++){
                float q=bincof(n-1,k)*pow(t,k)*pow(1-t,n-k-1);
                a+=x[k]*q;
                b+=y[k]*q;
            }
            glVertex2f(a,b);
        }
    glEnd();
    glFlush();
}
int main(int argc, char ** argv)
{   printf("Enter The Number Of Points : ");
    scanf("%d",&n);
    printf("\nEnter The Co-ordinates : ");
    for(int i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i]);
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bezier Curve");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;

}

// No. of points - 3 
// Co ord = -40, -40, 30, 50, 50, 10