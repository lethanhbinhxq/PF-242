/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 2
 * Programming Fundamentals Spring 2025
 * Date: 02.02.2025
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_HCM_CAMPAIGN_H_
#define _H_HCM_CAMPAIGN_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
class Unit; // done
class UnitList; // done
class Army; // done
class TerrainElement; // done

class Vehicle; // done
class Infantry; // done

class LiberationArmy; // done
class ARVN; // done

class Position; // done

class Road; // done
class Mountain; // done
class River; // done
class Urban; // done
class Fortification;
class SpecialZone; // done

class BattleField; // done

class HCMCampaign;
class Configuration; // done

enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};
enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

enum UnitType {
    INFANTRY_UNIT,
    VEHICLE_UNIT
};

enum UpdateUnitFlag {
    DECREASE_10_PERCENT_WEIGHT,
    DECREASE_20_PERCENT_WEIGHT,
    DECREASE_10_PERCENT_QUANTITY,
    INCREASE_TO_FIBONACCI_QUANTITY,
    DECREASE_20_PERCENT_QUANTITY
};

enum TerrainType {
    ROAD,
    MOUNTAIN,
    RIVER,
    URBAN,
    FORTIFICATION,
    SPECIALZONE
};

class Army
{
protected:
    int LF, EXP;
    string name;
    UnitList *unitList;
    BattleField *battleField;
    bool battleFlag;

    void normalizeArmyData();
    bool checkSpecialNumber(int S, int base);

public:
    Army();
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
    int getLF();
    int getEXP();
    UnitList* getUnitList() const;
    void setLF(int LF);
    void setEXP(int EXP);
    void updateScores();
    void removeUnit(vector<Unit*> infantryList = {}, vector<Unit*> vehicleList = {});
    void confiscate(Army* winner, Army* loser);
    bool getBattleFlag();
};

class LiberationArmy : public Army {
public:
    LiberationArmy(Unit **unitArray, int size, string name, BattleField *battleField);
    void fight(Army* enemy, bool defense = false);
    bool getBattleFlag();
    string str() const;
private:
    vector<Unit*> findMinCombination(vector<Unit*>& units, int targetValue);
};

class ARVN : public Army {
public:
    ARVN(Unit **unitArray, int size, string name, BattleField *battleField);
    void fight(Army* enemy, bool defense = false);
    string str() const;
};

class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos); // Example: str_pos = "(1,15)"
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const; // Example: returns "(1,15)"
    static double calculateDistance(Position a, Position b);
};

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    int computedAttackScore;

public:
    Unit();
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    Position getCurrentPosition() const;
    virtual string str() const = 0;
    int getQuantity() const;
    void setQuantity(int quantity);
    int getWeight() const;
    void setWeight(int weight);
    int getComputedAttackScore() const;
    void setComputedAttackScore(int score);
    virtual int getEnumType() const = 0;
};

class Vehicle : public Unit {
private:
    VehicleType vehicleType;
    string vehicleTypeString() const;
public:
    Vehicle(int quantity, int weight, const Position pos, VehicleType vehicleType);
    ~Vehicle();
    int getAttackScore();
    int getEnumType() const;
    string str() const;
    static VehicleType convertToVehicleType(string str);
};

class Infantry : public Unit {
private:
    InfantryType infantryType;
    bool checkPerfectSquare(int weight);
    int getPersonalNumber(int score, int year = 1975);
    string infantryTypeString() const;
public:
    Infantry(int quantity, int weight, const Position pos, InfantryType infantryType);
    ~Infantry();
    int getAttackScore();
    int getEnumType() const;
    string str() const;
    static InfantryType convertToInfantryType(string str);
};

class UnitList
{
private:
    // TODO
    class UnitNode {
    public:
        Unit* unit;
        UnitNode* next;

        UnitNode(Unit* unit, UnitNode* next = nullptr) {
            this->unit = unit;
            this->next = next;
        }
    };

