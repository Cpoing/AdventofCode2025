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

ll traverse(int row, int col, vector<vector<char>>& arr, vector<vector<bool>>& visited) {
    int n = arr.size();
    int m = arr[0].size();

    if (row >= n || col < 0 || col >= m)
        return 0;

    if (arr[row][col] == '.') {
        return traverse(row + 1, col, arr, visited);
    }

    if (arr[row][col] == '^') {
        if (visited[row][col])
            return 0;

        visited[row][col] = true;

        return 1
            + traverse(row + 1, col - 1, arr, visited)
            + traverse(row + 1, col + 1, arr, visited);
    }

    return 0;
}

ll part1(const vector<string>& lines) {
	vector<vector<char>> arr = constructArray(lines);
	int start = 0;
	for (int i = 0; i < arr.at(0).size(); i++) {
		if (arr[0][i] == 'S') {
			start = i;
			break;
		}
	}
	vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
	ll result = traverse(1, start, arr, visited);
	return result;
}

ll traverse2(int row, int col, const vector<vector<char>>& arr, vector<vector<ll>>& memo) {
    int n = arr.size();
    int m = arr[0].size();

    if (row >= n)
        return 1;

    if (col < 0 || col >= m)
        return 0;

    if (memo[row][col] != -1)
        return memo[row][col];

    ll result;

    if (arr[row][col] == '.') {
        result = traverse2(row + 1, col, arr, memo);
    } 
    else if (arr[row][col] == '^') {
        result = traverse2(row + 1, col - 1, arr, memo)
               + traverse2(row + 1, col + 1, arr, memo);
    }
    else {
        result = 0;
    }

    memo[row][col] = result;
    return result;
}

ll part2(const vector<string>& lines) {
    vector<vector<char>> arr = constructArray(lines);

    int start = 0;
    for (int i = 0; i < arr[0].size(); i++) {
        if (arr[0][i] == 'S') {
            start = i;
            break;
        }
    }

    vector<vector<ll>> memo(arr.size(), vector<ll>(arr[0].size(), -1));

    return traverse2(1, start, arr, memo);
}


int main() {
	ifstream input("inputs/day07.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}

