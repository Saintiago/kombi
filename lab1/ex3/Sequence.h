#pragma once
#include "../lab1/Permutation.h"
#include "../ex2/Combination.h"

class CSequence
{
public:
	CSequence(int n, int k);
	~CSequence();
	long SpawnSequences(bool showSequences);

private:
	int m_n, m_k;
};

