#include "../unit_test_TASK4.hpp"

bool UNIT_TEST_TASK4::TASK408() {
  string name = "TASK408";
  //! data ------------------------------------
  int LF1 = -7, LF2 = 2;
  int EXP1 = 0, EXP2 = -8;
  int T1 = 0, T2 = 0;
  int battleField[10][10] =
  {
    {0,0,0,10,0,0,0,10,0,0},
    {15,15,15,21,21,21,19,19,19,19},
    {0,10,0,10,0,10,0,10,0,10},
    {31,11,21,41,18,13,15,17,19,1},
    {0,10,0,30,0,0,50,0,80,0},
    {18,31,11,15,16,17,18,19,12,15},
    {0,0,0,0,0,0,0,0,0,0},
    {31,41,51,61,71,18,19,10,11,12},
    {23,24,0,0,0,0,29,100,0,0},
    {1,1,0,0,1,1010,0,0,1,1}
  };

  int result = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battleField);

  //! expect ----------------------------------
  string expect = "-3099";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
