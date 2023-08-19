void test(int *a)
{
    (*a)++;
}
#include <stdio.h>
int main()
{
    int b = 6;
    
    //*a = 6;
    //b = &a;
    //*b = 7;
    test(&b);
    printf("%d\n", b);
}
