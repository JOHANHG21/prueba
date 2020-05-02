#include<cstdlib>
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include <string>

using namespace std;

struct sueteres { 
int tela=1;
int botones=2;
};

struct pantalones { 
int tela=2;
int zipper=1;
};

void ingresar();
void mostrar();

void mp();
void modificar();
void borrar();
int main() { 
  mp();
   return 0; 
   }
   
void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal Fabrica de Confeccion de Sueteres y Pantalones de ninio"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Venta "<<"\n";
		cout<<" 2 - Modificar Venta "<<"\n";
		cout<<" 3 - Borrar Pedido "<<"\n";
		cout<<" 4 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresar();			
		}
		else if (resp==2){		
			system("CLS");
			modificar();
		}
		else if (resp==3){		
			system("CLS");
			borrar();
		}			
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=4);	
}
				   
void ingresar(){
    		remove("temporal.txt");
int codigo;
	sueteres ventasueter;
	int tela,boton,zip,ttela,tboton,tzip;
	int eleccionventa,cantidadproducto;
system("cls");	
cout<<"Ingrese su pedido "<<endl;
cout<<"Sueteres (1), Pantalon (2) "<<endl;
cin>>eleccionventa;
if (eleccionventa==1)
{cout<<"Indique las unidades a pedir"<<endl;
	cin>>cantidadproducto;
	cout<<"Ingrese el codigo de pedido"<<endl;
	cin>>codigo;
	ventasueter.botones*=cantidadproducto;
	ventasueter.tela*=cantidadproducto;
	cout<<ventasueter.tela<<"   "<<ventasueter.botones<<endl;
		ofstream ingresovalores;
	ingresovalores.open("fabrica.txt",ios::app);
	ifstream valoresstock;
	valoresstock.open("existencia.txt",ios::in);
	while (valoresstock>>tela>>boton>>zip)
	{
	    
	    cout<<tela<<boton<<zip<<endl;
		if (ventasueter.botones<boton && ventasueter.tela<tela)
		
		{cout<<"Pedido realizado exitosamente!!"<<endl;
			
	ingresovalores<<codigo<<"\t"<<ventasueter.botones<<"\t"<<ventasueter.tela<<"\t"<<cantidadproducto<<endl;
	tboton=boton-ventasueter.botones;
	ttela=tela-ventasueter.tela;
	ofstream temporal;
	temporal.open("temporal.txt",ios::app);
	temporal<<ttela<<"\t"<<tboton<<"\t"<<zip;
		}
		else
		{
		cout<<"No fue posible completar el pedido, no hay suficiente existencia en bodega"<<endl;
		}
		remove("existencia.txt");
		rename("temporal.txt","stock.txt");
	}	
}
else
{	pantalones ventapantalon;
    cout<<"Ingrese las unidades"<<endl;
	cin>>cantidadproducto;
		cout<<"Ingrese el codigo de pedido"<<endl;
	cin>>codigo;
	ventapantalon.zipper*=cantidadproducto;
	ventapantalon.tela*=cantidadproducto;
		ofstream ingresovalores1;
	ingresovalores1.open("pantalones.txt",ios::app);
	ifstream valoresstock;
	valoresstock.open("existencia.txt",ios::in);
	while (valoresstock>>tela>>boton>>zip)
	{
		if (ventapantalon.zipper<zip && ventapantalon.tela<tela)
		{cout<<"Pedido completado exitosamente!!"<<endl;
			ingresovalores1<<codigo<<"\t"<<ventapantalon.zipper<<"\t"<<ventapantalon.tela<<"\t"<<cantidadproducto<<endl;
	tzip=zip-ventapantalon.zipper;
	ttela=tela-ventapantalon.tela;
	ofstream temporal;
	temporal.open("temporal.txt",ios::app);
	temporal<<ttela<<"\t"<<boton<<"\t"<<tzip;
		}
		else
		{
		cout<<"No fue posible completar el pedido, no hay suficiente existencia en bodega"<<endl;
		}
		remove("existencia.txt");
		rename("temporal.txt","stock.txt");
	}
}
system("pause");
 }
 void mostrar()
 {int t1,t2,t3,t4,t5;
 int t11,t22,t33,t44;
     ifstream muestra1;
     cout<<"Codigo\tBotones\tTela\tCantidad"<<endl;
     muestra1.open("venta.txt",ios::in);
     while(muestra1>>t1>>t2>>t3>>t4)
     {
         cout<<t1<<"\t"<<t2<<"\t"<<t3<<"\t"<<t4<<endl;
         
     }
      ifstream muestra2;
     cout<<"Codigo\tzipper\tTela\tCantidad"<<endl;
     muestra2.open("ventaspaltalon.txt",ios::in);
     while(muestra2>>t11>>t22>>t33>>t44)
     {
         cout<<t11<<"\t"<<t22<<"\t"<<t33<<"\t"<<t44<<endl;
         
     }
 }
     
