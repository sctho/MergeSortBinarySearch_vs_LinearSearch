#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Books {
	int ISBN;
	string authorName;
	string bookName;
	int bytes;
	int pointer;
};

int main(int argc, char* argv[]) {
	ifstream itemsListGet;

	std::vector<string> itemList;
	vector<Books> BookList;
	string line;
	itemsListGet.open(argv[1]);

	while (getline(itemsListGet, line)) {
		itemList.push_back(line);
	}

	for (int i = 0; i < itemList.size(); ++i) {
		vector<int> commas;
		string compString = itemList[i];
		for (int j = 0; j < itemList[i].length(); ++j) {
			if (compString[j] == ',') {
				commas.push_back(j);
			}
		}
		Books object1;
		object1.ISBN = atoi((compString.substr(0, commas[0])).c_str());
		object1.authorName = compString.substr(commas[0] + 1, commas[1]);
		object1.bookName = compString.substr(commas[1] + 1, commas[2]);
		object1.bytes = atoi((compString.substr(commas[2] + 1, commas[3])).c_str());
		object1.pointer = atoi((compString.substr(commas[3] + 1)).c_str());
		BookList.push_back(object1);

	}
	bool checker = false;
	int keyIndex;
	int z = 0;

	clock_t start, start1, end, end1;

	start = clock();

	for (int i = 0; i < 5000; ++i) {

		int key = rand() % 99999;

		while ((checker == false) && (z < itemList.size())) {
			if (BookList[z].ISBN == key) {
				keyIndex = z;
				checker = true;
			}
			else {
				z++;
			}
		}
		checker = false;
		z = 0;
		keyIndex = -1;
	}
	end = clock();

	double time = double(end - start) / CLOCKS_PER_SEC;
	time = time * 1000;
	std::cout << itemList.size() << ", " << time << " msec\n";

}