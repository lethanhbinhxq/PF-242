#include "../unit_test_TASK4.hpp"

bool UNIT_TEST_TASK4::TASK404() {
  string name = "TASK404";
  //! data ------------------------------------
  int LF1 = -7, LF2 = 2;
  int EXP1 = 0, EXP2 = -8;
  int T1 = 0, T2 = 0;
  int battleField[10][10] =
  {
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0}
  };

  int result = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battleField);

  //! expect ----------------------------------
  string expect = "-31";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
