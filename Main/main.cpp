
#include "../Server/Server.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main(int argc , char * argv[])
{
    //Server* s= new Server();
    testing::InitGoogleTest(&argc ,argv);
    return RUN_ALL_TESTS();

    return 0;
}