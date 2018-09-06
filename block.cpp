#include "block.hpp"

Block::Block(unsigned index, const string &data) : mIndex(index), mData(data) {


    mHash = CalculateHash();
}
