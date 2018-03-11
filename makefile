project0: main.o priorityQueueSort.o priorityQueueSearch.o shopper.o
	g++ -std=c++11 -o project0 main.o priorityQueueSort.o priorityQueueSearch.o shopper.o

main.o: main.cpp priorityQueueSort.h priorityQueueSearch.h ArrayQueue.h shopper.h
	g++ -std=c++11 -c main.cpp

priorityQueueSort.o: priorityQueueSort.cpp priorityQueueSort.h
	g++ -std=c++11 -c priorityQueueSort.cpp

priorityQueueSearch.o: priorityQueueSearch.cpp priorityQueueSearch.h
	g++ -std=c++11 -c priorityQueueSearch.cpp

shopper.o: shopper.cpp shopper.h
	g++ -std=c++11 -c shopper.cpp
