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

	NodePathNodeVector GetOstov();
	

private:
	CGraph m_graph;
	ComponentPtrVector m_components = {};
	NodePathNodeVector m_links = {};

	void InitComponents(NodePtrVector nodes);
	void AddClosestNode(ComponentPtr component);
	NodePathNode GetClosestLink(NodePathNodeVector links);
	void resetComponents();
	void AddLink(NodePathNode link);

	ComponentPtr GetNewComponent(NodePtrVector & allNodes);
	void ExpandComponent(NodePtr node, ComponentPtr & comp, NodePtrVector & allNodes);
	NodePtrVector GetAdjacentNodes(NodePtr node);
};