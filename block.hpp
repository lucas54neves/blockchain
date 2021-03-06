#ifndef BLOCK_HPP
#define BLOCK_HPP

using namespace std;

typedef string Type;

class Block {
    public:
	    Block(Type data, string previousHash, uint32_t i);
	    Type GetData();
	    string GetPreviousHash();
	    string GetHash();
	    time_t GetTime();
	    uint32_t GetIndex();
	    void ModPreviousHash(string hash);
	    string CalculateHash();
	private:
	    Type mData; //our data will be a simple message.
	    time_t mTimeStamp; //as number of milliseconds since 1/1/1970.
       string mHash;
	    string mPreviousHash;
	    uint32_t mIndex;
};

#endif // BLOCK_HPP
