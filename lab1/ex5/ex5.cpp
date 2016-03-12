// ex5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ex2/Combination.h"

using namespace std;

struct ThingWeightPrice
{
	int weight, cost;
};

typedef map<int, ThingWeightPrice> IndexedStuff;


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		throw exception("Usage: ex5.exe <input-file>");
	}

	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		throw exception("Cannot open file.");
	}

	IndexedStuff stuff;
	IndexedStuff backpack;
	int maxWeight;
	int bestTotalWeight = 0;
	int bestTotalCost = 0;
	int index = 1;
	string buffer;

	getline(fin, buffer);
	stringstream ss(buffer);
	ss >> maxWeight;
	
	while (!fin.eof())
	{
		int weight, cost;
		getline(fin, buffer);
		stringstream ss(buffer);
		ss >> weight >> cost;
		stuff.insert({ index,{ weight, cost } });
		index++;
	}

	int stuffQty = stuff.size();
	int backPackStuffQty = stuffQty;
	vector<int> bestCombination;

	while (backPackStuffQty > 0)
	{
		CCombination packer(stuffQty, backPackStuffQty);
		do
		{
			bool combinationValid = true;
			int totalWeight = 0;
			int totalCost = 0;
			vector<int> stuffIndecies = packer.GetCombination();
			for (auto index : stuffIndecies)
			{
				ThingWeightPrice thing = stuff.at(index);
				if (thing.weight > (maxWeight - totalWeight))
				{
					combinationValid = false;
					break;
				}

				totalWeight += thing.weight;
				totalCost += thing.cost;
			}

			if (combinationValid && totalCost > bestTotalCost)
			{
				bestTotalCost = totalCost;
				bestTotalWeight = totalWeight;
				bestCombination = stuffIndecies;
			}


		} while (packer.SpawnNextCombination());
		--backPackStuffQty;
	}

	cout << "Total cost: " << bestTotalCost << endl;
	cout << "Total weight: " << bestTotalWeight << endl;

	for (size_t i = 1; i <= stuff.size(); ++i)
	{
		if (find(bestCombination.begin(), bestCombination.end(), i) != bestCombination.end())
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}

	cout << endl;

    return 0;
}

