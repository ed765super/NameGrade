#include "constants.h"
#include "StudentList.h"
#include "stringFunctions.h"
#include "inputFunctions.h"
#include <iostream>

using namespace std;

// PRE:
// POST: This object is empty. CI is satisfied.
StudentList::StudentList () {
  numStudents = 0;
  scoresAdjusted = false;
}

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
void StudentList::readInfo () {
  bool endOfInput = false; // endOfInput = true iff the sentinel word
			   // end has been read.
  // ASSERT: numStudents = 0.
  //         IS contains information for N students.
  while (!endOfInput) {
    // ASSERT: numStudents = n, List[0]..List[n-1] are defined.
    //                          Scores[0]..Scores[n-1] are defined.
    //          IS contains information for (N - n).
    //         
    endOfInput = processLine();
    // ASSERT: endOfInput = true Iff the last line had the sentinel
    //            word. 
    //         if the last line was not the sentinel, numStudents =
    //            n+1, and List[n] and Scores[n] are defined.
    //            IS has information for (N - n) - 1 students.
  }
  // ASSERT: numStudents = N where IS had info for N students.
  //         List[0]..List[N-1] are defined.
  //         Scores[0]..Scores[N-1] are defined.
}


// PRE: IS contains information for k >= 0 students.
//      numStudents = n.
// POST: RV is true iff the last line has the sentinel word;
//      otherwise, numStudents = n+1. List[n] is defined with the
//      name on the last line. Scores[n] is defined with the score
//      on the last line.
//      IS contains information for k-1 students.
bool StudentList::processLine () {
  char nextString[MAX_LENGTH+1]; // array to hold the next string
				 // read. Since the length of the
				 // scores strings is smaller than the
				 // nax length of names, this bound
				 // suffices.
  bool endOfLine = false;        // true iff the newline character is
				 // read. 
  bool sentinel = false;         // true iff the sentinel word is read.
  getNextToken (nextString, endOfLine);
  // ASSERT: nextString[0] is a letter or digit.
  //         There is some i, nextString[i] = '\0'
  //          If nextString[i] = '\0', then nextString[i-1] is a
  //         letter or a digit.
  //         endOfLine = true iff the new line character is read.
  if (isEqualString (nextString, (char *)SENTINEL)) {
    // ASSERT: sentinel word was read
    if (endOfLine) {
      // ASSERT: We have reached the end of input.
      sentinel = true;
    }
  }
  // ASSERT: We did not read the sentinel word or
  //         We read the sentinel word, but there is more input.
  if (!sentinel) {
    // ASSERT: This was the first token on the line. It is either a
    //           first name or a score.
    //         nextString contains the first token (a score or first name)
    processRestOfTheLine (nextString);
    // ASSERT: Fill in student data and score from this line.
  }
  return (sentinel);
}

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
void StudentList::setScoreAndNames (char currToken[],
		       bool & scoreRead, bool & firstNameRead) {
  bool tokenProcessed = false; // true iff this token has been
			       // processed. 
  if (!scoreRead) {
    // ASSERT: currToken must be a score or first or last name.
    // ADD THIS
    if (isDigit(currToken[0])) {
      // ASSERT: currToken is a score.
      Scores[numStudents] = strToInt(currToken);
      scoreRead = true;
      tokenProcessed = true;
    }
  }
  // ASSERT: tokenProcessed is true, then we are done.
  //         tokenProcessed is false, then this token is a first or
  //           last name.
  if (!tokenProcessed) {
    // ASSERT: currToken must be a first or last name.
    if (!firstNameRead) {
      // ASSERT: currToken is a first name
      firstNameRead = true;
      // ADD THIS
      List[numStudents].setFirstName (currToken);
    }
    else {
      // ASSERT: currToken is a last name
      // ADD THIS
      List[numStudents].setLastName (currToken);
    }
  }
}

