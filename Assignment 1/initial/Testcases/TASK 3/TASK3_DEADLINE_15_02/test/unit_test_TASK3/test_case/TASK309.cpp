#include "../unit_test_TASK3.hpp"

bool UNIT_TEST_TASK3::TASK309() {
  string name = "TASK309";
  //! data ------------------------------------
  int LF1 = 567, LF2 = 20;
  int EXP1 = 200, EXP2 = 1000;
  int T1 = 2000, T2 = 987;
  int E = 0;

  manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);

  //! expect ----------------------------------
  string expect = "0 3000";

  //! output ----------------------------------
  stringstream output;
  output << T1 << " " << T2;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
