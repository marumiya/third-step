#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

double sci[N] = {65.0, 80.0, 67.0, 35.0, 58.0, 60.0, 72.0, 75.0, 68.0, 92.0, 36.0, 50.0, 2.0, 58.5, 46.0, 42.0, 78.0, 62.0, 84.0, 70.0};
double eng[N] = {44.0, 87.0, 100.0, 63.0, 52.0, 60.0, 58.0, 73.0, 55.0, 86.0, 29.0, 56.0, 89.0, 23.0, 65.0, 84.0, 64.0, 27.0, 86.0, 84.0};

/*-----�����-----*/
double sum(int i){
	int j;
	double ans = 0.0;
	for( j = 0; j < N; j++){
		if( i == 0)		//����
			ans += sci[j];
		else			//�Ѹ�
			ans += eng[j];
	}
	return ans;
}


/*-----ʿ����-----*/
double ave(int i){
	return sum(i) / (double)N;
}


/*-----ɸ���к�-----*/
double dev(int i){
	int j;
	double ave = ave(i);

	for(j = 0; j < N; j++){
		if( i == 0)		//����
			ans = ans + pow(sci[j] - ave, 2.0);
		else			//�Ѹ�
			ans = ans + pow(eng[j] - ave, 2.0);
	}
	return sqrt(ans / (double)N);
}

/*-----�к���-----*/
double stasco(int i, int j){
	if( i == 0)		//����
		return 50 * (sci[j] / ave(i));
	else			//�Ѹ�
		return 50 * (eng[j] / ave(i));
}


/*-----������-----*/

//�Х֥륽����
double bubble_sort( int a[], int n){
	int i, j, t;
	for( i = 0; i < n-1; i++){
		for( j = n-1; j > i; j--){
			if( a[j] < a[j-1]){
				t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
			}
		}
	}
	return a;
}

int main(){
	double a[N], b[N];
	int i,j;

	fprintf( stdout, "[����]ʿ���� : %.2lf	ɸ���к� : %.2lf	����� : %.2lf\n, ave(0), dev(0), sum(0));
	fprintf( stdout, "[�Ѹ�]ʿ���� : %.2lf	ɸ���к� : %.2lf	����� : %.2lf\n, ave(1), dev(1), sum(1));

	fprintf( stdout, "\n�к���	[����] | [�Ѹ�]\n");
	for(j = 0; j < N; j++){
		fprintf(stdout, "j����	:	 %.1lf, %.1lf\n", stasco(0,j),stasco(1,j));
	}


	memcpy( a, sci, sizeof(double) * N);
	memcpy( a, bubble_sort( a, N), sizeof(double) * N);

	memcpy( b, sci, sizeof(double) * N);
	memcpy( b, bubble_sort( b, N), sizeof(double) * N);

	for(j = 0; j < N; j++){
		fprintf(stdout, "%lf ", a[j]);
	}
	fprintf(stdout, "\n");

	for(j = 0; j < N; j++){
		fprintf(stdout, "%lf ", b[j]);
	}
	fprintf(stdout, "\n");

	return 0;
}
