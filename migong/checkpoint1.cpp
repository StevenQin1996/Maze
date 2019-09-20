#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#define SIZE 7

typedef struct{
	int x;
	int y;
}Point;

Point pt(int x, int y){
	Point p = {x,y};
	return p; 
}

int visit(int maze[][SIZE],Point start,Point end)
{
	if(!maze[start.x][start.y])
	{
		maze[start.x][start.y] = 1;
		if(!maze[end.x][end.y] &&
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
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			switch(maze[i][j])
			{
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
		{2,0,0,0,0,0,2},
		{2,0,2,0,2,2,2},
		{2,0,0,2,0,2,2},
		{2,2,0,2,0,2,2},
		{2,0,0,0,0,0,2},
		{2,2,2,2,2,2,2},
	};

	if (!visit(maze, pt(1,2), pt(4,4))){
		printf("No way out.\n");
	}

	else
	{
		print(maze);
		system("pause");
		return 0;
	}
	
}










