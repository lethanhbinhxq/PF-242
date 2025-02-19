#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game07() {
  string name = "end_game07";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input7");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "87Gia 18Lai39";
  string code2_2 = "Olv Wlv";
  int array_task4[10][10] = {{5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
                             {4, 8, 12, 16, 20, 24, 28, 32, 36, 40},
                             {3, 6, 9, 12, 15, 18, 21, 24, 27, 30},
                             {2, 4, 6, 8, 10, 12, 14, 16, 18, 20},
                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                             {5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
                             {4, 8, 12, 16, 20, 24, 28, 32, 36, 40},
                             {3, 6, 9, 12, 15, 18, 21, 24, 27, 30},
                             {2, 4, 6, 8, 10, 12, 14, 16, 18, 20},
                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
  int array_task5[5][5] = {{500, 500, 500, 500, 500},
                           {500, 500, 500, 500, 500},
                           {500, 500, 1, 500, 500},
                           {500, 500, 500, 500, 500},
                           {500, 500, 500, 500, 500}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 969 583 1000 1000 1000 609 1000 517 662 717 311 777 907 54 929 "
      "1000 979 \n"
      "LF2: 360 1000 1000 330 510 1000 1000 905 838 1000 891 626 749 1000 495 "
      "1000 308 \n"
      "EXP1: 350\n"
      "EXP2: 380\n"
      "T1: 2600\n"
      "T2: 2800\n"
      "E: 67\n\n"

      "----Check Task 1----\n"
      "gatherForces: 454104\n\n"
      "----Check Task 2----\n"
      "String code: 87Gia 18Lai39\n"
      "determineRightTarget: Dak Lak\n\n"
      "String Code: Olv Wlv\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 2600\n"
      "T2: 2800\n\n"

      "----Check Task 4----\n"
      "planAttack: 466767\n\n"
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