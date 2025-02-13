/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2025
* Date: 07.02.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "tay_nguyen_campaign.h"

// ANSI color codes for terminal output
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

using namespace std;

string tnc_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("tnc_tc_01_input");
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;
    if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
        return "";
    }

    cout << "LF1[0]: " << LF1[0] << ", LF2[0]: " << LF2[0] << endl;
    int result = gatherForces(LF1, LF2);
    cout << "Result: " << result << endl;
    return to_string(result);
}
string tnc_tc_0211() {
    cout << "----- Sample Testcase 02 1 1 -----" << endl;
    string test = "Kon3 Tum";
    string result = determineRightTarget(test);
    cout << "Target: " << result << endl;
    return result;
}

string tnc_tc_0212() {
    cout << "----- Sample Testcase 02 1 2 -----" << endl;
    string test = "Ple9i ku";
    string result = determineRightTarget(test);
    cout << "Target: " << result << endl;
    return result;
}

string tnc_tc_0213() {
    cout << "----- Sample Testcase 02 1 3 -----" << endl;
    string test = "Ple1Ku4Nat9";
    string result = determineRightTarget(test);
    cout << "Target: " << result << endl;
    return result;
}

string tnc_tc_0214() {
    cout << "----- Sample Testcase 02 1 4 -----" << endl;
    string test = "KonTum";
    string result = determineRightTarget(test);
    cout << "Target: " << result << endl;
    return result;
}

string tnc_tc_0215() {
    cout << "----- Sample Testcase 02 1 5 -----" << endl;
    string test = "Buon1Ma3Thuot5-8";
    string result = determineRightTarget(test);
    cout << "Target: " << result << endl;
    return result;
}


string tnc_tc_0221() {
    cout << "----- Sample Testcase 02 2 1 -----" << endl;
    return decodeTarget("Zwg Hwg", 350, 400);
}

string tnc_tc_0222() {
    cout << "----- Sample Testcase 02 2 2 -----" << endl;
    return decodeTarget("Pal cUd", 250, 200);
}

string tnc_tc_0223() {
    cout << "----- Sample Testcase 02 2 3 -----" << endl;
    return decodeTarget("random", 250, 400);
}

string tnc_tc_0224() {
    cout << "----- Sample Testcase 02 2 4 -----" << endl;
    return decodeTarget("DUC LAP", 350, 400);
}


string tnc_tc_03() {
    cout << "----- Sample Testcase 03 -----" << endl;
    string input_file("tnc_tc_03_input");
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;
    if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
        return "";
    }
    manageLogistics(LF1[0], LF2[0], EXP1, EXP2, T1, T2, E);
    cout << "T1: " << T1 << ", T2: " << T2 << endl;
    return to_string(T1) + " " + to_string(T2);
}

string tnc_tc_041(){
    cout << "----- Sample Testcase 04 1 -----" << endl;
    int LF1 = 300, LF2 = 280;
    int EXP1 = 450, EXP2 = 470;
    int T1 = 2500, T2 = 2600;

    // Example battlefield strength matrix
    int battleField[10][10] = {
        {506, 15, 20, 25, 305, 635, 540, 145, 50, 55},
        {325, 18, 24, 330, 36, 442, 48, 54, 660, 665},
        {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
        {562, 24, 323, 404, 484, 60, 40, 72, 80, 88},
        {181, 27, 36, 52, 543, 63, 72, 81, 90, 99},
        {505, 30, 40, 501, 602, 70, 80, 90, 100, 110},
        {922, 33, 442, 55, 66, 77, 58, 99, 110, 121},
        {124, 36, 48, 60, 72, 84, 96, 108, 20, 132},
        {264, 39, 525, 65, 78, 91, 104, 170, 130, 143},
        {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}
    };

    int result = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battleField);

    if (result > 0) {
        cout << "Army wins! Remaining strength: " << result << endl;
    } else {
        cout << "Army loses! Additional supplies needed: " << abs(result) << endl;
    }

    return to_string(result);
}

string tnc_tc_042(){
    cout << "----- Sample Testcase 04 1 -----" << endl;
    int LF1 = 300, LF2 = 280;
    int EXP1 = 450, EXP2 = 470;
    int T1 = 2500, T2 = 2600;

    // Example battlefield strength matrix
    int battleField[10][10] = {
        {106, 15, 20, 25, 305, 635, 540, 145, 50, 55},
        {25, 18, 24, 330, 36, 442, 48, 54, 660, 665},
        {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
        {162, 24, 323, 404, 484, 60, 40, 72, 80, 88},
        {181, 27, 36, 52, 543, 63, 72, 81, 90, 99},
        {5, 30, 40, 501, 602, 70, 80, 90, 100, 110},
        {22, 33, 442, 55, 66, 77, 58, 99, 110, 121},
        {24, 36, 48, 60, 72, 84, 96, 108, 20, 132},
        {264, 39, 525, 65, 78, 91, 104, 70, 130, 143},
        {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}
    };

    int result = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battleField);

    if (result > 0) {
        cout << "Army wins! Remaining strength: " << result << endl;
    } else {
        cout << "Army loses! Additional supplies needed: " << abs(result) << endl;
    }

    return to_string(result);
}
string tnc_tc_05(){
    cout << "----- Sample Testcase 05 -----" << endl;

    int shortfall = 1050;

    int supply[5][5] = {
        {150, 200, 180, 90, 110},
        {70, 80, 120, 140, 160},
        {220, 240, 200, 190, 130},
        {100, 110, 300, 280, 320},
        {170, 210, 260, 230, 290}
    };

    int result = resupply(shortfall, supply);
    cout << "Optimal supply sum: " << result << endl;
    return to_string(result);
}

int passed_tests = 0;
int total_tests = 0;

void check_testcase(const string& actual, const string& expected) {
    total_tests++;
    if (actual == expected) {
        cout << GREEN << "Test Passed" << RESET << endl;
        passed_tests++;
    } else {
        cout << RED << "Test Failed: Expected " << expected << ", but got " << actual << RESET << endl;
    }
}

int main() {
    cout << "Running Test Cases..." << endl;
    
    check_testcase(tnc_tc_01(), "4955");
    check_testcase(tnc_tc_0211(), "Buon Ma Thuot");
    check_testcase(tnc_tc_0212(), "INVALID");
    check_testcase(tnc_tc_0213(), "National Route 14");
    check_testcase(tnc_tc_0214(), "INVALID");
    check_testcase(tnc_tc_0215(), "INVALID");
    check_testcase(tnc_tc_0221(), "Dak Lak");
    check_testcase(tnc_tc_0222(), "Duc Lap");
    check_testcase(tnc_tc_0223(), "INVALID");
    check_testcase(tnc_tc_0224(), "INVALID");
    check_testcase(tnc_tc_03(), "2660 2925");
    check_testcase(tnc_tc_041(), "-2758");
    check_testcase(tnc_tc_042(), "126");
    check_testcase(tnc_tc_05(), "1050");
    
    double pass_percentage = (static_cast<double>(passed_tests) / total_tests) * 100;
    cout << "\nTest Summary: " << passed_tests << "/" << total_tests << " tests passed (";
    if (pass_percentage == 100.0) {
        cout << GREEN;
    } else {
        cout << RED;
    }
    cout << pass_percentage << "% passed" << RESET << ")" << endl;
    
    return 0;
}
