#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
  char str[100];
  scanf("%s",str);
  int i;
  int *arr = (int*)calloc(26,sizeof(int));
  for(i=0;i<strlen(str);i++){
    arr[str[i]-97]++;
  }
  int max=arr[0],c=0;
  for(i=1;i<26;i++)
  {
    if(arr[i]>max){
      max = arr[i];
      c=i;
    }
  }
  printf("%d %c\n",max,c+97);
}
  return 0;
}
