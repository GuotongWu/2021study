#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>
#include"lab2.h"

#include<GL/glut.h>

#define BLACK 0, 0, 0

#define WHITE 1, 1, 1

#define LIGHT_GREEN 0.125, 0.698, 0.667
#define DARK_GREEN 0.000, 0.502, 0.502

#define LIGHT_RED 0.647, 0.165, 0.165
#define DARK_RED 0.502, 0.000, 0.000

#define LIGHT_WHITE 0.961, 0.961, 0.961
#define DARK_WHITE 0.502, 0.502, 0.502
#define DEEP_DARK_WHITE 0.412, 0.412, 0.412


#define START_RILL 45
#define RILL_DELTA 2
#define DEVIDER_LEN 25

#define START_LAMP -200
#define LAMP_DELTA 2
#define END_LAMP -400
#define LAMP_INTERVAL 200

#define START_ANGLE 4
#define END_ANGLE 5.5

#define MAX_CAMERA_HEIGHT 100
#define MIN_CAMERA_HEIGHT 10


#define CAR_POSITION_MIN -18
#define CAR_POSITION_DELTA 0.2
#define CAR_POSITION_MAX 38



#define LAMP_COLOR 0.184, 0.310, 0.310
#define LIGHT_COLOR 0.914, 0.588, 0.478

#define DELTA 0.001


#define SKY_TOP 1.000, 1.000, 1.000

//make a global variable -- for tracking the anglular position of camera
double cameraAngle;			//in radian
double cameraAngleDelta;

double cameraHeight;
double cameraHeightDelta = 0.05;
double cameraRadius;

double rectAngle;	//in degree
double lamp_start;

double car_position;

bool canDrawGrid;
bool camera_angle_inc;
bool camera_height_inc;

bool move_enable;

double car_move = START_RILL;

GLUquadric *qobj;

GLuint top_layer, middle_layer, buttom_layer;
GLuint front_incline, back_incline, left_incline, right_incline;
GLuint front_vertical, back_vertical, left_vertical, right_vertical;


double Random(){
    return rand()%(199+1)/(double)(99+1) - 1;
}

double color [3][3] = {LIGHT_GREEN, LIGHT_RED, LIGHT_WHITE};
int color_point = 0;
double current_color[3];

void create_triangle(double x, double y,double z,double radius, double resolution)
{
    /* top triangle */
    double PI = 3.1416;
    double i;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(DARK_WHITE);
        glVertex3f(x, y, z);  /* center */
        for (i = 2 * PI; i >= 0; i -= resolution, color_point=(color_point+1)%3){
            for(int j=0; j<3; ++j) current_color[j] = color[color_point][j];
            glColor3f(current_color[0],current_color[1],current_color[2]);
            glVertex3f(x, y+radius*cos(i), z+radius*sin(i));
        }
        glColor3f(DARK_WHITE);
        glVertex3f(x, y+radius*cos(i), z+radius*sin(i));
    glEnd();
}

void create_wheel(double x, double y, double z, double radious, double width){
    glPushMatrix();
    {
        glColor3f(DARK_WHITE);
        // glTranslatef(10,-20,50);
        glTranslatef(x, y, z);
        glRotatef(90,0,1,0);
        
        glColor3f(DARK_WHITE); 
        gluCylinder(qobj, radious, radious, width, 15, 20);
    }
    glPopMatrix();

    glColor3f(DARK_WHITE);
    create_triangle(x+width,y, z, radious, 1);
    create_triangle(x,y, z, radious, 1);
}

