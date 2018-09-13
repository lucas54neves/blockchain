#include <iostream>
#include <vector>
#include "block.hpp"

using namespace std;

typedef std::vector<Block> blockchain;

int main() {
    blockchain chain;
    Block B1("D1asds", "hash1");
    chain.push_back(B1);
    Block B2("D2sfd", "hash2");
    chain.push_back(B2);
    Block B3("D3asd", "hash3");
    chain.push_back(B3);
    cout << "Tamanho: " << chain.size() << endl;
     
    for(blockchain::iterator j = chain.begin();
     j != chain.end(); j++)
     	cout << (j)->GetData() << endl; 
    return 0;
}
