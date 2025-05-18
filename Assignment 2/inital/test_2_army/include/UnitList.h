#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"

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
};

#endif
