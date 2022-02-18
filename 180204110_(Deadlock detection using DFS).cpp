#include<stdio.h>
int n,i,j,starting_node,k=1,top=1,countt=1,cycle=0,en,sn,l=2,counth=0;
int stackk[25], sortt[25], matrix[25][25], parent[25];
char visited[25];

void DFS(int v);
int main()
{
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter the matrix : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",& matrix[i][j]);
        }
    }


    for(i=1;i<=n;i++){
        visited[i]='W';
    }


    printf("Enter starting node : ");
    scanf("%d",&starting_node);
    stackk[1]=starting_node;
    if(starting_node==1){
        parent[i]=0;
    }
    DFS(starting_node);
    printf("\n");

    printf("DFS sort: \n");
    for(j=1;j<=n;j++)
        printf("%d ",sortt[j]);

    printf("\n");
    for(i=1;i<n;i++){
        for(j=1;j<=n;j++){
            if((matrix[sortt[i]][j] == sortt[j]) && (i!=j)){
                cycle=1;
                sn=matrix[sortt[i]][j];
                en=sortt[i];
            }
        }
    }
    if(cycle==1){
        int deadlock[n],y,z,x=1;
        for(i=1;i<=n;i++){
            if(sortt[i] == sn){
                y=i;
            }
            if(sortt[i] == en){
                z=i;
            }
        }
        deadlock[1]=en;
        int p = sortt[z];
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(parent[p]==sortt[j]){

                    deadlock[l++]=sortt[j];
                    p=j;
                    counth++;
                    if(sortt[j]=sn)
                        break;
                }
            }
        }
        printf("Deadlock detected. The deadlock-cycle is: ");
        for(j=(counth+1);j>=1;j--)
        printf("%d ",deadlock[j]);
    }
    else {
        printf("Deadlock does not detected");
    }
}

void DFS(int node){
    sortt[k++]=stackk[top--];
    for(i=1;i<=n;i++){
        if((matrix[node][i]==1) && (visited[i]=='W')){
                stackk[++top]=i;
                visited[i]='G';

                if(countt==1){
                    visited[node]=1;
                }
                ++countt;

                parent[i]=node;
                if(i==1){
                     parent[i]=0;
                }
        }
    }
    if(top!=0)
        DFS(stackk[top]);
}



/*       A(1)-----
        /   \     \
       B(2)  C(3)  |
      /     /   \  |
     D(4)  E(5)  F(6)
 */

 /*
  0 1 1 0 0 0
  0 0 0 1 0 0
  0 0 0 0 1 1
  0 0 0 0 0 0
  0 0 0 0 0 0
  1 0 0 0 0 0
  */

