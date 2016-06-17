// cutpoints.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAXN 100

using namespace std;

void IS_CUTPOINT(int v);

vector<int> g[MAXN];
bool used[MAXN], cutpoint[MAXN];
int n, timer, tin[MAXN], fup[MAXN];

void dfs(int v, int p = -1) 
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (size_t i = 0; i<g[v].size(); ++i) 
	{
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
		{
			fup[v] = min(fup[v], tin[to]);
		}
		else 
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
			{
				IS_CUTPOINT(v);
			}
			++children;
		}
	}

	if (p == -1 && children > 1)
	{
		IS_CUTPOINT(v);
	}
}

void readGraph(ifstream & is)
{
	string line;
	while (getline(is, line))
	{
		stringstream ss(line);
		for (int i = 0; i < MAXN; i++)
		{
			int node;
			ss >> node;
			if (!ss) break;
			g[n].push_back(node);
		}
		n++;
	}
}

void writeGraph()
{
	ofstream out;
	out.open("output.txt");
	
	for (int i = 0; i < n; i++)
	{
		if (cutpoint[i])
		{
			out << i << " ";
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
			throw exception("Usage: search.exe <file-name> <search-string>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		n = 0;

		readGraph(fin);

		timer = 0;
		for (int i = 0; i < n; ++i)
		{
			used[i] = cutpoint[i] = false;
		}
		dfs(0);

		writeGraph();
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

    return 0;
}

void IS_CUTPOINT(int v)
{
	cutpoint[v] = true;
}