#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;


int check(int a) {
    return (*(char *)&a);
}

 

int main(void) {
 
    if(check(1) == 1) {
        cout << "该机器是小端!\n";
    } else {
        cout << "该机器是大端!\n";
    }

 return 0;
}