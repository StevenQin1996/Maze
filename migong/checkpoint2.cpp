#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 7
using namespace std;


typedef struct{
	int x;
	int y;
}Point;


Point pt(int x, int y){
	Point p = {x,y};
	return p; 
}


void start( int maze[][SIZE], int &a, int &b)
{
	for (int i =0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			if (maze[i][j]==3)
			{
				 a=i;//heng zuo biao of start
				 b=j;//zhong zuo biao of start
				
			}
		}
	}
}

void end( int maze[][SIZE], int &c,int &d)
{
	for (int i =0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			if (maze[i][j]==4)
			{
				 c=i;//heng zuo biao of start
				 d=j;//zhong zuo biao of start
			}
		}
	}
}


int visit(int maze[][SIZE],Point start, Point end)
{
	maze[end.x][end.y]=0;
	if(maze[start.x][start.y] == 3 || !maze[start.x][start.y])
	{
		maze[start.x][start.y] = 1;
		if((!maze[end.x][end.y]) &&
		   !(visit(maze,pt(start.x, start.y +1),end) || 
		   visit(maze, pt(start.x+1, start.y), end) ||
		   visit(maze,pt(start.x, start.y -1), end)|| 
		   visit(maze, pt(start.x - 1, start.y),end) ) )
		{
			maze[start.x][start.y] = 0;
		}
	}
	return maze[end.x][end.y];
}

void print(int maze[][SIZE])
{
	cout << endl;
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			switch(maze[i][j])
			{
				case 3 : printf("S");break;
				case 4 : printf("F");break;
				case 0 : printf(" ");break;
				case 1 : printf(".");break;
				case 2 : printf("#");
			}
		}
		printf("\n");
	}
}


int main(void)
{

	int maze[SIZE][SIZE] = 
	{
		{2,2,2,2,2,2,2},
		{2,0,3,0,0,0,2},
		{2,0,2,0,2,2,2},
		{2,0,0,2,0,2,2},
		{2,2,0,2,4,2,2},
		{2,0,0,0,0,0,2},
		{2,2,2,2,2,2,2},
	};

	int a=0,b=0,c=0,d=0;
	start(maze,a,b);
	end(maze,c,d);
	cout<<"("<<a<<", "<<b<<"), ("<<c<<", "<<d<<")"<<endl;
	cout << !maze[4][4] << endl;
	if (!visit(maze, pt(1,2), pt(4,4)))
	{
		printf("No way out.\n");
	}

	else
	{
		print(maze);
		system("pause");
		return 0;
	}
	
}










