#include <GL/glut.h>  // GLUT, includes glu.h and gl.h


void display1(){
    glLineWidth(3.0);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -6.0f);

        glColor3f(0.0f, 1.0f ,0.0f);
        glVertex3f(0.0f, 1.0f, -6.0f);
        
        glColor3f(0.0f ,0.0f ,1.0f);
        glVertex3f(1.0f, 1.0f, -6.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -6.0f);

        glColor3f(0.0f, 1.0f ,0.0f);
        glVertex3f(0.0f, 1.0f, -6.0f);
        
        glColor3f(0.0f ,0.0f ,0.0f);
        glVertex3f(-1.0f, 0.0f, -6.0f);
    glEnd();
}

void display2(){
  
    glNewList(1, GL_COMPILE);  

        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 1.0f);

            glVertex3f(0.0f, 0.0f, -6.0f);
            glVertex3f(0.0f, -1.0f, -6.0f);
            glVertex3f(-1.0f, -1.0f, -6.0f);

            glVertex3f(0.0f, 0.0f, -6.0f);
            glVertex3f(0.0f, -1.0f, -6.0f);
            glVertex3f(1.0f, 0.0f, -6.0f);
            
        glEnd();
    glEndList();  
    glCallList(1);  

    
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    display1();
    display2();
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

int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(1024, 1000);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   glutReshapeFunc(reshape);
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}