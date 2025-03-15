/*
 * DSA1 - HK242
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 05.12.2024

 ! build code macbook, linux: ./run.sh => run file run.sh

 ! build window: ./build.bat => run file build.bat

 ! link : https://discord.com/channels/1334472759945990184/1338826972284977183
*/

#include "main.hpp"
#ifdef TEST_TASK1
#include "unit_test_TASK1/unit_test_TASK1.hpp"
const string TEST_CASE = "TASK1";
#endif
void printTestCase();

int main(int argc, char *argv[]) {
  cout << "-------------------------------------------------------------"
       << endl;
  cout << GREEN << BOLD << "DSA1 - HK242 - VO TIEN" << endl;
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

#ifdef TEST_TASK1
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
#endif

void printTestCase() {
  std::cout << GREEN << BOLD << "terminal unit test" << RESET << std::endl;
  std::cout << RED << "./main test_unit" << RESET << std::endl;
  std::cout << RED << "./main test_unit nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;
}