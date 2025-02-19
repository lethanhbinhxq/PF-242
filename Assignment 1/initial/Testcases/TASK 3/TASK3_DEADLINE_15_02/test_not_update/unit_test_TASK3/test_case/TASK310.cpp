#include "../unit_test_TASK3.hpp"

bool UNIT_TEST_TASK3::TASK310() {
  string name = "TASK310";
  //! data ------------------------------------
  int LF1 = 236, LF2 = 417;
  int EXP1 = 490, EXP2 = 567;
  int T1 = 2578, T2 = 2019;
  int E = 0;

  manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);

  //! expect ----------------------------------
  string expect = "2196 0";

  //! output ----------------------------------
  stringstream output;
  output << T1 << " " << T2;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
