#pragma once
#include "stdafx.h"

class CNode;
typedef std::shared_ptr<CNode> NodePtr;
typedef std::vector<NodePtr> NodePtrVector;
typedef std::pair<unsigned, unsigned> NodePathPair;
typedef std::vector<NodePathPair> NodePathPairVector;


class CNode
{
public:

	CNode();
	~CNode();

	void AddLink(unsigned node, unsigned weight);
	NodePathPairVector & GetLinks();

	bool GetVisited();
	void SetVisited(bool visited);

private:
	NodePathPairVector m_links;
	bool m_visited = false;
};
