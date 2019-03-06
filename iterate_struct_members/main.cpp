#include <stdio.h>
typedef struct {
  int num1;
  int num2;
  int num3;
} mystruct;

int main()
{
    mystruct numStruct;

    numStruct.num1 = 0;
    numStruct.num2 = 1;
    numStruct.num3 = 2;
    
    int* numPtr = &numStruct.num1;
 
    for(int i = 0; i <= 2; i++)
    {
        printf("%d\n",*numPtr++);
    }
    return 0;
}