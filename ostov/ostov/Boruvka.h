#pragma once
#include "stdafx.h"
#include "Graph.h"
#include "Component.h"

class CBoruvka
{
public:
	CBoruvka();
	~CBoruvka();

	void MakeGraph(std::ifstream & fin);
	CGraph GetGraph();

	CComponent GetOstov();
	

private:
	CGraph m_graph;
	ComponentPtrVector m_components = {};

	void InitComponents(NodePtrVector nodes);
	void AddClosestNode(ComponentPtr component);
};