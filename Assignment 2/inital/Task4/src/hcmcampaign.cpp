#include "hcmcampaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////

// class Position
Position::Position(int r, int c) {
    this->r = r;
    this->c = c;
}

Position::Position(const string &str_pos) {
    stringstream ss(str_pos);
    char ignoreChar;
    int row, column;
    ss >> ignoreChar >> row >> ignoreChar >> column;
    this->r = row;
    this->c = column;
}

int Position::getRow() const {
    return this->r;
}

int Position::getCol() const {
    return this->c;
}

void Position::setRow(int r) {
    this->r = r;
}

void Position::setCol(int c) {
    this->c = c;
}

string Position::str() const {
    string positionStr = "(";
    positionStr += to_string(this->r) + ",";
    positionStr += to_string(this->c) + ")";
    return positionStr;
}

double Position::calculateDistance(Position a, Position b) {
    double dx = pow(a.r - b.r, 2);
    double dy = pow(a.c - b.c, 2);
    return sqrt(dx + dy);
}

// class Unit
Unit::Unit(): quantity(0), weight(0), pos(Position()), computedAttackScore(0) {}

Unit::Unit(int quantity, int weight, Position pos) {
    this->quantity = quantity;
    this->weight = weight;
    this->pos.setRow(pos.getRow());
    this->pos.setCol(pos.getCol());
    this->computedAttackScore = 0;
}

Unit::~Unit() {}

Position Unit::getCurrentPosition() const {
    return this->pos;
}

int Unit::getQuantity() const {
    return this->quantity;
}

void Unit::setQuantity(int quantity) {
    this->quantity = quantity;
}

int Unit::getWeight() const {
    return this->weight;
}

void Unit::setWeight(int weight) {
    this->weight = weight;
}

int Unit::getComputedAttackScore() const {
    return this->computedAttackScore;
}

void Unit::setComputedAttackScore(int score) {
    this->computedAttackScore = score;
}

// class Vehicle
string Vehicle::vehicleTypeString() const {
    switch(this->vehicleType) {
        case TRUCK: return "TRUCK";
        case MORTAR: return "MORTAR";
        case ANTIAIRCRAFT: return "ANTIAIRCRAFT";
        case ARMOREDCAR: return "ARMOREDCAR";
        case APC: return "APC";
        case ARTILLERY: return "ARTILLERY";
        case TANK: return "TANK";
    }
    return "";
}

Vehicle::Vehicle(int quantity, int weight, const Position pos, VehicleType vehicleType) : Unit(quantity, weight, pos) {
    this->vehicleType = vehicleType;
}

Vehicle::~Vehicle() {}

int Vehicle::getAttackScore() {
    double score = ((double)(this->vehicleType) * 304 + this->quantity * this->weight) / 30;
    int attackScore = ceil(score);
    setComputedAttackScore(attackScore);
    return attackScore;
}

int Vehicle::getEnumType() const {
    return this->vehicleType;
}

string Vehicle::str() const {
    string vehicleStr = "Vehicle[";
    vehicleStr += "vehicleType=" + vehicleTypeString();
    vehicleStr += ",quantity=" + to_string(this->quantity);
    vehicleStr += ",weight=" + to_string(this->weight);
    vehicleStr += ",position=" + this->pos.str();
    vehicleStr += "]";
    return vehicleStr;
}

VehicleType Vehicle::convertToVehicleType(string str) {
    if (str == "TRUCK") return TRUCK;
    if (str == "MORTAR") return MORTAR;
    if (str == "ANTIAIRCRAFT") return ANTIAIRCRAFT;
    if (str == "ARMOREDCAR") return ARMOREDCAR;
    if (str == "APC") return APC;
    if (str == "ARTILLERY") return ARTILLERY;
    if (str == "TANK") return TANK;
    return TANK;
}

// class Infantry
bool Infantry::checkPerfectSquare(int weight) {
    int sqrtNumber = sqrt(weight);
    return (sqrtNumber * sqrtNumber == weight);
}

int Infantry::getPersonalNumber(int score, int year) {
    int sumDigit = 0;
    while (year > 0) {
        sumDigit += year % 10;
        year /= 10;
    }

    sumDigit += score;
    while (sumDigit >= 10) {
        int temp = 0;
        while (sumDigit > 0) {
            temp += sumDigit % 10;
            sumDigit /= 10;
        }
        sumDigit = temp;
    }

    return sumDigit;
}

string Infantry::infantryTypeString() const {
    switch(this->infantryType) {
        case SNIPER: return "SNIPER";
        case ANTIAIRCRAFTSQUAD: return "ANTIAIRCRAFTSQUAD";
        case MORTARSQUAD: return "MORTARSQUAD";
        case ENGINEER: return "ENGINEER";
        case SPECIALFORCES: return "SPECIALFORCES";
        case REGULARINFANTRY: return "REGULARINFANTRY";
    }
    return "";
}

InfantryType Infantry::convertToInfantryType(string str) {
    if (str == "SNIPER") return SNIPER;
    if (str == "ANTIAIRCRAFTSQUAD") return ANTIAIRCRAFTSQUAD;
    if (str == "MORTARSQUAD") return MORTARSQUAD;
    if (str == "ENGINEER") return ENGINEER;
    if (str == "SPECIALFORCES") return SPECIALFORCES;
    if (str == "REGULARINFANTRY") return REGULARINFANTRY;
    return SNIPER;
}

Infantry::Infantry(int quantity, int weight, const Position pos, InfantryType infantryType) : Unit(quantity, weight, pos) {
    this->infantryType = infantryType; 
}

Infantry::~Infantry() {}

