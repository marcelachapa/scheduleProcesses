/*
 * File: prog.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h> 

struct PCB_st 
{
    int ProcId;
    int ProcPR; 
    int CPUburst; 
    int myReg[8]; 
    int queueEnterClock, waitingTime; /* you can add other fields */
    struct PCB_st *next;
};

int CPUreg[8] = {0};
struct PCB_st *Head=NULL;
struct PCB_st *Tail=NULL;
int CLOCK=0; 
int Total_waiting_time=0; 
int Total_turnaround_time=0; 
int Total_job=0;

typedef struct PCB_st node_t;

void add_group_list(node_t *ptr_list);

int main( int argc, char *argv[] ) {
    FILE *fp;
    int alg, inpt, quantum;
    int pID, pPriority, burst;
    int i;
    int node=0;

    //loop through arguments and find the index of the txt file
    //find -alg, input , -quantum
    for(i=0; i<=argc; i++){
        if(strcmp("-alg", argv[i]) == 0){
            alg=i+1;
        }
        if(strcmp("-input", argv[i]) == 0){
            inpt=i+1;
        }
        if(strcmp("-quantum", argv[i]) == 0){
            quantum=i+1;
        }
    }
    //open file and read using index assignes in first loop
    fp = fopen(argv[inpt], "r");

    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }


    //loop and read the read a line consisting of three integers: Process Id, Process Priority, CPU Burst time.  fscanf(...,"%d %d %d",...); will be OK
     // in loop
        //allocate struct and read in the data into struct

        //set its next pointer and continue reading 
     while(feof(fp)!=EOF)
        {
            fscanf(fp,"%d %d %d",&pID, &pPriority, &burst);
           if(node == 0){
            struct PCB_st *PCB = (struct PCB_st*) malloc(sizeof(struct PCB_st));
            PCB->ProcId = pID;
            PCB->ProcPR = pPriority;
            PCB->CPUburst = burst;
            Head = PCB;
            Tail = PCB;
            PCB->next = NULL;
            node=1;
           }
           else{
               struct PCB_st *PCB = (struct PCB_st*) malloc(sizeof(struct PCB_st));
                Tail = PCB;
                PCB->ProcId = pID;
                PCB->ProcPR = pPriority;
                PCB->CPUburst = burst;
                PCB->next = NULL;
                Tail = PCB;
           }
        }
    //After list has been created, based on input call the function and pass it the linked list 

return 0;
}

