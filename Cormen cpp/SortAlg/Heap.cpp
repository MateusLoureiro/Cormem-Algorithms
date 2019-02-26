#include "Heap.h"
#include <iostream>
#include <vector>
#include "SortVec.h"

using namespace std;

Heap::Heap(vector<int> vetor)
{
  //ctor
  this->heap = vetor;
  this->tamHeap = vetor.size();
}

Heap::~Heap()
{
  //dtor
}

void Heap::imprime()
{
  cout << "[";
  for(int i = 0; i < this->heap.size() - 1; i++)
  {
    cout << this->heap[i] << ", ";
  }
  cout << this->heap[this->heap.size() - 1] << "]" << endl;
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

void Heap::buildMaxHeap()
{
  for(int i = tamHeap / 2 - 1; i >= 0; i--)
    maxHeapify(i);
}

vector<int> Heap::getHeap()           { return heap; }
void Heap::setHeap(vector<int> vetor) { heap = vetor; }
int Heap::getTamHeap()                { return tamHeap; }
void Heap::setTamHeap(int num)        { tamHeap = num; }
