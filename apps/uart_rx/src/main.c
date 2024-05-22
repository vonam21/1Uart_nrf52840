#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(application, LOG_LEVEL_DBG);
#include <zephyr/drivers/uart.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <stdio.h>
#include <stdlib.h>
/* change this to any other UART peripheral if desired */
#define LED1_NODE DT_NODELABEL(led_1)
// #define UART_DEVICE_NODE DT_NODELABEL(uart_tutorial)
#define BUFFER_SIZE 9
// Use alias if you want your code to be portable between boards
#define UART_DEVICE_NODE DT_ALIAS(uart_tutorial)
/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
uint8_t buffer[BUFFER_SIZE] = {0x00};
uint8_t buffer_count = 0;
int number =0,time =0;
uint8_t temp[BUFFER_SIZE] = {0x00};

static void uart_isr_cb(const struct device *dev, void *user_data)
{
    int num_bytes_read = 0;
    while (uart_irq_update(dev) &&
            uart_irq_rx_ready(dev)) {

        int available_space = BUFFER_SIZE - buffer_count;
        uint8_t *current_buffer_pointer = buffer + buffer_count;
        num_bytes_read = uart_fifo_read(dev, current_buffer_pointer, available_space);
        if (num_bytes_read <= 0) {
            continue;
        }
        LOG_INF("data received %d %x", num_bytes_read, *current_buffer_pointer);

        for (int i = 0; i < num_bytes_read; i++)
        {
            if (*(current_buffer_pointer + i) == '\0') {
                number = atoi(temp);
                LOG_WRN("number1: %s", temp);
                memset(temp, 0x00, BUFFER_SIZE);
                buffer_count = 0;
                time = 1000/(2*number);
                return;
            } else {
                *(temp + buffer_count + i) = *(current_buffer_pointer + i); //?????
            }
        }

        buffer_count += num_bytes_read;
        if (buffer_count == BUFFER_SIZE) {
            number = atoi(buffer);
            buffer_count = 0;
            LOG_ERR("abc: %s", buffer);
            memset(temp, 0x00, BUFFER_SIZE);
            time = 1000/(2*number);
        }
    }
}
int main(void)
{
    if (!device_is_ready(uart_dev)) {
        return -ENODEV;
    }
    int ret;

    if (!gpio_is_ready_dt(&led1)) {
            return -1;
    }

    ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
            return -1;
    }
    // Disable both RX and TX of the UART
    uart_irq_rx_disable(uart_dev);
    uart_irq_tx_disable(uart_dev);
    // Set the ISR callback for each character
    uart_irq_callback_set(uart_dev, uart_isr_cb);

    // Enable the RX of the UART dev
    uart_irq_rx_enable(uart_dev);

    int z = 0;
    while (1) {
        LOG_INF(" nam ");
        //t1= k_uptime_get();
        z = number << 1;
        while (z != 0)
        {
            gpio_pin_toggle_dt(&led1);
            k_msleep(time);
            z--;

            if (z == 0) {
                number = 0;
            }
        }
        k_msleep(1000);
    }
    return 0;
}


