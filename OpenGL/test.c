#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>

/*
 功能描述：使用OpenGL简单画一个旋转的三角形
 旋转变换函数glRotatef
 */

//输出模式，0-单缓存模式；非0双缓存模式
#define OUTPUT_MODE 1

//角度
int angle = 0;

int xyz[3] = {0, 0, 0};

void display(void)
{
    printf("xyz={%d,  %d,  %d}\n", xyz[0], xyz[1], xyz[2]);

    glClear(GL_COLOR_BUFFER_BIT);


    glLoadIdentity();
    glRotatef(angle, xyz[0], xyz[1], xyz[2]);

    glBegin(GL_TRIANGLES);
    {
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
    }
    glEnd();

    angle += 1;
    angle %= 360;

    if (OUTPUT_MODE == 0) {
        glFlush();//单缓存GLUT_SINGLE时使用
    } else {
        glutSwapBuffers();//因为使用的是双缓存GLUT_DOUBLE，所以这里必须要交换缓存才会显示
    }

    Sleep(100);
}

//按键
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'x':
    case 'X':
        xyz[0] = 1;
        xyz[1] = xyz[2] = 0;
        break;
    case 'y':
    case 'Y':
        xyz[1] = 1;
        xyz[0] = xyz[2] = 0;
        break;
    case 'z':
    case 'Z':
        xyz[2] = 1;
        xyz[0] = xyz[1] = 0;
        break;
    case 'a':
    case 'A':
        xyz[0] = xyz[1] = xyz[2] = 0;
        break;
    case 'b':
    case 'B':
        xyz[0] = xyz[1] = xyz[2] = 1;
        break;
    default:
        break;
    }
    printf("当前绕%c轴旋转\n", key);
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    int offset = 50;
    int dis = (w > h ? h : w) - offset * 2;

    //配置显示物体屏幕的大小
    glViewport(offset, offset, (GLsizei)dis, (GLsizei)dis);
    printf("reshape: w=%d, h=%d, dis=%d\n", w, h, dis);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.5, 1.5, -1.5, 1.5, 0, 10);
    //gluOrtho2D(-1.5, 1.5, -1.5, 1.5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char *argv[])
{
    printf("可通过按键xyzab控制图形旋转原点/轴\n");
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);

    glutCreateWindow("第一个 OpenGL 程序");

    glutDisplayFunc(&display);
    glutIdleFunc(display);  //设置不断调用显示函数
    glutReshapeFunc(reshape);
    glutKeyboardFunc(&keyboard);
    glutMainLoop();
    return 0;
}