//Nathan Clark, CS 4120, Project1C Generation File
//Date: 10/25/23
//The purpose of this program is to generate files to use 
//in a linear search vs. binary search algorithm comparison.
//Created files: "database5000.txt", "database10000.txt", "database20000.txt",
//"database40000.txt", and "database80000.txt"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
ofstream itemsListEdit;

//This function creates each file and populates it with the amount of 
//samples as intended.
	void AddFile(int size, string fileName) {
		itemsListEdit.open(fileName); //opening file to write to
		string itemName;
		double itemPrice;

		for (int t = 0; t < size; ++t) {

			for (int i = 0; i < 6; ++i) {
				if (i == 0) {
					itemsListEdit << ((rand() % 9) + 1);
				}
				else {
					itemsListEdit << rand() % 10;  //ispn number
				}
			} //ispn number

			itemsListEdit << ",";

			for (int i = 0; i < (rand() % 6) + 1; ++i) {
				if (i == 0) {
					char character = 'A' + rand() % 26;  //first name of author
					itemsListEdit << character;
				}

				else {
					char character = 'a' + rand() % 26;
					itemsListEdit << character;
				}

			}
			itemsListEdit << " ";

			for (int i = 0; i < (rand() % 6) + 1; ++i) {  //last name of author
				if (i == 0) {
					char character = 'A' + rand() % 26;
					itemsListEdit << character;
				}

				else {
					char character = 'a' + rand() % 26;
					itemsListEdit << character;
				}

			}
			itemsListEdit << ",";

			for (int i = 0; i < (rand() % 6) + 1; ++i) { //title of book
				if (i == 0) {
					char character = 'A' + rand() % 26;
					itemsListEdit << character;
				}

				else {
					char character = 'a' + rand() % 26;
					itemsListEdit << character;
				}

			}

			itemsListEdit << "," << (rand() % 999999) + 1 << ","; //byte size of book

			for (int i = 0; i < 10; ++i) {
				itemsListEdit << rand() % 10;  //pointer number

			}
			itemsListEdit << "\n";
		}

		itemsListEdit.close();
	}

	int main(int argc, char* argv[]) {
		
		int choice = atoi(argv[1]); //accepts integer size to create files of that size

			if (choice == 5000) {
				AddFile(5000, "database5000.txt");
			}
			if (choice == 10000) {
				AddFile(10000, "database10000.txt");
			}
			if (choice == 20000) {
				AddFile(20000, "database20000.txt");
			}
			if (choice == 40000) {
				AddFile(40000, "database40000.txt");
			}
			if (choice == 80000) {
				AddFile(80000, "database80000.txt");
			}
		
	
	return 0;
}