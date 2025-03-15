#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK207() {
  string name = "TASK207";
  //! data ------------------------------------
  string code = "P100L0CE in Kon Tum";
  string result = determineRightTarget(code);

  //! expect ----------------------------------
  string expect = "Buon Ma Thuot";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}