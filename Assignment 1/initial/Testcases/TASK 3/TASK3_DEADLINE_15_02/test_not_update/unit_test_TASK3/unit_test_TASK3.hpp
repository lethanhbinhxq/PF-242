#ifndef UNIT_TEST_TASK3_HPP
#define UNIT_TEST_TASK3_HPP

#include "TASK3.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_TASK3 : public UNIT_TEST {
 public:
  UNIT_TEST_TASK3() {
    REGISTER_TEST(TASK301);
    REGISTER_TEST(TASK302);
    REGISTER_TEST(TASK303);
    REGISTER_TEST(TASK304);
    REGISTER_TEST(TASK305);
    REGISTER_TEST(TASK306);
    REGISTER_TEST(TASK307);
    REGISTER_TEST(TASK308);
    REGISTER_TEST(TASK309);
    REGISTER_TEST(TASK310);

    // TODO
  }

 private:
  bool TASK301();
  bool TASK302();
  bool TASK303();
  bool TASK304();
  bool TASK305();
  bool TASK306();
  bool TASK307();
  bool TASK308();
  bool TASK309();
  bool TASK310();
  // TODO
};

#endif  // UNIT_TEST_TASK3_HPP