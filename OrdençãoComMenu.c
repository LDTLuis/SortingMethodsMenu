#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define TAM 50000
#define STRTAM 65
#define MAX_VAL 200000

void criarMenuLinhaSuperior(){
    int i;
    printf("%c",201);
    for(i = 0; i < STRTAM; i++)
        printf("%c", 205);
    printf("%c\n", 187);

}

void criarMenuRodape(int tamX){
    int i;
    printf("%c",200);
    for(i = 0; i < STRTAM; i++)
        printf("%c", 205);
    printf("%c", 188);

}

void criarMenuLinhaHorizontal(int tamX){
    int i;
    printf("%c", 204);
    for(i = 0; i < tamX; i++)
        printf("%c", 205);
    printf("%c\n", 185);

}

void criarMenu(int tamX, char str[]){
    int i;
    int contaLetras = 0;

    for(i = 0; i < tamX; i++)
        if(str[i] == '\0')
            break;
        else
            contaLetras++;

    printf("%c", 186);
    mudarCor("\033[32m");
    printf("%s", str);
    mudarCor("\e[0;37m");
    while(contaLetras < tamX){
        printf("%c", 32);
        contaLetras++;
    }
    printf("%c\n", 186);

}

void mudarCor(const char* cor) {
    printf("%s", cor);
}

void esconderCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Esconde o cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void mostrarCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;  // Mostra o cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void preencherArray(int vec[], int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 200000 + 1;
    }
}

