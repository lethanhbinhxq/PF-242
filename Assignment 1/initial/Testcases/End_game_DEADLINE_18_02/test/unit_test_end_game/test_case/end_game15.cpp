#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game15() {
  string name = "end_game15";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input15");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Gi4 Lai";
  string code2_2 = "FCm ncM";
  int array_task4[10][10] = {{0, 999, 0, 999, 0, 999, 0, 999, 0, 999},
                             {999, 0, 999, 0, 999, 0, 999, 0, 999, 0},
                             {0, 999, 0, 999, 0, 999, 0, 999, 0, 999},
                             {999, 0, 999, 0, 999, 0, 999, 0, 999, 0},
                             {0, 999, 0, 999, 0, 999, 0, 999, 0, 999},
                             {999, 0, 999, 0, 999, 0, 999, 0, 999, 0},
                             {0, 999, 0, 999, 0, 999, 0, 999, 0, 999},
                             {999, 0, 999, 0, 999, 0, 999, 0, 999, 0},
                             {0, 999, 0, 999, 0, 999, 0, 999, 0, 999},
                             {999, 0, 999, 0, 999, 0, 999, 0, 999, 0}};
  int array_task5[5][5] = {{0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0},
                           {0, 0, 1, 0, 0},
                           {0, 0, 0, 1, 0}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 292 581 413 1000 716 1000 299 923 949 1000 348 1000 606 1000 "
      "571 971 \n"
      "LF2: 1000 683 1000 595 390 771 721 1000 662 1000 131 1000 1000 540 1000 "
      "485 838 \n"
      "EXP1: 598\n"
      "EXP2: 600\n"
      "T1: 2596\n"
      "T2: 2874\n"
      "E: 0\n\n"

      "----Check Task 1----\n"
      "gatherForces: 469820\n\n"
      "----Check Task 2----\n"
      "String code: Gi4 Lai\n"
      "determineRightTarget: Duc Lap\n\n"
      "String Code: FCm ncM\n"
      "decodeTarget: Dak Lak\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 0\n"
      "T2: 169\n\n"

      "----Check Task 4----\n"
      "planAttack: 422036\n\n"
      "----Check Task 5----\n"
      "Chien thang\n"
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