#include <iostream>
#include <stdexcept>
#include "rat.h"
using namespace std;

Rational::Rational(int num, int den)
{
    if (den==0) throw invalid_argument("Nul denominator");
    if (den > 0)
    {
        _num = num;
        _den = den;
    }
    else
    {
        _num = -num;
        _den = -den;
    }
    _reduce();
}

void Rational::_reduce()
{
    int factor = gcd(_num, _den); // common factor
    _num /= factor;
    _den /= factor;
}

void Rational::display() const
{
    cout << _num << '/' << _den << endl;
}

int Rational::getNum() const
{
    return _num;
}

int Rational::getDen() const
{
    return _den;
}

int gcd(int a, int b)      // uses recursiveGCD
{
    int a2 = (a > 0) ? a : -a;
    if (a2 < b)
    {
        int temp = a2;
        a2 = b;
        b = temp;
    }
    return recursiveGCD(a2, b);
}

int recursiveGCD(int a, int b)      // uses Euclide's algorithm
{
    return (b==0) ? a : recursiveGCD(b, a%b);
}
/*
Rational Rational::operator * (const Rational & r) const{
    Rational res((_num * r._num), (_den * r._den));
    return res;
}
*/
Rational operator * (const Rational & r1, const Rational & r2){
    Rational res(r1.getNum() * r2.getNum(), r1.getDen() * r2.getDen());
    return res;
}

bool Rational::operator == (const Rational & r) const{
    bool res;
    res = ((r._num == _num) && (r._den == _den));
    return res;
}

ostream & operator << (ostream & o, const Rational & r){
    o << r.getNum() << '/' << r.getDen() << endl;
    return o;
}

Rational Rational::operator - () const{
    Rational res(-_num,_den);
    return res;
}

Rational Rational::operator + (const Rational & r) const{
    Rational res(_num*r._den + r._num*_den, _den*r._den);
    return res;
}

bool Rational::operator < (const Rational & r) const{
    bool res = ((_num*r._den < r._num*_den) && (_den < r._den));
    return res;
}

void Rational::input(istream & in){
    cout << "numerator ?";
    in >> _num;
    do{
    cout << "denominator (non null value) ?";
    in >> _den;
    }
    while(_den == 0);
    if (_den < 0) {
    _num = -_num;
    _den = -_den;
    }
    _reduce();
}

istream & operator >> (istream & i, Rational & r){
    r.input(i);
    return i;
}

bool operator != (const Rational & r1, const Rational & r2){
    bool res = !(r1 == r2);
    return res;
}

bool operator <= (const Rational & r1, const Rational & r2){
    bool res = (r1 < r2 || r1 == r2);
    return res;
}

// Test functions
bool testEmptyConstructorAndGetters()
{
    bool ok = true;
    Rational r;
    if (!(r.getNum() == 0))
    {
        ok = false;
        cout << "Error in the empty constructor or getNum : the numerator is " << r.getNum()
            << " (expected : 0)" << endl;
    }
    if (!(r.getDen() == 1))
    {
        ok = false;
        cout << "Error in the empty constructor or getDen : the denominator is " << r.getDen()
            << " (expected : 1)" << endl;
    }
    return ok;
}

bool testConstructorParamAndGetters(int n, int d, int nres, int dres, bool exc)
{
    bool ok = true;
    if (exc)
    {
        try
        {
            Rational r(n, d);
            ok = false;
            cout << "Error in the constructor with parameters : an exception should have been thrown" << endl;
        }
        catch (const invalid_argument &) { }
    }
    else
    {
        try
        {
            Rational r(n,d);
            if (!(r.getNum() == nres))
            {
                ok = false;
                cout << "Error in the constructor with parameters or getNum : the numerator is "
                    << r.getNum() << " (expected : " << nres << ")" << endl;
            }
            if (!(r.getDen() == dres))
            {
                ok = false;
                cout << "Error in the constructor with parameters or getDen : the denominator is "
                    << r.getDen() << " (expected : " << dres << ")" << endl;
            }
        }
        catch (const invalid_argument &e)
        {
            ok = false;
            cout << "Error in the constructor with parameters: the exception  " << e.what()
                << " has been thrown" << endl;
        }
    }
    return ok;
}

bool testConstructorParamAndGetters()
{
    bool ok = true;
    ok = ok && testConstructorParamAndGetters(0, 1, 0, 1, false);
    ok = ok && testConstructorParamAndGetters(1, 2, 1, 2, false);
    ok = ok && testConstructorParamAndGetters(-1, 2, -1, 2, false);
    ok = ok && testConstructorParamAndGetters(1, -2, -1, 2, false);
    ok = ok && testConstructorParamAndGetters(-1, -2, 1, 2, false);
    ok = ok && testConstructorParamAndGetters(2, 4, 1, 2, false);
    ok = ok && testConstructorParamAndGetters(1, 0, 1, 0, true);
    return ok;
}
