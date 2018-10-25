#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <stdlib.h>

//main

int main()
{
    //終了時関数を登録
    atexit(exitprocess);
    
    const char SERIALNAME[] = "/dev/ttyACM0";
    int fd;
    fd = serialOpen( SERIALNAME , 9600 );
    if (fd < 0)
    {
        printf("Serial conection dennied" );
        return -1;
    }
    else
    {
        printf ( "Serial connection succeced to %s at %d\n" , SERIALNAME , fd );
    }
    int i;
        
    while ( 1 )
    {
        serialPuts ( fd , "a" );
        if ( serialDataAvail( fd ) > 0 )
        {
            
            printf("%c", serialGetchar (fd) );
        }
    }

    
    return 0;
}

void exitprocess()
{
    printf ("Program closed");
    serialClose (fd) ;
}
