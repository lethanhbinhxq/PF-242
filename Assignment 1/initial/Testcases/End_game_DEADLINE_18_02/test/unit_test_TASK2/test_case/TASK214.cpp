#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK214() {
  string name = "TASK214";
  //! data ------------------------------------
  string code = "15Pleiku0Gia Lai0Buon Ma Thuot0";
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