// cutpoints.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAXN 100

using namespace std;

int n, k, pairCount;
vector < vector<int> > g;
vector<int> mt;
vector<bool> used;

bool DoKuhn(int v) {
	if (used[v]) return false;
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i) 
	{
		int to = g[v][i];
		if (mt[to] == -1 || DoKuhn(mt[to])) 
		{
			pairCount++;
			mt[to] = v;
			return true;
		}
	}
	return false;
}

void readGraph(ifstream & is)
{
	string line;
	while (getline(is, line))
	{
		g.push_back({});
		stringstream ss(line);
		for (int i = 0; i < MAXN; i++)
		{
			int node;
			ss >> node;
			if (!ss) break;
			if (node == 1)
			{
				g[n].push_back(i);
			}
			if (n == 0)	k++;
		}
		n++;
	}
}

void writeResult()
{
	ofstream out;
	out.open("output.txt");

	if (pairCount == n)
	{
		out << "Yes" << endl;
	}
	else
	{
		out << "No" << endl;
		for (int i = 0; i < k; ++i)
		{
			if (mt[i] != -1)
			{
				out << mt[i] + 1 << " " << i + 1 << endl;
			}
		}
	}

	out.close();
}

int main(int argc, char* argv[])
{
	try
	{

		if (argc != 2)
		{
			throw exception("Usage: kun.exe <input-file>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		n = k = pairCount = 0;
		readGraph(fin);

		mt.assign(k, -1);
		for (int v = 0; v < n; ++v) 
		{
			used.assign(n, false);
			DoKuhn(v);
		}

		writeResult();
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}

