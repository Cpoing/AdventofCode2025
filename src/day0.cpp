#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/utils.hpp"

using namespace std;
using ll = long long;

ll part1(const vector<string>& lines) {
	return 0;
}

ll part2(const vector<string>& lines) {
	return 0;
}


int main() {
	ifstream input("inputs/day0.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}
