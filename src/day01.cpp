#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

int part1(const std::vector<std::string>& lines) {
	int dial = 50;
	int count = 0;

	for (auto& line : lines) {
		int distance = std::stoi(line.substr(1));
		if (line[0] == 'L') {
			dial -= distance;
		}
		else {
			dial += distance;
		}

		dial = (dial + 100) % 100;

		if (dial == 0) count++;
	}
	return count;
}

int part2(const std::vector<std::string>& lines) {
	int dial = 50;
	int count = 0;

	for (auto& line : lines) {
		int distance = std::stoi(line.substr(1));
		int direction = (line[0] == 'L') ? -1 : 1;

		for (int i = 0; i < distance; i++) {
			dial += direction;
			dial = (dial + 100) % 100;
			if (dial == 0) count++;
		}
	}
	return count;
}


int main() {
	std::ifstream input("inputs/day01.txt");
	std::vector<std::string> lines = aoc::read_lines(input);

	std::cout << "Part 1: " << part1(lines) << "\n";
	std::cout << "Part 2: " << part2(lines) << "\n";
}
