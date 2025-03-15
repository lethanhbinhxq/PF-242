#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK219() {
  string name = "TASK219";
  //! data ------------------------------------
  int EXP1 = 50;
  int EXP2 = -1;
  string code = "dUc lAP";
  code = "PAl cUd";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "Duc Lap";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}