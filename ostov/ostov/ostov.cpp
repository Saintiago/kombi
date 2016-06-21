#include "stdafx.h"

using namespace std;

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

		unsigned start, end;
		cout << "Getting graph from " << argv[1] << endl;
		algorithm.MakeGraph(fin);
		cout << "Our graph (arc list):" << endl;
		algorithm.GetGraph().WriteGraph(cout);
		cout << endl;

		string again;
		do
		{
			cout << "Please, enter two numbers for start and end nodes (starting with 0):" << endl;
			cin >> start >> end;
			cout << "Setting all nodes paths to infinity..." << endl;
			algorithm.GetGraph().ResetPaths();
			cout << "Setting start node (" << start << ") path to 0..." << endl;
			algorithm.SetStartNode(start);
			unsigned path = algorithm.FindPathFromStartTo(end);
			cout << "Shortest path from " << start << " to " << end << ": " << path << endl;
			cout << "Want to find another path? (press 'y' to continue)" << endl;
			cin >> again;
		} while (again == "y");

		cout << "Bye!" << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}
