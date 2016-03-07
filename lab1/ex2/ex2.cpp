// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Combination.h"

using namespace std;

int main()
{
	cout << "Spawning 10 combinations of length 5..." << endl;
	clock_t startTime = clock();
	long combinationsCount = CCombination(10, 5).SpawnCombinations(false);
	double duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Combinations count: " << combinationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;
	
	cout << "Spawning 20 combinations of length 5..." << endl;
	startTime = clock();
	combinationsCount = CCombination(20, 5).SpawnCombinations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Combinations count: " << combinationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 25 combinations of length 5..." << endl;
	startTime = clock();
	combinationsCount = CCombination(25, 5).SpawnCombinations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Combinations count: " << combinationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 50 combinations of length 5..." << endl;
	startTime = clock();
	combinationsCount = CCombination(50, 5).SpawnCombinations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Combinations count: " << combinationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 100 combinations of length 5..." << endl;
	startTime = clock();
	combinationsCount = CCombination(100, 5).SpawnCombinations(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Combinations count: " << combinationsCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl;
	
	return 0;
}

