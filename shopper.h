/*
  Name: Junyue Lu
  File name: shopper.h
*/

#include <iostream>
#include <random>
#include "ArrayQueue.h"


class Shopper
{
	private:
	long int loyalty;
	int cartSize;
	int priority;

	public:
	Shopper();
	Shopper(int);
	//Shopper operator=(const Shopper &right);

	friend bool operator<(const Shopper &left, const Shopper &right);
	friend bool operator>(const Shopper &left, const Shopper &right);
	

	template <class T>
	friend class priorityQueueSort;

	template <class T>
	friend class priorityQueueSearch;

};




