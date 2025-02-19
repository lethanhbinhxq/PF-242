#include "../unit_test_TASK1.hpp"

bool UNIT_TEST_TASK1::TASK102() {
  string name = "TASK102";
  //! data ------------------------------------
  int LF1[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20};
  int LF2[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10};
  int result = gatherForces(LF1, LF2);

  //! expect ----------------------------------
  string expect = "2100";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}