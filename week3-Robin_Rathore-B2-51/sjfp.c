#include<stdio.h>
#include<stdbool.h>

struct process {
    int pid, at, bt, rbt;
    int tat, wt, ct, st, rt;
    bool isCompleted;
};


void calculate(struct process ps[], int n){
    int currTime = 0;
    int complete = 0;
    printf("GANTT CHART : \n");
    while(complete < n){
        int index = -1;
        int maxi = 10000;

        for(int i =0; i < n; ++i) {
            if(currTime >= ps[i].at && !ps[i].isCompleted && maxi > ps[i].bt){
                maxi = ps[i].bt;
                index = i;
            }
        }
        if(index == -1){
            printf("##");
            currTime++;
        }else{
            printf("| P%d", ps[index].pid);
            ps[index].st = currTime;
            ps[index].ct = ps[index].st + ps[index].bt;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;
            ps[index].rt = ps[index].st - ps[index].at;
            currTime = ps[index].ct;
            ps[index].isCompleted = true;
            complete++;
        }
    }
    printf("\n");
}

int main(){
    printf("Enter the n : ");
    int n;
    scanf("%d", &n);
    struct process ps[n];
    printf("ENtre the proces feails : \n");
    for(int i =0; i < n; ++i) {
        printf("P%d : ", i+1);
        ps[i].pid = i+1;
        scanf("%d %d", &ps[i].at, &ps[i].bt);
        ps[i].isCompleted = false;
        ps[i].rbt = ps[i].bt;
    }

    calculate(ps, n);
}