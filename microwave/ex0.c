#include "ex0.h"

int main(int argc, char const *argv[]){
    key_t key;
    int shm_id;
    int *shm;
    key = ftok("/Users/takahashirintarou/Documents/shmdat/sdmkey",'R');
    shm_id = shmget(key,sizeof(int)*10,0666|IPC_CREAT);
    printf("shm_id = %d\n", shm_id);
    shm = shmat(shm_id,0,0);
    *(shm+SYNCH) = 0;
    printf("run all the programs now, then hit a return key.\n ");
    getchar();
    *(shm+SYNCH) = 1;

    while(1){
        if( *(shm+DOOR) != 0) printf("door open\n");
        //ここでオンオフ切り替えられるようにSYNCHを変える操作が欲しい
    }
    return 0;
}