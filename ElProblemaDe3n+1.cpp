#include<iostream>
#include<fstream>
using namespace std;

unsigned long long int calcular(long valor);

int main(){
	
	ofstream file ("ElProblemaDe3n+1[cache].txt", ios::out);
	for(long int i = 1;i<=999999;i++)
		file << calcular(i) << "\r\n";
	file.close();
}

unsigned long long int calcular(long valor){
	unsigned long long int total = 0;
	while(valor != 1){
		if(valor % 2 == 0){
			valor = valor / 2;
		}
		else{
			valor = valor * 3 + 1;
		}
		
		if(valor/2 ==1) total++;

		total++;
	}
	
	return total;
}
