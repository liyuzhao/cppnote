#include <iostream>
#include <cpuid.h>
#include <sstream>
using namespace std;


std::string GetCPUId()
{
    std::string strCPUId;
    unsigned int level = 1;
    unsigned eax = 3 /* processor serial number */, ebx = 0, ecx = 0, edx = 0;
    __get_cpuid(level, &eax, &ebx, &ecx, &edx);

    // byte swap
    int first = ((eax >> 24) & 0xff) | ((eax << 8) & 0xff0000) | ((eax >> 8) & 0xff00) | ((eax << 24) & 0xff000000);
    int last = ((edx >> 24) & 0xff) | ((edx << 8) & 0xff0000) | ((edx >> 8) & 0xff00) | ((edx << 24) & 0xff000000);

    // transfer to string
    std::stringstream ss;
    ss << std::hex << first;
    ss << std::hex << last;
    ss >> strCPUId;

    return strCPUId;
}

/**
 *  Test hello world
 * 
 */


// int main(void) {

//     for (int i = 0; i <= 10; i++)
//     {
//         cout << "i ->" << i << endl;
//     }
    
//     cout << "Hello World !" << endl;
//     return 0;
// }

int main(void) {

    std::string cpuId = GetCPUId();

    cout << "cpuId:" << cpuId << endl;

    return 0;
}