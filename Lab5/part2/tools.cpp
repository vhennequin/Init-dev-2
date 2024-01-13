/// Lab5 Sorting and complexity
/// 2022-2023
/// tools.cpp file

#include <iostream>
#include "vectorSort.h"
#include "tools.h"

/// return a positive integer entered by the user
int inputInteger()
{
    int integer;
    cin >> integer ;
    while(integer <= 0)
    {
        cout << "A positive number please: ";
        cin >> integer ;
    }
    return integer;
}

/// return the initial order of the vector chosen by the user
Order inputOrder()
{
    Order myOrder;
    int number;
    do
    {
        cout<<"Choose the initial ordering of your values:" << endl;
        cout<<" 1 random" << endl;
        cout<<" 2 ascending order" << endl;
        cout<<" 3 descending order" << endl;
        cin >> number;
    } while(number< 1 || number > 3);

    switch(number)
    {
    case 1: myOrder=RANDOM; break;
    case 2: myOrder=ASCENDING; break;
    case 3: myOrder=DECREASING; break;
    default: break;
    }
    return myOrder;
}

/// return the sorting algorithm chosen by the user
Algorithm inputAlgorithm()
{
    Algorithm myAlgorithm;
    int number;
    do
    {
        cout<<"Choose the sorting algorithm:" << endl;
        cout<<"1 bubble sort" << endl;
        cout<<"2 optimized bubble sort " << endl;
        cout<<"3 selection sort " << endl;
        cout<<"4 quick sort" << endl;
        cin >> number ;
    } while(number < 1 || number > 4);

    switch(number)
    {
    case 1: myAlgorithm=BUBBLE; break;
    case 2: myAlgorithm=BUBBLE_OPT; break;
    case 3: myAlgorithm=SELECTION; break;
    case 4: myAlgorithm=QUICK; break;
    default: break;
    }
    return myAlgorithm;
}

/// Input the various parameters needed to sort :
/// number of values, maximum value, number of executions, initial order, sorting algorithm.
void sortParameters(int & nbElts, int & maxVal, int & nbExec, Order & myOrder, Algorithm & myAlgorithm)
{
    cout<<"How many integers to sort? ";
    nbElts=inputInteger();
    cout<<"\nMaximum value of integers? ";
    maxVal=inputInteger();
    cout<<"\nHow many executions ? ";
    nbExec=inputInteger();
    myOrder=inputOrder();
    myAlgorithm=inputAlgorithm();
}

/// Create a vector containing nbVal random integers ranging between theMin and theMax
void randomVector(vector<int> &v, int nbVal, int theMin, int theMax)
{
    if (theMax < theMin) /// swap
    {
        int temp = theMax;
        theMax=theMin;
        theMin=temp;
    }
    for (int i=0; i<nbVal; i++)
    {
        v.push_back(theMin + rand()%(theMax-theMin+1)); /// random number between theMin and theMax included
    }
}

/// Ask the user if she wants to start over
bool again()
{
    char answer;
    cout << "Do you want to start over? (y/n)" ;
    cin >> answer;
    return (answer == 'y');
}


