#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK506() {
  string name = "TASK506";
  //! data ------------------------------------
  int shortfall = 50;
  int supply[5][5] ={
    {0,0,0,0,0},
    {10,20,30,40,50},
    {5,15,25,35,45},
    {7,14,21,28,35},
    {2,4,6,8,10}
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "50";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}