int Infantry::getAttackScore() {
    int score = (int)(this->infantryType) * 56 + this->quantity * this->weight;

    if (this->infantryType == SPECIALFORCES && checkPerfectSquare(this->weight)) {
        score += 75;
    }

    int personalNumber = getPersonalNumber(score);
    if (personalNumber > 7) {
        double newQuantity = this->quantity + this->quantity * 0.2;
        this->quantity = ceil(newQuantity);
    }
    else if (personalNumber < 3) {
        double newQuantity = this->quantity - this->quantity * 0.1;
        this->quantity = ceil(newQuantity);
    }

    score = (int)(this->infantryType) * 56 + this->quantity * this->weight;
    setComputedAttackScore(score);
    return score;
}

int Infantry::getEnumType() const {
    return this->infantryType;
}

string Infantry::str() const {
    string infantryStr = "Infantry[";
    infantryStr += "infantryType=" + infantryTypeString();
    infantryStr += ",quantity=" + to_string(this->quantity);
    infantryStr += ",weight=" + to_string(this->weight);
    infantryStr += ",position=" + this->pos.str();
    infantryStr += "]";
    return infantryStr;
}

// class UnitList
UnitList::UnitList(int capacity) {
    this->capacity = capacity;
    this->vehicleCount = 0;
    this->infantryCount = 0;
    this->headUnit = nullptr;
    this->tailUnit = nullptr;
}

UnitList::~UnitList() {
    UnitNode* cur = this->headUnit;
    while (cur) {
        UnitNode* temp = cur->next;
        cur->next = nullptr;
        delete cur;
        cur = temp;
    }
    this->headUnit = nullptr;
    this->tailUnit = nullptr;
}

void UnitList::insertFront(UnitNode* newNode) {
    newNode->next = this->headUnit;
    this->headUnit = newNode;
}

void UnitList::insertRear(UnitNode* newNode) {
    this->tailUnit->next = newNode;
    this->tailUnit = this->tailUnit->next;
}

bool UnitList::insert(Unit* unit) {
    if (this->vehicleCount + this->infantryCount < this->capacity) {
        UnitNode* cur = this->headUnit;
        bool foundFlag = false;
        while (cur) {
            bool sameDataType = (dynamic_cast<Vehicle*>(cur->unit) && dynamic_cast<Vehicle*>(unit)) || (dynamic_cast<Infantry*>(cur->unit) && dynamic_cast<Infantry*>(unit));

            if (sameDataType && cur->unit->getEnumType() == unit->getEnumType()) {
                foundFlag = true;
                int newQuantity = cur->unit->getQuantity() + unit->getQuantity();
                cur->unit->setQuantity(newQuantity);

                int weight1 = cur->unit->getWeight();
                int weight2 = unit->getWeight();
                cur->unit->setWeight(max(weight1, weight2));

                if (dynamic_cast<Infantry*>(unit)) {
                    cur->unit->getAttackScore();
                }
                return false;
            }
            cur = cur->next;
        }

        if (!foundFlag) {
            UnitNode* newNode = new UnitNode(unit);
            if (!this->headUnit) {
                this->headUnit = newNode;
                this->tailUnit = newNode;
                if (dynamic_cast<Vehicle*>(unit)) {
                    vehicleCount++;
                }
                else infantryCount++;
            }
            else if (dynamic_cast<Vehicle*>(unit)) {
                insertRear(newNode);
                vehicleCount++;
            }
            else {
                insertFront(newNode);
                infantryCount++;
            }
        }
        return true;
    }
    return false;
}

