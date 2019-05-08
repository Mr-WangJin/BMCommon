#include "stdafx.h"
#include "CascadeNode.h"

using namespace BIMCOMMON;

CascadeNode::CascadeNode()
{

}

CascadeNode::~CascadeNode()
{
	this->clear();
}

void CascadeNode::addChild(CascadeNode * node)
{
	if (m_child.contains(node))
	{
		return;
	}
	m_child.append(node);
}

void CascadeNode::removeChild(CascadeNode * node)
{
	if (!m_child.contains(node))
	{
		return;
	}
	m_child.removeOne(node);
}

const QList<CascadeNode*>& CascadeNode::getChild() const
{
	return m_child;
}

bool CascadeNode::hasChild() const
{
	return m_child.count() > 0;
}

void CascadeNode::clear()
{
	for each (auto var in m_child)
	{
		delete var;
	}
	m_child.clear();
}



