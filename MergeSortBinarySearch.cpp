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

void IterativeBinarySearch(vector<Books> A) {
	int p = 0;
		int q = A.size() - 1;
		bool checker = false;
		for (int i = 0; i < 5000; ++i) {
			int v = (rand() % 899999) + 100000;

			while (q >= p && checker == false) {
				int midpoint = (p + q) / 2;
				if (A[midpoint].ISBN == v) {
					checker = true;
				}
				if (A[midpoint].ISBN > v) {
					q = midpoint - 1;
				}
				if (A[midpoint].ISBN < v) {
					p = midpoint + 1;
				}
			}
			checker = false;
			p = 0;
			q = A.size() - 1;
		}

}


void Merge(vector<Books>& vectorUse, int floor, int midpoint, int top) {
	int n1 = midpoint - floor + 1;
	int n2 = top - midpoint;
	//cout << "N1,N2" << n1 << " " << n2 << "\n";
	vector<Books> L(n1 + 1);
	vector<Books> R(n2 + 1);
	for (int i = 0; i < n1; ++i) {
		L[i] = vectorUse[floor + i];
		//cout << "L:" << L[i]<< "\n";
	}
	for (int j = 0; j < n2; ++j) {
		R[j] = vectorUse[midpoint + j + 1];
	}
	L[n1].ISBN = 99999999999999;
	R[n2].ISBN = 99999999999999;
	int i = 0;
	int j = 0;

	for (int k = floor; k <= top; ++k) {
		
		if (L[i].ISBN <= R[j].ISBN) {
			vectorUse[k] = L[i];
			++i;
		}
		else {
			vectorUse[k] = R[j];
			++j;
		}
	}

}

void MergeSort(vector<Books>& vectorUse, int floor, int top) {
	//cout << floor << " " << top << "\n";
	if ((top - floor) > 0) {
		MergeSort(vectorUse, floor, (top + floor) / 2);
		MergeSort(vectorUse, ((floor + top) / 2) + 1, top);
	}
	Merge(vectorUse, floor, (top + floor) / 2, top);
}

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

	clock_t start1, start2, end1, end2;
	start1 = clock();

	MergeSort(BookList, 0, BookList.size() - 1);

	end1 = clock();

	double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
	time1 = time1 * 1000;
	cout << itemList.size() << ", " << time1 << " msec\n";

	start2 = clock();

	IterativeBinarySearch(BookList);

	end2 = clock();

	double time2 = double(end2 - start2) / CLOCKS_PER_SEC;
	time2 = time2 * 1000;
	cout << itemList.size() << ", " << time2 << " msec\n";

}