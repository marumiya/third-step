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
		else			//±Ñ¸ì
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
	double ave = ave(i);

	for(j = 0; j < N; j++){
		if( i == 0)		//Íý²Ê
			ans = ans + pow(sci[j] - ave, 2.0);
		else			//±Ñ¸ì
			ans = ans + pow(eng[j] - ave, 2.0);
	}
	return sqrt(ans / (double)N);
}


/*-----ÊÐº¹ÃÍ-----*/
double stasco(int i, int j){
	if( i == 0)		//Íý²Ê
		return 50 * (sci[j] / ave(i));
	else			//±Ñ¸ì
		return 50 * (eng[j] / ave(i));
}

int main(){
	
	fprintf( stdout, "[Íý²Ê]Ê¿¶ÑÅÀ : %.2lf	É¸½àÊÐº¹ : %.2lf	¹ç·×ÅÀ : %.2lf\n, ave(0), dev(0), sum(0));
	fprintf( stdout, "[±Ñ¸ì]Ê¿¶ÑÅÀ : %.2lf	É¸½àÊÐº¹ : %.2lf	¹ç·×ÅÀ : %.2lf\n, ave(1), dev(1), sum(1));
	return 0;
}
