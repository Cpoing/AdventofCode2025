#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/utils.hpp"

using ll = long long;
using namespace std;

ll part1(const vector<string>& lines) {
	ll sum = 0;

	for (auto& line : lines) {
		int l = line[0] - '0';
		int pos = 0;

		for (int i = 1; i < line.size() - 1; i++) {
			int val = line[i] - '0';
			if (val > l) {
				l = val;
				pos = i;
			}
		}

		int r = line[pos + 1] - '0';
		for (int i = pos + 1; i < line.size(); i++) {
			int val = line[i] - '0';
			if (val > r) {
				r = val;
			}
		}
		string comb = std::to_string(l) + std::to_string(r);
		sum += std::stoi(comb);
	}
	return sum;
}

ll part2(const vector<string>& lines) {
    ll sum = 0;

    for (auto& line : lines) {
        int remove_count = line.size() - 12;
        string st;

        for (char c : line) {
            while (!st.empty() && remove_count > 0 && st.back() < c) {
                st.pop_back();
                remove_count--;
            }
            st.push_back(c);
        }

        st.resize(12);
        sum += stoll(st);
    }

    return sum;
}

int main() {
	ifstream input("inputs/day03.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}

