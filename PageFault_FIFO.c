#include<stdio.h>

int main()
{
  int reference_Values[20], page_faults = 0, m, n, s, pages, frames,flag=0;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &reference_Values[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &frames);

      int temp[frames];
      for( m=0;m<frames;m++){
          temp[m] = -1;
      }

      for( m=0;m<pages;m++){
        s =0;
        flag=0;
        for(n=0;n<frames;n++){
          if (reference_Values[m] == temp[n]) {
            s++;
            page_faults--;
          }else{flag++;}

        }
        page_faults++;
        if(page_faults<=frames && s==0){
          temp[m] = reference_Values[m];
        }else if(s==0){
          temp[(page_faults -1 )%frames] = reference_Values[m];
        }
        printf("\n");
        for(n=0;n<frames;n++){
          printf("%d\t",temp[n]);
        }
        if (flag==3) {

          printf("\t*");
        }
      }
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
}
