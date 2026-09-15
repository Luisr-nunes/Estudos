class O_n_linear {
    public static int buscaLinear(int[] array, int alvo) {
        for (int i = 0; i < array.length; i++) {  // Um loop → O(n)
            if (array[i] == alvo) {
                return i;
            }
        }
        return -1;  // Elemento não encontrado
    }

    public static void main(String[] args) {
        int[] array = {4, 7, 2, 9, 1};
        int alvo = 9;
        System.out.println("Índice encontrado: " + buscaLinear(array, alvo));
    }
}