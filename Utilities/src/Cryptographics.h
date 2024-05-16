#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>

class MD5 {
public:
    std::string MD5CreateHash(std::string input);

private:
    uint32_t workingBits[16];

    uint32_t a0_;
    uint32_t b0_;
    uint32_t c0_;
    uint32_t d0_;

    const uint32_t k_array_[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    const uint32_t s_array_[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };

    void runMD5Algorithm();
    void addLengthBits(uint64_t originalLength);
    uint32_t charsToUint32_t(char input[4]);
    uint32_t leftRotate(uint32_t input, uint32_t rotateDistance);
    std::string convertOutputToHexString();
    void initializeWorkingBits(const std::string& input, uint64_t originalBitLength, size_t startIndex, size_t length);
};

std::string MD5::MD5CreateHash(std::string input) {
    a0_ = 0x67452301;
    b0_ = 0xefcdab89;
    c0_ = 0x98badcfe;
    d0_ = 0x10325476;

    uint64_t originalBitLength = input.size() * 8;

    size_t fullBlocks = input.size() / 64;
    size_t remainingBytes = input.size() % 64;

    for (size_t i = 0; i < fullBlocks; ++i) {
        initializeWorkingBits(input, originalBitLength, i * 64, 64);
        runMD5Algorithm();
    }

    // Process remaining bytes and padding
    initializeWorkingBits(input, originalBitLength, fullBlocks * 64, remainingBytes);
    runMD5Algorithm();

    // Output the hash
    return convertOutputToHexString();
}

void MD5::initializeWorkingBits(const std::string& input, uint64_t originalBitLength, size_t startIndex, size_t length) {
    std::memset(workingBits, 0, sizeof(workingBits));

    size_t i;
    for (i = 0; i < length; ++i) {
        workingBits[i / 4] |= (uint32_t)(unsigned char)input[startIndex + i] << ((i % 4) * 8);
    }

    if (length < 64) {
        if (length < 56) {
            workingBits[length / 4] |= 0x80 << ((length % 4) * 8);
        }
        else {
            workingBits[length / 4] |= 0x80 << ((length % 4) * 8);
            runMD5Algorithm();
            std::memset(workingBits, 0, sizeof(workingBits));
        }
    }

    if (length < 56) {
        workingBits[14] = originalBitLength & 0xFFFFFFFF;
        workingBits[15] = (originalBitLength >> 32) & 0xFFFFFFFF;
    }
    else {
        workingBits[14] = originalBitLength & 0xFFFFFFFF;
        workingBits[15] = (originalBitLength >> 32) & 0xFFFFFFFF;
    }
}

uint32_t MD5::charsToUint32_t(char input[4]) {
    return ((uint32_t)input[0] & 0xFF) |
        ((uint32_t)input[1] & 0xFF) << 8 |
        ((uint32_t)input[2] & 0xFF) << 16 |
        ((uint32_t)input[3] & 0xFF) << 24;
}

uint32_t MD5::leftRotate(uint32_t input, uint32_t rotateDistance) {
    return (input << rotateDistance) | (input >> (32 - rotateDistance));
}

void MD5::runMD5Algorithm() {
    uint32_t a = a0_;
    uint32_t b = b0_;
    uint32_t c = c0_;
    uint32_t d = d0_;

    for (int i = 0; i < 64; ++i) {
        uint32_t f, g;
        if (i < 16) {
            f = (b & c) | (~b & d);
            g = i;
        }
        else if (i < 32) {
            f = (d & b) | (~d & c);
            g = (5 * i + 1) % 16;
        }
        else if (i < 48) {
            f = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        }
        else {
            f = c ^ (b | ~d);
            g = (7 * i) % 16;
        }

        uint32_t temp = d;
        d = c;
        c = b;
        b = b + leftRotate(a + f + k_array_[i] + workingBits[g], s_array_[i]);
        a = temp;
    }

    a0_ += a;
    b0_ += b;
    c0_ += c;
    d0_ += d;
}

std::string MD5::convertOutputToHexString() {

    std::string result = "";
    static const char characters[] = "0123456789abcdef";

    uint8_t buffer[16] = {0, 0, 0, 0,0,0,0,0, 0, 0,0, 0, 0,0,0,0};

    buffer[0] |= a0_ & 0xFF; 
    buffer[1] |= (a0_ >> 8) & 0xFF;
    buffer[2] |= (a0_ >> 16) & 0xFF;
    buffer[3] = (a0_ >> 24) & 0xFF;
    buffer[7] = (b0_ >> 24) & 0xFF;
    buffer[6] |= (b0_ >> 16) & 0xFF;
    buffer[5] |= (b0_ >> 8) & 0xFF;
    buffer[4] |= b0_ & 0xFF;
    buffer[11] = (c0_ >> 24) & 0xFF;
    buffer[10] |= (c0_ >> 16) & 0xFF;
    buffer[9] |= (c0_ >> 8) & 0xFF;
    buffer[8] |= c0_ & 0xFF;
    buffer[15] = (d0_ >> 24) & 0xFF;
    buffer[14] |= (d0_ >> 16) & 0xFF;
    buffer[13] |= (d0_ >> 8) & 0xFF;
    buffer[12] |= d0_ & 0xFF;


    for (uint8_t element : buffer) {
        result += characters[(element >> 4) & 0x0F];
        result += characters[element & 0x0F];
    }

    
    return result;
}