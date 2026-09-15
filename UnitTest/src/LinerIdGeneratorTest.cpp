#include <array>
#include <cstddef>
#include <cstdint>

#include <gtest/gtest.h>
#include <Impl/LinerIdGenerator.h>

class LinerIdGeneratorTest: public testing::Test
{
protected:
	LinerIdGeneratorTest()
	{
		// Fill the array
		for (std::size_t i = 0; i < 8; i++)
		{
			m_ids[i] = m_generator.GenerateId();
		}
	}

	// Hold generator and id array;
	LinerIdGenerator m_generator;
	std::array<std::uint64_t, 8> m_ids;
};


TEST_F(LinerIdGeneratorTest, CheckIds)
{
	// assert that the gap between any two numbers is only one
	ASSERT_EQ(m_ids[3] - m_ids[2], 1);
	ASSERT_EQ(m_ids[7] - m_ids[6], 1);
}


TEST_F(LinerIdGeneratorTest, CheckIdsAreLiner)
{
	std::uint64_t sum {};

	for (const auto& num: m_ids)
	{
		sum += num;
	};

	// assert that the sum of the id's are linear. 
	ASSERT_EQ(sum, 4 *(1 + 8));
}

