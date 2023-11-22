#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nrIncidente;

struct accident
{
    char zona[50];
    char tip[50];
    char ziua[50];
    char ora[50];
} incidente[50];

void readIncidentsFromFile()
{
    FILE* fp = fopen("incidente.txt", "r");

    fscanf(fp, "%d", &nrIncidente);

    fgetc(fp);
    fflush(stdin);
    for (int i = 0; i < nrIncidente; ++i)
    {

        fgets(incidente[i].zona, 50, fp);
        incidente[i].zona[strlen(incidente[i].zona) - 1] = '\0';

        fgets(incidente[i].tip, 50, fp);
        incidente[i].tip[strlen(incidente[i].tip) - 1] = '\0';

        fgets(incidente[i].ziua, 50, fp);
        incidente[i].ziua[strlen(incidente[i].ziua) - 1] = '\0';

        fgets(incidente[i].ora, 50, fp);
        incidente[i].ora[strlen(incidente[i].ora) - 1] = '\0';

    }

    fclose(fp);
}

void writeIncidentsToFile()
{
    FILE* fp = fopen("incidente.txt", "w");

    fprintf(fp, "%d\n", nrIncidente);

    for (int i = 0; i < nrIncidente; ++i)
    {
        fprintf(fp, "%s\n", incidente[i].zona);
        fprintf(fp, "%s\n", incidente[i].tip);
        fprintf(fp, "%s\n", incidente[i].ziua);
        fprintf(fp, "%s\n", incidente[i].ora);
    }

    fclose(fp);
}

void appendToFile()
{
    FILE* fp = fopen("incidente.txt", "a");

    fprintf(fp, "SCRIEM INFORMATIE LA FINALUL FISIERULUI\n");

    fclose(fp);
}

int main()
{
    int i=0,k=0;
    char zon[50],ti[50];
    readIncidentsFromFile();
    while(1==1)
    {
        system("cls");
        printf("-= Alegeti o optiune =-\n\n");
        printf("1. Raportati un accident\n");
        printf("2. Vizualizati incidentele raportate\n");
        printf("3. Vizualizati incidentele raportate in functie de zona\n");
        printf("4. Vizualizati incidentele raportate in functie de tip\n");
        printf("5. Iesire\n");

        int choice, a;
        scanf("%d", &choice);

        system("cls");

        if(choice==1)
        {
            printf("-= RAPORTARE INCIDENT =-\n");
            printf("Zona: ");
            fflush(stdin);
            gets(incidente[nrIncidente].zona);
            printf("Tipul: ");
            fflush(stdin);
            gets(incidente[nrIncidente].tip);
            printf("Ziua: ");
            fflush(stdin);
            gets(incidente[nrIncidente].ziua);
            printf("Ora: ");
            fflush(stdin);
            gets(incidente[nrIncidente].ora);
            nrIncidente++;
            writeIncidentsToFile();
            system("pause");
        }

        else if(choice==2)
        {
            printf("-= VIZUALIZARE INCIDENTE (total: %d) =-\n\n", nrIncidente);
            for (int i = 0; i < nrIncidente; ++i)
            {
                printf("Zona: %s\n", incidente[i].zona);
                printf("Tipul: %s\n", incidente[i].tip);
                printf("Ziua: %s\n", incidente[i].ziua);
                printf("Ora: %s\n\n", incidente[i].ora);
            }

            system("pause");
        }

        else if(choice==3)
        {
            printf("Introduceti zona incidentului: ");
            fflush(stdin);
            gets(zon);
            for (int i = 0; i < nrIncidente; ++i)
            {
                if(strcmp(zon,incidente[i].zona)==0)
                {
                printf("Zona: %s\n", incidente[i].zona);
                printf("Tipul: %s\n", incidente[i].tip);
                printf("Ziua: %s\n", incidente[i].ziua);
                printf("Ora: %s\n\n", incidente[i].ora);
                k=1;
                }
            }
            if(k==0)
                printf("-- Nu exista niciun incident raportat in aceasta zona --\n");
            system("pause");
        }

        else if(choice==4)
        {
            printf("Introduceti tipul incidentului: ");
            fflush(stdin);
            gets(ti);
            for (int i = 0; i < nrIncidente; ++i)
            {
                if(strcmp(incidente[i].tip,ti)==0)
                {
                printf("Zona: %s\n", incidente[i].zona);
                printf("Tipul: %s\n", incidente[i].tip);
                printf("Ziua: %s\n", incidente[i].ziua);
                printf("Ora: %s\n\n", incidente[i].ora);
                k=1;
                }
            }
            if(k==0)
                printf("-- Nu exista niciun incident raportat de acest tip --\n");
            system("pause");
        }

        else if(choice==5)
        {
            break;
        }
        else
        {
            printf("Aceasta optiune nu exista, va rugam introduceti alta. ");
            system("pause");
        }
    }

    return 0;
}