void UnitList::remove(Unit* unit) {
    if (!this->headUnit) return;
    UnitNode* cur = this->headUnit;
    UnitNode* prev = nullptr;
    while (cur) {
        if (cur->unit == unit) {
            if (prev) {
                prev->next = cur->next;
            }
            else {
                this->headUnit = cur->next;
            }

            if (cur == this->tailUnit) {
                this->tailUnit = prev;
            }

            if (dynamic_cast<Vehicle*>(cur->unit)) {
                vehicleCount--;
            }
            else {
                infantryCount--;
            }
            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

bool UnitList::isContain(VehicleType vehicleType) {
    UnitNode* cur = this->headUnit;
    while (cur && dynamic_cast<Vehicle*>(cur->unit)) {
        if (cur->unit->getEnumType() == int(vehicleType)) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool UnitList::isContain(InfantryType infantryType) {
    UnitNode* cur = this->headUnit;
    while (cur && dynamic_cast<Infantry*>(cur->unit)) {
        if (cur->unit->getEnumType() == int(infantryType)) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

vector<Unit*> UnitList::getUnitsByType(UnitType type) {
    vector<Unit*> result;
    UnitNode* cur = this->headUnit;
    while (cur) {
        if (type == INFANTRY_UNIT) {
            if (dynamic_cast<Infantry*>(cur->unit)) {
                result.push_back(cur->unit);
            }
        }
        else {
            if (dynamic_cast<Vehicle*>(cur->unit)) {
                result.push_back(cur->unit);
            }
        }
        cur = cur->next;
    }
    return result;
}

int UnitList::nextNearestFibonacci(int n) {
    if (n <= 0) return 0;
    int first = 0;
    int second = 1;
    while (second < n) {
        int fib = first + second;
        first = second;
        second = fib;
    }
    return second;
}

void UnitList::updateUnitScore(UpdateUnitFlag flag) {
    UnitNode* cur = this->headUnit;
    while (cur) {
        if (flag == DECREASE_10_PERCENT_WEIGHT) {
            int oldWeight = cur->unit->getWeight();
            int newWeight = ceil(oldWeight * (1 - 0.1));
            cur->unit->setWeight(newWeight);
        }
        else if (flag == DECREASE_20_PERCENT_WEIGHT) {
            int oldWeight = cur->unit->getWeight();
            int newWeight = ceil(oldWeight * (1 - 0.2));
            cur->unit->setWeight(newWeight);
        }
        else if (flag == DECREASE_10_PERCENT_QUANTITY) {
            int oldQuantity = cur->unit->getQuantity();
            int newQuantity = ceil(oldQuantity * (1 - 0.1));
            cur->unit->setQuantity(newQuantity);
        }
        else if (flag == INCREASE_TO_FIBONACCI_QUANTITY) {
            int oldQuantity = cur->unit->getQuantity();
            int newQuantity = nextNearestFibonacci(oldQuantity);
            cur->unit->setQuantity(newQuantity);
        }
        else if (flag == DECREASE_20_PERCENT_QUANTITY) {
            int oldQuantity = cur->unit->getQuantity();
            int newQuantity = ceil(oldQuantity * (1 - 0.2));
            if (newQuantity <= 1) {
                UnitNode* temp = cur->next;
                remove(cur->unit);
                cur = temp;
            }
            else {
                cur->unit->setQuantity(newQuantity);
            }
        }

        if (cur) {
            cur = cur->next;
        }
    }
}

void UnitList::addUnitList(UnitList list) {
    UnitNode* cur = list.headUnit;
    while (cur) {
        insert(cur->unit);
        cur = cur->next;
    }
}

void UnitList::clear() {
    UnitNode* cur = this->headUnit;
    while (cur) {
        remove(cur->unit);
        cur = cur->next;
    }
}

bool UnitList::isFull() {
    return (this->capacity == this->vehicleCount + this->infantryCount);
}

bool UnitList::isEmpty() {
    return (this->vehicleCount + this->infantryCount == 0);
}

Unit* UnitList::pop_back_unit() {
    if (!this->headUnit) return nullptr;
    Unit* backup;

    if (this->headUnit == this->tailUnit) {
        backup = this->tailUnit->unit;
        delete this->tailUnit;
        this->headUnit = nullptr;
        this->tailUnit = nullptr;
    }
    else {
        UnitNode* cur = this->headUnit;
        while (cur && cur->next != this->tailUnit) {
            cur = cur->next;
        }
        backup = this->tailUnit->unit;
        delete this->tailUnit;
        this->tailUnit = cur;
        this->tailUnit->next = nullptr;
    }

    if (dynamic_cast<Vehicle*>(backup)) {
        this->vehicleCount--;
    }
    else {
        this->infantryCount--;
    }

    return backup;
}

void UnitList::removeWithQuantity(int quantity) {
    UnitNode* cur = this->headUnit;
    while (cur) {
        UnitNode* temp = cur->next;
        if (cur->unit->getQuantity() <= quantity) {
            remove(cur->unit);
        }
        cur = temp;
        
    }
}

void UnitList::removeWithAttackScore(int attackScore, bool computed) {
    UnitNode* cur = this->headUnit;
    while (cur) {
        UnitNode* temp = cur->next;
        // cout << cur->unit->str() << endl << "Computed attack score = " << cur->unit->getComputedAttackScore() << endl;
        int score = computed ? cur->unit->getComputedAttackScore() : cur->unit->getAttackScore();
        if (score <= attackScore) {
            remove(cur->unit);
        }
        cur = temp;
        
    }
}

string UnitList::str() const {
    string unitListStr = "UnitList[";
    unitListStr += "count_vehicle=" + to_string(this->vehicleCount);
    unitListStr += ";count_infantry=" + to_string(this->infantryCount);

    UnitNode* cur = this->headUnit;
    if (cur) unitListStr += ";";
    while (cur) {
        unitListStr += cur->unit->str();
        if (cur->next) {
            unitListStr += ",";
        }
        cur = cur->next;
    }
    unitListStr += "]";
    return unitListStr;
}

// class Army
void Army::normalizeArmyData() {
    const int MIN_VALUE = 0;
    const int MAX_LF = 1000;
    const int MAX_EXP = 500;

    this->LF = max(this->LF, MIN_VALUE);
    this->LF = min(this->LF, MAX_LF);

    this->EXP = max(this->EXP, MIN_VALUE);
    this->EXP = min(this->EXP, MAX_EXP);
}

bool Army::checkSpecialNumber(int S, int base) {
    while (S > 0) {
        if (S % base > 1) {
            return false;
        }
        S /= base;
    }
    return true;
}

Army::Army(): LF(0), EXP(0), name(""), unitList(nullptr), battleField(nullptr) {}

Army::Army(Unit **unitArray, int size, string name, BattleField *battleField) {
    this->name = name;
    this->battleField = battleField;
    this->LF = 0;
    this->EXP = 0;
    this->battleFlag = false;
    int bases[] = {3, 5, 7};
    bool specialFlag = false;

    const int SPECIAL_CAPACITY = 12;
    const int NORMAL_CAPACITY = 8; 

    for (int i = 0; i < size; i++) {
        if (dynamic_cast<Vehicle*>(unitArray[i])) {
            this->LF += unitArray[i]->getAttackScore();
        }
        else {
            this->EXP += unitArray[i]->getAttackScore();
        }
    }

    normalizeArmyData();

    int S = this->LF + this->EXP;
    for (int i = 0; i < sizeof(bases) / sizeof(int); i++) {
        if (checkSpecialNumber(S, bases[i])) {
            specialFlag = true;
            break;
        }
    }

    if (specialFlag) {
        this->unitList = new UnitList(SPECIAL_CAPACITY);
    }
    else {
        this->unitList = new UnitList(NORMAL_CAPACITY);
    }

    for (int i = 0; i < size; i++) {
        this->unitList->insert(unitArray[i]);
    }
}

int Army::getLF() {
    return this->LF;
}

int Army::getEXP() {
    return this->EXP;
}

bool Army::getBattleFlag() {
    return this->battleFlag;
}

UnitList* Army::getUnitList() const {
    return this->unitList;
}

void Army::setLF(int LF) {
    this->LF = LF;
}

void Army::setEXP(int EXP) {
    this->EXP = EXP;
}

void Army::updateScores() {
    vector<Unit*> infantryList = this->unitList->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleList = this->unitList->getUnitsByType(VEHICLE_UNIT);
    int newEXP = 0;
    int newLF = 0;

    // for (int i = 0; i < vehicleList.size(); i++) {
    //     cout << vehicleList[i]->getAttackScore() << endl;
    // }

    for (int i = 0; i < infantryList.size(); i++)  {
        newEXP += infantryList[i]->getAttackScore();
    }
    for (int i = 0; i < vehicleList.size(); i++) {
        newLF += vehicleList[i]->getAttackScore();
    }
    this->EXP = newEXP;
    this->LF = newLF;
    normalizeArmyData();
}

void Army::removeUnit(vector<Unit*> infantryList, vector<Unit*> vehicleList) {
    for (int i = 0; i < infantryList.size(); i++) {
        this->unitList->remove(infantryList[i]);
    }
    for (int i = 0; i < vehicleList.size(); i++) {
        this->unitList->remove(vehicleList[i]);
    }
}

void Army::confiscate(Army* winner, Army* loser) {
    UnitList* winnerUL = winner->getUnitList();
    UnitList* loserUL = loser->getUnitList();
    while(!(winnerUL->isFull()) && !(loserUL->isEmpty())) {
        winnerUL->insert(loserUL->pop_back_unit());
    }
}

// class LiberationArmy
LiberationArmy::LiberationArmy(Unit **unitArray, int size, string name, BattleField *battleField) : Army(unitArray, size, name, battleField) { /*cout << "Init: " << str() << endl;*/ }

void LiberationArmy::fight(Army* enemy, bool defense) {
    if (!defense) {
        this->LF = ceil(this->LF * 1.5);
        this->EXP = ceil(this->EXP * 1.5);

        vector<Unit*> infantryUnits = this->unitList->getUnitsByType(INFANTRY_UNIT);
        vector<Unit*> vehicleUnits = this->unitList->getUnitsByType(VEHICLE_UNIT);
        // cout << "Lib before attack" << endl << str() << endl;

        // for (int i = 0; i < infantryUnits.size(); i++) {
        //         cout << infantryUnits[i]->str() << endl << "Computed attackscore = " << infantryUnits[i]->getComputedAttackScore() << endl;
        //     }
        //     for (int i = 0; i < vehicleUnits.size(); i++) {
        //         cout << vehicleUnits[i]->str() << endl;
        //     }

        vector<Unit*> infantryCombo = findMinCombination(infantryUnits, enemy->getEXP());
        vector<Unit*> vehicleCombo = findMinCombination(vehicleUnits, enemy->getLF());
        bool foundI = !infantryCombo.empty();
        bool foundV = !vehicleCombo.empty();
        // cout << "FoundI foundV " << foundI << foundV << endl;

        if (!foundI && !foundV) {
            this->battleFlag = false;
        }
        else if (!foundI && this->getEXP() > enemy->getEXP()) {
            this->battleFlag = true;
        }
        else if (!foundV && this->getLF() > enemy->getLF()) {
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
    }

    else {
        this->LF = ceil(this->LF * 1.3);
        this->EXP = ceil(this->EXP * 1.3);
        bool smallerLF = this->LF < enemy->getLF();
        bool smallerEXP = this->EXP < enemy->getEXP();
        if (smallerLF && smallerEXP) {
            this->unitList->updateUnitScore(INCREASE_TO_FIBONACCI_QUANTITY);
        }
        else if (!smallerLF && !smallerEXP) {
            // confiscate(this, enemy);
        }
        else {
            this->unitList->updateUnitScore(DECREASE_10_PERCENT_QUANTITY);
        }
    }

    // cout << "Before update score" << endl << str() << endl;
    updateScores();
    // cout << "After update score" << endl << str() << endl;
    // auto a = enemy->getUnitList()->getUnitsByType(INFANTRY_UNIT);
    // for (int i = 0; i < a.size(); i++) {
    //     cout << "After lib fight: "<< a[i]->getComputedAttackScore() << endl;
    // }
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
    libStr += ",battleField=";
    if (this->battleField) libStr += this->battleField->str();
    libStr += "]";
    return libStr;
}

vector<Unit*> LiberationArmy::findMinCombination(vector<Unit*>& units, int targetValue) {
    vector<pair<int, vector<Unit*>>> pPair;
    pPair.push_back({0, {}});

    for (int i = 0; i < units.size(); i++) {
        int unitScore = units[i]->getComputedAttackScore();
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
        if (pPair[i].second.empty()) continue;
        int score = pPair[i].first;
        if (score >= targetValue && score < minScore) {
            minScore = score;
            minCombo = pPair[i].second;
        }
    }
    return minCombo;
}

// class ARVN
ARVN::ARVN(Unit **unitArray, int size, string name, BattleField *battleField) : Army(unitArray, size, name, battleField) { /*cout << "Init: " << str() << endl;*/ }

void ARVN::fight(Army* enemy, bool defense) {
    if (!defense) {
        enemy->fight(this, true);
        this->unitList->updateUnitScore(DECREASE_20_PERCENT_QUANTITY);
        this->unitList->removeWithQuantity(1);
        updateScores();
        // cout << "After remove quantity 1: " << endl << str() << endl;
    }
    else {
    //     auto a = this->getUnitList()->getUnitsByType(INFANTRY_UNIT);
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i]->getComputedAttackScore() << endl;
    // }
        enemy->fight(this, false);
        bool battleFlag = enemy->getBattleFlag();
        // cout << "battleFlag: " << battleFlag << endl;
        if (battleFlag) {
            this->unitList->updateUnitScore(DECREASE_20_PERCENT_WEIGHT);
            updateScores();
        }
    //     for (int i = 0; i < a.size(); i++) {
    //     cout << a[i]->getComputedAttackScore() << endl;
    // }
    }
}

string ARVN::str() const {
    string arvnStr = "ARVN[";
    // arvnStr += "name=" + this->name;
    arvnStr += "LF=" + to_string(this->LF);
    arvnStr += ",EXP=" + to_string(this->EXP);
    arvnStr += ",unitList=";
    if (this->unitList) arvnStr += this->unitList->str();
    arvnStr += ",battleField=";
    if (this->battleField) arvnStr += this->battleField->str();
    arvnStr += "]";
    return arvnStr;
}

// class TerrainElement
TerrainElement::TerrainElement(): pos(nullptr) {}

TerrainElement::~TerrainElement() {
    if (pos) delete this->pos;
}

Position* TerrainElement::getPosition() {
    return this->pos;
}

void TerrainElement::setPosition(Position* p) {
    this->pos = p;
}

// class Road
void Road::getEffect(Army *army) {
    // no effect
}

// class Mountain
void Mountain::updateArmyScore(vector<Unit*>& units, double disThreshold, double ratio, int& score, bool increase) {
    for (int i = 0; i < (int)(units.size()); i++) {
        double distance = Position::calculateDistance(*(this->pos), units[i]->getCurrentPosition());
        if (distance <= disThreshold) {
            if (increase) {
                score += ceil(ratio * units[i]->getComputedAttackScore());
                // cout << (units[i]->getComputedAttackScore()) << endl;
                // cout << (ratio * units[i]->getComputedAttackScore()) << endl;
            }
            else {
                score -= ceil(ratio * units[i]->getComputedAttackScore());
            }
        }
    }
}

void Mountain::getEffect(Army* army) {
    if (!army) return;
    int EXP = army->getEXP();
    int LF = army->getLF();
    // cout << "EXP before: " << EXP << endl;
    UnitList* ul = army->getUnitList();
    vector<Unit*> infantryUnits = ul->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleUnits = ul->getUnitsByType(VEHICLE_UNIT);

    if (dynamic_cast<LiberationArmy*>(army)) {
        updateArmyScore(infantryUnits, 2, 0.3, EXP);
        updateArmyScore(vehicleUnits, 2, 0.1, LF, false);
    }
    else {
        updateArmyScore(infantryUnits, 4, 0.2, EXP);
        updateArmyScore(vehicleUnits, 4, 0.05, LF, false);
    }
    army->setEXP(EXP);
    army->setLF(LF);
    army->normalizeArmyData();
    // cout << "Mountain" << endl << army->str() << endl << "LF = " << army->getLF() << ", EXP = " << army->getEXP() << endl;
}

// class River
void River::getEffect(Army* army) {
    if (!army) return;
    UnitList* ul = army->getUnitList();
    vector<Unit*> infantryUnits = ul->getUnitsByType(INFANTRY_UNIT);
    for (int i = 0; i < (int)(infantryUnits.size()); i++) {
        double distance = Position::calculateDistance(*(this->pos), infantryUnits[i]->getCurrentPosition());
        if (distance <= 2) {
            int oldScore = infantryUnits[i]->getComputedAttackScore();
            int newScore = oldScore - ceil(oldScore * 0.1);
            infantryUnits[i]->setComputedAttackScore(ceil(newScore));
        }
    }
}

// class Urban
void Urban::updateAttackScore(vector<Unit*>& units, vector<int> types, double disThreshold, double coefficient, bool infantry) {
    for (int i = 0; i < (int)(units.size()); i++) {
        int type = units[i]->getEnumType();
        double distance = Position::calculateDistance(*(this->pos), units[i]->getCurrentPosition());
        bool found = false;
        for (int j = 0; j < (int)(types.size()); j++) {
            if (type == types[i]) {
                found = true;
                break;
            }
        }
        if (found && distance <= disThreshold) {
            int oldScore = units[i]->getComputedAttackScore();
            int newScore;
            if (infantry) {
                newScore = oldScore + ceil(coefficient * oldScore / distance);
            }
            else {
                newScore = oldScore - ceil(oldScore * coefficient);
            }
            units[i]->setComputedAttackScore(ceil(newScore));
        }
    }
}

void Urban::getEffect(Army* army) {
    if (!army) return;
    UnitList* ul = army->getUnitList();
    vector<Unit*> infantryUnits = ul->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleUnits = ul->getUnitsByType(VEHICLE_UNIT);

    if (dynamic_cast<LiberationArmy*>(army)) {
        vector<int> infTypes = {SPECIALFORCES, REGULARINFANTRY};
        vector<int> vehTypes = {ARTILLERY};
        updateAttackScore(infantryUnits, infTypes, 5, 2);
        updateAttackScore(vehicleUnits, vehTypes, 2, 0.5, false);

    }
    else {
        vector<int> infTypes = {REGULARINFANTRY};
        double coefficient = 1.5;
        updateAttackScore(infantryUnits, infTypes, 3, coefficient);
    }
}

// class Fortification
void Fortification::updateAttackScore(vector<Unit*>& units, double disThreshold, double coefficient) {
    for(int i = 0; i < (int)(units.size()); i++) {
        double distance = Position::calculateDistance(*(this->pos), units[i]->getCurrentPosition());
        if (distance <= disThreshold) {
            int oldScore = units[i]->getComputedAttackScore();
            int newScore = ceil(oldScore * coefficient);
            units[i]->setComputedAttackScore(ceil(newScore));
        }
    }
}

void Fortification::getEffect(Army* army) {
    if (!army) return;
    UnitList* ul = army->getUnitList();
    vector<Unit*> infantryUnits = ul->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleUnits = ul->getUnitsByType(VEHICLE_UNIT);

    if (dynamic_cast<LiberationArmy*>(army)) {
        updateAttackScore(infantryUnits, 2, 1 - 0.2);
        updateAttackScore(vehicleUnits, 2, 1 - 0.2);
    }
    else {
        updateAttackScore(infantryUnits, 2, 1 + 0.2);
        updateAttackScore(vehicleUnits, 2, 1 + 0.2);
    }
}

// class SpecialZone
void SpecialZone::setAttackScoreZero(vector<Unit*>& units) {
    for (int i = 0; i < (int)(units.size()); i++) {
        double distance = Position::calculateDistance(*(this->pos), units[i]->getCurrentPosition());
        if (distance <= 1) {
            units[i]->setComputedAttackScore(0);
        }
    }
}

void SpecialZone::getEffect(Army* army) {
    if (!army) return;
    UnitList* ul = army->getUnitList();
    vector<Unit*> infantryUnits = ul->getUnitsByType(INFANTRY_UNIT);
    vector<Unit*> vehicleUnits = ul->getUnitsByType(VEHICLE_UNIT);
    setAttackScoreZero(infantryUnits);
    setAttackScoreZero(vehicleUnits);
}

// class BattleField
void BattleField::setTerrain(vector<Position *> posList, TerrainType type) {
    for (int i = 0; i < (int)(posList.size()); i++) {
        Position* p = posList[i];
        int r = p->getRow();
        int c = p->getCol();
        if ((r >= 0 && r < n_rows) && (c >= 0 && c < n_cols)) {
            if (type == MOUNTAIN) {
                terrain[r][c] = new Mountain;
            }
            else if (type == RIVER) {
                terrain[r][c] = new River;
            }
            else if (type == URBAN) {
                terrain[r][c] = new Urban;
            }
            else if (type == FORTIFICATION) {
                terrain[r][c] = new Fortification;
            }
            else if (type == SPECIALZONE) {
                terrain[r][c] = new SpecialZone;
            }
            if (terrain[r][c]) terrain[r][c]->setPosition(p);
        }
    }
}

BattleField::BattleField(int n_rows, int n_cols,
                vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone) {
    this->n_rows = n_rows;
    this->n_cols = n_cols;
    this->terrain = new vector<TerrainElement*>[n_rows];
    for (int i = 0; i < n_rows; i++) {
        this->terrain[i] = vector<TerrainElement*>(n_cols, nullptr);
    }

    setTerrain(arrayForest, MOUNTAIN);
    setTerrain(arrayRiver, RIVER);
    setTerrain(arrayFortification, FORTIFICATION);
    setTerrain(arrayUrban, URBAN);
    setTerrain(arraySpecialZone, SPECIALZONE);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (terrain[i][j] == nullptr) {
                terrain[i][j] = new Road;
                terrain[i][j]->setPosition(new Position(i, j));
            }
        }
    }
}

BattleField::~BattleField() {
    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            delete terrain[i][j];
        }
    }
    delete[] terrain;
}

TerrainElement* BattleField::getTerrainElement(int i, int j) {
    if (i < 0 || i >= this->n_rows || j < 0 || j >= this->n_cols) return nullptr;
    return this->terrain[i][j];
}

int BattleField::getNRows() const {
    return this->n_rows;
}

int BattleField::getNCols() const {
    return this->n_cols;
}

void BattleField::getTerrainEffect(Army* army) {
    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            TerrainElement* t = this->terrain[i][j];
            if (dynamic_cast<Mountain*>(t)) {
                t->getEffect(army);
            }
        }
    }

    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            TerrainElement* t = this->terrain[i][j];
            if (dynamic_cast<River*>(t)) {
                t->getEffect(army);
            }
        }
    }

    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            TerrainElement* t = this->terrain[i][j];
            if (dynamic_cast<Urban*>(t)) {
                t->getEffect(army);
            }
        }
    }

    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            TerrainElement* t = this->terrain[i][j];
            if (dynamic_cast<Fortification*>(t)) {
                t->getEffect(army);
            }
        }
    }

    for (int i = 0; i < this->n_rows; i++) {
        for (int j = 0; j < this->n_cols; j++) {
            TerrainElement* t = this->terrain[i][j];
            if (dynamic_cast<SpecialZone*>(t)) {
                t->getEffect(army);
            }
        }
    }
}

