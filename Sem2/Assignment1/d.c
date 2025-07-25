// Program to calculate the distance between co-ordinates of two points and the slope of straight line joining them.

#include<stdio.h>
#include<math.h>
int main()
{
    printf("Enter (x1,y1) : ");
    int x1,y1;
    scanf("%d%d",&x1,&y1);
    printf("Enter (x2,y2) : ");
    int x2,y2;
    scanf("%d%d",&x2,&y2);

    float dist=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    float slope=(float)(y2-y1)/(x2-x1);

    printf("Distance between the coordinates : %.2f\n",dist);
    printf("Slope : %.2f\n",slope);
    return 0;
}