void draw_road(){
    //road border
    glBegin(GL_POLYGON);{
            glColor3f(0.412, 0.412, 0.412);
            glVertex3f(-50,-400,1);//right low
            glVertex3f(-5,1000,1);//right low
            glVertex3f(-2,1000,1);//right low
            glVertex3f(-45,-400,1);//right low

   }glEnd();
   glBegin(GL_POLYGON);{
            glColor3f(0.412, 0.412, 0.412);
            glVertex3f(80,-400,1);//right low
            glVertex3f(5,1000,1);//right low
            glVertex3f(2,1000,1);//right low
            glVertex3f(75,-400,1);//right low

   }glEnd();
   //0.663, 0.663, 0.663
   //0.827, 0.827, 0.827
   //main road
   glBegin(GL_POLYGON);{
            glColor3f(0.663, 0.663, 0.663);
            glVertex3f(-45,-400,1);
            glVertex3f(-2,1000,1);

            glColor3f(0.827, 0.827, 0.827);
            glVertex3f(0,1000,1);
            glVertex3f(15,-400,1);

   }glEnd();
   glBegin(GL_POLYGON);{
            glColor3f(0.827, 0.827, 0.827);
            glVertex3f(0,1000,1);
            glVertex3f(15,-400,1);

            glColor3f(0.663, 0.663, 0.663);
            glVertex3f(75,-400,1);
            glVertex3f(2,1000,1);
    }glEnd();
}

void draw_grass(){
    //grass

    glBegin(GL_POLYGON);{
             glColor3f(0.741, 0.718, 0.420);
             glVertex3f(-50,-400,1);
             glVertex3f(-5,1000,1);


             glColor3f(0.941, 0.902, 0.549);
             glVertex3f(-800,1000,1);
             glVertex3f(-800,-400,1);


    }glEnd();

    glBegin(GL_POLYGON);{
             glColor3f(0.741, 0.718, 0.420);
             glVertex3f(80,-400,1);
             glVertex3f(5,1000,1);


             glColor3f(0.941, 0.902, 0.549);
             glVertex3f(800,1000,1);
             glVertex3f(800,-400,1);


    }glEnd();

}

void draw_sky(){
    //sky
    //sky front
   glBegin(GL_POLYGON);{
            glColor3f(0.678, 0.847, 0.902);
            glVertex3f(-800,1000,-10);
            glVertex3f(800,1000,-10);

            glColor3f(SKY_TOP);
            glVertex3f(900,1000,200);
            glVertex3f(-900,1000,200);
   }glEnd();

   //sky left
   glBegin(GL_POLYGON);{
            glColor3f(0.678, 0.847, 0.902);
            glVertex3f(-800,1000,-10);
            glVertex3f(-800,-400,-10);

            glColor3f(SKY_TOP);
            glVertex3f(-900,-400,200);
            glVertex3f(-900,1000,200);
   }glEnd();

   //sky right
   glBegin(GL_POLYGON);{
            glColor3f(0.678, 0.847, 0.902);
            glVertex3f(800,1000,-10);
            glVertex3f(800,-400,-10);

            glColor3f(SKY_TOP);
            glVertex3f(900,-400,200);
            glVertex3f(900,1000,200);
   }glEnd();

    //sky back
    glBegin(GL_POLYGON);{
            glColor3f(0.678, 0.847, 0.902);
            glVertex3f(-800,-400,-10);
            glVertex3f(800,-400,-10);

            glColor3f(SKY_TOP);
            glVertex3f(900,-400,200);
            glVertex3f(-900,-400,200);
   }glEnd();

}

