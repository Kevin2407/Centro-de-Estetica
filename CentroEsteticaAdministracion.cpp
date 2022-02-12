#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funciones.h"
#include<locale.h>
#include<wchar.h>
#include<stdbool.h>
#include<ctype.h>

struct registro {
    char apellidoYNombre[60],usuario[10],contrasenia[10],telefono[25];
    bool recepcionista;
    int idProfesional,dni;
}reg;

void registrarProfesional(FILE *arch,registro reg);

int main(){
	setlocale(LC_ALL, "");
	int opcion;
	FILE *arch;
	//abrir archivos
    arch = fopen("Recepcionistas.dat","ab");
    if (arch == NULL){
			printf("Error al crear el archivo.");
			exit(1);
    }
    arch = fopen("Profesionales.dat","ab");
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
void verificarUsuario(FILE *arch,registro reg);
void registrarProfesional(FILE *arch,registro reg){
	
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
	fwrite(&reg,sizeof(registro),1,arch);
	fclose(arch);
	//tal vez convenga colocar un verificar si son correctos los datos ingresados
	system("cls");//posiblemente quitar
	printf("Registro de cuenta profesional");
	printf("\n=========================");
	printf("\nRequisitos:\n1. Ser único para cada usuario registrado.\n2. Comenzar con una letra minúscula.\n3. Tener al menos 2 letras mayúsculas.\n4. Tener como máximo 3 dígitos.");
	verificarUsuario(arch,reg);
	
}

void verificarUsuario(FILE *arch,registro reg){
	int cantidadLetras,cm=0/*contador letras mayusculas*/,cn=0/*contador de digitos*/,granBandera=0,b=0/*bandera chica de la condicion de usuarios diferente*/;
	char verificador[10],usuario[10];
	
	arch=fopen("Profesionales.dat","a+b");
		
	do{
		printf("\nNombre de usuario: ");
		_flushall();
		gets(usuario);
		cantidadLetras=strlen(usuario);
		for(int i=0;i<cantidadLetras;i++){//contar cantidad de letras
			verificador[i]=usuario[i];
		}
	
	
	//condicion de cantidad
		if(cantidadLetras>=6&&cantidadLetras<=10){
			//verificar==usuario... la primera letra la paso a minuscula del verificador
			verificador[0]=tolower(verificador[0]);
			//comparo ambas y si son iguales, cumple la condicion de la primera letra es minuscula
				if(strcmp(verificador,usuario)==0){
					for(int i=0;i<cantidadLetras;i++){//verificador de cantidad de letras mayusculas
						//verificacion por codigo ascii
						if(usuario[i]>=65&&usuario[i]<=90){
							cm++;
						}
					}
					//verificador de cantidad letras mayusculas
					if(cm>=2){
						for(int i=0;i<cantidadLetras;i++){//verificador de cantidad de numeros
						//verificacion por codigo ascii
							if(usuario[i]>=48&&usuario[i]<=57){
								cn++;
							}
						}
						//cumple condicion de tener menos de 3 digitos
						if(cn<=3){
							//verificador de usuarios iguales
							fread(&reg,sizeof(registro),1,arch);
							
							while(!feof(arch)&&b==0){
								if(strcmp(usuario,reg.usuario)==0){
								b=1;			
								
								/*system("cls");
								printf("\nReingresar nombre de usuario");
								printf("\n=========================");
								printf("\nNombre de usuario: ");
								_flushall();
								gets(apeYNombre);*/			
								}
							fread(&reg,sizeof(registro),1,arch);
							}
							if(b==0){
								fwrite(&reg.usuario,sizeof(registro),1,arch);
							}
							else{
								printf("\n\n***El usuario ya existe***");
								granBandera=1;
							}
						}
						else{
							printf("\nTiene que haber menos de 3 digitos");
							granBandera=1;
						}						
					}
					else{
						printf("\nTiene que haber dos o más mayusculas");
						granBandera=1;
					}
				}
				else{
					printf("\nPrimera letra tiene que ser minuscula");
					granBandera=1;
				}
		}
		else{
			printf("\nCantidad minima de caracteres es 6 y maxima de 10");
			granBandera=1;
		}
	}while(granBandera==0);
}
