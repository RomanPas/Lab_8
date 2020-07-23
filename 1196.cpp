#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	size_t count;
	cin >> count;

	size_t number;
	unordered_set<size_t> numbers;

	while (count) {
		cin >> number;
		numbers.insert(number);
		--count;
	}

	cin >> count;

	size_t result = 0;
	while (count) {
		cin >> number;
		if (numbers.find(number) != numbers.end())
			++result;
		--count;
	}

	cout << result;

	return 0;
}
