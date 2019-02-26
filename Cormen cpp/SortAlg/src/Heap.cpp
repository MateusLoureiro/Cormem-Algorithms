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
  int largest = heap(num);

  if(r < tamHeap && heap(r) > largest)
    largest = heap(r);
  if(l < tamHeap && heap(l) > largest)
    largest = heap(l);
  if(largest != heap(num))
  {
    VecOp::troca(largest, num);
    this.maxHeapify(largest);
  }
}
