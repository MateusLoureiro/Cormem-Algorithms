#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "SortVec.h"


using namespace std;

class Heap
{
  private:
    vector<int> heap;
    int tamHeap;

  public:
    Heap(vector<int> vetor);
    ~Heap();

    void imprime ();
    int  parente (int num);
    int  direito (int num);
    int  esquerdo(int num);
    void maxHeapify(int num);
    void buildHeap();

  protected:
};

#endif // HEAP_H
