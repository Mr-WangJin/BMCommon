#pragma once

/** 
 *	�����
 *  �������ڵ㣬֧�������û�����
 */

#include <qvariant.h>
#include "BMGlobal.h"

namespace BIMCOMMON
{

	class BIMCOMMON_EXPORT CascadeNode
	{
	public:
		CascadeNode();
		~CascadeNode();

		void addChild(CascadeNode* node);
		void removeChild(CascadeNode* node);

		void clear();

		const QList<CascadeNode*> &getChild() const;
		bool hasChild() const;

		QVariant getUserData() { return m_userData; };
		void setUserData(const QVariant &userData) { m_userData = userData; };

	private:
		QList<CascadeNode*> m_child;

		QVariant m_userData;
	};
}