#include<stdio.h>
typedef struct
{
	int at,bt,wt,tat,n,flag,id;

}process;



void FCFS(int n,process p[n]){
	int s;
	float avg,avgt;
	for(int i =0;i<n;i++){
		p[i].wt = s;
		s = p[i].bt + s;
		printf("Waiting time of process %d : %d\n",i+1,s);

	}
		for(int i = 0;i<n;i++){
			p[i].tat = p[i].wt+p[i].bt;
		}

	printf("\nGantt Chart : \n");
	printf("----------------------------------\n");
	printf("|");
	for(int i=0;i<n;i++)
	{
		printf(" P%d |",i+1);
	}
	printf("\n----------------------------------\n");
	printf("\n");
	printf("Process\tAT\tBT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].wt,p[i].tat);
	}
	for(int i =0;i<n;i++){
		avg = avg+p[i].wt;
		avgt = avgt + p[i].tat;
	}
	printf("Average WT is %f\n",avg/n );
	printf("Average TAT is %f\n",avgt/n );
}

//SJF NON PREEMPTIVE
void sjfNon(int n, process p[n]){
	int s,k,check,flag,temp,temp2;
	float avg=0.0,avgt=0.0;
	for(int i =0;i<n;i++){
		int count = 1;
	//	p[i].id = count;
		for(int j=i+1;j<n;j++){
			if(p[i].bt>p[j].bt){
				temp = p[i].bt;
				p[i].bt = p[j].bt;
				p[j].bt = temp;
				temp2 = p[i].at;
				p[i].at = p[j].at;
				p[j].at = temp2;
				p[i].id = count ;
				count++;

			}
		}
	}
	for(int i =0;i<n;i++){
		p[i].wt = s;
		s = p[i].bt + s;
		printf("Waiting time of process %d : %d\n",i+1,s);

	}
		for(int i = 0;i<n;i++){
			p[i].tat = p[i].wt+p[i].bt;
		}

	printf("\nGantt Chart : \n");
	printf("----------------------------------\n");
	printf("|");
	for(int i=0;i<n;i++)
	{
		// printf(" P%d |",p[i].id);
		printf(" P%d |",i+1);

	}
	printf("\n----------------------------------\n");
	printf("\n");
	printf("Process\tAT\tBT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		//if(p[i].bt>p[i+1].bt){
			printf("%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].wt,p[i].tat);
		//}
	}
	for(int i =0;i<n;i++){
		avg = avg+p[i].wt;
		avgt = avgt + p[i].tat;
	}
	printf("Average WT is %f\n",avg/n );
	printf("Average TAT is %f\n",avgt/n );
}


int main(){
	int n;
	printf("Enter the no. of proccesses\n");
	scanf("%d",&n );
	process p[n];
for(int i =0;i<n;i++){
	printf("Enter AT for P%d \n",i+1);
	scanf("%d",&p[i].at);
	printf("Enter BT for P%d \n",i+1);
	scanf("%d",&p[i].bt);
}

	sjfNon(n,p);
	return 0;
}
