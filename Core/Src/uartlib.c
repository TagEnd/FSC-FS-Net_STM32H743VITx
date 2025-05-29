#include "uartlib.h"
#include "string.h"

void (*handle_start_rx_byte_it_func)(DRIVE_UART_TYPEDEF *device, unsigned char *rx_buf);
/// @brief 接受一bit的数据
/// @param helper
void uart_rx_byte_callback(UART_HandleType *helper)
{
    helper->rx_delay_cnt = UART_HEANDLE_DELAY_MS;
    helper->rx_buf[helper->rx_len++] = helper->rx_tmp;
    helper->rx_len %= helper->rx_maxlen;
    handle_start_rx_byte_it_func(helper->handle, &(helper->rx_tmp));
}

// 处理数据
void uart_process_rx_data(UART_HandleType *helper)
{
    if (helper->rx_ok)
    {
        helper->rx_ok = 0;
        helper->handle_dataprocess(helper->rx_buf, helper->rx_len);
        helper->rx_len = 0;
    }
}
/// @brief 标志处理任务
/// @param helper
void uart_process_flags(UART_HandleType *helper)
{
    if (helper->rx_delay_cnt > 1)
    {
        helper->rx_delay_cnt--;
    }
    if (helper->rx_delay_cnt == 1)
    {
        helper->rx_ok = 1;
        helper->rx_delay_cnt = 0;
    }
}
// 发送数据处理函数
void uart_process_data_send(UART_HandleType *helper)
{
    static unsigned short cnt = 0;
    if (helper->tx_start)
    {
        helper->handle_send_byte(helper->handle, helper->tx_buf[cnt]);
        cnt++;
        if (cnt == helper->tx_len)
        {
            cnt = 0;
            helper->tx_start = 0;
        }
    }
}
/**
 * @brief 发送长数据
 * @describe 
 * @author SmallWhitePassingBy
 * @param helper 串口帮助对象
 * @param buf 数据buf
 * @param len 待发送的数据长度
 * @return UART_STATUS_FLAGS
*/
UART_STATUS_FLAGS uart_push_buffer(UART_HandleType *helper, unsigned char *buf, unsigned short len)
{
    if (helper->tx_start == 1)
    {
        return UART_TX_HAS_DATA_UNSEND;
    }
    if (len > helper->tx_maxlen)
    {
        return UART_TX_BUF_TOO_LONG;
    }

    memcpy(helper->tx_buf, buf, len);
    helper->tx_len = len;
    helper->tx_start = 1;
    return UART_TX_OK;
}
// 1ms 定时任务处理串口的数据
void uart_helper_run(UART_HandleType *helper)
{
    uart_process_rx_data(helper);
    uart_process_flags(helper);
    uart_process_data_send(helper);
}
/**
 * @brief 初始化一个串口助手
 * @describe
 * @author SmallWhitePassingBy
 * @param device 串口设备，hal库则为UART_HandleTypeDef
 * @param rx_buf 接受缓存区
 * @param rx_maxlen 接受缓存区大小
 * @param tx_buf 发送缓存区
 * @param tx_maxlen 发送缓存区大小
 * @param handle_dataprocess 用户数据接受完成一帧的回调函数
 * @param handle_send_byte 发一个字节的函数接口
 * @param handle_start_rx_byte_it 开启接受一个byte数据的中断
 * @return
 */
void uart_helper_init(
    DRIVE_UART_TYPEDEF *device,
    UART_HandleType *helper,
    unsigned char *rx_buf,
    unsigned short rx_maxlen,
    unsigned char *tx_buf,
    unsigned short tx_maxlen,
    void (*handle_dataprocess)(unsigned char *rx_buf, unsigned short rx_len),
    void (*handle_send_byte)(DRIVE_UART_TYPEDEF *device, unsigned char tx_buf),
    void (*handle_start_rx_byte_it)(DRIVE_UART_TYPEDEF *device, unsigned char *rx_buf))
{
    helper->handle = device;
    helper->rx_buf = rx_buf;
    helper->rx_len = 0;
    helper->rx_maxlen = rx_maxlen;
    helper->tx_buf = tx_buf;
    helper->tx_maxlen = tx_maxlen;
    helper->handle_dataprocess = handle_dataprocess;
    handle_start_rx_byte_it_func = handle_start_rx_byte_it;
    helper->handle_send_byte = handle_send_byte;
    handle_start_rx_byte_it_func(helper->handle, &(helper->rx_tmp));
}

