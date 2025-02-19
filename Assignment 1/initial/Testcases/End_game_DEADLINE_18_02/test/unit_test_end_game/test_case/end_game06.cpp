#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game06() {
  string name = "end_game06";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input6");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Kon69 Tum";
  string code2_2 = "Fwe Ncr";
  int array_task4[10][10] = {
      {27, 7, 19, 73, 19, 74, 19, 75, 19, 86},
      {17, 151, 224, 45, 1, 90, 18, 24, 70, 90},
      {100, 101000, 102, 103, 104, 401, 301, 201, 101, 1},
      {5, 10, 15, 20, 25, 30, 35, 40, 40, 50},
      {560000, 480, 120, 290, 300, 159, 80000, 70, 30, 2},
      {120, 30, 140, 60, 60, 40, 110, 20, 20},
      {25000, 15, 19, 60, 66000, 77, 88, 99, 110, 121},
      {22, 44, 88, 60, 72, 84, 96, 108, 20000, 132},
      {264, 39, 525, 65000, 78, 91, 104, 70, 130, 143},
      {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}};
  int array_task5[5][5] = {{137000, 10000, 10000, 10000, 10000},
                           {10000, 135568, 10000, 10000, 10000},
                           {10000, 10000, 234098, 10000, 10000},
                           {10000, 10000, 10000, 436546, 10000},
                           {10000, 10000, 10000, 1000, 356190}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 1000 735 387 1000 587 703 1000 436 1000 1000 419 1000 473 "
      "1000 432 806 \n"
      "LF2: 1000 345 513 1000 475 595 503 615 1000 848 1000 727 425 463 746 "
      "773 623 \n"
      "EXP1: 400\n"
      "EXP2: 450\n"
      "T1: 2800\n"
      "T2: 3000\n"
      "E: 56\n\n"

      "----Check Task 1----\n"
      "gatherForces: 427678\n\n"
      "----Check Task 2----\n"
      "String code: Kon69 Tum\n"
      "determineRightTarget: INVALID\n\n"
      "String Code: Fwe Ncr\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 3000\n"
      "T2: 3000\n\n"

      "----Check Task 4----\n"
      "planAttack: -192429\n\n"
      "----Check Task 5----\n"
      "resupply: 265098\n\n"
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