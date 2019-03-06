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
    int status; //0 == NOHEAP, 1 == MAXHEAP, 2 == MINHEAP

  public:
    Heap(vector<int> vetor);
    ~Heap();

    void imprime ();
    void trocaHeap(int a, int b);
    int  parente (int num);
    int  direito (int num);
    int  esquerdo(int num);
    void maxHeapify(int num);
    void minHeapify(int num);
    void buildMaxHeap();
    void buildMinHeap();
    int  firstElement();
    int  extractFirst();
    void increaseKey(int index, int newKey);
    void decreaseKey(int index, int newKey);
    void maxHeapInsert(int key);
    void minHeapInsert(int key);

    ///GETTERS AND SETTERS
    vector<int> getHeap();
    void setHeap(vector<int> vetor);
    int getTamHeap();
    void setTamHeap(int num);

};

#endif // HEAP_H
