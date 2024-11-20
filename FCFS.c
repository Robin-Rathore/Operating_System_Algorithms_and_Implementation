#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int burst_time[n];
    int arrival_time[n];

    printf("Enter the Burst Time Details : ");
    for(int i =0; i < n; ++i){
        scanf("%d", &burst_time[i]);
    }
    printf("Enter the arrival Time Details : ");
    for(int i =0; i < n; ++i){
        scanf("%d", &arrival_time[i]);
    }
    for(int i =1; i <n; ++i){
        burst_time[i] = burst_time[i] + burst_time[i-1];
    }
    int sum =0;
    for(int i =0; i < n-1; ++i){
        sum += burst_time[i];
    }

    printf("Waiting time is : %d", sum/n);
}