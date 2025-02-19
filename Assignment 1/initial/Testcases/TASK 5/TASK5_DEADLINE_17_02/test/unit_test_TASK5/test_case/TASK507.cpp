#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK507() {
  string name = "TASK507";
  //! data ------------------------------------
  int shortfall = 2400;
  int supply[5][5] = {{100, 100, 100, 100, 100},
                      {100, 100, 100, 100, 100},
                      {100, 100, 100, 100, 100},
                      {100, 100, 100, 100, 100},
                      {100, 100, 100, 100, 100}};

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "-1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  return printResult(output.str(), expect, name);
}
