#include "Configuration.h"
void processFile(const string &filename, TerrainType **&battlefield, int &NUM_ROWS, int &NUM_COLS, vector<UNIT_NAME> &units, int &EVENT_CODE) {
    ifstream f(filename);
    assert(f.is_open());

    NUM_ROWS = 0;
    NUM_COLS = 0;
    EVENT_CODE = 0;
    battlefield = nullptr;
    units.clear();

    // Temporary storage for terrain coordinates by type
    vector<pair<int,int>> forest_coords;
    vector<pair<int,int>> river_coords;
    vector<pair<int,int>> fortification_coords;
    vector<pair<int,int>> urban_coords;
    vector<pair<int,int>> special_zone_coords;

    string unit_list_str; // Will accumulate UNIT_LIST lines

    string line;
    while (getline(f, line)) {
        int equalPos = line.find('=');
        if (equalPos == string::npos) continue;

        // trim key
        int keyStart = 0;
        while (keyStart < equalPos && line[keyStart] == ' ') keyStart++;
        int keyEnd = equalPos - 1;
        while (keyEnd >= 0 && line[keyEnd] == ' ') keyEnd--;
        string key = line.substr(keyStart, keyEnd - keyStart + 1);

        // trim value
        int valueStart = equalPos + 1;
        while (valueStart < (int)line.length() && line[valueStart] == ' ') valueStart++;
        int valueEnd = line.length() - 1;
        while (valueEnd >= valueStart && line[valueEnd] == ' ') valueEnd--;
        string value = line.substr(valueStart, valueEnd - valueStart + 1);

        if (key == "NUM_ROWS") {
            NUM_ROWS = stoi(value);
        } else if (key == "NUM_COLS") {
            NUM_COLS = stoi(value);
        } else if (key == "EVENT_CODE") {
            EVENT_CODE = stoi(value);
            if (EVENT_CODE < 0) EVENT_CODE = 0;
            else if (EVENT_CODE > 99) EVENT_CODE %= 100;
        } 
        else if (key == "ARRAY_FOREST" || key == "ARRAY_RIVER" || key == "ARRAY_FORTIFICATION" || key == "ARRAY_URBAN" || key == "ARRAY_SPECIAL_ZONE") {
            string pStr = value.substr(1, value.length() - 2); // strip [ ]
            if (pStr.length() == 0) continue;
            stringstream ss(pStr);
            char c;
            int x,y;
            while (ss >> c) {
                if (c == '(') {
                    ss >> x >> c >> y >> c;
                    if (key == "ARRAY_FOREST") forest_coords.emplace_back(x,y);
                    else if (key == "ARRAY_RIVER") river_coords.emplace_back(x,y);
                    else if (key == "ARRAY_FORTIFICATION") fortification_coords.emplace_back(x,y);
                    else if (key == "ARRAY_URBAN") urban_coords.emplace_back(x,y);
                    else special_zone_coords.emplace_back(x,y);
                }
            }
        }
        else if (key == "UNIT_LIST") {
            unit_list_str = value;
            // If unit list not complete (no closing ']'), read more lines until found
            while (unit_list_str.find(']') == string::npos && getline(f, line)) {
                unit_list_str += line;
            }
        }
    }
    f.close();

    // Now initialize battlefield after NUM_ROWS and NUM_COLS are known
    if (NUM_ROWS > 0 && NUM_COLS > 0) {
        battlefield = new TerrainType*[NUM_ROWS];
        for (int i = 0; i < NUM_ROWS; i++) {
            battlefield[i] = new TerrainType[NUM_COLS];
            for (int j = 0; j < NUM_COLS; j++) {
                battlefield[i][j] = ROAD;
            }
        }
    }

    // Apply terrain from saved coordinates
    for (auto &p : forest_coords) {
        if (p.first >= 0 && p.first < NUM_ROWS && p.second >=0 && p.second < NUM_COLS)
            battlefield[p.first][p.second] = FOREST;
    }
    for (auto &p : river_coords) {
        if (p.first >= 0 && p.first < NUM_ROWS && p.second >=0 && p.second < NUM_COLS)
            battlefield[p.first][p.second] = RIVER;
    }
    for (auto &p : fortification_coords) {
        if (p.first >= 0 && p.first < NUM_ROWS && p.second >=0 && p.second < NUM_COLS)
            battlefield[p.first][p.second] = FORTIFICATION;
    }
    for (auto &p : urban_coords) {
        if (p.first >= 0 && p.first < NUM_ROWS && p.second >=0 && p.second < NUM_COLS)
            battlefield[p.first][p.second] = URBAN;
    }
    for (auto &p : special_zone_coords) {
        if (p.first >= 0 && p.first < NUM_ROWS && p.second >=0 && p.second < NUM_COLS)
            battlefield[p.first][p.second] = SPECIAL_ZONE;
    }

    // Parse units from unit_list_str if non-empty
    if (!unit_list_str.empty()) {
        // Extract substring inside brackets [ ... ]
        size_t start = unit_list_str.find('[');
        size_t end = unit_list_str.find(']');
        if (start != string::npos && end != string::npos && end > start) {
            string unitsContent = unit_list_str.substr(start + 1, end - start - 1);

            // Remove tabs, newlines, returns
            string filtered;
            for (char ch : unitsContent) {
                if (ch != '\t' && ch != '\n' && ch != '\r') filtered.push_back(ch);
            }

            // Split by commas outside parentheses
            vector<string> unitTokens;
            int parenDepth = 0;
            size_t lastPos = 0;
            for (size_t i = 0; i < filtered.size(); i++) {
                if (filtered[i] == '(') parenDepth++;
                else if (filtered[i] == ')') parenDepth--;
                else if (filtered[i] == ',' && parenDepth == 0) {
                    unitTokens.push_back(filtered.substr(lastPos, i - lastPos));
                    lastPos = i + 1;
                }
            }
            if (lastPos < filtered.size()) {
                unitTokens.push_back(filtered.substr(lastPos));
            }

            // Parse each token
            for (string &token : unitTokens) {
                // trim whitespace
                size_t first = 0;
                while (first < token.size() && isspace(token[first])) first++;
                size_t last = token.size();
                while (last > first && isspace(token[last-1])) last--;
                token = token.substr(first, last - first);
                if (token.empty()) continue;

                size_t posParen = token.find('(');
                if (posParen == string::npos) continue;

                string unitTypeStr = token.substr(0, posParen);
                InfantryType type;
                if (unitTypeStr == "SNIPER") type = SNIPER;
                else if (unitTypeStr == "ANTIAIRCRAFTSQUAD") type = ANTIAIRCRAFTSQUAD;
                else if (unitTypeStr == "MORTARSQUAD") type = MORTARSQUAD;
                else if (unitTypeStr == "ENGINEER") type = ENGINEER;
                else if (unitTypeStr == "SPECIALFORCES") type = SPECIALFORCES;
                else if (unitTypeStr == "REGULARINFANTRY") type = REGULARINFANTRY;
                else continue;

                string params = token.substr(posParen + 1, token.length() - posParen - 2);
                stringstream paramSS(params);
                int quantity, weight, pos_x, pos_y, armyBelong;
                char ch;

                paramSS >> quantity >> ch;
                paramSS >> weight >> ch;
                paramSS >> ch; // '('
                paramSS >> pos_x >> ch >> pos_y >> ch >> ch;
                paramSS >> armyBelong;

                UNIT_NAME unit;
                unit.type = type;
                unit.quantity = quantity;
                unit.weight = weight;
                unit.position_x = pos_x;
                unit.position_y = pos_y;
                unit.armyBelong = armyBelong;

                units.push_back(unit);
            }
        }
    }
}

