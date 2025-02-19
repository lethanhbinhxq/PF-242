#ifndef UNIT_TEST_TASK5_HPP
#define UNIT_TEST_TASK5_HPP

#include "tay_nguyen_campaign.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_TASK5 : public UNIT_TEST {
 public:
  UNIT_TEST_TASK5() {
    REGISTER_TEST(TASK501);
    REGISTER_TEST(TASK502);
    REGISTER_TEST(TASK503);
    REGISTER_TEST(TASK504);
    REGISTER_TEST(TASK505);
    REGISTER_TEST(TASK506);
    REGISTER_TEST(TASK507);
    REGISTER_TEST(TASK508);
    // TODO
  }

 private:
  bool TASK501();
  bool TASK502();
  bool TASK503();
  bool TASK504();
  bool TASK505();
  bool TASK506();
  bool TASK507();
  bool TASK508();
  // TODO
};

#endif  // UNIT_TEST_TASK5_HPP