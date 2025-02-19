#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK213() {
  string name = "TASK213";
  //! data ------------------------------------
  string code = "82 K O 16 N T 9 U M";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "Dak Lak";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}