// PRE: currToken is a valid string, either a first name or a score.
//      This line of the IS contains two more tokens.
// POST: Fill in student data and score from the tokens on this line.
//         numStudents is incremented by one.
void StudentList::processRestOfTheLine (char currToken[]) {
  bool scoreRead = false;      // true iff a score was read.
  bool firstNameRead = false;  // true iff a first name was read.
  bool endOfLine = false;
      // ADD THIS to the .h file
  setScoreAndNames (currToken, scoreRead, firstNameRead);
  // ASSERT: Score or first name is filled in.
  getNextToken (currToken, endOfLine);
  setScoreAndNames (currToken, scoreRead, firstNameRead);
  // ASSERT: Score and first name are filled in OR
  //         First name and last are filled in.
  getNextToken (currToken, endOfLine);
  setScoreAndNames (currToken, scoreRead, firstNameRead);
  // ASSERT: First name, Last name and score are filled in.
  if (!endOfLine) {
    skipWhiteSpaceToEndOfLine ();
  }
  numStudents++;
  // ASSERT: Entire line has been read.
}

// PRE:  This object is populated with the list of students on IS. The scores
// for the students may not be associated with the correct student.
// POST:  The i-th student in this object has his/her correct score.
void StudentList::adjustScores () {
  sortByName();
  // ASSERT: Names in List are in dictionary order.
  for (int studentNo = 0; (studentNo < numStudents); studentNo++) {
    List[studentNo].setScore (Scores[studentNo]);
  }
  // ASSERT: Each student has his/her correct score.
  scoresAdjusted = true;
}

// PRE: numStudents = n > 0, List[0]..List[numStudents-1] is defined.
// POST: List[0] < List[1] < ... < List[numStudents-1] (by name)
void StudentList::sortByName () {
  mergeSortByName (0, numStudents-1); // sort List by name
}

// PRE: 0 <= firstIndex <= lastIndex < numStudents
//      List[firstIndex]..List[lastIndex] is defined.
// POST: List[firstIndex] < List[firstIndex+1] < .. <
//      List[lastIndex] (by name) 
void StudentList::mergeSortByName (int firstIndex, int lastIndex) {
  if (firstIndex < lastIndex) {
    // ASSERT: There are at leasat two elements to be sorted.
    int mid = (firstIndex + lastIndex)/2;
    // ASSERT: firstIndex <= mid
    //         mid+1 <= lastIndex
    mergeSortByName (firstIndex, mid);
    // ASSERT: List[firstIndex] < ... < List[mid] (by name)
    mergeSortByName (mid+1, lastIndex);
    // ASSERT: List[mid+1] < ... < List[lastIndex] (by name)
    mergeByName (firstIndex, mid, lastIndex);
    // ASSERT: List[firstIndex] < ... < List[lastIndex] (by name)
  }
  // ASSERT: List[firstIndex] < ... < List[lastIndex] (by name)
}

// PRE: 0 <= left1 <= right1 < right2 < numStudents
//      List[left1] < ... < List[right1] (by name) and
//      List[right1+1] < ... < List[right2] (by name)
// POST: List[left1] < ... < List[right2]
void StudentList::mergeByName (int left1, int right1, int right2) {
  
  Student temp;
  temp.copy (List[right1+1]);
  // ASSERT: temp is the same (deep copy) as List[right1+1]
  int index = right1; // Start index for comparing with temp
  bool positionFound = false; // true iff the correct position for
			      // temp is found.
  bool oneChangeMade = false; // No element of List has been moved.
  while ((index >= left1) && (!positionFound)) {
    // ASSERT: index = right1 or List[index+1] > temp (by name)
    if (temp.lessThanByName(List[index])) {
      List[index+1].copy(List[index]);
      index--;
      oneChangeMade = true; // One element of List was moved.
    }
    else {
      // ASSERT: index is the correct position for temp
      List[index+1].copy(temp);
      positionFound = true;
    }
  }
  // ASSERT: index = left1 or List[left1] < ... < List[right1+1]
  if (index < left1) {
    // ASSERT: left1 is the correct position for temp
    List[left1].copy(temp);
    // ASSERT: List[left1] < ... < List[right1+1]
  }
  // ASSERT: List[left1] < ... < List[right1+1]
  //         right1+1 <= right2
  //         if (right1 + 1) < right2, then
  //             List[right1+2] < ... < List[right2]
  //         if (right1+1] = right2), then
  //             List[left1] < ... < List[right2]
  if ((oneChangeMade) && ((right1 + 1) < right2)) {
    mergeByName (left1, right1+1, right2);
    // ASSERT: List[left1] < ... < List[right2]
  }
  // ASSERT: List[left1] < ... < List[right2]
}

