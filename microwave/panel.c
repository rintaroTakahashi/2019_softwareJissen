#include "ex0.h"

int main(int argc, char const *argv[])
{
    key_t key;
    int shm_id;
    int *shm;
    int doorstat;
    int time = 0;
    int flg;

    key = ftok("/Users/takahashirintarou/Documents/shmdat/sdmkey",'R');
    shm_id = shmget(key,sizeof(int)*10,0666);
    printf("shm_id = %d\n", shm_id);
    shm = shmat(shm_id,0,0);
    while(*(shm+SYNCH) == 0 );
    while(1){
        if(time == 0){
            *(shm+TIME) = 0;
            printf("時間を入力してください\n");
            scanf("%d", &time);
            *(shm+TIME) = time;
        }else{
            if(flg == 0){
                *(shm+KEYPAD) = 0;
                printf("開始 -> 1, 停止　-> 0\n");
                scanf("%d", &flg);
            }
            if(flg == 1){
                printf("温め中 のこり%d秒\n",time);
                *(shm+KEYPAD) = 1;
                time = *(shm+TIME);
                if(time == 0) {
                    printf("終了\n");
                    flg = 0;
                }
            }
            //timerの稼働条件にこのkeypadの状態を追加する
        }
    }
    return 0;
}
