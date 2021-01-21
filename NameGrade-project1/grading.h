#ifndef INCLUDED_grading
#define INCLUDED_grading

#define NUM_LETTER_GRADES 12
#define LETTER_GRADE_LENGTH 2

// Letter grades to be assigned.
static char LetterGrades[NUM_LETTER_GRADES][LETTER_GRADE_LENGTH+1] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};

// Inclusive Boundaries for the letter grades, e.g.,
//   if score >= GradeBoundaries[0], then assigned grade is LetterGrades[0]
static int GradeBoundaries [NUM_LETTER_GRADES] = {93, 90, 86, 83, 80, 76, 73, 70, 66, 63, 60, 0};

// PRE: score is defined = s, where 0 <= s <= 100
// POST: RV is the index (in the array LetterGrades) of the letter
//         grade corresponding to the score.
int getLetterGradeIndex (int score);


#endif
