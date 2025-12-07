#include <set>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/utils.hpp"

using namespace std;
using ll = long long;

struct range {
	ll start, end;
};

bool contains(const vector<range>& ranges, ll num) {
	for (const auto& r : ranges) {
		if (num >= r.start && num <= r.end) {
			return true;
		}
	}
	return false;
}

ll part1(const vector<string>& lines) {
    vector<range> ranges;
    ll i = 0;

    for (; i < lines.size(); i++) {
        if (lines[i].empty()) {
            i++;
            break;
        }

        auto split = aoc::split(lines[i], '-');
        ll start = stoll(split[0]);
        ll end = stoll(split[1]);
        ranges.push_back({start, end});
    }

    ll count = 0;
    for (; i < lines.size(); i++) {
        if (lines[i].empty()) continue;
        ll num = stoll(lines[i]);

        if (contains(ranges, num)) count++;
    }

    return count;
}

ll part2(const vector<string>& lines) {
	vector<range> ranges;
	for (int i = 0; i < lines.size(); i++) {
		if (lines[i].empty()) {
			break;
		}
        auto split = aoc::split(lines[i], '-');
        ll start = stoll(split[0]);
        ll end = stoll(split[1]);
		ranges.push_back({start, end});
	}

	sort(ranges.begin(), ranges.end(), [](const range& a, const range& b){
		return a.start < b.start;
	});
	ll count = 0;
	ll last_num = 0;
	for (const auto& r : ranges) {
		if (r.end <= last_num) continue;

		if (r.start <= last_num) {
			count += r.end - last_num;
			last_num = r.end;
		}
		else {
			count += (r.end - r.start) + 1;
			last_num = r.end;
		}
	}
	
	return count;
}


int main() {
	ifstream input("inputs/day05.txt");
	vector<string> lines = aoc::read_lines(input);

	cout << "Part 1: " << part1(lines) << "\n";
	cout << "Part 2: " << part2(lines) << "\n";
}
