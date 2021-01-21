#include "StudentList.h"

// PRE: IS contains lines, with information for one student on each line.
//        The input ends with a line containing the word end.
//        Each line contains a first name, a last name and a score.
//        first and last names do not contain spaces or tabs.
//        first name always appears before the last name.
//        first and last names do not have any more than MAX_LENGTH
//        characters (see constants.h for the constants)
//        First and last names are in lowercase.
//        Scores are between 0 and 100, inclusive.
//        There are no more than MAX_NAMES students on the IS.
//        The scores are included assuming that the students' names
//        were in dictionary order, but the IS may not contain the
//        names in dictionary order.
//        (For names, a name A comes before a name B if the last name
//        for A comes before that of B, or if the last names are the
//        same and the first name for A comes before the first name
//        for B.
//        The IS is not empty.
//        There are no blank lines before the line containing the end
//        of input sentinel - the word end.
// POST: OS contains the names (first and last) of all the students
//        (in descending order of their scores),
//        their scores, and their letter grades as
//        computed according to the scale:
//        0 - 60: F, 61 - 70: D, 71 - 80: C, 81 - 90: B, 91 - 100: A
//        The OS also contains the average score.
int main () {

  StudentList Students;
  // ASSERT: Students is an empty list.

  Students.readInfo ();
  // ASSERT:  Students is populated with the list of students on IS. The scores
  // for the students may not be associated with the correct student.

  Students.adjustScores ();
  // ASSERT:  The i-th student in Students has his/her correct score.

  Students.sortByScore ();
  // ASSERT:  Students is sorted by their scores.

  Students.print ();
    // ASSERT:  OS contains the names (first and last) of all the students
    //        (in descending order of their scores),
    //        their scores, and their letter grades as
    //        computed according to the scale:
    //        0 - 60: F, 61 - 70: D, 71 - 80: C, 81 - 90: B, 91 - 100: A
    //        The OS also contains the average score.
}
