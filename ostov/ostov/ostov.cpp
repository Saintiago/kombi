#include "stdafx.h"
#include "Boruvka.h"

using namespace std;

unsigned GetTotalLinksPath(NodePathNodeVector links);

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

		cout << "Getting graph from " << argv[1] << endl;
		CBoruvka algorithm;
		algorithm.MakeGraph(fin);
		cout << "Our graph (arc list):" << endl;
		algorithm.GetGraph().WriteGraph(cout);
		cout << endl;

		cout << "Result: " << endl;
		NodePathNodeVector links = algorithm.GetOstov();
		cout << "Minimal tree weight: " << GetTotalLinksPath(links) << endl;
		for (auto const &link : links)
		{
			cout << link.first << " " << link.second.first << endl;
		}

	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}

unsigned GetTotalLinksPath(NodePathNodeVector links)
{
	unsigned totalPath = 0;
	for (auto const &link : links)
	{
		totalPath += link.second.second;
	}
	return totalPath;
}