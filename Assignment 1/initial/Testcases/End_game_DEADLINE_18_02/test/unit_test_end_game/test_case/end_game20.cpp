#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game20() {
  string name = "end_game20";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input20");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "G33ia L95ai7";
  string code2_2 = "Fysr Qe Xlysy";
  int array_task4[10][10] = {
      {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10},
      {10, 9000, 8, 7, 6, 5000, 4, 3, 2, 1},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {10, 9, 8, 7000, 6, 5, 4, 3, 2, 1},
      {1, 2, 3, 4, 5000, 6, 7, 8, 9, 10},
      {10, 9, 8, 7, 6000, 5, 4, 3, 2, 1},
      {1, 2, 3000, 4, 5, 6, 7, 8, 9, 10000},
      {10, 9, 8000, 7, 6, 5, 4000, 3, 2, 1},
      {1, 2, 3, 4, 5000, 6, 7, 8, 9, 10},
      {10, 9000, 8, 7, 6, 5, 4, 3, 2, 1}};
  int array_task5[5][5] = {{7, 14, 7, 14, 7},
                           {14, 7, 14, 7, 14},
                           {7, 14, 7, 14, 7},
                           {14, 7, 14, 7, 14},
                           {7, 14, 7, 14, 7}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 1000 942 811 595 422 498 613 515 177 1000 554 602 373 767 631 "
      "632 \n"
      "LF2: 426 202 832 806 1000 1000 1000 198 292 201 260 296 415 581 625 "
      "1000 1000 \n"
      "EXP1: 395\n"
      "EXP2: 134\n"
      "T1: 1299\n"
      "T2: 1697\n"
      "E: 34\n\n"

      "----Check Task 1----\n"
      "gatherForces: 400068\n\n"
      "----Check Task 2----\n"
      "String code: G33ia L95ai7\n"
      "determineRightTarget: Buon Ma Thuot\n\n"
      "String Code: Fysr Qe Xlysy\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 1520\n"
      "T2: 1813\n\n"

      "----Check Task 4----\n"
      "planAttack: 291568\n\n"
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