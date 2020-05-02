/*
El Instituto Nacional de Arqueolog�a almacena informaci�n sobre el numero de visitantes a los diferentes centros arqueol�gicos, 58, 
en forma mensual durante los �ltimos 10 a�os, la informaci�n se registra en un arreglo tipo estructura. 
Para lo cual se le solicita que el programa muestre la siguiente informaci�n:
"	�En qu� a�o el centro arqueol�gico n�mero 43, obtuvo la mayor cantidad de visitantes?
"	�Cu�l fue el centro arqueol�gico que en el 2004 recibi� la mayor afluencia de visitantes?
"	�En qu� mes del a�o 2019, los centros recibieron mayor n�mero de visitantes?
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;

struct datos {
	int centro;
	int anio;
	int mes;
	int visitantes;
	int arreglo[2];
	//int v_anio[10];//Arreglo
	//int v_meses[12];//Arreglo
	//int visitantes;
};
//Llamo a las funciones con las que trabajar�
void mp();
void leer_datos();
void insertar_datos();
//Dentro del programa mando a llamar al Men� Principal
int main(){
	mp();
}
//Creo mi funci�n del Men� Principal
void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal Instituto Nacional de Arqueologia"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Datos "<<"\n";
		cout<<" 2 - Mostrar Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insertar_datos();			
		}
		else if (resp==2){		
			system("CLS");
			leer_datos();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void insertar_datos(){
	int centro,anio,mes,visitantes;
	string s;
	datos arreglo[58];//centros[58] para almacenar mas de 1 centro
	int v_meses[12];//Arreglo
	int v_anio[10];//Arreglo
	//Con ciclo for para almacenar un arreglo CICLO PARA INGRESAR DATOS
	int i,j=0,k=0;
	int n=57,m=9,o=11;
	for(i=0; i<=n; i++){
		fflush(stdin);//Limpiar el ciclo
	cout<<"__________CENTROS ARQUEOLOGICOS (1-58)_____________"<<endl;
	cout<<"\n Centro Arqueologico No. : ";
	cin>>centro;
	//CICLO PARA INGRESAR LOS A�OS EN EL ARREGLO
	for(j=0; j<=m;j++){
	cout<<"\n________ULTIMOS 10 ANIOS (2009-2019)________________"<<endl;
	cout<<"\n Anio: ";
	cin>>anio;
	//CICLO PARA INGRESAR LOS VISITANTES POR MES EN EL ARREGLO
	for(k=0; k<=o;k++){
	cout<<"\n ________________MESES (1-12)____________________"<<endl; 
	cout<<"\n Mes: ";
	cin>>mes;
	cout<<"\n Numero de visitantes: ";
	cin>>visitantes;
	ofstream grabar;
	try{
		grabar.open("visitante.txt",ios::app);
		grabar<<centro<<"\t"<<anio<<"\t"<<mes<<"\t"<<visitantes<<"\t"<<endl;
		grabar.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	}

	
}
}
}
void leer_datos(){
	//declaracion de variables
	int centro,anio,mes,visitantes,i,mayoranio,mayorcentro,mayormes;	
	string linea;
	int t_visitantes=0;
	int mayorvisitantes = -1;
	
	ifstream db;	
	try{
		db.open("visitante.txt",ios::in);	

		cout << "---------------------------------------------" << endl;
		cout << "Centro"<< "\t" << "ANIO" << "\t" << "MES"<<"\t"<< "VISITANTES" << endl;
		cout << "---------------------------------------------" << endl; 	
		while (db>>centro>>anio>>mes>>visitantes){
			cout<<centro<<"\t"<<anio<<"\t"<<mes<<"\t"<<visitantes<<endl;
			i++;					
//			system("Pause");
			if(centro==43){
			if (visitantes>mayorvisitantes){
				mayorvisitantes=visitantes;
				mayoranio =anio;
			}
		}
		if(anio==2014){//El programa decia 2004 pero como son los �ltimos 10 a�os le puse 2014
			if (visitantes>mayorvisitantes){
				mayorvisitantes=visitantes;
				mayorcentro =centro;
			}
		}
		if(anio==2019){
			if (visitantes>mayorvisitantes){
				mayorvisitantes=visitantes;
				mayormes =mes;
				t_visitantes+=visitantes;
			}
		}
		}	
		db.close();	
		
		cout << "___________________________________________________________________________________________________________"<<endl;
		cout<<"\nAnio con la mayor cantidad de visitantes del Centro No. 43: "<<mayoranio<<" - Visitantes: "<<mayorvisitantes<<endl<<endl;
		cout << "___________________________________________________________________________________________________________"<<endl;
		cout<<"\nCentro con la mayor cantidad de visitantes del Anio 2014: "<<mayorcentro<<" - Visitantes: "<<mayorvisitantes<<endl<<endl;
		cout << "___________________________________________________________________________________________________________"<<endl;
		cout<<"\nMes del Anio 2019 en que los centros recibieron mas visitantes: "<<mayormes<<endl;
		cout << "___________________________________________________________________________________________________________"<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
