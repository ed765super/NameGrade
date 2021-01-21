#include "inputFunctions.h"
#include "constants.h"
#include <iostream>

using namespace std;

// PRE: IS contains ar least one token whose length is no more than MAX_LENGTH.
//        token has been allocated at least MAX_LENGTH + 1 bytes.
// POST: token contains the token from the IS ending with the end of
//        string character.
//       endOfLine = true iff the new line character was read at the
//       end of the token 
void getNextToken (char token[], bool & endOfLine) {
  int index = 0; // index of the next character in token
  char ch;      //  ch will hold the character read from input.

  ch = cin.get(); // ch is the next character on IS
  while ((ch == SPACE) || (ch == TAB)) {
    // ASSERT: the character read is a white space character
    ch = cin.get();
  }
  // ASSERT: ch is not a white space character.
  //         ch must be the fist character of a token.
  do {
    token[index] = ch;
    index++;
    ch = cin.get();
  } while ((ch != SPACE) && (ch != TAB) && (ch != NEWLINE));
  // ASSERT: ch must be a white space character or the newline character.
  //         index must be the number of characters in the token.
  token[index] = EOS;
  if (ch == NEWLINE) {
    endOfLine = true;
  }
}

// PRE: The next character on IS is the end of line character, or IS
//        contains white space characters followed by the end of line
//        character. 
// POST: The next character to be read is the one after the end of
//        line character.
void skipWhiteSpaceToEndOfLine () {
  char ch; // holds the next character read from input.
  ch = cin.get();
  while (ch != NEWLINE) {
    ch = cin.get();
  }
  // ASSERT: The new line character has been read, and the next
  //           character on IS is the one after the new line character.
}
