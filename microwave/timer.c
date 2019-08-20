#include "ex0.h"

int main(int argc, char const *argv[])
{
    key_t key;
    int shm_id;
    int *shm;
    int doorstat;
    int time = 0;

    key = ftok("/Users/takahashirintarou/Documents/shmdat/sdmkey",'R');
    shm_id = shmget(key,sizeof(int)*10,0666);
    printf("shm_id = %d\n", shm_id);
    shm = shmat(shm_id,0,0);
    while(*(shm+SYNCH) == 0 );
    while(1){
        if(time == 0){
            if(*(shm+KEYPAD) != 0){
                time = *(shm+TIME);
            }
        }
        else{
            sleep(1);
            if((*(shm+DOOR) != 0) || *(shm+KEYPAD) == 0) printf("stop timer\n");
            else {
                time = time -1;
                *(shm+TIME) = time;
                printf("のこり%d秒\n", time);
            }
            if(time == 0) printf("終了\n");
        }
    }
    return 0;
}
