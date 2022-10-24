#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vehiculo{

    int anio;
    float precio;
    char color[15];
    char patente[7];

};
struct vehiculo cargarVehiculo();
int validarPatente (char patente[7]);
void cargarvehiculos(struct vehiculo v[], int tam);
void mostrarVehiculo(struct vehiculo v);
void mostrarVehiculos (struct vehiculo v[], int tam);




int main()
{
    int t=2;
    struct vehiculo vehiculos[t];
    cargarvehiculos(vehiculos,t);
    mostrarVehiculos (vehiculos, t);


    return 0;
}

struct vehiculo cargarVehiculo(){
    struct vehiculo v;

    printf("ingrese el anio del vehiculo\n");
    scanf("%d",&v.anio);
    printf("ingrese el valor del vehiculo\n");
    scanf("%f",&v.precio);
    printf("ingrese el color del vehiculo\n");
    fflush(stdin);
    gets(v.color);
    printf("ingrese la patente del vehiculo\n");
    fflush(stdin);
    gets(v.patente);

   while (!validarPatente(v.patente)){
    printf("INGRESO UNA PATENTE QUE NO ES VALIDA\n");
    printf("ingrese nuevamente la patente\n");
    fflush(stdin);
    gets(v.patente);
   }
return v;
};

int validarPatente (char patente[7]){
    int sumaPartes = 0;

    ///PATENTE TIPO LLLNNN

    if (strlen(patente)==6){
        //comprobar letras
        for (int i=0;i<3;i++){
            if (isalpha(patente[i]) !=0 ){
                sumaPartes=sumaPartes+1;
            }
        }//cierra for letras
        //comprobar numeros
        for (int i=3;i<6;i++){
            if (isdigit(patente[i]) != 0){
                sumaPartes=sumaPartes+1;
            }
        }//cierra for numeros

        if (sumaPartes == 6 ){
            sumaPartes=1;
        }else {
            sumaPartes=0;
        }

    }//cierra if strlen = 6


    ///PATENTE TIPO LL NNN XX
    if (strlen(patente)==7){
        // comprobamos LL
        for(int i=0;i<2;i++){
           if(isalpha(patente[i])!=0){
                sumaPartes=sumaPartes+1;
           }
        }//cierra for LL
        //comprobamos parte de numeros
        for (int i=2;i<5;i++){
            if (isdigit(patente[i])!=0){
                sumaPartes=sumaPartes+1;
            }
        }//cierra for parte numeros

        //comprobamos XX
        for(int i=5;i<7;i++){
            if(isalpha(patente[i])!=0){
                sumaPartes=sumaPartes+1;
            }
        }//cierra for XX

        if (sumaPartes == 7 ){
            sumaPartes=1;
        }else {
            sumaPartes=0;
        }
    }//cierra if strlen = 7


    return sumaPartes;

};


void cargarvehiculos(struct vehiculo v[], int tam){

    for (int i=0;i<tam;i++){

        v[i]=cargarVehiculo();
    }

};

void mostrarVehiculo(struct vehiculo v){

    printf(" \n DATOS DEL VEHICULO:\n");
    printf("anio del auto:%d----",v.anio);
    printf("precio del auto:%.2f----",v.precio);
    printf("color del auto:%s----",v.color);
    printf("patente del auto:%s----",v.patente);

};

void mostrarVehiculos (struct vehiculo v[], int tam){

    for (int i=0;i<tam;i++){
        mostrarVehiculo(v[i]);
    }


};










