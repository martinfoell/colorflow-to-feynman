#include "../include/readfile.hpp"



// int main() {
//     std::string filename = "example.txt"; // Replace with your file's name
//     std::map<std::string, std::vector<std::string>> data = readNamedCommaSeparatedValues(filename);

//     // Now, you can work with the data as needed
//     std::vector<std::string> particles;
//     // Check if a specific name exists in the map
//     std::string nameToCheck = "cf1"; // Replace with the name you want to check
//     auto it = data.find(nameToCheck);
    
//     if (it != data.end()) {
//         // Name exists in the map, you can access its associated vector of values
//         const std::vector<std::string>& values = it->second;
//         std::cout << "Name: " << nameToCheck << " exists in the map." << std::endl;
//         std::cout << "Values associated with " << nameToCheck << ":" << std::endl;
//         for (const std::string& value : values) {
//             particles.push_back(value);
//             std::cout << "Value: " << value << std::endl;
//         }
//     } else {
//         // Name does not exist in the map
//         std::cout << "Name: " << nameToCheck << " does not exist in the map." << std::endl;
//     }

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // for trim functions

// Trim leading and trailing white spaces from a string
void trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

std::map<std::string, std::vector<std::string>> readNamedCommaSeparatedValues(const std::string& filename) {
    std::map<std::string, std::vector<std::string>> data; // Create a map to store name-value pairs
    std::ifstream inputFile(filename); // Open the file for reading

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        // Handle the error as needed, e.g., return an empty map or exit the program
        return data;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Find the position of the equal sign '='
        size_t equalPos = line.find('=');
        if (equalPos != std::string::npos) {
            // Extract the name (before the equal sign) and values (after the equal sign)
            std::string name = line.substr(0, equalPos);
            std::string partAfterEqual = line.substr(equalPos + 1);

            // Trim leading and trailing spaces from name and values
            trim(name);
            trim(partAfterEqual);

            // Split the part after the equal sign using commas as the delimiter
            std::istringstream iss(partAfterEqual);
            std::string element;
            std::vector<std::string> values;
            while (std::getline(iss, element, ',')) {
                trim(element); // Trim spaces from each element
                values.push_back(element); // Add each element to the vector
            }

            // Associate the name with the vector of values
            data[name] = values;
        }
    }

    inputFile.close(); // Close the file
    return data;
}
