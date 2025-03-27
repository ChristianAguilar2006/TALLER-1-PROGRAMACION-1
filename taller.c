#include <stdio.h>
#include <string.h>

int main()
{
    char id[100];
    char nombre[100];
    int stock;
    float precio;
    int seguir = 1;
    int opcion;
    int Cantidad;
    int reabastecer;
    int totalUnidades = 0;
    float totalGanancias = 0;
    float PrecioDescuento;
    float Ganancias = 0;
    int op=1;
    while (seguir)
    {
        printf("\n1) Registrar producto\n");
        printf("2) Vender unidades\n");
        printf("3) Reabastecer Productos\n");
        printf("4) Consultar informacion del producto\n");
        printf("5) Calcular y mostrar informacion de ventas\n");
        printf("6) Salir\n");
        printf("Ingrese una opcion: ");
        op= scanf("%d",&opcion);
       if (op!=1)
       {
        printf("\n ENTRADA NO VALIDA");
        while (getchar()!='\n');
        continue;
        
       }
       
        
        

        switch (opcion)
        {

        case 1:

            printf("\nIngresar datos\n");

            printf("\n Ingrese el id del PRODUCTO: ");
            fflush(stdin);
            fgets(id, 100, stdin);

            printf("\n Ingrese el NOMBRE: ");
            fflush(stdin);
            fgets(nombre, 100, stdin);

            printf("\n Ingrese el precio: ");
            scanf("%f", &precio);
            while (precio<0)
            {
            printf("\n Ingrese el precio VALIDO : ");
            scanf("%f", &precio);
            }
            
            

            printf("\n Ingrese la cantidad de STOCK: ");
            scanf("%d", &stock);
            while (stock<0)
            {
            printf("\n Ingrese el precio VALIDO : ");
            scanf("%f", &stock);
            }
            break;

        case 2:
            if (strlen(nombre) == 0 || stock == 0 || precio == 0)
            {
                printf("\n No hay producto registrado");
                break;
            }
            printf("\n Ingrese cuantas unidades va a vender: ");
            scanf("%d", &Cantidad);

            while (Cantidad > stock || Cantidad <= 0)
            {
                printf("\n No hay suficientes unidades para vender.");
                printf("\n Ingrese una cantidad DISPONIBLE o VALIDA: ");
                scanf("%d", &Cantidad);
            }

            totalUnidades += Cantidad;
            stock -= Cantidad;

            if (Cantidad >= 5)
            {
                PrecioDescuento = precio * 0.9;
            }
            else
            {
                PrecioDescuento = precio;
            }

            Ganancias = Cantidad * PrecioDescuento;
            totalGanancias += Ganancias;

            printf("\n Vendidos con exito");
            break;

        case 3:
            if (strlen(nombre) == 0 || stock == 0 || precio == 0)
            {
                printf("\n No hay producto registrado");
                break;
            }
            printf("\n Ingrese la cantidad de unidades a reabastecer: ");
            scanf("%d", &reabastecer);
            stock += reabastecer;
            break;

        case 4:
            if (strlen(nombre) == 0 || stock == 0 || precio == 0)
            {
                printf("\n No hay producto registrado");
                break;
            }
            printf("\n Informacion del producto:");
            printf(" \nNombre: %s", nombre);
            printf(" \nID: %s\n", id);
            printf(" \nCantidad de %s: %d", nombre, stock);
            printf(" \nPrecio de %s: %.2f", nombre, precio);
            break;

        case 5:
            if (strlen(nombre) == 0 || stock == 0 || precio == 0)
            {
                printf("\n No hay producto registrado");
                break;
            }
            printf("\n Informacion de ventas:\n");
            printf(" Total de ganancias: %.2f\n", totalGanancias);
            printf(" Total de unidades vendidas: %d\n", totalUnidades);
            break;

        case 6:
            printf("\n GRACIAS POR USAR EL PROGRAMA");
            seguir = 0;
            break;

        default:
            printf("\n Opcion no valida\n");
            break;
        }
    }

    return 0;
}