    int capacity;
    int vehicleCount;
    int infantryCount;
    UnitNode* headUnit;
    UnitNode* tailUnit;

    void insertFront(UnitNode* newNode);
    void insertRear(UnitNode* newNode);

    int nextNearestFibonacci(int n);
public:
    UnitList(int capacity);
    ~UnitList();
    bool insert(Unit *unit);                   // return true if insert successfully
    bool isContain(VehicleType vehicleType);   // return true if it exists
    bool isContain(InfantryType infantryType); // return true if it exists
    string str() const;
    // TODO
    void remove(Unit* unit);
    vector<Unit*> getUnitsByType(UnitType type = INFANTRY_UNIT);
    void updateUnitScore(UpdateUnitFlag flag = DECREASE_10_PERCENT_QUANTITY);
    void addUnitList(UnitList list);
    void clear();
    bool isFull();
    bool isEmpty();
    Unit* pop_back_unit();
    void removeWithQuantity(int quantity = 1);
    void removeWithAttackScore(int attackScore = 5);
};

class TerrainElement
{
protected:
    Position* pos;
public:
    TerrainElement();
    ~TerrainElement();
    Position* getPosition();
    void setPosition(Position* p);
    virtual void getEffect(Army *army) = 0;
};

class Road : public TerrainElement {
public:
    void getEffect(Army *army);
};

class Mountain : public TerrainElement {
private:
    void updateArmyScore(vector<Unit*>& units, double disThreshold, double ratio, double& score, bool increase = true);
public:
    void getEffect(Army* army);
};

class River : public TerrainElement {
public:
    void getEffect(Army* army);
};

class Urban : public TerrainElement {
private:
    void updateAttackScore(vector<Unit*>& units, vector<int> types, double disThreshold, double coefficient, bool infantry = true);
public:
    void getEffect(Army* army);
};

class Fortification : public TerrainElement {
private:
    void updateAttackScore(vector<Unit*>& units, double disThreshold, double terrainModifier);
public:
    void getEffect(Army* army);
};

class SpecialZone : public TerrainElement {
private:
    void setAttackScoreZero(vector<Unit*>& units);
public:
    void getEffect(Army* army);
};

class BattleField
{
private:
    int n_rows, n_cols;
    // TODO
    vector<TerrainElement*>* terrain;
    void setTerrain(vector<Position *> posList = vector<Position*>(), TerrainType type = MOUNTAIN);
public:
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();
    int getNRows() const;
    int getNCols() const;
    TerrainElement* getTerrainElement(int i, int j);
    string str();
};

class Configuration {
private:
    int num_rows;
    int num_cols;
    vector<Position*> arrayForest;
    vector<Position*> arrayRiver;
    vector<Position*> arrayFortification;
    vector<Position*> arrayUrban;
    vector<Position*> arraySpecialZone;
    Unit** liberationUnits;
    Unit** ARVNUnits;
    int num_lib_unit;
    int num_ar_unit;
    int eventCode;

    void normalizeConfigData();
    void readPositionArray(const string& str, vector<Position*>& array);
    void readUnitList(const string& str);
    void convertUnitType(InfantryType& iType, VehicleType& vType, bool& infantry, string unitName);
public:
    Configuration(const string& filepath);
    ~Configuration();
    int getNumRows() const;
    int getNumCols() const;
    vector<Position*> getArrayForest() const;
    vector<Position*> getArrayRiver() const;
    vector<Position*> getArrayFortification() const;
    vector<Position*> getArrayUrban() const;
    vector<Position*> getArraySpecialZone() const;
    Unit** getLiberationUnits() const;
    Unit** getARVNUnits() const;
    int getNumLibUnit() const;
    int getNumARUnit() const;
    int getEventCode() const;
    string str() const;
};

class HCMCampaign
{
private:
    Configuration *config;
    BattleField *battleField;
    LiberationArmy *liberationArmy;
    ARVN *arvn;

public:
    HCMCampaign(const string &config_file_path);
    void run();
    string printResult();
};

#endif