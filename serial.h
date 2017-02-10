#include <stdio.h>
#include <iostream>
//#include <fildes.h>
#include <fcntl.h>

using namespace std;

int main()
{

    cout << "starting up" << endl;
    int serialPort;
    serialPort = open( "/dev/ttyUSB0", O_RDWR  , 0 );
    if(serialPort == 0)
    {
        cout << "Error opening file." << endl;
        return(0);
    }
    write(serialPort, "0", 2);

    char* readBuffer[20];
    cout << "starting to read ... " << endl;
    while(1)
    {
        read(serialPort, readBuffer, 10);

        cout << readBuffer << endl;
    }

    close(serialPort);

    cout << "end" << endl;
    return(0);
}