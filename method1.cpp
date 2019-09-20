// maze solver - breadth-first search

#include <iostream>
#include <fstream>
#include "p2queue.h"
using namespace std;

/************************************/
// Path definition and functions
/************************************/

struct Path {
   string maze;
   int width;
   int steps[500]; // ordered list of steps
   int length; // how many steps
};

// Read maze from file, initialize path with starting location
void initialize(Path &p, string filename)
{
   ifstream fin; // Create input stream using file
   string line;

   // Assume file exists, is properly formatted, etc.
   fin.open(filename.c_str()); // Open file of given name 

   p.maze = "";
   fin >> p.width;
   for( int r = 0; r < p.width; r++ )
   {
      fin >> line;
      p.maze += line;
   }
   fin.close();   

   // Find starting index
   int start = 0;
   while( p.maze[start] != 'S' ) 
   start++;
   // Initialize path to starting index, length 1
   p.steps[0] = start;
   p.length = 1;
}

// Copy A to B
void initialize( Path A, Path &B)
{
   B.maze  = A.maze;
   B.width = A.width;
   for( int i = 0; i < A.length; i++ )
   B.steps[i] = A.steps[i];
   B.length = A.length;
}

// Given: path, current location, direction of proposed step (N/S/E/W)
int findIndex(Path p, char dir)
{
   int loc = p.steps[p.length-1]; // current location
   // Find index of proposed step (0 if invalid direction)
   return (dir=='N')*(loc-p.width) + (dir=='S')*(loc+p.width) + 
          (dir=='W')*(loc-1)       + (dir=='E')*(loc+1);
}

// Assume step has already been checked using isGoodStep
void takeStep( Path &p, char direction)
{
   p.steps[p.length++] = findIndex(p,direction);
}

bool isFinished(Path p)
{
   return p.maze[p.steps[p.length-1]] == 'F';
}

// Given: path, current location, direction of proposed step (N/S/E/W)
// Return evaluation of whether good step (not wall, starting point or repeated step)
bool isGoodStep(Path p, char direction)
{
   // Find index of proposed step (0 if invalid direction)
   int index = findIndex(p,direction);

   if( p.maze[index] == 'X' || p.maze[index] == 'S' ) // wall, start
   return false;
   for( int i = 0; i < p.length; i++ )
      if( p.steps[i] == index )
        return false;
   // else, not a wall and not already visited
   return true;
}

ostream& operator<< (ostream& out, Path p)
{
   string directions = "?NSEW";
   for( int i = 1; i < p.length; i++ )
   {
      int diff = p.steps[i-1]-p.steps[i];
      out << directions[(diff==p.width)*1 + (diff==-p.width)*2 + (diff==-1)*3 + (diff==1)*4];
   }
   return out;
}

/************************************/
// Main function
/************************************/

int main()
{
   Queue trails;
   initialize(trails);
   
   string filename;
   cin >> filename;   
   
   // Initialize first path
   Path p;
   initialize(p,filename);
   push(trails,p);
   
   while( true )
   {
      if( isEmpty(trails) )
      {
         cout << "No path.\n";
         break;
      }

      p = pop(trails); // get next partial path to check

      // Stop when path stretches START to FINISH
      if( isFinished(p) )
      {
         cout << p << endl;
         break;
      }

      string directions = "NSEW";
      for( int i = 0; i < 4; i++ )
         if( isGoodStep(p,directions[i]) )
         {
            Path copy;
            initialize(p,copy);  
            takeStep(copy,directions[i]);
            push(trails,copy);
         }
   }
   destroy(trails);
}