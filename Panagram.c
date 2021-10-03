/* panagram or not*/
#include<stdio.h>
int main(){
	char str[100];
	int count[26]={0};
	int i,status=0;
	gets(str);
	for(i=0;str[i];i++){
		if(str[i]>=65 && str[i]<=90)
			count[str[i]-'A']++;
		if(str[i]>=97 && str[i]<=122)
			count[str[i]-'a']++;	
	}
	for(i=0;i<=26;i++)
		if(count[i]==0){
			status=1;
			break;
		}
	if(!status)
	printf("Panagram\n");
	else
		printf("Not a panagram\n");
	return 0;
}
