
#include "preprocessing.h"


int   converttobinary(int * src,int row, int col,int threshold){
int i=0;
int MAX = row*col;

if(src == NULL) return -1; //check if  pointers have  been initialised

	for( ; i<MAX; i++){
	src[i] = src[i] > threshold ? 0 : 1;

	}
return 0;
}
