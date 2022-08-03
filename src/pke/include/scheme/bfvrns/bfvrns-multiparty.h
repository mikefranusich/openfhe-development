//==================================================================================
// BSD 2-Clause License
//
// Copyright (c) 2014-2022, NJIT, Duality Technologies Inc. and other contributors
//
// All rights reserved.
//
// Author TPOC: contact@openfhe.org
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//==================================================================================

#ifndef LBCRYPTO_CRYPTO_BFVRNS_MULTIPARTY_H
#define LBCRYPTO_CRYPTO_BFVRNS_MULTIPARTY_H

#include "schemerns/rns-multiparty.h"

#include <string>
#include <vector>

/**
 * @namespace lbcrypto
 * The namespace of lbcrypto
 */
namespace lbcrypto {
class MultipartyBFVRNS : public MultipartyRNS {
    using ParmType = typename DCRTPoly::Params;
    using IntType  = typename DCRTPoly::Integer;
    using DugType  = typename DCRTPoly::DugType;
    using DggType  = typename DCRTPoly::DggType;
    using TugType  = typename DCRTPoly::TugType;

public:
    virtual ~MultipartyBFVRNS() {}

    KeyPair<DCRTPoly> MultipartyKeyGen(CryptoContext<DCRTPoly> cc,
                                       const std::vector<PrivateKey<DCRTPoly>>& privateKeyVec,
                                       bool makeSparse) override;

    KeyPair<DCRTPoly> MultipartyKeyGen(CryptoContext<DCRTPoly> cc, const PublicKey<DCRTPoly> publicKey, bool makeSparse,
                                       bool fresh) override;

    DecryptResult MultipartyDecryptFusion(const std::vector<Ciphertext<DCRTPoly>>& ciphertextVec,
                                          NativePoly* plaintext) const override;

    /////////////////////////////////////
    // SERIALIZATION
    /////////////////////////////////////

    template <class Archive>
    void save(Archive& ar, std::uint32_t const version) const {}

    template <class Archive>
    void load(Archive& ar, std::uint32_t const version) {}
};
}  // namespace lbcrypto

#endif
