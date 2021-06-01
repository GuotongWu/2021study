// Lines.cpp
// Demonstrates primative GL_LINES
// OpenGL SuperBible
// Richard S. Wright Jr.
// rwright@starstonesoftware.com

#include <GL/glut.h>
#include <math.h>

// Define a constant for the value of PI
#define GL_PI 3.1415f


///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
	{
        GLfloat x,y,z,angle; // Storeage for coordinates and angles

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);


	// Call only once for all remaining points
	glBegin(GL_LINES);

	z = 0.0f;
	for(angle = 0.0f; angle <= GL_PI; angle += (GL_PI / 20.0f))
		{
		// Top half of the circle
		x = 0.50f*sin(angle);
		y = 0.50f*cos(angle);
		glVertex3f(x, y, z);

		// Bottom half of the circle
		x = 0.50f*sin(angle+GL_PI);
		y = 0.50f*cos(angle+GL_PI);
		glVertex3f(x, y, z);	
		}

	// Done drawing points
	glEnd();

	// Flush drawing commands
	glutSwapBuffers();
	}

///////////////////////////////////////////////////////////
// This function does any needed initialization on the 
// rendering context. 
void SetupRC()
	{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	}




///////////////////////////////////////////////////////////
// Main Program Entry Point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("Lines Example");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

	return 0;
}