#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int razmertipa(unsigned short int *p);
unsigned char getbyte(unsigned char *p, int index);

int main()
{
    int choice, i;
    char *pc;
    int *pi;
    double *pd;
    float PI, *p1, *p2;
    int x3, *pa;
    double d3, *pd3;
    char c3, *pc3;
    long double ld3, *pld3;
    unsigned short int us3, *pus3;
    _Bool b3, *pb3;
    float array[10] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f };
    float *ptra;
    int x5;
    float f5;
    double d5;
    unsigned short int mas[2];
    int sz;

    setlocale(LC_ALL, ".UTF8");

    do
    {
        printf("\n===== ЛАБОРАТОРНАЯ РАБОТА (УКАЗАТЕЛИ) =====\n");
        printf("1 - Задание 1 (Размер указателей)\n");
        printf("2 - Задание 2 (Вывод адреса %%p и %%x)\n");
        printf("3 - Задание 3 (Смещение указателей разных типов)\n");
        printf("4 - Задание 4 (Перемещение по массиву)\n");
        printf("5 - Задание 5 (Побайтовый вывод int, float, double)\n");
        printf("6 - ДЗ (Размер unsigned short int)\n");
        printf("0 - Выход\n");
        printf("Выберите задание: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nЗадание 1:\n");
                printf("char*:   %lu байт\n", (unsigned long)sizeof(pc));
                printf("int*:    %lu байт\n", (unsigned long)sizeof(pi));
                printf("double*: %lu байт\n", (unsigned long)sizeof(pd));
                break;

            case 2:
                PI = 3.14159f;
                p1 = p2 = &PI;
                printf("\nЗадание 2:\n");
                printf("По адресу p1=%p (hex=%llx) хранится *p1=%g\n", p1, (unsigned long long)p1, *p1);
                printf("По адресу p2=%p (hex=%llx) хранится *p2=%g\n", p2, (unsigned long long)p2, *p2);
                break;

            case 3:
                printf("\nЗадание 3:\n");
                x3 = 5; pa = &x3;
                printf("int:         до=%p, ", (void *)pa); pa++;
                printf("после ++=%p, ", (void *)pa); pa--;
                printf("после --=%p\n", (void *)pa);

                d3 = 5.0; pd3 = &d3;
                printf("double:      до=%p, ", (void *)pd3); pd3++;
                printf("после ++=%p, ", (void *)pd3); pd3--;
                printf("после --=%p\n", (void *)pd3);

                c3 = 'A'; pc3 = &c3;
                printf("char:        до=%p, ", (void *)pc3); pc3++;
                printf("после ++=%p, ", (void *)pc3); pc3--;
                printf("после --=%p\n", (void *)pc3);

                ld3 = 5.0L; pld3 = &ld3;
                printf("long double: до=%p, ", (void *)pld3); pld3++;
                printf("после ++=%p, ", (void *)pld3); pld3--;
                printf("после --=%p\n", (void *)pld3);

                us3 = 5; pus3 = &us3;
                printf("ushort int:  до=%p, ", (void *)pus3); pus3++;
                printf("после ++=%p, ", (void *)pus3); pus3--;
                printf("после --=%p\n", (void *)pus3);

                b3 = 1; pb3 = &b3;
                printf("_Bool:       до=%p, ", (void *)pb3); pb3++;
                printf("после ++=%p, ", (void *)pb3); pb3--;
                printf("после --=%p\n", (void *)pb3);
                break;

            case 4:
                printf("\nЗадание 4:\n");
                printf("4.1: array=%p, &array[0]=%p, &array=%p\n", (void *)array, (void *)&array[0], (void *)&array);

                ptra = array;
                printf("4.2: начало ptra=%p (*ptra=%.2f)\n", (void *)ptra, *ptra);
                ptra++;
                printf("     ptra++=%p (*ptra=%.2f)\n", (void *)ptra, *ptra);
                printf("     ptra+4=%p (*(ptra+4)=%.2f)\n", (void *)(ptra + 4), *(ptra + 4));
                printf("     ptra-2=%p\n", (void *)(ptra - 2));

                printf("4.3 (прямой проход с шагом +2): ");
                for (ptra = array; ptra < array + 10; ptra += 2)
                {
                    printf("%.2f ", *ptra);
                }
                printf("\n");

                printf("4.4 (обратный проход с декрементом): ");
                for (ptra = &array[9]; ptra >= array; ptra--)
                {
                    printf("%.2f ", *ptra);
                }
                printf("\n");
                break;

            case 5:
                printf("\nЗадание 5:\n");
                x5 = 12345;
                f5 = 12345.0f;
                d5 = 12345.0;

                printf("int (12345) в памяти (младший -> старший байт): ");
                for (i = 0; i < (int)sizeof(int); i++)
                {
                    printf("%.2x ", getbyte((unsigned char *)&x5, i));
                }
                printf("\n");

                printf("float (12345.0) в памяти: ");
                for (i = 0; i < (int)sizeof(float); i++)
                {
                    printf("%.2x ", getbyte((unsigned char *)&f5, i));
                }
                printf("\n");

                printf("double (12345.0) в памяти: ");
                for (i = 0; i < (int)sizeof(double); i++)
                {
                    printf("%.2x ", getbyte((unsigned char *)&d5, i));
                }
                printf("\nВывод: в системе используется порядок байтов: младший байт по младшему адресу.\n");
                break;

            case 6:
                printf("\nДомашнее задание (пункт 3 - unsigned short int):\n");
                sz = razmertipa(mas);
                printf("Размер типа unsigned short int: %d байт(а)\n", sz);
                break;

            case 0:
                printf("Завершение работы.\n");
                break;

            default:
                printf("Ошибка: неверный пункт меню.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}

int razmertipa(unsigned short int *p)
{
    unsigned char *p1, *p2;

    p1 = (unsigned char *)p;
    p2 = (unsigned char *)(p + 1);
    return (int)(p2 - p1);
}

unsigned char getbyte(unsigned char *p, int index)
{
    return *(p + index);
}