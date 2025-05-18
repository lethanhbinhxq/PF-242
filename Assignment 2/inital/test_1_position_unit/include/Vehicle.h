#ifndef VEHICLE_H
#define VEHICLE_H

#include "Unit.h"

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

#endif // VEHICLE_H