void modificar(){
    remove("temporal.txt");
    remove("temporal2.txt");
    int valormod,a1,a2,a3,a4,e1,e2,e3,e4,cant,var1,var2,var3,var4;
      mostrar();
      cout<<"Indique el registro que desea modificar"<<endl;
      cin>>valormod;
      ifstream n1;
      ifstream n2;
      ofstream temp;
            ofstream temp1;

      temp.open("temporal.txt",ios::app);
            temp1.open("temporal2.txt",ios::app);

      n1.open("venta.txt",ios::in);
      n2.open("ventaspaltalon.txt",ios::in);
      while(n1>>a1>>a2>>a3>>a4)
      {
          if(valormod==a1)
          {
              cout<<"Seleccione la cantidad que desea modificar "<<endl;
              cin>>cant;
              var1=(a2/a4)*cant;
              var2=(a3/a4)*cant;
              temp<<a1<<"\t"<<var1<<"\t"<<var2<<"\t"<<cant<<endl;
           }
          else
          {
              
          temp<<a1<<"\t"<<a2<<"\t"<<a3<<"\t"<<a4<<endl;
          }
         
          
      }
       while(n2>>e1>>e2>>e3>>e4)
      {
          if(valormod==e1)
          {
              cout<<"Seleccione la cantidad que desea modificar "<<endl;
              cin>>cant;
              var1=(e2/e4)*cant;
              var2=(e3/e4)*cant;
              temp1<<e1<<"\t"<<var1<<"\t"<<var2<<"\t"<<cant<<endl;
           }
          else
          {
              
          temp1<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;
          }
         
          
      }
      
      remove("venta.txt");
      remove("pantalones.txt");
      rename("temporal.txt","venta.txt");
            rename("temporal2.txt","ventaspaltalon.txt");
}
void borrar(){
    remove("temporal.txt");
    remove("temporal2.txt");
    int valormod,a1,a2,a3,a4,e1,e2,e3,e4,cant,var1,var2,var3,var4;
      mostrar();
      cout<<"Seleccione el registro que desea eliminar"<<endl;
      cin>>valormod;
      ifstream n1;
      ifstream n2;
      ofstream temp;
            ofstream temp1;

      temp.open("temporal.txt",ios::app);
            temp1.open("temporal2.txt",ios::app);

      n1.open("venta.txt",ios::in);
      n2.open("pantalones.txt",ios::in);
      while(n1>>a1>>a2>>a3>>a4)
      {
          if(valormod==a1)
          {
              cout<<"Registro eliminado exitosamente!!";
           }
          else
          {
          temp<<a1<<"\t"<<a2<<"\t"<<a3<<"\t"<<a4<<endl;
          }
      }
       while(n2>>e1>>e2>>e3>>e4)
      {
          if(valormod==e1)
          {
                            cout<<"Registro eliminado exitosamente!!";
           }
          else
          {
          temp1<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;
          }
      }
      
      remove("venta.txt");
      remove("pantalones.txt");
      
      rename("temporal.txt","venta.txt");
            rename("temporal2.txt","pantalones.txt");
}
