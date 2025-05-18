#include "UnitList.h"

UnitList::UnitList(int capacity) {
    this->capacity = capacity;
    this->vehicleCount = 0;
    this->infantryCount = 0;
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

            if (sameDataType && (cur->unit->getEnumType() == unit->getEnumType())) {
                foundFlag = true;
                int newQuantity = cur->unit->getQuantity() + unit->getQuantity();
                cur->unit->setQuantity(newQuantity);
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