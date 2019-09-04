#include<stdio.h>
int main(){

  int reference_Values[20],temp[20],l,k, page_faults = 0, m, n, s, pages, frame,flag=0,a,b,position;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &reference_Values[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &frame);

      int frames[frame];
      for( m=0;m<frame;m++){
          frames[m] = -1;
      }

      for(n=0;n<pages;n++){
        for(m=0;m<frame;m++){
          if(reference_Values[n]==frames[m]){
            a=b=1;
            break;
          }
        }
        if(a==0){
          for(m=0;m<frame;m++){
            if(temp[m]==-1){
              a=1;
              break;
          }
        }
      }
      if(b==0){
        for(m = 0; m < frame; m++){
             temp[m] = 0;
           }
           for(k = n - 1, l = 1; l < frame; l++, k--)
                          {
                                for(m = 0; m < frame; m++)
                                {
                                      if(frames[m] == reference_Values[k])
                                      {
                                            temp[m] = 1;
                                      }
                                }
                          }

           for(m = 0; m < frame; m++){
                  if(temp[m]==0)
                    {
                      position = m;
                    }
                  }
                  frames[position] = reference_Values[n];
                }

              printf("\n");
           for(m = 0; m < frame; m++)
           {
                 printf("%d\t", frames[m]);
           }
         }

  return 0;
}
