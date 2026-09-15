class O_n_log_n_log_linear {
    public static void mergeSort(int[] array, int esq, int dir) {
        // Divide (log n) + combina (n) = O(n log n)
    }

    public static void main(String[] args) {
        int[] array = {8, 3, 1, 7, 0, 10};
        mergeSort(array, 0, array.length - 1);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }
}
