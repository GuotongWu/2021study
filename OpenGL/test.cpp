#include<GL/glut.h>

void init(){
    glClearColor(0.1, 0.1, 0.4, 0.0);
    glShadeModel(GL_SMOOTH);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // 绘制三角形
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(-1, -1, -5);
        glColor3f(0, 1, 0);
        glVertex3f(1, -1, -5);
        glColor3f(0, 0, 1);
        glVertex3f(0, 1, -5);
    glEnd();
    // 执行绘图命令
    glFlush();    
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

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello World!");

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}