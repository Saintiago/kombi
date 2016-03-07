#pragma once
class CCombination
{
public:
	CCombination(int n, int k);
	~CCombination();

	long SpawnCombinations(bool showCombinations);
	std::vector<int> GetCombination();
	bool SpawnNextCombination();

private:
	std::vector<int> m_set;
	int m_n, m_k;

	void showCombination(std::ostream & out);
};