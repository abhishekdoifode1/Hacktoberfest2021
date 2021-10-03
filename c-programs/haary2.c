#include<reg51.h>
void main()
{ 
	unsigned char xdata *ptr=0x4000;
  unsigned long s=0,n,i;
	n=*ptr;
	ptr++;
	for(i=0;i<n;i++)
	{
		s=s+*ptr;
		ptr++;
	}
	ptr=0x401a;
	*ptr=s/256;
	*(++ptr)=s;
}
