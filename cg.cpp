/* 
Starting Commands and how to execute the file 
gedit filename.cpp
...
g++ filename.cpp -o filename -lGL -lGLU -lglut
./filename


*/

#include<GL/glu.h>
#include<GL/glut.h> //inside the GL folder we have the glut.h file
void MyInit()
{
  glClearColor(1.0,1.0,1.0,1.0);//bgcolor r,g,b,transparency-->default 1
  glColor3f(1.0,0.0,0.0);//drawing color

}

void Draw()
{
  glClear(GL_COLOR_BUFFER_BIT);/*to Clear the background we clear the color buffer and set it to glClearColor*/
  //We draw a square here
  //glPointSize(5);//Default point size is 1
  glBegin(GL_POLYGON);//To group the vertices we use glBegin and glEnd
  //if the primitive used here is GL_POINTS it just displays the 4 points
  //if the primitives used here is GL_LINES it just joins the adjacent 
  //points and hence in this case we get two parallel lines
  //To get a complete outline we use GL_LINE_LOOP primitive
  //To get a solid square we use GL_POLYGON primitive
  	glVertex2f(-0.5,0.5);//2-> 2d x and y f->floating point
  	//glVertex2f( 0,0.5);//For the triangle 
  	glVertex2f(0.5,0.5);
  	glVertex2f( 0.5,-0.5);
 	glVertex2f(-0.5,-0.5);
 glEnd();
  glFlush();/*To put this in the frame buffer as soon as the processing of the drawing is done*/
}

//CHECK FROM HERE
int main(int C, char *V[]) 
/*two parameters argument Count and argument Vector-> 2d array we are gonna using character pointer as we are not assigning the values to argV[][] argC and argV can be changed to any other variable name So here to keep it simple i use C and V respectively*/
{
  glutInit(&C,V);//Initializing console for input and output in C
  //Default window size is 300x300 so we are going to change it
  glutInitWindowPosition(200,50);//To set the initial position of the window
  glutInitWindowSize(500,500);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  /*RGB mode with single buffer (Macros which have their own values) 
 Note: We use '|' bit wise or operator*/
  glutCreateWindow("Basic OpenGL Program");//Creates the window 
  MyInit();
  glutDisplayFunc(Draw);/*this function is called so that we can display anything on our graphics window. the parameter given is the (user-defined function) functionName and this function returns nothing(void) */
  
  glutMainLoop();/*This function will make sure that the main function is executed on loop and it is going to be the starting point of the window operations*/
  
  
  return 0;
}




