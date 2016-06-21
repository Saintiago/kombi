#include "stdafx.h"
#include "Node.h"

using namespace std;

CNode::CNode(unsigned index)
	:m_index(index)
{
}

CNode::~CNode()
{
}

void CNode::AddLink(unsigned node, unsigned weight)
{
	m_links.push_back(make_pair(node, weight));

	if (m_links.size() > 1)
	{
		for (size_t i = (m_links.size() - 1); i > 0 ; i--)
		{
			if (m_links.at(i).second < m_links.at(i - 1).second)
			{
				m_links.at(i).swap(m_links.at(i - 1));
			}
			else
			{
				break;
			}
		}
	}
}

NodePathPairVector & CNode::GetLinks()
{
	return m_links;
}

NodePathNodeVector & CNode::GetNodeLinks()
{
	NodePathNodeVector nodeLinks = {};
	for (auto const &link : m_links)
	{
		NodePathNode nodeLink = { m_index, {link.first, link.second} };
		nodeLinks.push_back(nodeLink);
	}
	return nodeLinks;
}

bool CNode::GetVisited()
{
	return m_visited;
}

void CNode::SetVisited(bool visited)
{
	m_visited = visited;
}

unsigned CNode::GetIndex()
{
	return m_index;
}