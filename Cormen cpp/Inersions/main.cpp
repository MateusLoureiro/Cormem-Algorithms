#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void imprime(vector<int> vetor);
int mergeVectors(vector<int> &vetor, int inicio, int meio);
int mergeSort(vector<int> &vetor, int inicio, int ultimoIndice);

int main()
{
  vector<int> vetor(20);
  vector<int> copia(20);

  //INICIALIZAÇÃO DO VETOR
  srand(time(NULL));
  for(int i = 0; i < vetor.size(); i++)
  {
    int valor = rand() % 100;
    vetor[i] = valor;
    copia[i] = valor;
  }

  cout << "Vetor original:" << endl;
  imprime(vetor);
  imprime(copia);
  cout << endl << endl;

  int inversoes = mergeSort(copia, 0, vetor.size() - 1);

  imprime(vetor);
  imprime(copia);
  cout << "Inversões: " << inversoes << endl;

  return 0;
}

void imprime(vector<int> vetor)
{
  int tamanho = vetor.size();
  if(tamanho == 0)
  {
    cout << "Vetor Vazio!" << endl;
    return;
  }
  cout << "[";
  for(int i = 0; i < tamanho - 1; i++)
    cout << vetor[i] << ", ";
  cout << vetor[tamanho - 1] << "]" << endl;
}

int mergeVectors(vector<int> &vetor, int inicio, int meio, int ultimoIndice)
{
  vector<int> v1(meio - inicio + 1);
  for(int i = inicio; i <= meio; i++)
  {
    v1[i - inicio] = vetor[i];
  }

  vector<int> v2(ultimoIndice - meio);
  for(int i = meio + 1; i <= ultimoIndice; i++)
  {
    v2[i - meio - 1] = vetor[i];
  }

  cout << "v1: ";
  imprime(v1);
  cout << "v2: ";
  imprime(v2);

  int i = 0;
  int j = 0;
  int k = inicio;
  int inversoes = 0;
  while(k <= ultimoIndice)
  {
    if(i == v1.size())
    {
      for(int o = k; o <= ultimoIndice; o++, j++)
      {
        vetor[o] = v2[j];
      }
      break;
    }
    else if(j == v2.size())
    {
      for(int o = k; o <= ultimoIndice; o++, i++)
      {
        vetor[o] = v1[i];
      }
      break;
    }
    if(v1[i] <= v2[j])
    {
      vetor[k] = v1[i];
      i++;
    }
    else
    {
      vetor[k] = v2[j];
      j++;
      inversoes += v1.size() - i;
    }
    k++;
  }
  cout << inversoes << endl;
  return inversoes;
}

int mergeSort(vector<int> &vetor, int inicio, int ultimoIndice)
{
  int inv = 0;
  if(ultimoIndice > inicio)
  {
    int meio = (ultimoIndice + inicio)/2;
    inv += mergeSort(vetor, inicio, meio);
    inv += mergeSort(vetor, meio + 1, ultimoIndice);
    inv += mergeVectors(vetor, inicio, meio, ultimoIndice);
  }
  return inv;
}

