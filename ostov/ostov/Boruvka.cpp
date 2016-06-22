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
	m_graph.CreateByArcList(fin);
}

CGraph CBoruvka::GetGraph()
{
	return m_graph;
}

NodePathNodeVector CBoruvka::GetOstov()
{
	InitComponents(m_graph.GetNodes());

	while (m_components.size() > 1)
	{
		for (auto const &component : m_components)
		{
			AddClosestNode(component);
		}
		resetComponents();
	}

	return m_links;
}

void CBoruvka::InitComponents(NodePtrVector nodes)
{
	for (auto const &node : nodes)
	{
		ComponentPtr comp = make_shared<CComponent>();
		comp->AddNode(node);
		m_components.push_back(comp);
	}
}

void CBoruvka::AddClosestNode(ComponentPtr component)
{
	NodePathNodeVector allLinks = {};

	for (auto const &node : component->GetNodes())
	{
		NodePathNodeVector nodeLinks = node->GetNodeLinks();
		allLinks.insert(allLinks.end(), nodeLinks.begin(), nodeLinks.end());
	}

	NodePathNodeVector freeLinks = {};

	for (auto const &link : allLinks)
	{
		if (!component->hasNode(link.second.first))
		{
			freeLinks.push_back(link);
		}
	}

	NodePathNode closestLink = GetClosestLink(freeLinks);
	component->AddNode(m_graph.GetNode(closestLink.second.first));
	AddLink(closestLink);
}

NodePathNode CBoruvka::GetClosestLink(NodePathNodeVector links)
{
	NodePathNode closestLink = links.at(0);

	for (auto const &link : links)
	{
		if (link.second.second < closestLink.second.second)
		{
			closestLink = link;
		}
	}
	return closestLink;
}

void CBoruvka::resetComponents()
{
	NodePtrVector allNodes = m_graph.GetNodes();
	while (allNodes.size() > 0)
	{
		m_components.push_back(GetNewComponent(allNodes));
	}
}

void CBoruvka::AddLink(NodePathNode link)
{
	m_links.push_back(link);
}

ComponentPtr CBoruvka::GetNewComponent(NodePtrVector & allNodes)
{
	ComponentPtr comp = make_shared<CComponent>();
	ExpandComponent(allNodes.at(0), comp, allNodes);
	return comp;
}

void CBoruvka::ExpandComponent(NodePtr node, ComponentPtr & comp, NodePtrVector & allNodes)
{
	comp->AddNode(node);
	for (auto &adjacentNode : GetAdjacentNodes(node))
	{
		ExpandComponent(adjacentNode, comp, allNodes);
	}
	allNodes.erase(allNodes.begin() + node->GetIndex());
}

NodePtrVector CBoruvka::GetAdjacentNodes(NodePtr node)
{
	NodePtrVector adjacentNodes = {};
	unsigned index = node->GetIndex();
	for (auto const &link : m_links)
	{
		if (link.first == index)
		{
			adjacentNodes.push_back(m_graph.GetNode(link.second.first));
		}
		if (link.second.first == index)
		{
			adjacentNodes.push_back(m_graph.GetNode(link.first));
		}
	}
	return adjacentNodes;
}