#include "../unit_test_TASK3.hpp"

bool UNIT_TEST_TASK3::TASK308() {
  string name = "TASK308";
  //! data ------------------------------------
  int LF1 = 1000, LF2 = 1000;
  int EXP1 = 350, EXP2 = 380;
  int T1 = 46, T2 = 52;
  int E = 0;

  manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);

  //! expect ----------------------------------
  string expect = "12 0";

  //! output ----------------------------------
  stringstream output;
  output << T1 << " " << T2;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
