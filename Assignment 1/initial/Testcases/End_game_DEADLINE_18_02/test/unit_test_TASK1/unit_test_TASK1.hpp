#ifndef UNIT_TEST_TASK1_HPP
#define UNIT_TEST_TASK1_HPP

#include "tay_nguyen_campaign.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_TASK1 : public UNIT_TEST {
 public:
  UNIT_TEST_TASK1() {
    REGISTER_TEST(TASK101);
    REGISTER_TEST(TASK102);
    REGISTER_TEST(TASK103);
    REGISTER_TEST(TASK104);
    REGISTER_TEST(TASK105);
    // TODO REGISTER_TEST
  }

 private:
  bool TASK101();
  bool TASK102();
  bool TASK103();
  bool TASK104();
  bool TASK105();
  // TODO CREATE_TEST
};

#endif  // UNIT_TEST_TASK1_HPP