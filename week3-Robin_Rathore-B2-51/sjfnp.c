#include<stdio.h>

typedef struct {
    int pid,AT,BT,ST;
    int CT,RT,TAT,WT;
} Process;


void sortByArrival(int n, Process p[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].AT > p[j+1].AT){
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void calculate(int n, Process p[]){
    int currTime = 0, complete = 0;
    int isCompleted[n];
    for(int i=0; i<n; i++) isCompleted[i] = 0;
    while(complete < n){
        int idx = -1;
        int minBT = 1e9;
        for(int i=0; i<n; i++){
            if(p[i].AT <= currTime && !isCompleted[i] && p[i].BT < minBT){
                minBT = p[i].BT;
                idx = i;
            }
        }
        if(idx == -1){
            currTime++;
            continue;
        }

        p[idx].ST = currTime;
        p[idx].CT = p[idx].ST + p[idx].BT;//  CT = ST + BT
        p[idx].TAT = p[idx].CT - p[idx].AT; //TAT  = CT - AT
        p[idx].RT = p[idx].ST - p[idx].AT;
        p[idx].WT = p[idx].TAT - p[idx].BT;
        currTime = p[idx].CT;
        isCompleted[idx] = 1;
        complete++;
    }
}
void sjfNonPreemptive(Process p[], int n){
    sortByArrival(n,p);
    calculate(n,p);
    int totalWT = 0, totalTat = 0, totalRT = 0;
    printf("\nID\tArrival\tBurst\tStart\tCompletion\tWaiting\tTAT\tResponse\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",p[i].pid,p[i].AT,p[i].BT,p[i].ST,p[i].CT,p[i].WT,p[i].TAT,p[i].RT);
        totalWT += p[i].WT;
        totalTat += p[i].TAT;
        totalRT += p[i].RT;
    }
    printf("Average Waiting Time : %.2f\n",(float)totalWT/n);
    printf("Average TurnAround Time : %.2f\n",(float)totalTat/n);
    printf("Average Response Time : %.2f\n",(float)totalRT/n);
}
int main (){
    int n;
    printf("Enter the process :");
    scanf("%d",&n);
    Process p[n];
    for(int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("Enter arrival time and burst time for process %d",p[i].pid);
        scanf("%d %d",&p[i].AT,&p[i].BT);
    }
    sjfNonPreemptive(p,n);
    return 0;
}