void car(double x, double y){
    top_layer = load_texture("image/top_layer.bmp");
    middle_layer = load_texture("image/middle_layer.bmp");
    buttom_layer = load_texture("image/buttom_layer.bmp");

    front_incline = load_texture("image/front_incline.bmp");
    back_incline = load_texture("image/back_incline.bmp");
    left_incline = load_texture("image/left_incline.bmp");
    right_incline = load_texture("image/right_incline.bmp");

    front_vertical = load_texture("image/front_vertical.bmp");
    back_vertical = load_texture("image/back_vertical.bmp");
    left_vertical = load_texture("image/left_vertical.bmp");
    right_vertical = load_texture("image/right_vertical.bmp");

    // top level
    glBindTexture(GL_TEXTURE_2D, top_layer);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-7,10,30);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+7,10,30);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+7,30,30);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-7,30,30);
    }glEnd();

    //middle level
    glBindTexture(GL_TEXTURE_2D, middle_layer);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-15,-10,20);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+15,-10,20);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+15,50,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-15,50,20);
    }glEnd();

    //bottom layer
    glBindTexture(GL_TEXTURE_2D, buttom_layer);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-15,-10,10);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+15,-10,10);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+15,50,10);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-15,50,10);
    }glEnd();

    // left incline
    glBindTexture(GL_TEXTURE_2D, left_incline);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-11,5,20);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x-7,10,30);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x-7,30,30);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-11,35,20);
    }glEnd();

    // right incline
    glBindTexture(GL_TEXTURE_2D, right_incline);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x+7,10,30);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+11,5,20);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+11,35,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x+7,30,30);
    }glEnd();

    // front incline
    glBindTexture(GL_TEXTURE_2D, front_incline);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-7,30,30);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+7,30,30);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+11,35,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-11,35,20);
    }glEnd();

    // back inclie
    glBindTexture(GL_TEXTURE_2D, back_incline);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-11,5,20);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+11,5,20);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+7,10,30);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-7,10,30);
    }glEnd();

    // left vertical
    glBindTexture(GL_TEXTURE_2D, left_vertical);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-15,-10,10);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x-15,-10,20);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x-15,50,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-15,50,10);
    }glEnd();

    // right vertical
    glBindTexture(GL_TEXTURE_2D, right_vertical);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x+15,-10,20);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+15,-10,10);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+15,50,10);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x+15,50,20);
    }glEnd();

    //back vertical
    glBindTexture(GL_TEXTURE_2D, back_vertical);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-15,-10,10);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+15,-10,10);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+15,-10,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-15,-10,20);
    }glEnd();
    
    // front vertical
    glBindTexture(GL_TEXTURE_2D, front_vertical);
    glBegin(GL_QUADS);{
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x-15,50,10);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x+15,50,10);//right low
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x+15,50,20);//right top
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x-15,50,20);
    }glEnd();

    glDeleteTextures(1, &front_vertical);
}

void draw_car(double x, double y){
    car(x,y);
    create_wheel(x+12.5, 0, 7, 6, 3);
    create_wheel(x-16.5, 0, 7, 6, 3);

    create_wheel(x+12.5, 30, 7, 6, 3);
    create_wheel(x-16.5, 30, 7, 6, 3);
}

void create_lamp(double x,double y,double z,double height){
    double radius = 2.00*height/100.00;

    glPushMatrix();
    {
        glColor3f(LAMP_COLOR);
        //glTranslatef(10,-20,50);
        glTranslatef(x, y, z);
        glRotatef(90,0,0,1);
        // qobject, radious bottom, radious top, height, slice , slice
        gluCylinder(qobj, radius, 3.00*radius/2.00, 5.00*height/100.00, 10, 10);
    }glPopMatrix();
    glPushMatrix();
    {
        glColor3f(LAMP_COLOR);
        //glTranslatef(10,-20,50);
        glTranslatef(x, y, z+5.00*height/100.00);
        glRotatef(90,0,0.0,1);
        // qobject, radious bottom, radious top, height, slice , slice
        gluCylinder(qobj, 3.00*radius/2.00, 3.00*radius/2.00, 0.5*height/100.00, 10, 10);
    }glPopMatrix();

    glPushMatrix();
    {
        glColor3f(LAMP_COLOR);
        //glTranslatef(10,-20,50);
        glTranslatef(x, y, z+5.5*height/100.00);
        glRotatef(90,0,0.0,1);
        // qobject, radious bottom, radious top, height, slice , slice
        gluCylinder(qobj, 3.00*radius/2.00, radius, 5.0*height/100.00, 10, 10);
    }glPopMatrix();

    glPushMatrix();
    {
        glColor3f(LAMP_COLOR);
        //glTranslatef(10,-20,50);
        glTranslatef(x, y, z+10.5*height/100.00);
        glRotatef(90,0,0.0,1);
        // qobject, radious bottom, radious top, height, slice , slice
        gluCylinder(qobj, radius, radius/2, 90*height/100.00, 50, 50);
    }glPopMatrix();

    glPushMatrix();
    {
        glColor3f(LAMP_COLOR);
        //glTranslatef(10,-20,50);
        glTranslatef(x, y, height);
        glRotatef(90,0,1,0);
        // qobject, radious bottom, radious top, height, slice , slice
        gluCylinder(qobj, 0.5*radius/2.00, 0.5*radius/2.00, 10*height/100.00, 50, 15);
    }glPopMatrix();

    //void glutSolidSphere(GLdouble radius,GLint slices, GLint stacks);
    double equ[4];

        equ[0] = 1;	//0.x
        equ[1] = 0;	//0.y
        equ[2] = 0;//-1.z x + 10*height/100.00

        equ[3] = (-1.00)*(x + 10*height/100.00);//30

        glClipPlane(GL_CLIP_PLANE0,equ);
        //now we enable the clip plane

   // glEnable(GL_CLIP_PLANE0);{
    glEnable(GL_CLIP_PLANE0);{
        glColor3f(LIGHT_COLOR);
            glPushMatrix();{
                glTranslatef(x+15.00*height/100.00, y+.4, height);
                glScalef(3, 1, 0.5);

                glutSolidSphere(5*height/100.00, 20.00*height/100.00, 20.00*height/100.00);
            }glPopMatrix();
   }glDisable(GL_CLIP_PLANE0);
   //}glDisable(GL_CLIP_PLANE0);
}

