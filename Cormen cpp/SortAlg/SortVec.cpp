#include "SortVec.h"
#include "Heap.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

//Cria o Vetor
vector<int> VecOp::cria(int modo)
{
  int tamanho = 10;
//  cout << "Digite o tamanho do vetor: ";
//  cin >> tamanho;
  vector<int> vetor(tamanho);

  //INICIALIZAÇÃO DO VETOR
  srand(time(NULL));
  switch(modo)
  {
    //Numeros aleatorios entre 0 e 99 inclusos
    case(1):
      for(int i = 0; i < vetor.size(); i++)
      {
        vetor[i] = rand() % 1000;
      }
      break;
    //Numeros aleatorios entre -20 e 20 inclusos
    case(2):
      for(int i = 0; i < vetor.size(); i++)
      {
        vetor[i] = rand() % 41 - 20;
      }
      break;
    case(3):
      for(int i = 0; i < vetor.size(); i++)
      {
        vetor[i] = rand() % 6;
      }
      break;
    //Coloca 0 em tudo
    default:
      for(int i = 0; i < vetor.size(); i++)
      {
        vetor[i] = 0;
      }
  }
  return vetor;
}

//Imprime o vetor; imprime "Vetor Vazio!" caso o vetor esteja vazio;
/// TODO (jack_bagunca#1#): What if vetor is NULL?
void VecOp::imprime(vector<int> vetor)
{
  if(vetor.size() == 0)
  {
    cout << "Vetor Vazio!" << endl;
    return;
  }
  cout << "[";
  for(int i = 0; i < vetor.size() - 1; i++)
    cout << vetor[i] << ", ";
  cout << vetor[vetor.size() - 1] << "]" << endl;
}

//Imprime o subvetor v[inicio] ate v[ultimo]; imprime "Vetor Vazio!" caso o vetor esteja vazio;
/// TODO (jack_bagunca#1#): What if vetor is NULL?
void VecOp::imprime(vector<int> vetor, int inicio, int ultimo)
{
  if(vetor.size() == 0)
  {
    cout << "Vetor Vazio!" << endl;
    return;
  }
  if(ultimo < inicio || ultimo < 0 || inicio >= vetor.size())
  {
    cout << "Subvetor Invalido!" << endl;
    return;
  }
  if(inicio < 0)
    inicio = 0;
  if(ultimo >= vetor.size())
    ultimo = vetor.size() - 1;
  cout << "[";
  for(int i = inicio; i < ultimo; i++)
    cout << vetor[i] << ", ";
  cout << vetor[ultimo] << "]" << endl;
}

//Faz as trocas no vetor
void VecOp::troca(vector<int> &vetor, int a, int b)
{
  int temp = vetor[a];
  vetor[a] = vetor[b];
  vetor[b] = temp;
}

//Encontra o menor elemento menor que o numBuscado
int VecOp::searchSup(vector<int> &vetor, int numBuscado, int maximo)
{
  int atual = 0;
  while(atual < maximo && vetor[atual] <= numBuscado)
  {
    atual++;
  }
  return atual;
}

//Encontra o menor elemento menor que o numBuscado
int VecOp::binarySearchSup(vector<int> &vetor, int numBuscado, int inicio, int maximo)
{
  if(inicio >= maximo)
    return (vetor[inicio] > numBuscado ? inicio : (inicio + 1));
  int meio = (inicio + maximo) / 2;
  if(vetor[meio] == numBuscado)
    return meio;
  if(vetor[meio] > numBuscado)
    return binarySearchSup(vetor, numBuscado, inicio, meio - 1);
  return binarySearchSup(vetor, numBuscado, meio + 1, maximo);
}

//Ordena
void VecOp::bubbleSort(vector<int> &vetor)
{
  int trocas = 1;
  int totalPassagens = 0;
  int tamanho = vetor.size();
  for(int i = 0; i < tamanho - 1 && trocas != 0; i++)
  {
    trocas = 0;
    for(int j = 0; j < tamanho - 1; j++)
    {
      if(vetor[j] > vetor[j + 1])
      {
        VecOp::troca(vetor, j, j + 1);
        trocas++;
      }
    }
    totalPassagens++;
  }
  cout << endl << "BubbleSort finalizou com " << totalPassagens << " passagens." << endl;
}

//Ordena
void VecOp::insertionSort(vector<int> &vetor)
{
  int passagens = 0;
  for(int atual = 1; atual < vetor.size(); atual++)
  {
    int chave = vetor[atual];
    for(int i = atual - 1; i >= 0 && vetor[i] > chave; i--)
    {
      VecOp::troca(vetor, i, i + 1);
    }
    passagens++;
    imprime(vetor);
  }
  cout << endl << "InsertionSort finalizou com " << passagens << " passagens." << endl;
}

