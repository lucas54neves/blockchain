#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>

using namespace std;

class Block {
    public:
        string mPrevHash;
        string mHash;
    
        Block(unsigned index, const string &data);
        void Mine(unsigned int difficulty);
    private:
        unsigned int mIndex;
        unsigned int mTimeStamp;
        string mData;
        unsigned int mNonce;
        
        string CalculeHash() const;
};

#endif
