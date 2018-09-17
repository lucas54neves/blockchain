#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

using namespace std;

#include <vector>
#include "block.hpp"

class Blockchain {
    public:
	    Blockchain();
	    void AddBlock(Block newBlock);
	    bool ValidChain();
	    unsigned Size();
	private:
	    vector<Block> mChain;
	    Block GetLastBlock() const;
};

#endif // BLOCKCHAIN_HPP
