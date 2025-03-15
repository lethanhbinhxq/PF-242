#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK201() {
  string name = "TASK201";
  //! data ------------------------------------
  string code = "PLeIKU";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "INVALID";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}