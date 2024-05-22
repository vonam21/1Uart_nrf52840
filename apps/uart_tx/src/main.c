#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <stdio.h>
#define MY_STACK_SIZE 500
#define MY_PRIORITY 5
#define LED1_NODE DT_NODELABEL(led_1)
#define LED2_NODE DT_NODELABEL(led_2)
const char *message = "this is";
#define UART_DEVICE_NODE DT_ALIAS(uart_tutorial)
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
K_THREAD_STACK_DEFINE(led1_thread_stack_area, MY_STACK_SIZE);
struct k_thread led1_thread_data;
k_tid_t led1_threadid;
K_THREAD_STACK_DEFINE(led2_thread_stack_area, MY_STACK_SIZE);
struct k_thread led2_thread_data;
k_tid_t led2_threadid;

int count=0,countmain =0;
struct k_mutex car;
struct k_sem button_pressed_sem;

void led1_control_thread(void *, void *, void *) {
    LOG_INF("lan dau vao thread_led1");
    while (1) {
        // k_mutex_lock(&car, K_FOREVER);
        LOG_INF("truoc lock thread_led_1 count = %d",count);
        k_mutex_lock(&car, K_FOREVER);
        LOG_INF("trong locklan 1 thread_led1");
        // for(int i=0;i<10;i++){
        //     gpio_pin_toggle_dt(&led1);
        //     k_msleep(300);
        // }
        //k_mutex_lock(&car,K_FOREVER);
        k_msleep(3000);
        LOG_INF("sau locklan2 thread_led_1 count = %d",count);
        //k_mutex_unlock(&car);
        //LOG_INF("sau unlock thread_led_1 count = %d",count);
        //k_sem_take(&button_pressed_sem, K_FOREVER);
    }
}

// void led2_control_thread(void *, void *, void *) {
//     LOG_INF("lan dau vao thread_led2");
//     while (1) {
//         LOG_INF("truoc delay500 thread_led_2 count = %d",count);
//         k_msleep(1000);
//         LOG_INF("sau delay500 thread_led_2 count = %d",count);
//     }
// }

int main(void)
{
    LOG_INF("vao ham main dau tien");
    k_mutex_init(&car);
    k_sem_init(&button_pressed_sem, 0, 5);
    led1_threadid = k_thread_create(&led1_thread_data, led1_thread_stack_area,
        K_THREAD_STACK_SIZEOF(led1_thread_stack_area),
        led1_control_thread,
        NULL, NULL, NULL,
        6, 0, K_NO_WAIT);
    LOG_INF("sau khai bao");
    // led2_threadid = k_thread_create(&led2_thread_data, led2_thread_stack_area,
    //     K_THREAD_STACK_SIZEOF(led2_thread_stack_area),
    //     led2_control_thread,
    //     NULL, NULL, NULL,
    //     4, 0, K_NO_WAIT);
    
    int ret;

    if (!gpio_is_ready_dt(&led1)) {
            return 0;
    }

    ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
            return 0;
    }
    if (!gpio_is_ready_dt(&led2)) {
            return 0;
    }

    ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
            return 0;
    }
    LOG_ERR("sau config");
   
    while (1) {
        LOG_INF("truoc lock main count = %d",count);
        k_mutex_lock(&car, K_FOREVER);
        k_mutex_lock(&car, K_FOREVER);
        LOG_INF("trong lock main");
        for(int i=0;i<8;i++){
            gpio_pin_toggle_dt(&led2);
            k_msleep(1000);
        }
        LOG_INF("sau lock main count = %d",count);
        k_mutex_unlock(&car);
        LOG_INF("sau unlock main count = %d",count);

        // LOG_INF("dang o truoc ksemtake ham main countmain = %d",countmain);
        // //k_sem_give(&button_pressed_sem);
        // k_msleep(1);
        // LOG_INF("dang o sau ksemtake ham main countmain = %d", countmain);
        // for (int i = 0; i < strlen(message) + 1; i++) {
        //     uart_poll_out(uart_dev, *(message + i));

        // }
        // LOG_INF("dang o sau ksemtake ham main");
        // gpio_pin_toggle_dt(&led2);
        k_msleep(2000);

    }
    return 0;
}