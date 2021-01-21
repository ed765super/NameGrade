#ifndef INCLUDED_STUDENT
#define INCLUDED_STUDENT

#include "constants.h"
#include <iostream>

using namespace std;

class Student {
  // CLASS INVARIANT: first name and last name are character arrays
  // with no more than MAX_LENGTH characters, and ending with '\0'.

 private:

  char firstName[MAX_LENGTH+1]; // holds the first name 
  char lastName[MAX_LENGTH+1];  // holds the last name
  int score;                  // holds the score 
  
 public:
  // PRE:
  // POST: first name and last name are empty.
  //       score = 0.
  Student ();

  // PRE: pFirstName is a string of letters ending with an end of
  // string character.
  // POST: This object's firstName is the same as pFirstName.
  void setFirstName (char pFirstName[]);

    // PRE: pLastName is a string of letters ending with an end of
  // string character.
  // POST: This object's lastName is the same as pLastName.
  void setLastName (char pLastName[]);

  // PRE: pScore is defined. This object is defined.
  // POST: Set the score for this student to pScore.
  void setScore (int pScore);

  // PRE: This object is defined.
  //      pStudent is defined.
  // POST: This object is a deep copy of pStudent
  void copy (const Student & pStudent);

  // PRE: This object is defined.
  //      pStudent is defined.
  // POST: RV = ture iff the name for this object is less than
  //      (dictionary ordering and with last name compared first, and
  //      if equal then first name compared) that of pStudent. 
  bool lessThanByName (const Student & pStudent) const;

  // PRE: This object is defined.
  //      pStudent is defined.
  // POST: RV = ture iff the score for this object is less than
  //                 that of pStudent. 
  bool operator < (const Student & pStudent) const;

  // PRE: pStudent is defined.
  // POST: stream contains the student's first name, last name and
  //         score followed by a new line. 
  friend ostream & operator << (ostream & stream, const Student & pStudent);
  
};

#endif
