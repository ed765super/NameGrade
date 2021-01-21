#include "grading.h"

// PRE: score is defined = s, where 0 <= s <= 100
// POST: RV is the index (in the array LetterGrades) of the letter
//         grade corresponding to the score.
int getLetterGradeIndex (int score) {
  int index = 0; // the first score boundary to be checked.
  while (score < GradeBoundaries[index]) {
    // ASSERT: for all i, 0 <= i <= index, score < GradeBoundaries[i]
    index++;
  }
  // ASSERT: for all i, 0 <= i < index, score < GradeBoundaries[i]
  //         score >= GradeBoundaries[index]
  return (index);
}
