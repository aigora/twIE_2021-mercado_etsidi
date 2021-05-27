#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void MenuMercado();
void ImagenMercado();
void ImagenLetrero();
void Fecha(); //Funcion para mostrar la hora en pantalla
void delay(int number_of_seconds);
void datosenvio(float pacumulado);

typedef struct
{
int orden;
char tipo[50];
char unidad_peso[5];
float peso;
float precio;
}productos;

typedef struct {
char nombre[50];
char apellido[50];
int telefono;
char direccion[100];
int tarjeta;
float saldo;
}enviar;

int main()
{
productos tienda[20],tienda1[20],tienda2[20],tienda3[20];
float coste, pacumulado=0;
int eleccion_operacion,eleccion_compra,cantidad,eleccion_productos,i,j,k,l,nproductos=0,nproductos1=0,nproductos2=0,nproductos3=0;
int deseo_operacion,nuevo_cliente,correcto=1;
FILE *charcuteria;
FILE *panaderia;
FILE *pescaderia;
FILE *fruteria;
ImagenLetrero(); //Imagen principal
printf("\033[2J");
//LECTURA DE FICHEROS DE DATOS
charcuteria = fopen("charcuteria.txt","r");
    if (charcuteria == NULL)
    {
    printf("Error al abrir el archivo destino.\n");
    return -1;
    }else
    {
        while(fscanf(charcuteria, "%i %s %f %f",&tienda[nproductos].orden,tienda[nproductos].tipo,&tienda[nproductos].peso,&tienda[nproductos].precio)!=EOF)
            {
            nproductos++;
            }
        fclose(charcuteria);
    }



    pescaderia = fopen("pescaderia.txt","r");
    if (pescaderia == NULL)
    {
    printf("Error al abrir el archivo destino.\n");
    return -2;
    }else
    {
        while(fscanf(pescaderia, "%i %s %f %s %f",&tienda1[nproductos1].orden,tienda1[nproductos1].tipo,&tienda1[nproductos1].peso,tienda1[nproductos1].unidad_peso,&tienda1[nproductos1].precio)!=EOF)
        {
        nproductos1++;
        }
        fclose(pescaderia);
    }



    panaderia = fopen("panaderia.txt","r");
    if (panaderia == NULL)
    {
    printf("Error al abrir el archivo destino.\n");
    return -3;
    }else
    {
        while(fscanf(panaderia, "%i %s %f",&tienda2[nproductos2].orden,tienda2[nproductos2].tipo,&tienda2[nproductos2].precio)!=EOF)
        {
        nproductos2++;
        }
        fclose(panaderia);
    }
    fruteria = fopen("fruteria.txt","r");
    if (fruteria == NULL)
    {
    printf("Error al abrir el archivo destino.\n");
    return -4;
    }else
    {
        while(fscanf(fruteria, "%i %s %f %f",&tienda3[nproductos3].orden,tienda3[nproductos3].tipo,&tienda3[nproductos3].peso,&tienda3[nproductos3].precio)!=EOF)
        {
        nproductos3++;
        }
        fclose(fruteria);
    }
    do{
      do
        {
        ImagenMercado(); //Imagen Mercado Etsidi
        fflush(stdin);
        do{
        MenuMercado();
        scanf ("%i",&eleccion_operacion);
        switch (eleccion_operacion)
            {
        /////////////////////////////////////////////////CHARCUTERIA///////////////////////////////////////////////////////////////////////////////
            case 1:
                do
                {
                    printf("\033[2J");
                    printf("--------------------------------------\n");
                    printf("--------------CHARCUTERIA-------------");
                    printf(" ");
                    Fecha();
                    printf("\n--------------------------------------\n\n");
                    printf("Seleccione el producto deseado\n\n");
                    for(i=0;i<nproductos;i++)
                        {
                        printf(" %d.-> %s\t\t%.2fg\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].peso,tienda[i].precio);
                        }

                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
                    fflush(stdin);
                    printf ("\n Usted ha elegido %s\n",tienda[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n",tienda[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar: ");
                    scanf ("%d",&cantidad);
                    coste=cantidad*tienda[eleccion_productos-1].precio;
                    printf ("\n La cantidad de es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n",pacumulado);
                    do
                    {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de charcuteria?\n");
                    printf (" 1.-Si\n");
                    printf (" 2.-No\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n");

                    } while(deseo_operacion!=2 && deseo_operacion!=1 );
                    printf("\033[2J");
                }while(deseo_operacion!=2);///////////
            break;//case 1
        /////////////////////////////////////////////////PESCADERIA///////////////////////////////////////////////////////////////////////////////
            case 2:
                do
                {
                    printf("\033[2J");
                    printf("--------------------------------------\n");
                    printf("--------------PESCADERIA-------------");
                    printf(" ");
                    Fecha();
                    printf("\n--------------------------------------\n\n");
                    printf(" Seleccione el producto deseado\n\n");
                    for(j=0;j<nproductos1;j++)
                        {
                        printf(" %i.-%s\t\t%.2f\t%s\t\t%.2f euros\t\n",tienda1[j].orden,tienda1[j].tipo,tienda1[j].peso,tienda1[j].unidad_peso,tienda1[j].precio);
                        }

                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
                    fflush(stdin);
                    printf (" Usted ha elegido %s\n",tienda1[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n",tienda1[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda1[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n",pacumulado);
                do
                {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de pescaderia?\n");
                    printf (" 1.-Si\n");
                    printf (" 2.-No\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n");
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );


                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//case 2
        /////////////////////////////////////////////////PANADERIA///////////////////////////////////////////////////////////////////////////////
            case 3:
                do
                {
                    printf("\033[2J");
                    printf("--------------------------------------\n");
                    printf("--------------PANADERIA-------------");
                    printf(" ");
                    Fecha();
                    printf("\n--------------------------------------\n\n");
                    printf(" Seleccione el producto deseado\n\n");
                    for(k=0;k<=nproductos2;k++)
                        {
                        printf(" %i.-%s\t\t%.2f euros\t\n",tienda2[k].orden,tienda2[k].tipo,tienda2[k].precio);
                        }
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
                    fflush(stdin);
                    printf (" Usted ha elegido %s\n",tienda2[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n",tienda2[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda2[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n",pacumulado);
                    do
                    {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de panaderia?\n");
                    printf (" 1.-Si\n");
                    printf (" 2.-No\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n");
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );

                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//case 3
        /////////////////////////////////////////////////FRUTERIA///////////////////////////////////////////////////////////////////////////////
            case 4:
                do
                {
                    printf("\033[2J");
                    printf("--------------------------------------\n");
                    printf("--------------FRUTERIA-------------");
                    printf(" ");
                    Fecha();
                    printf("\n--------------------------------------\n\n");
                    printf(" Seleccione el producto deseado\n\n");
                    for(l=0;l<=nproductos;l++)
                        {
                        printf(" %i.-%s\t\t%.2f Kg\t\t%.2f euros\t\n",tienda3[l].orden,tienda3[l].tipo,tienda3[l].peso,tienda3[l].precio);
                        }
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
                    fflush(stdin);
                    printf (" Usted ha elegido %s\n",tienda3[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n",tienda3[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda3[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n",pacumulado);
                    do
                        {
                    fflush(stdin);
                    printf ("\nDesea comprar algo mas en la seccion de fruteria?\n\n");
                    printf (" 1.-Si\n\n");
                    printf (" 2.-No\n\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n");
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );
                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//case4
            case 5:
                exit(-1);
            break;

            }
            printf("\033[2J");
            if (eleccion_operacion>5 || eleccion_operacion<1)
            {
                printf ("ERROR!!! opcion no valida\n\n");
                printf ("Introduce una opcion valida\n\n");
            }
            else
                correcto=0;
            }while (correcto);

            //switch MENU MERCADO
                    do{
                    printf ("\n Desea seguir comprando en MERCADO ETSIDI?\n\n");
                    printf (" 1.-Si\n\n");
                    printf (" 2.-No\n\n");
                    printf (" Respuesta: ");
                    fflush(stdin);
                    scanf("%i",&eleccion_compra);
                    if (eleccion_compra!=2 && eleccion_compra!=1)
                    printf("\n Opcion Incorrecta.\n");
                    }while(eleccion_compra!=2 && eleccion_compra!=1);

            }while (eleccion_compra!=2);
    printf("\n\n El precio total de su compra es de %.2f\n\n",pacumulado);
    datosenvio (pacumulado);
    delay(1);
    printf("Compra realizada correctamente!!!!");
    printf("\n\n\nMuchas gracias por haber confiado en MercadoEtsidi.com, le esperamos de vuelta pronto!!!\n\n");
    delay(1);
    printf ("Desea salir de la pagina de MERCADO ETSIDI?\n\n");
    printf("1.-Si\n\n");
    printf("2.-No\n\n");
    scanf("%i",&nuevo_cliente);

}while(nuevo_cliente==2);
    return 0;
}




void MenuMercado()
{
printf("\t\t\t\t\t-----------------------------------------\n");
printf("\t\t\t\t\t-------------MERCADO ETSIDI.COM----------\n");
printf("\t\t\t\t\t-----------------------------------------\n\n");
Fecha();
printf("\n");
printf ("\t\t\t\t\t\t 1.-Charcuteria\n\n");
printf ("\t\t\t\t\t\t 2.-Pescaderia\n\n");
printf ("\t\t\t\t\t\t 3.-Panaderia\n\n");
printf ("\t\t\t\t\t\t 4.-Fruteria\n\n");
printf ("\t\t\t\t\t\t 5.-Salir del programa\n\n");
printf ("\t\t\t\t\t\t Elige una opcion: ");
}



void ImagenMercado()
{
char c;
FILE *fd;
printf("\033[2J");
fd = fopen("ImagenMercadoEtsidi.txt", "r");
if (fd == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(fd,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(fd);
}

void ImagenLetrero()
{
char c;
FILE *letrero;
printf("\033[2J");
letrero = fopen("letrero.txt", "r");
if (letrero == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(letrero,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(letrero);
delay(1);
}



void datosenvio(float pacumulado)
{
FILE *clientes;
enviar datos;
int eleccion_datos;

printf("Necesitamos sus datos para realizar la entrega\n\n");
    do{
        printf("Introduzca su nombre separado con guiones (-):\n\n");
        scanf("%s",datos.nombre);
        printf("Introduzca sus apellidos separados con guiones (-):\n\n");
        scanf("%s",datos.apellido);
        printf("Introduzca un telefono de contacto:\n\n");
        scanf("%d",&datos.telefono);
        printf("Introduzca la direccion del envio separado con guiones (-):\n\n");
        scanf("%s",datos.direccion);
        printf("Introduzca el numero de su Tarjeta de credito:\n\n");
        scanf("%i",&datos.tarjeta);
        do{
        printf ("Introduzca el saldo de su tarjeta de credito:\n\n");
        scanf("%f",&datos.saldo);
        clientes = fopen("usuarios.txt","w");
        if (clientes == NULL)
            {
            printf("Error al abrir el fichero.\n");
            }
        else
            {
            fprintf(clientes,"Nombre:%s\n Apellido: %s\n Telefono:%i\n Direccion:%s\n Tarjeta:%i\n Saldo:%f\n ",datos.nombre,datos.apellido,datos.telefono,datos.direccion,datos.tarjeta,datos.saldo );
            fclose(clientes);
            }

        printf("Muchas gracias: %s %s \n\n",datos.nombre,datos.apellido);
        printf("El envio se realizara a la direccion: %s\n\n",datos.direccion);
        printf("Para cualquier informacion lo llamaremos al numero: %i\n\n",datos.telefono);
        printf("Son estos datos correctos?\n\n");
        printf("1.-Si\n\n");
        printf("2.-No\n\n");
        scanf ("%i",&eleccion_datos);
        delay (1);
        }while (datos.saldo<pacumulado);
        if (datos.saldo<pacumulado)
        {
         printf ("No tiene saldo suficiente!!\n\n");
        }

    }while (eleccion_datos==2);
}

void Fecha()
{
time_t t;
struct tm *tm;
char fecha_dia[100];

t = time(NULL);

tm = localtime(&t);
strftime(fecha_dia, 100, "%d/%m/%Y", tm);
printf(" Fecha actual: %s", fecha_dia);
}

void delay(int number_of_seconds)
{

int milli_seconds = 1000 * number_of_seconds;

clock_t start_time = clock();

while (clock() < start_time + milli_seconds);
}
