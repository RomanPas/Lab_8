#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	size_t count;
	cin >> count;

	unordered_map<string, size_t> nicknames;

	for (string nickname = ""; count != 0; --count) {
		cin >> nickname;
		++nicknames[nickname];
	}

	for (const auto& nickname : nicknames)
		if (nickname.second > 1)
			cout << nickname.first << "\n";

	return 0;
}
