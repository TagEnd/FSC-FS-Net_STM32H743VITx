#ifndef _UARTLIB_H
#define _UARTLIB_H

// 断帧延时判断数，5MS
#define UART_HEANDLE_DELAY_MS 5

#ifndef DRIVE_UART_TYPEDEF
#define DRIVE_UART_TYPEDEF void
#endif

#define UART_VOID_FUNC ((void *)0)
typedef enum
{
    // 串口数据还未方式完成就添加数据到发送缓存区
    UART_TX_HAS_DATA_UNSEND = 0,
    // 添加数据到发送缓存区成功
    UART_TX_OK,
    // 待发送的数据太大了，超出发送缓存区的大小
    UART_TX_BUF_TOO_LONG,
    // 未知状态
    UART_UNKWON
} UART_STATUS_FLAGS;
typedef struct _UART_HANDER_
{
    // 数据接受的长度
    unsigned short rx_len;
    // 接受数据缓存区大小
    unsigned short rx_maxlen;
    // 接受数据缓存区
    unsigned char *rx_buf;
    // 数据方式发送的长度
    unsigned short tx_len;
    // 发送数据缓存区大小
    unsigned short tx_maxlen;
    // 发送数据缓存区
    unsigned char *tx_buf;
    // 接受单byte区
    unsigned char rx_tmp;
    // 接受完成的标志位
    unsigned char rx_ok;
    // 发送开始的标志位
    unsigned char tx_start;
    // 用户使用的接受数据的回调函数
    void (*handle_dataprocess)(unsigned char *rx_buf, unsigned short rx_len);
    // 用户使用的发送byte的函数接口
    void (*handle_send_byte)(DRIVE_UART_TYPEDEF *device, unsigned char tx_buf);
    // 断帧计数变量
    unsigned char rx_delay_cnt;
    // 硬件驱动
    DRIVE_UART_TYPEDEF *handle;
} UART_HandleType;

void uart_helper_run(UART_HandleType *helper);
void uart_rx_byte_callback(UART_HandleType *helper);
void uart_helper_init(
    DRIVE_UART_TYPEDEF *device,
    UART_HandleType *helper,
    unsigned char *rx_buf,
    unsigned short rx_maxlen,
    unsigned char *tx_buf,
    unsigned short tx_maxlen,
    void (*handle_dataprocess)(unsigned char *rx_buf, unsigned short rx_len),
    void (*handle_send_byte)(DRIVE_UART_TYPEDEF *device, unsigned char tx_buf),
    void (*handle_start_rx_byte_it)(DRIVE_UART_TYPEDEF *device, unsigned char *rx_buf));
UART_STATUS_FLAGS uart_push_buffer(UART_HandleType *helper, unsigned char *buf, unsigned short len);

// template
/*
    1.重定义DRIVE_UART_TYPEDEF
    #define DRIVE_UART_TYPEDEF UART_HandleTypeDef
    2.声明一个自定义的数据处理回调函数
    void process_uart_data(uint8_t *buf,uint16_t len)
    {
        // 处理你的数据
    }
    3.自定义一个开启接受一个byte串口数据的中断和方式一个数据的接口
    void handle_start_rx_byte_it(DRIVE_UART_TYPEDEF* device,uint8_t* byte)
    {
        HAL_UART_Receive_IT(device,byte,1);
    }
    void handle_send_byte(DRIVE_UART_TYPEDEF *device,uint8_t byte)
    {
        HAL_UART_Transmit(device,&byte,1,0xff);
    }
    4.定义一个帮助对象
    UART_HandleType helper = {0};
    uint8_t rx_buf[1024];
    uint8_t tx_buf[1024];
    5.初始化帮助对象
    uart_helper_init(&huart1,&helper,rx_buf,1024,tx_buf,1024,process_uart_data,handle_send_byte,handle_start_rx_byte_it);
    6.定时1ms处理帮助对象的任务
    uart_helper_run(&helper);
    7.在硬件接受回调函数执行以下函数：
    uart_rx_byte_callback(&helper);

    发送“大”数据
    uart_push_buffer(&helper, "test buffer!!\r\n",15);
*/

#endif /*_UARTLIB_H*/