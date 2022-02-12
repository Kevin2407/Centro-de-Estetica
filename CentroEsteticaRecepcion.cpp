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
		printf("Modulo del recepcionista");
		printf("\n=========================");
		printf("\n1.- Iniciar Sesión\n2.- Registrar Cliente\n3.- Registrar Turno\n4.- Listado de Atenciones por Profesional y Fecha \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
		scanf("%d",&opcion);
		if(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4){
			do{
			
			printf("***ERROR AL DIGITAR\n"),
			system("pause");
			system("cls");
			printf("Modulo del recepcionista");
			printf("\n=========================");
			printf("\n1.- Iniciar Sesión\n2.- Registrar Cliente\n3.- Registrar Turno\n4.- Listado de Atenciones por Profesional y Fecha \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
			scanf("%d",&opcion);
			}while(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4);
		}
	}while(opcion!=4);

	return 0;
}
