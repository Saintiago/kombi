#include "stdafx.h"
#include "Combination.h"

using namespace std;

CCombination::CCombination(int n, int k)
	: m_n(n)
	, m_k(k)
{
	m_set.insert(m_set.begin(), -1);
	for (int i = 1; i <= m_k; ++i)
	{
		m_set.push_back(i);
	}
}


CCombination::~CCombination()
{
}

vector<int> CCombination::GetCombination()
{
	vector<int> cleanCombination;
	cleanCombination.resize(m_set.size() - 1);
	copy(m_set.begin() + 1, m_set.end(), cleanCombination.begin());
	return cleanCombination;
}

bool CCombination::SpawnNextCombination()
{
	int j = m_k;

	while (m_set[j] == (m_n - m_k + j))
	{
		--j;
	}

	++m_set[j];

	for (int i = j + 1; i <= m_k; i++)
	{
		m_set[i] = m_set[i - 1] + 1;
	}

	return (j != 0);
}

long CCombination::SpawnCombinations(bool showCombinations)
{
	int counter = 0;

	do
	{
		if (showCombinations)
		{
			showCombination(cout);
		}
		++counter;
	} 
	while (SpawnNextCombination());

	return counter;
}

void CCombination::showCombination(ostream & out)
{
	copy(m_set.begin() + 1, m_set.end(), ostream_iterator<int>(out, ", "));
	out << endl;
}