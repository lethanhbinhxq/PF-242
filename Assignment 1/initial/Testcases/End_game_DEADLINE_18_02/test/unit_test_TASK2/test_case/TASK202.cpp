#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK202() {
  string name = "TASK202";
  //! data ------------------------------------
  string code = "P1EIKU";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "DECOY";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}