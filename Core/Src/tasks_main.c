#include "tasks.h"
#include "gui_guider.h"
#include "key.h"
#include "stdio.h"
#include "ai_device_adaptor.h"
#include "spi.h"

#ifdef TestModel

uint8_t test_flag = 0;
char wifi_info[10][33];

#endif // TestModel

short socket_establish_falg = 0;
uint8_t esp_spi_handshake = 0;
uint8_t esp_need_recv_flag = 0;

uint8_t esp32_data_frame_start[2] = {0xEB, 0x90};
uint8_t esp32_data_frame_end[2] = {0xED, 0xEA};
// uint8_t esp32_wifi_cmd_end[2] = {0xCC};

inline double calculateRMS(float buf[], int size)
{
    double sum_of_squares = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum_of_squares += buf[i] * buf[i];
    }
    double mean_of_squares = sum_of_squares / size;
    return sqrt(mean_of_squares);
}

void spi1_send_task(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size)
{
    HAL_GPIO_WritePin(WIFI_CS_GPIO_Port, WIFI_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(hspi, pData, Size, 10);
    HAL_GPIO_WritePin(WIFI_CS_GPIO_Port, WIFI_CS_Pin, GPIO_PIN_SET);
}

// wifi扫描命令
void request_wifi_scan_task(SPI_HandleTypeDef *hspi)
{
    esp_need_recv_flag = 1;
    uint8_t esp32_wifi_scan_cmd[1] = {0x01};
    uint8_t esp32_wifi_scan_frame[5];

    memcpy(esp32_wifi_scan_frame, esp32_data_frame_start, 2);
    memcpy(esp32_wifi_scan_frame + 2, esp32_wifi_scan_cmd, 1);
    memcpy(esp32_wifi_scan_frame + 3, esp32_data_frame_end, 2);

    spi1_send_task(hspi, esp32_wifi_scan_frame, 5);
}

// wifi连接命令
void connect_wifi_task(SPI_HandleTypeDef *hspi, WifiNode WifiInfo)
{
    uint8_t esp32_wifi_connect_frame[70];
    uint8_t esp32_wifi_connect_cmd[1] = {0x02};
    memcpy(esp32_wifi_connect_frame, esp32_data_frame_start, 2);
    memcpy(esp32_wifi_connect_frame + 2, esp32_wifi_connect_cmd, 1);

    memcpy(esp32_wifi_connect_frame + 3, &WifiInfo.SSIDLen, 1);
    memcpy(esp32_wifi_connect_frame + 4, WifiInfo.SSID, WifiInfo.SSIDLen);
    memcpy(esp32_wifi_connect_frame + 4 + WifiInfo.SSIDLen, &WifiInfo.PWDLen, 1);
    memcpy(esp32_wifi_connect_frame + 4 + WifiInfo.SSIDLen + 1, WifiInfo.PWD, WifiInfo.PWDLen);
    memcpy(esp32_wifi_connect_frame + 4 + WifiInfo.SSIDLen + 1 + WifiInfo.PWDLen, esp32_data_frame_end, 2);

    spi1_send_task(hspi, esp32_wifi_connect_frame, 70);
    esp_need_recv_flag = 1;
}

// 开启/关闭 实时数据传输
void control_real_data_status_task(SPI_HandleTypeDef *hspi, uint8_t Status)
{
    uint8_t esp32_real_data_status_frame[6];
    uint8_t esp32_real_data_status_cmd = 0x03;

    uint8_t esp32_real_data_status = 0x00;
    if (Status)
    {
        esp32_real_data_status = 0x01;
    }
    memcpy(esp32_real_data_status_frame, esp32_data_frame_start, 2);
    memcpy(esp32_real_data_status_frame + 2, &esp32_real_data_status_cmd, 1);
    memcpy(esp32_real_data_status_frame + 2 + 1, &esp32_real_data_status, 1);
    memcpy(esp32_real_data_status_frame + 2 + 1 + 1, esp32_data_frame_end, 2);

    spi1_send_task(hspi, esp32_real_data_status_frame, 6);
}

void send_ad7606_data_task()
{
    if (socket_establish_falg == 1)
    {
        if (ping_finish_flag == 1 && pingPongFlag == 0)
        {
            // spi send_ping_data
            // control_real_data_status_task(&hspi1, 1);
            spi1_send_task(&hspi1, (uint8_t *)test_ping_buffer1, ArrBufferLen * 2);

            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer1, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer2, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer3, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer4, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer5, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer6, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer7, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_ping_buffer8, BufferLen, 20);

            ping_finish_flag = 0;
        }
        else if (pong_finish_flag == 1 && pingPongFlag == 1)
        {
            // spi send_pong_data
            // control_real_data_status_task(&hspi1, 0);
            spi1_send_task(&hspi1, (uint8_t *)test_pong_buffer1, ArrBufferLen * 2);

            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer1, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer2, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer3, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer4, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer5, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer6, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer7, BufferLen, 20);
            // HAL_SPI_Transmit(&hspi1, (uint8_t *)test_pong_buffer8, BufferLen, 20);

            pong_finish_flag = 0;
        }
    }
}

// 解析数据帧
void analyse_frame(uint8_t *frame, uint32_t len)
{
    printf("%ld\n", len);
    if (frame[0] != 0xEB || frame[1] != 0x90)
    {
        return;
    }

    uint8_t cmd = frame[2];
    uint8_t content_index = 3;

    switch (cmd)
    {
    case 0x01:
    {

        /* Wifi扫描命令 返回值 */
        int ap_num = frame[3];
        scan_wifi_node scan_wifi_list[ap_num];
        uint16_t NodeSize = sizeof(scan_wifi_node);
        uint16_t arraySize = NodeSize * ap_num;

        memcpy(scan_wifi_list, &frame[4], arraySize);
        for (uint8_t i = 0; i < ap_num; i++)
        {
            memcpy(wifi_info[i], &scan_wifi_list[i].SSID, sizeof(scan_wifi_list[i].SSID));
        }
        reload_wifi_page();
        reload_wifi_page();
        break;
    }

    case 0x02:
    {
        ip_info_node ip_info;
        /* Wifi连接命令 返回值 */
        volatile uint8_t res = frame[3];
        // printf("%d\n");
        uint16_t NodeSize = sizeof(ip_info_node);
        memcpy(&ip_info, &frame[4], NodeSize);

        // memcpy(&guider_ui.ip_buf, &ip_info.ip, sizeof(ip_info.ip));
        sprintf(&guider_ui.ip_buf, "%d.%d.%d.%d", ip_info.ip.add1, ip_info.ip.add2, ip_info.ip.add3, ip_info.ip.add4);
        if (res == 1)
        {
            password_right();
            socket_establish_falg = 1;
        }
        if (res == 0)
        {
            password_wrong();
        }

        // printf("%d\n");
        break;
    }

    default:

        break;
    }

    return;
}
