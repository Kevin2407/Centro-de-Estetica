#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

struct registro {
    char apellidoYNombre[60],usuario[10],contraseña[10],telefono[25];
    bool recepcionista;
    int idProfesional,dni;
}reg;

void menuEspacios(int &op);
void iniciarSesion(FILE *arch, bool &bs, bool recOprof);




void menuEspacios(int &op)
{
    system("cls");

    printf("\n\n--- Módulo Espacios ---\n");
    printf("1- Iniciar Sesión\n");
    printf("2- Visualizar Lista de Espera de Turnos (informe)\n");
    printf("3- Registrar Evolución del tratamiento\n");
    printf("0- Cerrar la aplicacion\n");
    printf("---> ");

    scanf("%d",&op);
}




void iniciarSesion(FILE *arch, bool &bs, bool recOprof) 
{
    // el boolean bs (bandera sesion) indica si la sesion esta abierta o cerrada, si es true, permite al usuario acceder a las demas funciones
    // el boolean recOprof (recepcionista o profesional) indica si la sesion a iniciar es de un recepcionista o de un profesional (true- recepcionista, false- profesional)

    bool val = false; // el boolean val (validado) se pone en true si se el usuario y contraseña coinciden con algun usuario y contraseña del archivo
    int op; // el usuario ingresa esta variable para que el programa sepa si quiere cerrar una sesion ya iniciada o no
    char nomUsuario[10],contra[10];
    registro prof; 

    if (!bs)  // es decir, si no hay una sesion iniciada
    {
        printf("Ingrese nombre de usuario: ");
        flushall();
        gets(nomUsuario);
        printf("Ingrese la contraseña: ");
        flushall();
        gets(contra);


        if (recOprof)
        {
            arch=fopen("Recepcionistas.dat","rb");
            if (arch == NULL){
			    printf("Error. No hay archivo de cuentas.\nCree el archivo e intente ingresar nuevamente");
                system("pause");
                fclose(arch);
                exit(1);
            }
        }else
        {
            arch=fopen("Profesionales.dat","rb");
            if (arch == NULL){
			    printf("Error. No hay archivo de cuentas.\nCree el archivo e intente ingresar nuevamente");
                system("pause");
                fclose(arch);
                exit(1);
            }
        }
        

        fread(&prof,sizeof(registro),1,arch);

        while(!feof(arch)) 
        {
            if ( strcmp(nomUsuario,prof.usuario) == 0  && strcmp(contra,prof.contraseña) == 0) // si el nombre de usuario y contraseña coinciden, se valida
            {
                val=true;
            }
            fread(&prof,sizeof(registro),1,arch);
        }

        if (val)
        {
            printf("Sesion iniciada\n");
            bs=true;
            system("pause");
            system("cls");
        }else
        {
            printf("El usuario o contraseña no son correctos\n");
            system("pause");
            system("cls");
        }
        fclose(arch);
    }else
    {
            printf("Ya hay una sesion iniciada\nDesea cerrar sesion?\n1 --> SI\n2 --> NO\n---> ");
            scanf("%d",&op);
            while (op!=0 || op!=1)
            {
                printf("***ERROR AL DIGITAR\n");
                system("pause");
                system("cls");
                printf("Desea cerrar sesion?\n1 --> SI\n2 --> NO\n---> ");
                scanf("%d",&op);
            }

            if (op==1)
            {
                bs=false;
                printf("Se ha cerrado sesion\n");
                system("pause");
                system("cls");
            }else
            {
                printf("No se ha cerrado sesion\n");
                system("pause");
                system("cls");
            }
    }

}











// MODELO MENÚ

// void menu(int &op)
// {
//     system("cls");

//     printf("\n\n--- Menu ---\n");
//     printf("1- texto\n");
//     printf("2- texto\n");
//     printf("3- texto\n");
//     printf("4- texto\n");
//     printf("5- texto\n");
//     printf("6- texto\n");
//     printf("7- texto\n");
//     printf("8- texto\n");
//     printf("9- texto\n");
//     printf("10- texto\n");
//     printf("0- texto\n");
//     printf("---> ");

//     scanf("%d",&op);
// }