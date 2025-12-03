#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "../include/utils.hpp"

long long part1(const std::vector<std::string>& lines) {
	long long sum = 0;
    std::vector<std::string> ranges = aoc::split(lines[0], ',');

	for (auto& range : ranges) {
		auto seg = aoc::split(range, '-');

		long long L = std::stoll(seg[0]);
		long long R = std::stoll(seg[1]);

		for (auto i = L; i <= R; i++) {
			std::string num = std::to_string(i);
			int len = num.size();
			if (len % 2 == 0) {
				std::string first = num.substr(0, len/2);
				std::string second = num.substr(len/2);
				if (first == second) {
					sum += i;
				}
			}
		}
	}
	return sum;
}

bool is_invalid(const std::string& num) {
	int n = num.size();

	for (int i = 1; i <= n/2; i++) {
		if (n % i != 0) continue;

		std::string block = num.substr(0, i);

		std::string repeated;
		int repeatLength = n / i;
		for (int j = 0; j < repeatLength; j++) repeated += block;

		if (repeated == num) return true;
	}
	return false;
}

long long part2(const std::vector<std::string>& lines) {
	long long sum = 0;
    std::vector<std::string> ranges = aoc::split(lines[0], ',');

	for (auto& range : ranges) {
		auto seg = aoc::split(range, '-');

		long long L = std::stoll(seg[0]);
		long long R = std::stoll(seg[1]);

		for (auto i = L; i <= R; i++) {
			std::string num = std::to_string(i);
			if (is_invalid(num)) sum += i;

		}
	}
	return sum;
}


int main() {
	std::ifstream input("inputs/day02.txt");
	std::vector<std::string> lines = aoc::read_lines(input);

	std::cout << "Part 1: " << part1(lines) << "\n";
	std::cout << "Part 2: " << part2(lines) << "\n";
}

