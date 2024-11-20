#include<stdio.h>
#include<stdbool.h>

struct process {
    int pid, at, bt;
    int tat, wt, ct;
};

void sortAtAr(struct process ps[], int n){
    for(int i =0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(ps[i].at > ps[j].at){
                struct process temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

void calculateCt(struct process ps[], int n) {
    ps[0].ct = ps[0].bt;

    for(int i = 1; i < n; ++i){
        ps[i].ct = ps[i-1].ct + ps[i].bt;
    }
}

void calculateTaTime(struct process ps[], int n) {
    for(int i =0; i < n; ++i){
        ps[i].tat = ps[i].ct - ps[i].at;
    }
}

void calculateWaTime(struct process ps[], int n){
    for(int i =0; i < n; ++i) {
        ps[i].wt = ps[i].tat - ps[i].bt;
    }
}


void print(struct process ps[], int n){
    printf("PID\t| At\t| Bt\t| Ct\t| TAT\t| Wt|\n");
    for(int i =0; i < n; ++i){
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    struct process ps[n];
    printf("Enter the process : \n");
    for(int i =0; i < n; ++i){
        printf("P%d", i+1);
        scanf("%d %d", &ps[i].at, &ps[i].bt);
    }

    sortAtAr(ps, n);

    calculateCt(ps, n);
    calculateTaTime(ps, n);
    calculateWaTime(ps, n);
    print(ps, n);

}