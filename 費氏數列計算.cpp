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
    			cout << "��J���Ȧ����D!! " << endl;
    		cout << "�п�J�@�ӼƦr(���Ʀrn�� n >= 0): ";
    		cin >> n;
    	}while(n < 0 || n > f_Buffer);
    	system("cls");
    	cout << "�t�Υ��b�H" << endl << endl
    		 << "\t�p�G n =0 �� 1 ���׬� f(n) = 1               �Ӻ� �åB" << endl
    		 << "\t�p�G n >= 2    ���׬� f(n) = f(n-1) + f(n-2) �Ӻ� " << endl << endl
    		 << "�]������k�]�p��q�ӹL�e�j�A�ҥH�i��ݭn���W�Ƥ����C" << endl << endl
    		 << "�еy��..." << endl << endl;
    	long clk = clock()/CLOCKS_PER_SEC; //��J�{�������{�b���ɶ� 
    	unsigned long long a = n / 10000;
    	for(unsigned long long i = 1; i < a+1; i++){
    		f(i*10000);	
    	}
    	f(a*10000 + n % 10000);
    	cout << endl << "f(" << n <<") ���B�⵪�׬�: " ;
    	for(int i = 0; i < f_num ;i++)
    		if(know_f[i][n]!=0)
				cout << know_f[i][n];
		cout << endl << endl <<  "�B��ɶ�: " << clock()/CLOCKS_PER_SEC - clk  <<  " ��" << endl << endl; //��X���ץH�� ��k�`���檺�ɶ�  
		int countttt = 0;
		for(int i = 0; i < f_num ;i++)
    		if(know_f[i][n]!=0)
    			countttt++;
    	cout << "�o�Ʀr�ϥ� " << countttt << " �줸" << endl << endl;
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
