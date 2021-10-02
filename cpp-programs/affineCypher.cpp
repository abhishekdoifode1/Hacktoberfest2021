#include<iostream>
#include<string>
using namespace std;
string encrypt(string m,int k1,int k2) {
	for (int i = 0; i < m.length(); i++) {
		if(m[i]!=' ')
			m[i] =(char)(((k1 * (m[i]-'A')  + k2) % 26) + 'A');
	}
	return m;
}
string decrypt(string c,int k1,int k2) {
	int inverse = 0;
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		flag = (k1 * i) % 26;
		if (flag == 1)
			inverse = i;
	}
	for (int i = 0; i < c.length(); i++) {
		if(c[i] != ' ')
			c[i] =(char)((inverse * (c[i]-'A'- k2) % 26) + 'A');
	}
	return c;
}
int main(void) {
	string text;
	int k1,k2;
	cout<<"-----AFFINE CIPHER-----";
	cout<<"\nEnter string to encrypt:";
	cin>>text;
	//k1:first key should have have multiplicative inverse.
	cout<<"Enter keys:";
	cin>>k1>>k2;
	string encrypted_text=encrypt(text,k1,k2);
	cout<<"Encrypted Text:"<<encrypted_text;
	cout<<"\nKeys:"<<k1<<' '<<k2;
	cout<<"\nDecrypted Text:"<<decrypt(encrypted_text,k1,k2);
	return 0;
}
