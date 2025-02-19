#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK212() {
  string name = "TASK212";
  //! data ------------------------------------
  string code = "88K2ALKAD84EIRI";
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