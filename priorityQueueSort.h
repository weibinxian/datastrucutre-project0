/*
  Name: Junyue Lu
  File name: priorityQueueSort.h
*/

#include<iostream>
#include "ArrayQueue.h"

using namespace ods;

template<class T>
class priorityQueueSort:public ArrayQueue <T>
{
	public:
	bool add(T x);
	T remove();
	void sort();
	void displayArray();
	int getPriority(T x);
};



template<class T>
bool priorityQueueSort<T>::add(T x)
{
	 if (ArrayQueue<T>::n + 1 > ArrayQueue<T>::a.length) ArrayQueue<T>::resize();
	 ArrayQueue<T>::a[(ArrayQueue<T>::j+ArrayQueue<T>::n) % ArrayQueue<T>::a.length] = x;
	 ArrayQueue<T>::n++;

	 return true;
}


template<class T>
T priorityQueueSort<T>::remove()
{
    T x = ArrayQueue<T>::a[ArrayQueue<T>::j];
    ArrayQueue<T>::j = (ArrayQueue<T>::j+1) % ArrayQueue<T>::a.length;
    ArrayQueue<T>::n--;
    if (ArrayQueue<T>::a.length >= 3*ArrayQueue<T>::n)
        ArrayQueue<T>::resize();
    return x;
}


template<class T>
void priorityQueueSort<T>::sort()
{
    for (int i=0; i < ArrayQueue<T>::n-1; i++)
        for (int k=0; k < ArrayQueue<T>::n-i-1; k++){
            if (ArrayQueue<T>::a[k] > ArrayQueue<T>::a[k+1]){
		T temp = ArrayQueue<T>::a[k];
		ArrayQueue<T>::a[k] = ArrayQueue<T>::a[k+1];
		ArrayQueue<T>::a[k+1] = temp;
		}
	}
    return;
}


template<class T>
void priorityQueueSort<T>::displayArray()
{
	for (int i=ArrayQueue<T>::j; i<ArrayQueue<T>::n; i++)
	std::cout<<ArrayQueue<T>::a[i] << " ";
	
	return;
}


template<class T>
int priorityQueueSort<T>::getPriority(T x)
{	
	return x.priority;
}


