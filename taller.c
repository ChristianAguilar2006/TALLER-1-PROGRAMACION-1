#include <stdio.h>
#include <string.h>

int main() {
    int id;
    char nombre[15];
    int stock;
    float precio;
    int seguir = 1;
    int opcion;
    int VenderUnidades;
    float Ganancias = 0;
    int reabastecer; 
    int totalUnidades = 0;
    float totalGanancias = 0;
    float PrecioDescuento;

    printf("\nIngresar datos\n");

    printf("\n Ingrese el id del PRODUCTO: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    printf("\n Ingrese el NOMBRE: ");
    fgets(nombre, 15, stdin);
    strtok(nombre, "\n");

    printf("\n Ingrese el precio: ");
    scanf("%f", &precio);

    printf("\n Ingrese la cantidad de STOCK: ");
    scanf("%d", &stock);
    
    while (seguir) {
        printf("\n1) Vender unidades\n");
        printf("2) Reabastecer Productos\n");
        printf("3) Consultar informacion del producto\n");
        printf("4) Calcular y mostrar informacion de ventas\n");
        printf("5) Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n Ingrese cuantas unidades va a vender: ");
                scanf("%d", &VenderUnidades);

                while (VenderUnidades > stock || VenderUnidades <= 0) {
                    printf("\n No hay suficientes unidades para vender.");
                    printf("\n Ingrese una cantidad DISPONIBLE o VALIDA: ");
                    scanf("%d", &VenderUnidades);
                }

                totalUnidades += VenderUnidades;
                stock -= VenderUnidades;

                if (VenderUnidades >= 5) {
                    PrecioDescuento = precio * 0.9; 
                } else {
                    PrecioDescuento = precio; 
                }

                Ganancias = VenderUnidades * PrecioDescuento;
                totalGanancias += Ganancias;

                printf("\n Vendidos con exito");
                break;

            case 2:
                if (id == 0 || strlen(nombre) == 0 || precio == 0 || stock == 0) {
                    printf("\n No hay productos registrados\n");
                    break;
                }
                printf("\n Ingrese la cantidad de unidades a reabastecer: ");
                scanf("%d", &reabastecer);
                stock += reabastecer;
                break;

            case 3:
                printf("\n Informacion del producto:\n");
                printf(" Nombre: %s\n", nombre);
                printf(" ID: %d\n", id);
                printf(" Cantidad de %s: %d\n", nombre, stock);
                printf(" Precio de %s: %.2f\n", nombre, precio);
                break;

            case 4:
                printf("\n Informacion de ventas:\n");
                printf(" Total de ganancias: %.2f\n", totalGanancias);
                printf(" Total de unidades vendidas: %d\n", totalUnidades);
                break;

            case 5:
                seguir = 0;
                break;

            default:
                printf("\n Opcion no valida\n");
                break;
        }
    }

    return 0;
}
