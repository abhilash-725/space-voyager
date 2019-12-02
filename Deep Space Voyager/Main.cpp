#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void initWindow(void);

float angle = 0.0;
int left, right;
int leftTime, rightTime;
int thrust, thrustTime;

float x = 20, y = 20, xv, yv, v;
int shield = 0, cursor = 1;
int lastTime;
int paused = 0;
int resuming = 1;
int originalWindow = 0, currentWindow;



void drawstars()
{

	float b=rand()%30;	
	glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		for(int i=0;i<b;i++){
			
			float c=rand()%30;
			
		glVertex2f(5+b,21+c);
		glVertex2f(20+c,35+b);
		glVertex2f(-9.0+20+b,-1.9+15+c);
		glVertex2f(-40.0+20+b,-1.9+12+c);
}
	
		glEnd();
}
void
drawShip(float angle)
{
  float rad;
 

  glPushMatrix();
   
//drawstars();
  glTranslatef(x, y, 0.0);
   
  glRotatef(angle, 0.0, 0.0, 1.0);
  if (thrust) {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8, -0.5);
    glVertex2f(-1.8, 0);
    glVertex2f(-0.8, 0.5);
    glEnd();
  }
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(1.8, -1.0);
  glVertex2f(-0.2, 0.0);
  glVertex2f(-0.2, 0.0);
  
  glVertex2f(-0.2, -1.0);
  glVertex2f(-0.2, 0.0);
  glVertex2f(-0.2, 1.0);
  glVertex2f(1.8, 1.0);
  glEnd();
   
  glBegin(GL_TRIANGLES);
  glVertex2f(-1.0, -1.0);
  glVertex2f(-1.0, 1.0);
  glVertex2f(0.0, 0.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.3, -0.4);
  glVertex2f(0.7, -0.4);
  glVertex2f(0.7, 0.7);
  
  glVertex2f(0.3, 0.7);
  glEnd();
   
  glColor3f(0.5, 0.5, 1.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.8, 1.0);
  glVertex2f(0.8, 1.7);
  glEnd();
  glColor3f(0.5, 0.5, 1.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.8, -1.0);
  glVertex2f(0.8, -1.7);
	glEnd();  
  glColor3f(0.5, 0.5, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0.8, 1.7);
  glVertex2f(1.3, 2.0);
  glVertex2f(1.3, 4.0);
  glVertex2f(0.3, 4.0);
  glVertex2f(0.3, 2.0);
  glVertex2f(0.8, 1.7);
  glEnd();
  glColor3f(0.5, 0.5, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0.8, -1.7);
  glVertex2f(1.3, -2.0);
  glVertex2f(1.3, -4.0);
  glVertex2f(0.3, -4.0);
  glVertex2f(0.3, -2.0);
  glVertex2f(0.8, -1.7);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.8, -1.7);
  glVertex2f(0.8, -4.0);
  glEnd();
   glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.8, 1.7);
  glVertex2f(0.8, 4.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, -2.0);
  glVertex2f(1.7, -2.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, -2.5);
  glVertex2f(1.7, -2.5);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, -3.0);
  glVertex2f(1.7, -3.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, -3.5);
  glVertex2f(1.7, -3.5);
  glEnd();
   glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, 2.0);
  glVertex2f(1.7, 2.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, 2.5);
  glVertex2f(1.7, 2.5);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, 3.0);
  glVertex2f(1.7, 3.0);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(0.3, 3.5);
  glVertex2f(1.7, 3.5);
  glEnd();
  /*glColor3f(1.0,1.0,1.0);
  for(float ii=4.0;ii<50.0;ii=ii+3){
	  for(float x=2.9;x<45;x=x+1.8){
			glBegin(GL_POINTS);
		glVertex2f(-ii, -ii);
		glVertex2f(x,x+2.7);
		glEnd();
	  }}*/

  if (shield) {
    glColor3f(0.1, 0.1, 1.0);
    glBegin(GL_LINE_LOOP);
    for (rad=0.0; rad<12.0; rad += 1.0) {
      glVertex2f(2.3 * cos(2*rad/M_PI)+0.2, 2.0 * sin(2*rad/M_PI));
    }
	glEnd();
  }
  if(right)
  {
	  glColor3f(1.0,0.0,0.0);
	  glBegin(GL_TRIANGLES);
	  glVertex2f(1.8, 1.0);
		glVertex2f(1.6, 1.0);
		glVertex2f(1.7, 1.9);
		glEnd();
		glColor3f(1.0,0.0,0.0);
	  glBegin(GL_TRIANGLES);
	  glVertex2f(-0.2, -1.0);
		glVertex2f(0.0, -1.0);
		glVertex2f(-0.1, -1.9);
		glEnd();
  }
  if(left)
  {
	  glColor3f(1.0,0.0,0.0);
	  glBegin(GL_TRIANGLES);
	  glVertex2f(1.8, -1.0);
		glVertex2f(1.6, -1.0);
		glVertex2f(1.7, -1.9);
		glEnd();
		glColor3f(1.0,0.0,0.0);
	  glBegin(GL_TRIANGLES);
	  glVertex2f(-0.2, 1.0);
		glVertex2f(0.0, 1.0);
		glVertex2f(-0.1,1.9);
		glEnd();
		
  }
  
  glPopMatrix();

}


