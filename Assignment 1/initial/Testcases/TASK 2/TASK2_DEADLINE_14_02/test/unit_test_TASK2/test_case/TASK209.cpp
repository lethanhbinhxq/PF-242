#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK209() {
  string name = "TASK209";
  //! data ------------------------------------
  string code = "GIALAI15 23  ";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "National Route 21";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}