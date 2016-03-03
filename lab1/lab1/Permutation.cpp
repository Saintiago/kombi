#include "stdafx.h"
#include "Permutation.h"

using namespace std;

CPermutation::CPermutation(int length)
{
	for (int i = 0; i < length; ++i)
	{
		m_current.push_back(i);
	}
	m_reversal = m_current;
	fill(m_direction.begin(), m_direction.end(), -1);
}


CPermutation::~CPermutation()
{
}
