/*------------------------------------------------------------- 
Menú de gestión de empresas por Keux00
---------------------------------------------------------------*/

// Incluímos las librerias que consideremos necesarias

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Definimos las variables

int i;
int n=0;
int opc;
int pos;
int h=0;
int continuar='Y';
int numident;
int empleados_registrados=0;

// Hacemos y preparamos las estructuras y sus datos correspondientes

struct proyecto
{
char nombreproyecto[60];
int presupuestoproyecto;
};

struct empleado
{
char nombre[50];
char apellido[50];
int numidentif;
int edad;
int anyo;
struct proyecto proyecto_empleado[10];
int eliminar;
}lista[500];

// Función para revisar errores (nos servirá próximamente)

int error(){
	
	int j;
	char reg;
	for (j=0; j<n; j++){
		if(lista[j].eliminar == 1){
			printf("\n Este empleado ya habia sid registrado, desea volver a registrarlo (Y/N): ");
			reg=getch();
			reg=toupper(reg);
			if(reg=='Y'){
				printf("\n Empleado registrado de nuevo!");
				lista[j].eliminar=0;
				empleados_registrados++;
				j=n;
			}
		}
		else{
			printf("\n Empleado registrado");
			j=n;
		}
	}
	system("PAUSE");
	menu();
}

// Función para recoger los datos del empleado

int pedir_datos(){

	int a;
	do {

		printf("\n INTRODUZCA LOS DATOS DEL CLIENTE \n");
		
		printf("\n Nombre: "); scanf("%s",&lista[i].nombre);
		printf("\n Apellido: "); scanf("%s",&lista[i].apellido);
		printf("\n Num. identif: "); scanf("%d",&lista[i].numidentif);
		//---------------------------REVISAR QUE NO EXISTA--------------------------
		for (a=0; a<n; a++){
			if(lista[i].numidentif == lista[a].numidentif){
				error();
				a=n;
				return 0;
			}
		}
		//---------------------------------------------------------------------------
		printf("\n Edad: "); scanf("%d",&lista[i].edad);
		printf("\nA%co de nacimiento del empleado: "); scanf("%d",&lista[i].anyo)
		printf("\nN%cmero de proyectos en los que trabaja: "); scanf("%d",&lista[i].proyectos)
		lista[i].eliminar=0;
		n++;
		i++;
		empleados_registrados++;
		printf("\n Desea continuar(Y/N): ");
		continuar=getch();
	}while(toupper(continuar)!='N');
}

// Función para mostrar los datos del empleado

void mostrar_datos(){
	
	while (j<DIM){
		
		if(lista[j].numidentif!=0){
		
		printf("\n");
		printf("\nDatos del empleado: %i",j+1);
		printf("\n-----------------------------------");
		printf("\nN%cmero indentificativo: %i",163,lista[j].numidentif);
		printf("\nNombre del empleado: %s",lista[j].nombre);
		printf("\nApellido del empleado: %s",lista[j].apellido);
		printf("\nEdad del empleado: %i",lista[j].edad);
		printf("\nA%co de nacimiento del empleado: %i",164,lista[j].anyo);
		printf("\nN%cmero de proyectos en los que trabaja: %i",163,lista[j].proyectos);
		printf("\n");
		}
		
		else
		{
			break;
		}
	}
	
	printf("\n");
}

// Función para eliminar empleados

void eliminar_empleado(){
	
	printf("\n Eliminar registro \n");
	
	if(empleados_registrados==0) printf("\n No se ha registrado ningun empleado");
	else{
		printf ("\nIngrese el num. identif del empleado a eliminar: ");
		scanf("%d",&numident);
	for (i=0; i<n;i++){
		if(numident == lista[i].numidentif && lista[i].eliminar==0){
			pos=i;i=n;
		}
		else pos=-1;
	}
	if (pos!=-1){
		printf("\n Nombre: %s", lista[pos].nombre);
		printf("\n Apellido: %s", lista[pos].apellido);
		printf("\n Num. identif: %d", lista[pos].numidentif);
		printf("\n Edad: %d", lista[pos].edad);
		printf("\nA%co de nacimiento del empleado: %i",164,lista[pos].anyo);
		printf("\n Desea Eliminar Registro (Y/N): ");
		scanf("%s",&opc);
		if (toupper(opc)=='Y'){
			lista[pos].eliminar=1;
			printf("\n Registro eliminado...");
			empleados_registrados--;
		}
		else
		printf("\n Nigun registro eliminado...");
	}
	else
	printf("\n Registro no existe");
	}
	getch();
}

