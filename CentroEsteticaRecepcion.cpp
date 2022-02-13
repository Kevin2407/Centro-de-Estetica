#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funciones.h"
#include<locale.h>
#include<wchar.h>
#include<stdbool.h>
#include<ctype.h>


int iniciarSesion(FILE *arch);
void registrarCliente(FILE *arch);


int main(){
	setlocale(LC_ALL, "");
	int opcion,sesionIniciada=0;
	FILE *arch;	
	do{
		system("cls");
		printf("Módulo del recepcionista");
		printf("\n=========================");
		printf("\n1.- Iniciar Sesión \n2.- Registrar cliente\n3.- registrar Turno\n4.- Listado de Atenciones por Profesional y Fecha    \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
		scanf("%d",&opcion);
	
		switch(opcion){
			case 1:			
				sesionIniciada=Iniciar Sesión(arch);
				break;
			case 2:
				if(sesionIniciada==1){				
					Registrar cliente(arch,reg);
					break;
				}
				else{
					printf("\n\n No se ha iniciado sesión ");
					system("pause");

				}
			case 3:
			//Atenciones por Profesional
			case 4:
			//Ranking de Profesionales por Atenciones
			case 5:
				printf("\n\nEl sistema se esta cerrando...\n");
				system("pause");
				return 0;
			//cerrar
			default:
				printf("\nERROR AL DIGITAR.");
		}
	}while(opcion!=5);
}

int verificarDatos(FILE *arch,char usuario,char contrasenia);
int iniciarSesion(FILE *arch){
	int verificador,opcion,iniciarSesion=0;
	char usuario[20],contrasenia[40];
	do{
	
	system("cls");
	printf("Iniciar Sesión");
	printf("\n=========================");
	printf("\n\n1)Ingresar Usuario: ");
	_flushall();
	gets(usuario);
	printf("\n\n2)Ingresar contraseña: ");
	_flushall();
	gets(contrasenia);
	verificador=verificarDatos(arch,usuario,contrasenia);
		if(verificador==0){
			printf("\n\nContraseña y/o usuario invalidos.\n\nDesea ingresar nuevamente?\n1)si\n2)no\nopcion= ");
			scanf("%d",&opcion);
			if(opcion!=1 && opcion !=2){
				do{
				
				system("cls");
				printf("Error.Desea ingresar nuevamente?\n1)si\n2)no\nopcion= ");
				scanf("%d",&opcion);
				}while(opcion!=1 && opcion !=2);
			}
		}
		else{
			system("cls");
			printf("\n Usuario verificado...Porfavor espere. \n\n")
			system("pause");
			iniciarSesion=1;
		}
	
	}while(opcion==1);
	return iniciarSesion;
}
int verificarDatos(FILE *arch,char usuario,char contrasenia){
	arch=fopen("Recepcionistas.dat","rb");
	int verificarDatos=0;
	  if (arch == NULL){
			printf("Error al abrir archivo.");
			exit(1);
      }
    fread(&reg,sizeof(registro),1,arch);
    while(!feof(arch)){
    	if(strcmp(reg.usuario,usuario)==0 && strcmp(reg.contrasenia,contrasenia)==0){
    		verificarDatos=1;
    		arch=NULL;
    		fclose(arch);
    	}    	
    	fread(&reg,sizeof(registro),1,arch);
    }
    fclose(arch);
    return verificarDatos;
}
