/*------ ADMINISTRACIÓN DE MEMORIA---------
Programa creado por Cesar Eduardo Garza Ceja
Asignatura: Sistemas Operativos
Semestre: 2022-2*/

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
        void delay(float number_of_seconds){
                // Converting time into milli_seconds
                int milli_seconds = 1000 * number_of_seconds;
                // Storing start time
                clock_t start_time = clock();
                // looping till required time is not achieved
                while (clock() < start_time + milli_seconds)
                        ;
        }
        
        //PARTICION ESTATICA
        void pEstatic(int memory){
                int numPart, tamPart, proceso, numProcesos,response2,flag2=0,exit=0;
                
                while (exit != 1)
                {
                        system("cls");
                        printf("\n--- PARTICIONAMIENTO ESTATICO ---");
                        printf("\nMemoria disponible: %d kB",memory);
                        printf("\nIngrese el numero de particiones: ");
                        scanf("%d", &numPart); //NUMERO DE PARTICIONES 
                        int parts[numPart];
                        tamPart = memory/numPart;
                        printf("\nCada partici%cn estatica es de: %d kB\n",162,tamPart); 
                        
                        for (int i = 0; i < numPart; i++)
                        {
                                parts[i]=tamPart;
                                printf("\n  Partici%cn %d = %d kB",162,i+1,parts[i]);
                        }
                        
                        printf("\n\nDeseas agregar un proceso?   0=No   1=Si   2=regresar  : ");
                        scanf("%d", &proceso);
                        if(proceso == 1)
                        {       
                                printf("\n   Cuantos procesos deseas agregar?");
                                scanf("%d",&numProcesos);
                                
                                int i = 0;
                                while(flag2!=1 )
                                {
                                        printf("\nindique el tama%co del proceso %d en kB: ",164,i+1);
                                        scanf("%d",&response2);
                                        
                                        if(response2 > tamPart){
                                                printf("\nMEMORIA INSUFICIENTE");
                                                delay(3);
                                        }else if (response2 < tamPart && response2>0){
                                                if( i == numProcesos-1){
                                                        flag2=1;
                                                }else{
                                                        parts[i]=parts[i]-response2;
                                                        printf("\nProceso agregado correctamente.");
                                                        i=i+1;
                                                }
                                        }
                                        else{
                                                printf("Ingrese un algo valido");
                                        }
                                }
                                for (int i = 0; i < numPart; i++)
                                {
                                        parts[i]=tamPart;
                                        printf("\n  Partici%cn %d = %d kB",162,i+1,parts[i]);
                                }    
                        }
                        else if(proceso == 2){
                                exit= 1;
                                
                        }
                        else if(proceso == 0){
                                
                        }
                        else{
                                system("cls");
                                printf("%cIngresa un valor valido!",173);
                                delay(3);      
                        }          
                }                       
        }
        
        void menuP (){
                printf("\n   CezkOS 1.0");
                //delay(2);
                printf("\n   Preparando archivos ");
                for (  int i = 0; i < 50; i++)
                {
                        //delay(0.1);
                        printf("#");
                }

        
                int  opcion, memory;
                memory = 1024;
                do{
                        system("cls");
                        printf("\n Memoria disponible: %d kB\n", memory);
                        printf("\n   En el sistema se pueden usar los siguientes modos de gestion de memoria:");
                        printf("\n\n   1. Particionamiento estatico");
                        printf("\n   2. Parcicionamiento dinamico.");
                        printf("\n   3. Paginaci%cn de memoria.",162);
                        printf("\n   4. Segmentaci%cn de memoria.",162);
                        printf("\n\n   Introduzca opci%con (1-4): ", 162);

                        scanf("%d", &opcion);
                        if (opcion == 1)
                        {
                                pEstatic(memory);
                        }
                        else if(opcion == 2){
                                printf("En produccion...");
                        }
                        else{
                                opcion=4;
                        }
                        
                } while (opcion != 4);
        }

        // INICIO
        menuP();

}