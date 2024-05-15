#pragma once
#include <iostream>
#include <string>
#include <bitset>

class MD5 {
public:
	void MD5CreateHash(std::string input);

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

	//to be implemented after tests show I a getting proper outputs.
	//std::string convertOutputToHexString();

	uint32_t charsToUint32_t(char input[4]);
	uint32_t leftRotate(uint32_t input, uint32_t rotateDistance);
};



void MD5::MD5CreateHash(std::string input) {
	a0_ = 0x67452301;
	b0_ = 0xefcdab89;
	c0_ = 0x98badcfe;
	d0_ = 0x10325476;

	uint64_t originalBitLength = input.size() * 8;

	char charBlock[4];
	while (input != "") {
		if (input.size() > 64) {
			for (int i = 0; i < 64; i++) {
				charBlock[i % 4] = input[i];
				if (i % 4 == 3) {
					workingBits[i / 4] = charsToUint32_t(charBlock);
				}
			}
			input = input.substr(64);
		}
		else if (input.size() < 64 ) {
			//normal inputting of chars
			int iterator = 0;
			for (; iterator < input.size(); iterator++) {
				charBlock[iterator % 4] = input[iterator];
				if (iterator % 4 == 3) {
					workingBits[iterator / 4] = charsToUint32_t(charBlock);
				}
			}

			//pad the 1
			charBlock[iterator % 4] = 0x80;
			iterator++;
			if (iterator % 4 == 3) {
				workingBits[iterator / 4] = charsToUint32_t(charBlock);
			}

			if (input.size() >= 56) {
				//add the 0's
				while (iterator < 64) {
					charBlock[iterator % 4] = 0x00;
					if (iterator % 4 == 3) {
						workingBits[iterator / 4] = charsToUint32_t(charBlock);
					}
				}
				input = "";
				runMD5Algorithm();

				for (iterator = 0; iterator < 14; iterator++) {
					workingBits[iterator] = 0;
				}
			}
			else {
				while (iterator < 56) {
					charBlock[iterator % 4] = 0x00;
					if (iterator % 4 == 3) {
						workingBits[iterator / 4] = charsToUint32_t(charBlock);
					}
					iterator++;
				}
				input = "";
			}

			addLengthBits(originalBitLength);
			runMD5Algorithm();
		}
	}
}

uint32_t MD5::charsToUint32_t(char input[4])
{
	uint32_t returnVal = (uint32_t)input[0] & 0x000000ff;
	returnVal |= ((uint32_t)input[1] & 0x000000ff) << 8;
	returnVal |= ((uint32_t)input[2] & 0x000000ff) << 16;
	returnVal |= ((uint32_t)input[3] & 0x000000ff) << 24;

	return returnVal;
}

uint32_t MD5::leftRotate(uint32_t input, uint32_t rotateDistance) {
	return (input << rotateDistance) | (input >> (32 - rotateDistance));
}

void MD5::runMD5Algorithm() {
	//get initial values
	uint32_t a = a0_;
	uint32_t b = b0_;
	uint32_t c = c0_;
	uint32_t d = d0_;

	std::cout << "Initial Values: \n" << std::dec << a0_ << std::endl << b0_ << std::endl << c0_ << std::endl << d0_ << std::endl << std::endl;

	for (int i = 0; i < 64; i++) {
		//perform the algorithm
		uint32_t f, g;
		if (i >= 0 && i <= 15) {
			f = ((b & c) | ((~b) & d));
			g = i;
		}
		else if (i >= 16 && i <= 31) {
			f = ((d & b) | ((~d) & c));
			g = ((5 * i) + 1) % 16;
		}
		else if (i >= 32 && i <= 47) {
			f = (b ^ c ^ d);
			g = ((3 * i) + 5) % 16;
		}
		else if (i >= 48 && i <= 63) {
			f = (c ^ (b | (~d)));
			g = (7 * i) % 16;
		}

		//setup the next round
		uint32_t dTemp = d;
		d = c;
		c = b;
		b = b + leftRotate(a + f + k_array_[i] + workingBits[g], s_array_[i]);
		a = dTemp;

		std::cout << std::dec << "Step " << i << ":\n";
		std::cout << std::dec << a << std::endl << b << std::endl << c << std::endl << d << std::endl << std::endl;
	}

	//return result
	a0_ = a0_ + a;
	b0_ = b0_ + b;
	c0_ = c0_ + c;
	d0_ = d0_ + d;

	a0_ = ((a0_ & 0xFF000000) >> 24) | ((a0_ & 0x00FF0000) >> 8) | ((a0_ & 0x0000FF00) << 8) | ((a0_ & 0x000000FF) << 24);
	b0_ = ((b0_ & 0xFF000000) >> 24) | ((b0_ & 0x00FF0000) >> 8) | ((b0_ & 0x0000FF00) << 8) | ((b0_ & 0x000000FF) << 24);
	c0_ = ((c0_ & 0xFF000000) >> 24) | ((c0_ & 0x00FF0000) >> 8) | ((c0_ & 0x0000FF00) << 8) | ((c0_ & 0x000000FF) << 24);
	d0_ = ((d0_ & 0xFF000000) >> 24) | ((d0_ & 0x00FF0000) >> 8) | ((d0_ & 0x0000FF00) << 8) | ((d0_ & 0x000000FF) << 24);

	std::cout << std::hex << a0_ << std::endl << b0_ << std::endl << c0_ << std::endl << d0_ << std::endl << std::endl;
}

void MD5::addLengthBits(uint64_t originalLength) {
	uint32_t lowerHalf, upperHalf;
	lowerHalf = originalLength;
	upperHalf = originalLength >> 32;
	workingBits[14] = ((lowerHalf & 0xFF000000) >> 24) | ((lowerHalf & 0x00FF0000) >> 8)
		| ((lowerHalf & 0x0000FF00) << 8) |((lowerHalf & 0x000000FF) << 24);
	workingBits[15] = ((upperHalf & 0xFF000000) >> 24) | ((upperHalf & 0x00FF0000) >> 8)
		| ((upperHalf & 0x0000FF00) << 8) | ((upperHalf & 0x000000FF) << 24);
}