#include "ad7606.h"
#include "ai_device_adaptor.h"
uint8_t pingPongFlag = 0;

short test_ping_buffer1[ArrBufferLen];
short test_ping_buffer2[ArrBufferLen];
short test_ping_buffer3[ArrBufferLen];
short test_ping_buffer4[ArrBufferLen];
short test_ping_buffer5[ArrBufferLen];
short test_ping_buffer6[ArrBufferLen];
short test_ping_buffer7[ArrBufferLen];
short test_ping_buffer8[ArrBufferLen];

short test_pong_buffer1[ArrBufferLen];
short test_pong_buffer2[ArrBufferLen];
short test_pong_buffer3[ArrBufferLen];
short test_pong_buffer4[ArrBufferLen];
short test_pong_buffer5[ArrBufferLen];
short test_pong_buffer6[ArrBufferLen];
short test_pong_buffer7[ArrBufferLen];
short test_pong_buffer8[ArrBufferLen];

uint8_t ping_finish_flag = 0;
uint8_t pong_finish_flag = 0;

void adc7606_init()
{
    test_ping_buffer1[0] = 0xffff;
    test_ping_buffer1[1] = 0xfefe;
    test_ping_buffer1[BufferLen + 2] = 0xffff;
    test_ping_buffer1[BufferLen + 3] = 0xfafa;

    test_ping_buffer2[0] = 0xffff;
    test_ping_buffer2[1] = 0xfefe;
    test_ping_buffer2[BufferLen + 2] = 0xffff;
    test_ping_buffer2[BufferLen + 3] = 0xfafa;

    test_ping_buffer3[0] = 0xffff;
    test_ping_buffer3[1] = 0xfefe;
    test_ping_buffer3[BufferLen + 2] = 0xffff;
    test_ping_buffer3[BufferLen + 3] = 0xfafa;

    test_ping_buffer4[0] = 0xffff;
    test_ping_buffer4[1] = 0xfefe;
    test_ping_buffer4[BufferLen + 2] = 0xffff;
    test_ping_buffer4[BufferLen + 3] = 0xfafa;

    test_ping_buffer5[0] = 0xffff;
    test_ping_buffer5[1] = 0xfefe;
    test_ping_buffer5[BufferLen + 2] = 0xffff;
    test_ping_buffer5[BufferLen + 3] = 0xfafa;

    test_ping_buffer6[0] = 0xffff;
    test_ping_buffer6[1] = 0xfefe;
    test_ping_buffer6[BufferLen + 2] = 0xffff;
    test_ping_buffer6[BufferLen + 3] = 0xfafa;

    test_ping_buffer7[0] = 0xffff;
    test_ping_buffer7[1] = 0xfefe;
    test_ping_buffer7[BufferLen + 2] = 0xffff;
    test_ping_buffer7[BufferLen + 3] = 0xfafa;

    test_ping_buffer8[0] = 0xffff;
    test_ping_buffer8[1] = 0xfefe;
    test_ping_buffer8[BufferLen + 2] = 0xffff;
    test_ping_buffer8[BufferLen + 3] = 0xfafa;
    // pong
    test_pong_buffer1[0] = 0xffff;
    test_pong_buffer1[1] = 0xfefe;
    test_pong_buffer1[BufferLen + 2] = 0xffff;
    test_pong_buffer1[BufferLen + 3] = 0xfafa;

    test_pong_buffer2[0] = 0xffff;
    test_pong_buffer2[1] = 0xfefe;
    test_pong_buffer2[BufferLen + 2] = 0xffff;
    test_pong_buffer2[BufferLen + 3] = 0xfafa;

    test_pong_buffer3[0] = 0xffff;
    test_pong_buffer3[1] = 0xfefe;
    test_pong_buffer3[BufferLen + 2] = 0xffff;
    test_pong_buffer3[BufferLen + 3] = 0xfafa;

    test_pong_buffer4[0] = 0xffff;
    test_pong_buffer4[1] = 0xfefe;
    test_pong_buffer4[BufferLen + 2] = 0xffff;
    test_pong_buffer4[BufferLen + 3] = 0xfafa;

    test_pong_buffer5[0] = 0xffff;
    test_pong_buffer5[1] = 0xfefe;
    test_pong_buffer5[BufferLen + 2] = 0xffff;
    test_pong_buffer5[BufferLen + 3] = 0xfafa;

    test_pong_buffer6[0] = 0xffff;
    test_pong_buffer6[1] = 0xfefe;
    test_pong_buffer6[BufferLen + 2] = 0xffff;
    test_pong_buffer6[BufferLen + 3] = 0xfafa;

    test_pong_buffer7[0] = 0xffff;
    test_pong_buffer7[1] = 0xfefe;
    test_pong_buffer7[BufferLen + 2] = 0xffff;
    test_pong_buffer7[BufferLen + 3] = 0xfafa;

    test_pong_buffer8[0] = 0xffff;
    test_pong_buffer8[1] = 0xfefe;
    test_pong_buffer8[BufferLen + 2] = 0xffff;
    test_pong_buffer8[BufferLen + 3] = 0xfafa;

    HAL_GPIO_WritePin(ADC_RST_GPIO_Port, ADC_RST_Pin, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(ADC_RST_GPIO_Port, ADC_RST_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ADC_STBY_GPIO_Port, GPIO_PIN_3, GPIO_PIN_SET);
}

void get_ad7606()
{
    static int bufPtr = 2;

    if (pingPongFlag)
    {
        test_ping_buffer1[bufPtr] = AD7606Addr;
        test_ping_buffer2[bufPtr] = AD7606Addr;
        test_ping_buffer3[bufPtr] = AD7606Addr;
        test_ping_buffer4[bufPtr] = AD7606Addr;
        test_ping_buffer5[bufPtr] = AD7606Addr;
        test_ping_buffer6[bufPtr] = AD7606Addr;
        test_ping_buffer7[bufPtr] = AD7606Addr;
        test_ping_buffer8[bufPtr] = AD7606Addr;
        bufPtr++;

        if (bufPtr == BufferLen + 2)
        {
            bufPtr = 2;
            pingPongFlag = 1 - pingPongFlag;
            ping_finish_flag = 1;
        }
    }
    else
    {
        test_pong_buffer1[bufPtr] = AD7606Addr;
        test_pong_buffer2[bufPtr] = AD7606Addr;
        test_pong_buffer3[bufPtr] = AD7606Addr;
        test_pong_buffer4[bufPtr] = AD7606Addr;
        test_pong_buffer5[bufPtr] = AD7606Addr;
        test_pong_buffer6[bufPtr] = AD7606Addr;
        test_pong_buffer7[bufPtr] = AD7606Addr;
        test_pong_buffer8[bufPtr] = AD7606Addr;
        bufPtr++;

        if (bufPtr == BufferLen + 2)
        {
            bufPtr = 2;
            pingPongFlag = 1 - pingPongFlag;
            pong_finish_flag = 1;
        }
    }
}

void test_ad7606()
{
    if (pingPongFlag == 1 && pong_finish_flag)
    {
        LC_PRINT("1---------%f\r\n", test_pong_buffer1[0] / 32767.0f * ADRANG);
        LC_PRINT("2---------%f\r\n", test_pong_buffer2[0] / 32767.0f * ADRANG);
        LC_PRINT("3---------%f\r\n", test_pong_buffer3[0] / 32767.0f * ADRANG);
        LC_PRINT("4---------%f\r\n", test_pong_buffer4[0] / 32767.0f * ADRANG);
        LC_PRINT("5---------%f\r\n", test_pong_buffer5[0] / 32767.0f * ADRANG);
        LC_PRINT("6---------%f\r\n", test_pong_buffer6[0] / 32767.0f * ADRANG);
        LC_PRINT("7---------%f\r\n", test_pong_buffer7[0] / 32767.0f * ADRANG);
        LC_PRINT("8---------%f\r\n", test_pong_buffer8[0] / 32767.0f * ADRANG);
        pong_finish_flag = 0;
    }
    else if (pingPongFlag == 0 && ping_finish_flag)
    {
        LC_PRINT("1---------%f\r\n", test_ping_buffer1[0] / 32767.0f * ADRANG);
        LC_PRINT("2---------%f\r\n", test_ping_buffer2[0] / 32767.0f * ADRANG);
        LC_PRINT("3---------%f\r\n", test_ping_buffer3[0] / 32767.0f * ADRANG);
        LC_PRINT("4---------%f\r\n", test_ping_buffer4[0] / 32767.0f * ADRANG);
        LC_PRINT("5---------%f\r\n", test_ping_buffer5[0] / 32767.0f * ADRANG);
        LC_PRINT("6---------%f\r\n", test_ping_buffer6[0] / 32767.0f * ADRANG);
        LC_PRINT("7---------%f\r\n", test_ping_buffer7[0] / 32767.0f * ADRANG);
        LC_PRINT("8---------%f\r\n", test_ping_buffer8[0] / 32767.0f * ADRANG);
        ping_finish_flag = 0;
    }
}
