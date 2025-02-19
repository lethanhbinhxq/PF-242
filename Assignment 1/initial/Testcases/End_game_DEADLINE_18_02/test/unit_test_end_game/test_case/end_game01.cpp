#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game01() {
  string name = "end_game01";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input1");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Kon3Tum";
  string code2_2 = "Ifp Qfp";
  int array_task4[10][10] = {
      {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000},
      {100, 100, 1000, 100, 100, 100, 100, 100, 100, 100},
      {0, 10, 0, 10, 0, 10, 0, 10, 0, 10},
      {31, 11, 21, 41, 18, 13, 15, 17, 19, 1},
      {0, 10, 0, 30, 0, 0, 50, 0, 80, 0},
      {18, 31, 11, 15, 16, 17, 18, 19, 12, 15},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {31, 41, 51, 61, 71, 18, 19, 10, 11, 12},
      {23, 24, 0, 0, 0, 0, 29, 100, 0, 0},
      {1, 1, 0, 0, 1, 101, 0, 0, 1, 1}};
  int array_task5[5][5] = {{1002, 100, 100, 3097, 100},
                           {100, 100, 1007, 2220, 100},
                           {1003, 100, 1870, 100, 100},
                           {9618, 1006, 1550, 100, 100},
                           {100, 1001, 100, 100, 1004}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 200 150 100 80 50 30 20 10 5 2 1 1 1 1 0 0 0 \n"
      "LF2: 250 200 150 100 80 50 30 20 10 5 2 1 1 1 1 0 0 \n"
      "EXP1: 26\n"
      "EXP2: 12\n"
      "T1: 152\n"
      "T2: 20\n"
      "E: 99\n\n"

      "----Check Task 1----\n"
      "gatherForces: 4955\n\n"
      "----Check Task 2----\n"
      "String code: Kon3Tum\n"
      "determineRightTarget: Buon Ma Thuot\n\n"
      "String Code: Ifp Qfp\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 152\n"
      "T2: 20\n\n"

      "----Check Task 4----\n"
      "planAttack: -5476\n\n"
      "----Check Task 5----\n"
      "resupply: 5523\n\n"
      "Viet Nam Doc Lap\n";

  //! output ----------------------------------
  if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
    return printResult("file fail", expect, name);
  }
  stringstream output;
  output << "----Input----" << endl;
  output << "LF1: ";
  for (int i = 0; i < 17; i++) {
    output << LF1[i] << " ";
  }
  output << "" << endl;

  output << "LF2: ";
  for (int i = 0; i < 17; i++) {
    output << LF2[i] << " ";
  }
  output << "" << endl;

  output << "EXP1: " << EXP1 << "" << endl;
  output << "EXP2: " << EXP2 << "" << endl;
  output << "T1: " << T1 << "" << endl;
  output << "T2: " << T2 << "" << endl;
  output << "E: " << E << "" << endl << endl;

  output << "----Check Task 1----" << endl;
  int result = gatherForces(LF1, LF2);
  output << "gatherForces: " << result << "" << endl << endl;

  output << "----Check Task 2----" << endl;
  output << "String code: " << code2_1 << "" << endl;
  string result2_1 = determineRightTarget(code2_1);
  output << "determineRightTarget: " << result2_1 << "" << endl << endl;

  output << "String Code: " << code2_2 << "" << endl;
  string result2_2 = decodeTarget(code2_2, EXP1, EXP2);
  output << "decodeTarget: " << result2_2 << "" << endl << endl;

  output << "----Check Task 3----" << endl;
  const int force_weights[17] = {1,  2,  3,  4,  5,  7,  8,  9, 10,
                                 12, 15, 18, 20, 30, 40, 50, 70};

  int SumLF1 = 0;
  int SumLF2 = 0;
  for (int i = 0; i < 17; i++) {
    SumLF1 += LF1[i] * force_weights[i];
    SumLF2 += LF2[i] * force_weights[i];
  }
  cout << "sumLF1 = " << SumLF1 << endl;
  cout << "sumLF2 = " << SumLF2 << endl;

  manageLogistics(SumLF1, SumLF2, EXP1, EXP2, T1, T2, E);
  output << "After manageLogistics: " << endl;
  output << "T1: " << T1 << "" << endl;
  output << "T2: " << T2 << "" << endl << endl;

  output << "----Check Task 4----" << endl;
  int plan = planAttack(SumLF1, SumLF2, EXP1, EXP2, T1, T2, array_task4);
  output << "planAttack: " << plan << "" << endl << endl;

  output << "----Check Task 5----" << endl;
  if (plan >= 0) {
    output << "Chien thang" << endl;
    output << "Viet Nam Doc Lap" << endl;
  } else {
    int supply = resupply(abs(plan), array_task5);
    output << "resupply: " << supply << "" << endl << endl;
    output << "Viet Nam Doc Lap" << endl;
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}