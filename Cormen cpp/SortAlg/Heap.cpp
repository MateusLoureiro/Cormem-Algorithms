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
  this->status = 0;
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
  this->status = 1;
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
  maxHeapify(0);
  return first;
}

vector<int> Heap::getHeap()           { return heap; }
void Heap::setHeap(vector<int> vetor) { heap = vetor; }
int Heap::getTamHeap()                { return tamHeap; }
void Heap::setTamHeap(int num)        { tamHeap = num; }
