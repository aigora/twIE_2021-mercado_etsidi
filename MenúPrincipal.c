#include <stdio.h>
#include <stdlib.h>
void menu_principal();
void pagina_web();
typedef struct
{
	int orden;
	char tipo[50];
	char unidad_peso[5];
	float peso;
	float precio;
}productos;

int main()
{
  productos tienda[20];
  char elije;
  float coste;
  int eleccion_operacion,deseo_operacion,eleccion_compra,cantidad,eleccion_productos,i,nproductos=0;
  FILE *charcuteria;
  FILE *panaderia;
  FILE *pescaderia;
  FILE *fruteria;

  system("Color e");
  menu_principal();
                do{
                    system("cls");
                    pagina_web();
                    scanf ("%i",&eleccion_operacion);
                            if (eleccion_operacion==1){
                                charcuteria = fopen("charcuteria.txt","r");
                                if (charcuteria == NULL){
                                    printf("Error al abrir el archivo destino.\n");
                                    return -1;
                                }
                                while(fscanf(charcuteria, "%i %s %f %f",&tienda[nproductos].orden,tienda[nproductos].tipo,&tienda[nproductos].peso,&tienda[nproductos].precio)!=EOF)
                                        {
                                    nproductos++;
                                        }
                                fclose(charcuteria);
                                do{
                                system("cls");
                                printf("--------------------------------------\n");
                                printf("--------------CHARCUTERIA-------------\n");
                                printf("--------------------------------------\n\n");
                                printf("Seleccione el producto deseado\n\n");
                                for(i=0;i<nproductos;i++){
                                printf("%i.-%s\t\t%.2fg\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].peso,tienda[i].precio);
                                        }
                                fflush(stdin);
                                scanf("%i",&eleccion_productos);
                                if (eleccion_productos == 1){
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[0].tipo);
                                printf ("Precio:%.2f euros\n",tienda[0].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[0].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==2)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[1].tipo);
                                printf ("Precio:%.2f euros\n",tienda[1].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[1].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==3)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[2].tipo);
                                printf ("Precio:%.2f euros\n",tienda[2].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[2].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==4)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[3].tipo);
                                printf ("Precio:%.2f euros\n",tienda[3].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[3].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==5)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[4].tipo);
                                printf ("Precio:%.2f euros\n",tienda[4].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[4].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==6)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[5].tipo);
                                printf ("Precio:%.2f euros\n",tienda[5].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[5].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==7)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[6].tipo);
                                printf ("Precio:%.2f euros\n",tienda[6].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[6].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==8)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[7].tipo);
                                printf ("Precio:%.2f euros\n",tienda[7].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[7].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==9)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[8].tipo);
                                printf ("Precio:%.2f euros\n",tienda[8].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[8].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==10)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[9].tipo);
                                printf ("Precio:%.2f euros\n",tienda[9].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[9].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==11)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[10].tipo);
                                printf ("Precio:%.2f euros\n",tienda[10].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[10].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==12)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[11].tipo);
                                printf ("Precio:%.2f euros\n",tienda[11].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[11].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else
                                {
                                    printf ("La opcion no es valida..\n");
                                }
                                fflush(stdin);
                                printf ("Desea comprar algo mas en la seccion de charcuteria?\n");
                                printf ("1.-Si\n");
                                printf ("2.-No\n");
                                scanf ("%i",&deseo_operacion);
                                system("cls");
                                }while (deseo_operacion!=2);
                            }else if (eleccion_operacion==2)
                            {
                                pescaderia = fopen("pescaderia.txt","r");
                                while(fscanf(pescaderia, "%i %s %f %s %f",&tienda[nproductos].orden,tienda[nproductos].tipo,&tienda[nproductos].peso,tienda[nproductos].unidad_peso,&tienda[nproductos].precio)!=EOF)
                                        {
                                    nproductos++;
                                        }
                                fclose(pescaderia);
                                do{
                                system("cls");
                                printf("--------------------------------------\n");
                                printf("--------------PESCADERIA--------------\n");
                                printf("--------------------------------------\n\n");
                                printf("Seleccione el producto deseado\n\n");
                                for(i=0;i<nproductos;i++){
                                printf("%i.-%s\t\t%.2f\t%s\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].peso,tienda[i].unidad_peso,tienda[i].precio);

                                        }
                                fflush(stdin);
                                scanf("%i",&eleccion_productos);
                                if (eleccion_productos == 1){
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[0].tipo);
                                printf ("Precio:%.2f euros\n",tienda[0].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[0].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==2)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[1].tipo);
                                printf ("Precio:%.2f euros\n",tienda[1].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[1].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==3)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[2].tipo);
                                printf ("Precio:%.2f euros\n",tienda[2].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[2].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==4)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[3].tipo);
                                printf ("Precio:%.2f euros\n",tienda[3].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[3].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==5)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[4].tipo);
                                printf ("Precio:%.2f euros\n",tienda[4].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[4].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==6)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[5].tipo);
                                printf ("Precio:%.2f euros\n",tienda[5].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[5].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==7)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[6].tipo);
                                printf ("Precio:%.2f euros\n",tienda[6].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[6].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==8)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[7].tipo);
                                printf ("Precio:%.2f euros\n",tienda[7].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[7].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==9)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[8].tipo);
                                printf ("Precio:%.2f euros\n",tienda[8].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[8].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==10)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[9].tipo);
                                printf ("Precio:%.2f euros\n",tienda[9].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[9].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==11)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[10].tipo);
                                printf ("Precio:%.2f euros\n",tienda[10].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[10].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==12)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[11].tipo);
                                printf ("Precio:%.2f euros\n",tienda[11].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[11].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else
                                {
                                    printf ("La opcion no es valida..\n");
                                }
                                fflush(stdin);
                                printf ("Desea comprar algo mas en la seccion de pescaderia?\n");
                                printf ("1.-Si\n");
                                printf ("2.-No\n");
                                scanf ("%i",&deseo_operacion);
                                system("cls");
                                }while (deseo_operacion!=2);
                            }else if (eleccion_operacion==3)
                            {
                                panaderia = fopen("panaderia.txt","r");
                                while(fscanf(panaderia, "%i %s %f",&tienda[nproductos].orden,tienda[nproductos].tipo,&tienda[nproductos].precio)!=EOF)
                                        {
                                    nproductos++;
                                        }
                                fclose(panaderia);
                                do{
                                system("cls");
                                printf("--------------------------------------\n");
                                printf("--------------PANADERIA---------------\n");
                                printf("--------------------------------------\n\n");
                                printf("Seleccione el producto deseado\n\n");
                                for(i=0;i<nproductos;i++){
                                printf("%i.-%s\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].precio);

                                        }
                                fflush(stdin);
                                scanf("%i",&eleccion_productos);
                                if (eleccion_productos == 1){
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[0].tipo);
                                printf ("Precio:%.2f euros\n",tienda[0].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[0].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==2)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[1].tipo);
                                printf ("Precio:%.2f euros\n",tienda[1].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[1].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==3)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[2].tipo);
                                printf ("Precio:%.2f euros\n",tienda[2].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[2].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==4)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[3].tipo);
                                printf ("Precio:%.2f euros\n",tienda[3].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[3].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==5)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[4].tipo);
                                printf ("Precio:%.2f euros\n",tienda[4].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[4].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==6)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[5].tipo);
                                printf ("Precio:%.2f euros\n",tienda[5].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[5].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==7)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[6].tipo);
                                printf ("Precio:%.2f euros\n",tienda[6].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[6].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==8)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[7].tipo);
                                printf ("Precio:%.2f euros\n",tienda[7].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[7].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==9)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[8].tipo);
                                printf ("Precio:%.2f euros\n",tienda[8].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[8].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==10)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[9].tipo);
                                printf ("Precio:%.2f euros\n",tienda[9].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[9].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==11)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[10].tipo);
                                printf ("Precio:%.2f euros\n",tienda[10].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[10].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==12)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[11].tipo);
                                printf ("Precio:%.2f euros\n",tienda[11].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[11].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else
                                {
                                    printf ("La opcion no es valida..\n");
                                }
                                fflush(stdin);
                                printf ("Desea comprar algo mas en la seccion de panaderia?\n");
                                printf ("1.-Si\n");
                                printf ("2.-No\n");
                                scanf ("%i",&deseo_operacion);
                                system("cls");
                                }while (deseo_operacion!=2);
                            }else if(eleccion_operacion==4)
                            {
                                fruteria = fopen("fruteria.txt","r");
                                while(fscanf(fruteria, "%i %s %f %f",&tienda[nproductos].orden,tienda[nproductos].tipo,&tienda[nproductos].peso,&tienda[nproductos].precio)!=EOF)
                                        {
                                    nproductos++;
                                        }
                                fclose(fruteria);
                                do{
                                system("cls");
                                printf("--------------------------------------\n");
                                printf("---------------FRUTERIA---------------\n");
                                printf("--------------------------------------\n\n");
                                printf("Seleccione el producto deseado\n\n");
                                for(i=0;i<nproductos;i++){
                                printf("%i.-%s\t\t%.2f Kg\t\t%.2f euros\t\n",tienda[i].orden,tienda[i].tipo,tienda[i].peso,tienda[i].precio);
                                        }
                                fflush(stdin);
                                scanf("%i",&eleccion_productos);
                                if (eleccion_productos == 1){
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[0].tipo);
                                printf ("Precio:%.2f euros\n",tienda[0].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[0].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==2)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[1].tipo);
                                printf ("Precio:%.2f euros\n",tienda[1].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[1].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==3)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[2].tipo);
                                printf ("Precio:%.2f euros\n",tienda[2].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[2].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==4)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[3].tipo);
                                printf ("Precio:%.2f euros\n",tienda[3].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[3].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==5)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[4].tipo);
                                printf ("Precio:%.2f euros\n",tienda[4].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[4].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==6)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[5].tipo);
                                printf ("Precio:%.2f euros\n",tienda[5].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[5].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==7)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[6].tipo);
                                printf ("Precio:%.2f euros\n",tienda[6].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[6].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==8)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[7].tipo);
                                printf ("Precio:%.2f euros\n",tienda[7].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[7].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==9)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[8].tipo);
                                printf ("Precio:%.2f euros\n",tienda[8].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[8].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==10)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[9].tipo);
                                printf ("Precio:%.2f euros\n",tienda[9].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[9].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==11)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[10].tipo);
                                printf ("Precio:%.2f euros\n",tienda[10].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[10].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else if (eleccion_productos==12)
                                {
                                system("cls");
                                printf ("Usted ha elegido %s\n",tienda[11].tipo);
                                printf ("Precio:%.2f euros\n",tienda[11].precio);
                                printf ("Eliga la cantidad en unidades que desea comprar\n");
                                scanf ("%i",&cantidad);
                                coste=cantidad*tienda[11].precio;
                                printf ("La cantidad a pagar es: %.2f\n",coste);
                                }else
                                {
                                    printf ("La opcion no es valida..\n");
                                }
                                fflush(stdin);
                                printf ("Desea comprar algo mas en la seccion de charcuteria?\n\n");
                                printf ("1.-Si\n");
                                printf ("2.-No\n");
                                scanf ("%i",&deseo_operacion);
                                system("cls");
                                }while (deseo_operacion!=2);
                            }

                            printf ("Desea comprar en otra seccion del MERCADO ETSIDI\n\n");
                            printf ("1.-Si\n\n");
                            printf ("2.-No\n\n");
                            scanf("%i",&eleccion_compra);
                            fflush(stdin);
                            }while (eleccion_compra!=2);
 return 0;
}


void menu_principal()
{
  char p;
  FILE *pf;
  pf = fopen("letrero.txt", "r");
  while (fscanf(pf, "%c", &p) != EOF)
  printf ("%c",p);
  system("color E0");
  Sleep(2000);
}
void pagina_web()
{
    char c;
    FILE *fd;

	system ("cls");
	system ("color E0");

	fd = fopen("ImagenMercadoEtsidi.txt", "r");

	if (fd == NULL)
    {
	  printf("\nEl fichero no pudo ser abierto.");
    }
	while (fscanf(fd,"%c",&c) != EOF)
    printf ("%c",c);
	printf("\n");
	printf("\t\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t\t-------------MERCADO ETSIDI.COM----------\n");
    printf("\t\t\t\t\t-----------------------------------------\n\n");
	printf ("\t\t\t\t\t\t     1.-Charcuteria\n\n");
	printf ("\t\t\t\t\t\t     2.-Pescaderia\n\n");
	printf ("\t\t\t\t\t\t     3.-Panaderia\n\n");
	printf ("\t\t\t\t\t\t     4.-Fruteria\n\n");
	printf ("\t\t\t\t\t\t     Elige una opcion\n\n");
}


