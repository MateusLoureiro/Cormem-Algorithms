/* Library by Mateus Lucena Loureiro
 *
 *  TODO: -implementar matriz (Os 3 algoritmos de multiplicação);
 *        -implementar os 3 algoritmos de maior subarray
 *
 *
 */

#include <iostream>
#include <vector>
#include "SortVec.h"
#include "Heap.h"

using namespace std;

int menu();

int main()
{
  vector<int> vetor = VecOp::cria(1);

  cout << "Vetor original:" << endl;
  VecOp::imprime(vetor);
  cout << endl;

///TESTE DAS FUNÇOES SORT
//{
//  int metodo = 0;
//  while(metodo < 1 || metodo > 8)
//  {
//    metodo = menu();
////    metodo = 6;
//    switch(metodo){
//      case(1):
//        cout << "Metodo Escolhido: BubbleSort." << endl << endl;
//        VecOp::bubbleSort(vetor);
//        break;
//      case(2):
//        cout << "Metodo Escolhido: InsertionSort." << endl << endl;
//        VecOp::insertionSort(vetor);
//        break;
//      case(3):
//        cout << "Metodo Escolhido: (Non Increasing)InsertionSort." << endl << endl;
//        VecOp::insertionSortNI(vetor);
//        break;
//      case(4):
//        cout << "Metodo Escolhido: BinaryInsertionSort." << endl << endl;
//        VecOp::binaryInsertionSort(vetor);
//        break;
//      case(5):
//        cout << "Metodo Escolhido: SelectionSort." << endl << endl;
//        VecOp::selectionSort(vetor);
//        break;
//      case(6):
//      {
//        cout << "Metodo Escolhido: MergeSort." << endl;
//        int inv = VecOp::mergeSort(vetor, 0, vetor.size() - 1);
//        cout << "Número de inversões: " << inv << endl;
//        break;
//      }
//      case(7):
//        cout << "Metodo Escolhido: QuickSort." << endl << endl;
//        break;
//      case(8):
//        cout << "Metodo Escolhido: HeapSort." << endl << endl;
//        VecOp::heapSort(vetor);
//        break;
//      default:
//        cout << "Escolha inválida, favor escolher um número válido." << endl << endl;
//        break;
//    }
//    cout << endl;
//  }
//  cout << "Vetor ordenado:" << endl;
//  VecOp::imprime(vetor);
//}

/////TESTE DAS FUNÇOES MAXIMUM SUBARRAY
//{
//  enum mapSubarrayObj {SOMA, INICIO, ULTIMO};
//  int[3] espec; //a[SOMA] == soma, a[INICIO] == inicio, a[ULTIMO] == ultimo;
//  VecOp::maximumSubarrayBF(vetor);
//  ///TIRAR O SEGMENTATION FAULT (a causa é a mistura entre array e ponteiro; facilmente resolvida com uma struct.)
//  VecOp::maximumSubarrayDC(vetor);
//  VecOp::maximumSubarrayLT(vetor);
//}

  Heap* heap = new Heap(vetor);
  heap->buildMinHeap();
  heap->imprime();
  heap->decreaseKey(9, 0);
//  heap->minHeapInsert(1000);
  heap->imprime();
  cout << "Primeiro elemento: " << heap->firstElement() << endl;
  cout << "Extraindo primeiro elemento: " << heap->extractFirst() << endl;
  cout << "Extraindo segundo elemento: " << heap->extractFirst() << endl;
  cout << "Extraindo terceiro elemento: " << heap->extractFirst() << endl;
  cout << "Extraindo quarto elemento: " << heap->extractFirst() << endl;
  heap->imprime();


  return 0;
}

int menu()
{
  cout << "Escolha um dos métodos abaixo para perfazer a ordenação:" << endl;
  cout << "1: BubbleSort;" << endl;
  cout << "2: InsertionSort;" << endl;
  cout << "3: (Non Increasing)InsertionSort;" << endl;
  cout << "4: BinaryInserionSort;" << endl;
  cout << "5: SelectionSort;" << endl;
  cout << "6: MergeSort (também dá o número de inversões);" << endl;
  cout << "7: QuickSort;" << endl;
  cout << "8: HeapSort." << endl;
  cout << endl << "Escolha: ";
  int escolha;
  cin >> escolha;
  return escolha;
}
