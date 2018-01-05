/*
 * to compile:
 * gcc tictactoeGraphical.c -o tictactoeGraphical.c.o -lGL -lglut -lm
 *
 * to run:
 * ./tictactoeGraphical.c.o
*/
#include<GL/glut.h>
#include<GL/gl.h>
#include<time.h>
#include<stdio.h>
#include "math.h"
#define SIZE 3
int table[SIZE][SIZE];
float two_by_three=2.0/3.0;
void resetTable()
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			table[i][j]=-SIZE;
}
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
void drawCross(float cx,float cy,float size)
{
	drawLine(cx+size,cy+size,cx-size,cy-size);
	drawLine(cx+size,cy-size,cx-size,cy+size);
}
int chance=0;
void generateTable()
{
	// for(int i=0;i<SIZE/2;i++)
	// {
	// 	drawLine(1.0/SIZE*i,-1,1.0/SIZE*i,1);
	// }
	drawLine(-1.0/3.0 ,-1 , -1.0/3.0 , 1);
	drawLine(1.0/3.0 ,-1 , 1.0/3.0 , 1);
	drawLine(-1 ,-1.0/3.0 , 1 , -1.0/3.0);
	drawLine(-1 ,1.0/3.0 , 1 , 1.0/3.0);
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
		{
			glRasterPos2f(+two_by_three*(float)((i*SIZE+j)%SIZE-1),-two_by_three*(float)((i*SIZE+j)/SIZE-1));
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,i*SIZE+j+'0');						
			if(table[i][j]==0)
				drawCircle(+two_by_three*(float)((i*SIZE+j)%SIZE-1),-two_by_three*(float)((i*SIZE+j)/SIZE-1),0.25,35);
			else if(table[i][j]==1)
				drawCross(+two_by_three*(float)((i*SIZE+j)%SIZE-1),-two_by_three*(float)((i*SIZE+j)/SIZE-1),0.25);
		}
}
void display()
{
	printf("Player %d's chance!\n",chance%2);
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLineWidth(1.0); 
	generateTable();
	glFlush();
}
int win()
{
	glColor3f(0,1,0);
	int result[2]={0,0};
	for(int i=0;i<SIZE;i++,result[0]=0,result[1]=0)
	{
		for(int j=0;j<SIZE;j++)
			result[0]+=table[i][j],result[1]+=table[j][i];
		if(result[0]==3 || result[0]==0)
			drawLine(-1,-(i%SIZE-1)*two_by_three,1,-(i%SIZE-1)*two_by_three);
		if(result[1]==3 || result[1]==0)
			drawLine((i%SIZE-1)*two_by_three,-1,(i%SIZE-1)*two_by_three,1);
		if(result[0]==3||result[1]==3)
			return 1;
		if(result[0]==0||result[1]==0)
			return 0;
	}
	for(int i=0;i<SIZE;i++)
		result[0]+=table[i][i],result[1]+=table[SIZE-i-1][i];
	if(result[0]==3||result[0]==0)
		drawLine(-1,1,1,-1);
	if(result[1]==3||result[1]==0)
		drawLine(-1,-1,1,1);
	if(result[0]==3 || result[1]==3)
		return 1;
	if(result[0]==0 || result[1]==0)
		return 0;
	return -1;
}
int game=1;
void keyPressed(unsigned char key,int x, int y)
{
	if(key==27)
		exit(0);
	if(game==0)
		return;
	printf("Key %c (%d) is pressed! Mouse was at: (%d, %d)\n",key,key,x,y);
	glClear(GL_COLOR_BUFFER_BIT);
	int tabX=(key-'0')/SIZE,tabY=(key-'0')%SIZE;
	if(table[tabX][tabY]==-SIZE)
		table[tabX][tabY]=chance++%2;
	generateTable();
	int winStatus=win();
	glColor3f(1,1,1);	
	if(winStatus==0)
	{
		printf("Player 0 won!");
		game=0;
	}
	else if(winStatus==1)
	{
		printf("Player 1 won!");
		game=0;
	}
	glFlush();
	printf("Player %d's chance!\n",chance%2);
}
void main(int argc, char**argv) 
{
	resetTable();
	srand(time (NULL));
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Tic Tac Toe -By Harshal :)");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
}