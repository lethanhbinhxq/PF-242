#include "../unit_test_TASK1.hpp"

bool UNIT_TEST_TASK1::TASK104() {
  string name = "TASK104";
  //! data ------------------------------------
  int LF1[17] = {-3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int LF2[17] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int result = gatherForces(LF1, LF2);

  //! expect ----------------------------------
  string expect = "2";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}