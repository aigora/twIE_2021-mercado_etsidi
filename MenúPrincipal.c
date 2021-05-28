#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void MenuMercado();
void ImagenMercado();
void ImagenLetrero();
void Fecha();
void delay(int number_of_seconds);
void datosenvio(float pacumulado);

typedef struct //estructura para almacenar los datos de los ficheros de las secciones de la tienda
{
int orden;
char tipo[50];
char unidad_peso[5];
float peso;
float precio;
}productos;

typedef struct //estrutura para guardar los datos del usuario para realizar el pago y posterior envio
 {
char nombre[50];
char apellido[50];
long int telefono;
char direccion[100];
long int tarjeta;
float saldo;
}enviar;

int main()
{
productos tienda[20],tienda1[20],tienda2[20],tienda3[20];//vectores de la estructura "productos"
float coste, pacumulado=0;//diferenciamos entre precio que genera cada operacion y precio que lleva acumulado

int eleccion_operacion,eleccion_compra,cantidad,eleccion_productos,i,j,k,l,nproductos=0,nproductos1=0,nproductos2=0,nproductos3=0;//variables para los diferentes bucles utilizados
int deseo_operacion,nuevo_cliente,correcto=1;

FILE *charcuteria;//un puntero a fichero por cada tienda
FILE *panaderia;
FILE *pescaderia;
FILE *fruteria;
ImagenLetrero(); //Imagen principal que muestra el nombre de la tienda
printf("\033[2J");//codigo ANSI para limpiar la pantalla

                                               //APERTURA DE LOS FICHEROS DE LAS SECCIONES DE LA TIENDA EN MODO LECTURA
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
     pacumulado=0.0; //Para inicializar la cuenta total que va acumulando las compras
      do
        {
        do{
        ImagenMercado(); //Ilustracion de un supermercado que muestra la disposición de  las tiendas
        fflush(stdin);
        MenuMercado();//llamada a la función que muestra menú principal del mercado
        
        scanf ("%i",&eleccion_operacion);
        switch (eleccion_operacion)//switch-case para las 5 opciones que ofrece el menu principal
            {
                                                                                    //CHARCUTERIA
            case 1:
                do
                {
                    printf("\033[2J");//codigo ANSI para limpiar pantalla
                    printf("--------------------------------------\n");
                    printf("--------------CHARCUTERIA-------------");
                    printf(" ");
                    Fecha();
                    printf("\n--------------------------------------\n\n");
                    printf("Seleccione el producto deseado\n\n");
                    for(i=0;i<nproductos;i++)//bucle for que imprime la lista de productos
                        {
                        printf(" %d.-> %s\t\t%.2fg\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].peso,tienda[i].precio);
                        }

                    do
                    {
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
		    if(eleccion_productos<1 || eleccion_productos>nproductos)
                    	{
                        printf("\n\nERROR!! Seleccione una opcion valida\n\n");
                    	}
                    }while(eleccion_productos<1 || eleccion_productos>nproductos);//bucle do-while,si la elección no corresponde a una opción valida vuelve a preguntar

                    printf("\033[2J");
                    printf ("\n Usted ha elegido %s\n\n",tienda[eleccion_productos-1].tipo);//se imprime el producto seleccionado 
                    fflush(stdin);
                    printf (" Precio:%.2f euros\n\n",tienda[eleccion_productos-1].precio);//se imprime le precio del producto
                    printf (" Eliga la cantidad en unidades que desea comprar: ");
                    scanf ("%d",&cantidad);
                    coste=cantidad*tienda[eleccion_productos-1].precio;
                    printf ("\n La cantidad de es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n\n",pacumulado);//se acumula el precio total de la compra y se imprime

                    do
                    {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de charcuteria?\n\n");
                    printf (" 1.-Si\n\n");
                    printf (" 2.-No\n\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1) //Si el usuario responde distinto a lo que se pregunta, se volverá a repetir la pregunta
	            printf("\n Opcion Incorrecta\n");             //tantas veces como sea posible hasta que el usuario marque una de las opciones validas.
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );
                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//finaliza aqui el case 1
	    case 2:                                                                        //PESCADERIA
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

                     do
                    {
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
		    if(eleccion_productos<1 || eleccion_productos>nproductos1)
                   	 {
                        printf("\n\nERROR!! Seleccione una opcion valida\n\n");
                    	 }
                    }while(eleccion_productos<1 || eleccion_productos>nproductos1);

                    fflush(stdin);
                    printf("\033[2J");
                    printf (" \nUsted ha elegido %s\n\n",tienda1[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n\n",tienda1[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda1[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n\n",pacumulado);
                do
                {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de pescaderia?\n\n");
                    printf (" 1.-Si\n\n");
                    printf (" 2.-No\n\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n\n");
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );


                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//case2
                                                                                    //PANADERIA
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
                    for(k=0;k<nproductos2;k++)
                        {
                        printf(" %i.-%s\t\t%.2f euros\t\n",tienda2[k].orden,tienda2[k].tipo,tienda2[k].precio);
                        }
                     do
                    {
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
		    if(eleccion_productos<1 || eleccion_productos>nproductos2)
                    {
                        printf("\n\nERROR!! Seleccione una opcion valida\n\n");
                    }
                    }while(eleccion_productos<1 || eleccion_productos>nproductos2);

                    fflush(stdin);
                    printf("\033[2J");
                    printf (" \nUsted ha elegido %s\n\n",tienda2[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n\n",tienda2[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda2[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n\n",pacumulado);
                    do
                    {
                    fflush(stdin);
                    printf ("\n Desea comprar algo mas en la seccion de panaderia?\n\n");
                    printf (" 1.-Si\n\n");
                    printf (" 2.-No\n\n");
                    printf(" Respuesta: ");
                    scanf ("%i",&deseo_operacion);
                    if (deseo_operacion!=2 && deseo_operacion!=1)
                    printf("\n Opcion Incorrecta\n\n");
                    } while(deseo_operacion!=2 && deseo_operacion!=1 );

                    printf("\033[2J");
                }while(deseo_operacion!=2);
            break;//case3
                                                                                    //FRUTERIA
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
                     do
                    {
                    printf("\n Opcion seleccionada: ");
                    scanf("%d",&eleccion_productos);
		    if(eleccion_productos<1 || eleccion_productos>nproductos1)
                    {
                        printf("\n\nERROR!! Seleccione una opcion valida\n\n");
                    }
                    }while(eleccion_productos<1 || eleccion_productos>nproductos1);

                    fflush(stdin);
                    printf("\033[2J");
                    printf (" \nUsted ha elegido %s\n\n",tienda3[eleccion_productos-1].tipo);
                    printf (" Precio:%.2f euros\n\n",tienda3[eleccion_productos-1].precio);
                    printf (" Eliga la cantidad en unidades que desea comprar\n\n");
                    scanf ("%i",&cantidad);
                    coste=cantidad*tienda3[eleccion_productos-1].precio;
                    printf (" La cantidad a pagar es: %.2f\n\n",coste);
                    pacumulado += coste;
                    printf("La cantidad total de la compra es de %.2f\n\n",pacumulado);
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

            case 5: //Opcion salir del programa
                exit(-1);//funcion para finalizar proceso
            break;//case5

            }
            printf("\033[2J");
            if (eleccion_operacion>5 || eleccion_operacion<1)
            {
                printf ("ERROR!!! opcion no valida\n\n");       //Si el usuario no selecciona una de las opciones posibles le avisara de que no es valido.
                printf ("Introduce una opcion valida\n\n");
                delay (1.5);
            }
            else
                correcto=0;
            }while (correcto);

            //switch MENU MERCADO
                    do{
                    printf("\033[2J");
                    printf ("\n Desea seguir comprando en MERCADO ETSIDI?\n\n"); //Si el usuario responde distinto a lo que se pregunta, se volvera a repetir la pregunta
                    printf (" 1.-Si\n\n");                                       //tantas veces como sea posible hasta que el usuario marce una de las opciones posibles.
                    printf (" 2.-No\n\n");
                    printf (" Respuesta: ");
                    fflush(stdin);
                    scanf("%i",&eleccion_compra);
                    if (eleccion_compra!=2 && eleccion_compra!=1)
                    printf("\n Opcion Incorrecta.\n");
                    }while(eleccion_compra!=2 && eleccion_compra!=1);

            }while (eleccion_compra!=2);
    printf("\033[2J");
    printf("\n\n El precio total de su compra es de %.2f\n\n",pacumulado); //Precio total que el usuario ha ido acumulado a lo largo de su compra
    datosenvio (pacumulado);//llamada a la función de datos para el pago y posterior envio
    delay(1);
    printf("Compra realizada correctamente!!!! Su compra sera enviada");
    delay(1);
    printf("\n\n\nMuchas gracias por haber confiado en MercadoEtsidi.com, le esperamos de vuelta pronto!!!\n\n");
    delay(1.5);
    printf("\033[2J");
    printf ("Desea salir de la pagina de MERCADO ETSIDI?\n\n");//Pregunta para salir de la pagina o seguir comprando
    printf("1.-Si\n\n");
    printf("2.-No\n\n");
    scanf("%i",&nuevo_cliente);
}while(nuevo_cliente==2);
    return 0; //Finalizacion programa
}


                                                                                    //FUNCIONES

void MenuMercado()//funcion que imprime el menu principal de la tienda
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


//Imagen mercado
void ImagenMercado()
{
char c;
FILE *fd;
printf("\033[2J");
fd = fopen("ImagenMercadoEtsidi.txt", "r");//la imagen que muestra en pantalla corresponde a un letrero 
if (fd == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(fd,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(fd);
}

//Funcion que muestra el letrero con el nombre el mercado
void ImagenLetrero()
{
char c;
FILE *letrero;
printf("\033[2J");
letrero = fopen("letrero.txt", "r");//se abre el fichero que contiene el letrero en modo lectura
if (letrero == NULL)
{
printf("\nEl fichero no pudo ser abierto.");
}
while (fscanf(letrero,"%c",&c) != EOF)
printf ("%c",c);
printf("\n");
fclose(letrero);
delay(2);
}


//Muestra en pantalla  y pide los datos que necesita del usuario para poder finalizar su compra correctamente
void datosenvio(float pacumulado)
{
FILE *clientes;
enviar datos;
int eleccion_datos;

printf("Necesitamos sus datos para realizar la entrega\n\n");
    do{
	printf("\033[2J");
        printf("Introduzca su nombre separado con guiones (-):\n\n");
        scanf("%s",datos.nombre);
        printf("Introduzca sus apellidos separados con guiones (-):\n\n");
        scanf("%s",datos.apellido);
        printf("Introduzca un telefono de contacto:\n\n");
        scanf("%li",&datos.telefono);
        printf("Introduzca la direccion del envio separado con guiones (-):\n\n");
        scanf("%s",datos.direccion);
        printf("Introduzca el numero de su Tarjeta de credito:\n\n");
        scanf("%li",&datos.tarjeta);
        do{
        printf ("Introduzca el saldo de su tarjeta de credito:\n\n");
        scanf("%f",&datos.saldo);
        clientes = fopen("usuarios.txt","w");//Apertura de fichero en modo escritura para guardar los datos del cliente
        if (clientes == NULL)
            {
            printf("Error al abrir el fichero.\n");
            }
        else
            {
            fprintf(clientes,"Nombre:%s\n Apellido: %s\n Telefono:%li\n Direccion:%s\n Tarjeta:%li\n Saldo:%f\n ",datos.nombre,datos.apellido,datos.telefono,datos.direccion,datos.tarjeta,datos.saldo );
            fclose(clientes);
            }
	delay (1);
	printf("\033[2J");
        printf("Muchas gracias: %s %s \n\n",datos.nombre,datos.apellido);
        printf("El envio se realizara a la direccion: %s\n\n",datos.direccion);
        printf("Para cualquier informacion lo llamaremos al numero: %li\n\n",datos.telefono);
        printf("Son estos datos correctos?\n\n");
        printf("1.-Si\n\n");
        printf("2.-No\n\n");
        scanf ("%i",&eleccion_datos);
        delay (1);
	if (datos.saldo<pacumulado)
        {
         printf ("No tiene saldo suficiente!!\n\n");
        }
        }while (datos.saldo<pacumulado);


    }while (eleccion_datos==2);
}

//Funcion para mostrar la hora en pantalla
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

void delay(int number_of_seconds)//añade una pequeña pausa al igual que lo haria "sleep"
{

int milli_seconds = 1000 * number_of_seconds;

clock_t start_time = clock();

while (clock() < start_time + milli_seconds);
}
