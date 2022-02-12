#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include<locale.h>
#include <wchar.h>

int main(){
	setlocale(LC_ALL, "");
	int opcion;
	do{
		system("cls");
		printf("Modulo Espacios");
		printf("\n=========================");
		printf("\n1.- Iniciar Sesión\n2.- Visualizar Lista de Espera de Turnos (informe)\n3.- Registrar Evolucion del tratamiento\n\n4.-Cerrar la aplicacion \n\nIngrese una opción: ");
		scanf("%d",&opcion);
		if(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4){
			do{
			
			printf("***ERROR AL DIGITAR\n"),
			system("pause");
			system("cls");
			printf("\nModulo Espacios");
			printf("\n=========================");
			printf("\n1.- Iniciar Sesión\n2.- Visualizar Lista de Espera de Turnos (informe)\n3.- Registrar Evolucion del tratamiento\n\n\n4.-Cerrar la aplicacion \n\nIngrese una opción: ");
			scanf("%d",&opcion);
			}while(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4);
		}
	}while(opcion!=4);

	return 0;
}
