#include <cstdlib>
#include <iostream>
#include <fstream>
#include "rat.h"

using namespace std;

int main()
{
    cout << "----- Automatic Tests -----------------------------------------------" << endl;
    if (testEmptyConstructorAndGetters()) cout << "Empty constructor and getters ok" << endl;
    if (testConstructorParamAndGetters()) cout << "Constructor with parameters and getters ok" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    cout << "----- Main program ----------------------------------------------" << endl;
    cout << "Please enter the numerator and denominator" << endl;
    //int n, d;
    //cin >> n >> d;
    try
    {
        Rational r;
        cin >> r;
        cout << "Here is your reduced rational: ";
        cout << r;
        cout << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error : " << e.what() << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    Rational r(5, 5);
    Rational t(4, 5);
    r = r * t;
    cout << r;
    Rational s(20, 25);
    bool same;
    same = (s == t);
    if (same) cout << "same rationals" << endl;
    else cout << "not the same" << endl;
    Rational x(2,3);
    s = -x;
    cout << s << endl;
    r = t + x;
    cout << r;
    Rational a(1,2);
    Rational b(49,100);
    bool smaller;
    smaller = (a < b);
    if (smaller) cout << "a < b" << endl;
    else cout << "b < a" << endl;

    Rational r1(5,7);
    Rational r2(4,9);
    r2 = r1 * 3; // it compiles and give the right result.
    cout << r2;
    r2 = 3 * r1; // it doesn't compile because the left member is an int and not a rational.
    cout << r2;
    bool not_same;
    not_same = (r1 != r2);
    if (smaller) cout << "not the same" << endl;
    else cout << "same" << endl;
    return 0;
}

// Didn't have the time for part 2 question 6
