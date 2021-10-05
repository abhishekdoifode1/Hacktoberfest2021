#include<stdio.h>
#include<string.h>
void main()
{
    int l1,l2,c=0,i,j,f=0,m;
    char s1[20],s2[10];
    printf("1");
    scanf("%s",&s1);
    printf("2:");
    scanf("%s",&s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=0;i<l1;i++)
    {
        j=0;
        if(s1[i]==s2[j])
        {
            c=0;
            m=i;
            while(s2[j]!='\0')
            {
                if(s1[m]==s2[j])
                {
                    c++;
                    m++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            if(c==l2)
            {
                printf("found at %d",i+1);
                f=1;
                break;
            }
        }
    }
    if(f==0)
    {
        printf("no sub");
        exit(0);
    }

    m=i+l2;
    while(s1[m]!='\0')
    {
        s1[i]=s1[m];
        m++;
        i++;
    }
    s1[l1-l2]='\0';
        printf("\n%s",s1);




}
