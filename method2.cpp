// maze solver

#include <iostream>
#include <fstream>
#include "p2stack.h"
using namespace std;

int maze[10000];
int width;
int finish;
const int INFINITE = 20000;

// Return starting index
int input()
{
   int start; 
   
   ifstream fin; // Create input stream using file
   string filename;
   string layout = "";
   
   cin >> filename;
   
   // Assume file exists, is properly formatted, etc.
   fin.open(filename.c_str()); // Open file of given name
   
   fin >> width; // width/height of one wall

   string row;
   for( int i = 0; i < width; i++ ) {
      fin >> row;
      layout += row;
   }    
   
   for( int i = 0; i < width*width; i++ )
      if( layout[i] == 'X' ) // wall
         maze[i] = -1;
      else if( layout[i] == 'S' ) {
         maze[i] = 0;
         start = i;
      }
      else if( layout[i] == '.' )
         maze[i] = INFINITE;
      else { // 'F'
         maze[i] = INFINITE;
         finish = i;
      }
   
   return start;
}

int main()
{
   Stack<int> points;
   initialize(points);
   
   push(points,input()); // push starting location
   
   while( !isEmpty(points) )
   {
      int p = pop(points);
      
      if( maze[p-width] > maze[p] + 1 ) { // north
         maze[p-width] = maze[p] + 1;
         push(points,p-width);
      }
      if( maze[p+width] > maze[p] + 1 ) { // south
         maze[p+width] = maze[p] + 1;
         push(points,p+width);
      }      
      if( maze[p+1] > maze[p] + 1 ) { // east
         maze[p+1] = maze[p] + 1;
         push(points,p+1);
      }
      if( maze[p-1] > maze[p] + 1 ) { // west
         maze[p-1] = maze[p] + 1;
         push(points,p-1);
      }      
   }
   
    // if finish not reached, no path exits
   if( maze[finish] == INFINITE )
       cout << "No path.\n";
   else
   {
      string path = "";
      int p = finish;
      while( maze[p] != 0 )
      {
         if( maze[p-width] == maze[p] - 1 ) { // came from north
             p -= width;
             path = "S" + path;
         }
         else if( maze[p+width] == maze[p] - 1 ) { // came from south
             p += width;
             path = "N" + path;
         }      
         else if( maze[p+1] == maze[p] - 1 ) { // came from east
             p += 1;
             path = "W" + path;
         }
         else { // came from west
             p -= 1;
             path = "E" + path;
         }         
      }   
      cout << endl << path << endl;
   }
}