// PRE: This object is sorted by their scores.
// POST: OS contains the names (first and last) of all the students
//        (in descending order of their scores),
//        their scores, and their letter grades as
//        computed according to the scale:
//        0 - 60: F, 61 - 70: D, 71 - 80: C, 81 - 90: B, 91 - 100: A
//        The OS also contains the average score.
void StudentList::print () {
  //  for (int index = numStudents-1; (index >= 0); index--) {
  for (int index = 0; (index < numStudents); index++) {
    cout << List[index];
  }
}

// PRE: numStudents = n > 0, List[0]..List[numStudents-1] is defined.
// POST: List[0] < List[1] < ... < List[numStudents-1] (by score)
void StudentList::sortByScore () {
  mergeSortByScore (0, numStudents-1); // sort List by score
}

// PRE: 0 <= firstIndex <= lastIndex < numStudents
//      List[firstIndex]..List[lastIndex] is defined.
// POST: List[firstIndex] < List[firstIndex+1] < .. <
//      List[lastIndex] (by score) 
void StudentList::mergeSortByScore (int firstIndex, int lastIndex) {
  if (firstIndex < lastIndex) {
    // ASSERT: There are at leasat two elements to be sorted.
    int mid = (firstIndex + lastIndex)/2;
    // ASSERT: firstIndex <= mid
    //         mid+1 <= lastIndex
    mergeSortByScore (firstIndex, mid);
    // ASSERT: List[firstIndex] < ... < List[mid] (by score)
    mergeSortByScore (mid+1, lastIndex);
    // ASSERT: List[mid+1] < ... < List[lastIndex] (by score)
    mergeByScore (firstIndex, mid, lastIndex);
    // ASSERT: List[firstIndex] < ... < List[lastIndex] (by score)
  }
  // ASSERT: List[firstIndex] < ... < List[lastIndex] (by score)
}

// PRE: 0 <= left1 <= right1 < right2 < numStudents
//      List[left1] < ... < List[right1] (by score) and
//      List[right1+1] < ... < List[right2] (by score)
// POST: List[left1] < ... < List[right2]
void StudentList::mergeByScore (int left1, int right1, int right2) {
  Student temp;
  temp.copy (List[right1+1]);
  // ASSERT: temp is the same (deep copy) as List[right1+1]
  int index = right1; // Start index for comparing with temp
  bool positionFound = false; // true iff the correct position for
			      // temp is found.
  bool oneChangeMade = false; // No element of List has been moved.
  while ((index >= left1) && (!positionFound)) {
    // ASSERT: index = right1 or List[index+1] > temp (by score)
    //    if (temp.lessThanByScore(List[index])) {
    if (temp < List[index]) { // overloaded < (by score)
      List[index+1].copy(List[index]);
      index--;
      oneChangeMade = true; // One element of List was moved.
    }
    else {
      // ASSERT: index is the correct position for temp
      List[index+1].copy(temp);
      positionFound = true;
    }
  }
  // ASSERT: index = left1 or List[left1] < ... < List[right1+1]
  //             (by score)
  if (index < left1) {
    // ASSERT: left1 is the correct position (by score) for temp
    List[left1].copy(temp);
    // ASSERT: List[left1] < ... < List[right1+1] (by score)
  }
  // ASSERT: List[left1] < ... < List[right1+1] (by score)
  //         right1+1 <= right2
  //         if (right1 + 1) < right2, then
  //             List[right1+2] < ... < List[right2] (by score)
  //         if (right1+1] = right2), then
  //             List[left1] < ... < List[right2] (by score)
  if ((oneChangeMade) && ((right1 + 1) < right2)) {
    mergeByScore (left1, right1+1, right2);
    // ASSERT: List[left1] < ... < List[right2] (by score)
  }
  // ASSERT: List[left1] < ... < List[right2] (by score)
}
