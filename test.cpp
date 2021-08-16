/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
#define ull unsigned long long
ull calculateFor(ull a){
	if(a==1) return 1;
	ull moves = 0,prev = 1;
	for(ull i=2;i<=a/2;){
		if(a%i==0 && i%prev == 0){
			moves+=a/i;
			prev = i;
		}
		i+=prev;
	}
	moves += a+1;
	return moves;
}

int main(int argc, char *a[])
{
	//Write code here
	int n;
	
	scanf("%d",&n);
	ull ni[n],moves = 0;
	for(int i=0;i<n;i++){
		scanf("%lld",&ni[i]);
		moves += calculateFor(ni[i]);
	}
	printf("%lld",moves);

	return 0;
}
