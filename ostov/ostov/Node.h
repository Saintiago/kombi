#pragma once
#include "stdafx.h"

class CNode;
typedef std::shared_ptr<CNode> NodePtr;
typedef std::vector<NodePtr> NodePtrVector;
typedef std::pair<unsigned, unsigned> NodePathPair;
typedef std::vector<NodePathPair> NodePathPairVector;

typedef std::pair<unsigned, NodePathPair> NodePathNode;
typedef std::vector<NodePathNode> NodePathNodeVector;

class CNode
{
public:

	CNode(unsigned index);
	~CNode();

	void AddLink(unsigned node, unsigned weight);
	NodePathPairVector & GetLinks();
	NodePathNodeVector & GetNodeLinks();
	unsigned GetIndex();

	bool GetVisited();
	void SetVisited(bool visited);

private:
	NodePathPairVector m_links;
	bool m_visited = false;

	unsigned m_index;
};
