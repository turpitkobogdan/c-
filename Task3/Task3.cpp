#include <fstream>
#include <locale>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <set>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

namespace std {

	template <typename T, typename U>
	std::ostream& operator<< (std::ostream& os, const std::pair<T, U>& v)
	{
		return os << "Word: " << v.first << ", Repeats: " << v.second;
	}
}

typedef std::map<std::string, size_t> WordsMap;

void print(std::string s)
{
	WordsMap map;
	std::string word;

	std::istringstream ss(s);
	while (ss >> word)
		++map[word];

	typedef ostream_iterator <WordsMap::value_type> O;
	std::copy(map.begin(), map.end(), O(std::cout, "\n"));
}

int main()
{
	setlocale(LC_ALL, "");

	string text;
	ifstream file("task3.txt");
	if (file.is_open())
	{
		while (getline(file, text)) {
			cout << text << endl;
		}
	}
	file.close();
	print(text);
	system("pause");
	return 0;
}