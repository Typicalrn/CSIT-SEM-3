//wap to demostrate false position method
#include<stdio.h>
#include<math.h>

float f(float x){
    return (x*x*x + x*x -3*x -3);
}

int main(){
    float x1,x2,acc=0.001,xm=0,temp;
    int i=1;
    do{
        printf("Enter x1 and x2:");
        scanf("%f %f",&x1,&x2);
    } while (f(x1)*f(x2)>=0);
    
    printf("Iteration |\t x1 \t|\t x2 \t|\t xm \t|\t f(x1) \t|\t f(x2) \t|\t f(xm)|\n");

    do
    {
        temp=xm;
        xm=x1 - f(x1) * (x2 - x1) / (f(x2) - f(x1));
        printf("%d |\t %14.4f |\t %.4f |\t %.4f |\t %.4f |\t %.4f |\t %.4f\n",i++,x1,x2,xm,f(x1),f(x2),f(xm));
        if (f(x1)*f(xm)<0)
        {
            x2=xm;
            // printf("x1=%.4f x2=%.4f f(x1)=%.4f f(x2)=%.4f f(xm)=%.4f\n",x1,x2,f(x1),f(x2),f(xm));
        }
        else
        {
            x1=xm;
            // printf("x1=%.4f x2=%.4f f(x1)=%.4f f(x2)=%.4ff(xm)=%.4f\n",x1,x2,f(x1),f(x2),f(xm));

        }
        
    } while (fabs(temp-xm)>=acc);
    
    printf("The real root is:%.4f\n",xm);

    return 0;
}