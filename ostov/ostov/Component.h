#pragma once
#include "stdafx.h"
#include "Node.h"

class CComponent;
typedef std::shared_ptr<CComponent> ComponentPtr;
typedef std::vector<ComponentPtr> ComponentPtrVector;

class CComponent
{
public:
	CComponent(NodePtr node);
	~CComponent();

	void AddNode(NodePtr node);
	NodePtrVector GetNodes();
	bool hasNode(unsigned nodeIndex);

private:
	NodePtrVector m_nodes = {};

};

