#include <stdio.h>
#include <stdlib.h>

struct Voter{
    char name[12];
    char surname[12];
    int pin;
};

void getData(int n, struct Voter r1[]){
    for(int i=0;i<n;i++){
        scanf("%s %s %d",r1[i].name,r1[i].surname,&r1[i].pin);
    }
}
void merge(int n, int m, struct Voter r1[], struct Voter r2[], struct Voter combined[]){
    for(int i=0;i<n;i++){
        combined[i]=r1[i];
    }
    int j=0;
    for(int i=n;i<=m+n;i++){
        combined[i]=r2[j];
        j++;
    }
}
void sort(int total, struct Voter combined[]){
    int minIndex;
    struct Voter temp;
    for(int i=0;i<total-1;i++){
        minIndex=i;
        for(int j=i+1;j<total;j++){
            if(combined[j].pin<combined[minIndex].pin){
                minIndex=j;
            }
        }
        temp=combined[i];
        combined[i]=combined[minIndex];
        combined[minIndex]=temp;
    }
}
void print(int k, struct Voter combined[]){
    printf("%s %s %d",combined[k-1].name,combined[k-1].surname,combined[k-1].pin);
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    struct Voter r1[5000];
    struct Voter r2[5000];
    struct Voter combined[10000];
    getData(n,r1);
    int m;
    scanf("%d",&m);
    getData(m,r2);
    merge(n,m,r1,r2,combined);
    int total=n+m;
    sort(total,combined);
    print(k,combined);
    return 0;
}