#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace aoc {

// Read all lines from a file into a vector of strings
inline std::vector<std::string> read_lines(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    return lines;
}

// Split a string by a delimiter into a vector of strings
inline std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
		if (!token.empty())
			tokens.push_back(token);
    }
    return tokens;
}

// Convert a vector of strings to a vector of ints
inline std::vector<int> strings_to_ints(const std::vector<std::string>& strs) {
    std::vector<int> nums;
    for (const auto& s : strs) nums.push_back(std::stoi(s));
    return nums;
}

// Generic helper: sum a vector of ints
inline int sum(const std::vector<int>& nums) {
    int total = 0;
    for (int n : nums) total += n;
    return total;
}

// Optional: trim whitespace from start and end
inline std::string trim(const std::string& s) {
    const char* whitespace = " \t\n\r\f\v";
    size_t start = s.find_first_not_of(whitespace);
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(whitespace);
    return s.substr(start, end - start + 1);
}

} 

