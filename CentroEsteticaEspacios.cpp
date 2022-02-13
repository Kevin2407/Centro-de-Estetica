#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include<locale.h>
#include <wchar.h>


struct registro {
    char apellidoYNombre[60],usuario[10],contraseña[10],telefono[25];
    bool recepcionista;
    int idProfesional,dni;
}reg;


int main(){
	setlocale(LC_ALL, "");
	int op;
	bool bs = false; // bs (bandera sesion) indica si la sesion esta abierta o cerrada, si es true, permite al usuario acceder a las demas funciones
	FILE *arch;

	//abrir archivos
    arch = fopen("Profesionales.dat","rb");
    if (arch == NULL){
			printf("Error al crear el archivo.");
			exit(1);
    }
    fclose(arch);



	menuEspacios(op);

    do
    {
        switch (op)
        {
        case 1:
            iniciarSesion(arch,bs,false);
            menuEspacios(op);
            break;

        case 2:
            // verTurnos(arch);
            menuEspacios(op);
            break;

        case 3:
            // registrarPaciente(arch);
            menuEspacios(op);
            break;

        case 0:
			system("cls");
			printf("Gracias por usar nuestros servicios");
			exit(1);
            break;

        default:
            system("cls");
            printf("***ERROR AL DIGITAR\n");
            system("pause");
            menuEspacios(op);
            break;
        }
    } while (op!=0);



	return 0;
}
