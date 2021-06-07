#include<GL/glut.h>
#include<time.h>
#include<iostream>
using namespace std;

const int N = 1e4;


void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

double Random(){
    return rand()%(199+1)/(double)(99+1) - 1;
}

void draw_triangle(int op){
    GLenum shademode = GL_FLAT, drawmode, trimode = GL_TRIANGLES;
    switch(op){
        case 1:
            drawmode = GL_FILL;
            break;
        case 2:
            drawmode = GL_LINE;
            break;
        case 3:
            drawmode = GL_POINT;
            break;
        case 4:
            drawmode =  GL_FILL;
            trimode = GL_TRIANGLE_FAN;
            break;
        case 5:
            shademode = GL_SMOOTH;
            drawmode = GL_FILL;
            break;
    }
    glShadeModel(shademode);
    glPolygonMode(GL_FRONT_AND_BACK, drawmode);
    glBegin(trimode);
        glColor3f(Random(), Random(), Random());
        glVertex3f(Random(), Random(), -1.0);
        glColor3f(Random(), Random(), Random());
        glVertex3f(Random(), Random(), -1.0);
        glColor3f(Random(), Random(), Random());
        glVertex3f(Random(), Random(), -1.0);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    clock_t start, end;

    for(int i=1; i<=5; ++i){
        glClearColor(Random(), Random(), Random(), 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        start = clock();
        for(int j=0; j<N; ++j){
            draw_triangle(i);
        }
        glFlush();
        end = clock();
        cout<<i<<". time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    }
    puts("<===================================>");
    
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 0.1, 100000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, const char * argv[]){
    glutInit(&argc, const_cast<char **>(argv));
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("lab1");

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}