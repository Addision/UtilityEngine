﻿/**
* @file mem_buffer.hpp
*
* @author Hourui (liquidmonkey)
*/
#ifndef __MEM_BUFFER_HPP__
#define __MEM_BUFFER_HPP__

#include "mem_message.hpp"

namespace Utility
{
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mem
{
////////////////////////////////////////////////////////////////////////////////////////////////////
class buffer_iface : public message
{
public:
	buffer_iface(void) = default;
	virtual ~buffer_iface(void) = default;

	//! Set size and initialize  
	virtual void init(std::size_t size) = 0;

	//! Reset initialize 
	virtual void clear(void) = 0;

	//! Returns: total writable size
	virtual net_size_t writable_size(void) = 0;
	//! Reg write operation
	//! Param:(in-out)size [0~MAX_PACKET_LEN]
	virtual char* write(net_size_t& size) = 0;
	//! Commit write operation
	//! Returns: |true [m_lastread = 0]|false [m_lastread != 0]|
	//!	Next:	 |Need notify readable |No need notify readable|
	virtual bool commit_write(net_size_t size) = 0;

	//! Returns: total readable size, 0 when readable size less-than exp.
	//! Change member [m_lastread] to 0 when readable size less-than exp.
	//! Next: readable size less-than exp [m_lastread = 0]. Need wait for readable notify.
	virtual net_size_t readable_size(net_size_t exp = 0) = 0;
	//! Reg read operation
	//! Param:(in-out)size [0~MAX_PACKET_LEN]
	//! Always change member [m_lastread]
	virtual const char* read(net_size_t& size) = 0;
	//! Commit read operation
	//! Release space for write operation
	virtual void commit_read(net_size_t size) = 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////
}//namespace mem
////////////////////////////////////////////////////////////////////////////////////////////////////
}//namespace Utility 
#endif //__MEM_BUFFER_HPP__