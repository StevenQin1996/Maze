#include <iostream>
#include <iomanip>
//#include <fstream>
using namespace std;

template <class T>
struct Queue
{
	T* data;
	int size;
	int head;
	int tail;
};

template <class T>
void initialize(Queue<T>& Q)
{
	Q.size=2;
	Q.head=0;
	Q.tail=0;
	Q.data = new T[Q.size];
}

template <class T>
void destroy(Queue<T>& Q)
{
	//initialize(Q);
	delete [] Q.data;
	Q.data = NULL;
	Q.size=2;
	Q.head=0;
	Q.tail=0;

}

template <class T>
int  getSize(Queue<T> Q)
{
	int count=0;
	if(Q.tail>=Q.head)
		count = Q.tail-Q.head;
	else
	 	count = Q.tail+ (Q.size - Q.head);
	return count;
}

template <class T>
bool isEmpty(Queue<T> Q)
{
	return (getSize(Q)==0);
}

template <class T>
void push(Queue<T>& Q, T n)
{
	if (getSize(Q) == Q.size-1)
	{
		
	 	T* stupid = new T[Q.size*2];
	
		for (int x=0; x < Q.size; x++)
		{
			stupid[x]=Q.data[Q.head++];

			if (Q.head == Q.size)
				Q.head=0;
		} 
		Q.tail = Q.size-1;
		Q.head = 0;
		Q.size = Q.size * 2;

		delete [] Q.data;
		Q.data = stupid;
	}


	Q.data[Q.tail]= n;
	Q.tail++;

	if (Q.tail==Q.size )
	{
		Q.tail=0;
	}
	
}

template <class T>
T    pop(Queue<T>& Q)
{
	T temp=Q.data[Q.head];
	Q.head++;
	if (Q.head==Q.size)
	{
		Q.head=0;
	}
	return temp;
}	