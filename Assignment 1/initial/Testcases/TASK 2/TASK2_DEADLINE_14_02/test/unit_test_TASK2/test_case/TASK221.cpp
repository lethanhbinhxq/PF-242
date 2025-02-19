#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK221() {
  string name = "TASK221";
  //! data ------------------------------------
  int EXP1 = 301;
  int EXP2 = 301;
  string code = "Buon Ma Thuoc";
  code = "Fysr Qe Xlysy";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "INVALID";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}