/******************************************************************************

Actividad 1

*******************************************************************************/
#include <iostream>
#include <stdio.h>

int main ()
{
	int edad;
	std::cout << "Ingrese su edad: ";
	std::cin >> edad ;

	if (edad >= 18) {
		std::cout << "Usted es mayor de edad" << std:: endl;
	} else {
		std::cout << "Usted es menor de edad" << std:: endl;
	}

	return 0;

}