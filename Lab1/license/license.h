// HB/CB november 2022 - version for students
// License class, to handle drivers licensesses
// license.h file
#ifndef _LICENSE_H_
#define _LICENSE_H_

#include <string>
using namespace std;


const int MAXP = 12;    // Maximum number of points for a licecce
const int MINP = 0;     //  Minimum number of points


class License {
  string _name;      //  Name of the license holder (surname, also called last name, but name here to simplify things)
  string _firstName;   //  First name of the license holder (also called given name)
  string _date;     //  Date of issue of the license, format JJ/MM/YYYY (ex: 09/10/2021)
  string _number;   //  License number (ex: 0123456789)
  int _nbpoints;    //  Number of points of the license, between MINP and MAXP

 public:
  /*--------------  License();
    Empty constructor
    Constructs the license of an unknown person, with 12 points by default
  */
  //License ();

 /*-------------  License (string, string, string, string, int); Constructor on the basis of given information
   Constructs a license from the name and first name of the holder,
   the date of issue, the number, and the number of points
 */
  License (string = "User", string = "Anonymous", string = "01/01/1970", string = "123456", int = MAXP);
  /* ----------- void display() const;
     Display of a license
     Displays all data associated with the target license
  */
  void display() const;

  /*------------- int getNbpoints() const;
    Number of points of a license
    Returns the number of points of the target license
   */
  int getNbpoints() const;

   /*--------------  string getName() const;
    Name of a license holder
    Returns the name of the target license holder
   */

   /*----------- void withdrawPoints(int);
    Withdraws points from a license
    Withdraws the number of points passed as parameter from the target license,
    for a minimum of MINP.
   */
   void withdrawPoints(int);

   string getName() const;

   void incrementPoints();

   void decrementPoints();

   ~License();

   bool compare(const License &) const;

   void input();

};

void addPoints(License &, int);

#endif
