#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK504() {
  string name = "TASK504";
  //! data ------------------------------------
  int shortfall = 100;
  int supply[5][5] ={
    {10,20,30,40,50},
    {15,25,35,45,55},
    {60,70,80,90,100},  // có phần tử 100
    {5,5,5,5,5},
    {12,12,12,12,12}
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "100";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}

