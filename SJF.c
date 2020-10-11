#include<stdio.h>
#include<stdlib.h>

struct sjf{
    int pro;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}temp;



void main(){
    int sum=0,n;
    int cap=0;
    int count=1;
    printf("Enter number of processes");
    scanf("%d",&n);
    struct sjf obj[n];
    struct sjf ob[n];
    for(int i=0;i<n;i++){
        scanf("%d",&obj[i].pro);
        scanf("%d",&obj[i].at);
        scanf("%d",&obj[i].bt);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(obj[j].at>obj[j+1].at){
                temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
            }
        }
    }

    ob[0].at=obj[0].at;ob[0].bt=obj[0].bt;ob[0].pro=obj[0].pro;

    cap=obj[0].bt+obj[0].at;

    ob[0].ct=ob[0].bt+ob[0].at;
    ob[0].tat=ob[0].ct-ob[0].at;
    ob[0].wt=ob[0].tat-ob[0].bt;
  

      for(int i=1;i<n;i++){
        for(int j=1;j<n-i-1;j++){
            if(obj[j].bt>obj[j+1].bt){
                temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
            }
        }
    }

while(count<n){
    for(int i=1;i<n;i++){
        if(obj[i].at<=cap){
        ob[count]=obj[i];
        ob[count].ct=ob[count-1].ct+ob[count].bt;
    ob[count].tat=ob[count].ct-ob[count].at;
    ob[count].wt=ob[count].tat-ob[count].bt;
    obj[i].at=9999;
    cap=cap+obj[i].bt;
    count++;
    break;
        }
    }
}

    printf("process  at    bt      ct      tat      wt");
     printf("\n");
        for(int i=0;i<n;i++) {
            printf("%d\t%d\t%d\t%d\t%d\t%d\t",ob[i].pro,ob[i].at,ob[i].bt,ob[i].ct,ob[i].tat,ob[i].wt);
            printf("\n");
        }

   



}
