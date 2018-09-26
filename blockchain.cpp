#include <iostream>
#include <vector>
#include "blockchain.hpp"
#include "block.hpp"

// Construtor da blockchain usando o Bloco Gênesis
Blockchain::Blockchain() {
    mChain.emplace_back(Block("Bloco gênesis", "0", Size()+1));
}

// Adiciona um novo bloco à blockchain
void Blockchain::AddBlock(Block newBlock) {
    newBlock.ModPreviousHash(GetLastBlock().GetHash());
    mChain.push_back(newBlock);
}

// Valida a blockchain usando as Hash, o tempo de criação e o índice dos blocos
bool Blockchain::ValidChain() {
    for (unsigned i = 1; i < mChain.size(); ++i) {
        if ((mChain[i-1].GetHash() != mChain[i].GetPreviousHash()) || (mChain[i-1].GetTime() > mChain[i].GetTime()) || (mChain[i-1].GetIndex() > mChain[i].GetIndex())) {
            return false;
        }
    }
    return true;
}

// Retorna o último bloco da blockchain
Block Blockchain::GetLastBlock() const {
    return mChain.back();
}

// Retorna o tamanho da blockchain
uint32_t Blockchain::Size() {
    return mChain.size();
}

// Imprime a blockchain a fim de depuração
void Blockchain::Print() {
    for (uint32_t i = 0; i < Size(); ++i) {
        cout << "Block " << mChain[i].GetIndex() << endl;
        cout << "Data: " << mChain[i].GetData() << endl;
        cout << "Previous Hash: " << mChain[i].GetPreviousHash() << endl;
        cout << "Hash: " << mChain[i].GetHash() << endl;
        cout << "Time: " << mChain[i].GetTime() << endl;
        cout << endl;
    }
}
