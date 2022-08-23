#ifndef INTERFACE_ADDRESSES_LIB
#define INTERFACE_ADDRESSES_LIB

#include <map>

typedef struct {
    char *interface;
    char *address;
    char *netmask;
    char *family;
    char *mac;
    int internal;
} NetworkInterface;

map<char *, NetworkInterface> *getNetworkInterfaces();
int getNetworkInterfaceArrayLen(NetworkInterface *arr);

#endif