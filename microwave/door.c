#include "ex0.h"

int main(int argc, char const *argv[])
{
    key_t key;
    int shm_id;
    int *shm;
    int doorstat;

    key = ftok("/Users/takahashirintarou/Documents/shmdat/sdmkey",'R');
    shm_id = shmget(key,sizeof(int)*10,0666);
    printf("shm_id = %d\n", shm_id);
    shm = shmat(shm_id,0,0);
    while(*(shm+SYNCH) == 0 );
    while(1){
        scanf("%d", &doorstat);
        if( doorstat == 0 ) *(shm+DOOR) = 0;
        else *(shm+DOOR) = 1;
    }
    return 0;
}
