/*
* COMP 3500: Project 5 Scheduling
* Shyam Patel
*
* I am using the sample code provided in files section in Canvas
*
* This source code shows how to conduct separate compilation.
*
* scheduler.h: The header file of scheduler.c
*/
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_
#define MAX_TASK_NUM 32

typedef unsigned int u_int;

typedef struct task_info {
    u_int pid;
    u_int arrival_time;
    u_int burst_time;
    u_int remaining_time;
    u_int queued; // indicates a task is in the ready queue
    u_int start_time; // starting time
    u_int finish_time; // finish time
    u_int null; // indicates a task has finished, i.e. 'removed' from ready queue
    u_int TurnTaken; //used for round robin
} task_t;

typedef struct stat_info { // statistical analysis
    double WaitingAverage;
    double TurnaroundAverage;
    double ResponseAverage;
    double CPUUsage;
} stat_info_t;

// TaskList is the waiting list, size is the size of waiting list, Policy is the policy passed in, and quantum is for round robin
void TaskManager(task_t TaskList[], int size, char *Policy, u_int quantum);
// chooses the correct policy function to call

//task_array is the waiting list, count is the size of waiting list
void fcfs_policy(task_t task_array[], u_int count);
//implements first come first serve, i.e. tasks are processed in order of arrival

//task_array is the waiting list, count is the size of waiting list
void srtf_policy(task_t task_array[], u_int count);
//implements shortest remaining time first, i.e. remaining time is processed on ready queue before a task is chosen

//task_array is the waiting list, count is the size of waiting list, quantum is length of equal time slices
void rr_policy(task_t task_array[], u_int count, u_int quantum);
//implements round robin, allows for time slices so that response time is minimized

#endif
