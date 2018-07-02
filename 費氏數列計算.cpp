#include <iostream>
#include <stdlib.h>
#include <time.h>
#define f_Buffer 145000
#define f_num 1700
//1152921504606846976
using namespace std;

void f(unsigned long long n);
unsigned long long know_f[f_num][f_Buffer];
void elapsed_time();

int main(){
	for(int i = 0; i < f_num ;i++)
		for(int j = 0; j < f_Buffer ;j++)
			know_f[i][j] = 0;
	long n;
	do{
    	do{
    		system("cls");
    		if(n < 0 || n > f_Buffer)
    			cout << "輸入的值有問題!! " << endl;
    		cout << "請輸入一個數字(此數字n請 n >= 0): ";
    		cin >> n;
    	}while(n < 0 || n > f_Buffer);
    	system("cls");
    	cout << "系統正在以" << endl << endl
    		 << "\t如果 n =0 或 1 答案為 f(n) = 1               來算 並且" << endl
    		 << "\t如果 n >= 2    答案為 f(n) = f(n-1) + f(n-2) 來算 " << endl << endl
    		 << "因為此算法因計算量太過龐大，所以可能需要等上數分鐘。" << endl << endl
    		 << "請稍後..." << endl << endl;
    	long clk = clock()/CLOCKS_PER_SEC; //輸入程式執行到現在的時間 
    	unsigned long long a = n / 10000;
    	for(unsigned long long i = 1; i < a+1; i++){
    		f(i*10000);	
    	}
    	f(a*10000 + n % 10000);
    	cout << endl << "f(" << n <<") 的運算答案為: " ;
    	for(int i = 0; i < f_num ;i++)
    		if(know_f[i][n]!=0)
				cout << know_f[i][n];
		cout << endl << endl <<  "運算時間: " << clock()/CLOCKS_PER_SEC - clk  <<  " 秒" << endl << endl; //輸出答案以及 算法總執行的時間  
		int countttt = 0;
		for(int i = 0; i < f_num ;i++)
    		if(know_f[i][n]!=0)
    			countttt++;
    	cout << "這數字使用 " << countttt << " 位元" << endl << endl;
    	system("pause");
    }while(1);
}

void f(unsigned long long n){
	if(n == 0 || n == 1)
		know_f[f_num - 1][n] = 1;
	else{
        if(know_f[f_num - 1][n] == 0){
            f(n-1);
            f(n-2);
            for(int i = f_num-1 ; i >= 0 ;i--)
        		know_f[i][n] = know_f[i][n-1] + know_f[i][n-2];
	        for(int i = f_num-1 ; i >= 0 ;i--)
		        if(know_f[i][n] >= 1000000000000000000 ){
		        	know_f[i-1][n] += ((know_f[i][n] - (know_f[i][n] % 1000000000000000000))/1000000000000000000);
		        	know_f[i][n] = know_f[i][n] % 1000000000000000000;
		        }
        }
    }
}
