#include <stdio.h>

int main()
{
    int count=0,i,j,flag,p,r,k;
    printf("\nEnter the number of processes and resources : ");
    scanf("%d%d",&p,&r);
    int avail[r],max[p][r],allo[p][r],need[p][r],finish[p],safeseq[p];

    for(i=0;i<r;i++)
    {
        printf("\nEnter the resource value of resource R%d : ",i);
        scanf("%d",&avail[i]);
    }
    printf("\nAllocation Matrix...\n");
    for(i=0;i<p;i++)
    {
        finish[i]=0;
        for(j=0;j<r;j++)
        {
            printf("Enter resource value R%d of process P%d : ",j,i);
            scanf("%d",&allo[i][j]);
        }
    }
    printf("\nMax Matrix...");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("Enter resource value R%d of process P%d : ",j,i);
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    printf("\n---------MAX MATRIX -------\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("\n--------Need Matrix----------\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    while(count<p)
    {
        flag = 0;
        for(i=0;i<p;i++){
          if(finish[i]==0){
            for(j=0;j<r;j++){
              if(need[i][j]>avail[j]){break;}
            }
            if(j==r){
              for(k=0;k<r;k++){
                avail[k]+=allo[i][k];
                safeseq[count++] = i;
                finish[i] =1;
                flag=1;
              }
            }
          }
        }
        if (flag==0) {
          printf("\nSafe sequence does not exist.\n");
        }
    }
    printf("\nSafe sequence exists.\n");
    for(i=0;i<p;i++)
        printf("P%d  ",safeseq[i]);

    return 0;
}
