#include "../unit_test_TASK5.hpp"

bool UNIT_TEST_TASK5::TASK501() {
  string name = "TASK501";
  //! data ------------------------------------
  int shortfall = 1050;
  int supply[5][5] ={
    {150,200,180,90,110},
    {70,80,120,140,160},
    {220,240,200,190,130},
    {100,110,300,280,320},
    {170,210,260,230,290},
  };

  int result = resupply(shortfall, supply);

  //! expect ----------------------------------
  string expect = "1050";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
