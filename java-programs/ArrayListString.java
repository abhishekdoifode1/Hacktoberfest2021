import java.util.ArrayList;

public class ArrayListString {

	/**
	 * Método principal de execução da Classe
	 */
	public static void main(String[] args) {

		// declarar e instanciar uma lista de String
		ArrayList<String> listaString = new ArrayList<String>();

		// adicionar registros na lista
		listaString.add("Elemento 1");
		listaString.add("Elemento 2");
		listaString.add("Elemento 3");

		// exibindo o conteúdo da lista
		System.out.println(listaString.get(0));
		System.out.println(listaString.get(1));
		System.out.println(listaString.get(2));

		// adicionando elemento em uma posição especifica
		listaString.add(1, "Elemento 1.5");

		// varrendo a lista para exibir ao usuário
		for (String obj : listaString) {
			System.out.println(obj);
		}

		// obtendo o tamanho da lista
		System.out.println("O tamanho da lista é:" + listaString.size());

		// pesquisando um valor especifico na lista
		if (listaString.contains("Elemento 1")) {
			System.out.println("Elemento encontrado");
		} else {
			System.out.println("Elemento não encontrado ");
		}

		// descobrindo o indice do Elemento pesquisado
		int indice = listaString.indexOf("Elemento 1");
		System.out.println("Indice: " + indice);

		// adicionando um novo elemento na lista
		listaString.add("Elemento 4");

		// obtendo o tamanho da lista
		System.out.println("O tamanho da lista é:" + listaString.size());

		// removendo um elemento da lista
		listaString.remove("Elemento 1.5");
		for (String obj : listaString) {
			System.out.println(obj);
		}

		// obtendo o tamanho da lista
		System.out.println("O tamanho da lista é:" + listaString.size());

	}

}
