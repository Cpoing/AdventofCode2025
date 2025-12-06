#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/utils.hpp"

using namespace std;
using ll = long long;

vector<vector<char>> constructArray(const vector<string>& lines) {
	vector<vector<char>> arr;
	arr.reserve(lines.size());

	for (const string& line : lines) {
		arr.emplace_back(line.begin(), line.end());
	}
	return arr;
}

ll part1(const vector<string>& lines) {
	int count = 0;

	vector<vector<char>> arr = constructArray(lines);
	vector<pair<int, int>> dirs = {
		{-1, -1}, 
		{-1, 0}, 
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	for (int r = 0; r < arr.size(); r++) {
		for (int c = 0; c < arr.at(0).size(); c++) {
			if (arr[r][c] == '.') continue;

			int adj = 0;
			for (pair<int, int> dir : dirs) {
				int dr = r + dir.first;
				int dc = c + dir.second;
				if (dr < 0 || dr >= arr.size() || dc < 0 || dc >= arr.at(0).size())
					continue;
				if (arr[dr][dc] == '.')
					continue;
				adj++;
			}
			if (adj < 4) count++;
		}
	}
	return count;

	return 0;
}

ll part2(const vector<string>& lines) {
	int count = 0;

	vector<vector<char>> arr = constructArray(lines);
	vector<pair<int, int>> dirs = {
		{-1, -1}, 
		{-1, 0}, 
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	bool remove = true;

	while (remove) {
		int totalRemoved = 0;
		for (int r = 0; r < arr.size(); r++) {
			for (int c = 0; c < arr.at(0).size(); c++) {
				if (arr[r][c] == '.') continue;

				int adj = 0;
				for (pair<int, int> dir : dirs) {
					int dr = r + dir.first;
					int dc = c + dir.second;
					if (dr < 0 || dr >= arr.size() || dc < 0 || dc >= arr.at(0).size())
						continue;
					if (arr[dr][dc] == '.')
						continue;
					adj++;
				}
				if (adj < 4) {
					arr[r][c] = '.';
					count++;
					totalRemoved++;
				}
			}
		}
		if (totalRemoved == 0) remove = false;
	}
	return count;

}

int main() {
	ifstream input("inputs/day04.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}
