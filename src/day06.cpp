#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/utils.hpp"

using namespace std;
using ll = long long;

vector<vector<string>> constructArray(const vector<string>& lines) {
    vector<vector<string>> arr;
    arr.reserve(lines.size());

    for (const string& line : lines) {
        vector<string> row;
        string token;
        for (char c : line) {
            if (c != ' ') {
                token += c;
            } else if (!token.empty()) {
                row.push_back(token);
                token.clear();
            }
        }

        if (!token.empty()) {
            row.push_back(token);
        }

        arr.push_back(row);
    }

    return arr;
}

ll part1(const vector<string>& lines) {
	ll total = 0;
	vector<vector<string>> arr = constructArray(lines);

	vector<vector<string>> transposed(arr[0].size(), vector<string>(arr.size()));

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			transposed[j][i] = arr[i][j];
		}
	}

	for (auto& row : transposed) {
		ll cur_sum = 0;
		char op = row.back()[0];

		if (op == '*') {
			cur_sum = 1;
			for (int i = 0; i < row.size() - 1; i++) {
				cur_sum *= stoll(row[i]);
			}
		}
		else {
			for (int i = 0; i < row.size() - 1; i++) {
				cur_sum += stoll(row[i]);
			}
		}
		total += cur_sum;
	}

	return total;
}

ll part2(const vector<string>& lines) {
    int rows = lines.size();
    int cols = 0;

    for (auto &s : lines)
        cols = max(cols, (int)s.size());

    vector<string> rotated;

    for (int c = cols - 1; c >= 0; c--) {
        string newRow;
        for (int r = 0; r < rows; r++) {
            if (c < (int)lines[r].size())
                newRow.push_back(lines[r][c]);
        }
        rotated.push_back(newRow);
    }

    vector<vector<string>> nums;
    nums.push_back({});

    for (auto &row : rotated) {
        bool isEmpty = true;
        for (char ch : row)
            if (ch != ' ') { isEmpty = false; break; }
        if (isEmpty) {
            nums.push_back({});
            continue;
        }

        stringstream ss(row);
        string token;
        while (ss >> token) {
            nums.back().push_back(token);
        }
    }

	ll total = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i].empty()) continue;

		ll cur_total = 0;
		string &lastVal = nums[i].back();
		char op = lastVal.back();
		if (op == '*') cur_total = 1;

		for (auto &val : nums[i]) {
			string s = val;

			while (!s.empty() && !isdigit(s.back()))
				s.pop_back();

			int start = 0;
			while (start < s.size() && !isdigit(s[start]))
				start++;
			s = s.substr(start);

			if (s.empty()) continue;

			ll num = stoll(s);

			if (op == '+') {
				cur_total += num;
			} else if (op == '*') {
				cur_total *= num;
			}
		}

		total += cur_total;
	}

    return total;
}


int main() {
	ifstream input("inputs/day06.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}
