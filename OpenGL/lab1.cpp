#include<GL/glut.h>

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void draw_triangle(int left){
    glLineWidth(3);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(-1-left, -1, -6);
        glColor3f(0, 1, 0);
        glVertex3f(1-left, -1, -6);
        glColor3f(0, 0, 1);
        glVertex3f(0-left, 1, -6);

        glColor3f(0, 0, 1);
        glVertex3f(0-left, 1, -6);
        glColor3f(0, 1, 0);
        glVertex3f(1-left, -1, -6);
        glColor3f(0, 0, 0);
        glVertex3f(2-left, 1, -6);
    glEnd();
}

void draw_triangle_fan(int right){
    glShadeModel(GL_FLAT);
    glNewList(1, GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0, 0, 1);
            glVertex3f(-1+right, -1, -6);
            glColor3f(0, 0, 1);
            glVertex3f(1+right, -1, -6);
            glColor3f(0, 0, 1);
            glVertex3f(0+right, 1, -6);

            glColor3f(0, 0, 1);
            glVertex3f(2+right, 1, -6);
            glColor3f(0, 0, 1);
            glVertex3f(1+right, -1, -6);
            glColor3f(0, 0, 1);
            glVertex3f(0+right, 1, -6);
            
        glEnd();
    glEndList();

    glCallList(1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // 绘制三角形
    draw_triangle(2);
    draw_triangle_fan(1);
    
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

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("lab1");

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}