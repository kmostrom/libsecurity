
#include <gtest/gtest.h>
#include <security/HashCrc32.h>
#include <security/HashMd5.h>

#include <string>
#include <algorithm>

TEST(HashTest, Crc32Test)
{
	char a = '1';
	std::string checksum = HashCrc32::GetCrc32(&a, sizeof(a));
	ASSERT_EQ(std::string("83dcefb7"), checksum);
}

TEST(HashTest, Md5Test)
{
	unsigned char a = '1';
	MD5 checksum_md5 = MD5();
	checksum_md5.update(&a, sizeof(a));
	checksum_md5.finalize();
	std::string checksum = checksum_md5.hex_digest();
	ASSERT_EQ(std::string("c4ca4238a0b923820dcc509a6f75849b"), checksum);
}
