#include <stdio.h>
#include <iostream>
#include <vector>

#include "UtilityTest.hpp"
#include "logger.hpp"
#include "com_hex_caster.hpp"
using namespace Utility;

int main(void)
{
	logger klogger(logger::log_level::debug);
	Clog::active_logger(&klogger);

	UtilityTest::_Service();
	UtilityTest::_Singleton();
	UtilityTest::_ThreadPool();
	UtilityTest::_DataFactory();
	//UtilityTest::_Mysql();
	UtilityTest::_Protobuf();

	UtilityTest::_Other();
	std::cout << static_cast<unsigned short>((1437439665242112 & 0x0000ffff00000000ULL) >> 32) << std::endl;
	Clog::debug("test done!");
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}

