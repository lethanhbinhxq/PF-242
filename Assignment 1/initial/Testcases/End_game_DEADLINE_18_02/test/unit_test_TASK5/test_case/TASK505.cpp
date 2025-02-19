#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK505() {
  string name = "TASK505";
  //! data ------------------------------------
  int shortfall = 20;
  int supply[5][5] ={
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5}
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "20";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}

