#include <iostream>
#include <fstream>
using namespace std;
    
const int SIZE = 100;
	
template <class T>
struct Queue {
   T   data[SIZE];
   int tail;
};

template <class T>	
void initialize(Queue<T>& Q)
{
	Q.tail=0; 
}

template <class T>
void destroy(Queue<T>& Q) 
{
	Q.tail=0; 
}

template <class T>
int getSize(Queue<T> Q)
{
	int count = Q.tail;
	return count;
}

template <class T>
bool isEmpty(Queue<T> Q)
{
	return (getSize(Q) == 0);
}

template <class T>
void push(Queue<T>& Q, T n)
{
	Q.data[Q.tail]= n;
	
	Q.tail++;
}

template <class T>
T    pop(Queue<T>& Q)
{
		T temp = Q.data[0];
		for (int n=1; n<Q.tail;n++)
		{
			Q.data[n-1]=Q.data[n];
		}
		Q.tail--;
		return temp;
}	