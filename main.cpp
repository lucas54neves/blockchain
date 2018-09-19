#include <iostream>
#include <vector>
#include "block.hpp"
#include "blockchain.hpp"

using namespace std;


int main() {
    Blockchain chain;
    string dado;
    for (unsigned int i = 2; i < 7; ++i) {
        cout << "Entre com os dados do bloco " << i << endl;
        cin >> dado;
        Block testBlock(dado, chain.GetLastBlock().GetHash(), chain.Size()+1);
        chain.AddBlock(testBlock);
        
    }
    
    cout << endl;
    cout << "Tamanho da Blockchain: " << chain.Size() << endl;
    cout << endl;
    
    chain.Print();
    
    if (chain.ValidChain()) {
        cout << "Blockchain válida" << endl;
    } else {
        cout << "Blockchain inválida" << endl;
    }
    
    return 0;
}
