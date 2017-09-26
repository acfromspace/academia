// SDSU CS 560
// Algorithms
// Three Divide-and-Conquer Sort Algorithms
// Example Java Source Code

public class divideAndConquerDemo {

    static int partition(int[] A, int p, int r) {
        int temp;
        int x = A[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++)
            if (A[j] <= x) {
                i = i + 1;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        temp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = temp;
        return i + 1;
    }

    static int partition_descending(int[] A, int p, int r) {
        int temp;
        int x = A[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++)
            if (A[j] > x) {
                i = i + 1;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        temp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = temp;
        return i + 1;
    }

    static void quicksort(int[] A, int p, int r) {
        if (p < r) {
            int q = partition(A, p, r);
            quicksort(A, p, q - 1);
            quicksort(A, q + 1, r);
        }
    }

    static void quicksort_descending(int[] A, int p, int r) {
        if (p < r) {
            int q = partition_descending(A, p, r);
            quicksort_descending(A, p, q - 1);
            quicksort_descending(A, q + 1, r);
        }
    }

    static void merge(int[] data, int lo, int middle, int hi, int size) {
        int i, j;
        int[] aux = new int[size];
        for (i = middle + 1; i > lo; i--) aux[i - 1] = data[i - 1];
        for (j = middle; j < hi; j++) aux[hi + middle - j] = data[j + 1];
        for (int k = lo; k <= hi; k++)
            if (aux[j] < aux[i])
                data[k] = aux[j--];
            else
                data[k] = aux[i++];
    }

    static void mergesort(int[] data, int lo, int hi, int size) {
        if (hi <= lo) return;
        int middle = (lo + hi) / 2;
        mergesort(data, lo, middle, size);
        mergesort(data, middle + 1, hi, size);
        merge(data, lo, middle, hi, size);
    }
    
    public static void main() {
        int[] data = new int[12];
        data[0] = 12;
        data[1] = 22;
        data[2] = 15;
        data[3] = 21;
        data[4] = 19;
        data[5] = 18;
        data[6] = 20;
        data[7] = 14;
        data[8] = 16;
        data[9] = 13;
        data[10] = 11;
        data[11] = 17;
        System.out.println("====================");
        System.out.println("MERGESORT");
        mergesort(data, 0, 11, 12);
        for (int i = 0; i < 12; i++)
            System.out.println(data[i]);
        System.out.println("====================");
        System.out.println("QUICKSORT");
        quicksort(data, 0, 11);
        for (int i = 0; i < 12; i++)
            System.out.println(data[i]);
        System.out.println("====================");
        System.out.println("QUICKSORT_DESCENDING");
        quicksort_descending(data, 0, 11);
        for (int i = 0; i < 12; i++)
            System.out.println(data[i]);
        System.out.println("====================");
    }
}