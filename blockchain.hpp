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
	    uint32_t Size();  // contém a quantidade atual de blocos contidos na blockchain
	    void Print();
	    Block GetLastBlock() const;
	private:
	    vector<Block> mChain;
};

#endif // BLOCKCHAIN_HPP
