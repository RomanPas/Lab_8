#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Data {
	bool used;
	size_t id;
};

void printResult(const vector<string>& allFirstNames, const unordered_map<string, Data>& result);

int main() {
	size_t count;
	cin >> count;

	unordered_map<string, unordered_set<string>> firstnames;
	vector<string> team;
	team.resize(3);

	while (count) {
		cin >> team[0] >> team[1] >> team[2];
		firstnames[team[0]].insert(team[1]);
		firstnames[team[0]].insert(team[2]);
		firstnames[team[1]].insert(team[0]);
		firstnames[team[1]].insert(team[2]);
		firstnames[team[2]].insert(team[0]);
		firstnames[team[2]].insert(team[1]);
		--count;
	}

	unordered_map<string, Data> result;
	vector<string> allFirstNames;
	allFirstNames.reserve(firstnames.size());

	for (const auto& fn : firstnames) {
		result[fn.first] = { false, 0 };
		allFirstNames.push_back(fn.first);
	}
	sort(allFirstNames.begin(), allFirstNames.end());

	unordered_set<string> buff;
	unordered_set<string> tempBuff;

	string name = "Isenbaev";

	auto namePtr = firstnames.find(name);
	if (namePtr == firstnames.end()) {
		printResult(allFirstNames, result);
		return 0;
	}

	size_t countId = 0;
	result[namePtr->first].used = true;
	result[namePtr->first].id = countId;
	for (const auto& firstname : namePtr->second) {
		firstnames[firstname].erase(namePtr->first);
		buff.insert(firstname);
	}
	++countId;

	while (!buff.empty()) {
		for (const auto& firstname : buff) {
			auto it = result.find(firstname);
			if (!it->second.used || (it->second.used && countId < it->second.id)) {
				it->second.used = true;
				it->second.id = countId;
				for (const auto& fn : firstnames[firstname]) {
					firstnames[fn].erase(firstname);
					tempBuff.insert(fn);
				}
			}
		}
		buff = move(tempBuff);
		++countId;
	}

	printResult(allFirstNames, result);

	return 0;
}

void printResult(const vector<string>& allFirstNames, const unordered_map<string, Data>& result) {
	for (const auto& firstname : allFirstNames) {
		cout << firstname << " ";
		if (result.at(firstname).used)
			cout << result.at(firstname).id << "\n";
		else
			cout << " undefined\n";
	}
}