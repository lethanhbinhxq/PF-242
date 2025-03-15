#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK216() {
  string name = "TASK216";
  //! data ------------------------------------
  int EXP1 = 598;
  int EXP2 = 1000;
  string code = "DAk laK";
  code = "FCm ncM";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "Dak Lak";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}