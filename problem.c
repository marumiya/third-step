#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

double sci[N] = {65.0, 80.0, 67.0, 35.0, 58.0, 60.0, 72.0, 75.0, 68.0, 92.0, 36.0, 50.0, 2.0, 58.5, 46.0, 42.0, 78.0, 62.0, 84.0, 70.0};
double eng[N] = {44.0, 87.0, 100.0, 63.0, 52.0, 60.0, 58.0, 73.0, 55.0, 86.0, 29.0, 56.0, 89.0, 23.0, 65.0, 84.0, 64.0, 27.0, 86.0, 84.0};

/*-----¹ç·×ÅÀ-----*/
double sum(int i){
	int j;
	double ans = 0.0;
	for( j = 0; j < N; j++){
		if( i == 0)		//Íý²Ê
			ans += sci[j];
		else			//±Ñ¸
			ans += eng[j];
	}
	return ans;
}


/*-----Ê¿¶ÑÅÀ-----*/
double ave(int i){
	return sum(i) / (double)N;
}


/*-----É¸½àÊÐº¹-----*/
double dev(int i){
	int j;
	double ans = 0.0;

	for(j = 0; j < N; j++){
		if( i == 0)		//Íý²Ê
			ans = ans + pow(sci[j] - ave(i), 2.0);
		else			//±Ñ¸
			ans = ans + pow(eng[j] - ave(i), 2.0);
	}
	return sqrt(ans / (double)N);
}

/*-----ÊÐº¹ÃÍ-----*/
double stasco(int i, int j){
	if( i == 0)		//Íý²Ê
		return 50 * (sci[j] / ave(i));
	else			//±Ñ¸
		return 50 * (eng[j] / ave(i));
}


/*-----¥½¡¼¥È-----*/

//¥Ð¥Ö¥E½¡¼¥È
void bubble_sort( double* a, int n){
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
	for (j = 0; j < N; j++) {
		fprintf(stdout, "%4.1lf ", a[j]);
	}
	fprintf(stdout, "\n");
}

int main(){
	double a[N], b[N];
	int i,j;

	fprintf( stdout, "[—‰È]•½‹Ï“_ :	%.2lf	•W€•Î· : %.2lf	‡Œv : %.2lf\n", ave(0), dev(0), sum(0));
	fprintf( stdout, "[‰pŒê]•½‹Ï“_ :	%.2lf	•W€•Î· : %.2lf	‡Œv : %.2lf\n", ave(1), dev(1), sum(1));

	fprintf( stdout, "\n•Î·’l		[—‰È] | [‰pŒê]\n");
	for(j = 0; j < N; j++){
		fprintf(stdout, "%dl–Ú	:	%4.1lf    %4.1lf\n", j+1, stasco(0,j),stasco(1,j));
	}

	fprintf(stdout, "•À‚Ñ‘Ö‚¦\n");

	memcpy( a, sci, sizeof(double) * N);
	bubble_sort(a, N);

	memcpy( b, eng, sizeof(double) * N);
	bubble_sort(b, N);

	return 0;
}
