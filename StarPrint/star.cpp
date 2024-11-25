#include <stdio.h>

int main()
{

    //Chapter 1
    int i = 0;
    int j = 0;
    do{
        for(j = 0 ; j < i ; j++){
            printf("*");
        }
        printf("\n");
        i++;
    }while(i <= 10);

    printf("\n---------------------------------\n");

    bool status = true;
    i = 1;
    j = 0;

    do {
        // 별을 i만큼 출력
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");

        // i가 10보다 작을 때는 증가, 10일 때부터는 감소
        if (status) 
        {
            i++;
            if (i == 10) {
                status = false;  // 10에 도달하면 감소로 전환
            }
        } 
        else 
        {
            i--;
        }
    } while (i > 0);

    printf("\n---------------------------------\n");

    int center = 4;
    status = true;

    i = 0;
    do
    {
        for (j = 0; j < 9; j++) 
        {
            if (j >= center - i && j <= center + i) 
            {
                printf("*");
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
        if(status)  i++;
        if(i == 5) status = false;
        
    }while(i < 5);

    printf("---------------------\n");

    center = 4;
    status = true;
    i = 0;
    j = 0;

    do {
        for (j = 0; j < 9; j++) 
        {
            if (j >= center - i && j <= center + i) 
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        if (status)
        {
            i++;
            if (i == 4) status = false;
        } 
        else 
        {
            i--;
        }
    } while (i >= 0);

    printf("i = %d, j = %d, ",i,j);
}
