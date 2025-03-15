#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK205() {
  string name = "TASK205";
  //! data ------------------------------------
  string code = "00000007";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "National Route 14";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}