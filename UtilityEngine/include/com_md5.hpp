/**
* @file com_md5.hpp
*
* @author Hourui (liquidmonkey)
**/

#ifndef __COM_MD5_HPP__
#define __COM_MD5_HPP__

#include <cstddef>
#include <cstdint>

namespace Utility
{
////////////////////////////////////////////////////////////////////////////////
namespace com
{
////////////////////////////////////////////////////////////////////////////////
class md5
{
public:
	md5();
	md5(const void* data, std::size_t len);

	md5(const md5&) = delete;
	md5& operator=(const md5&) = delete;

	void update(const void* input, std::size_t length);
	const char* c_str(void);
	void reset(); 
private:
	const unsigned char* digest();
	void final();
	void transform(const unsigned char block[64]);
	void encode(const std::uint32_t* input, unsigned char* output, std::size_t length);
	void decode(const unsigned char* input, std::uint32_t* output, std::size_t length);
private:
	char _result[32+1];
	std::uint32_t _state[4]; /* state (ABCD) */
	std::uint32_t _count[2]; /* number of bits, modulo 2^64 (low-order word first) */
	unsigned char _buffer[64]; /* input buffer */
	unsigned char _digest[16]; /* message digest */
	bool _finished; /* calculate finished ? */
	static constexpr unsigned char PADDING[64] = { 0x80 }; /* padding for calculate */
};
////////////////////////////////////////////////////////////////////////////////
}// namespace com
////////////////////////////////////////////////////////////////////////////////
}// namespace Utility
#endif // __COM_MD5_HPP__