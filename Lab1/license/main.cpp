#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "license.h"

using namespace std;


int main()
{
    //12) verifications are not done, but the creation works.
    License li;
    li.input();
    License ldef, l, l1, l2, l3;
    //9)
    vector<License>v(10);
    for (int i = 0; i < v.size(); i++){
        v[i].display();
    }
    //6)
    cout << "----- License validity test: ------------------------------" << endl;
    try {
        l = License("Duck", "Donald", "09/06/1934", "012345", 7);
        //2)a)
        l1 = License("Serov", "Sinister", "01/07/1990", "001292", 11);
        l2 = License("Guevayat", "Dvalin", "31/08/1999", "981212", 0);
        l3 = License("6", "Question", "01/01/0000", "999999", -6);
    }
    catch(const invalid_argument & e){
        cerr << "Erreur: " << e.what() << endl;
    }
    cout << "----- Question 11----------------------------------" <<endl;
    License pa("Toto");
    if (pa.compare(string("Toto"))) cout << "we can compare a license to a string"  << endl;
    else cout << "we cannot compare a license to a string" << endl;
    if (pa.compare(string("Titi"))) cout << "we can compare a license to a string"  << endl;
    else cout << "we cannot compare a license to a string" << endl;

    cout << endl << "----- Manual tests for display -----------------------------------------" << endl;
    ldef.display();
    l.display();
    l1.display();
    l2.display();
    //7) if (l1 == l2) cout << "same licenses" << endl;
    //8)
    l3 = License("8", "Question", "01/01/0000", "999999", 11);
    cout << "----- Comparison between 2 licenses: --------------------------------" << endl;
    bool comparaison;
    comparaison = l1.compare(l3);
    if (comparaison) cout << "Same licenses" << endl;
    // 3)a)
    cout << "----- Get the name of one person --------------------------------------" << endl;
    cout << l1.getName() << endl;
    // 3)b)
    try{
    l1.incrementPoints();
    l1.incrementPoints();
    l2.incrementPoints();
    }
    catch(const invalid_argument &e){
        cerr << "Erreur: " << e.what() << endl;
    }
    //3)c)
    try{
    l1.decrementPoints();
    l2.decrementPoints();
    l2.decrementPoints();
    }
    catch(const invalid_argument &f){
        cerr << "Erreur: " << f.what() << endl;
    }
    //4)a)
    addPoints(l2, 4);
    l2.display();
    addPoints(l1, 5);
    l1.display();

    cout << endl << "----- Automatic tests for getNbpoints --------------------------------" << endl;
    bool ok = true;
    if (!(l.getNbpoints() == 7))
    {
        ok = false;
        cout << "Error : l.getNbpoints() = " << l.getNbpoints() << " (expected : 7)" << endl;
    }
    if (ok) cout << "Method getNbpoints correct" << endl;

    cout << endl << "----- Automatic tests for withdrawPoints ------------------------------" << endl;
    ok = true;
    l.withdrawPoints(3);
    if (!(l.getNbpoints() == 4))
    {
        ok = false;
        cout << "Error : after having retrieved 3 points from a license with 7 points, we get a license with "
             << l.getNbpoints() << " points (expected : 4)" << endl;
    }
    l = License ("Duck", "Donald", "09/06/1934", "012345", 7);
    l.withdrawPoints(0);
    if (!(l.getNbpoints() == 7))
    {
        ok = false;
        cout << "Error : after having retrieved 0 points from a license with 7 points, we get a license with "
             << l.getNbpoints() << " points (expected : 7)" << endl;
    }
    l = License ("Duck", "Donald", "09/06/1934", "012345", 7);
    l.withdrawPoints(7);
    if (!(l.getNbpoints() == 0))
    {
        ok = false;
        cout << "Error : after having retrieved 7 points from a license with 7 points, we get a license with "
             << l.getNbpoints() << " points (expected : 0)" << endl;
    }
    l = License ("Duck", "Donald", "09/06/1934", "012345", 7);
    l.withdrawPoints(10);
    if (!(l.getNbpoints() == 0))
    {
        ok = false;
        cout << "Error : after having retrieved 10 points from a license with 7 points, we get a license with "
             << l.getNbpoints() << " points (expected : 0)" << endl;
    }
    l = License ("Duck", "Donald", "09/06/1934", "012345", 7);
    if (ok) cout << "Method withdrawPoints correct" << endl;

    return 0;
}

//1)a) The file license.h contains the declaration of the class license
//--> private data --> private variables/attributes
//--> public functions --> prototype; --> methods
//b) The file license.cpp contains the definition of the functions/methods
//--> it include the file license.h
// License:: is the call of the class License
// if removed, the function can't use the variables because they are in the class License who hasn't been called.
//c) main.cpp contains the call of the functions and the automatic tests. It include the file license.h
/* d)
Construction of a license
Construction of a license

----- Manual tests for display -----------------------------------------
Information concerning the license of unknown unknown :
00000
unknown
Number of points : 12
Information concerning the license of Donald Duck :
012345
09/06/1934
Number of points : 7

----- Automatic tests for getNbpoints --------------------------------
Method getNbpoints correct

----- Automatic tests for withdrawPoints ------------------------------
Construction of a license
Construction of a license
Construction of a license
Construction of a license
Method withdrawPoints correct

It'll construct a default license and the license of Donald Duck then try to remove points to them.
2)b)
it doesn't compile, no match for operator and 'Licence'
the cout doesn't know License
c) it doesn't compile, _name is private within this context
_name is a private data variable
d) display does not (ant can't) modify the object while withdrawPoints does that's why withdrawPoints is not const.
*/
//4)b) error because the function addpoints modify License, we can't put it in const.
//5)b) The destructor is called at the end of a bloc or each time a license with the same name is created. It destroys in the reverse order of creation.
// (the newest first, and the first created in last)
//7) no match for operator ==. We can't compare two licenses because we havn't define the method for compare these 2 licenses
//9) all the licenses created are default licenses. They are created at the beginning of their bloc life like the other licenses.
// The content is displayed at the end when the objects are destroyed.
//10) If you enter a license with no parameters then the default license and the license with default values are ambigous.
// The default license is no longer needed, no further problems.
//11) By default, the number of points will be 12 if not specified.
// In the license Toto it's not specified so 12. In the new license created for the comparison not specified so 12 points.
// We have the same amount of points so compare() returns true even if the names are different.
