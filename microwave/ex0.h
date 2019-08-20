#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdbool.h>
enum op {SYNCH, DOOR, TIME, LIGHT, TURNTBL, EMITTER, KEYPAD };