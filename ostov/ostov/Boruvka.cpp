#include "stdafx.h"
#include "Boruvka.h"

using namespace std;

CBoruvka::CBoruvka()
{
}


CBoruvka::~CBoruvka()
{
}

void CBoruvka::MakeGraph(ifstream & fin)
{
	//m_graph.CreateByAdjacencyMatrix(fin);
	m_graph.CreateByArcList(fin);
}

CGraph CBoruvka::GetGraph()
{
	return m_graph;
}

CComponent CBoruvka::GetOstov()
{
	InitComponents(m_graph.GetNodes());

	while (m_components.size() > 1)
	{
		for (auto const &component : m_components)
		{
			component->AddClosestNode();
		}
	}
}

void CBoruvka::InitComponents(NodePtrVector nodes)
{
	for (auto const &node : nodes)
	{
		m_components.push_back(make_shared<CComponent>(node));
	}

	for (auto const &component : m_components)
	{
		AddClosestNode(component);
	}
}

void CBoruvka::AddClosestNode(ComponentPtr component)
{
	for (auto const &node : component->GetNodes())
	{

	}
}