string print_battlefield(const TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS){
    stringstream ss;
    // TODO
    if (!battlefield) {
        ss << "";
    }
    else {
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                TerrainType type = battlefield[i][j];
                if (j != 0) ss << " ";
                if (type == ROAD) ss << "ROA";
                else if (type == FOREST) ss << "FOR";
                else if (type == RIVER) ss << "RIV";
                else if (type == FORTIFICATION) ss << "FOR";
                else if (type == URBAN) ss << "URB";
                else if (type == SPECIAL_ZONE) ss << "SPE";
            }
            if (i != NUM_ROWS - 1) ss << endl;
        }
    }
    return ss.str();  
}
string print_UNIT_NAME(const vector<UNIT_NAME> &units) {
    stringstream ss;
    // TODO
    ss << "[" << endl;
    for (int i = 0; i < units.size(); i++) {
        // ss << "\t";
        InfantryType type = units[i].type;
        if (type == SNIPER) ss << "SNIPER";
        else if (type == ANTIAIRCRAFTSQUAD) ss << "ANTIAIRCRAFTSQUAD";
        else if (type == MORTARSQUAD) ss << "MORTARSQUAD";
        else if (type == ENGINEER) ss << "ENGINEER";
        else if (type == SPECIALFORCES) ss << "SPECIALFORCES";
        else if (type == REGULARINFANTRY) ss << "REGULARINFANTRY";
        ss << "(" << units[i].quantity << "," << units[i].weight << ",(" << units[i].position_x << "," << units[i].position_y << ")," << units[i].armyBelong << ")";
        if (i != units.size() - 1) ss << ",";
        ss << endl;
    }
    if (units.size() == 0) {
        ss << endl;
    }
    ss << "]";
    return ss.str();
}

void clearBattlefield(TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS) {
    if (!battlefield) return;

    // Đặt toàn bộ ô về ROAD
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            battlefield[i][j] = ROAD;
        }
    }
    for (int i = 0; i < NUM_ROWS; i++) {
        delete[] battlefield[i];
    }
    delete[] battlefield;
    battlefield = nullptr;
}

