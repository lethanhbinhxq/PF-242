#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK503() {
  string name = "TASK503";
  //! data ------------------------------------
  int shortfall = 30;
  int supply[5][5] ={
    {5,5,5,5,5},       // tổng 25
    {10,10,10,10,10},   // tổng 50
    {20,20,20,20,20},   // tổng 100
    {1,1,1,1,1},        // tổng 5
    {2,2,2,2,2}         // tổng 10
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "30";  // VD: 10+10+10 = 30 là tập con nhỏ nhất đạt yêu cầu

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}

