/*
 ============================================================================
 Name        : TP_LABORATORIO1.c
 Author      : Santiago Vidal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1 Enunciado
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
 para ofrecerlos a sus clientes.
 Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
 El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
 Para ello el programa iniciar� y contar� con un men� de opciones:
 1. Ingresar Kil�metros: ( km=x)
 2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
 - Precio vuelo Aerol�neas:
 - Precio vuelo Latam:
 3. Calcular todos los costos:
 a) Tarjeta de d�bito (descuento 10%)
 b) Tarjeta de cr�dito (inter�s 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
 4. Informar Resultados
 �Latam:
 a) Precio con tarjeta de d�bito: r
 b) Precio con tarjeta de cr�dito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerol�neas:
 a) Precio con tarjeta de d�bito: r
 b) Precio con tarjeta de cr�dito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r �
 5. Carga forzada de datos
 6. Salir

 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	float kilometros;
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
	int banderakm = 0;
	int banderaprecioArgentinas = 0;
	int banderaprecioLatam = 0;
	int banderaCostos=0;

	do {

		printf("\n\n1- Ingresar Kilometros(km=x). \n"
				"2- Ingresar Precio de Vuelos.(Aerolineas=y, Latam=z) \n"
				"3- Calcular todos los costos. \n"
				"4- Informar Resultados. \n"
				"5- Carga forzada de datos. \n"
				"6- Salir. \n"
				"\n Ingrese la opcion deseada: ");

		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			printf("\ningrese los kilometros: ");
			scanf("%f", &kilometros);
			if (kilometros > 0) {
				banderakm = 1;
			} else {
				printf("\nERROR , ingrese un valor valido");
			}
			break;
		case 2:
			printf("\ningrese el precio de Aerolineas Argentinas: ");
			scanf("%f", &precioAerolineas);
			if (precioAerolineas > 0) {
				banderaprecioArgentinas = 1;
			} else {
				printf("\n ingrese un valor valido");
			}
			printf("\ningrese el precio de Aerolineas Latam: ");
			scanf("%f", &precioLatam);
			if (precioLatam > 0) {
				banderaprecioLatam = 1;
			} else {
				printf("\n ingrese un valor valido");
			}
			break;
		case 3:
			if (banderakm == 1 && banderaprecioArgentinas == 1
					&& banderaprecioLatam == 1) {
				precioDebitoLatam = valorDebito(precioLatam);
				precioCreditoLatam = valorCredito(precioLatam);
				precioBtcLatam = valorBtc(precioLatam);
				precioPorKmLatam = precioPorKm(precioLatam, kilometros);
				precioDebitoAerolineas = valorDebito(precioAerolineas);
				precioCreditoAerolineas = valorCredito(precioAerolineas);
				precioBtcAerolineas = valorBtc(precioAerolineas);
				precioPorKmAerolineas = precioPorKm(precioAerolineas,
						kilometros);
				diferenciaPrecios = diferenciaPrecio(precioLatam,
						precioAerolineas);
				banderaCostos=1;
				printf("\n los calculos han sido realizados correctamente");
			} else {
				if (banderakm == 0) {
					printf("ingrese los kilometros\n");
				}
				if (banderaprecioArgentinas == 0) {
					printf("ingrese el precio de Aerolineas Argentinas\n");
				}
				if (banderaprecioLatam == 0) {
					printf("ingrese el precio de Aerolineas Latam\n");
				}
			}
			break;
		case 4:
			if (banderakm == 1 && banderaprecioArgentinas == 1
					&& banderaprecioLatam == 1 && banderaCostos==1) {
				printf("\nKMs Ingresados: %f km"
						"\n\nPrecio Aerolineas: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.7f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\nPrecio Latam: $ %.2f"
						"\na) Precio con tarjeta de debito: $ %.2f"
						"\nb) Precio con tarjeta de credito: $ %.2f"
						"\nc) Precio pagando con bitcoin: $ %.7f"
						"\nd) Mostrar precio unitario: $ %.2f"
						"\n\n Diferencia: %.2f", kilometros, precioAerolineas,
						precioDebitoAerolineas, precioCreditoAerolineas,
						precioBtcAerolineas, precioPorKmAerolineas, precioLatam,
						precioDebitoLatam, precioCreditoLatam, precioBtcLatam,
						precioPorKmLatam, diferenciaPrecios);
			} else {
				if(banderaCostos==0)
				{
					printf("Todavia no se han calculado los costos \n");
				}
				if (banderakm == 0) {
					printf("ingrese los kilometros\n");
				}
				if (banderaprecioArgentinas == 0) {
					printf("ingrese el precio de Aerolineas Argentinas\n");
				}
				if (banderaprecioLatam == 0) {
					printf("ingrese el precio de Aerolineas Latam\n");
				}
			}
			break;
		case 5:

			precioLatam = 159339;
			kilometros = 7090;
			precioAerolineas = 162965;
			precioDebitoLatam = valorDebito(precioLatam);
			precioCreditoLatam = valorCredito(precioLatam);
			precioBtcLatam = valorBtc(precioLatam);
			precioPorKmLatam = precioPorKm(precioLatam, kilometros);
			precioDebitoAerolineas = valorDebito(precioAerolineas);
			precioCreditoAerolineas = valorCredito(precioAerolineas);
			precioBtcAerolineas = valorBtc(precioAerolineas);
			precioPorKmAerolineas = precioPorKm(precioAerolineas, kilometros);
			diferenciaPrecios = diferenciaPrecio(precioLatam, precioAerolineas);
			printf("\nKMs Ingresados: %f km"
					"\n\nPrecio Aerolineas: $ %.2f"
					"\na) Precio con tarjeta de debito: $ %.2f"
					"\nb) Precio con tarjeta de credito: $ %.2f"
					"\nc) Precio pagando con bitcoin: $ %.7f"
					"\nd) Mostrar precio unitario: $ %.2f"
					"\n\nPrecio Latam: $ %.2f"
					"\na) Precio con tarjeta de debito: $ %.2f"
					"\nb) Precio con tarjeta de credito: $ %.2f"
					"\nc) Precio pagando con bitcoin: $ %.7f"
					"\nd) Mostrar precio unitario: $ %.2f"
					"\n\n Diferencia: %.2f", kilometros, precioAerolineas,
					precioDebitoAerolineas, precioCreditoAerolineas,
					precioBtcAerolineas, precioPorKmAerolineas, precioLatam,
					precioDebitoLatam, precioCreditoLatam, precioBtcLatam,
					precioPorKmLatam, diferenciaPrecios);

			break;
		case 6:
			printf("Muchas gracias por utilizar nuestra plataforma");
			break;

		default:
			printf("esta opcion no es valida");

		}

	} while (opcion != 6);

	return EXIT_SUCCESS;
}
