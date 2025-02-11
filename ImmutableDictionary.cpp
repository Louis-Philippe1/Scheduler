#include "ImmutableDictionary.h"
#include <iostream>
#include <stdexcept>

ImmutableDictionary::ImmutableDictionary() : data(initializeData()) {}

std::map<int, std::string> ImmutableDictionary::initializeData() {
    std::map<int, std::string> temp;
    const std::string days[] = {
        "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday", "Sunday"
    };
    
    for (int i = 1; i <= 21; i++) {
        // Integer division by 3 gives us the day index
        int dayIndex = (i - 1) / 3;
        // Modulo 3 gives us the session number (add 1 since we want sessions 1-3)
        int sessionNum = ((i - 1) % 3) + 1;
        temp[i] = days[dayIndex] + " Session " + std::to_string(sessionNum);
    }
    return temp;
}

const ImmutableDictionary& ImmutableDictionary::getInstance() {
    static ImmutableDictionary instance;
    return instance;
}

std::string ImmutableDictionary::get(int key) const {
    auto it = data.find(key);
    if (it == data.end()) {
        throw std::out_of_range("Key not found");
    }
    return it->second;
}

bool ImmutableDictionary::contains(int key) const {
    return data.find(key) != data.end();
}

size_t ImmutableDictionary::size() const {
    return data.size();
}

void ImmutableDictionary::printAll() const {
    std::string currentDay = "";
    for (const auto& pair : data) {
        // Extract the day part for grouping
        size_t sessionPos = pair.second.find(" Session");
        std::string day = pair.second.substr(0, sessionPos);
        
        // Print day header when day changes
        if (day != currentDay) {
            if (!currentDay.empty()) std::cout << std::endl;
            std::cout << "=== " << day << " ===" << std::endl;
            currentDay = day;
        }
        
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
