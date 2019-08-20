#include "ex0.h"

int main(int argc, char const *argv[])
{
    key_t key;
    int shm_id;
    int *shm;
    bool state = false;    

    key = ftok("/Users/takahashirintarou/Documents/shmdat/sdmkey",'R');
    shm_id = shmget(key,sizeof(int)*10,0666);
    printf("shm_id = %d\n", shm_id);
    shm = shmat(shm_id,0,0);
    while(*(shm+SYNCH) == 0 );
    while(1){
        if((*(shm+TIME) != 0) && (*(shm+DOOR) == 0)) state = true;
        else state = false;
        if(state) {
            *(shm+TURNTBL) = 1;
            printf("回転中\n");
        }else *(shm+TURNTBL) = 0;
    }
    return 0;
}
