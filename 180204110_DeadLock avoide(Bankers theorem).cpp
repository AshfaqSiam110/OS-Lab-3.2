#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
    int m,n,i,j,k;
    string filename("pp.txt");
    ifstream input_file(filename);

    input_file >> m;
    input_file >> n;


    int maximum[m][n],allocation[m][n],avilableperiteration[m][n],need[m][n],total[n],avilable[n],totalallocation[n],p=0,f[n],y=0,sequence[m],ind=0,q=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            input_file >> maximum[i][j];
        }
    }


    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            input_file >> allocation[i][j];
        }
    }


    for(i=0;i<n;i++)
        input_file >> total[i];


    for(i=0;i<n;i++)
        totalallocation[i]=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            totalallocation[p++] += allocation[i][j];
        }
        p=0;
    }

    for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			need[i][j] = maximum[i][j] - allocation[i][j];
	}
	for(i=0;i<n;i++)
        avilable[i]=total[i]-totalallocation[i];


    printf("Maximum: \n");
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",maximum[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Allocated: \n");
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Need: \n");
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Maximum space in resource: \n");
    for(i=0;i<n;i++){
        printf("%d ",total[i]);
    }
    printf("\n\n");

    printf("Allocated space in resource: \n");
    for(i=0;i<n;i++){
        printf("%d ",totalallocation[i]);
    }
    printf("\n\n");

    printf("Avilable space in resource: \n");
    for(i=0;i<n;i++){
        printf("%d ",avilable[i]);
    }
    printf("\n\n");



    for (k=0;k<m;k++){
		f[k]=0;
	}
	for (k=0;k<m;k++){
		for(i=0;i<m;i++){
			if(f[i]==0){
				int flag = 0;
				for (j=0;j<n;j++) {
					if (need[i][j] > avilable[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					sequence[ind++] = i;
					for (y = 0; y < n; y++){
						avilable[y] += allocation[i][y];

					}

					f[i] = 1;
				}
			}
		}
	}

    int flag = 1;
	for(i=0;i<m;i++)
	{
        if(f[i]==0)
        {
            flag=0;
            printf("The following system is not safe");
            break;
        }
	}


	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < m - 1; i++)
		printf("P%d ->", sequence[i]+1);
	printf("P%d", sequence[m]);
	}
	printf("\n\n");
}
