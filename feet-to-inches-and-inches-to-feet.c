#include <stdio.h>

void f2i(void); 
void i2f(void);

int main(void)
{
    int n;

    while (1) {
        printf("1. Feet to Inches \n");  
        printf("2. Inches to feet \n"); 
        printf("3. Exit \n");          
        printf("Enter choice : ");          
        scanf("%d",&n);
        switch(n) {
            case 1:
                f2i();
                break;
            case 2:
                i2f();
                break;
            case 3:
                printf("Thanks! \n");
                return 0;
                break;
            default:
                printf("Invalid input.. try again \n");
                break;
        }
    }

    return 0;
}

void f2i(void) 
{
    float ft;

    printf("Enter feet: ");
    scanf("%f", &ft);
    printf("%f feet is %f inches\n", ft, ft*12);
    return;
}

void i2f(void)
{
    float in;

    printf("Enter inches: ");
    scanf("%f", &in);
    printf("%f inches is %f feet\n", in, in*0.0833);
    return;

}

