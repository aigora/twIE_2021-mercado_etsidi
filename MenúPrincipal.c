#include <stdio.h>

int main()
{
  char elige;
  printf("Bienvenido a Mercado etsidi: \n\nComo desea comprar? \n\nEliga entre:\n\nOpcion (A): Visitar pagina web. \n\nOpcion (B): Llamada a domicilio.\n\n");
  scanf("%c", &elige);

  switch(elige)
    {
    case 'A':
    case 'a':
       system("cls");
        printf("Visitar pagina web\n\n");
        printf ("Elige la seccion en la que deseas comprar\n\n");
        printf ("1.- Charcuteria.\n\n");
        printf ("2.- Pescaderia.\n\n");
        printf ("3.- Panaderia.\n\n");
        printf ("4.- Herbolario.\n\n");
        printf ("5.- Fruteria.\n\n");
      break;
    case 'B':
    case 'b':
    	system("cls");
        printf("Llamada a domicilio\n");
        printf ("Elige la seccion en la que deseas comprar\n\n");
        printf ("1.- Charcuteria.\n\n");
        printf ("2.- Pescaderia.\n\n");
        printf ("3.- Panaderia.\n\n");
        printf ("4.- Herbolario.\n\n");
        printf ("5.- Fruteria.\n\n");
      break;

    default:
      printf("Vuelva a introducir una opcion\n");
    }
  return 0;
  }
