#include "../unit_test_TASK3.hpp"

bool UNIT_TEST_TASK3::TASK301() {
  string name = "TASK301";
  //! data ------------------------------------
  int LF1 = 1000, LF2 = 1000;
  int EXP1 = 400, EXP2 = 450;
  int T1 = 2800, T2 = 3000;
  int E = 5;

  manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);

  //! expect ----------------------------------
  string expect = "2660 2925";

  //! output ----------------------------------
  stringstream output;
  output << T1 << " " << T2;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
