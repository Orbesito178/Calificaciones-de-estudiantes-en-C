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

============== SISTEMA DE CALIFICACIONES =============
*/

//=====INCLUSIÓN DE LIBRERÍAS=====

#include <stdio.h>
#include <string.h>
#include <stdbool.h> //Librería para usar variables booleanas.

//=====PROTOTIPOS=====

//Prototipo-Firma de la función para elegir al estudiante.
void elegirEstudiante(int eleccion); 
//Prototipo de la función para mostrar el submenú posteriormente.
void subMenu();


//DECLARACIÓN DE MATRICES COMO VARIABLES GLOBALES
char nombresAlumnos[5][50]={"David Canizares", "Sebastian Orbe", "Jean Pierre Rosas", "Derek Yepez", "Jeff Einstein"}; //Matriz que almacena los nombres de los 5 estudiantes.
char nombresMaterias[3][20]={"Calculo I", "Programacion I", "Fisica General"}; //Matriz que almacena el nombre de las 3 materias.
float calificaciones[5][3]; //Matriz que almacena las calificaciones de los 5 estudiantes en cada una de las 3 materias.
float sumaEst[5]; //Arreglo que almacena la suma de las calificaciones por estudiante.
float promedioEst[5]; //Arreglo que almacena el promedio de las calificaciones por estudiante.
float sumaMateria[5]; //Arreglo que almacena la suma de las calificaciones por materia.
float promedioMateria[5]; //Arreglo que almacena el promedio de las calificaciones por materia.
char buscado[30]; //Arreglo que almacena el nombre del estudiante a buscar.
bool encontrado = false; //Variable booleana que cambia o no de estado para la búsqueda por nombre de estudiante.


///////////////////////////////////////////////

/*=====FUNCION PRINCIPAL=====*/

