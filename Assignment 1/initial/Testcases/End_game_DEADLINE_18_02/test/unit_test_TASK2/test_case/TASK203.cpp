#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK203() {
  string name = "TASK203";
  //! data ------------------------------------
  string code = "K0NTUM";
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