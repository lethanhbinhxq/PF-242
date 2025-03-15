#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK502() {
  string name = "TASK502";
  //! data ------------------------------------
  int shortfall = 250;
  int supply[5][5] ={
    {10,10,10,10,10},
    {10,10,10,10,10},
    {10,10,10,10,10},
    {10,10,10,10,10},
    {10,10,10,10,10}
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "-1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}

