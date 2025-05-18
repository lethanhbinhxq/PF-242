#include "LiberationArmy.h"

// TODO: Implement
// class LiberationArmy
LiberationArmy::LiberationArmy(Unit **unitArray, int size, string name) : Army(unitArray, size, name) { }

void LiberationArmy::fight(Army* enemy, bool defense) {
    if (!defense) {
        this->LF = ceil(this->LF * 1.5);
        this->EXP = ceil(this->EXP * 1.5);
        normalizeArmyData();

        vector<Unit*> infantryUnits = this->unitList->getUnitsByType(INFANTRY_UNIT);
        vector<Unit*> vehicleUnits = this->unitList->getUnitsByType(VEHICLE_UNIT);

        // for (int i = 0; i < infantryUnits.size(); i++) {
        //         cout << infantryUnits[i]->str() << endl;
        //     }
        //     for (int i = 0; i < vehicleUnits.size(); i++) {
        //         cout << vehicleUnits[i]->str() << endl;
        //     }

        vector<Unit*> infantryCombo = findMinCombination(infantryUnits, enemy->getEXP());
        vector<Unit*> vehicleCombo = findMinCombination(vehicleUnits, enemy->getLF());
        bool foundI = !infantryCombo.empty();
        bool foundV = !vehicleCombo.empty();
        // cout << "Combo infantry:" << endl;
        // for (int i = 0; i < infantryCombo.size(); i++) {
        //     cout << infantryCombo[i]->str() << endl;
        // }
        // cout << "Combo vehicle:" << endl;
        // for (int i = 0; i < vehicleCombo.size(); i++) {
        //     cout << vehicleCombo[i]->str() << endl;
        // }

        // cout << "FoundI: " << foundI << endl;
        // cout << "FoundV: " << foundV << endl;
        // cout << "This->EXP: " << this->EXP << endl;
        // cout << "Enemy EXP: " << enemy->getEXP() << endl;

        if (!foundI && !foundV) {
            this->battleFlag = false;
        }
        else if (!foundI && this->EXP > enemy->getEXP()) {
            this->battleFlag = true;
        }
        else if (!foundV && this->LF > enemy->getLF()) {
            this->battleFlag = true;
        }
        else if (foundI && foundV) {
            this->battleFlag = true;
        }

        if (!battleFlag) {
            this->unitList->updateUnitScore(DECREASE_10_PERCENT_WEIGHT);
        }
        else {
            // for (int i = 0; i < infantryCombo.size(); i++) {
            //     cout << infantryCombo[i]->str() << endl;
            // }
            // for (int i = 0; i < vehicleCombo.size(); i++) {
            //     cout << vehicleCombo[i]->str() << endl;
            // }
            if (foundI && foundV) {
                removeUnit(infantryCombo, vehicleCombo);
            }
            else if (foundI) {
                removeUnit(infantryCombo, vehicleUnits);
            }
            else {
                removeUnit(infantryUnits, vehicleCombo);
            }
            confiscate(this, enemy);
        }
        updateScores();
    }

    else {
        this->LF = ceil(this->LF * 1.3);
        this->EXP = ceil(this->EXP * 1.3);
        // cout << "LF = " << LF << endl;
        // cout << "EXP = " << EXP << endl;
        normalizeArmyData();
        bool smallerLF = this->LF < enemy->getLF();
        bool smallerEXP = this->EXP < enemy->getEXP();
        if (smallerLF && smallerEXP) {
            this->unitList->updateUnitScore(INCREASE_TO_FIBONACCI_QUANTITY);
        }
        // else if (!smallerLF && !smallerEXP) {
        //     confiscate(this, enemy);
        // }
        else if (smallerLF || smallerEXP) {
            this->unitList->updateUnitScore(DECREASE_10_PERCENT_QUANTITY);
            updateScores();
        }
    }

}

bool LiberationArmy::getBattleFlag() {
    return battleFlag;
}

string LiberationArmy::str() const {
    string libStr = "LiberationArmy[";
    // libStr += "name=" + this->name;
    libStr += "LF=" + to_string(this->LF);
    libStr += ",EXP=" + to_string(this->EXP);
    libStr += ",unitList=";
    if (this->unitList) libStr += this->unitList->str();
    libStr += "]";
    return libStr;
}

vector<Unit*> LiberationArmy::findMinCombination(vector<Unit*>& units, int targetValue) {
    vector<pair<int, vector<Unit*>>> pPair;
    pPair.push_back({0, {}});

    for (int i = 0; i < units.size(); i++) {
        int unitScore = units[i]->getAttackScoreImmutable();
        int pPairSize = pPair.size();

        for (int j = 0; j < pPairSize; j++) {
            int newScore = pPair[j].first + unitScore;
            bool exist = false;

            for (int k = 0; k < pPair.size(); k++) {
                if (pPair[k].first == newScore) {
                    exist = true;
                    break;
                }
            }

            if (!exist) {
                vector<Unit*> newCombo = pPair[j].second;
                newCombo.push_back(units[i]);
                pPair.push_back({newScore, newCombo});
            }
        }
    }

    int minScore = INT_MAX;
    vector<Unit*> minCombo;
    for (int i = 0; i < pPair.size(); i++) {
        int score = pPair[i].first;
        if (score >= targetValue && score < minScore) {
            minScore = score;
            minCombo = pPair[i].second;
        }
    }
    return minCombo;
}