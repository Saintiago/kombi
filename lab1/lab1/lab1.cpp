// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Permutation.h"

using namespace std;

int main()
{
	cout << "Spawning 10 permutations..." << endl;
	clock_t startTime = clock();
	long permutationsCount = CPermutation(10).SpawnPermutations(false);
	double duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Permutations count: " << permutationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 20 permutations..." << endl;
	startTime = clock();
	permutationsCount = CPermutation(20).SpawnPermutations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Permutations count: " << permutationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 25 permutations..." << endl;
	startTime = clock();
	permutationsCount = CPermutation(25).SpawnPermutations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Permutations count: " << permutationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl;
	
    return 0;
}

