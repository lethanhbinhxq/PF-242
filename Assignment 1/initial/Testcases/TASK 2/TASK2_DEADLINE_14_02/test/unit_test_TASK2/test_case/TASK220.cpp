#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK220() {
  string name = "TASK220";
  //! data ------------------------------------
  int EXP1 = 301;
  int EXP2 = 301;
  string code = "Buon Ma Thuot";
  code = "Fysr Qe Xlysx";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "Buon Ma Thuot";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}