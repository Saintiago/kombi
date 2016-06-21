#pragma once
#include "stdafx.h"
#include "Node.h"

class CGraph
{
public:
	CGraph();
	~CGraph();

	void CreateByArcList(std::ifstream & ArcList);
	size_t Size();
	NodePtr GetNode(unsigned index);
	NodePtrVector GetNodes();
	void WriteGraph(std::ostream & out);

private:
	NodePtrVector m_nodes;

	void AddNode(unsigned index);
};

