#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;

void sort(int* arrN, int sizeN)
{
    int tmp = 0;
    for (int i = 0; i < sizeN; ++i)
    {
        for (int j = i + 1; j < sizeN; ++j)
        {
            if (arrN[j] < arrN[i])
            {
                tmp = arrN[j];
                arrN[j] = arrN[i];
                arrN[i] = tmp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

 
    {
        int sizeA, sizeB;
        cout << "Введите размер первого массива: ";
        cin >> sizeA;
        cout << "Введите размер второго массива: ";
        cin >> sizeB;
        int* arrA = new int[sizeA];
        int* arrB = new int[sizeB];
        cout << "\n\nПервый массив: ";
        for (int x = 0; x < sizeA; x++)
        {
            arrA[x] = rand() % 9 + 1;
            cout << arrA[x] << " ";
        }
        cout << "\n\nВторой массив: ";
        for (int x = 0; x < sizeB; x++)
        {
            arrB[x] = rand() % 9 + 1;
            cout << arrB[x] << " ";
        }

        sort(arrA, sizeA);
        sort(arrB, sizeB);

        cout << "\n\nПервый массив (Отсортированный): ";
        for (int x = 0; x < sizeA; x++)
        {
            cout << arrA[x] << " ";
        }
        cout << "\n\nВторой массив (Отсортированный): ";
        for (int x = 0; x < sizeB; x++)
        {
            cout << arrB[x] << " ";
        }
        int* arrC = new int[sizeA < sizeB ? sizeA : sizeB];
        int sizeC = 0;
        cout << endl << endl << endl;


        bool flag;
        for (int x = 0; x < sizeA; x++)
        {
            flag = true;
            for (int y = 0; y < sizeB; y++)
            {
                if (arrA[x] == arrB[y])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                arrC[sizeC] = arrA[x];
                sizeC++;
            }
        }


        int y;
        for (int x = 0; x < sizeA; x++)
        {
            flag = true;
            for (y = 0; y < sizeB; y++)
            {
                if (arrB[x] == arrA[y])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                arrC[sizeC] = arrA[y];
                sizeC++;
            }
        }

        for (int x = 0, y = 0; x < sizeA && y < sizeB; )
        {
            if (arrA[x] > arrB[y]) {
                arrC[sizeC++] = arrB[y++]; if (y == sizeB && arrA[x] != NULL) while (x < sizeA)  arrC[sizeC++] = arrA[x++];

            }

            else if (arrA[x] < arrB[y]) {
                arrC[sizeC++] = arrA[x++]; if (x == sizeA && arrB[y] != NULL) while (y < sizeB)  arrC[sizeC++] = arrB[y++];

            }

            else    if (arrA[x] == arrB[y]) {
                x++; y++;


                if (y == sizeB && arrA[x]) { while (x < sizeA) { arrC[sizeC++] = arrA[x++]; } }
                if (x == sizeA && arrB[y]) { while (y < sizeB) { arrC[sizeC++] = arrB[y++]; } }

                if (y == sizeB && arrA[x - 1] == arrA[x]) { arrC[sizeC++] = arrA[x]; }; if (x == sizeA && arrB[y - 1] == arrB[y]) { arrC[sizeC++] = arrB[y]; }
            }

        }

        sizeC--;
        cout << "\n\nТретий массив: ";
        for (int x = 0; x < sizeC; x++)
        {
            cout << arrC[x] << " ";
        }
    }
}