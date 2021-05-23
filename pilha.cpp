/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1069 
Na entrada, deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."
*/
#include <iostream>
#include <string>

using namespace std;

template <class T> class Pilha {
private:

    template <class TT> class Celula {
    public:
        Celula<TT> *prox;
        TT valor;

        Celula(TT v) {
            this->valor = v;
            prox = nullptr;
        }
    };

    int tamanho;
    Celula<T> *topo;
public:

    Pilha() {
        topo = nullptr;
        tamanho = 0;
    }
    ~Pilha() {
        Celula<T> *aux;
        while(topo != nullptr) {
            aux=topo;
            topo = topo->prox;
            delete aux;
        }
    }
    int getTamanho() {
        return tamanho;
    }
    bool inserir(const T &valor) {
        if(this->topo == nullptr) {
            this->topo = new Celula<T>(valor);
        } else {
            Celula<T> *aux = new Celula<T>(valor);
            aux->prox = this->topo;
            this->topo = aux;
        }
        ++tamanho;
        return true;
    }
    bool excluir(void) {
        if(this->topo == nullptr) {
            return false;
        } else {
            Celula<T> *aux;
            aux = topo;
            this->topo = this->topo->prox;
            delete aux;
            --tamanho;
        }
        return true;
    }
    void mostrar() {
        if(this->topo == nullptr) {
            cout << "<<nada>>";
        } else {
            cout << this->topo->valor;
        }
        cout << endl;
    }
};

int main() {
    unsigned int qtd, i,j;
    cin >> qtd;
    string mina;
    int diamantes[qtd];
    Pilha<char> fila[qtd];
    for(i = 0; i < qtd; i++) {
        diamantes[i] = 0;
        cin >> mina;
        for(j = 0; j < mina.size(); j++) {
            if(mina[j] == '<') {
                fila[i].inserir('<');
            } else if(mina[j] == '>' && fila[i].getTamanho()) {
                fila[i].excluir();
                diamantes[i]++;
            }
        }
    }
    for(i = 0; i < qtd; i++) {
        cout << diamantes[i] << endl;
    }

    return 0;
}