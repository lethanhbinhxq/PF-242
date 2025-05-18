#include "Vehicle.h"

//!----------------------------------------------
//! Lớp Vehicle
//!----------------------------------------------
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
    score *= this->terrainModifier;
    return ceil(score);
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