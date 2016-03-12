// ex4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../lab1/Permutation.h"

using namespace std;

vector<int> GetCombination(int length)
{
	vector<int> combination;
	for (int i = 1; i <= length; ++i)
	{
		combination.push_back(i);
	}
	return combination;
}

int main()
{
	srand(time(NULL));

	cout << "Spawning random permutation of length 5: " << endl;
	vector<int> randomPermutation = CPermutation(GetCombination(5)).GetRandomPermutation();
	copy(randomPermutation.begin(), randomPermutation.end(), ostream_iterator<int>(cout, ", "));
	cout << endl << endl;

	cout << "Spawning random permutation of length 10: " << endl;
	randomPermutation = CPermutation(GetCombination(10)).GetRandomPermutation();
	copy(randomPermutation.begin(), randomPermutation.end(), ostream_iterator<int>(cout, ", "));
	cout << endl << endl;

	cout << "Spawning random permutation of length 15: " << endl;
	randomPermutation = CPermutation(GetCombination(15)).GetRandomPermutation();
	copy(randomPermutation.begin(), randomPermutation.end(), ostream_iterator<int>(cout, ", "));
	cout << endl << endl;

    return 0;
}

