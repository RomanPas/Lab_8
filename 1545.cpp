#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
	size_t count;
	cin >> count;

	unordered_map<char, list<string>> data;
	string word;

	while (count) {
		cin >> word;
		data[word.front()].push_back(word);
		--count;
	}

	cin >> word;
	for (const auto& d : data[word.front()])
		cout << d << "\n";

	return 0;
}
