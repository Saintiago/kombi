#include "stdafx.h"
#include "Combination.h"

using namespace std;

CCombination::CCombination(int n, int k)
	: m_n(n)
	, m_k(k)
{
	for (int i = 1; i <= m_k; ++i)
	{
		m_set.push_back(i);
	}
}


CCombination::~CCombination()
{
}

long CCombination::SpawnCombinations(bool showCombinations)
{
	m_set.insert(m_set.begin(), -1);
	int counter = 0;
	int j = 1;

	while (j != 0)
	{
		if (showCombinations)
		{
			showCombination(cout);
		}
		++counter;
		j = m_k;

		while (m_set[j] == (m_n - m_k + j))
		{
			--j;
		}

		++m_set[j];

		for (int i = j + 1; i <= m_k; i++)
		{
			m_set[i] = m_set[i - 1] + 1;
		}
	}
	return counter;
}

void CCombination::showCombination(ostream & out)
{
	copy(m_set.begin() + 1, m_set.end(), ostream_iterator<int>(out, ", "));
	out << endl;
}