void display(){

    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(WHITE, 0);	//color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /********************
    / set-up camera here
    ********************/
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);
    //initialize the matrix
    glLoadIdentity();
    /*
     *  now give three info
     *  1. where is the camera (viewer)?
     *  2. where is the camera is looking?
     *  3. Which direction is the camera's UP direction?
     */

    gluLookAt(cameraRadius*cos(cameraAngle), cameraRadius*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
    //NOTE: the camera still CONSTANTLY looks at the center
    // cameraAngle is in RADIAN, since you are using inside COS and SIN


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);

        draw_car(car_position,0);

        draw_road();

        draw_grass();

        draw_sky();


    glPushMatrix();
    {

        for(double road_y = -400+car_move; road_y <= 950 ; road_y+=START_RILL){
            double x_left,x_right,x1,x2,x3,x4,y,y1,y2;
            x1 = 13;
            x2 = 17;
            x3 = -0.3;
            x4 = 0.3;
            y1 = -400;
            y2 = 1000;

            x_left = (road_y-y1)*(x3 - x1)/(y2 - y1) + x1;
            x_right = (road_y - y1)*(x4 - x2)/(y2 - y1) + x2;

            glBegin(GL_POLYGON);{
                    glColor3f(DEEP_DARK_WHITE);
                    glVertex3f(x_left, road_y, 2);
                    glVertex3f(x_right, road_y, 2);

                    x_left = (road_y + DEVIDER_LEN -y1)*(x3 - x1)/(y2 - y1) + x1;
                    x_right = (road_y + DEVIDER_LEN - y1)*(x4 - x2)/(y2 - y1) + x2;

                    glVertex3f(x_right, road_y+DEVIDER_LEN, 2);
                    glVertex3f(x_left, road_y+DEVIDER_LEN, 2);
           }glEnd();


        }
       }glPopMatrix();
    /*
    x ,y ,z, height
    */
   // glPushMatrix();
   // {
    for(double lamp_tmp = lamp_start; lamp_tmp <=1000; lamp_tmp += LAMP_INTERVAL){
            double lamp_x,lamp_x1,lamp_x2,lamp_y1,lamp_y2;
            lamp_x1 = -53;
            lamp_x2 = -3;
            lamp_y1 = -400;
            lamp_y2 = 1000;
            lamp_x = (lamp_tmp - lamp_y1)*(lamp_x2 - lamp_x1)/(lamp_y2 - lamp_y1) + lamp_x1;
            create_lamp(lamp_x, lamp_tmp, 0.00, 120 - 10.00*(lamp_tmp + 500.00 - 100.00)/200.00);
        }

    //}
    //glPopMatrix();

    // glEnable(GL_LIGHTING);
	// glEnable(GL_LIGHT0);

	// GLfloat ambient[] = { .3f,.3f,.3f,1.f };
	// GLfloat diffuse[] = { .7f,.7f,.7f,1.f };
	// GLfloat specular[] = { .5f,.5f,.5f,1.f };

	// glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	// glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// GLfloat position[] = { 1.0f,0.0f,0.f,1.f };
	// glLightfv(GL_LIGHT0, GL_POSITION, position);


    glutSwapBuffers();
}

