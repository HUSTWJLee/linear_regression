#include<stdio.h>
#include<stdlib.h>

int main() 
{
    FILE *fp;
    char strline[50]; //读取文件每行的buffer 
    int j = 0,i = 0;
    float x[200];
    float y[200];
    float parameter_1 = 0,parameter_2 = 0;
    float sum_x = 0,x_2 = 0;
    float average_x = 0;
    float Molecular = 0;
    float Denominator = 0;
    if((fp=fopen("D:\\c_tests\\data1.txt","r"))==NULL) //文件位置和文件名 
    {
        printf("file open error");
        return 0;
    }
    while(!feof(fp))  //判断文件是否已到末尾 
    {
        fgets(strline,50,fp);  //读取一行 
        sscanf(strline,"%f %f",&x[i],&y[i]); //从文件读取到的一行数据分别存放在两个数组中 
        i++;
    }
    fclose(fp);
    while(1)
    {
        printf("\n%.3f %.3f",x[j],y[j]);
        j++;
        if(j>=i)
        {
            break;
        }
    }
    for(j = 0;j < i;j++){
        sum_x += x[j];
    }
    average_x = sum_x/i;
    for(j = 0;j < i;j++){
        Molecular += y[j]*(x[j]-average_x);
        x_2 += x[j]*x[j]; 
    }
    Denominator = x_2-sum_x*sum_x/i;
    parameter_1 = Molecular/Denominator;
    for(j = 0;j < i;j++){
        parameter_2 += y[j]-parameter_1*x[j];
    }
    parameter_2 = parameter_2/i;
    printf("\ny = %.3f*x + %.3f",parameter_1,parameter_2);
    getchar();
    getchar();
    return 0;
}