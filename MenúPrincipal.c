#include <stdio.h>
#include <stdlib.h>
void menu_principal();
typedef struct
{
	int orden;
	char tipo[50];
	float peso;
	float precio;
}productos;

int main()
{
  productos tienda[20];
  char elije,eleccion_productos,deseo_compra,sub,charc,pana,pesca,frut;
  float coste,descu,iva,total=0,pago_total,pago_introducido,vuelta;
  int eleccion_operacion,deseo_operacion,nproductos=0,op2,p=1,i,orden[20];
  FILE *submenu;
  FILE *charcuteria;
  FILE *panaderia;
  FILE *pescaderia;
  FILE *fruteria;

  system("Color e");
  menu_principal();
  scanf ("%c",&elije);
        switch (elije)
            {
            case 'a':
            case 'A':
                do{
                    system("cls");
                    printf("--------------------------------------\n");
                    printf("----------MERCADO ETSIDI.COM----------\n");
                    printf("--------------------------------------\n\n");
                    printf("Seleccione una seccion\n");
                    printf("1.-Charcuteria\n");
                    printf("2.-Pescaderia\n");
                    printf("3.-Panaderia\n");
                    printf("4.-Fruteria\n");
                    scanf ("%i",&eleccion_operacion);
                    if (eleccion_operacion==1){
                            charcuteria = fopen("charcuteria.txt","r");
                            if (charcuteria == NULL)
                            {
                            printf("No se encuentra el fichero\n");
                                return -1;
                            }
                        while(fscanf(charcuteria, "%s %f %f",tienda[nproductos].tipo,&tienda[nproductos].peso,&tienda[nproductos].precio)!=EOF)
                            {
                        nproductos++;
                            }
                            fclose(charcuteria);
                            system("cls");
                            printf("--------------------------------------\n");
                            printf("--------------CHARCUTERIA-------------\n");
                            printf("--------------------------------------\n\n");
                            printf("Seleccione el producto deseado\n\n");
                            do{

                                for(i=0;i<nproductos;i++){
                                printf("%i.-%s\t\t%.2fg\t\t%.2f euro\t\n",p++,tienda[i].tipo,tienda[i].peso,tienda[i].precio);
                                }
                                printf("13.-Volver\n");
                                fflush(stdin);
                                scanf("%c",&eleccion_productos);
                                system("cls");
                                if (eleccion_productos == 1){
                                coste+=tienda[0].precio;
                                    }
                                else if(eleccion_productos == 2){
                                coste+=tienda[1].precio;
                                    }
                                else if(eleccion_productos == 3){
                                coste+=tienda[2].precio;
                                    }
                                else if(eleccion_productos == 4){
                                coste+=tienda[3].precio;
                                    }
                                else if(eleccion_productos == 5){
                                coste+=tienda[4].precio;
                                    }
                                else if(eleccion_productos == 6){
                                coste+=tienda[5].precio;
                                    }
                                else if(eleccion_productos == 7){
                                coste+=tienda[6].precio;
                                    }
                                else if(eleccion_productos == 8){
                                coste+=tienda[7].precio;
                                    }
                                else if(eleccion_productos == 9){
                                coste+=tienda[8].precio;
                                    }
                                else if(eleccion_productos == 10){
                                coste+=tienda[9].precio;
                                    }
                                else if(eleccion_productos == 11){
                                coste+=tienda[10].precio;
                                    }
                                else if(eleccion_productos == 12){
                                coste+=tienda[11].precio;
                                    }
                                else if(eleccion_productos == 13){
                                break;
                                    }
                                else{
                                printf("Esa opcion no corresponde a ningun producto\nSeleccione otro producto\n");
                                    }
                                fflush(stdin);
                                printf("Desea comprar algun otro producto?\n");
                                printf("1.-Si");
                                printf("2.-No");
                                scanf("%c",&deseo_compra);
                                system("cls");
                              }while (deseo_compra != 2);

                                if(coste==0){
                                printf("No has comprado nada\n");
                                }else{
                                while(pago_total<coste){
                                printf("Cantidad a pagar: %.2f\n",coste-pago_total);
                                fflush(stdin);
                                printf ("Introduzca la cantidad:\n");
                                scanf("%f",&pago_introducido);
                                pago_total+=pago_introducido;
                                system("cls");
                                            }
                                vuelta=pago_total-coste;
                                printf("Su vuelta es: %.2f\n",vuelta);
                                break;
                                }
                                }



                printf("Desea realizar alguna otra operacion?\n");
                printf ("1.-Si");
                printf ("2.-No");
                fflush(stdin);
                scanf("%i",&deseo_operacion);
                system("cls");
                }while(deseo_operacion !=2) ;



            }
 return 0;
}


void menu_principal()
{
  char p;
  FILE *pf;
  pf = fopen("letrero.txt", "r");
  while (fscanf(pf, "%c", &p) != EOF)
  printf ("%c",p);
  printf("Bienvenido a Mercado etsidi: \n\nComo desea comprar? \n\nEliga entre:\n\nOpcion (A): Visitar pagina web. \n\nOpcion (B): Llamada a domicilio.\n\n");
}


