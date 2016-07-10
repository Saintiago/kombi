// cutpoints.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAXN 1000
#define RAND_GRAPH_SIZE 500;

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

void generateRandomDenseGraph()
{
	srand(time(0));
	for (int j = 0; j < n; j++)
	{
		g.push_back({});
		for (int i = 0; i < n; i++)
		{
			int node = rand() % 2;
			if (node == 1)
			{
				g[j].push_back(i);
			}
		}
	}
}

void writeResult(double duration)
{
	ofstream out;
	out.open("output.txt");

	out << "Time spent: " << duration << " sec." << endl;

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
			n = k = RAND_GRAPH_SIZE;
			cout << "Using random " << n << " graph." << endl;
			generateRandomDenseGraph();
		}
		else
		{
			ifstream fin(argv[1]);
			if (!fin.is_open())
			{
				throw exception("Cannot open file.");
			}

			n = k = 0;
			readGraph(fin);
		}

		clock_t start;
		double duration;
		start = std::clock();
		
		pairCount = 0;
		mt.assign(k, -1);
		for (int v = 0; v < n; ++v) 
		{
			used.assign(n, false);
			DoKuhn(v);
		}

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		writeResult(duration);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}

