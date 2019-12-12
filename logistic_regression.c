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
    float parameter[200][4];
    double theta[4]={2,2,2,2};
    char result[200];
    double h,error,derivate,test = 0;
    if((fp=fopen("D:\\c_tests\\data2.txt","r"))==NULL) //文件位置和文件名 
    {
        printf("file open error");
        return 0;
    }
    while(!feof(fp))  //判断文件是否已到末尾 
    {
        fgets(strline,50,fp);  //读取一行 
        sscanf(strline,"%f %f %f %f %c",&parameter[i][0],&parameter[i][1],&parameter[i][2],&parameter[i][3],&result[i]); 
        i++;
    }
    fclose(fp);
    while(1)
    {
        printf("\n%.3f %.3f %.3f %.3f %c\n",parameter[j][0],parameter[j][1],parameter[j][2],parameter[j][3],result[j]);
        j++;
        if(j>=i)
        {
            break;
        }
    }
    test = sigmoidFunction(1888);
    for(k = 0;k < 1000;k++){
        for(j = 0;j < i;j++){
            h = 0;
            for(t = 0;t < 4;t++){
                h += parameter[j][t]*theta[t];
            }
            error = sigmoidFunction(h) - result[j];
            for(t = 0;t <4;t++){
                derivate = (-1)*error*parameter[j][t];
                theta[t] += derivate*0.05;
            }
        }
        printf("%f %f %f %f\n",theta[0],theta[1],theta[2],theta[3]);
    }
    getchar();
    getchar();
    return 0;
}