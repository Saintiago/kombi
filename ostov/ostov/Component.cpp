#include "stdafx.h"
#include "Component.h"


CComponent::CComponent(NodePtr node)
{
	AddNode(node);
}


CComponent::~CComponent()
{
}

void CComponent::AddNode(NodePtr node)
{
	m_nodes.push_back(node);
}

NodePtrVector CComponent::GetNodes()
{
	return m_nodes;
}

bool CComponent::hasNode(unsigned nodeIndex)
{
	bool found = false;
	for (auto const & componentNode : m_nodes)
	{
		if (nodeIndex == componentNode->GetIndex())
		{
			found = true;
			break;
		}
	}
	return found;
}