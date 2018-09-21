#include <iostream>
#include <vector>
#include "blockchain.hpp"
#include "block.hpp"

Blockchain::Blockchain() {
    mChain.emplace_back(Block("Bloco gênesis", "0", Size()+1));
}

void Blockchain::AddBlock(Block newBlock) {
    newBlock.ModPreviousHash(GetLastBlock().GetHash());
    mChain.push_back(newBlock);
}

bool Blockchain::ValidChain() {
    for (unsigned i = 1; i < mChain.size(); ++i) {
        if ((mChain[i-1].GetHash() != mChain[i].GetPreviousHash()) || (mChain[i-1].GetTime() > mChain[i].GetTime()) || (mChain[i-1].GetIndex() > mChain[i].GetIndex())) {
            return false;
        }
    }
    return true;
}

Block Blockchain::GetLastBlock() const {
    return mChain.back();
}

uint32_t Blockchain::Size() {
    return mChain.size();
}

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
