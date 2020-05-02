#include <iostream> 

using namespace std;

int main(){	
	cout<<"__________________________________________"<<"\n";
		cout<<" Menu Programa de Arreglos "<<"\n";
		cout<<"______________________________________"<<"\n";
		cout<<" Ingresar Datos al Arreglo "<<"\n"<<endl;
		float arreglo[5];
	int i,n=5;
	for(i=0; i<5; i++){
		cout<<"Ingrese valor No. "<<i+1<<": ";
		cin>>arreglo[i];
	}
	cout<<"\n ____________________________________________"<<"\n";
	cout<<" Imprimir Datos del Arreglo "<<"\n";
	for(int i=0; i<5; i++)
	cout<<"\n ARREGLO #"<<i+1<<": "<<arreglo[i]<<endl<<endl;
}

