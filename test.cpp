# include <iostream>
# include <iomanip>
#include <fstream>
# include "p2queue.h"
using namespace std;
struct Path{
	string maze;
	int width;//size of the maze;
	int location[500];
	int length;
};

void start(Path& P, string filename)
{
	ifstream fin;//• accept	new	Path	and	filename	as	arguments
	fin.open(filename.c_str());

	if( fin.is_open())
	{
		P.length = 0;
		string s;
		P.maze = "";

		fin>>P.width;
		for (int a=0; a<P.width; a++)//• read	maze	from	file	into	maze	field	in	Path
		{
			fin>>s;
			P.maze += s;
			
		}
		for (int b=0; b<P.width*P.width; b++)
		{
			if (P.maze[b] == 'S')
			{
				P.location[0] = b;//array which holds the path ---- output;
				P.length ++ ; //index of location

				break;
			}
			
		}
		
	}

	fin.close();
}

bool isFinished(Path P)
//accept Path as argument
//indicate	(T/F)	if	Path	has	reached	finish	point	in	maze
{
	for (int c=0; c<P.width*P.width; c++)
	{
		if(P.maze[c] == 'F')
		{
			//cout<<c;
			for (int m=0; m<P.length; m++)
			{
				if(P.location[m] == c)
					return true;
			}
		}
	}
	return false;
}

ostream& operator<<(ostream& out, Path P)//overload	output	operator	to	display	Path
{
	for (int d=0; d<P.length; d++)
	{
		if ((P.location[d]) + 1 == P.location[d+1])//iterate	through	Path	locations,	display	each	as	directional	step	from	previous	location
			out<<'E';
		else if ((P.location[d]) - 1 == P.location[d+1])//iterate	through	Path	locations,	display	each	as	directional	step	from	previous	location
			out<<'W';
		else if ((P.location[d]) - P.width == P.location[d+1])//iterate	through	Path	locations,	display	each	as	directional	step	from	previous	location
			out<<'N';
		else if ((P.location[d]) + P.width == P.location[d+1])//iterate	through	Path	locations,	display	each	as	directional	step	from	previous	location
			out<<'S';
	}
		
	//(so	initial	location	– start	– does	not	show	in	output)
	return out;//return	ostream	reference
}

void copyPath(Path a, Path& b)
{
	b.maze = a.maze;
	b.width = a.width;//size of the maze;

	b.length = a.length;
	for (int n=0; n<=b.length;n++)
	{
		b.location[n] = a.location[n];
	}
	//accept	two	Paths as	arguments,	copies	contents	of	a into	b so	the	two	Paths	are	identical
	
}


bool isGoodstep(Path P, char direction)
{	
	if(direction == 'E' )//currentlocation should be a point which point to the current location.
	{
		if (P.maze[P.location[P.length-1]+1]  == 'X')
		{
			return false;
		}
		else
		{
			for (int n=0; n<P.width*P.width; n++)
			{
				if ((P.location[P.length-1]+1) == P.location[n])
					return false;
			}
			
			return true;
		}
	}
	else if(direction == 'W' )
	{
		if (P.maze[P.location[P.length-1]-1]  == 'X')
			return false;
		else 
		{
			for (int n=0; n<P.width*P.width; n++)
			{
				if ((P.location[P.length-1]-1) == P.location[n])
					return false;
			}
			//cout<<2;
			return true;
		}
	}
	else if(direction == 'N')
	{
		if (P.maze[P.location[P.length-1] - P.width] == 'X')
			return false;
		else
		{
			for (int n=0;n<P.width*P.width; n++)
			{
				if ((P.location[P.length-1]-P.width) == P.location[n])
					return false;
			}
			//cout << ;
			return true;
		}
	}
	else if(direction == 'S')
	{
		if (P.maze[P.location[P.length-1]+ P.width]  == 'X')
			return false;
		else
		{
			for (int n=0; n<P.width*P.width; n++)
			{
				if ((P.location[P.length-1] + P.width) == P.location[n])
					return false;
			}
			//cout<<4;
			return true;
		}
	}
	return 0;
}

void takeStep(Path& P, char direction)
{
	if (direction=='E')
	{
		P.location[P.length] = P.location[P.length-1] + 1;
		P.length++;
	}
	if (direction == 'W')
	{
		P.location[P.length] = P.location[P.length-1] - 1;
		P.length++;
	}
	if (direction == 'N')
		{
			P.location[P.length] = P.location[P.length-1] - P.width;
			P.length++;
		}
	if (direction == 'S')
		{
			P.location[P.length] = P.location[P.length-1] + P.width;
			P.length++;
		}

	
}

int main()
{
	char array[4]= {'E','W','N','S'};
	Queue<Path> Q;
    initialize(Q);

	string filename;
	cout<<"Enter filename."<<endl;
	cin>>filename;

	Path P;
	Path* b;

	Path temp;

	start(P, filename);
	
	push(Q,P);
	//pop(Q);

	//copyPath(P, *b);
	
	while(!isEmpty(Q))
	{
		//cout<<1;
		temp = pop(Q);
		if(isFinished(temp))
		{
		//	cout<<2;
			cout<<temp<<endl;
			break;
		}//cout<<P<<endl;
		
		else 
		{
 			for (int n=0; n<4; n++)
			{
				if(isGoodstep(temp, array[n]))
				{ 
					//cout << array[n];
					b = new Path();
					copyPath(temp, *b);
					takeStep(*b,array[n]);
					push(Q, *b);
					delete b;
					b = NULL;
				}
			}
		}
	}

	if(!isFinished(temp) && isEmpty(Q))
		cout<<"No path."<<endl;
	destroy(Q);

}

