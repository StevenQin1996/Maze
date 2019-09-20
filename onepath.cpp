#include <iostream>
// use priorityqueue to make a array of queue, whenever we see a new path
// copy and past the previous one to the newt open space in the array
# include <iomanip>
# include "p2queue.h"
using namespace std;

template <class T> 
struct Path{
	string maze;
	int width;//size of the maze;
	int **location[500];
	int length;
	
};

template <class T>
void initialize(Path<T>& P)
{
	int size=2;
	P.length=0;
};

template <class T>
void start(Path& P, string filename)
{
	ifstream fin;//• accept	new	Path	and	filename	as	arguments
	fin.open(filename.c_str());

	if( fin.is_open())
	{
		while(fin>>maze)//• read	maze	from	file	into	maze	field	in	Path
		{
			fin>>maze;
			if (maze = "S")//find	starting	point	in	maze,	intialize	Path	to	have	that	one	location	and	length	of	1
			{
				Push(P,"S")//array which holds the path ---- output;
				P.length = 1; //index of location
			}
		}
	}
}

bool isFinished(Path P)
//accept Path as argument
//indicate	(T/F)	if	Path	has	reached	finish	point	in	maze
{
	T r=Pop(P.location);
	if (r==F)
		return (isFinished);
}

template <class T>
ostream& operator<<(ostream& out, Path P)//overload	output	operator	to	display	Path
{
	if (isFinished(P))
		{
		for (int n = 1; P.location[n] != 0; n++)//iterate	through	Path	locations,	display	each	as	directional	step	from	previous	location
			out<<P.location[n];//(so	initial	location	– start	– does	not	show	in	output)
		}
	return out;//return	ostream	reference
}

template <class T>
void copyPath(Path a, Path& b)
{
	for (int n=0; n<P.length; n++)
	{
		b[n]= P.location[n];//accept	two	Paths as	arguments,	copies	contents	of	a into	b so	the	two	Paths	are	identical
	}
}

/*template <class T>
void hasbeen(Path P, char direction)
{
	for (int n=0; n<P.length; n++)
	{
		if (direction == "N")
	}
}*/

template <class T>
bool isGoodstep(Path P, char direction)
{
	if(direction == "E" )//currentlocation should be a point which point to the current location.
	{
		if (P.location +1 != "X" && P.location[P.length-1] != "W")
			return  true;
		else 
			return false;
	}
	if(direction == "W" )
	{
		if (P.location -1 != "X" && P.location[P.length-1] != "E")
			return  true;
		else 
			return false;
	}
	if(direction == "N")
	{
		if (P.location +P.width != "X" && P.location[P.length-1] != "S")
			return true;
		else 
			return false;
	}
	if(direction == "S" )
	{
		if (P.location -P.width != "X" && P.location[P.length-1] != "N")
			return true;
		else 
			return false;
	}

}

template <class T>
void takeStep(Path& P, char direction)
{
		
	while(!isFinished(P))
	{
		int arraydirection[4]={"N,S,E,W"};
		for (int n=0; n<4; n++)
		{
			if (isGoodstep(arraydirection[n]))
			{
				for()
			}
		}
	}	
	
}

int main()
{
	initialize(P);
	ifstream fin;
	string filename;
	cin>>filename;

	fin.open(filename.c_str())

	if (fin.is_open)
	{
		start(P, filename);
		while (!isEmpty(P))
		{
			Pop(P);
			
			if (end=="Yes")
				break;//if true, break out of the loop and output the path (using <<)
			
			if (isGoodstep("N"))
			{

			}

			if(isGoodstep("S"))
			{

			}

			if(isGoodstep("E"))
			{

			}

			if(isGoodstep("W"))
			{
				
			}

		}
		
	}
	else 
		cout<<"File not exist. "<<endl;

}