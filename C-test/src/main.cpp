#include <iostream>
#include <pcap/pcap.h>


using namespace std;


/**
 *  Test hello world
 * 
 */
int main(void) {

    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    dev = pcap_lookupdev(errbuf);
    if(dev == nullptr) {
        cout << "cound't find default device: %s\n" << errbuf;
        return 2;
    }

    cout << "Device:" << dev << endl;
    return 0;
}