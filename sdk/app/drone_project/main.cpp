#include "rplidar.h"
using namespace rp::standalone::rplidar;


#include <iostream>
using namespace std;

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//namespace Lidar = rp;

int main()
{

RPlidarDriver * drv  = RPlidarDriver::CreateDriver(DRIVER_TYPE_SERIALPORT); //Inititalize RDLidarDriver instance
if(!drv){
    fprintf(stderr,"Instance could not be created"); //throw error if instance can not be made
    exit(-69);
}

Initialize_Lidar(drv);


}

void Initialize_Lidar(RPlidarDriver * drv){
#ifdef _WIN32
drv->connect("com3", 115200); //for windows 
#elif defined __unix__
drv->connect("/dev/ttyUSB0", 115200); //for linux
#endif
}

