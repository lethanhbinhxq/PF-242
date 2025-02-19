#include "../unit_test_TASK1.hpp"

bool UNIT_TEST_TASK1::TASK101() {
  string name = "TASK101";
  //! data ------------------------------------
  int LF1[17] = {200, 150, 100, 80, 50, 30, 20, 10, 5, 2, 1, 1, 1, 1, 0, 0, 0};
  int LF2[17] = {250, 200, 150, 100, 80, 50, 30, 20, 10,
                 5,   2,   1,   1,   1,  1,  0,  0};
  int result = gatherForces(LF1, LF2);

  //! expect ----------------------------------
  string expect = "4955";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}