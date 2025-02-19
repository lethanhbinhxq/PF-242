#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK204() {
  string name = "TASK204";
  //! data ------------------------------------
  string code = "GI4LAI";
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