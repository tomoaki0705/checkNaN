#include <iostream>
#include <gtest/gtest.h>
#include <arm_neon.h>

TEST(testNaN, NEON) {
    unsigned int inputZero[] = {0, 0, 0xffffffff, 0xffffffff};
    unsigned int inputNaN[] = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
    unsigned int resultSIMD[4];
    float32x4_t a = vld1q_f32((float*)inputZero);
    float32x4_t b = vld1q_f32((float*)inputNaN);
    vst1q_f32((float*)resultSIMD, vaddq_f32(a, b));
    for(int i = 0;i < 4;i++)
    {
        EXPECT_FALSE(resultSIMD[i] == (inputZero[i] + ((float*)inputNaN)[i]));
        std::cout << std::hex << "0x" << resultSIMD[i] << std::endl;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