double medirTempo(void (*func)(int[], int), int vec[], int n) {
    clock_t start, end;
    start = clock();
    func(vec, n);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void imprimirArray(int vec[], int n) {
    for (int i = 0; i < 200 && i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("... ");
    for (int i = n - 200; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Funções de ordenação

void bubbleSort(int vec[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int vec[], int n) {
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void selectionSort(int vec[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIdx]) {
                minIdx = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[minIdx];
        vec[minIdx] = temp;
    }
}

void heapify(int vec[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest]) {
        largest = left;
    }
    if (right < n && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = vec[i];
        vec[i] = vec[largest];
        vec[largest] = temp;
        heapify(vec, n, largest);
    }
}

void heapSort(int vec[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vec, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = vec[0];
        vec[0] = vec[i];
        vec[i] = temp;
        heapify(vec, i, 0);
    }
}

int partition(int vec[], int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    int temp = vec[i + 1];
    vec[i + 1] = vec[high];
    vec[high] = temp;
    return i + 1;
}

void quickSort(int vec[], int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void merge(int vec[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = vec[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vec[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k++] = L[i++];
        } else {
            vec[k++] = R[j++];
        }
    }

    while (i < n1) {
        vec[k++] = L[i++];
    }

    while (j < n2) {
        vec[k++] = R[j++];
    }
}

void mergeSort(int vec[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

void shellSort(int vec[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vec[i];
            int j = i;
            while (j >= gap && vec[j - gap] > temp) {
                vec[j] = vec[j - gap];
                j -= gap;
            }
            vec[j] = temp;
        }
    }
}

void radixSort(int vec[], int n) {
    int max = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(vec[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(vec[i] / exp) % 10] - 1] = vec[i];
            count[(vec[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            vec[i] = output[i];
        }
    }
}

void countingSort(int *vec, int size) {
    int count[MAX_VAL + 1] = {0};

    for (int i = 0; i < size; i++) {
        count[vec[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= MAX_VAL; i++) {
        while (count[i] > 0) {
            vec[index++] = i;
            count[i]--;
        }
    }
}

void combSort(int vec[], int n) {
    int gap = n;
    float shrink = 1.3;
    int swapped = 0;

    while (gap > 1 || swapped == 0) {
        if (gap > 1) {
            gap = (int)(gap / shrink);
        }

        swapped = 1;
        for (int i = 0; i + gap < n; i++) {
            if (vec[i] > vec[i + gap]) {
                int temp = vec[i];
                vec[i] = vec[i + gap];
                vec[i + gap] = temp;
                swapped = 0;
            }
        }
    }
}


int main() {
    int vec[TAM] = {};
    int opcao;
    double tempos[11] = {0};
    int i;

    while (1) {
        sleep(2);
        mostrarCursor();
        criarMenuLinhaSuperior();
        criarMenu(STRTAM, "Menu Principal");
        criarMenuLinhaHorizontal(STRTAM);
        criarMenu(STRTAM, "(01) Preencher o array com numeros aleatorios");
        criarMenu(STRTAM, "(02) Ordenar o array pelo metodo Bubble Sort");
        criarMenu(STRTAM, "(03) Ordenar o array pelo metodo Insertion Sort");
        criarMenu(STRTAM, "(04) Ordenar o array pelo metodo Selection Sort");
        criarMenu(STRTAM, "(05) Ordenar o array pelo metodo Heap Sort");
        criarMenu(STRTAM, "(06) Ordenar o array pelo metodo Quick Sort");
        criarMenu(STRTAM, "(07) Ordenar o array pelo metodo Merge Sort");
        criarMenu(STRTAM, "(08) Ordenar o array pelo metodo Shell Sort");
        criarMenu(STRTAM, "(09) Ordenar o array pelo metodo Radix Sort");
        criarMenu(STRTAM, "(10) Ordenar o array pelo metodo Counting Sort");
        criarMenu(STRTAM, "(11) Ordenar o array pelo metodo Comb Sort");
        criarMenu(STRTAM, "(12) Imprimir resultados dos metodos de ordenacao executados");
        criarMenu(STRTAM, "(13) Executar todos os metodos de ordenacao");
        criarMenu(STRTAM, "(14) Imprimir o array");
        criarMenu(STRTAM, "(00) Encerrar o programa");
        criarMenuRodape(STRTAM);
        printf("\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        esconderCursor();

        switch(opcao) {
            case 1:
                system("cls");
                preencherArray(vec, TAM);
                printf("array preenchido com numeros aleatorios.\n");
                sleep(3);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Organizando...");
                tempos[0] = medirTempo(bubbleSort, vec, TAM);
                system("cls");
                printf("Bubble Sort concluido em %.6f segundos.\n", tempos[0]);
                sleep(3);
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Organizando...");
                tempos[1] = medirTempo(insertionSort, vec, TAM);
                system("cls");
                printf("Insertion Sort concluido em %.6f segundos.\n", tempos[1]);
                sleep(3);
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Organizando...");
                tempos[2] = medirTempo(selectionSort, vec, TAM);
                system("cls");
                printf("Selection Sort concluido em %.6f segundos.\n", tempos[2]);
                sleep(3);
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Organizando...");
                tempos[3] = medirTempo(heapSort, vec, TAM);
                system("cls");
                printf("Heap Sort concluido em %.6f segundos.\n", tempos[3]);
                sleep(3);
                system("cls");
                break;
            case 6:
                system("cls");
                printf("Organizando...");
                tempos[4] = medirTempo(quickSort, vec, TAM);
                system("cls");
                printf("Quick Sort concluido em %.6f segundos.\n", tempos[4]);
                sleep(3);
                system("cls");
                break;
            case 7:
                system("cls");
                printf("Organizando...");
                tempos[5] = medirTempo(mergeSort, vec, TAM);
                system("cls");
                printf("Merge Sort concluido em %.6f segundos.\n", tempos[5]);
                sleep(3);
                system("cls");
                break;
            case 8:
                system("cls");
                printf("Organizando...");
                tempos[6] = medirTempo(shellSort, vec, TAM);
                system("cls");
                printf("Shell Sort concluido em %.6f segundos.\n", tempos[6]);
                sleep(3);
                system("cls");
                break;
            case 9:
                system("cls");
                printf("Organizando...");
                tempos[7] = medirTempo(radixSort, vec, TAM);
                system("cls");
                printf("Radix Sort concluido em %.6f segundos.\n", tempos[7]);
                sleep(3);
                system("cls");
                break;
            case 10:
                system("cls");
                printf("Organizando...");
                tempos[8] = medirTempo(countingSort, vec, TAM);
                system("cls");
                printf("Counting Sort concluido em %.6f segundos.\n", tempos[8]);
                sleep(3);
                system("cls");
                break;
            case 11:
                system("cls");
                printf("Organizando...");
                tempos[9] = medirTempo(combSort, vec, TAM);
                system("cls");
                printf("Comb Sort concluido em %.6f segundos.\n", tempos[9]);
                sleep(3);
                system("cls");
                break;
            case 12:
                esconderCursor();
                mudarCor("\e[0;37m");
                system("cls");
                printf("Carregando...");
                sleep(1);
                system("cls");
                printf("33%%\n");
                mudarCor("\033[32m");
                printf("||||||||");
                mudarCor("\e[0;37m");
                sleep(3);
                system("cls");
                printf("66%%\n");
                mudarCor("\033[32m");
                printf("||||||||||||||||");
                mudarCor("\e[0;37m");
                sleep(3);
                system("cls");
                printf("99%%\n");
                mudarCor("\033[32m");
                printf("|||||||||||||||||||||||||");
                mudarCor("\e[0;37m");
                sleep(2);
                system("cls");
                printf("100%%\n");
                mudarCor("\033[32m");
                printf("|||||||||||||||||||||||||||");
                mudarCor("\e[0;37m");
                system("cls");
                mostrarCursor();
                printf("\nTempos de execucao:\n");
                for (i = 0; i < 10; i++) {
                    printf("metodo %d: %.6f segundos.\n", i + 1, tempos[i]);
                printf("\n");
                }
                break;
            case 13:
                tempos[0] = medirTempo(bubbleSort, vec, TAM);
                tempos[1] = medirTempo(insertionSort, vec, TAM);
                tempos[2] = medirTempo(selectionSort, vec, TAM);
                tempos[3] = medirTempo(heapSort, vec, TAM);
                tempos[4] = medirTempo(quickSort, vec, TAM);
                tempos[5] = medirTempo(mergeSort, vec, TAM);
                tempos[6] = medirTempo(shellSort, vec, TAM);
                tempos[7] = medirTempo(radixSort, vec, TAM);
                tempos[8] = medirTempo(countingSort, vec, TAM);
                tempos[9] = medirTempo(combSort, vec, TAM);
                printf("\nTodos os metodos de ordenacao concluidos.\n");
                sleep(1);
                system("cls");
                break;
            case 14:
                system("cls");
                imprimirArray(vec, TAM);
                break;
            case 0:
                system("cls");
                printf("Encerrando o programa...\n");
                return 0;
            default:
                system("cls");
                printf("Opcao invalida. Tente novamente.\n");
                sleep(2);
                system("cls");
        }
    }
}
