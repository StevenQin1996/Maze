#include <iostream>
//#include <fstream>
using namespace std;

const int SIZE = 5;

template <class T>
struct Queue
{
	T data[SIZE];
	int head;
	int tail;
};

template <class T>
void initialize(Queue<T>& Q)
{
	Q.head=0;
	Q.tail=0;
}

template <class T>
void destroy(Queue<T>& Q)
{
	initialize(Q);
}

template <class T>
int  getSize(Queue<T> Q)
{
	int count=0;
	if(Q.tail>=Q.head)
		count = Q.tail-Q.head;
	else
	 	count = Q.tail+ (SIZE - Q.head);
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
	Q.data[Q.tail]= n;
	//if(Q.tail++ != Q.head)
		Q.tail++;
	if (Q.tail==5 )
	{
		//`if (Q.head!=0)
			Q.tail=0;
	}
}

template <class T>
T    pop(Queue<T>& Q)
{
	T temp=Q.data[Q.head];
	Q.head++;
	if (Q.head==5)
	{
		Q.head=0;
	}
	return temp;
}	