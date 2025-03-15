#include "../unit_test_TASK3.hpp"

bool UNIT_TEST_TASK3::TASK303() {
  string name = "TASK303";
  //! data ------------------------------------
  int LF1 = 1000, LF2 = 1000;
  int EXP1 = 350, EXP2 = 380;
  int T1 = 1234, T2 = 5000;
  int E = 44;

  manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);

  //! expect ----------------------------------
  string expect = "1506 3000";

  //! output ----------------------------------
  stringstream output;
  output << T1 << " " << T2;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
