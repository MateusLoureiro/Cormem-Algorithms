#ifndef SORTVEC_H
#define SORTVEC_H

#include <vector>

using namespace std;

class VecOp
{
  public:
    static vector<int> cria(int modo);
    static void imprime(vector<int> vetor);
    static void imprime(vector<int> vetor, int inicio, int ultimo);
    static void troca(vector<int> &vetor, int a, int b);
    static int searchSup(vector<int> &vetor, int numBuscado, int maximo);
    static int binarySearchSup(vector<int> &vetor, int numBuscado, int inicio, int maximo);
    static void bubbleSort(vector<int> &vetor);
    static void insertionSort(vector<int> &vetor);
    static void insertionSortNI(vector<int> &vetor);
    static void binaryInsertionSort(vector<int> &vetor);
    static void selectionSort(vector<int> &vetor);
    static int mergeVectors(vector<int> &vetor, int inicio, int meio, int ultimoIndice);
    static int mergeSort(vector<int> &vetor, int inicio, int ultimoIndice);
    static void heapSort(vector<int> &vetor);
    static void maximumSubarrayBF(vector<int> vetor);
    static void maximumSubarrayDC(vector<int> vetor);
    static void maximumSubarrayLT(vector<int> vetor);
};


#endif // SORTVEC_H
