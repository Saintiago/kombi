#include "stdafx.h"
#include "Graph.h"

using namespace std;

void ThrowOutOfRange(size_t pos)
{
	std::stringstream ss;
	ss << "There is no " << pos << "th node in graph!";
	throw std::out_of_range(ss.str());
}

CGraph::CGraph()
{
}


CGraph::~CGraph()
{
}

void CGraph::CreateByArcList(ifstream & is)
{
	string line;
	unsigned n1, n2, path;
	while (getline(is, line))
	{
		stringstream arc(line);
		arc >> n1 >> n2 >> path;
		AddNode(n1);
		AddNode(n2);
		m_nodes.at(n1)->AddLink(n2, path);
		m_nodes.at(n2)->AddLink(n1, path);
	}
}

void CGraph::WriteGraph(ostream & out)
{
	unsigned index = 0;
	for (auto & node : m_nodes)
	{
		out << "Node " << index << " linked to: ";
		for (auto & link : node->GetLinks())
		{
			out << "(" << link.first << ", " << link.second << ") ";
		}
		out << endl;
		index++;
	}
}

size_t CGraph::Size()
{
	return m_nodes.size();
}

NodePtr CGraph::GetNode(unsigned index)
{
	if (index > (Size() - 1))
	{
		ThrowOutOfRange(index);
	}
	return m_nodes.at(index);
}

void CGraph::AddNode(unsigned index)
{
	unsigned curSize = m_nodes.size();
	if (index >= curSize)
		for (unsigned i = 0; i <= (index - curSize); i++)
		{
			m_nodes.push_back(make_shared<CNode>(index));
		}
}

NodePtrVector CGraph::GetNodes()
{
	return m_nodes;
}