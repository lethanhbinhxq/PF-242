#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK206() {
  string name = "TASK206";
  //! data ------------------------------------
  string code = "KON TUM to DAK LAK";
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