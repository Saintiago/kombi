// falkerson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const int MY_INFINITY = 10000;
 
vector<vector<int>> currentFlow, arcCapacity;
int vertCount, maxFlow = 0;
vector<int> flow;
vector<int> link;
vector<int> queue;
int queuePtr, queueCount; 

int FindPath(int source, int target) 
{
	queuePtr = 0; queueCount = 1; queue[0] = source;
	link[target] = -1; 
	int i;
	int CurVertex;
	flow.assign(vertCount, 0);
	flow[source] = MY_INFINITY;
	while (link[target] == -1 && queuePtr < queueCount)
	{
		CurVertex = queue[queuePtr];
		for (i = 0; i < vertCount; i++)
			if ((arcCapacity[CurVertex][i] - currentFlow[CurVertex][i]) > 0 && flow[i] == 0)
			{
				queue[queueCount] = i; queueCount++;
				link[i] = CurVertex; 
									 
				if (arcCapacity[CurVertex][i] - currentFlow[CurVertex][i] < flow[CurVertex])
					flow[i] = arcCapacity[CurVertex][i];
				else
					flow[i] = flow[CurVertex];
			}
		queuePtr++;
	}
	if (link[target] == -1) return 0; 
									  
	CurVertex = target;
	while (CurVertex != source) 
	{
		currentFlow[link[CurVertex]][CurVertex] += flow[target];
		CurVertex = link[CurVertex];
	}
	return flow[target]; 
}

void MaxFlow(int source, int target)
{
	int AddFlow;
	do
	{
		AddFlow = FindPath(source, target);
		maxFlow += AddFlow;
	} 
	while (AddFlow >0);
}

void readGraph(ifstream & is)
{
	int n = 0;
	string line;
	while (getline(is, line))
	{
		arcCapacity.push_back({});
		currentFlow.push_back({});
		stringstream ss(line);
		for (;;)
		{
			int node;
			ss >> node;
			if (!ss) break;
			arcCapacity[n].push_back(node);
			currentFlow[n].push_back(0);
		}
		n++;
	}
}

void writeResult()
{
	ofstream out;
	out.open("output.txt");

	out << "Max flow: " << maxFlow << endl;

	out.close();
}

int main(int argc, char* argv[])
{
	try
	{

		if (argc != 2)
		{
			throw exception("Usage: falkeson.exe <input-file>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		readGraph(fin);

		vertCount = arcCapacity.size();

		queue.assign(vertCount, 0);
		link.assign(vertCount, 0);

		MaxFlow(0, vertCount - 1);

		writeResult();
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}