int modificar_datos(){
	
	int modificar (){
	
	bool empleado_no_registrado=false;
	int a;

	printf("\n Modificar datos del empleado ");
	
	if(empleados_registrados==0)
		printf("\n No se ha registrado ningun empleado");
	else{
		printf ("\n Introduzca el num. identif del empleado a modificar: ");
		scanf("%d",&numident);
		for (i=0; i<n;i++){
			if(numident == empleado[i].numidentif){

				printf("\n Modificar los datos del empleado");
				printf("\n Nombre: %s", lista[i].nombre);
				printf("\n Apellido: %s", lista[i].apellido);
				printf("\n Num. identif: %d", lista[i].numidentif);
				printf("\n Edad: %d", lista[i].edad);
				printf("\nA%co de nacimiento del empleado: %i",164,lista[i].anyo);
				
				printf("\n Datos a modificar:");
				printf("\n Nombre: ");
				scanf("%s",&lista[400].nombre);
				printf("\n Apellido: ");
				scanf("%s",&lista[400].apellido);
				printf("\n Num. identif: "); scanf("%d",&lista[400].numidentif);
				//---------------------------REVISAR QUE NO EXISTA--------------------------
				for (a=0; a<n-1; a++){
					if(lista[400].numidentif == lista[a].numidentif){
						error();
						a=n;
						return 0;
					}
				}
				//---------------------------------------------------------------------------
				continuar:
				printf("\n Edad: ");
				scanf("%d",&lista[400].edad);
				printf("\nA%co de nacimiento: ",164);
				scanf("%d",&lista[400].anyo);
				strcpy(lista[i].nombre, lista[400].nombre);
				strcpy(lista[i].apellido, lista[400].apellido);
				lista[i].numidentif = lista[400].numidentif;
				lista[i].edad = lista[400].edad;
				lista[i].anyo = lista[400].anyo;
				
				printf("\n Datos modificados exitosamente!");
				lista[i].eliminar=0;
				empleado_no_registrado=false;
				i=n;
			}
			else empleado_no_registrado=true;
		}
	}
	if(empleado_no_registrado == true) printf("\n Empleado no registrado ");
	getch();
}
}

void listar_proyectos(){
	
	for (l=0;l<lista[i].proyectos;l++)
 		
		 {
		 	printf("\n");
 			printf("\n Proyecto n%cmero: %i",163,l+1);
 			printf("\n");
 			//printf("\n Nombre del proyecto: %s",lista[i].nombreproyecto);
 			//printf("\n Presupuesto del proyecto: %i",lista[i].presupuestoproyecto);
		 }
	
}

void asignar_proyecto(){
	
/*	for(i=0;i<DIM;i++){
	
	printf("Introduce el n%cmero identificativo del empleado: ",163);
	scanf("%u",&buscarnumident);
	
	if (lista[i].numidentif==buscarnumident){
		
	fflush(stdin);
 		printf("\nIntroduce el n%cmero de proyectos en los que trabaja: ",163);
 		scanf("%i",&lista[i].proyectos);
 		
	if (lista[i].proyectos>10)
		{
 		printf("\nError, introduce m%cximo 10 proyectos",160);
 		printf("\nIntroduce el n%cmero de proyectos en los que trabaja: ",163);
 		scanf("%i",&lista[i].proyectos);
 		}
	
	for (l=0;l<lista[i].proyectos;l++)
 		{
 			printf("\n Proyecto n%cmero: %i",163,l+1);
 			printf("\n");
 			printf("\n Introduce el nombre del proyecto: ");
 			//scanf("%s",&lista[i].nombreproyecto);
 			printf("\n Introduce el presupuesto del proyecto: ");
 			//scanf("%i",&lista[i].presupuestoproyecto);
		 }
	}
	
	break;
}
*/
}

void darbaja_proyecto(){
}

void guardar_fichero(){
}

void cargar_fichero(){
}
 
// Función menú

void menu(){
	
int opcion;
 
 for(;;){
 
 	printf("\n Men%c de gesti%cn de empleados",163,162);
 	printf("\n--------------------------------");
 	printf("\n1. Introducir nuevo empleado");
 	printf("\n2. Eliminar un empleado");
 	printf("\n3. Modificar datos de un empleado");
 	printf("\n4. Lista de proyectos de empleado");
 	printf("\n5. Asignar a un empleado un nuevo proyecto");
 	printf("\n6. Dar de baja un proyecto de un empleado");
	printf("\n7. Listar todos los empleados y sus datos");
	printf("\n8. Guardar en fichero");
	printf("\n9. Cargar de fichero");
 	printf("\n10. Salir del programa");
 	printf("\n");
 	printf("\n Introduce una opci%cn: ",162);
 	scanf("%i", &opcion);
 
 	if(opcion==1){pedir_datos();}
 	if(opcion==2){eliminar_empleado();}
 	if(opcion==3){modificar_datos();}
	if(opcion==4){listar_proyectos();}
	if(opcion==5){asignar_proyecto();}
	if(opcion==6){darbaja_proyecto();}	
	if(opcion==7){mostrar_datos();}
 	if(opcion==8){ guardar_fichero();}
 	if(opcion==9){cargar_fichero();}
 	if(opcion==10)
		{
 		printf("\nA continuaci%cn el programa se cerrar%c",162,160);
 		return 0;
 		}
	}
}

// Función principal que contiene el menú y los submenús

int main()
{
 menu();
}
