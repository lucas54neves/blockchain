#include <iostream>
#include <vector>
#include "blockchain.hpp"
#include "block.hpp"

Blockchain::Blockchain() {
    mChain.emplace_back(Block("Bloco gênesis", "0"));
}

void Blockchain::AddBlock(Block newBlock) {
    newBlock.ModPreviousHash(GetLastBlock().GetHash());
    mChain.push_back(newBlock);
}

bool Blockchain::ValidChain() {
    for (unsigned i = 1; i < mChain.size(); ++i) {
        cout << mChain[i].GetHash() << endl;
        cout << mChain[i].GetPreviousHash() << endl;
        if (mChain[i].GetHash() != mChain[i].GetPreviousHash()) {
            return false;
        }
    }
    return true;
}

Block Blockchain::GetLastBlock() const {
    return mChain.back();
}

unsigned Blockchain::Size() {
    return mChain.size();
}
