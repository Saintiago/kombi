#include "stdafx.h"
#include "Permutation.h"

using namespace std;

CPermutation::CPermutation(vector<int> combination)
	: m_combination(combination)
	, m_length(m_combination.size())
{
	for (int i = 1; i <= m_length; ++i)
	{
		m_current.push_back(i);
	}
	m_reversal = m_current;
	m_direction.resize(m_length, -1);
}


CPermutation::~CPermutation()
{
}

long CPermutation::SpawnPermutations(bool showPermutations)
{
	int counter = 0;
	m_direction[0] = 0;
	int m = m_length + 1;
	m_current.push_back(m);
	m_current.insert(m_current.begin(), m);

	while (m != 1)
	{
		if (showPermutations)
		{
			showPermutation(cout);
		}
		++counter;
		m = m_length;

		while (m_current[m_reversal[m - 1] + m_direction[m - 1]] > m)
		{
			m_direction[m - 1] = -m_direction[m - 1];
			--m;
		}

		swap(m_current[m_reversal[m - 1]], m_current[m_reversal[m - 1] + m_direction[m - 1]]);
		swap(m_reversal[m_current[m_reversal[m - 1]] - 1], m_reversal[m - 1]);
	}
	return counter;
}

void CPermutation::showPermutation(ostream & out)
{
	for (size_t i = 1; i < (m_current.size() - 1); ++i)
	{
		out << m_combination.at(m_current.at(i) - 1) << ", ";
	}
	out << endl;
}