#include<stdio.h>
#include<pthread.h>

void add(int[]);
void sub(int[]);
void mul(int[]);
void div(int[]);

int main(){

pthread_t thread1,thread2,thread3,thread4;
int num[2];
printf("Which operation? \n");
printf("1: Add\n");
printf("2: Sub\n");
printf("3: Mul\n");
printf("4: Div\n");
printf("Enter your choice bet 1-4\n");
int ch;
scanf("%d",&ch );
switch (ch) {
  case 1:
  printf("Enter two numbers\n");

  for(int i =0;i<2;i++){
      scanf("%d",&num[i]);
  }
  pthread_create(&thread1,NULL,(void *)add,num);
  pthread_join(thread1,NULL);

  break;
  case 2:
  printf("Enter two numbers\n");

  for(int i =0;i<2;i++){
      scanf("%d",&num[i]);
  }
  pthread_create(&thread2,NULL,(void *)sub,num);
  pthread_join(thread2,NULL);

  break;
  case 3:
  printf("Enter two numbers\n");

  for(int i =0;i<2;i++){
      scanf("%d",&num[i]);
  }
  pthread_create(&thread3,NULL,(void *)mul,num);
  pthread_join(thread3,NULL);

  break;
  case 4:
  printf("Enter two numbers\n");

  for(int i =0;i<2;i++){
      scanf("%d",&num[i]);
  }
  pthread_create(&thread4,NULL,(void *)div,num);
  pthread_join(thread4,NULL);

  break;
  default:
  printf("Wrong Choice \n");
}

  return 0;
}
void add(int num[2])
{
	int res =num[0]+num[1];
	printf("The result from Thread 1(add) is : %d\n",res);
}

void sub(int num[2])
{
  int res =num[0] - num[1];
	printf("The result from Thread 2(sub) is : %d\n",res);
}

void mul(int num[2])
{
  int res =num[0] * num[1];
	printf("The result from Thread 3(mul) is : %d\n",res);
}

void div(int num[2])
{
  int res =num[0] / num[1];
	printf("The result from Thread 4(div) is : %d\n",res);
}
