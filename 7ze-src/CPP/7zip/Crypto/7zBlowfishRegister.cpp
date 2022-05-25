// 7zBlowfishRegister.cpp

#include "StdAfx.h"

#include "../Common/RegisterCodec.h"

#include "7zBlowFish.h"

namespace NCrypto {
namespace N7zBl {

REGISTER_FILTER_E(7zBl,
    CDecoder(),
    CEncoder(),
    0x6F10751, "7zBlowfish")

}}
