#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PC
{
    int sCore;     // entre 1 y 3 GHz
    int yFab;      // entre 2015 y 2023
    int qCores;    // entre 1 y 8
    char tCPU[10]; // valores del arreglo tipos
} typedef pc;

void cargar(pc *estructura, char *tipos);
void mostrar(pc *estructura);
void mostrarOlddest(pc *estructura);
void mostrarFastest(pc *estructura);
void main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *p_Tipos;
    p_Tipos = &tipos[0][0];

    pc *arrpc = (pc *)malloc(5 * sizeof(pc));

    srand(time(NULL));

    cargar(arrpc, p_Tipos);
    mostrar(arrpc);

    mostrarOlddest(arrpc);
    mostrarFastest(arrpc);

    free(arrpc);
}

void cargar(pc *estructura, char *tipos)
{
    for (int i = 0; i < 5; i++)
    {
        estructura->qCores = 1 + rand() % (8 - 1) + 1;
        estructura->sCore = 1 + rand() % (3 - 1) + 1;
        estructura->yFab = 1 + rand() % (2023 - 2015) + 2015;
        int randomTypeSelected = (rand() % (6 - 0) + 0) * 10;
        tipos += randomTypeSelected;
        for (int j = 0; j < 10; j++)
        {
            estructura->tCPU[j] = *tipos;
            tipos++;
        }
        tipos -= randomTypeSelected;
        tipos -= 10;
        estructura++;
    }
}

void mostrar(pc *estructura)
{
    for (int i = 0; i < 5; i++)
    {
        printf("-- PC Numero: %d --\n", i + 1);
        printf("Velocidad: %d GHz\n", estructura->sCore);
        printf("Anio de Fabricacion: %d\n", estructura->yFab);
        printf("Cantidad de nucleos: %d\n", estructura->qCores);
        printf("Tipo de Procesador: ");
        for (int j = 0; j < 10; j++)
        {
            printf("%c", estructura->tCPU[j]);
        }
        printf("\n");
        estructura++;
    }
}

void mostrarOlddest(pc *estructura)
{
    int min, aux, k = 0;
    min = estructura->yFab;
    for (k; k < 5; k++)
    {
        if (min > estructura->yFab)
        {
            min = estructura->yFab;
            aux = k;
        }

        estructura++;
    }
    estructura -= 5;
    if (aux == 10) // THROUBLESHOOTING
    {
        aux = 0;
    }
    printf("aux: %d", aux);
    estructura += aux;
    printf("\n=== PC MAS ANTIGUA ===\n");
    printf("-- PC Numero: %d --\n", aux);
    printf("Velocidad: %d GHz\n", estructura->sCore);
    printf("Anio de Fabricacion: %d\n", estructura->yFab);
    printf("Cantidad de nucleos: %d\n", estructura->qCores);
    printf("Tipo de Procesador: ");
    for (int j = 0; j < 10; j++)
    {
        printf("%c", estructura->tCPU[j]);
    }
    printf("\n");
}

void mostrarFastest(pc *estructura)
{
    int max, aux, qNuc, k = 0;
    max = estructura->sCore;
    qNuc = estructura->qCores;
    for (k; k < 5; k++)
    {
        if (max < estructura->sCore)
        {
            max = estructura->sCore;
            qNuc = estructura->qCores;
            aux = k;
        }
        if (max == estructura->sCore && qNuc < estructura->qCores)
        {
            max = estructura->sCore;
            qNuc = estructura->qCores;
            aux = k;
        }

        estructura++;
    }
    estructura -= 5;
    if (aux == 10) // THROUBLESHOOTING
    {
        aux = 0;
    }
    printf("aux: %d", aux);
    estructura += aux;
    printf("\n=== PC MAS RAPIDA ===\n");
    printf("-- PC Numero: %d --\n", aux + 1);
    printf("Velocidad: %d GHz\n", estructura->sCore);
    printf("Anio de Fabricacion: %d\n", estructura->yFab);
    printf("Cantidad de nucleos: %d\n", estructura->qCores);
    printf("Tipo de Procesador: ");
    for (int j = 0; j < 10; j++)
    {
        printf("%c", estructura->tCPU[j]);
    }
    printf("\n");
}