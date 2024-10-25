#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp"  // Include the nlohmann/json header

using json = nlohmann::json;
using namespace std;

int main() {
    // Open and parse the JSON file
    ifstream file("data.json");
    json j;
    file >> j;

    // Create a vector of vectors to represent the table
    vector<vector<string>> table;

    // Add headers
    table.push_back({"Name", "Age", "City"});

    // Iterate through the JSON array and extract data
    for (const auto& item : j) {
        vector<string> row;
        row.push_back(item["name"].get<string>());
        row.push_back(to_string(item["age"].get<int>()));
        row.push_back(item["city"].get<string>());
        table.push_back(row);
    }

    // Display the data in tabular form
    for (const auto& row : table) {
        for (const auto& col : row) {
            cout << col << "\t";  // Use \t for tab separation
        }
        cout << endl;
    }

    return 0;
}
