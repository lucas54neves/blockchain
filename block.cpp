#include <ctime>
#include <string>
#include <sstream>
#include "block.hpp"
#include "sha256.hpp"

// Construtor do bloco, utilizando como parâmetro do dado de entrada,
// a hash do último bloco da blockchain e o índice do novo bloco.
Block::Block(Type data, string previousHash, uint32_t i) {
   this->mData = data;
	this->mPreviousHash = previousHash;
	this->mTimeStamp = time(0);
	this->mHash = CalculateHash();
	this->mIndex = i;
}

// Retorna o dado armazenado no bloco
Type Block::GetData() {
    return this->mData;
}

// Retorna a hash do bloco anterior lincado ao bloco atual
string Block::GetPreviousHash() {
    return this->mPreviousHash;
}

// Retorna a hash do bloco atual
string Block::GetHash() {
    return this->mHash;
}

// Retorna o tempo que o bloco foi criado
time_t Block::GetTime() {
    return this->mTimeStamp;
}

// Retorna o índice do bloco
uint32_t Block::GetIndex() {
    return this->mIndex;
}

// Insere a hash do bloco anterior ao bloco atual
// Método necessário porque o atributo mPreviousHash está como privado
void Block::ModPreviousHash(string hash) {
    mPreviousHash = hash;
}

// Calcula a hash do bloco atual
string Block::CalculateHash() {
    stringstream ss;
    ss << mTimeStamp << mData << mPreviousHash << mIndex;
 
    return sha256(ss.str());
}
