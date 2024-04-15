// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono> 
#include <iomanip>

using namespace std;
using namespace std::chrono;


void swapint(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapstring(string* xp, string* yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n, int arr1[], int arr2[])
{
	int d, y, min;

	for (d = 0; d < n - 1; d++)
	{
		min = d;
		for (y = d + 1; y < n; y++)
			if (arr[y] < arr[min])
				min = y;

		// Swap elements
		swapint(&arr[min], &arr[d]);
		swapint(&arr1[min], &arr1[d]);
		swapint(&arr2[min], &arr2[d]);
	}
}

int parent[110000];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return find(parent[x]);
}

void unions(int x, int y) {
	int vx = find(x);
	int vy = find(y);
	parent[vx] = vy;
}


int main(int argc, char const* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid input. How to run: ./Algorithm.exe nodeFilePath\n";
		return 0;
	}

	ifstream myfile;
	string word;
	myfile.open(argv[1]);
	ofstream output("Answer.txt");

	long long int counterNode = 0;
	long long int counterCon1 = 0;
	long long int counterCon2 = 0;
	long long int counterCost = 0;
	bool nodesCom = false;


	string* nodes; nodes = new string[110000];
	int* nodeConnection; nodeConnection = new int[110000];
	int* nodeConnection2; nodeConnection2 = new int[110000];
	int* nodeCost; nodeCost = new int[110000];

	if (!myfile.is_open()) {
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	while (myfile >> word)
	{
		if (nodes[0] != word && nodesCom == false)
		{
			//	cout << word << endl;
			nodes[counterNode] = word;
			counterNode++;
		}

		else {
			nodesCom = true;
			//Fill node connections and cost.
			if (counterCon1 == counterCon2 && counterCon1 == counterCost) {
				//FIRST NODE
				// Find the index of word here, use this index inside nodeConnection array, this index will then be used to print letters.
				// and to allow for int usage instead of string.
				int x = std::distance(nodes, std::find(nodes, nodes + counterNode, word));

				nodeConnection[counterCon1] = x; // Location in array
				counterCon1++;
			}

			else if (counterCon2 < counterCon1) {
				//CONNECTED NODE 
				// Find the index of word here, use this index inside nodeConnection array, this index will then be used to print letters.
				// and to allow for int usage instead of string.
				int x = std::distance(nodes, std::find(nodes, nodes + counterNode, word));

				nodeConnection2[counterCon2] = x;
				counterCon2++;
			}

			else {
				//COST
				//convert string to integer
				nodeCost[counterCost] = stoi(word);
				counterCost++;
			}


		}

	}

	//Selection  sorting
	selectionSort(nodeCost, counterCost, nodeConnection, nodeConnection2);



	for (int i = 0; i < counterNode; i++)
		parent[i] = i;


	for (int i = 0; i < counterNode; i++)
		output << nodes[i] << endl;

	//Clear one line 
	output << endl;

	vector < pair < int, pair < int, int > > > connection;

	for (int j = 0; j < counterCost; j++) {
		int v1 = nodeConnection[j];
		int v2 = nodeConnection2[j];
		int w = nodeCost[j];
		connection.push_back(make_pair(w, make_pair(v1, v2)));
	}

	int totalWeight = 0, numConnection = 0;
	int	mstindex = 0;

	auto start = high_resolution_clock::now();

	while ((numConnection < counterNode - 1) || (mstindex < counterCost)) {

		int x = connection[mstindex].second.first;
		int y = connection[mstindex].second.second;
		int w = connection[mstindex].first;
		if (find(x) != find(y)) {
			unions(x, y);
			totalWeight += w;
			output << nodes[x] << "	" << nodes[y] << "	" << w << endl;
			numConnection++;
		}
		//	increase the index of the edge we will be chacking
		mstindex++;
	}

	cout << "\nTotal Weight: " << totalWeight << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Execution time for Kruskals in Microseconds: " << duration.count() << endl;
	cout << "Execution time for Kruskals in Miliseconds: " << duration.count() / 1000 << endl;


	//Clear arrays and memory
	delete[] nodes;
	delete[] nodeConnection;
	delete[] nodeConnection2;
	delete[] nodeCost;

}
