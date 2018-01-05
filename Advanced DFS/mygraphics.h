#include "stdio.h"
#include "GL/glut.h"
#include "GL/gl.h"
//#include "time.h"
#include "math.h"
void drawLine(float x1,float y1,float x2,float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}
void drawCircle(float cx,float cy,float r,int seg)
{
	float angle,x,y;
	glBegin(GL_LINE_LOOP);
	for(int i = 0; i < seg; i++)
    {
        angle = 2.0f * M_PI * (float)i / (float)seg;
        x = r * cosf(angle);
        y = r * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
	glEnd();
}
