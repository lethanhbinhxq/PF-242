#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK204() {
  string name = "TASK204";
  //! data ------------------------------------
  int EXP1 = 596;
  int EXP2 = 1000;
  string code = "NaTiOnAl RoUtE 14";
  code = "NaTiOnAl RoUtE 14";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "National Route 14";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}