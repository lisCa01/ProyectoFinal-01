//FUNDAMENTOS DE PROGRAMACION 
//proyecto final 
//primero debemos declarar las librerias  , pues que nos serviran para poder realizar el ejercicio

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//estructura ya dada
const int longCad = 20;
struct costoPorArticulo{
    char nombreArticulo[longCad + 1]; 
    int cantidad;
    float precio;
    float costoPorArti;
}; 
//funcion para pedir informacion 
float PedirDatos(int m, costoPorArticulo articulo[]){
    string nombre;
    for (int i = 0; i <m ; i++)//el ciclo for para pedir datos de cuanto producto lleve el usuario
    {
        cout<<"Por favor, Digite el nombre del articulo que va a llevar : ";
        getline(cin,nombre, '\n');
        strncpy(articulo[i].nombreArticulo,nombre.c_str( ),longCad);//strncpy copia los caracteres al origen de destino
        articulo[i].nombreArticulo[longCad]='\0'; 
        
        cout<<"Digite la cantidad de producto: ";
        cin>>articulo[i].cantidad;
        
        cout<<"Digite el precio unitario del articulo: ";
        cin>>articulo[i].precio;
        cout<<"....................................."<<endl;
        cin.ignore(100,'\n');//limite de caracteres
    }
    
}
//funcion costoArticulo
float CostopArticulo(int m, costoPorArticulo articulo[]){
    for (int i = 0; i < m; i++)
    {
        articulo[i].costoPorArti = (articulo[i].cantidad)*(articulo[i].precio);
        // almacena el producto para tener   el costo
    }
}

//funcion para mostrar la informacion 
float MostrarInformacion(int m, costoPorArticulo articulo[]){
    cout<<"------------FACTURA--------sweet wind----"<<endl;
    cout<<"nº factura.. 01"<<endl<<endl;
    cout<<"producto:" <<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<articulo[i].nombreArticulo<<endl;
        cout<<articulo[i].cantidad<<" * "<<articulo[i].precio<<" = "<<articulo[i].costoPorArti<<endl;
    }
    
}
//funcion que da el costo total de la compra
float CostoTotal(int m, costoPorArticulo articulo[]){
    float total;
    for (int i = 0; i < m; i++)
    {
        total = total + articulo[i].costoPorArti;
    }
    return total;
}
//funcion principal, en esta se mandan a llavar todas las demas funciones antes creadas
int main() {
    int m;
//primero le puse nombre al supercito
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<         " SWEET WIND"         <<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<endl;
    
    cout<<"vendedora: Mercy."<<endl<<endl;
    
    cout<<"Digite la cantidad de articulos que va a llevar: ";cin>>m;
    cin.ignore(100,'\n');
    costoPorArticulo Articulo[m];
    PedirDatos(m,Articulo);
    CostopArticulo(m, Articulo);
    MostrarInformacion(m, Articulo);
    cout<<"ESTIMADO CLIENTE, SU TOTAL A PAGAR ES: $"<<CostoTotal(m,Articulo)<<endl<<endl;
    cout<<"*Gracias por su compra, lo esperamos pronto*"<<endl;
    
    return 0;
}
//y asi hemos concluido :)