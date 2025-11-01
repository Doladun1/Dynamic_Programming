/*
 * hello_world.c
 *
 *  Created on: Sep 10, 2025
 *      Author: davae
 */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define INT8_MAX		127


// I dont want it global anymore I want an object that takes args and has private attributes

typedef struct Track{
	int arr[INT8_MAX];
	int idx;
	void *ptr;
	int *ptr2;
}Track;

//Add function to fill queue based on interr
void fill(int var, Track *track){
	printf("%s : var %d\n",__func__,var);
	track->arr[track->idx++] = var;
}

//Empty queues after interr 
int empty(Track *track){
	int buf;
	printf("%s ",__func__);

	buf = track->idx ? track->arr[--track->idx] : track->arr[track->idx] ;	
	return buf;
}

int main(){
	printf("Input Value:\n");
	fflush(stdout);
	int var =0;
	Track *track = (Track *) calloc(2,sizeof(Track));

/*	while(var != -999) {
		scanf("%d",&var);
		fill(var,track);
		}
*/
	printf("Stack: \n");
	while(track->idx>0){
		printf("Val: %d\n", empty(track));
	}

	fill(100,track);
	printf("idx:%d\n",track->idx);
	printf("Val: %d\n", empty(track));
	fill(100,track);

	while(track->idx>0){
		printf("Val: %d\n", empty(track));
	}	
	printf("idx:%d\n",track->idx);
	if (++track == NULL)	printf("Nothing there\n");

	return 0;
}