//Ordena
void VecOp::insertionSortNI(vector<int> &vetor)
{
  int passagens = 0;
  for(int atual = vetor.size() - 2; atual >= 0; atual--)
  {
    int chave = vetor[atual];
    for(int j = atual + 1; j < vetor.size() && vetor[j] < chave; j++)
    {
      VecOp::troca(vetor, j, j - 1);
    }
    passagens++;
    VecOp::imprime(vetor);
  }
  cout << endl << "InsertionSortNI finalizou com " << passagens << " passagens." << endl;
}

//Ordena
void VecOp::binaryInsertionSort(vector<int> &vetor)
{
  int passagens = 0;
  for(int i = 1; i < vetor.size(); i++)
  {
    int atual = vetor[i];
    int local = binarySearchSup(vetor, atual, 0, i);

    for(int j = i - 1; j >= local; j--)
    {
      vetor[j + 1] = vetor [j];
    }
    vetor[local] = atual;
    VecOp::imprime(vetor);
    passagens++;
  }
  cout << endl << "BinaryInsertionSort finalizou com " << passagens << " passagens." << endl;
}

//Ordena
void VecOp::selectionSort(vector<int> &vetor)
{
  int passagens = 0;
  for(int i = 0; i < vetor.size() - 1; i++)
  {
    int minimo = vetor[i];
    int indiceMin = i;
    for(int j = i; j < vetor.size(); j++)
    {
      if(vetor[j] < minimo)
      {
        indiceMin = j;
        minimo = vetor[j];
      }
    }
    VecOp::troca(vetor, i, indiceMin);
    VecOp::imprime(vetor);
    passagens++;
  }
  cout << endl << "SelectionSort finalizou com " << passagens << " passagens." << endl;
}

//Faz o merge entre dois vetores e diz as inversões
int VecOp::mergeVectors(vector<int> &vetor, int inicio, int meio, int ultimoIndice)
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
  int i = 0;
  int j = 0;
  int k = inicio;
  int inv = 0;
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
      inv += v1.size() - i;
    }

    k++;
  }
  return inv;
}

//Ordena e diz o numero de inversões
int VecOp::mergeSort(vector<int> &vetor, int inicio, int ultimoIndice)
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

void VecOp::heapSort(vector<int> &vetor)
{
  Heap* heap = new Heap(vetor);
  heap->buildMaxHeap();
  int tamanho = heap->getTamHeap();

  for(int i = tamanho - 1; i > 0; i--)
  {
    tamanho--;
    heap->trocaHeap(0, tamanho);
    heap->setTamHeap(tamanho);
    heap->maxHeapify(0);
  }
  vetor = heap->getHeap();
}

int VecOp::randomPartition(vector<int> &vetor, int comeco, int fim) //fim == ultimo elemento
{
  srand(time(NULL));
  int pivo = comeco + rand() % (fim - comeco + 1);
  troca(vetor, pivo, fim);
  int i = comeco;
  for(int j = comeco; j < fim; j++)
  {
    if(vetor[j] < vetor[fim])
    {
      troca(vetor, j, i);
      i++;
    }
  }
  troca(vetor, fim, i);
  return i;
}

void VecOp::quickSort(vector<int> &vetor, int comeco, int fim)
{
  if(comeco < fim)
  {
    int p = randomPartition(vetor, comeco, fim);
    quickSort(vetor, comeco, p - 1);
    quickSort(vetor, p + 1, fim);
  }
}

void VecOp::tailQuickSort(vector<int> &vetor, int comeco, int fim)
{
  while(comeco < fim)
  {
    int q = randomPartition(vetor, comeco, fim);
    tailQuickSort(vetor, comeco, q - 1);
    comeco = q + 1;
  }
}

void VecOp::countingSort(vector<int> &vetor, vector<int> resto, int k)
{
  vector<int> temp(k);
  vector<int> ordenado(vetor.size());
  for(int i = 0; i < k; i++)
    temp[i] = 0;
  for(int i = 0; i < vetor.size(); i++)
    temp[resto[i]] += 1;
  for(int i = 1; i < k; i++)
    temp[i] += temp[i - 1];
  for(int i = vetor.size() - 1; i >= 0; i--)
  {
    temp[resto[i]]--;
    ordenado[temp[resto[i]]] = vetor[i];
  }
  vetor = ordenado;
}

void VecOp::radixSort(vector<int> &vetor, int offset)
{
  int hasDigits = 1;
  vector<int> restosTemp(vetor.size());
  vector<int> procVec = vetor;
  int pot = 0;
  while(hasDigits)
  {
    hasDigits = 0;
    for(int i = 0; i < vetor.size(); i++)
    {
      restosTemp[i] = (vetor[i] / ((int)pow(offset, pot))) % offset;
      if(restosTemp[i] != 0)
        hasDigits = 1;
    }
    pot++;
    countingSort(vetor, restosTemp, offset);
  }
}

