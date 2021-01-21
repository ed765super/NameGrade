#ifndef INCLUDED_stringFunctions
#define INCLUDED_stringFunctions

// PRE: string1 and string2 are defined and have the end of string
// character  at the end.
// POST: RV is true iff string1 has the same characters as string2.
bool isEqualString (const char string1[], const char string2[]);

// PRE: string1 and string2 are defined and have the end of string
// character  at the end.
// POST: RV is true iff string1 comes before string2 in dictionary ordering.
bool  isLessThanString (const char string1[], const char string2[]);

// PRE: ch is defined.
// POST: RV is true iff ch is a digit ('0'..'9')
bool isDigit (char ch);

// PRE: token is a string of digits end with an end of string character.
// POST: RV is the decimal value of the string.
int strToInt (const char token[]);

// PRE: string1 is defined and has the end of string
//        character  at the end. string2 has adequate space allocated
//        to it accomodate string1.
// POST: for all 0 <= i <= length of string1, string2[i] = string1[i].
void copyString (const char string1[], char string2[]);

#endif
