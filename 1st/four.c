#include <stdio.h>

int main(void){
	int a,b,r,tmp;

	scanf("%d %d",&a,&b);

	if(a<b){
	tmp = a;
	a = b;
	b = tmp;
	}

	r = a%b;

	while(r!=0){
		a = b;
		b = r;
		r = a%b;
	}
		
	printf("%d",b);
}


