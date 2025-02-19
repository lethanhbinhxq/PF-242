#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK211() {
  string name = "TASK211";
  //! data ------------------------------------
  string code = "1000PP1000LL1000CC";
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