/**
* @file task_dispatcher.hpp
*
* @author Hourui (liquidmonkey)
*/
#ifndef __TASK_DISPATCHER_HPP__
#define __TASK_DISPATCHER_HPP__

#include "msg_controler.hpp"

namespace Utility
{
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace task
{
////////////////////////////////////////////////////////////////////////////////////////////////////
class dispatcher_iface
{
public:
	struct task_info
	{
		msg::controler_iface*		m_controler;
		task::object_iface*			m_obj;
		std::uint32_t				m_compkey;
		mem::message*				m_message;
		void*						m_userdata;

		void run(void)
		{
			m_controler->handle_wrap(m_obj, m_compkey, m_message, m_userdata);
		}
	};
public:
	virtual void start(std::uint32_t nworker) = 0;
	virtual void stop(void) = 0;
	virtual void dispatch(task_info&& _task) = 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
}//namespace task
////////////////////////////////////////////////////////////////////////////////////////////////////
}//namespace Utility 
#endif //__TASK_DISPATCHER_HPP__