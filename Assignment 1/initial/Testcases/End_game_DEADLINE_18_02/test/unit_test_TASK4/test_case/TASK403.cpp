#include "../unit_test_TASK4.hpp"

bool UNIT_TEST_TASK4::TASK403() {
  string name = "TASK403";
  //! data ------------------------------------
  int LF1 = 1, LF2 = 2;
  int EXP1 = 2, EXP2 = 2;
  int T1 = 2, T2 = 1;
  int battleField[10][10] =
  {
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1}
  };

  int result = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battleField);

  //! expect ----------------------------------
  string expect = "-46";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
