#include <iostream>
#include <chrono>
#include <random>
#include "priorityQueueSort.h"
#include "priorityQueueSearch.h"
#include "ArrayQueue.h"
#include "shopper.h"

using namespace ods;
using namespace std;

const int number=5000;

int main()
{
    // produces random #s between 0 and 1
    default_random_engine generator;
    // converts those to equally-likely ints between 1 and 10
    uniform_int_distribution<int> distribution(1,10);

    priorityQueueSort <int> arraySort;
    auto start1 = chrono::steady_clock::now();
    for (int i=0; i<number; i++){
        int priority1 = distribution(generator);
        arraySort.add(priority1);
    }
    arraySort.sort();
    auto end1 = chrono::steady_clock::now();
    auto diff1 = end1 - start1;
    cout << "priority queue sort add ints: " << chrono::duration <double, milli> (diff1).count() << " ms" << endl;
    //arraySort.displayArray();

    auto start2 = chrono::steady_clock::now();
    for (int i=0; i<number; i++)
        arraySort.remove();

    auto end2 = chrono::steady_clock::now();
    auto diff2 = end2 - start2;
    cout << "priority queue sort remove ints: " << chrono::duration <double, milli> (diff2).count() << " ms" << endl;

    priorityQueueSearch <int> arraySearch;
    auto start3 = chrono::steady_clock::now();
    for (int i=0; i<number; i++){
        int priority1 = distribution(generator);
        arraySearch.add(priority1);
    }
    auto end3 = chrono::steady_clock::now();
    auto diff3 = end3 - start3;
    cout << "priority queue search add ints: " << chrono::duration <double, milli> (diff3).count() << " ms" << endl;
    //arraySearch.displayArray();

    auto start4 = chrono::steady_clock::now();
    for (int i=0; i<number; i++)
        arraySearch.remove();

    auto end4 = chrono::steady_clock::now();
    auto diff4 = end4 - start4;
    cout << "priority queue search remove ints: " << chrono::duration <double, milli> (diff4).count() << " ms" << endl;



    priorityQueueSort <Shopper> PQSortShopper;
    auto start5 = chrono::steady_clock::now();
    for (int i=0; i<number; i++){
        int priority2 = distribution(generator);
        Shopper shopper1(priority2);
        PQSortShopper.add(shopper1);
        //cout << PQSortShopper.getPriority(shopper1) << " ";
    }
    PQSortShopper.sort();

    auto end5 = chrono::steady_clock::now();
    auto diff5 = end5 - start5;
    cout << "priority queue sort add shoppers: " << chrono::duration <double, milli> (diff5).count() << " ms" << endl;



    auto start6 = chrono::steady_clock::now();
    for (int i=0; i<number; i++)
        PQSortShopper.remove();

    auto end6 = chrono::steady_clock::now();
    auto diff6 = end6 - start6;
    cout << "priority queue sort remove shoppers: " << chrono::duration <double, milli> (diff6).count() << " ms" << endl;


    priorityQueueSearch <Shopper> PQSearchShopper;
    auto start7 = chrono::steady_clock::now();
    for (int i=0; i<number; i++){
        int priority2 = distribution(generator);
        Shopper shopper2(priority2);
        PQSearchShopper.add(shopper2);
        //cout << PQSearchShopper.getPriority(shopper2) << " ";
    }
    auto end7 = chrono::steady_clock::now();
    auto diff7 = end7 - start7;
    cout << "priority queue sort add shoppers: " << chrono::duration <double, milli> (diff7).count() << " ms" << endl;

    auto start8 = chrono::steady_clock::now();
    for (int i=0; i<number; i++)
        PQSearchShopper.remove();

    auto end8 = chrono::steady_clock::now();
    auto diff8 = end8 - start8;
    cout << "priority queue search remove ints: " << chrono::duration <double, milli> (diff8).count() << " ms" << endl;

}
