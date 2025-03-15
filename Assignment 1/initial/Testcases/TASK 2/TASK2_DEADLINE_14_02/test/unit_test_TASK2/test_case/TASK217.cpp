#include "../unit_test_TASK2.hpp"

bool UNIT_TEST_TASK2::TASK217() {
  string name = "TASK217";
  //! data ------------------------------------
  int EXP1 = -1000;
  int EXP2 = 1000;
  string code = "natiONAL ROuTe 21";
  code = "12 eTuOR LANOitan";
  string result = decodeTarget(code, EXP1, EXP2);

  //! expect ----------------------------------
  string expect = "National Route 21";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}