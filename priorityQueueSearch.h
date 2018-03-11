/*
  Name: Junyue Lu
  File name: priorityQueueSearch.h
*/

#include<iostream>
#include "ArrayQueue.h"

using namespace ods;

template<class T>
class priorityQueueSearch:public ArrayQueue <T>
{
	public:
	bool add(T x);
	T remove();
	int searchMin();
	void displayArray();
	int getPriority(T x);
};



template<class T>
bool priorityQueueSearch<T>::add(T x)
{
	 if (ArrayQueue<T>::n + 1 > ArrayQueue<T>::a.length) ArrayQueue<T>::resize();
	 ArrayQueue<T>::a[(ArrayQueue<T>::j+ArrayQueue<T>::n) % ArrayQueue<T>::a.length] = x;
	 ArrayQueue<T>::n++;
	 return true;
}


template<class T>
T priorityQueueSearch<T>::remove()
{	
	int min = searchMin();
	T x = ArrayQueue<T>::a[min];
	for (int i=min; i < ArrayQueue<T>::n-1; i++)
  	ArrayQueue<T>::a[i] = ArrayQueue<T>::a[i + 1];
	ArrayQueue<T>::n--;
	if (ArrayQueue<T>::a.length >= 3 * ArrayQueue<T>::n) ArrayQueue<T>::resize();

	return x;
}


template<class T>
int priorityQueueSearch<T>::searchMin()
{
	T min = ArrayQueue<T>::a[ArrayQueue<T>::j];
	int minIndex = ArrayQueue<T>::j;
	for (int i = ArrayQueue<T>::j; i < ArrayQueue<T>::n-1; i++){
	if (ArrayQueue<T>::a[i+1] < min) {
		min = ArrayQueue<T>::a[i+1];
		minIndex = i+1;
}
}
	return minIndex;
}


template<class T>
void priorityQueueSearch<T>::displayArray()
{
	for (int i=ArrayQueue<T>::j; i<ArrayQueue<T>::n; i++)
	std::cout<<ArrayQueue<T>::a[i] << " ";

	return;
}


template<class T>
int priorityQueueSearch<T>::getPriority(T x)
{	
	return x.priority;
}



