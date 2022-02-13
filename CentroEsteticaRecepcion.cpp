#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funciones.h"
#include<locale.h>
#include<wchar.h>
#include<stdbool.h>
#include<ctype.h>
struct fecha{
	int dia,mes,anio;
};

struct cliente{
	char apellidoYNombre[60],telefono[25],domicilio[60],localidad[60];
	fecha fechadeNac;
	float peso;
    bool borrado;
    int dniCliente;
};

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
				if(sesionIniciada!=1 && sesionIniciada != 0){
					printf("\nFallo al iniciar sesión\n\n\n");
					system("pause")
				}
				break;
			case 2:
				if(sesionIniciada==1){				
					Registrar cliente(arch,reg);
					break;
				}
				else{
					printf("\n\n No se ha iniciado sesión ");
					system("pause");
					break;
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

void registrarCliente(FILE *arch){
	arch=fopen("Clientes.dat","ab");
	int opcion;
		do{
		
		system("cls");
		printf("Registrar cliente");
		printf("\n=========================");
		printf("\n\n1)Apellido y Nombre: ");
		_flushall();
		gets(reg.apellidoYNombre);
		printf("\n2)Domicilio: ");
		_flushall();
		gets(reg.domicilio);
		printf("\n3)DNI: ");
		scanf("%d",&reg.dniCliente);
		printf("\n4)LOCALIDAD: ");
		_flushall();
		gets(reg.localidad);
		printf("\ndia de nacimiento: ");
		scanf("%d",&reg.fechadeNac.dia);
		printf("\nmes de nacimiento: ");
		scanf("%d",&reg.fechadeNac.mes);
		printf("\naño de nacimiento: ");
		scanf("%d",&reg.fechadeNac.anio);

		printf("\nLos valores son correcto:\n1)si\n2)no\nopcion: ");
		scanf("%d",&opcion);
			if(opcion!=1 && opcion!=2){
				do{
					//imprimir datos anteriores?
					system("cls");
					printf("\nLos valores son correcto:\n1)si\n2)no\nopcion: ");
					scanf("%d",&opcion);
				}while(opcion!=1 && opcion!=2);
			}
			if(opcion==1){
				fwrite(&reg,sizeof(clientes),1,arch);
			}
			if(opcion==2){
				printf("\nDesea reingresar los datos\n1)si\n2)no\nopcion: ");//si es uno se repite el ciclo y si es dos... no se guarda nada y se sale del ciclo
				do{
					//imprimir datos anteriores?
					system("cls");
					printf("\nDesea reingresar los datos\n1)si\n2)no\nopcion: ");
					scanf("%d",&opcion);
				}while(opcion!=1 && opcion!=2);
			}
		}while(opcion!=2);
	fclose(arch);
}
