
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>

int compare(const void* x1, const void* x2)   // ��������������������������������
{
return (*(int*)x1 - *(int*)x2);              // ���� ��������� ��������� ����� 0, �� ����� �����, < 0: x1 < x2; > 0: x1 > x2
}


void qs(int items[], int left, int right) //������������: qs(items, 0, count-1);
{
int i, j;
int x, y;



i = left; j = right;

/* ����� ���������� */
x = items[(left + right) / 2];

do {
while ((items[i] < x) && (i<right)) i++;
while ((x <items[j]) && (j >left)) j--;

if (i<= j) {
            y = items[i];
items[i] = items[j];
items[j] = y;
i++; j--;
        }
    } while (i<= j);

if (left< j) qs(items, left, j);
if (i<right) qs(items, i, right);
}



//����������������������
void ShellSort(int n, int mass[])
{
int i, j, step;
int tmp;
for (step = n / 2; step > 0; step /= 2)
for (i = step; i<n; i++)
        {
tmp = mass[i];
for (j = i; j >= step; j -= step)
            {
if (tmp<mass[j - step])
mass[j] = mass[j - step];
else
break;
            }
mass[j] = tmp;
        }
}

int main()
{
clock_t start, end;
int maxcount = 20000000;
setlocale(LC_ALL, "Rus");
//���� N
int N;
printf("������� ���������� ��������� �������:");
scanf_s("%d", &N);

//��������� ������ ��� ������
int* mass;
int* mass1;
    mass = (int*)malloc(N * sizeof(int));
    mass1 = (int*)malloc(N * sizeof(int));
for (int i = 0; i< N; i++)
    {
        mass[i] = rand() % 100;
    }
for (int i = 0; i< N; i++)
    {
        mass1[i] = mass[i];
    }

//qsort(mass, N, sizeof(int), compare);
//���������� ������� �����
start = clock();
ShellSort(N, mass);    
    end = clock();
double diff = (end - start);
printf("\n     |������      |������������|��������� | |   �����  |\n");
    printf("________________________________________________________");
printf("\n�����| %lf |", diff);
for (int i = 0; i< N; i++)
    {
		maxcount = maxcount + 5;
        mass[i] = maxcount;
    }
maxcount = 20000000;
    start = clock();
ShellSort(N, mass);
    end = clock();
    diff = (end - start);
printf("% lf|", diff);
for (int i = 0; i< N; i++)
    {
		maxcount = maxcount - 2;
        mass[i] = maxcount;
    }
maxcount = 20000000;
    start = clock();
ShellSort(N, mass);
    end = clock();
    diff = (end - start);
printf("% lf |", diff);
for (int i = 0; i< N/2; i++)
    {
		maxcount = maxcount + 2;
        mass[i] = maxcount;
    }
for (int i = N/2; i< N; i++)
    {
		maxcount = maxcount - 2;
        mass[i] = maxcount;
    }
maxcount = 20000000;
    start = clock();
ShellSort(N, mass);
    end = clock();
    diff = (end - start);
printf("% lf|", diff);

for (int i = 0; i< N; i++)
    {
        mass[i] = mass1[i];
    }
    start = clock();
qs(mass, 0, N - 1);
    end = clock();

    diff = (end - start);
printf("\nQS   |");
printf(" %lf |", diff);
for (int i = 0; i< N; i++)
    {
		maxcount = maxcount + 5;
        mass[i] = maxcount;
    }

    start = clock();
qs(mass, 0, N - 1);
    end = clock();

    diff = (end - start);
printf("% lf |", diff);

maxcount = 20000000;

for (int i = 0; i< N; i++)
    {
		maxcount = maxcount - 5;
        mass[i] = maxcount;
    }

    start = clock();
qs(mass, 0, N - 1);
    end = clock();

    diff = (end - start);
printf("% lf  |", diff);

maxcount = 20000000;
for (int i = 0; i< N; i++)
    {
        mass[i] = mass1[i];
    }

for (int i = 0; i< N/2; i++)
    {
		maxcount = maxcount + 5;
        mass[i] = maxcount;
    }

for (int i = N/2; i< N; i++)
    {
		maxcount = maxcount - 5;
        mass[i] = maxcount;
    }


    start = clock();
qs(mass, 0, N - 1);
    end = clock();

    diff = (end - start);
printf("% lf |", diff);
///////////////////////
//QSORT
maxcount = 20000000;
for (int i = 0; i< N; i++)
    {
        mass[i] = mass1[i];
    }

printf("\nQsort|");

    start = clock();
qsort(mass, N, sizeof(int), compare);
    end = clock();

    diff = (end - start);
	printf("% lf |", diff);
////////////
for (int i = 0; i< N; i++)
    {
		maxcount = maxcount + 5;
        mass[i] = maxcount;
    }


    start = clock();
qsort(mass, N, sizeof(int), compare);
    end = clock();

    diff = (end - start);
printf("% lf |", diff);
////////////////
maxcount = 20000000;
for (int i = 0; i< N; i++)
	{
		maxcount = maxcount - 5;
		mass[i] = maxcount;
    }


start = clock();
qsort(mass, N, sizeof(int), compare);
    end = clock();

    diff = (end - start);
printf("% lf  |", diff);
///////////////////////
maxcount = 20000000;
for (int i = 0; i< N/2; i++)
    {
		maxcount = maxcount + 5;
        mass[i] = maxcount;
    }
for (int i = N/2; i< N ; i++)
    {
		maxcount = maxcount - 5;
        mass[i] = maxcount;
    }

    start = clock();
qsort(mass, N, sizeof(int), compare);
    end = clock();

    diff = (end - start);
printf("% lf |", diff);

    printf("\n_______________________________________________________");


    free(mass);
	free(mass1);
    _getch();
return 0;
}
