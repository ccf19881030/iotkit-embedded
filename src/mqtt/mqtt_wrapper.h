#include "infra_types.h"
#include "infra_defs.h"

int HAL_GetPartnerID(char *pid_str);
int HAL_GetModuleID(char *mid_str);
int HAL_SetProductKey(char *product_key);
int HAL_SetDeviceName(char *device_name);
int HAL_SetProductSecret(char *product_secret);
int HAL_SetDeviceSecret(char *device_secret);

int HAL_GetProductKey(char product_key[IOTX_PRODUCT_KEY_LEN]);
int HAL_GetDeviceName(char device_name[IOTX_DEVICE_NAME_LEN]);
int HAL_GetDeviceSecret(char device_secret[IOTX_DEVICE_SECRET_LEN]);

void *HAL_Malloc(uint32_t size);
void HAL_Free(void *ptr);
void HAL_Printf(const char *fmt, ...);
int HAL_Snprintf(char *str, const int len, const char *fmt, ...);
uint64_t HAL_UptimeMs(void);
void HAL_Srandom(uint32_t seed);
void *HAL_MutexCreate(void);
void HAL_MutexDestroy(void *mutex);
void HAL_MutexLock(void *mutex);
void HAL_MutexUnlock(void *mutex);
void HAL_SleepMs(uint32_t ms);
uint32_t HAL_Random(uint32_t region);
int HAL_GetFirmwareVersion(char *version);

//mqtt protocol wrapper
void *wrapper_mqtt_init(iotx_mqtt_param_t *mqtt_params);
int wrapper_mqtt_connect(void *client);
int wrapper_mqtt_yield(void *client, int timeout_ms);
int wrapper_mqtt_check_state(void *client);
int wrapper_mqtt_subscribe(void *client,
                           const char *topicFilter,
                           iotx_mqtt_qos_t qos,
                           iotx_mqtt_event_handle_func_fpt topic_handle_func,
                           void *pcontext);
int wrapper_mqtt_subscribe_sync(void *client,
                                const char *topic_filter,
                                iotx_mqtt_qos_t qos,
                                iotx_mqtt_event_handle_func_fpt topic_handle_func,
                                void *pcontext,
                                int timeout_ms);
int wrapper_mqtt_unsubscribe(void *client, const char *topicFilter);
int wrapper_mqtt_publish(void *client, const char *topicName, iotx_mqtt_topic_info_pt topic_msg);
int wrapper_mqtt_release(void **pclient);