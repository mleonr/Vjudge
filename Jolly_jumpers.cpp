#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
#include<stdlib.h>

using namespace std;

int main(){
	
	int i = 0, j = 0, k = 0, absoluto = 0, tam_cadena = 0;
	string cad_entrada;
	string s_cad="",s_aux="";
	
	bool ban = false;
	
	vector<int>vec_cad;
	vector<int>vec_aux;
	
	while(getline(cin,cad_entrada)){
	
		for(i=0;i<cad_entrada.length();i++){
			
			if(cad_entrada[i]!=' '){
				
				s_cad = cad_entrada[i];
				s_aux = s_aux+s_cad;

				if(cad_entrada.length()==1 || i == (cad_entrada.length()-1)){
					vec_cad.push_back(stoi(s_aux));
					s_aux="";	 
				}
			}else{
				vec_cad.push_back(stoi(s_aux));
				s_aux="";
			}
		}
		
		if(vec_cad.size()>2){
			
			for(j=1;j<(vec_cad.size()-1);j++){
				
				absoluto = abs(vec_cad[j]-vec_cad[j+1]);
				vec_aux.push_back(absoluto);
			}
			
			sort(vec_aux.begin(),vec_aux.end());
			
			for(k=0;k<(vec_cad.at(0)-1);k++){
					
				if(vec_aux[k]!=k+1){
					ban=true;
				}
			}		
			
			if(ban==true){
				cout<<"Not jolly"<<"\n";
			}else{
				cout<<"Jolly"<<"\n";
			}
		
		}else{
			if(vec_cad.at(0)!=0){
				cout<<"Jolly"<<"\n";
			}
		}
		
		vec_cad.clear();
		vec_aux.clear();
		ban = false;
	}
}
	