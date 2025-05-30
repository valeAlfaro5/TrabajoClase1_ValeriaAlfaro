//VALERIA ALFARO
#include <iostream>
#include <ctime>
using namespace std;

//basado en clase
void insertsort(int array[], int n){
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

//buscado en internet
void heapify(int array[], int n, int i) {
    int mayor = i;        
    int left = 2 * i + 1;      
    int right = 2 * i + 2;      

    if (left < n && array[left] > array[mayor])
        mayor = left;

    if (right < n && array[right] > array[mayor])
        mayor = right;
   
    if (mayor != i) {
        swap(array[i], array[mayor]);
        heapify(array, n, mayor);
    }
}

void heapsort(int array[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

//funcion de partition buscada en internet
int partition(int array[], int low, int high) {
  
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);  
    return i + 1;
}

//basado en examen
void quicksort(int array[], int low, int high){
    if(high-low <=0){
        return;
    }else{
        int pivot = partition(array, low, high);
        int i = low - 1;
        
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

//basado en clase
void bubblesort(int array[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

//basado en clase
void selectionsort(int array[], int n){
    for (int i =1; i<n-1; i++){
        int min =i ;
        for (int j = i+1; j<n; j++){
            if(array[j]<array[min]){
                min =j;
            }
        }
        if(min != i){
            swap(array[i], array[min]);
        }
    }
}

//basado en clase version mia
void mergesort(int array[], int n) {
    if (n <= 1){return;}

        int half = n / 2;
        int* left = new int[half];
        int* right = new int[n - half];

        for (int i = 0; i < half; i++) left[i] = array[i];
        for (int i = half; i < n; i++) right[i - half] = array[i];

        mergesort(left, half);
        mergesort(right, n - half);

        // mezclar
        int i = 0, j = 0, k = 0;
        while (i < half && j < n - half) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }
        while (i < half) array[k++] = left[i++];
        while (j < n - half) array[k++] = right[j++];

        delete[] left;
        delete[] right;
  
}

//funcion para presentar el arreglo
void presentar(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " , ";
    }
    cout<<endl;
}

int main()
{
    int n =1100000;
    int* arreglo = new int[n];  

    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 1000; 
    }
    
    unsigned t0, t1;
    int entrada=0;
 
    t0=clock();
    t1 = clock();
     
    // presentar(arreglo, n);
    cout<<"Tipos de Sort y Su Tiempo de Ejecución\n1. BubbleSort \n2. SelectionSort\n3. InsertSort\n4. QuickSort\n5.MergeSort\n6.HeapSort\nOpción deseada: ";
    cin>>entrada;
    
    switch(entrada){
        case 1:{//bubblesort
            cout<<"Utilizando BubbleSort para ordenar..."<<endl;
            t0 = clock();
            bubblesort(arreglo, n);
            t1 = clock();
        break;
        }
        
        case 2:{//selectionsort
            cout<<"Utilizando SelectionSort para ordenar..."<<endl;
            t0 = clock();
            selectionsort(arreglo, n);
            t1= clock();
        break;
        }
        case 3:{//insertsort
            cout<<"Utilizando InsertSort para ordenar..."<<endl;
            t0 = clock();
            insertsort(arreglo, n);
            t1= clock();
        break;
        }
        
        case 4:{//quicksort
            cout<<"Utilizando QuickSort para ordenar..."<<endl;
            t0 = clock();
            quicksort(arreglo, 0, n-1);
            t1= clock();
        break;
        }
        
        case 5:{//mergesort
            cout<<"Utilizando MergeSort para ordenar..."<<endl;
            t0 = clock();
            mergesort(arreglo, n);
            t1= clock();
        break;
        }
        
        case 6:{//heapsort
            cout<<"Utilizando HeapSort para ordenar..."<<endl;
            t0 = clock();
            heapsort(arreglo, n);
            t1 = clock();
        break;
        }
    }
    // presentar(arreglo, n);
    //muestra tiempo de ejecución
    double time = double(t1 - t0) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución: " << time << " segundos" << endl;

    return 0;
}

