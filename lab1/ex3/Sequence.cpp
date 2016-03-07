#include "stdafx.h"
#include "Sequence.h"


CSequence::CSequence(int n, int k)
	: m_n(n)
	, m_k(k)
{
}

CSequence::~CSequence()
{
}

long CSequence::SpawnSequences(bool showSequences)
{
	CCombination combination(m_n, m_k);
	long counter = 0;

	do
	{
		CPermutation permutation(combination.GetCombination());
		counter += permutation.SpawnPermutations(showSequences);
	} 
	while (combination.SpawnNextCombination());

	return counter;
}
