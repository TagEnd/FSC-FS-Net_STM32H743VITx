#ifndef __TASKS_H__
#define __TASKS_H__

#include "ad7606.h"
#include "spi.h"
#include "main.h"
#include "stdint.h"

// extern uint8_t ping_finish_flag;
// extern uint8_t pong_finish_flag;

#define TestModel 1

typedef struct
{
    uint8_t SSID[33];
    uint8_t SSIDLen;

    uint8_t PWD[30];
    uint8_t PWDLen;
} WifiNode;

typedef struct
{
    uint8_t SSID[33];
    int8_t RSSI;
    uint8_t BSSID[6];

} scan_wifi_node;

typedef struct
{
    uint8_t add1;
    uint8_t add2;
    uint8_t add3;
    uint8_t add4;
} addr4;

typedef struct
{
    addr4 ip;
    addr4 netmask;
    addr4 gw;
} ip_info_node;

#ifdef TestModel

extern uint8_t test_flag;

#endif // TestModel

extern short socket_establish_falg;
extern uint8_t esp_spi_handshake;
extern uint8_t esp_need_recv_flag;
extern WifiNode wifinode;

void spi1_send_task(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size);

void request_wifi_scan_task(SPI_HandleTypeDef *hspi);

void connect_wifi_task(SPI_HandleTypeDef *hspi, WifiNode WifiInfo);

void control_real_data_status_task(SPI_HandleTypeDef *hspi, uint8_t Status);

void send_ad7606_data_task();

void analyse_frame(uint8_t *frame, uint32_t len);

#endif
