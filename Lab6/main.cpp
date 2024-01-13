#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "chocolate.h"
#include "chocolatebox.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Chocolate c1("white",20); // a white chocolate weighing 20g
    Chocolate c2; // a dark chocolate weighing 30g
    Chocolate c3(10); // a chocolate weighing 10g, with a random type
    Chocolate c4("white"); // a white chocolate weighing 30g

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    bool res;
    res = c1 < c2;
    if (res) cout << "Chocolate 1 is heavier than Chocolate 2" << endl;
    else  cout << "Chocolate 2 is heavier than Chocolate 1" << endl;

    ChocolateBox cb1;
    cout << cb1 << endl;
    cb1.addChocolate(c4);
    cout << cb1 << endl;
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cb1.eatChocolate();
    cout << cb1 << endl;
    cout << "The weight of the box is: " << cb1.theWeight() << endl;
    return 0;
}
