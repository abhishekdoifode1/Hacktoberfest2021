#include<bits/stdc++.h>
using namespace std;
int main(){
	char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    int M=strlen(pat);
    int N=strlen(txt);
    int i=0,j=0;
    int h=1,d=256,q=101;
    for(i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    int p=0,t=0;
    for(i=0;i<M;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(i=0;i<=N-M;i++){
        if(p==t){
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j])
                	break;
            }
            if(j==M){
                cout<<i<<endl;
        	}        
        }
        if(i<N-M ){
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if(t<0)
            	t=(t+q);
		}
    }
}