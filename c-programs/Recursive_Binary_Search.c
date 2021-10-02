int binarysearch(int a[],int l,int r,int x) 
{ 
    if (r>=l) 
    { 
        int m=l +(r-l)/2; 
        if(a[m]==x)  //if element is present at the middle
            return m;
        else if(a[m]>x)   //if element is smaller than mid,element is present in the left subarray 
            return binarysearch(a,l,m-1,x);
        else   //else, element is present in the left subarray 
        	return binarysearch(a,m+1,r,x); 
    } 
    return -1;   //returns -1 if element is not present
}
int main() 
{ 
   int a[] = {2, 5, 14, 60, 77,80,81,99,101,150};  //array must be sorted
   int n=10;  //size of the array
   int x=14;  //number to be searched
   int ans=binarysearch(a,0,n-1,x); //position of the number is stored in ans
   if(ans==-1)
   {
   		printf("Element is not present in array");
   }
   else 
   {
   		printf("Element is present at the position: %d",ans+1);
   }
   return 0; 
} 