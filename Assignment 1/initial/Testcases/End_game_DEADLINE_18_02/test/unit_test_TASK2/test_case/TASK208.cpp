#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK208() {
  string name = "TASK208";
  //! data ------------------------------------
  string code = "Kon14 Tum22";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "Duc Lap";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}