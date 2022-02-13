#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#include<stdbool.h>
#include<ctype.h>

struct registro{
    char apellidoYNombre[60],usuario[10],contrasenia[32],telefono[25];
    bool recepcionista,borrado;
    int idProfesional,dni;
}reg;

void registrarProfesional(FILE *arch,registro reg);
void registrarRecepcionista(FILE *arch,registro reg);

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
		printf("MÃ³dulo AdministraciÃ³n");
		printf("\n=========================");
		printf("\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n4.- Ranking de Profesionales por Atenciones \n\n\n5.- Cerrar la aplicaciÃ³n.\n\nIngrese una opciÃ³n: ");
		scanf("%d",&opcion);
	
		switch(opcion){
			case 1:			
				registrarProfesional(arch,reg);
				break;
			case 2:
			
				registrarRecepcionista(arch,reg);
				break;
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

//profesional
void verificarUsuario(FILE *arch,registro reg);
void verificarContrasenia(FILE *arch,registro reg);

void registrarProfesional(FILE *arch,registro reg){	
	arch=fopen("Profesionales.dat","ab");



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
	reg.recepcionista=false;
	reg.borrado=false;
	// fwrite(&reg,sizeof(registro),1,arch);
	//tal vez convenga colocar un verificar si son correctos los datos ingresados
	system("cls");//posiblemente quitar
	printf("Registro de cuenta profesional");
	printf("\n=========================");
	printf("\nRequisitos:\n1. Ser Ãºnico para cada usuario registrado.\n2. Comenzar con una letra minÃºscula.\n3. Tener al menos 2 letras mayÃºsculas.\n4. Tener como mÃ¡ximo 3 dÃ­gitos.\n5. Un minimo de 6 caracteres y un maximo de 10");

	printf("\nNombre de usuario: ");
	_flushall();
	gets(reg.usuario);

	printf("\ncontraseÃ±a: ");
	_flushall();
	gets(reg.contrasenia);

	fwrite(&reg,sizeof(registro),1,arch);

	fclose(arch);


	// verificarUsuario(arch,reg);




	// //contraseÃ±a
	// system("cls");//posiblemente quitar
	// printf("Registro de contraseÃ±a");
	// printf("\n=========================");
	// printf("\nRequisitos:\n1. DeberÃ¡ contener al menos una letra mayÃºscula, una letra minÃºscula y un nÃºmero.\n2. No podrÃ¡ contener ningÃºn carÃ¡cter de puntuaciÃ³n, ni acentos, ni espacios. SÃ³lo caracteres alfanumÃ©ricos.\n3. DeberÃ¡ tener entre 6 y 32 caracteres.\n4. No debe tener mÃ¡s de 3 caracteres numÃ©ricos consecutivos.\n5. o debe tener 2 caracteres consecutivos que refieran a letras alfabÃ©ticamente consecutivas (ascendentemente). Este criterio es vÃ¡lido tanto para letras mayÃºsculas, minÃºsculas o combinaciÃ³n de ambas.");
	// verificarContrasenia(arch,reg);
}
void verificarUsuario(FILE *arch,registro reg){
	int cantidadLetras,cm=0/*contador letras mayusculas*/,cn=0/*contador de digitos*/,granBandera,b=0/*bandera chica de la condicion de usuarios diferente*/;
	char verificador[10],usuario[10];
	
	// arch=fopen("Profesionales.dat","a+b");
		
	// do{
	// 	granBandera=0;
		printf("\nNombre de usuario: ");
		_flushall();
		gets(usuario);
	// 	cantidadLetras=strlen(usuario);
	// 	for(int i=0;i<cantidadLetras;i++){//contar cantidad de letras
	// 		verificador[i]=usuario[i];
	// 	}
	
	
	// //condicion de cantidad
	// 	if(cantidadLetras>=6&&cantidadLetras<=10){
	// 		//verificar==usuario... la primera letra la paso a minuscula del verificador
	// 		// verificador[0]=tolower(verificador[0]);

			
	// 		// printf("%f",strcmp(verificador,usuario));
	// 		// puts(usuario);
	// 		// puts(verificador);
	// 		// system("pause");


	// 		//comparo ambas y si son iguales, cumple la condicion de la primera letra es minuscula
	// 			if(usuario[0]==tolower(verificador[0])){
	// 				for(int i=0;i<cantidadLetras;i++){//verificador de cantidad de letras mayusculas
	// 					//verificacion por codigo ascii
	// 					if(usuario[i]>=65&&usuario[i]<=90){
	// 						cm++;
						
	// 					//verificacion por codigo ascii
	// 						if(usuario[i]>=48&&usuario[i]<=57){
	// 							cn++;
	// 						}
	// 					}
	// 				}
	// 				//verificador de cantidad letras mayusculas
	// 				if(cm>=2){		
	// 					for(int i=0;i<cantidadLetras;i++){//verificador de cantidad de numeros}
	// 					//cumple condicion de tener menos de 3 digitos
	// 						if(cn<=3){
										
	// 							//verificador de usuarios iguales
	// 							fread(&reg,sizeof(registro),1,arch);		
	// 							while(!feof(arch)&&b==0){
	// 								if(strcmp(usuario,reg.usuario)==0){
	// 								b=1;				
	// 								}
	// 							fread(&reg,sizeof(registro),1,arch);
	// 							}
	// 							if(b==0){//finaliza todo si b es 0 ya que granBandera seguiria siendo 0 por lo que se sale del ciclo.
								// fwrite(&reg.usuario,sizeof(registro),1,arch);
	// 							}
	// 							else{
	// 								printf("\n\n***El usuario ya existe***");
	// 								granBandera=1;
	// 							}
						
	// 						}
	// 						else{
	// 						printf("\nTiene que haber menos de 3 digitos");
	// 						granBandera=1;
	// 						}
	// 					}
					
	// 				}
	// 				else{
	// 					printf("\nTiene que haber dos o mÃ¡s mayusculas");
	// 					granBandera=1;
	// 				}		
	// 			}
	// 			else{
	// 				printf("\nPrimera letra tiene que ser minuscula");
	// 				granBandera=1;
			
	// 			}
	// 	}
	// 	else{
	// 		printf("\nCantidad minima de caracteres es 6 y maxima de 10");
	// 		granBandera=1;
	// 	}
	// }while(granBandera==1);
	
// fclose(arch);
}
void verificarContrasenia(FILE *arch,registro reg){
	int cantidadLetras,cMayusc=0,cMinusc=0,cNum=0,cOtrosCaract=0,granBandera,b=0/*bandera chica de la condicion de usuarios diferente*/;
	char verificador[32],contrasenia[32];
	int codigoAscii[32];
	// arch=fopen("Profesionales.dat","a+b");
	
	// do{
	// 	granBandera=0;
		printf("\ncontraseÃ±a: ");
		_flushall();
		gets(contrasenia);
		// cantidadLetras=strlen(contrasenia);//contar cantidad de letras
		// for(int i=0;i<cantidadLetras;i++){//creo una variable que tenga lo mismo que el original
		// 	verificador[i]=contrasenia[i];
		// }
		// //condicion de cantidad
		// if(cantidadLetras>=6&&cantidadLetras<=32){
		// 	//verificar al menos una mayuscula
		// 	for(int i=0;i<cantidadLetras;i++){
		// 		if(contrasenia[i]>=65&&contrasenia[i]<=90){
		// 			cMayusc++;
		// 		}
		// 		if(contrasenia[i]>=97&&contrasenia[i]<=122){
		// 			cMinusc++;
		// 		}
		// 		if(contrasenia[i]>=48&&contrasenia[i]<=57){
		// 			cNum++;
		// 		}
		// 		else{
		// 			cOtrosCaract++;
		// 		}
		// 	}
		// 	//condiciones de cancelacion
		// 	if(cOtrosCaract!=0 || cMayusc==0 || cMinusc==0 ||cNum==0){
		// 		granBandera++;
		// 		printf("\nRequisitos:\n1. DeberÃ¡ contener al menos una letra mayÃºscula, una letra minÃºscula y un nÃºmero.\n2. No podrÃ¡ contener ningÃºn carÃ¡cter de puntuaciÃ³n, ni acentos, ni espacios. SÃ³lo caracteres alfanumÃ©ricos.\n3. DeberÃ¡ tener entre 6 y 32 caracteres.\n4. No debe tener mÃ¡s de 3 caracteres numÃ©ricos consecutivos.\n5. No debe tener 2 caracteres consecutivos que refieran a letras alfabÃ©ticamente consecutivas (ascendentemente). Este criterio es vÃ¡lido tanto para letras mayÃºsculas, minÃºsculas o combinaciÃ³n de ambas.");
		// 		for(int i=0;i<cantidadLetras;i++){//convierto todo los char en codigos ascii guardando en un int
		// 			verificador[i]=tolower(verificador[i]);
		// 			codigoAscii[i]=verificador[i];
		// 		}
		// 		for(int i=0;i<cantidadLetras-1;i++){//verificador de la ultima condicion. Es menos uno porque son dos numeros seguidos
		// 			if(codigoAscii[i]==codigoAscii[i]-1){
		// 			printf("\n5. No debe tener 2 caracteres consecutivos que refieran a letras alfabÃ©ticamente consecutivas (ascendentemente). Este criterio es vÃ¡lido tanto para letras mayÃºsculas, minÃºsculas o combinaciÃ³n de ambas.");
		// 			i=cantidadLetras;
		// 			}
		// 		}
		// 		for(int i=0;i<cantidadLetras-2;i++){//verificador de la penultima condicion. Es menos dos porque son 3 numeros seguidos		
		// 			if(verificador[i]>=48&&verificador[i]<=57&&verificador[i+1]>=48&&verificador[i+1]<=57&&verificador[i+2]>=48&&verificador[i+2]<=57){
		// 			printf("\n4. No debe tener mÃ¡s de 3 caracteres numÃ©ricos consecutivos.\n5. No debe tener 2 caracteres consecutivos que refieran a letras alfabÃ©ticamente consecutivas (ascendentemente). Este criterio es vÃ¡lido tanto para letras mayÃºsculas, minÃºsculas o combinaciÃ³n de ambas.");
		// 			i=cantidadLetras;
		// 			}
		// 		}				
		// 	}
		// 	else{
				fwrite(&reg,sizeof(registro),1,arch);
	// 		}
	// 	}
	// 	else{
	// 		printf("\nCantidad minima de caracteres es 6 y maxima de 32");
	// 		granBandera=1;	
	// 	}
	// }while(granBandera==1);	
	fclose(arch);
}
//recepcionista
void registrarRecepcionista(FILE *arch,registro reg){
	arch=fopen("Recepcionistas.dat","ab");
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
	reg.recepcionista=true;
	fwrite(&reg,sizeof(registro),1,arch);
	//tal vez convenga colocar un verificar si son correctos los datos ingresados
	system("cls");//posiblemente quitar
	printf("Registro de cuenta recepcionista");
	printf("\n=========================");
	printf("\nRequisitos:\n1. Ser Ãºnico para cada usuario registrado.\n2. Comenzar con una letra minÃºscula.\n3. Tener al menos 2 letras mayÃºsculas.\n4. Tener como mÃ¡ximo 3 dÃ­gitos.\n5. Un minimo de 6 caracteres y un maximo de 10");
	verificarUsuario(arch,reg);
	//contraseÃ±a
	system("cls");//posiblemente quitar
	printf("Registro de contraseÃ±a");
	printf("\n=========================");
	printf("\nRequisitos:\n1. DeberÃ¡ contener al menos una letra mayÃºscula, una letra minÃºscula y un nÃºmero.\n2. No podrÃ¡ contener ningÃºn carÃ¡cter de puntuaciÃ³n, ni acentos, ni espacios. SÃ³lo caracteres alfanumÃ©ricos.\n3. DeberÃ¡ tener entre 6 y 32 caracteres.\n4. No debe tener mÃ¡s de 3 caracteres numÃ©ricos consecutivos.\n5. o debe tener 2 caracteres consecutivos que refieran a letras alfabÃ©ticamente consecutivas (ascendentemente). Este criterio es vÃ¡lido tanto para letras mayÃºsculas, minÃºsculas o combinaciÃ³n de ambas.");
	verificarContrasenia(arch,reg);

	fclose(arch);
}
