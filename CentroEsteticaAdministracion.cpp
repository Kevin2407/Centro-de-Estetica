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
		printf("Módulo Administración");
		printf("\n=========================");
		printf("\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n4.- Ranking de Profesionales por Atenciones \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
		scanf("%d",&opcion);
		if(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4){
			do{
			
			printf("***ERROR AL DIGITAR\n"),
			system("pause");
			system("cls");
			printf("Módulo Administración");
			printf("\n=========================");
			printf("\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n4.- Ranking de Profesionales por Atenciones \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
			scanf("%d",&opcion);
			}while(opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4);
		}
	}while(opcion!=4);

	return 0;
}
