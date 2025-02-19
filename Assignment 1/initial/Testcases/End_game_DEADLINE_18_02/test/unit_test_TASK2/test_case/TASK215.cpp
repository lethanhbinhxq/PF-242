#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK215() {
  string name = "TASK215";
  //! data ------------------------------------
  string code = "Tim24Ve-6Pleiku0";
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