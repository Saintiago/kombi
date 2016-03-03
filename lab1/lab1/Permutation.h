#pragma once
class CPermutation
{
public:
	CPermutation(int length);
	~CPermutation();

	long SpawnPermutations(bool showPermutations);

private:
	std::vector<int> m_current;
	std::vector<int> m_reversal;
	std::vector<int> m_direction;
	int m_length;

	void showPermutation(std::ostream & out);
};

