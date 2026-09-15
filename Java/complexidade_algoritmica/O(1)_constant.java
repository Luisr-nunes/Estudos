class O_1_constant {
    public static int acessarElemento(int[] array, int indice) {
        return array[indice];  // Sempre O(1)
    }

    public static void main(String[] args) {
        int[] array = {10, 20, 30};
        System.out.println(acessarElemento(array, 1));
    }
}
