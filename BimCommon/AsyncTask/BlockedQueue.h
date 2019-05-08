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
		//m_maxCapacity为-1，代表队列无最大限制
		BlockedQueue(const int maxCapacity = -1)
			: m_maxCapacity(maxCapacity)
		{

		}
		virtual ~BlockedQueue()
		{
		}

		/** 
		 *	当满时，抛出异常
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
		 *	当满时，一直处于阻塞状态，等待
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
		 *	当为空是，一直处于阻塞状态，等待
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
		 *	当为空时，抛出异常
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
