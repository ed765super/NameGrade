#ifndef INCLUDED_StudentList
#define INCLUDED_StudentList

#include "constants.h"
#include "Student.h"

class StudentList {

  // CLASS INVARIANT: numStudents = n >= 0.
  //		      List[0] .. List[n-1] is defined.
  //                  Scores[0]..Scores[n-1] is defined.
  //                  scoresAdjusted is true iff Scores[i] matches the
  //		      student whose name is i-th in dictionary order.
 private:
  Student List[MAX_NAMES]; // List of all the student names and their
			   // scores. (initially, the scores will be
			   // 0 because the scores on input do not
			   // match the student names. 
  int Scores[MAX_NAMES];   // Scores of students as read from the
			   // input. The first score will correspond
			   // to the student whose name comes first in
			   // dictionary order.
  bool scoresAdjusted;     // true iff students have their correct
			   // scores.
  int numStudents;         // the number of students in List.

  // PRE: IS contains information for k >= 0 students.
  //      numStudents = n.
  // POST: RV is true iff the last line has the sentinel word;
  //      otherwise, numStudents = n+1. List[n] is defined with the
  //      name on the last line. Scores[n] is defined with the score
  //      on the last line.
  //      IS contains information for k-1 students.
  bool processLine ();

  // PRE: currToken is a valid string, either a first name or a score.
  //      This line of the IS contains two more tokens.
  // POST: Fill in student data and score from the tokens on this line.
  //         numStudents is incremented by one.
  void processRestOfTheLine (char currToken[]);

  // PRE: numStudents = n > 0, List[0]..List[numStudents-1] is defined.
  // POST: List[0] < List[1] < ... < List[numStudents-1] (by name)
  void sortByName ();

  // PRE: 0 <= firstIndex <= lastIndex < numStudents
  //      List[firstIndex]..List[lastIndex] is defined.
  // POST: List[firstIndex] < List[firstIndex+1] < .. <
  //      List[lastIndex] (by name) 
  void mergeSortByName (int firstIndex, int lastIndex);

  // PRE: 0 <= left1 <= right1 < right2 < numStudents
  //      List[left1] < ... < List[right1] (by name) and
  //      List[right1+1] < ... < List[right2] (by name)
  // POST: List[left1] < ... < List[right2]
  void mergeByName (int left1, int right1, int right2);
  
  // PRE: 0 <= firstIndex <= lastIndex < numStudents
  //      List[firstIndex]..List[lastIndex] is defined.
  // POST: List[firstIndex] < List[firstIndex+1] < .. <
  //      List[lastIndex] (by score) 
  void mergeSortByScore (int firstIndex, int lastIndex);

  // PRE: 0 <= left1 <= right1 < right2 < numStudents
  //      List[left1] < ... < List[right1] (by score) and
  //      List[right1+1] < ... < List[right2] (by score)
  // POST: List[left1] < ... < List[right2]
  void mergeByScore (int left1, int right1, int right2);

  // PRE: currToken is a score or a first or last name
  //      if scoreRead is true, then currToken must be a first or last name.
  //      if scoreRead is false, then currToken must be a score or first
  //        or last name.
  //      if firstNameRead is true, then currToken must be a score or a
  //        last name.
  //      if firstNameRead is false, then currToken must be a score or a
  //        first name.
  // POST: if currToken is a score, then scoreRead is true, and Scores
  //         is updated at numStudents
  //       if currToken is not a score, then the appropriate name is
  //         updated in List at numStudents.
  void setScoreAndNames (char currToken[],
			 bool & scoreRead, bool & firstNameRead);
  
 public:
  // PRE:
  // POST: This object is empty. CI is satisfied.
  StudentList();

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
  // POST:  This object is populated with the list of students on IS. The scores
  // for the students may not be associated with the correct student.
  void readInfo ();

  
  // PRE:  This object is populated with the list of students on IS. The scores
  // for the students may not be associated with the correct student.
  // POST:  The i-th student in this object has his/her correct score.
  void adjustScores ();

  
  // PRE:  The i-th student in this object has his/her correct score.
  // POST: This object is sorted by their scores.
  void sortByScore ();

  // PRE: This object is sorted by their scores.
  // POST: OS contains the names (first and last) of all the students
  //        (in descending order of their scores),
  //        their scores, and their letter grades as
  //        computed according to the scale:
  //        0 - 60: F, 61 - 70: D, 71 - 80: C, 81 - 90: B, 91 - 100: A
  //        The OS also contains the average score.
  void print ();

  
  
};

#endif
