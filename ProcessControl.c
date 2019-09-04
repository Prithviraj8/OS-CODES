
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>                                                    //header file for fork
#include<sys/wait.h>                                                  //header file for wait
#include<stdlib.h>


 int main() {

  pid_t ptd;
  int n,i,j;
  printf("Enter the number of elements\n");
  scanf("%d",&n );
  int arr[n];

  printf("Enter elements\n");
  for (int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }

ptd = fork();
  if(ptd == 0){
    int temp1;
    printf("\nHello from child\n");
    printf("Child getPid is %d\n",getpid());
    printf("Child output of getppid = %d\n",getppid());

    for(i=0; i<n; i++)
  {
      for(j=i+1; j<n; j++)
      {
          if(arr[i] > arr[j])
          {
              temp1 = arr[i];
              arr[i] = arr[j];
              arr[j] = temp1;
          }
      }
  }
    printf("elements in ascending order are:  \n");
    for ( i = 0; i < n; i++) {
        printf("%d\n",arr[i] );
    }

    }else{

      int temp2;
      wait(NULL);
      printf("\nHello from Parent\n");
      printf("Parent getPid is %d\n",getpid());
      printf("Parent output of getppid = %d\n",getppid());


    for ( i = 0; i < n; i++) {
      for ( j = i+1; j < n; j++) {
        if(arr[i]<arr[j]){
          temp2 = arr[i];
          arr[i] = arr[j];
          arr[j] = temp2;
        }
      }
    }

    printf("elements in descending order are:  \n");
    for ( i = 0; i < n; i++) {
        printf("%d\n",arr[i] );
    }
  }
  return 0;
}
