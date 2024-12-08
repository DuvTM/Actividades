#include <studio.h>
#include <iostream>

int main ()
{
    int edad;
    std:: count << "Ingrese su edad: ";
    std:: cin >> edad ;

    if (edad >= 18) {
        std:: count << "Usted es mayor de edad" << std:: endl;
    } else {
        std:: count << "Usted es menor de edad" << std:: endl;
    }

    return 0;

}