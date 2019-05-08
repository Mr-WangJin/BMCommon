#pragma once

#include "BMGlobal.h"
#include <QMutex>
#include <QQueue>
#include <QWaitCondition>

namespace BMCOMMON
{
	template<typename T>
	class BIMCOMMON_EXPORT BlockedQueue
	{
	public:
		//m_maxCapacityΪ-1������������������
		BlockedQueue(const int maxCapacity = -1)
			: m_maxCapacity(maxCapacity)
		{

		}
		virtual ~BlockedQueue()
		{
		}

		/** 
		 *	����ʱ���׳��쳣
		 */
		inline void add(const T &t)
		{
			QMutexLocker locker(&m_mutex);
			if (true == hasCapacity())
			{
				if (m_queue.size() >= m_maxCapacity)
				{
					throw std::exception("");
				}
			}
			m_queue.enqueue(t);

			m_notEmpty.wakeAll();
		};
		/**
		 *	����ʱ��һֱ��������״̬���ȴ�
		 */
		inline void put(const T &t)
		{
			m_mutex.lock();
			if (true == hasCapacity())
			{
				while (m_queue.size() >= m_maxCapacity)
				{
					m_notFull.wait(&m_mutex);
				}
			}
			m_queue.enqueue(t);
			m_mutex.unlock();

			m_notEmpty.wakeAll();
		}
		/** 
		 *	��Ϊ���ǣ�һֱ��������״̬���ȴ�
		 */
		inline T take() 
		{
			m_mutex.lock();
			while (m_queue.empty())
			{
				m_notEmpty.wait(&m_mutex);
			}

			T temp = m_queue.dequeue();

			m_mutex.unlock();
			m_notFull.wakeAll();
			return temp;
		}
		/** 
		 *	��Ϊ��ʱ���׳��쳣
		 */
		inline T remove()
		{
			QMutexLocker locker(&m_mutex);

			if (m_queue.empty())
			{
				throw std::exception("queue is empty");
			}

			T temp = m_queue.dequeue();
			m_notFull.wakeAll();
			return temp;
		}

		inline bool isEmpty() 
		{
			QMutexLocker locker(&m_mutex);
			return m_queue.isEmpty();
		};

		inline size_t size() 
		{
			QMutexLocker locker(&m_mutex);
			return m_queue.size();
		};
	private:
		bool hasCapacity() const
		{
			return m_maxCapacity > 0;
		}

	protected:
		QQueue<T>			m_queue;
		QMutex				m_mutex;
		QWaitCondition		m_notEmpty;
		QWaitCondition		m_notFull;

		int					m_maxCapacity;
	};
}
