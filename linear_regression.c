#include<stdio.h>
#include<stdlib.h>

int main() 
{
    FILE *fp;
    char strline[50]; //读取文件每行的buffer 
    float x[200];
    float y[200];
    int i=0,j=0,h=0;;
    float parameter_1 = 0,parameter_2 = 0;
    float sum_x = 0,sum_y = 0,sum_cost_1 = 0,sum_cost_2 = 0;
    float average_x = 0,average_y = 0;
    float Molecular = 0;
    float Denominator = 0;
    float whatever = 0,whatever_output = 0;
    float alpha;
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
    for(j=0;j<i;j++){
        sum_x += x[j];
        sum_y += y[j];
    }
    average_x = sum_x/i;
    average_y = sum_y/i;
    for(j=0;j<i;j++){
        Molecular += x[j]*y[j]-(j+1)*average_x*average_y; 
    }
    for(j=0;j<i;j++){
        Denominator += x[j]*x[j]-(j+1)*average_x*average_x;
    }
    parameter_1 = Molecular/Denominator;
    parameter_2 = average_y - average_x*parameter_1;
    printf("\n%.3f\n%.3f\n",parameter_1,parameter_2);
    alpha = 0.0005;
    while((parameter_1-10)>=0.001){
        for(j=0;j<i;j++){
            sum_cost_1 += (parameter_1*x[j]+parameter_2-y[j])*x[j];
            sum_cost_2 += (parameter_1*x[j]+parameter_2-y[j]);
        }
        parameter_1 -= alpha*sum_cost_1/i;
        parameter_2 -= alpha*sum_cost_2/i;
        h++;
    }
    printf("\n%.3f\n%.3f\n%d\n",parameter_1,parameter_2,h);
    scanf("%f",&whatever);
    whatever_output = whatever*parameter_1 + parameter_2;
    printf("%.3f",whatever_output);
    getchar();
    getchar();
    return 0;
}