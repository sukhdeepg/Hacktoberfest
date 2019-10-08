/**
 * Classe que implementa a estratégia de Counting Sort vista em sala. Procure
 * evitar desperdicio de memoria alocando o array de contadores com o tamanho
 * sendo o máximo inteiro presente no array a ser ordenado.
 *
 */
public class CountingSort extends AbstractSorting<Integer> {

	@Override
	public void sort(Integer[] array, int leftIndex, int rightIndex) {

		if ((leftIndex < rightIndex) && (rightIndex < array.length)) {
			countingSort(array, leftIndex, rightIndex);
		}
	}

	private void countingSort(Integer[] array, int leftIndex, int rightIndex) {

		//Criando array de frequencia zerada
		int[] frequencia = new int[maiorIndice(array, leftIndex, rightIndex) + 1];

		//Contando a frequencia
		for (int i = leftIndex; i <= rightIndex; i++){
			int key = array[i];
			frequencia[key] += 1;
		}

		//Somando frequencia[i] e frequencia[i-1]
		for (int i = 1; i < frequencia.length; i++){ //
			frequencia[i] += frequencia[i-1];
		}

		//Inserindo o numero na posição certa
		int[] resultado = new int[array.length];
		for (int i = leftIndex; i <= rightIndex; i++){
			resultado[frequencia[array[i]]-1] = array[i];
			frequencia[array[i]]--;
		}

		//Transmitindo resultado para o array original
		int index = 0;
		for (int i = leftIndex; i <= rightIndex; i++) {
			array[i] = resultado[index];
			index++;
		}

	}

	private int maiorIndice (Integer[] array, int leftIndex, int rightIndex) {
		int maior = leftIndex;
		for (int index = leftIndex + 1; index <= rightIndex; index++) {
			if (array[index] > array[maior]){
				maior = index;
			}
		}
		return array[maior];
	}
	
}