string BattleField::str() {
    string bfStr = "BattleField[";
    bfStr += "n_rows=" + to_string(this->n_rows);
    bfStr += ",n_cols=" + to_string(this->n_cols);
    bfStr += "]";
    return bfStr;
}

// class Configuration
void Configuration::normalizeConfigData() {
    const int MAX_EVENT = 99;
    const int MIN_EVENT = 0;
    this->eventCode = min(this->eventCode, MAX_EVENT);
    this->eventCode = max(this->eventCode, MIN_EVENT);
}

void Configuration::convertUnitType(InfantryType& iType, VehicleType& vType, bool& infantry, string unitName) {
    // cout << "Unitname: " << unitName << endl;
    if (unitName == "TRUCK" || unitName == "MORTAR" || unitName == "ANTIAIRCRAFT" || unitName == "ARMOREDCAR" || unitName == "APC" || unitName == "ARTILLERY" || unitName == "TANK") {
        infantry = false;
        vType = Vehicle::convertToVehicleType(unitName);
    }
    
    else {
        infantry = true;
        iType = Infantry::convertToInfantryType(unitName);
    }
}

void Configuration::readPositionArray(const string& str, vector<Position*>& array) {
    string pStr = str.substr(1, str.length() - 2);
    if (pStr.length() == 0) return;
    stringstream ss(pStr);
    char c;
    int x;
    int y;
    while (ss >> c) {
        if (c == '(') { // (x,y)
            ss >> x >> c >> y >> c;
            array.push_back(new Position(x, y));
        }
    }
}

