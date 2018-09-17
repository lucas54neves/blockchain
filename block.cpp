#include <ctime>
#include <string>
#include "block.hpp"

Block::Block(string data, string previousHash ) {
    this->mData = data;
	this->mPreviousHash = previousHash;
	this->mTimeStamp = time(0);
}

string Block::GetData() {
    return this->mData;
}

string Block::GetPreviousHash() {
    return this->mPreviousHash;
}

string Block::GetHash() {
    return this->mHash;
}

void Block::ModPreviousHash(string hash) {
    mHash = hash;
}
