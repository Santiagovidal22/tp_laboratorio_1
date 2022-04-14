/*
 ============================================================================
 Name        : TP_LABORATORIO1.c
 Author      : Santiago Vidal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int kilometros;
	float precioLatam;
	float precioAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBtcLatam;
	float precioPorKmLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBtcAerolineas;
	float precioPorKmAerolineas;
	float diferenciaPrecios;


	do{


	printf("\n\n1- Ingresar Kilómetros(km=x). \n"
				"2- Ingresar Precio de Vuelos.(Aerolíneas=y, Latam=z) \n"
				"3- Calcular todos los costos. \n"
				"4- Informar Resultados. \n"
				"5- Carga forzada de datos. \n"
				"6- Salir. \n"
				"\n Ingrese la opción deseada: ");

	scanf("%d", &opcion);

	switch(opcion)
		{
				case 1:
				printf("ingrese los kilometros");
				scanf("%d", &kilometros);
				break;
				case 2:
				printf("ingrese el precio de Aerolineas Argentinas");
				scanf("%f", &precioAerolineas);
				printf("ingrese el precio de Aerolineas Latam ");
				scanf("%f", &precioLatam);
				break;
				case 3:
				precioDebitoLatam= valorDebito(precioLatam);
				precioCreditoLatam= valorCredito(precioLatam);
				precioBtcLatam= valorBtc(precioLatam);
				precioPorKmLatam= precioPorKm(precioLatam,kilometros);
				precioDebitoAerolineas= valorDebito(precioAerolineas);
				precioCreditoAerolineas=valorCredito(precioAerolineas);
				precioBtcAerolineas= valorBtc(precioAerolineas);
				precioPorKmAerolineas= precioPorKm(precioAerolineas,kilometros);
				diferenciaPrecios= diferenciaPrecio(precioLatam ,precioAerolineas);
				break;
				case 4:
				printf("\nKMs Ingresados: %d km"
						"\n\nPrecio Aerolineas: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.2f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\nPrecio Latam: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.2f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\n Diferencia: %.2f",kilometros, precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas , precioBtcAerolineas, precioPorKmAerolineas, precioLatam, precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioPorKmLatam, diferenciaPrecios);

				break;
				case 5:
				precioLatam = 159339;
				kilometros = 7090;
				precioAerolineas= 162965;
				precioDebitoLatam= valorDebito(precioLatam);
				precioCreditoLatam= valorCredito(precioLatam);
				precioBtcLatam= valorBtc(precioLatam);
				precioPorKmLatam= precioPorKm(precioLatam,kilometros);
				precioDebitoAerolineas= valorDebito(precioAerolineas);
				precioCreditoAerolineas=valorCredito(precioAerolineas);
				precioBtcAerolineas= valorBtc(precioAerolineas);
				precioPorKmAerolineas= precioPorKm(precioAerolineas,kilometros);
				diferenciaPrecios= diferenciaPrecio(precioLatam ,precioAerolineas);
				printf("\nKMs Ingresados: %d km"
						"\n\nPrecio Aerolineas: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.2f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\nPrecio Latam: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.2f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\n Diferencia: %.2f",kilometros, precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas , precioBtcAerolineas, precioPorKmAerolineas, precioLatam, precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioPorKmLatam, diferenciaPrecios);
				break;
				case 6:
				printf("Muchas gracias por utilizar nuestra plataforma");
				break;

				default:
				printf("esta opcion no es valida");

		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
