#include<stdio.h>

int main(){
    char packet[50];
    int buffer_size = sizeof(packet);

    int required_len = snprintf(packet, buffer_size, "ID:%d|STATUS:%s",1004,"ACTIVE");

    if(required_len >= buffer_size){
        printf("Waring : Packet data truncated!");
    }

    return 0;
}