#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int GradoDeLaFuncion(int []);
void ConstantesDeLaFuncion(float [], int, int []);
int validarNumeros(char []);
int valorFuncionExtra;
float errorAproximado(float,float);
float aproximacionInicial(float [], int , int []);
float porcentajeError();
float iteracion(float [], int , int [], float);

int main (){
	int grado, i=0;
	int funcionExtra[' '];
	float aproximacion, error;
	float sigValor;
	float sigTempo;
	float valor;
	float aprox = 100;
	
	grado = GradoDeLaFuncion(funcionExtra);

	float funcion[grado-1];

	ConstantesDeLaFuncion(funcion, grado, funcionExtra);
	aproximacion = aproximacionInicial(funcion, grado, funcionExtra);
	error = porcentajeError();
	
	sigValor = iteracion(funcion, grado, funcionExtra, aproximacion);
	printf("\nIteracion		Xi		Ea");
	do{
		if(i==0)	{
			printf("\n%d		%f		NA", i, sigValor);
			valor = sigValor;
		}else{
			sigTempo = sigValor;
			sigValor = iteracion(funcion, grado, funcionExtra, valor);
			aprox = errorAproximado(sigValor, valor);
			printf("\n%d		%f		%f", i, sigValor, aprox);
			valor = sigValor;
		}
		i=i+1;
	}while(error < aprox);
	

	
	return 0;
}

int GradoDeLaFuncion(int funcionExtra[]){
	int i = 0, j=0, grado, opcion, longitud;
	char valor[' '];
	char tipoDeFunciones[' '];
	int funcion;
	
	do{
		printf("\nIngrese el grado de la Funcion:");
		scanf("%s", &valor);
	}while(validarNumeros(valor) != 0);
	
	grado = atoi(valor);
	
	do{
		do{
			printf("\nSeleccione una opcion si desea agregar una funcion.");
			printf("\n0-Exponencial negativo\n1-Seno\n2-Coseno\n3-Tangente\n4-Exponencial\n5-No agregar\n");
			scanf("%s", &valor);
		}while(validarNumeros(valor) != 0);
		
		opcion = atoi(valor);
		
			if(opcion == 0)
				funcionExtra[i] = 0;
			if(opcion == 1)
				funcionExtra[i] = 1;
			if(opcion == 2)
				funcionExtra[i] = 2;
			if(opcion == 3)
				funcionExtra[i] = 3;
			if(opcion == 4)
				funcionExtra[i] = 4;
		
				
		
		i=i+1;
	}while(opcion != 5);
	i = i - 1;
	valorFuncionExtra = i;
	grado = grado + i;
	
	return grado;
}

void ConstantesDeLaFuncion(float funcion[], int grado, int funcionExtra[]){
	int i, j=0;
	char valor[' '];
	int extra = grado-valorFuncionExtra;
	
	printf("\nSe ingresaran los valores de las constantes ");
	
	for(i = 0; i < extra; i++){
		
			printf("\n x%c%d: ", 94, extra-i);
			scanf("%f", &funcion[i]);
	
	}
	

	for(i = extra; i < grado; i++){
	
			if(funcionExtra[j] == 0){
				printf("\nExp negativo:");
				scanf("%f", &funcion[i] );
			}
			if(funcionExtra[j] == 1){
				printf("\nSen:");
				scanf("%f", &funcion[i]);
			}
			if(funcionExtra[j] == 2){
				printf("\nCos:");
				scanf("%f", &funcion[i]);
			}
			if(funcionExtra[j] == 3){
				printf("\nTan:");
				scanf("%f", &funcion[i]);
			}
			if(funcionExtra[j] == 4){
				printf("\nExp:");
				scanf("%f", &funcion[i]);
			}
	
	
	
		j= j+1;
		
	}
	
}

//Retorna 0 si es valido
int validarNumeros(char valorRecibido[' ']){
	int i = 0, esNumero = 0;
	int longitud = strlen(valorRecibido);
		
	for (i = 0 ; i < longitud ; i++){
		if(isdigit(valorRecibido[i]) == 0 && valorRecibido[i] != 46 && valorRecibido[i] != 45){
				printf("\n No es un valor valido.");	
				return 1;	
		}
	}
	
	return 0;
}

float errorAproximado(float valorActual, float valorAnterior){
	float error = ((valorActual-valorAnterior)/valorActual)*100;
		if(error<0)
			error= error*(-1);
	return error;
}

float aproximacionInicial(float funcion[], int grado, int funcionExtra[]){
	float aproximacionInicial=0;
	char valor[' '];

	do{
		printf("\nIngrese la aproximacion inicial:");
		fflush(stdin);
		scanf("%s", &valor);
	}while(validarNumeros(valor) != 0);	
	
	aproximacionInicial = atof(valor);
	
return aproximacionInicial;
}

float porcentajeError(){
	float errorAproximado;
	char valor[' '];
	do{
		printf("\nIngrese el porcentaje de error aproximado:");
		fflush(stdin);
		scanf("%s", &valor);
	}while(validarNumeros(valor) != 0);	
	
	errorAproximado = atof(valor);
	
return errorAproximado;
}

float iteracion(float funcion[], int grado, int funcionExtra[], float aproximacion){
	int i, j=0; 
	float valorFuncion=0;
	int iteracionesFuncion = grado-valorFuncionExtra;
	float elevar;
	
		for(i = iteracionesFuncion-1 ; i >= 0 ; i--){
			elevar = pow(aproximacion, i+1);
			valorFuncion = valorFuncion + (funcion[j] * elevar);
		
		
			j++;
		} 
	
		j=0;
		for(i = grado-1; i >= grado-valorFuncionExtra ; i--){
	
			
			if(funcionExtra[j] == 0){
		
				valorFuncion = valorFuncion + (funcion[i] * exp(-aproximacion));
			}
			if(funcionExtra[j] == 1){
			
				valorFuncion = valorFuncion + (funcion[i] * sin(aproximacion));
			}
			if(funcionExtra[j] == 2){
		
				valorFuncion = valorFuncion + (funcion[i] * cos(aproximacion));
			}
			if(funcionExtra[j] == 3){
			
				valorFuncion = valorFuncion + (funcion[i] * tan(aproximacion));
			}
			if(funcionExtra[j] == 4){
		
				valorFuncion = valorFuncion + (funcion[i] * exp(aproximacion));
			}
			j = j + 1;
		}
	
		
return valorFuncion;		
}

