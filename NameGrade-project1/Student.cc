#include "constants.h"
#include "Student.h"
#include "stringFunctions.h"
#include "grading.h"
#include <iostream>

using namespace std;

  // PRE:
  // POST: first name and last name are empty.
  //       score = 0.
Student::Student() {
  firstName[0] = lastName[0] = '\0';
  score = 0;
}

  // PRE: pFirstName is a string of letters ending with an end of
  // string character.
  // POST: This object's firstName is the same as pFirstName.
void Student::setFirstName (char pFirstName[]) {
  copyString(pFirstName, firstName);
}

    // PRE: pLastName is a string of letters ending with an end of
  // string character.
  // POST: This object's lastName is the same as pLastName.
void Student::setLastName (char pLastName[])  {
  copyString(pLastName, lastName);
}

// PRE: This object is defined.
//      pStudent is defined.
// POST: This object is a deep copy of pStudent
void Student::copy (const Student & pStudent) {
  copyString (pStudent.firstName, firstName);
  copyString (pStudent.lastName, lastName);
  score = pStudent.score;
}

// PRE: This object is defined.
//      pStudent is defined.
// POST: RV = ture iff the name for this object is less than
//      (dictionary ordering and with last name compared first, and
//      if equal then first name compared) that of pStudent. 
bool Student::lessThanByName (const Student & pStudent) const {
  bool answer = true;
  if (!(isLessThanString(lastName, pStudent.lastName))) {  // using the overloaded < operator.
    if (isEqualString (lastName, pStudent.lastName)) {
      if (isLessThanString(firstName, pStudent.firstName)) { 
	answer = true;
      }
      else {
	answer = false;
      }
    }
    else {
      answer = false;
    }
  }
  return (answer);
}


// PRE: pStudent is defined.
// POST: stream contains the student's first name, last name and
//         score followed by a new line. 
ostream & operator << (ostream & stream, const Student & pStudent) {
  int indexOfLetterGrade = getLetterGradeIndex(pStudent.score);
  stream << pStudent.firstName << " "
	 << pStudent.lastName << " "
	 << pStudent.score << " "
	 << LetterGrades[indexOfLetterGrade] << endl;
  return (stream);
}

// PRE: pScore is defined. This object is defined.
// POST: Set the score for this student to pScore.
void Student::setScore (int pScore) {
  score = pScore;
}

  // PRE: This object is defined.
  //      pStudent is defined.
  // POST: RV = ture iff the score for this object is less than
  //                 that of pStudent. 
bool Student::operator < (const Student & pStudent) const {
  return (score < pStudent.score);
}
