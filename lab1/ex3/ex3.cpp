// ex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sequence.h"

using namespace std;

int main()
{
	cout << "Spawning 10 sequences of length 5..." << endl;
	clock_t startTime = clock();
	long sequencesCount = CSequence(10, 5).SpawnSequences(false);
	double duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Sequences count: " << sequencesCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 20 sequences of length 5..." << endl;
	startTime = clock();
	sequencesCount = CSequence(20, 5).SpawnSequences(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Sequences count: " << sequencesCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

	cout << "Spawning 25 sequences of length 5..." << endl;
	startTime = clock();
	sequencesCount = CSequence(25, 5).SpawnSequences(false);
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	cout << "Sequences count: " << sequencesCount << endl;
	cout << "Time spent: " << duration << " seconds" << endl << endl;

    return 0;
}

