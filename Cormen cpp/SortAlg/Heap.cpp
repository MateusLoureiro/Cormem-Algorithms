#include "Heap.h"
#include <iostream>
#include <vector>
#include "SortVec.h"
#include <climits>

using namespace std;

Heap::Heap(vector<int> vetor)
{
  //ctor
  this->heap = vetor;
  this->tamHeap = vetor.size();
  this->status = 0;
}

Heap::~Heap()
{
  //dtor
}

void Heap::imprime()
{
  cout << "[";
  for(int i = 0; i < this->tamHeap - 1; i++)
  {
    cout << this->heap[i] << ", ";
  }
  cout << this->heap[this->tamHeap - 1] << "]" << endl;
  cout << "Tamanho = " << this->tamHeap << endl;;
}

void Heap::trocaHeap(int a, int b)
{
  VecOp::troca(heap, a, b);
}

int Heap::parente(int num)
{
  return num / 2;
}

int Heap::direito(int num)
{
  return num * 2 + 1;
}

int Heap::esquerdo(int num)
{
  return num * 2;
}

void Heap::maxHeapify(int num)
{
  int r = this->direito(num);
  int l = this->esquerdo(num);
  int largest = num;

  if(r < tamHeap && heap[r] > heap[largest])
    largest = r;
  if(l < tamHeap && heap[l] > heap[largest])
    largest = l;
  if(largest != num)
  {
    VecOp::troca(heap, largest, num);
    maxHeapify(largest);
  }
}

void Heap::minHeapify(int num)
{
  int r = this->direito(num);
  int l = this->esquerdo(num);
  int smallest = num;

  if(r < tamHeap && heap[r] < heap[smallest])
    smallest = r;
  if(l < tamHeap && heap[l] < heap[smallest])
    smallest = l;
  if(smallest != num)
  {
    VecOp::troca(heap, smallest, num);
    minHeapify(smallest);
  }
}

void Heap::buildMaxHeap()
{
  for(int i = tamHeap / 2 - 1; i >= 0; i--)
    maxHeapify(i);
  this->status = 1;
}

void Heap::buildMinHeap()
{
  for(int i = tamHeap / 2 - 1; i >= 0; i--)
    minHeapify(i);
  this->status = 2;
}

int Heap::firstElement()
{
  if(status != 0)
    return heap[0];
  cout << "Nao existe heap, impossível mandar o primeiro elemento." << endl;
}

int Heap::extractFirst()
{
  if(tamHeap < 1)
  {
    cout << "Tamanho da heap invalido." << endl;
    return -1;
  }
  int first = heap[0];
  heap[0] = heap[tamHeap - 1];
  tamHeap--;
  if(status == 1)
    maxHeapify(0);
  if(status == 2)
    minHeapify(0);
  return first;
}

void Heap::increaseKey(int i, int key)
{
  if(key < heap[i])
  {
    cout << "Valor inválido pra key." << endl;
    return;
  }
  heap[i] = key;
  while(i > 0 && heap[parente(i)] < heap[i])
  {
    this->trocaHeap(i, parente(i));
    i = parente(i);
  }
}

void Heap::decreaseKey(int i, int newKey)
{
  if(newKey > heap[i])
  {
    cout << "Valor inválido pra key." << endl;
    return;
  }
  heap[i] = newKey;
  while(i > 0 && heap[i] < heap[parente(i)])
  {
    trocaHeap(i, parente(i));
    i = parente(i);
  }
}

void Heap::maxHeapInsert(int key)
{
  heap[tamHeap] = INT_MIN;
  increaseKey(tamHeap, key);
  tamHeap++;
}

void Heap::minHeapInsert(int key)
{
  heap[tamHeap] = INT_MAX;
  decreaseKey(tamHeap, key);
  tamHeap++;
}

vector<int> Heap::getHeap()           { return heap; }
void Heap::setHeap(vector<int> vetor) { heap = vetor; }
int Heap::getTamHeap()                { return tamHeap; }
void Heap::setTamHeap(int num)        { tamHeap = num; }