void
display(void)
{
	
  glClear(GL_COLOR_BUFFER_BIT);
 // drawstars();
  drawShip(angle);
 
  glutSwapBuffers();
  //drawstars();
}

void
idle(void)
{
  int time, delta;

  time = glutGet(GLUT_ELAPSED_TIME);
  if (resuming) {
    lastTime = time;
    resuming = 0;
  }
  if (left) {
	  delta = time - leftTime;
    angle = angle + delta * 0.4;
    leftTime = time;
  }
  if (right) {
    delta = time - rightTime;
    angle = angle - delta * 0.4;
    rightTime = time;
  }
  if (thrust) {
    delta = time - thrustTime;
    v = delta * 0.00004;
    xv = xv + cos(angle*M_PI/180.0) * v;
    yv = yv + sin(angle*M_PI/180.0) * v;
    thrustTime = time;
  }
  delta = time - lastTime;
  x = x + xv * delta;
  y = y + yv * delta;
  x = x / 40.0;
  x = (x - floor(x))*40.0;
  y = y / 40.0;
  y = (y - floor(y))*40.0;
  lastTime = time;

  glutPostWindowRedisplay(currentWindow);
}
void
visible(int vis)
{
  if (vis == GLUT_VISIBLE) {
    if (!paused) {
      glutIdleFunc(idle);
    }
  } else {
    glutIdleFunc(NULL);
  }
}
void
key(unsigned char key, int px, int py)
{
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'A':
  case 'a':
    thrust = 1;
    thrustTime = glutGet(GLUT_ELAPSED_TIME);
    break;
  case 'S':
  case 's':
    shield = 1;
    break;
  case 'C':
  case 'c':
    cursor = !cursor;
    glutSetCursor(
      cursor ? GLUT_CURSOR_INHERIT : GLUT_CURSOR_NONE);
    break;
  case 'z':
  case 'Z':
    x = 20;
    y = 20;
    xv = 0;
    yv = 0;
    break;
  case 'f':
    glutGameModeString("400x300:16@60");
    glutEnterGameMode();
    initWindow();
    break;
  case 'g':
    glutGameModeString("640x480:16@60");
    glutEnterGameMode();
    initWindow();
    break;
  case 'l':
    if (originalWindow != 0 && currentWindow != originalWindow) {
      glutLeaveGameMode();
      currentWindow = originalWindow;
    }
    break;
  case 'P':
  case 'p':
    paused = !paused;
    if (paused) {
      glutIdleFunc(NULL);
    } else {
      glutIdleFunc(idle);
      resuming = 1;
    }
    break;

  }
}
void
keyup(unsigned char key, int x, int y)
{
  switch (key) {
  case 'A':
  case 'a':
    thrust = 0;
    break;
  case 'S':
  case 's':
    shield = 0;
    break;
  }
}

void
special(int key, int x, int y)
{
  switch (key) {
  case GLUT_KEY_F1:
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    break;
  case GLUT_KEY_F2:
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_POINT_SMOOTH);
    break;
  case GLUT_KEY_UP:
    thrust = 1;
    thrustTime = glutGet(GLUT_ELAPSED_TIME);
    break;
  case GLUT_KEY_LEFT:
    left = 1;
    leftTime = glutGet(GLUT_ELAPSED_TIME);
    break;
  case GLUT_KEY_RIGHT:
    right = 1;
    rightTime = glutGet(GLUT_ELAPSED_TIME);
    break;
  }
}

void
specialup(int key, int x, int y)
{
  switch (key) {
  case GLUT_KEY_UP:
    thrust = 0;
    break;
  case GLUT_KEY_LEFT:
    left = 0;
    break;
  case GLUT_KEY_RIGHT:
    right = 0;
    break;
  }
}
void
initWindow(void)
{
  glutIgnoreKeyRepeat(1);

  glutDisplayFunc(display);
  glutVisibilityFunc(visible);
  glutKeyboardFunc(key);
  glutKeyboardUpFunc(keyup);
  glutSpecialFunc(special);
  glutSpecialUpFunc(specialup);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 40, 0, 40, 0, 40);
  glMatrixMode(GL_MODELVIEW); 
  glPointSize(3.0);

  currentWindow = glutGetWindow();
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  if (argc > 1 && !strcmp(argv[1], "-fullscreen")) {
    glutGameModeString("640x480:16@60");
    glutEnterGameMode();
  } else {
    originalWindow = glutCreateWindow("DEEP SPACE VOYAGER-1");
  }

  initWindow();

  glutMainLoop();
  return 0;
}