void VecOp::maximumSubarrayBF(vector<int> vetor)
{
  vector<int> preco = vetor;
  preco[0] += 100;
  for(int i = 1; i < vetor.size(); i++)
  {
    preco[i] = vetor[i] + preco[i - 1];
  }
  cout << "Preços:  ";
  imprime(preco);
  cout << "Mudança: ";
  imprime(vetor);
  cout << endl;
  int maximo = vetor[0];
  int inicio = 0;
  int ultimo = 0;
  for(int i = 0; i < preco.size(); i++)
  {
    for(int j = i + 1; j < preco.size(); j++)
    {
      int soma = preco[j] - preco[i];
      if(i == 0)
        soma += vetor[0];
      if(soma > maximo)
      {
        maximo = soma;
        inicio = i;
        ultimo = j;
      }
    }
  }
  cout << "Soma Máxima: " << maximo << endl;
  cout << "Preços Sub:  ";
  imprime(preco, inicio, ultimo);
  cout << "Mudança Sub: ";
  imprime(vetor, inicio + 1, ultimo);
  cout << endl;
}

///TODO: Tirar o segmentation fault
void VecOp::maximumSubarrayDC(vector<int> vetor)
{
  int espec[] = {INT_MIN, 0, vetor.size() - 1};//a[SOMA] == soma, a[INICIO] == inicio, a[ULTIMO] == ultimo;
  int* maximumSubarray(vector<int> vetor, int espec[]);
  int* resultado = maximumSubarray(vetor, espec);
  cout << "SOMA: " << resultado << endl;
  cout << "SUB:  ";
  VecOp::imprime(vetor, *(1 + resultado), *(2 + resultado));
}

///TODO: Tirar o segmentation fault
int* maximumSubarray(vector<int> vetor, int espec[])
{
  int inicio = espec[1];
  int ultimo = espec[2];
  int meio = (ultimo + inicio) / 2;
  if(ultimo == inicio)
  {
    static int a[3] = {vetor[inicio], inicio, inicio};
    return a;
  }

  int* maxCrossingSub(vector<int> vetor, int espec[]);
  static int* somaMeio = maxCrossingSub(vetor, espec);
  espec[2] = meio;
  static int* somaDireita = maximumSubarray(vetor, espec);
  espec[1] = meio + 1;
  espec[2] = ultimo;
  static int* somaEsquerda = maximumSubarray(vetor, espec);

//  cout << "SomaMeio: " << somaDireita << endl;
//  somaDireita++;
//  cout << "Inicio: " << somaDireita << endl;
//  somaDireita++;
//  cout << "Final: " << somaDireita << endl;
//  int *ap;
//  return ap;

  if(*somaDireita > *somaEsquerda && *somaDireita > *somaMeio)
    return somaDireita;
  else if(*somaEsquerda > *somaMeio)
    return somaEsquerda;
  else
    return somaMeio;
}

///TODO: Tirar o segmentation fault
int* maxCrossingSub(vector<int> vetor, int* espec)
{
  int inicio = espec[1];
  int ultimo = espec[2];
  int meio = (ultimo + inicio) / 2;
  int leftSum = INT_MIN;
  int soma = 0;
  int maxLeft;
  for(int i = meio; i >= inicio; i--)
  {
    soma += vetor[i];
    if(soma > leftSum)
    {
      leftSum = soma;
      maxLeft = i;
    }
  }
  int rightSum = INT_MIN;
  soma = 0;
  int maxRight;
  for(int i = meio + 1; i <= ultimo; i++)
  {
    soma += vetor[i];
    if(soma > rightSum)
    {
      rightSum = soma;
      maxRight = i;
    }
  }
  static int resultado[3] = {rightSum + leftSum, maxLeft, maxRight};
  return resultado;
}

void VecOp::maximumSubarrayLT(vector<int> vetor)
{
  int somaMaxima = INT_MIN;
  int somaAtual  = 0;
  int maxRight   = 0;
  int esqAt      = 0;
  int maxLeft    = 0;

  for(int i = 0; i < vetor.size(); i++)
  {
    somaAtual += vetor[i];
    if(vetor[i] > somaAtual)
    {
      somaAtual = vetor[i];
      esqAt = i;
    }
    if(somaAtual > somaMaxima)
    {
      somaMaxima = somaAtual;
      maxRight   = i;
      maxLeft = esqAt;
    }
  }
  cout << "Soma Máxima: " << somaMaxima << endl;
  cout << "Mudança Sub: ";
  imprime(vetor, maxLeft, maxRight);
  cout << endl;
}

int VecOp::kthElement(vector<int> vetor, int k)
{
  int maxEl = vetor.size() - 1;
  int minEl = 0;
  int t = -1;
  while(t != k)
  {
    t = randomPartition(vetor, minEl, maxEl);
    if(t < k)
      minEl = t + 1;
    if(t > k)
      maxEl = t - 1;
  }
  return vetor[t];
}