void Configuration::readUnitList(const string& str) {
    string uStr = str.substr(1, str.length() - 2);
    if (uStr.length() == 0) return;
    int index = 0;
    vector<Unit*> libVector;
    vector<Unit*> ARVector;
    int count = 0;
    while (index < uStr.length() - 1) {
        int unitNameEnd = uStr.find('(', index);
        string unitName = uStr.substr(index, unitNameEnd - index);
        int unitEnd = uStr.find(')', index);
        unitEnd = uStr.find(')', unitEnd + 1);
        string parameters = uStr.substr(unitNameEnd + 1, unitEnd - unitNameEnd - 1);
        int quantity, weight, x, y, armyBelong;
        char c;
        stringstream ss(parameters);
        ss >> quantity >> c >> weight >> c >> c >> x >> c >> y >> c >> c >> armyBelong;
        bool infantry;
        InfantryType iType;
        VehicleType vType;
        convertUnitType(iType, vType, infantry, unitName);
        Unit* newUnit;
        if (infantry) {
            newUnit = new Infantry(quantity, weight, Position(x, y), iType);
        }
        else {
            newUnit = new Vehicle(quantity, weight, Position(x, y), vType);
        }
        if (armyBelong == 0) {
            libVector.push_back(newUnit);
        }
        else {
            ARVector.push_back(newUnit);
        }

        index = unitEnd + 2;
        count++;
    }

    this->num_lib_unit = libVector.size();
    this->num_ar_unit = ARVector.size();
    this->liberationUnits = new Unit*[num_lib_unit];
    this->ARVNUnits = new Unit*[num_ar_unit];
    for (int i = 0; i < num_lib_unit; i++) {
        this->liberationUnits[i] = libVector[i];
    }
    for (int i = 0; i < num_ar_unit; i++) {
        this->ARVNUnits[i] = ARVector[i];
    }

}

