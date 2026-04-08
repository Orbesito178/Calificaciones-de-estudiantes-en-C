/*
            UNIVERSIDAD DE LAS AMÉRICAS
    FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
            INGENIERÍA DE SOFTWARE
                PROGRAMACIÓN I
Autores: 
    -David Cañizares
    -Sebastián Orbe
    -Jean Pierre Rosas
    -Derek Yépez

============== SISTEMA DE CALIFICACIONES ==============
*/

#include <stdio.h>
#include <string.h>

//Prototipo-Firma de la función para elegir al estudiante.
void elegirEstudiante(int e); 
void subMenu();


//DECLARACIÓN DE LAS MATRICES COMO VARIABLES GLOBALES
char nombresAlumnos[5][50]={"David Canizares", "Sebastian Orbe", "Jean Pierre Rosas", "Derek Yepez", "Jeff Einstein"}; //Matriz que almacena los nombres de los 5 estudiantes.
char nombresMaterias[3][20]={"Calculo I", "Programacion I", "Fisica General"}; //Matriz que almacena el nombre de las 3 materias.
float calificaciones[5][3]; //Matriz que almacena las calificaciones de los 5 estudiantes en cada una de las 3 materias.



int main(){
    
    int opcionEst; //Variable para seleccionar al estudiante objetivo.
    int i, j, k; //Variables que recorren arreglos.
    int opcionSubMenu; //Variable que controla qué accion hacer despues de registrar a los estudiantes.
    
    //Creación del menú con los 5 alumnos para escoger y registrar.
    do{
        printf("======= REGISTRO DE NOTAS UDLA ======\n");

        for(i=0; i<5; i++){ //Se muestran los nombres de los alumnos para registrar.
            printf("%d. %s\n", i+1, nombresAlumnos[i]);
        }
        printf("--------------\n");
        printf("6. Acabar el registro.\n");
        printf("--------------\n");
        printf("Seleccione una opcion: ");
        
        while((scanf("%d", &opcionEst)!=1)){ //Validar que no se ingresen letras.
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionEst);    
            while(getchar()==1);
        }

        while(opcionEst > 6 || opcionEst < 1){ //Validar que no se ingresen valores fuera del rango.
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionEst);
        }

        if(opcionEst == 6){ //Salir del menú si se selecciona 6.
            break;
        }else{
            elegirEstudiante(opcionEst); //Invocar a la función que registra a cada estudiante seleccionado.
        }
        

    }while(opcionEst != 6);

    //Submenú para realizar las acciones despues del registro.
    do{
        subMenu(); //Invocar al procedimiento que muestra el submenú.
        while((scanf("%d", &opcionSubMenu)!=1)){ //Validar que no se ingresen letras.
            printf("[ERROR CARACTER]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionSubMenu);    
            while(getchar()==1);
        }
        switch(opcionSubMenu){
            case 1: //Imprimir el reporte de notas de los estudiantes.
                printf("\n==== REPORTE DE CALIFICACIONES ====\n");
                for(i=0; i<5; i++){
                    printf(">>> %s <<<\n", nombresAlumnos[i]);
                    for(j=0; j<3; j++){ //Mostrar el nombre de las materias, junto con su respectiva calificacion.
                        printf("%s: ", nombresMaterias[j]);
                        printf("%.1f", calificaciones[i][j]);
                        printf("\n");
                    }
                    printf("\n");
                }
                    
                break;
            case 2: 
                break;
            case 3:
                break;
            case 4:
                break;
        }

    }while(opcionSubMenu != 5);
    

        
        
    return 0;
}

/////////////////////////////////////////////////
//FUNCIONES

//Función usada para elegir al estudiante y mostrar su nombre, las 3 materias, y pedir su calificación por cada materia.
void elegirEstudiante(int eleccion){ //Variable eleccion que funciona de parámetro para la función (es el numero de estudiante seleccionado).
    int u; //Variable que recorre el arreglo de las materias y de las calificaciones
    printf(">>>>> %s <<<<<\n", nombresAlumnos[eleccion-1]);

    for(int u=0; u<3; u++){ //Recorre la matriz de las materias y las calificaciones.
        printf("%s: ", nombresMaterias[u]);
        
        //Validar que no se ingresen letras.
        while(scanf("%f", &calificaciones[eleccion-1][u]) != 1 ){ 
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%f", &calificaciones[eleccion-1][u]);     
            while(getchar()==1);
        }

        //Validar que no se ingresen valores fuera del rango.
        while(calificaciones[eleccion-1][u] > 10 || calificaciones[eleccion-1][u] < 0){ 
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%f", &calificaciones[eleccion-1][u]);
            while(getchar()==1);
        }
    }
        
    printf("\n");
}

//Función que muestra el submenú después de realizar el registro de estudiantes.
void subMenu(){
    printf("======== ACCIONES =======\n");
    printf("1. Imprimir Reporte completo de notas.\n");
    printf("2. Mostrar el promedio de cada estudiante.\n");
    printf("3. Mostrar el promedio por asignatura. \n");
    printf("4. Encontrar la calificacion mas alta.\n");
    printf("5. Encontrar la calificacion mas baja. \n");
    printf("6. Mostrar aprobados y reprobados por asignatura. \n");
    printf("-----------------\n");
    printf("Escoja una opcion: ");
}