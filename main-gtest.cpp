#include <iostream>
#include <gtest.h>
#include <string>
#include "test1.h"
#include "test2.h"
#include "test3.h"
using namespace std;

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
