#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 1000
char res[MAXSIZE+1];
char a[MAXSIZE],b[MAXSIZE];

void init(char *array){//初始化字符数组； 
     for(int i=0;i<MAXSIZE;i++){
         array[i]='0';//全部置零；    
     }
}

void recover(char *string)
{
    int length=strlen(string);
    char tmp;
    for(int i=0;i<length/2;i++)
    {
        tmp=string[i];
        string[i]=string[length-i-1];
        string[length-i-1]=tmp;
    }
}

char *LongNumAdd(char *num1, char *num2)
{    char *result,*big,*small;
     int l_num1=strlen(num1);
     int l_num2=strlen(num2);
     int bigger, smaller;
     if(l_num1 >= l_num2)
     {
         bigger=l_num1;
         smaller=l_num2;
         big=num1;
         small=num2;
     }
     else
     {
         bigger=l_num2;
         smaller=l_num1;
         big=num2;
         small=num1;
     }
     int tmp, tmp_gewei, tmp_jinwei = 0, num = 0;
     result = (char *)malloc(sizeof(char) * (bigger + 1));
     for(int i = smaller - 1, j = bigger - 1; i >= 0 && j >= 0; i--, j--)
     {
             tmp = big[j]+small[i]-'0'+tmp_jinwei;
             tmp_gewei = tmp % 10;
             tmp_jinwei = tmp / 10;
             result[num++] = tmp_gewei + '0';
     }
     for(int i = bigger - smaller - 1; i >= 0; i--)
     {
             tmp = big[i]-'0'+tmp_jinwei;
             tmp_gewei = tmp % 10;
             tmp_jinwei = tmp / 10;
             result[num++] = tmp_gewei + '0';
     }
     if(tmp_jinwei > 0)
     {
             result[num] = tmp_jinwei + '0';
     }
     else
     {
             result[num] = 0;
     }
     recover(result);
     return result;
}
int main(){
    init(a);
    init(b);
    printf("请输入两个大数：\n");
    scanf("%s %s",a,b);
    char *res=LongNumAdd(a,b);
    printf("%s\n", res);
    printf("\n");
}

