#ifndef INCLUDED_inputFunctions
#define INCLUDED_inputFunctions

// PRE: IS contains at least one token whose length is no more than MAX_LENGTH.
//        token has been allocated at least MAX_LENGTH + 1 bytes.
// POST: token contains the token from the IS ending with the end of
//        string character.
//       endOfLine = true iff the new line character was read at the
//       end of the token 
void getNextToken (char token[], bool & endOfLine);

// PRE: The next character on IS is the end of line character, or IS
//        contains white space characters followed by the end of line
//        character. 
// POST: The next character to be read is the one after the end of
//        line character.
void skipWhiteSpaceToEndOfLine ();

#endif
