#include <iostream>
#include <ClientPacket.h>
#include "UUID.h"

using namespace std;

int main(int argc, char* argv []) {
    cout << "Hello, World!" << endl;

    // Client Packet test
    ClientPacket c;
    c.uuid = uuid::generate_uuid_v4();
    c.name = "bob";
    c.paddleDirection = PADDLE_DOWN;

    string str = c.serialize();

    ClientPacket c2;
    c2.deserialize(str);

    cout << c2.uuid << endl;


    return 0;
}