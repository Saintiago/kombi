#pragma once
class CPermutation
{
public:
	CPermutation(int length);
	~CPermutation();

	int SpawnPermutations();

private:
	std::vector<int> m_current;
	std::vector<int> m_reversal;
	std::vector<int> m_direction;
};