Configuration::Configuration(const string& filepath) {
    ifstream f(filepath);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            // cout << line << endl;
            int equalPos = line.find("=");
            if (equalPos == string::npos) continue;

            int keyStart = 0;
            while (keyStart < equalPos && line[keyStart] == ' ') keyStart++;
            int keyEnd = equalPos - 1;
            while (keyEnd >= 0 && line[keyEnd] == ' ') keyEnd--;
            string key = line.substr(keyStart, keyEnd - keyStart + 1);

            int valueStart = equalPos + 1;
            while (valueStart < (int)line.length() && line[valueStart] == ' ') valueStart++;
            int valueEnd = line.length() - 1;
            while (valueEnd >= valueStart && line[valueEnd] == ' ') valueEnd--;
            string value = line.substr(valueStart, valueEnd - valueStart + 1);

            if (key == "NUM_ROWS") {
                this->num_rows = stoi(value);
            }
            else if (key == "NUM_COLS") {
                this->num_cols = stoi(value);
            }
            else if (key == "ARRAY_FOREST") {
                readPositionArray(value, this->arrayForest);
            }
            else if (key == "ARRAY_RIVER") {
                readPositionArray(value, this->arrayRiver);
            }
            else if (key == "ARRAY_FORTIFICATION") {
                readPositionArray(value, this->arrayFortification);
            }
            else if (key == "ARRAY_URBAN") {
                readPositionArray(value, this->arrayUrban);
            }
            else if (key == "ARRAY_SPECIAL_ZONE") {
                readPositionArray(value, this->arraySpecialZone);
            }
            else if (key == "UNIT_LIST") {
                readUnitList(value);
            }
            else if (key == "EVENT_CODE") {
                this->eventCode = stoi(value);
            }
        }
        normalizeConfigData();

        // cout << "num col: " << num_cols << endl;
        // cout << "event code: " << eventCode << endl;

        f.close();
    }
}

