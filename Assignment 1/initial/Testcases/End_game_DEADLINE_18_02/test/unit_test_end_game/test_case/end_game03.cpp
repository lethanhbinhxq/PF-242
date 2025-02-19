#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game03() {
  string name = "end_game03";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input3");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "GiaLai2B7C5";
  string code2_2 = "kaL kaD";
  int array_task4[10][10] = {{506, 15, 20, 25, 305, 635, 540, 145, 50, 55},
                             {325, 18, 24, 330, 3676, 442, 48, 54, 660, 665},
                             {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
                             {100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
                             {100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
                             {505, 30, 46570, 501, 602, 70, 80, 90, 100, 110},
                             {922, 33, 447682, 55, 66, 77, 58, 99, 110, 121},
                             {124, 36, 48, 60, 72, 84, 96, 108, 120, 132},
                             {264, 39, 525, 65, 78, 971, 104, 170, 130, 143},
                             {28, 42, 566, 50, 84, 98, 125, 126, 140, 154}};
  int array_task5[5][5] = {{250880, 878824, 298883, 78822, 208801},
                           {929880, 19099, 17788, 197, 10006},
                           {571885, 108914, 1903, 89012, 11},
                           {60180, 87990, 18008, 2787, 3566},
                           {1975, 2014, 3, 2, 1}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 123 2 234 3 345 4 0 1 101 202 0 0 0 0 0 0 0 \n"
      "LF2: 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n"
      "EXP1: 600\n"
      "EXP2: 10\n"
      "T1: 1500\n"
      "T2: 0\n"
      "E: 24\n\n"

      "----Check Task 1----\n"
      "gatherForces: 6039\n\n"
      "----Check Task 2----\n"
      "String code: GiaLai2B7C5\n"
      "determineRightTarget: Dak Lak\n\n"
      "String Code: kaL kaD\n"
      "decodeTarget: Dak Lak\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 2700\n"
      "T2: 1200\n\n"

      "----Check Task 4----\n"
      "planAttack: -374315\n\n"
      "----Check Task 5----\n"
      "resupply: 374490\n\n"
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