int main(){
    
    int opcionEst; //Variable para seleccionar al estudiante objetivo.
    int i, j, k; //Variables que recorren arreglos.
    int opcionSubMenu; //Variable que controla qué accion hacer despues de registrar a los estudiantes.
    int indiceMayor; //Variable que se usa para ajustar un índice de barrido dentro de un for y que no exista un desbordamiento de memoria.
    int aprobados; //Variable contadora usada para aumentar la cantidad de estudiantes aprobados.
    int reprobados; //Variable contadora usada para aumentar la cantidad de estudiantes reprobados.
    float notaMayorEst=0; //Variable usada para guardar la nota mayor por cada estudiante.
    float notaMayorAsig=0; //Variable usada para guardar la nota mayor por cada asignatura.
    float notaMenorEst=0; //Variable que guarda la nota más baja por cada estudiante.
    float notaMenorAsig=0; //Variable que almacena la nota más baja por cada asignatura.
    
    //Creación del menú con los 5 alumnos para escoger y registrar.
    do{
        printf("======= REGISTRO DE NOTAS UDLA ======\n");
        //Se muestran los nombres de los alumnos para registrar.
        for(i=0; i<5; i++){ 
            printf("%d. %s\n", i+1, nombresAlumnos[i]);
        }
        printf("--------------\n");
        printf("6. Acabar el registro.\n");
        printf("--------------\n");
        printf("Seleccione una opcion: ");
        
        //Validar que no se ingresen letras.
        while((scanf("%d", &opcionEst)!=1)){ 
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionEst);    
            while(getchar() != '\n'); //Limpiar el búfer
        }
        //Validar que no se ingresen valores fuera del rango.
        while(opcionEst > 6 || opcionEst < 1){ 
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionEst);
        }

        if(opcionEst == 6){ //Salir del menú si se selecciona 6.
            break;
        }else{
            elegirEstudiante(opcionEst); //Invocar a la función que registra a cada estudiante seleccionado.
        }


    }while(opcionEst != 6);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Submenú para realizar las acciones despues del registro.
    do{
        //Invocar al procedimiento que muestra el submenú.
        subMenu(); 

        //Validar que no se ingresen letras.
        while((scanf("%d", &opcionSubMenu)!=1)){ 
            printf("[ERROR CARACTER]: Vuelva a ingresar una opcion: ");
            scanf("%d", &opcionSubMenu);    
            while(getchar() != '\n');
        }

        //Validar que no se ingrese un valor fuera del rango
        while(opcionSubMenu < 1 || opcionSubMenu > 8){
            printf("[ERROR]: Opcion invalida. Ingrese un valor entre 1 y 8: ");
            while(scanf("%d", &opcionSubMenu) != 1){
                while(getchar() != '\n');
                printf("[ERROR]: Ingrese solo numeros. Vuelva a intentarlo: ");
            }
            while(getchar() != '\n');
        }

        //Switch con los casos del sub menú.
        switch(opcionSubMenu){
                    
            //Imprimir el reporte de notas de los estudiantes.
                    
            case 1: 
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

            //Promedio de calificaciones por cada estudiante.
                    
            case 2: 
                printf("\n======= PROMEDIOS GENERALES DE ESTUDIANTES =====\n");
                float sumaEst[5]={0}; //Se inicializa todos los valores de la matriz en 0 para evitar que los cálculos se acumulen cada
                                      //vez que se seleccione esta opción.
                
                for( i=0; i<5; i++){
                    printf("\n>>>> %s <<<<\n", nombresAlumnos[i]);
                    //Acumular y sumar las 3 calificaciones (cada asignatura) de 1 estudiante.
                    for(j=0; j<3; j++){
                        sumaEst[i] += calificaciones[i][j]; 
                        //Calcular el promedio dividiendo la suma entre el numero de materias.
                        promedioEst[i] = sumaEst[i] / 3;
                    }
                    printf("Promedio General: %.2f\n", promedioEst[i]);
                }
                    
                break;

            //Promedio de calificaciones por asignatura.
                    
            case 3:
                printf("\n======== PROMEDIOS GENERALES DE ASIGNATURAS =====\n");
                float sumaMateria[5]={0}; //Se inicializa la matriz en 0 para evitar cálculos acumulados cada vez que se seleccione esta opción.
                
                for(i=0; i<3; i++){
                    printf("\n>>>> %s <<<<\n", nombresMaterias[i]);
                    //Acumular y sumar las 5 calificaciones (cada estudiante) de 1 materia.
                    for(j=0; j<5; j++){
                        sumaMateria[i] += calificaciones[j][i];
                    }
                    //Calcular el promedio de la asignatura dividiendo la suma entre el numero de estudiantes.
                    promedioMateria[i] = sumaMateria[i] / 5;
                    printf("Promedio General: %.2f\n", promedioMateria[i]);
                }
                break;

            //Notas más altas por estudiante y por asignatura.
                    
            case 4:
                printf("\n==== NOTAS MAS ALTAS POR ESTUDIANTE ====\n");
              
                for(i = 0; i < 5; i+=1) {
                    indiceMayor = 0;
                    notaMayorEst = calificaciones[i][0]; //Se inicializa la nota mayor en el primer elemento del barrido-
                    for(j = 0; j < 3; j++) {
                        //Condicional para obtener la nota mayor por estudiante.
                        if(calificaciones[i][j] >= notaMayorEst) {
                            notaMayorEst = calificaciones[i][j];
                            indiceMayor = j; //se asigna el valor de j al índice mayor para que se ajuste el tamaño de la matriz de los nombres
                                             //de las materias al momento de imprimir en cada iteración.
                        }

                    }
                    printf(">>>> %s <<<<\n", nombresAlumnos[i]);

                    //Este recorrido imprime todas las asignaturas con mayor nota por estudiante. 
                    for(j = 0; j < 3; j++) {
                        if(calificaciones[i][j] == notaMayorEst) {
                            printf("%s: %.2f\n", nombresMaterias[j], notaMayorEst);
                        }
                    }
                    printf("\n");
                }


                printf("\n==== NOTAS MAS ALTAS POR ASIGNATURA ====\n");
                for(i=0; i<3; i+=1){
                    indiceMayor = 0;
                    notaMayorAsig = calificaciones[0][i];
                    for(j=0; j<5; j++){
                        //condicional para obtener la mayor nota por asignatura.
                        if(calificaciones[j][i] >= notaMayorAsig){
                            notaMayorAsig = calificaciones[j][i];
                            indiceMayor = j; //se asigna el valor de j al índice para ajustar al tamaño de la matriz de los nombre de los alumnos.
                        }
                    }
                    printf(">>>> %s <<<<\n", nombresMaterias[i]);

                    //Este recorrido imprime a todos los estudiantes que tienen mayor nota por asignatura.
                    for(j = 0; j < 5; j++) {
                        if(calificaciones[j][i] == notaMayorAsig) {
                            printf("%s: %.2f\n", nombresAlumnos[j], notaMayorAsig);
                        }
                    }
                    printf("\n");
                }

                break;
            
            //Notas mas bajas por estudiante y por asignatura.
            case 5:
                printf("==== NOTAS MAS BAJAS POR ESTUDIANTE====\n");
                for(i = 0; i < 5; i+=1) {
                    indiceMayor = 0;
                    notaMenorEst = calificaciones[i][0];
                    for(j = 0; j < 3; j++) {
                        if(calificaciones[i][j] <= notaMenorEst) {
                            notaMenorEst = calificaciones[i][j];
                            indiceMayor = j;
                        }
                    }

                    printf(">>>> %s <<<<\n", nombresAlumnos[i]);

                    //Imprime todos las asignaturas con la nota mas baja por estudiante. 
                    for(j = 0; j < 3; j++) {
                        if(calificaciones[i][j] == notaMenorEst) {
                            printf("%s: %.2f\n", nombresMaterias[j], notaMenorEst);
                        }
                    }
                    printf("\n");
                }
                printf("\n==== NOTAS MAS BAJAS POR ASIGNATURA ====\n");
                for(i=0; i<3; i+=1){
                    indiceMayor = 0;
                    notaMenorAsig = calificaciones[0][i];
                    for(j=0; j<5; j++){
                        if(calificaciones[j][i] <= notaMenorAsig){
                            notaMenorAsig = calificaciones[j][i];
                            indiceMayor = j;
                        }
                    }
                    printf(">>>> %s <<<<\n", nombresMaterias[i]);
                    
                    //imprime todos los estudiantes con menor nota por asignatura.
                    for(j = 0; j < 5; j++) {
                        if(calificaciones[j][i] == notaMenorAsig) {
                            printf("%s: %.2f\n", nombresAlumnos[j], notaMenorAsig);
                        }
                    }
                    printf("\n");
                }                
                break;

            //Aprobados y reprobados por asignatura.
            case 6:

                printf("\n======= APROBADOS Y REPROBADOS =====\n");
                for(i = 0; i < 3; i++) {
                    //Se inicializan las variables en 0 en cada iteración para evitar acumulaciones al momento del barrido de columnas.
                    aprobados = 0;
                    reprobados = 0;

                    for(j = 0; j < 5; j++) {
                        //condicional que evalúa si la nota es aprobatoria o no.
                        if(calificaciones[j][i] >= 6) {
                            aprobados++; //contador de aprobados.
                        } else {
                            reprobados++; //contador de reprobados.
                        }
                    }

                    printf("> %s:\n", nombresMaterias[i]);
                    printf("    Aprobados: %d\n", aprobados);
                    printf("    Reprobados: %d\n", reprobados);

                }
                break;
                
            //Buscar estudiante por nombre.
            case 7:
                printf("\n==== BUSQUEDA DE ESTUDIANTE ====\n");
                printf("Ingrese el nombre del estudiante: ");

                while(getchar() != '\n'); //Borra el buffer para usar el fgets.
                encontrado=false; //Se inicializa la variable "Bandera".

                fgets(buscado, 50, stdin);
                buscado[strcspn(buscado, "\n")] = '\0'; //Sustituye el "enter" por el caracter nulo para comparar las cadenas.
                //Búsqueda por los 5 estudiantes por una coincidencia con la cadena buscado.
                for(i=0; i<5; i++){
                    if(strcmp(buscado, nombresAlumnos[i]) == 0){ //se comparan las cadenas para encontrar coincidencia.
                        encontrado = true; //Se cambia el estado de encontrado de falso a verdadero.
                        printf("\n--- ALUMNO ENCONTRADO!\n");
                        //Impresión de las estadísticas del alumno.
                        printf("=== %s ===\n", nombresAlumnos[i]);
                        for(j=0; j<3; j++){
                            printf(">>> %s <<<\n", nombresMaterias[j]);
                            printf("%.2f\n", calificaciones[i][j]);
                        }
                    }
                }
                //Si no hubo coincidencia, el estado encontrado se mantiene en falso y se emite un mensaje.
                if(encontrado == false){
                    printf("Estudiante no encontrado.\n");
                }
                break;
            
            //Salida del programa.
            case 8:
                printf("Saliendo del programa...");
                break;

        }

    }while(opcionSubMenu != 8); 
    
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
            while(getchar() != '\n');
        }

        //Validar que no se ingresen valores fuera del rango.
        while(calificaciones[eleccion-1][u] > 10 || calificaciones[eleccion-1][u] < 0){ 
            printf("[ERROR]: Vuelva a ingresar una opcion: ");
            scanf("%f", &calificaciones[eleccion-1][u]);
            while(getchar() != '\n');
        }


    }
        
    printf("\n");
}

//Función que muestra el submenú después de realizar el registro de estudiantes.
void subMenu(){
    printf("\n======== ACCIONES =======\n");
    printf("1. Imprimir Reporte completo de notas.\n");
    printf("2. Mostrar el promedio de cada estudiante.\n");
    printf("3. Mostrar el promedio por asignatura. \n");
    printf("4. Encontrar la calificacion mas alta.\n");
    printf("5. Encontrar la calificacion mas baja. \n");
    printf("6. Mostrar aprobados y reprobados por asignatura. \n");
    printf("7. Buscar estudiante por nombre.\n");
    printf("8. Salir.\n");
    printf("-----------------\n");
    printf("Escoja una opcion: ");
}

