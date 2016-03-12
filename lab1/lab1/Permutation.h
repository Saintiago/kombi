#pragma once
class CPermutation
{
public:
	CPermutation(std::vector<int> combination);
	~CPermutation();

	long SpawnPermutations(bool showPermutations);
	std::vector<int> GetRandomPermutation();

private:
	std::vector<int> m_combination;
	std::vector<int> m_current;
	std::vector<int> m_reversal;
	std::vector<int> m_direction;
	int m_length;

	void showPermutation(std::ostream & out);
};