Configuration::~Configuration() {
    for (int i = 0; i < (int)(arrayForest.size()); i++) {
        delete arrayForest[i];
    }
    for (int i = 0; i < (int)(arrayRiver.size()); i++) {
        delete arrayRiver[i];
    }
    for (int i = 0; i < (int)(arrayFortification.size()); i++) {
        delete arrayFortification[i];
    }
    for (int i = 0; i < (int)(arrayUrban.size()); i++) {
        delete arrayUrban[i];
    }
    for (int i = 0; i < (int)(arraySpecialZone.size()); i++) {
        delete arraySpecialZone[i];
    }
    for (int i = 0; i < num_lib_unit; i++) {
        delete liberationUnits[i];
    }
    for (int i = 0; i < num_ar_unit; i++) {
        delete ARVNUnits[i];
    }
    delete[] liberationUnits;
    delete[] ARVNUnits;
}

int Configuration::getNumRows() const {
    return this->num_rows;
}

int Configuration::getNumCols() const {
    return this->num_cols;
}

vector<Position*> Configuration::getArrayForest() const {
    return this->arrayForest;
}

vector<Position*> Configuration::getArrayRiver() const {
    return this->arrayRiver;
}

vector<Position*> Configuration::getArrayFortification() const {
    return this->arrayFortification;
}

