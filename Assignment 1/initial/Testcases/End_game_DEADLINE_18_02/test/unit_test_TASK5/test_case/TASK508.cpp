#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK508() {
  string name = "TASK508";
  //! data ------------------------------------
  int shortfall = 26;
  int supply[5][5] ={
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1}
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "-1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}
