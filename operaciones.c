/* Este programa es para el laboratorio 3 de la clase de Alse 
  Autor:Mariana Herrera y  Karin Lugo 
  Licencia: Comercial
  Versión: 1.0
  */

/* inclusión de librerias */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_FILE_SIZE 600
#define TAM 50

void main(int argc, char *argv[])
{
	FILE *file_descriptor1,*file_descriptor2,*file_descriptor3,*file_descriptor4;
	char buffer[MAX_FILE_SIZE],buffer1[MAX_FILE_SIZE],buffer2[MAX_FILE_SIZE],buffer3[MAX_FILE_SIZE];
	size_t result = 0, result1 = 0,result2 = 0, result3 = 0;
	long file_size = 0, file_size1 = 0,file_size2 = 0, file_size3 = 0;
	char *bu;
	bu = &buffer;
	//unsigned char vectorA[ps],vectorB[ps],vector[ps];
	
    float a[TAM][TAM],b[TAM][TAM];
    int cont_fila,cont_col;
	int fil=0, col=0;
	
	
	
	file_descriptor1 = fopen (argv[1],"r");
	file_descriptor2 = fopen (argv[2],"r");
	
	if (file_descriptor1 == NULL)
	{
		printf("Error en la lectura del archivo\n");
		return 1;
	}
	
	
	fseek ( file_descriptor1, 0, SEEK_END);
	fseek ( file_descriptor2, 0, SEEK_END);
	
	file_size = ftell (file_descriptor1);
	file_size1 = ftell (file_descriptor2);
	
	rewind (file_descriptor1);
	rewind (file_descriptor2);
	
	//copy the file into the buffer:
	result = fread ( buffer, 1, file_size, file_descriptor1);
	result1 = fread ( buffer1, 1, file_size1, file_descriptor2);
	if (result != file_size)
	{
		fputs ("Error de lectura de buffer", stderr);
		
	}
	if (result1 != file_size1)
	{
		fputs ("Error de lectura de buffer1", stderr);
		
	}
	//close file 
	fclose(file_descriptor1);
	buffer[file_size] = '\0'; 
	printf("\n\nLa MatrizA es: \n\n%s",buffer);
	
	fclose(file_descriptor2);
	buffer1[file_size1] = '\0'; 
	printf("\n\nLa MatrizB es: \n\n%s",buffer1);
	
	
	/*
	for (int cont_col=0; b[cont_col] != '/r' && b[cont_col] != '/n'; cont_fila++)
	{
		int numeroC = 0
		if (b[cont_col] == ';')
		{ 
			numeroC = numeroC++;
		}
		printf("\nEl numero de columnas es: \n%d", numeroC);
	}
	
	*/
		
		
	
	
	
	
	
	if (strcmp("--help",argv[3])==0)	
	{
		file_descriptor3 = fopen ("texto.txt","r");
		fseek ( file_descriptor3, 0, SEEK_END);
		file_size2 = ftell (file_descriptor3);
		rewind (file_descriptor3);
		result2 = fread ( buffer2, 1, file_size2, file_descriptor3);
		fclose(file_descriptor3);
		buffer2[file_size2] = '\0'; 
		printf("\n\nLa ayuda es: \n\n%s",buffer2);
	}
	else 
		{
		if (strcmp("-v",argv[3])==0)
			{
				file_descriptor4 = fopen ("texto1.txt","r");
				fseek ( file_descriptor4, 0, SEEK_END);
				file_size3 = ftell (file_descriptor4);
				rewind (file_descriptor4);
				result3 = fread ( buffer3, 1, file_size3, file_descriptor4);
				fclose(file_descriptor4);
				buffer3[file_size3] = '\0'; 
				printf("\n\nLa  versión,los autores y la fecha de desarrollo son: \n\n%s",buffer3);
				printf("\n");
			}
	
			else 
			{
			if (strcmp("-t", argv[3])==0)
				{
				
					transpuesta_matrizA(fil, col, a[TAM][TAM]);
					transpuesta_matrizB(fil, col, b[TAM][TAM]);				
				}
				else 
					{
					if (strcmp("-a",argv[3])==0)
						{
							sumar_matrices (fil, col, a[TAM][TAM], b[TAM][TAM]);
						}
			
						else 
						{
						if (strcmp("-r",argv[3])==0)
							{
								restar_matrices (fil, col, a[TAM][TAM], b[TAM][TAM]);
							}
						}
					}	
				
			}
		}
		
}
								
void transpuesta_matrizA(int fil, int col, float a[TAM][TAM])
{
    float trans_a[TAM][TAM];
    for (int cont_fila=0; cont_fila < fil; cont_fila++)
        {
            for (int cont_col=0; cont_col< col; cont_col++)
            {
                trans_a[cont_fila][cont_col] = a[cont_col][cont_fila] ;
				printf("%f ",trans_a[cont_fila][cont_col]);
				printf("\n");
            }
        }
}

void transpuesta_matrizB(int fil, int col, float b[TAM][TAM])
{
    float trans_b[TAM][TAM];
    for (int cont_fila=0; cont_fila < fil; cont_fila++)
        {
            for (int cont_col=0; cont_col< col; cont_col++)
            {
                trans_b[cont_fila][cont_col] = b[cont_col][cont_fila] ;
				printf("%f ",trans_b[cont_fila][cont_col]);
				printf("\n");
            }
        }
}

void sumar_matrices (int fil, int col, float a[TAM][TAM], float b[TAM][TAM])
{
    float suma[TAM][TAM];
    for (int cont_fila=0; cont_fila<fil; cont_fila++)
        {
            for (int cont_col =0; cont_col<col; cont_col++)
            {
                suma[cont_fila][cont_col] = a[cont_fila][cont_col] + b[cont_fila][cont_col];
				printf("%f ",suma[cont_fila][cont_col]);
                printf("\n");
            }
        }          
}
void restar_matrices (int fil, int col, float a[TAM][TAM], float b[TAM][TAM])
{
    float resta[TAM][TAM];
    for (int cont_fila=0; cont_fila<fil; cont_fila++)
        {
            for (int cont_col =0; cont_col<col; cont_col++)
            {
                resta[cont_fila][cont_col] = a[cont_fila][cont_col] - b[cont_fila][cont_col];
				printf("%f ",resta[cont_fila][cont_col]);
                printf("\n");
            }
		}   
}