
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <ios>
#include <ctime> 
#include <conio.h>

#include "estructuras.h"


using namespace std;
void Imprimir_mapa( string Mapa1 [5][2]);
void Boleto(string name);
void Comprarvuelos(cliente *vcliente,vuelo *vvuelo,string Mapa[5][2],int vuel,int clien);
void Llenar(vuelo* vuelos);
int Menu();

int main()
{
    int const filas = 5, cols = 2;
    int op,i;
    string Mapa1[filas][cols] = { {"01", "02"}, {"10", "12"}, {"21", "22"}, {"31", "32"}, {"41", "42"}};
    string Mapa2[filas][cols] = { {"01", "02"}, {"10", "12"}, {"21", "22"}, {"31", "32"}, {"41", "42"}};
    string Mapa3[filas][cols] = { {"01", "02"}, {"10", "12"}, {"21", "22"}, {"31", "32"}, {"41", "42"}};
    srand(time(0)); 
    cliente* pClientes;
    vuelo* pVuelos;
    pClientes=new cliente[3];
    pVuelos=new vuelo[3];
    Llenar(pVuelos);
    for(i=0;i<3;i++)
    {
        do 
        {
            system("cls");
            cout<<"=================Bienvenido al AEROPUERTO UP=================\n";
            op=Menu();
            switch(op)
            {
                case 1:
                {
                    system("cls");
                    cout<<"Bienvenido a la plataforma de compra de vuelos para el vuelo a ROMA,ITALIA\n"; 
                    Comprarvuelos(pClientes,pVuelos, Mapa1,0,i);
                    system("Pause");
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout<<"Bienvenido a la plataforma de compra de vuelos para el vuelo a TOKYO,JAPON\n\n"; 
                    Comprarvuelos(pClientes,pVuelos,Mapa2,1,i); 
                    system("Pause");
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout<<"Bienvenido a la plataforma de compra de vuelos para el vuelo a PARIS,FRANCIA\n"; 
                    Comprarvuelos(pClientes,pVuelos,Mapa3,2,i);
                    system("Pause");
                    break;
                }
                default:
                {
                    cout << "Ingresa una opcion valida\n";
                    system("Pause");
                    break;
                }
            }
        }while (op<1||op>3); 
    }
}

int Menu()
{
    int op;
    cout<<"1.Roma\n";
    cout<<"2.Tokyo\n";
    cout<<"3.Paris\n";
    cout<<"Eliga una opcion:";
    cin>>op;
    return op;
}

void Comprarvuelos(cliente *vcliente,vuelo *vvuelo,string Mapa[5][2],int vuel,int clien)
{
    int posicionx, pposiciony; 
    int maxb=0; 
    int asientos,l,costo,pago;
     
    if(vvuelo[vuel].cant==0)
    {
        cout<<"NO HAY BOLETOS PARA ESTE VUELO";
    }
    else
    {
        do
        {
            cout<<"BOLETOS DISPONIBLES:"<<vvuelo[vuel].cant<<endl;
            cout<<"Ingrese la cantidad de boletos:\n";
            cin>>asientos;
            if(asientos>vvuelo[vuel].cant)
            {
                cout<<"ELIGA MENOS ASIENTOS\n";
            }
        } while(asientos>vvuelo[vuel].cant);
        vvuelo[vuel].cant=vvuelo[vuel].cant-asientos;

        for(int h = 0; h<asientos; h++)
        {
            system("cls");
            for (size_t i = 0; i < 5; i++) 
            {
                for (size_t j = 0; j < 2; j++)
                 {
                    if (Mapa[i][j]!= "X")
                    {
                        maxb+=1; 
                    }
                    cout << Mapa[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<"Selecciona la posicion en x de tu asiento "<<h+1<<": \n"; 
            cin>>posicionx; 
            cout<<"Seleccion la posicion en y de tu asiento "<<h+1<<": \n"; 
            cin>>pposiciony;
            pposiciony = pposiciony-1;  
            Mapa[posicionx][pposiciony] = "X"; 
        }
       vcliente[clien].total=vvuelo[vuel].costos*asientos;
       vcliente[clien].asientos=asientos;
       vcliente[clien].nombreVuelo=vvuelo[vuel].nombre;
       costo=vvuelo[vuel].costos*asientos;

       do {
            system("cls");
            cout<<"El total a pagar por los asientos es de "<<costo<<" $MXN\n";
            cout<<"Ingrese el total pagado por el cliente\n";
            cin>>pago; 
            if(pago==costo)
            {
             cout<<"Gracias por su compra\n"; 
            }
            if(pago >costo)
            {
                pago = pago-costo;  
                cout<<"Su cambio es de: "<<pago<<" $MXN\n"; 
            }
            else
            {
                cout<<"ERROR, FONDOS INSUFICIENTES\n"; 
            }
        }while(pago<costo); 
    }
}


void Llenar(vuelo* vuelos)
{   
    float costporAsiento[3] = {14000, 25000.34, 12546.98}; 
    string Nombres[3]={"Roma","Tokyo","Paris"},codigosdeVv[3]= {"R7S9L12", "TKYS3L1", "PRS6L10"},horasdeSalidav[3] = {"9:00", "15:00", "18:00"},horasdeLlegadav[3] = {"12:00", "1:00", "22:00"};
    for(int i = 0; i<3; i++)
    {
        vuelos[i].nombre = Nombres[i];
        vuelos[i].codigodeVuelo = codigosdeVv[i];
        vuelos[i].horadeSalida = horasdeSalidav[i]; 
        vuelos[i].horadeLlegada = horasdeLlegadav[i];  
        vuelos[i].costos = costporAsiento[i];
        vuelos[i].cant=10;
    }
}

void Imprimir_mapa(string Mapa1[5][2])
{
    string pausa; 
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 2; j++)
        {
            cout << Mapa1[i][j]<<"\t";
        }
    }
    system("Pause");
}
    

// // void Boleto(string name)
// //{
// //	int numerodec;
// //	string correo;
// //
// //	cout << "Ingresa tu correo electronico";
// //	cin >> correo;
// //
// //	numerodec = 1 + (rand() % 120);
// //	ofstream pasaje("Boleto.txt", ios::app);
// //	if (pasaje.is_open())
// //	{
// //		pasaje << "\t \t Informacion del Vuelo: \n";
// //		pasaje << "Nombre del Pasajero: " << name;
// //		pasaje << "Destino: \n" << "w";
// //		pasaje << "Num vuelo: \n" << "w";
// //		pasaje << "Asiento: \n" << "w";
// //		pasaje << "==========\n";
// //		pasaje << "Numero de Confirmacion.\n" << numerodec;
// //		pasaje << "==========\n";
// //
// //		pasaje.close();
// //		cout << "Llegara al correo " << correo << "la confirmacion del vuelo \n";
// //		cout << "Buen vieje \n";
// //	}
// //	else cout << "Error";
// //}