// Crypto/MyAes.h

#ifndef __CRYPTO_MY_BLOW_H
#define __CRYPTO_MY_BLOW_H

#include "../../../C/Aes.h"

#include "../../Common/MyCom.h"

#include "../ICoder.h"

#include <cstring>
#include <algorithm>

namespace NCrypto {

    class Blowfish {
    public:
        void SetKey(const unsigned char* key, int byte_length);
        void Encrypt(unsigned char* dst, const unsigned char* src, int byte_length) const;
        void Decrypt(unsigned char* dst, const unsigned char* src, int byte_length) const;

    private:
        void EncryptBlock(uint32_t* left, uint32_t* right) const;
        void DecryptBlock(uint32_t* left, uint32_t* right) const;
        uint32_t Feistel(uint32_t value) const;

    private:
        uint32_t pary_[18];
        uint32_t sbox_[4][256];
    };



class CBlowCbcCoder:
  public ICompressFilter,
  public ICryptoProperties,
  public ICompressSetCoderProperties,
  public CMyUnknownImp
{
 // unsigned _offset;
  unsigned _keySize;
  bool _keyIsSet;
  bool _encodeMode;
  //UInt32 _aes[AES_NUM_IVMRK_WORDS + 3];
  Byte _iv[AES_BLOCK_SIZE];

  Blowfish bl;


public:
  CBlowCbcCoder(bool encodeMode, unsigned keySize);
  
  MY_UNKNOWN_IMP3(ICompressFilter, ICryptoProperties, ICompressSetCoderProperties)
  
  INTERFACE_ICompressFilter(;)
  
  STDMETHOD(SetKey)(const Byte *data, UInt32 size);
  STDMETHOD(SetInitVector)(const Byte *data, UInt32 size);
  
  STDMETHOD(SetCoderProperties)(const PROPID *propIDs, const PROPVARIANT *props, UInt32 numProps);
};

struct CBlowCbcEncoder: public CBlowCbcCoder
{
  CBlowCbcEncoder(unsigned keySize = 0): CBlowCbcCoder(true, keySize) {}
};

struct CBlowCbcDecoder: public CBlowCbcCoder
{
  CBlowCbcDecoder(unsigned keySize = 0): CBlowCbcCoder(false, keySize) {}
};

}

#endif
