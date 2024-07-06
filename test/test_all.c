#include <md.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_hex(uint8_t *data, uint8_t data_len)
{
	for (uint8_t i = 0; i < data_len; i++)
	{
		printf("%02x", data[i]);
	}
}

int main()
{
	uint8_t *messages[] = {
		(uint8_t *)"a",
		(uint8_t *)"abc",
		(uint8_t *)"md hash",
		(uint8_t *)"abc123def456ghi?",
		(uint8_t *)"loooooooooooooong string!"};

	uint8_t md2_expecteds[][16] = {
		{0x32, 0xec, 0x01, 0xec, 0x4a, 0x6d, 0xac, 0x72, 0xc0, 0xab, 0x96, 0xfb, 0x34, 0xc0, 0xb5, 0xd1},
		{0xda, 0x85, 0x3b, 0x0d, 0x3f, 0x88, 0xd9, 0x9b, 0x30, 0x28, 0x3a, 0x69, 0xe6, 0xde, 0xd6, 0xbb},
		{0x28, 0x15, 0xdb, 0x15, 0x7d, 0x25, 0x3f, 0x55, 0x2b, 0xe5, 0xd1, 0x70, 0xe5, 0x44, 0x40, 0x1d},
		{0x67, 0x8f, 0x6c, 0xbe, 0x76, 0x00, 0x15, 0x8d, 0x84, 0xed, 0xdf, 0x76, 0x67, 0xdb, 0x93, 0xe4},
		{0xc1, 0x1d, 0x50, 0x40, 0x6a, 0x96, 0xa5, 0x03, 0x41, 0x43, 0x66, 0xbc, 0xaa, 0x12, 0xde, 0xf4}};

	uint8_t md4_expecteds[][16] = {
		{0xbd, 0xe5, 0x2c, 0xb3, 0x1d, 0xe3, 0x3e, 0x46, 0x24, 0x5e, 0x05, 0xfb, 0xdb, 0xd6, 0xfb, 0x24},
		{0xa4, 0x48, 0x01, 0x7a, 0xaf, 0x21, 0xd8, 0x52, 0x5f, 0xc1, 0x0a, 0xe8, 0x7a, 0xa6, 0x72, 0x9d},
		{0x26, 0xd4, 0x94, 0x46, 0x65, 0xfd, 0x6b, 0x0a, 0xd0, 0x24, 0xd7, 0x7c, 0x73, 0x5e, 0xd6, 0x82},
		{0x5e, 0x4c, 0x4d, 0x1b, 0xe9, 0xb0, 0xfe, 0x14, 0x2b, 0xb6, 0x78, 0x27, 0xc2, 0x19, 0xa7, 0x95},
		{0xcd, 0x4c, 0xd8, 0x8a, 0xac, 0x34, 0xf8, 0x26, 0xab, 0x00, 0x5d, 0x00, 0xf8, 0x14, 0x1e, 0xc1}};

	uint8_t md5_expecteds[][16] = {
		{0x0c, 0xc1, 0x75, 0xb9, 0xc0, 0xf1, 0xb6, 0xa8, 0x31, 0xc3, 0x99, 0xe2, 0x69, 0x77, 0x26, 0x61},
		{0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0, 0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72},
		{0xd0, 0xcf, 0x3d, 0x6c, 0xee, 0xc4, 0xad, 0xfc, 0x5e, 0x57, 0xf9, 0xb4, 0x88, 0x88, 0x35, 0xd0},
		{0x8c, 0x4d, 0x8f, 0x13, 0x5c, 0xba, 0xbe, 0x82, 0x8c, 0x2e, 0x14, 0x0c, 0x32, 0x8b, 0xe3, 0xd0},
		{0xa9, 0x82, 0xc1, 0x34, 0x93, 0xc5, 0x39, 0x96, 0x0f, 0x6f, 0xf3, 0xb9, 0x66, 0x21, 0xfd, 0x64}};

	uint8_t md2_digest[MD2_DIGEST_LENGTH];
	uint8_t md4_digest[MD4_DIGEST_LENGTH];
	uint8_t md5_digest[MD5_DIGEST_LENGTH];

	printf("\n##### MD2 #####\n");
	for (uint8_t i = 0; i < 5; i++)
	{
		printf("\n");
		printf("message : %s\n", messages[i]);
		printf("expected: ");
		print_hex(md2_expecteds[i], 16);
		printf("\n");
		MD2(messages[i], strlen((char *)messages[i]), md2_digest);
		printf("output  : ");
		print_hex(md2_digest, 16);
		printf("\n");
		printf("matches?: %s\n", memcmp(md2_digest, md2_expecteds[i], 16) ? "false" : "true");
	}
	printf("\n===============\n");

	printf("\n##### MD4 #####\n");
	for (uint8_t i = 0; i < 5; i++)
	{
		printf("\n");
		printf("message : %s\n", messages[i]);
		printf("expected: ");
		print_hex(md4_expecteds[i], 16);
		printf("\n");
		MD4(messages[i], strlen((char *)messages[i]), md4_digest);
		printf("output  : ");
		print_hex(md4_digest, 16);
		printf("\n");
		printf("matches?: %s\n", memcmp(md4_digest, md4_expecteds[i], 16) ? "false" : "true");
	}
	printf("\n===============\n");

	printf("\n##### MD5 #####\n");
	for (uint8_t i = 0; i < 5; i++)
	{
		printf("\n");
		printf("message : %s\n", messages[i]);
		printf("expected: ");
		print_hex(md5_expecteds[i], 16);
		printf("\n");
		MD5(messages[i], strlen((char *)messages[i]), md5_digest);
		printf("output  : ");
		print_hex(md5_digest, 16);
		printf("\n");
		printf("matches?: %s\n", memcmp(md5_digest, md5_expecteds[i], 16) ? "false" : "true");
	}
	printf("\n===============\n");

	return 0;
}