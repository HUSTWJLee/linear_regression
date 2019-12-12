#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double sigmoidFunction(double x)
{
    double ex;
    ex = pow(2.718281828,x);
    return ex/(1+ex);
}

int main(){
    FILE *fp;
    char strline[50]; //读取文件每行的buffer 
    int j = 0,i = 0,k = 0,t = 0;
    float parameter[6][4];
    double theta[4]={2,2,2,2};
    int result[6]={0};
    double h,error,derivate,test = 0;
    if((fp=fopen("D:\\c_tests\\data2.txt","r"))==NULL) //文件位置和文件名 
    {
        printf("file open error");
        return 0;
    }
    while(!feof(fp))  //判断文件是否已到末尾 
    {
        fgets(strline,50,fp);  //读取一行 
        sscanf(strline,"%f %f %f %f %u",&parameter[t][0],&parameter[t][1],&parameter[t][2],&parameter[t][3],&result[t]); 
        t++;
    }
    fclose(fp);
    while(1)
    {
        printf("\n%.3f %.3f %.3f %.3f %u\n",parameter[j][0],parameter[j][1],parameter[j][2],parameter[j][3],result[j]);
        j++;
        if(j>=t)
        {
            break;
        }
    }
    for(i=1;i<10000;i++)
    {
        for(j=0;j<6;j++)
        {
            h=0;
            for(k=0;k<4;k++)
            {
                h += parameter[j][k]*theta[k];
            }
            error = sigmoidFunction(h) - result[j];
            for(k=0;k<4;k++)
            {
                derivate = (-1)*error*parameter[j][k];
                theta[k] += 0.01*derivate;
            }
            printf("%lf %lf %lf %lf\n",theta[0],theta[1],theta[2],theta[3]); 
        } 
    }
    getchar();
    getchar();
    return 0;
}