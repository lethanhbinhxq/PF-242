#ifndef UNIT_TEST_TASK4_HPP
#define UNIT_TEST_TASK4_HPP

#include "TASK4.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_TASK4 : public UNIT_TEST {
 public:
  UNIT_TEST_TASK4() {
    REGISTER_TEST(TASK401);
    REGISTER_TEST(TASK402);
    REGISTER_TEST(TASK403);
    REGISTER_TEST(TASK404);
    REGISTER_TEST(TASK405);
    REGISTER_TEST(TASK406);
    REGISTER_TEST(TASK407);
    REGISTER_TEST(TASK408);
    // TODO
  }

 private:
  bool TASK401();
  bool TASK402();
  bool TASK403();
  bool TASK404();
  bool TASK405();
  bool TASK406();
  bool TASK407();
  bool TASK408();
  // TODO
};

#endif  // UNIT_TEST_TASK4_HPP