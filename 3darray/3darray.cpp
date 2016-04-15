#include <iostream>

int main (int argc, char const *argv[])
{
    int numbers [2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}}
        ,{{13,14,15,16},{17,18,19,20},{21,22,23,24}}};
    
    int i,j,k;
    
    printf("3D:\n");
    for(i=0;i<2;++i)
        for(j=0;j<3;++j)
            for(k=0;k<4;++k)
                printf("%i ", numbers[i][j][k]);
    
    printf("\n\n1D:\n");
    for(i=0;i<24;++i)
        printf("%i ", *((int*)numbers+i));
    
    printf("\n");
    
    return 0;
}