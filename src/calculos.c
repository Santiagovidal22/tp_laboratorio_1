/*
 * CALCULOS.C
 *
 *  Created on: 14 abr. 2022
 *      Author: Pc
 */

#include <stdio.h>
#include <stdlib.h>

float valorDebito(float precio)
{
	float precioDebito;

	precioDebito= precio - ((float)precio *0.10);

	return precioDebito;
}
float valorCredito(float precio)
{
	float precioCredito;

	precioCredito= precio + ((float) precio * 0.25);

	return precioCredito;

}

float valorBtc (float precio)

{
	float precioBtc;

	precioBtc= (float)precio / 4606954.55;

	return precioBtc;
}

float precioPorKm (float precio, int kilometros)

{
	float precioKm;

	precioKm= (float) precio / kilometros;

	return precioKm;

}

float diferenciaPrecio (float precioLatam, float precioAerolineas)
{
	float diferenciaPrecios;
	if(precioLatam > precioAerolineas)
	{
		diferenciaPrecios= precioLatam - precioAerolineas;
	}

	else
	{
		diferenciaPrecios= precioAerolineas - precioLatam;

	}

	return diferenciaPrecios;
}
