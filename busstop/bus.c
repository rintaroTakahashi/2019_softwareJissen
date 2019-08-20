#include "bus.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int busnum = 40;
    int bustime[busnum];
    int temp;
    int peopleTime;
    int count = 0;
    int maxtime = 10;
    int mintime[maxtime];
    int five, ten, fif, twen, twenfive, over;

    //バス生成
    for(int i = 0; i < busnum; i++){
        bustime[i] = rand() % 600 + 1 ;
        if(bustime[i] < 0) bustime[i] = 0;
    }

    //バブルソート
    for (int i = 0; i < busnum; i++) {
        for (int j = busnum; j > i; j--) {
            if (bustime[j-1] > bustime[j]) {
                temp = bustime[j-1];
                bustime[j-1] = bustime[j];
                bustime[j] = temp;
            }
        }
    }

    //そーと確認
    for(int i = 0; i < busnum; i++){
        if(bustime[i] < 0) bustime[i] = 0;
    }
    while(count < maxtime){       
    
        //人生成
        peopleTime = rand() % 600 + 1;
        
        for(int i = 0; i < busnum; i++){
            mintime[count] = 999;
            if(peopleTime < bustime[i] ) {
                mintime[count] = bustime[i] - peopleTime;
                // printf("%d %d %d \n", peopleTime, bustime[i], mintime[count]);
                break;
            }
            
        }
        count++;
    }
        printf("---------------\n");

    for(int i = 0; i < maxtime; i++){
        if(mintime[i] < 5) five++;
        else if(mintime[i] < 10) ten++;
        else if(mintime[i] < 15) fif++;
        else if(mintime[i] < 20) twen++;
        else if(mintime[i] < 25) twenfive++;
        else over++;
        printf("%d\n",mintime[i]);
    }
    return 0;
}