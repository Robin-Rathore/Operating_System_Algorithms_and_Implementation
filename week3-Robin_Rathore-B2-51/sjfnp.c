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

    while(complete < n){
        int index = -1;
        int maxi = 10000;

        for(int i =0; i < n; ++i) {
            if(currTime >= ps[i].at && !ps[i].isCompleted && maxi > ps[i].bt){
                maxi = ps[i].bt;
                index = i;
            }
        }
        ps[index].rbt--;
        if(ps[index].rbt == 0){
            complete++;
            ps[index].isCompleted = true;
            ps[index].ct = currTime+1;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;
        }
        currTime++;

    }
}

int main(){
    printf("Enter the n : ");
    int n;
    scanf("%d", &n);
    struct process ps[n];
    printf("ENtre the proces feails : \n");
    for(int i =0; i < n; ++i) {
        printf("P%d : ", i+1);
        scanf("%d %d", &ps[i].at, ps[i].bt);
        ps[i].isCompleted = false;
        ps[i].rbt = ps[i].bt;
    }

    calculate(ps, n);
}