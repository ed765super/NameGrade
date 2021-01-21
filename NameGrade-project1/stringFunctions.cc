#include "constants.h"
#include "stringFunctions.h"

// PRE: string1 and string2 are defined and have the end of string
// character  at the end.
// POST: RV is true iff string1 has the same characters as string2.
bool isEqualString (const char string1[], const char string2[]) {
  bool areEqual = true; // indicate if the strings seen so far are equal.
  int index = 0;        // index of the next characters to be
			// compared.
  while ((string1[index] == string2[index]) && (string1[index] != EOS)) {
    // ASSERT: The strings are equal up through index and
    //         there are more characters in the string.
    index++;
  }
  // ASSERT: string1[index] != string2[index] or
  //         string1[index] = string2[index] = EOS.
  if (string1[index] != string2[index]) {
    // ASSERT: Strings are not equal at index.
    areEqual = false;
  }
  return (areEqual);
}

// PRE: string1 and string2 are defined and have the end of string
// character  at the end.
// POST: RV is true iff string1 comes before string2 in dictionary ordering.
bool isLessThanString (const char string1[], const char string2[]) {
  bool isLess = true; // indicate if string1 seen so far is less than string2
  int index = 0;        // index of the next characters to be
			// compared.
  while ((string1[index] == string2[index]) && (string1[index] != EOS)) {
    // ASSERT: The strings are equal up through index and
    //         there are more characters in the string.
    index++;
  }
  // ASSERT: string1[index] != string2[index] or
  //         string1[index] = EOS
  if (string2[index] == EOS) {
    isLess = false;
  }
  else if (string1[index] > string2[index]) {
    isLess = false;
  }
  return (isLess);
}


// PRE: ch is defined.
// POST: RV is true iff ch is a digit ('0'..'9')
bool isDigit (char ch) {
  bool answer;
  answer = ((ch >= CHAR0) && (ch <= CHAR9));
  return (answer);
}

// PRE: token is a string of digits end with an end of string character.
// POST: RV is the decimal value of the string.
int strToInt (const char token[]) {
  int answer  = 0;
  int index = 0; // index of the next character in token
  while (token[index] != EOS) {
    answer = (answer * DECIMAL_BASE) + ((int)token[index] - (int)CHAR0);
    index++;
  }
  return (answer);
}

// PRE: string1 is defined and has the end of string
//        character  at the end. string2 has adequate space allocated
//        to it accomodate string1.
// POST: for all 0 <= i <= length of string1, string2[i] = string1[i].
void copyString (const char string1[], char string2[]) {
  int index = 0;
  while (string1[index] != EOS) {
    string2[index] = string1[index];
    index++;
  }
  string2[index] = EOS;
}

