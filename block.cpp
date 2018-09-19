#include <ctime>
#include <string>
#include <sstream>
#include "block.hpp"
#include "sha256.hpp"

Block::Block(string data, string previousHash, uint32_t i) {
    this->mData = data;
	this->mPreviousHash = previousHash;
	this->mTimeStamp = time(0);
	this->mHash = CalculateHash();
	this->mIndex = i;
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

time_t Block::GetTime() {
    return this->mTimeStamp;
}

uint32_t Block::GetIndex() {
    return this->mIndex;
}

void Block::ModPreviousHash(string hash) {
    mPreviousHash = hash;
}

string Block::CalculateHash() {
    stringstream ss;
    ss << mTimeStamp << mData << mPreviousHash << mIndex;
 
    return sha256(ss.str());
}
