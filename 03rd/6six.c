#include <stdio.h>
#include <string.h>

int add_number = 0;
int mult_number = 0;

struct golden{
	long long int a;
	long long int b;
};

// struct golden double_golden(struct golden x){
// 	struct golden y;
// 	y.a = x.a * 2;
// 	y.b = x.b * 2;	
// 	return y; 
// }

// struct golden add_golden(struct golden x, struct golden y){
// 	struct golden z;
// 	z.a = x.a + y.a;
// 	z.b = x.b + y.b;
// 	return z;
// }

struct golden mult_golden(struct golden x, struct golden y){
	struct golden z;
	z.a = x.a * y.a + x.b * y.b;
	z.b = x.a * y.b + y.a * x.b + x.b * y.b;
	add_number += 3;
	mult_number += 5;
	return z;
}

struct golden power_golden(struct golden x,int n){
	struct golden z;
	if(n == 0){
		z.a = 1;
		z.b = 0;
	}else if(n%2 == 1){
		z = mult_golden(x,power_golden(x,n-1));
	}else if(n%2 == 0){
		struct golden y;
		y = power_golden(x,n/2);
		z = mult_golden(y,y);

	}
	return z;
}

int main(){
	int n;
	struct golden n_minus_one;
	struct golden x;
	scanf("%d",&n);
	
	x.a = 1;
	x.b = -1;

	n_minus_one = power_golden(x,n-1);

	printf("%lld\n",n_minus_one.a);
	printf("%d\n",add_number);
	printf("%d\n",mult_number);
	return 0;
}
