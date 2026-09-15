class OQuadratico {
    public static void bubbleSort(int[] array) {
        for (int i = 0; i < array.length; i++) {            // Loop 1
            for (int j = 0; j < array.length - 1; j++) {    // Loop 2 → O(n²)
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] array = {5, 3, 8, 1, 2};
        bubbleSort(array);

        for (int value : array) {
            System.out.print(value + " ");
        }
    }
}

