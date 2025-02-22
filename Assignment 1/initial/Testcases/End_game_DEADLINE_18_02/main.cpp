/*
 * DSA1 - HK242
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 05.12.2024
 */
#include "main.hpp"

#ifdef TEST_end_game
#include "unit_test_end_game/unit_test_end_game.hpp"
const string TEST_CASE = "end_game";
#elif defined(TEST_TASK1)
#include "unit_test_TASK1/unit_test_TASK1.hpp"
const string TEST_CASE = "TASK1";
#elif defined(TEST_TASK2)
#include "unit_test_TASK2/unit_test_TASK2.hpp"
const string TEST_CASE = "TASK2";
#elif defined(TEST_TASK3)
#include "unit_test_TASK3/unit_test_TASK3.hpp"
const string TEST_CASE = "TASK3";
#elif defined(TEST_TASK4)
#include "unit_test_TASK4/unit_test_TASK4.hpp"
const string TEST_CASE = "TASK4";
#elif defined(TEST_TASK5)
#include "unit_test_TASK5/unit_test_TASK5.hpp"
const string TEST_CASE = "TASK5";
#endif

void printTestCase();

int main(int argc, char *argv[]) {
  cout << "-------------------------------------------------------------"
       << endl;
  cout << GREEN << BOLD << TEST_CASE << " - KTLT1 - HK242 - VO TIEN" << endl;
  cout << CYAN << BOLD << "Vo Tien : https://www.facebook.com/Shiba.Vo.Tien"
       << endl
       << endl;

  if (argc <= 1) {
    printTestCase();
    return 1;
  }

  std::string arg1 = argv[1];
  if (arg1 == "test_unit") {
    std::cout << GREEN << BOLD << "Running unit_test/unit_test_" << TEST_CASE
              << RESET << "\n";
    handleTestUnit(argc, argv);
  } else {
    printTestCase();
  }

  cout << "-------------------------------------------------------------"
       << endl;
}

#ifdef TEST_end_game
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_end_game unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#elif defined(TEST_TASK1)
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_TASK1 unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#elif defined(TEST_TASK2)
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_TASK2 unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#elif defined(TEST_TASK3)
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_TASK3 unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#elif defined(TEST_TASK4)
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_TASK4 unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#elif defined(TEST_TASK5)
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_TASK5 unitTest;
  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#endif

void printTestCase() {
  std::cout << GREEN << BOLD << "terminal unit test TASK " << TEST_CASE << RESET
            << std::endl;
  std::cout << RED << "./main test_unit" << RESET << std::endl;
  std::cout << RED << "./main test_unit nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;
}