vector<Position*> Configuration::getArrayUrban() const {
    return this->arrayUrban;
}

vector<Position*> Configuration::getArraySpecialZone() const {
    return this->arraySpecialZone;
}

Unit** Configuration::getLiberationUnits() const {
    return this->liberationUnits;
}

Unit** Configuration::getARVNUnits() const {
    return this->ARVNUnits;
}

int Configuration::getNumLibUnit() const {
    return this->num_lib_unit;
}

int Configuration::getNumARUnit() const {
    return this->num_ar_unit;
}

int Configuration::getEventCode() const {
    return this->eventCode;
}

string Configuration::str() const {
    string configStr = "[";
    configStr += "num_rows=" + to_string(this->num_rows);
    configStr += ",num_cols=" + to_string(this->num_cols);
    configStr += ",arrayForest=[";
    for (int i = 0; i <(int)(arrayForest.size()); i++) {
        if (i != 0) configStr += ",";
        configStr += arrayForest[i]->str();
    }
    configStr += "],arrayRiver=[";
    for (int i = 0; i <(int)(arrayRiver.size()); i++) {
        if (i != 0) configStr += ",";
        configStr += arrayRiver[i]->str();
    }
    configStr += "],arrayFortification=[";
    for (int i = 0; i <(int)(arrayFortification.size()); i++) {
        if (i != 0) configStr += ",";
        configStr += arrayFortification[i]->str();
    }
    configStr += "],arrayUrban=[";
    for (int i = 0; i <(int)(arrayUrban.size()); i++) {
        if (i != 0) configStr += ",";
        configStr += arrayUrban[i]->str();
    }
    configStr += "],arraySpecialZone=[";
    for (int i = 0; i <(int)(arraySpecialZone.size()); i++) {
        if (i != 0) configStr += ",";
        configStr += arraySpecialZone[i]->str();
    }
    configStr += "],liberationUnits=[";
    for (int i = 0; i < num_lib_unit; i++) {
        if (i != 0) configStr += ",";
        configStr += liberationUnits[i]->str();
    }
    configStr += "],ARVNUnits=[";
    for (int i = 0; i < num_ar_unit; i++) {
        if (i != 0) configStr += ",";
        configStr += ARVNUnits[i]->str();
    }
    configStr += "],eventCode=" + to_string(eventCode);
    configStr += "]";
    return configStr;
}

// class HCMCampaign
HCMCampaign::HCMCampaign(const string &config_file_path) {
    this->config = new Configuration(config_file_path);
    // cout << "In HCM, config = " << this->config->str() << endl;

    int n_rows = this->config->getNumRows();
    int n_cols = this->config->getNumCols();
    // cout << "n_rows = " << n_rows << ", n_cols = " << n_cols << endl;
    vector<Position*> arrayForest = this->config->getArrayForest();
    vector<Position*> arrayRiver = this->config->getArrayRiver();
    vector<Position*> arrayFortification = this->config->getArrayFortification();
    vector<Position*> arrayUrban = this->config->getArrayUrban();
    vector<Position*> arraySpecialZone = this->config->getArraySpecialZone();

    this->battleField = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    Unit** libUnit = this->config->getLiberationUnits();
    int libSize = this->config->getNumLibUnit();
    this->liberationArmy = new LiberationArmy(libUnit, libSize, "Liberation Army", this->battleField);

    Unit** arUnit = this->config->getARVNUnits();
    int arSize = this->config->getNumARUnit();
    this->arvn = new ARVN(arUnit, arSize, "ARVN Army", this->battleField);
}

void HCMCampaign::run() {
    cout << ": LBRA: " << this->liberationArmy->str() << endl;
    cout << ": ARVN: " << this->arvn->str() << endl;

    if (this->battleField) {
        this->battleField->getTerrainEffect(this->liberationArmy);
        this->battleField->getTerrainEffect(this->arvn);
    }
    cout << "RUN: LBRA: " << this->liberationArmy->str() << endl;
    cout << "RUN: ARVN: " << this->arvn->str() << endl;

    int eventCode = this->config->getEventCode();
    if (eventCode < 75) {
        this->arvn->fight(this->liberationArmy, true);
        cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        cout << "PRINT: ARVN: " << this->arvn->str() << endl;
    }
    else {
        this->arvn->fight(this->liberationArmy, false);
        cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        cout << "PRINT: ARVN: " << this->arvn->str() << endl;
        this->liberationArmy->fight(this->arvn, false);
        cout << "PRINT: LBRA: " << this->liberationArmy->str() << endl;
        cout << "PRINT: ARVN: " << this->arvn->str() << endl;
    }
    bool battleFlag = this->liberationArmy->getBattleFlag();
    this->liberationArmy->getUnitList()->removeWithAttackScore(5, !battleFlag);
    this->arvn->getUnitList()->removeWithAttackScore(5, !battleFlag);
    this->liberationArmy->updateScores();
    this->arvn->updateScores();

    cout << "REMOVED: LBRA: " << this->liberationArmy->str() << endl;
    cout << "REMOVED: ARVN: " << this->arvn->str() << endl;
}

string HCMCampaign::printResult() {
    string str = "LIBERATIONARMY[";
    str += "LF=" + to_string(this->liberationArmy->getLF());
    str += ",EXP=" + to_string(this->liberationArmy->getEXP());
    str += "]-ARVN[";
    str += "LF=" + to_string(this->arvn->getLF());
    str += ",EXP=" + to_string(this->arvn->getEXP());
    str += "]";
    return str;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////