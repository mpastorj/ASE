/*Trabajo realizado por:
- Marilyn Pastor Jaque
- Pedro Cuevas Meza
- Camilo Mart�nez Parraguez
para la asignatura de Sistemas Operativos*/


#include <stdio.h>
#include <iostream>


using namespace std;


void imprimir(int Matriz[10][10], int N, int procesos)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < procesos; i++)
    {
      for (j = 0; j < N; j++)
        {
          cout << "\t" << Matriz[i][j];
        }
      cout << endl;
    }
}

void CalcularNecesidad(int A[10][10], int B[10][10], int C[10][10], int procesos, int N)
{

  int i = 0;
  int j = 0;
  for (i = 0; i < procesos; i++)
    {
      for (j = 0; j < N; j++)
        {

          C[i][j] = B[i][j] - A[i][j];
        }

    }



}


int NecesidadCubierta(int C[10][10], int N , int procesos, int Disponibles[10])
{

  int i = 0;
  int j = 0;
  int cont = 0;
  int cont2 = 10;

  while (cont < N)
    {

      for (j = 0 ; j < N ; j++)
        {

          if (C[i][j] == 0)
            {
              cont2++;
            }
          if (C[i][j] <= Disponibles[j])
            {
              cont++;
            }
        }

      if (cont2 == N + 10)
        {
          cont = 0;
          cont2 = 10;
        }

      if (cont == N)
        {
          return i;
        }
      else if (i == procesos && cont2 == 10)
        {
          return 11;
        }
      else if (i == procesos)
        {
          return 12;
        }

      cont = 0;
      i++;
    }



}

void AsignaNecesidades(int A[10][10], int B[10][10] , int C[10][10] , int i , int N, int Disponibles[10])
{

  int j = 0;

  for (j = 0 ; j < N ; j++)
    {
      A[i][j] = B[i][j];
      Disponibles[j] = Disponibles[j] - C[i][j];
      C[i][j] = 0;


    }
}



void DevolverRecursos(int A[10][10], int B[10][10], int i , int N, int Disponibles[10])
{

  int j ;

  for (j = 0; j < N; j++)
    {

      Disponibles[j] += A[i][j];
      cout << "\t" << "R[" << j << "]: " << Disponibles[j];
      A[i][j] = 0;
      B[i][j] = 0;
    }
}

int main()
{
  int A[10][10];
  int B[10][10];
  int C[10][10];
  int Recursos[10];
  int SumaA[10];
  int Disponibles[10];
  int suma = 0;
  int N = 0;
  int R = 0;
  int procesos = 0;
  int p = 0;
  int i = 0;
  int j = 0;
  int maximo = 0;
  int indice = 0;
  int contador = 0;
  int veces = 0;
  int estado = 0;
  int instancia = 0;

  cout << endl << "       ALGORITMO DE SEGURIDAD DE ESTADO      " << endl << endl;
  cout << "* Este algoritmo no permite mas de 10 procesos" << endl << endl;
  cout << "* Este algoritmo no permite mas de 4 recursos" << endl << endl;
  cout << "* Este algoritmo permite un maximo de 10 instancias de cada recurso" << endl << endl;
  cout << "-> Ingrese Cantidad de Procesos: ";
  cin >> p;
  if (p > 10)
    {
      while (p > 10)
        {
          cout << "Solo le puede ingresar un maximo de 10 procesos!, vuelva a ingresar: ";
          cin >> p;
        }
      procesos = p;
    }
  else
    {
      procesos = p;
    }

  cout << "-> Ingrese Numero de Recursos: ";
  cin >> R;
  if (R > 4)
    {
      while (R > 4)
        {
          cout << "Solo le puede ingresar un maximo de 4 recursos!, vuelva a ingresar: ";
          cin >> R;
        }
      N = R;
    }
  else
    {
      N = R;
    }

  for (i = 0; i < N; i++)
    {
      cout << "Ingrese Instancias Totales de R[" << i << "]:";
      cin >> instancia;
      if (instancia > 10)
        {
          cout << "Solo se permite un maximo de 10 instancias" << endl;
          i = i - 1;
        }
      else
        {
          Recursos[i] = instancia;
        }

    }

  cout << endl << endl << "------ Ahora se llenaran las matrices ------" << endl;
  cout << endl << "1) ** RECURSOS ASIGNADOS **" << endl << endl;

  for (i = 0; i < procesos; i++)
    {
      for (j = 0; j < N; j++)
        {
          cout << "Ingrese Recursos asignados de: P[" << i << "], R[" << j << "]: ";
          cin >> A[i][j];
        }
    }
  for (j = 0; j < N; j++)
    {
      for (i = 0; i < procesos; i++)
        {
          suma = suma + A[i][j];
        }
      SumaA[j] = suma;
      suma = 0;

    }


  cout << endl << "2) ** RECURSOS MAXIMOS **" << endl << endl;
  for (i = 0; i < procesos; i++)
    {
      for (j = 0; j < N; j++)
        {
          cout << "Ingrese Recursos maximos de: P[" << i << "], R[" << j << "]: ";
          cin >> maximo;
          if (A[i][j] <= maximo)
            {
              B[i][j] = maximo;
            }
          else
            {
              cout << "El recurso maximo no debe ser menor que el recurso asignado!" << endl;
              j = j - 1;
            }
        }
    }

  cout << endl << endl << "-> RECURSOS DISPONIBLES: " << endl;
  for (i = 0; i < N; i++)
    {
      Disponibles[i] = Recursos[i] - SumaA[i];
      cout << "\t" << "R[" << i << "]: " << Disponibles[i];
    }

  CalcularNecesidad(A, B, C, procesos, N);

  indice = NecesidadCubierta(C, N, procesos, Disponibles);


  while (indice != 11 && indice != 12)
    {
      cout << endl << endl << "Matriz: ASIGNADOS" << endl << endl;
      imprimir(A, N, procesos);

      cout << endl << endl << "Matriz: MAXIMOS" << endl << endl;
      imprimir(B, N, procesos);

      cout << endl << endl << "Matriz: NECESIDAD" << endl << endl;
      imprimir(C, N, procesos);

      indice = NecesidadCubierta(C, N, procesos, Disponibles);

      AsignaNecesidades(A, B, C, indice, N, Disponibles);

      DevolverRecursos(A, B, indice, N, Disponibles);
      contador++;
      if (contador <= procesos && indice != 11 && indice != 12)
        {
          cout << endl << "-------------------------------------" << endl;
          cout << endl << "Se ha seleccionado P[" << indice << "]" << endl;
          veces++;
          estado = 1;
        }
      if ((indice == 11 || indice == 12) && veces != procesos)
        {
          cout << endl << "****** MEMORIA INSUFICIENTE ********";
          estado = 0;
        }
    }

  if (estado == 1)
    {
      cout << endl << endl << "-> El Sistema se encuentra en estado SEGURO" << endl << endl;
    }
  else
    cout << endl << endl << "-> El estado del Sistema es INSEGURO" << endl << endl;

  cout << endl << endl << endl;

  system("PAUSE");
  return 0;
}
