#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    int randmax = RAND_MAX;
    int maxcount = 500;
    int count = 0;
    int hhcount = 0;
    int htcount = 0;
    int ignore = 0;
    int kekka = 0;

    while(count < maxcount){
        if(rand() > randmax/2){
            //hhとする
            hhcount++;
        }else{
            if(rand() > randmax/2) htcount++;
            else ignore--;
        }
        count++;
    }
    kekka = 100 * htcount/ (maxcount + ignore);
    printf("kekka %d\n", kekka);
    return 0;
}
