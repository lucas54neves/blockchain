#ifndef BLOCK_HPP
#define BLOCK_HPP

using namespace std;

class Block {
    public:
	    Block(string data, string previousHash);
	    string GetData();
	    string GetPreviousHash();
	    string GetHash();
	    void ModPreviousHash(string hash);
	private:
	    string mData; //our data will be a simple message.
	    time_t mTimeStamp; //as number of milliseconds since 1/1/1970.
        string mHash;
	    string mPreviousHash;
	    uint32_t mIndex;
};

#endif // BLOCK_HPP