void animate(){
    //codes for any changes in Camera
    if(move_enable){
        if(camera_angle_inc == false){
            cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
            if(cameraAngle >= END_ANGLE)
                camera_angle_inc =true;
        }
        else {
            cameraAngle -= cameraAngleDelta;
            if(cameraAngle <= START_ANGLE)
                        camera_angle_inc =false;
        }


        if(camera_height_inc == false){
            cameraHeight += cameraHeightDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
            if(cameraHeight >= MAX_CAMERA_HEIGHT)
                camera_height_inc =true;
        }
        else {
            cameraHeight -= cameraHeightDelta;
            if(cameraHeight <= MIN_CAMERA_HEIGHT)
                        camera_height_inc =false;
        }


        //codes for any changes in Models

        if(car_move <= 0){
            car_move = START_RILL;
        }
        else{
            car_move -= RILL_DELTA;
        }

        lamp_start -= LAMP_DELTA;
        if(lamp_start <= END_LAMP)
            lamp_start = START_LAMP;

        rectAngle -= 1;
    }

    //MISSING SOMETHING? -- YES: add the following
    glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
    switch(key){
        case '4':
            if(car_position> CAR_POSITION_MIN)
                car_position -= CAR_POSITION_DELTA;
            break;
        case '5':
              move_enable = false;
              break;
        case '6':
            if(car_position< CAR_POSITION_MAX)
                car_position += CAR_POSITION_DELTA;
            break;
        case '8':	//toggle grids
           // canDrawGrid = 1 - canDrawGrid;
            move_enable = true;
            break;
        case 27:	//ESCAPE KEY -- simply exit
            exit(0);
            break;
        default:
            break;
    }
}

void specialKeyListener(int key, int x,int y){
    switch(key){
        case GLUT_KEY_DOWN:		//down arrow key
            cameraRadius += 10;
            break;
        case GLUT_KEY_UP:		// up arrow key
           if(cameraRadius > 10)
                cameraRadius -= 10;
            break;
        case GLUT_KEY_RIGHT:
            cameraAngle += cameraAngleDelta*10;
            break;
        case GLUT_KEY_LEFT:
            cameraAngle -= cameraAngleDelta*10;
            break;
        case GLUT_KEY_PAGE_UP:
            cameraHeight += 10;
            break;
        case GLUT_KEY_PAGE_DOWN:
            cameraHeight -= 10;
            break;
        default:
            break;
    }
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)		// 2 times?? in ONE click? -- solution is checking DOWN or UP
                cameraAngleDelta = -cameraAngleDelta;
            break;
        default:
            break;
    }
}


void init(){
    //codes for initialization
    cameraAngle = START_ANGLE;	//// init the cameraAngle
    cameraAngleDelta = 0.002;
    rectAngle = 0;
    canDrawGrid = true;
    cameraHeight = MIN_CAMERA_HEIGHT;
    camera_height_inc = true;
    cameraRadius = 180;
    move_enable = true;

    car_position = 7.5;
    //clear the screen
    glClearColor(WHITE, 0);

    lamp_start = START_LAMP;

    // cylinder
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);

    /************************
    / set-up projection here
    ************************/
    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    //give PERSPECTIVE parameters
    gluPerspective(70,	1,	0.1,	10000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glEnable(GL_TEXTURE_2D);    // 启用纹理

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    //ADD keyboard listeners:
    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);

    //ADD mouse listeners:
    glutMouseFunc(mouseListener);

    glutMainLoop();		//The main loop of OpenGL

    //cleanup
    gluDeleteQuadric(qobj);

    return 0;
}
