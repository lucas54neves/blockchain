#include <iostream>
#include <vector>
#include "block.hpp"
#include "blockchain.hpp"

using namespace std;


int main() {
    Blockchain chain;
    Block testBlock("Dado teste", "0");
    chain.AddBlock(testBlock);
    if (chain.ValidChain()) {
        cout << "Válida" << endl;
    } else {
        cout << "Inválida" << endl;
    }
    
    cout << "Tamanho: " << chain.Size() << endl;


/*    blockchain chain;
    Block B1("D1asds", "hash1");
    chain.push_back(B1);
    Block B2("D2sfd", "hash2");
    chain.push_back(B2);
    Block B3("D3asd", "hash3");
    chain.push_back(B3);
    cout << "Tamanho: " << chain.size() << endl;
     
    for(blockchain::iterator j = chain.begin();
     j != chain.end(); j++)
     	cout << (j)->GetData() << endl; */
    return 0;
}
