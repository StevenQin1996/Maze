#include "queue-provided.h"
#include <iostream>
using namespace std;

const int PQSIZE = 11;
   
template <class T>
struct PriorityQueue {
   Queue<T> array[PQSIZE];
};
   
template <class T>
void initialize(PriorityQueue<T>& PQ)
{
	for (int n=0; n<11; n++)
		initialize(PQ.array[n]);

}
template <class T>
void destroy(PriorityQueue<T>& PQ)
{
	initialize (PQ);
}

template <class T>
 int getSize(PriorityQueue<T> PQ)
{
	int size=0;
	for (int n=0; n<11; n++)
	{
		size += getSize(PQ.array[n]);
	}
	return size;
}

template <class T>
bool isEmpty(PriorityQueue<T> PQ)
{
	return (getSize(PQ)==0);
}

template <class T>
void push(PriorityQueue<T>& PQ,T input,int set)
{
//	for (int n=0; n<11; n++)
//	{
//		if (PQ.array[n]==set)
			push(PQ.array[set], input);
///	}	
}

template <class T>
T    pop(PriorityQueue<T>& PQ)
{
  for (int n=10; n>=0; n--)
  {
  	if (!isEmpty(PQ.array[n]))
  		return pop(PQ.array[n]);
  }
  return 0;
}