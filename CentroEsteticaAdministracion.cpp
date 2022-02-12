#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include<locale.h>
#include <wchar.h>
#include<bool.h>

struct registro {
    char apellidoYNombre[60],usuario[10],contraseña[10],telefono[25];
    bool recepcionista;
    int idProfesional,dni;
}reg;

void registrarProfesional(FILE *arch,registro reg);

int main(){
	setlocale(LC_ALL, "");
	int opcion;
	FILE *arch;
	//abrir archivos
    arch = fopen("Recepcionistas.dat","rb");
    if (arch == NULL){
			printf("Error al crear el archivo.");
			exit(1);
    }
    arch = fopen("Profesionales.dat","rb");
    if (arch == NULL){
			printf("Error al crear el archivo.");
			exit(1);
    }
    fclose(arch);
	//
	
	do{
		system("cls");
		printf("Módulo Administración");
		printf("\n=========================");
		printf("\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n4.- Ranking de Profesionales por Atenciones \n\n\n5.- Cerrar la aplicación.\n\nIngrese una opción: ");
		scanf("%d",&opcion);
	
		switch(opcion){
			case 1:
			//Registrar Profesional
				registrarProfesional(arch,reg);
			case 2:
			//Registrar Usuario Recepcionista
			case 3:
			//Atenciones por Profesional
			case 4:
			//Ranking de Profesionales por Atenciones
			case 5:
				return 0;
			//cerrar
			default:
				printf("\nERROR AL DIGITAR.");
		}
	}while(opcion!=5);
}
void verificarUsuario(FILE *ARCH,char apeYNombre,registro reg.usuario){
	int b;
	arch=fopen("Profesionales.dat","a+b");
	
	
	
	
	
	
	
	
	
	
	
	
	
	fread(&reg,sizeof(registro),1,arch);
	b=0;
	while(!feof(arch)){
		
		if(strcmp(apeYNombre,reg.usuario)==0){
			printf("\n\n***El usuario ya existe***");
			do{
				printf("\nReingresar nombre de usuario");
				printf("\n=========================");
				printf("\nNombre de usuario: ");
				_flushall();
				gets(apeYNombre);
				if(strcmp(apeYNombre,reg.usuario)==0){
					b=1;
				}
				else{
					b=0;
				}
			}while(b=1);
		}
		fread(&reg,sizeof(registro),1,arch);
	}
}

void registrarProfesional(FILE *arch,registro reg){
	char apeYNombre[60];
	arch=fopen("Profesionales.dat","ab");
	system("cls");
	printf("\nRegistro de profesionales");
	printf("\n=========================");
	printf("\nEn este orden. Ingrese el apellido y el nombre: ");
	_flushall();
	gets(reg.apellidoYNombre);
	printf("\nIdentificacion profesional: ");
	scanf("%d",&reg.idProfesional);
	printf("\nDNI: ");
	scanf("%d",&reg.dni);
	printf("\nNumero de telefono: ");
	_flushall();
	gets(reg.telefono);
	fclose(arch);
	//tal vez convenga colocar un verificar si son correctos los datos ingresados
	printf("\n\nRegistro de cuenta profesional");
	printf("\n=========================");
	printf("\nRequisitos:\n1. Ser único para cada usuario registrado.\n2. Comenzar con una letra minúscula.\n3. Tener al menos 2 letras mayúsculas.\n4. Tener como máximo 3 dígitos.");
	printf("\nNombre de usuario: ");
	_flushall();
	gets(apeYNombre);
	verificarUsuario(arch,apeYNombre,reg);
	
}
