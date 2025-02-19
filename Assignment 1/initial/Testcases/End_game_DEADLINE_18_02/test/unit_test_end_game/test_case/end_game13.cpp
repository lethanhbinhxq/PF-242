#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game13() {
  string name = "end_game13";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input13");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Gia La1";
  string code2_2 = "kaL kaD";
  int array_task4[10][10] = {
      {50, 20, 0, 75, 100, 200, 150, 60, 80, 90},
      {30, 0, 45, 55, 65, 70, 85, 95, 105, 115},
      {10, 25, 35, 45, 55, 65, 75, 85, 95, 105},
      {120, 110, 100, 90, 80, 70, 60, 50, 40, 30},
      {0, 5, 10, 15, 20, 25, 30, 35, 40, 45},
      {200, 190, 180, 170, 160, 150, 140, 130, 120, 110},
      {99, 88, 77, 66, 55, 44, 33, 22, 11, 0},
      {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
      {111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {130, 140, 150, 160, 170, 180, 190, 200, 210, 220}};
  int array_task5[5][5] = {{2, 3, 5, 7, 11},
                           {13, 17, 19, 23, 29},
                           {31, 37, 41, 43, 47},
                           {53, 59, 61, 67, 71},
                           {73, 79, 83, 89, 97}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 608 1000 1000 1000 878 1000 781 183 679 425 1000 1000 1000 1000 "
      "765 1000 452 \n"
      "LF2: 306 590 599 926 887 1000 543 511 491 277 191 788 1000 712 325 733 "
      "1000 \n"
      "EXP1: 363\n"
      "EXP2: 249\n"
      "T1: 1640\n"
      "T2: 2594\n"
      "E: 7\n\n"

      "----Check Task 1----\n"
      "gatherForces: 449681\n\n"
      "----Check Task 2----\n"
      "String code: Gia La1\n"
      "determineRightTarget: DECOY\n\n"
      "String Code: kaL kaD\n"
      "decodeTarget: Dak Lak\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 1526\n"
      "T2: 2504\n\n"

      "----Check Task 4----\n"
      "planAttack: 450707\n\n"
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