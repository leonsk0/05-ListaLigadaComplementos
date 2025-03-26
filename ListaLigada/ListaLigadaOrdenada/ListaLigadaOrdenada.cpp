#include <iostream>
using namespace std;

struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// Headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();

//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls");
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar(); break;
		case 2: exibirQuantidadeElementos(); break;
		case 3: exibirElementos(); break;
		case 4: buscarElemento(); break;
		case 5: inserirElemento(); break;
		case 6: excluirElemento(); break;
		case 7: return;
		default: break;
		}

		system("pause");
	}
}

void inicializar()
{
	for (NO* aux = primeiro; aux != NULL; ) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}
	primeiro = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
	int nElementos = 0;
	for (NO* aux = primeiro; aux != NULL; aux = aux->prox) {
		nElementos++;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	cout << "Elementos: \n";
	for (NO* aux = primeiro; aux != NULL; aux = aux->prox) {
		cout << aux->valor << endl;
	}
}

void inserirElemento()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL) return;
	novo->valor = valor;
	novo->prox = NULL;

	if (primeiro == NULL || valor < primeiro->valor) {
		if (primeiro != NULL && primeiro->valor == valor) {
			cout << "Elemento ja existe!\n";
			free(novo);
			return;
		}
		novo->prox = primeiro;
		primeiro = novo;
		return;
	}

	for (NO* atual = primeiro; atual != NULL; atual = atual->prox) {
		if (atual->prox == NULL || atual->prox->valor > valor) {
			if (atual->valor == valor || (atual->prox != NULL && atual->prox->valor == valor)) {
				cout << "Elemento ja existe!\n";
				free(novo);
				return;
			}
			novo->prox = atual->prox;
			atual->prox = novo;
			return;
		}
	}
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia\n";
		return;
	}

	int valor;
	cout << "Digite o valor a buscar: ";
	cin >> valor;

	for (NO* aux = primeiro; aux != NULL && aux->valor <= valor; aux = aux->prox) {
		if (aux->valor == valor) {
			cout << "Elemento encontrado\n";
			return;
		}
	}
	cout << "Elemento nao encontrado\n";
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia\n";
		return;
	}

	int valor;
	cout << "Digite o valor a excluir: ";
	cin >> valor;

	if (primeiro->valor == valor) {
		NO* paraExcluir = primeiro;
		primeiro = primeiro->prox;
		free(paraExcluir);
		cout << "Elemento excluido\n";
		return;
	}

	for (NO* atual = primeiro; atual->prox != NULL && atual->prox->valor <= valor; atual = atual->prox) {
		if (atual->prox->valor == valor) {
			NO* paraExcluir = atual->prox;
			atual->prox = atual->prox->prox;
			free(paraExcluir);
			cout << "Elemento excluido\n";
			return;
		}
	}
	cout << "Elemento nao encontrado\n";
}
