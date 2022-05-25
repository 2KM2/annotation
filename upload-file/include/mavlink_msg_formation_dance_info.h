#pragma once
// MESSAGE FORMATION_DANCE_INFO PACKING

#define MAVLINK_MSG_ID_FORMATION_DANCE_INFO 175

#pragma pack(1)
typedef struct __mavlink_formation_dance_info_t {
 uint16_t serial_num; /*< The serilal number of Aircraft. E.g: 13.*/
 uint32_t dance_id; /*< The formation dance number. E.g: 36.*/
 float position[3]; /*< Distance between the start points of x, y, z. E.g: 10, 20, 30.*/
 uint8_t rgbw[4]; /*< Light RGBW. E.g: 255 255 255 255.*/
 uint8_t light_ctr; /*< Light control. E.g: 1.*/
 uint8_t mode_ctr; /*< Mode control about arm or disarm etc.. E.g: 1.*/
 uint8_t reserve0; /*< Reservr0. E.g: 0.*/
 uint8_t reserve1; /*< Reservr1. E.g: 0.*/
} mavlink_formation_dance_info_t;
#pragma pack()

#define MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN 26
#define MAVLINK_MSG_ID_FORMATION_DANCE_INFO_MIN_LEN 26
#define MAVLINK_MSG_ID_175_LEN 26
#define MAVLINK_MSG_ID_175_MIN_LEN 26

#define MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC 54
#define MAVLINK_MSG_ID_175_CRC 54

#define MAVLINK_MSG_FORMATION_DANCE_INFO_FIELD_POSITION_LEN 3
#define MAVLINK_MSG_FORMATION_DANCE_INFO_FIELD_RGBW_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_DANCE_INFO { \
    175, \
    "FORMATION_DANCE_INFO", \
    8, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_formation_dance_info_t, serial_num) }, \
         { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_dance_info_t, dance_id) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 4, offsetof(mavlink_formation_dance_info_t, position) }, \
         { "rgbw", NULL, MAVLINK_TYPE_UINT8_T, 4, 18, offsetof(mavlink_formation_dance_info_t, rgbw) }, \
         { "light_ctr", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_formation_dance_info_t, light_ctr) }, \
         { "mode_ctr", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_formation_dance_info_t, mode_ctr) }, \
         { "reserve0", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_formation_dance_info_t, reserve0) }, \
         { "reserve1", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_formation_dance_info_t, reserve1) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_DANCE_INFO { \
    "FORMATION_DANCE_INFO", \
    8, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_formation_dance_info_t, serial_num) }, \
         { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_dance_info_t, dance_id) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 4, offsetof(mavlink_formation_dance_info_t, position) }, \
         { "rgbw", NULL, MAVLINK_TYPE_UINT8_T, 4, 18, offsetof(mavlink_formation_dance_info_t, rgbw) }, \
         { "light_ctr", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_formation_dance_info_t, light_ctr) }, \
         { "mode_ctr", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_formation_dance_info_t, mode_ctr) }, \
         { "reserve0", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_formation_dance_info_t, reserve0) }, \
         { "reserve1", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_formation_dance_info_t, reserve1) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_dance_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param dance_id The formation dance number. E.g: 36.
 * @param position Distance between the start points of x, y, z. E.g: 10, 20, 30.
 * @param rgbw Light RGBW. E.g: 255 255 255 255.
 * @param light_ctr Light control. E.g: 1.
 * @param mode_ctr Mode control about arm or disarm etc.. E.g: 1.
 * @param reserve0 Reservr0. E.g: 0.
 * @param reserve1 Reservr1. E.g: 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_dance_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t serial_num, uint32_t dance_id, const float *position, const uint8_t *rgbw, uint8_t light_ctr, uint8_t mode_ctr, uint8_t reserve0, uint8_t reserve1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint16_t(buf, 16, serial_num);
    _mav_put_uint8_t(buf, 22, light_ctr);
    _mav_put_uint8_t(buf, 23, mode_ctr);
    _mav_put_uint8_t(buf, 24, reserve0);
    _mav_put_uint8_t(buf, 25, reserve1);
    _mav_put_float_array(buf, 4, position, 3);
    _mav_put_uint8_t_array(buf, 18, rgbw, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN);
#else
    mavlink_formation_dance_info_t packet;
    packet.dance_id = dance_id;
    packet.serial_num = serial_num;
    packet.light_ctr = light_ctr;
    packet.mode_ctr = mode_ctr;
    packet.reserve0 = reserve0;
    packet.reserve1 = reserve1;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.rgbw, rgbw, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_DANCE_INFO;
    return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
}

/**
 * @brief Pack a formation_dance_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param dance_id The formation dance number. E.g: 36.
 * @param position Distance between the start points of x, y, z. E.g: 10, 20, 30.
 * @param rgbw Light RGBW. E.g: 255 255 255 255.
 * @param light_ctr Light control. E.g: 1.
 * @param mode_ctr Mode control about arm or disarm etc.. E.g: 1.
 * @param reserve0 Reservr0. E.g: 0.
 * @param reserve1 Reservr1. E.g: 0.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_dance_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t serial_num,uint32_t dance_id,const float *position,const uint8_t *rgbw,uint8_t light_ctr,uint8_t mode_ctr,uint8_t reserve0,uint8_t reserve1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint16_t(buf, 16, serial_num);
    _mav_put_uint8_t(buf, 22, light_ctr);
    _mav_put_uint8_t(buf, 23, mode_ctr);
    _mav_put_uint8_t(buf, 24, reserve0);
    _mav_put_uint8_t(buf, 25, reserve1);
    _mav_put_float_array(buf, 4, position, 3);
    _mav_put_uint8_t_array(buf, 18, rgbw, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN);
#else
    mavlink_formation_dance_info_t packet;
    packet.dance_id = dance_id;
    packet.serial_num = serial_num;
    packet.light_ctr = light_ctr;
    packet.mode_ctr = mode_ctr;
    packet.reserve0 = reserve0;
    packet.reserve1 = reserve1;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.rgbw, rgbw, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_DANCE_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
}

/**
 * @brief Encode a formation_dance_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_dance_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_dance_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_dance_info_t* formation_dance_info)
{
    return mavlink_msg_formation_dance_info_pack(system_id, component_id, msg, formation_dance_info->serial_num, formation_dance_info->dance_id, formation_dance_info->position, formation_dance_info->rgbw, formation_dance_info->light_ctr, formation_dance_info->mode_ctr, formation_dance_info->reserve0, formation_dance_info->reserve1);
}

/**
 * @brief Encode a formation_dance_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_dance_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_dance_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_dance_info_t* formation_dance_info)
{
    return mavlink_msg_formation_dance_info_pack_chan(system_id, component_id, chan, msg, formation_dance_info->serial_num, formation_dance_info->dance_id, formation_dance_info->position, formation_dance_info->rgbw, formation_dance_info->light_ctr, formation_dance_info->mode_ctr, formation_dance_info->reserve0, formation_dance_info->reserve1);
}

/**
 * @brief Send a formation_dance_info message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param dance_id The formation dance number. E.g: 36.
 * @param position Distance between the start points of x, y, z. E.g: 10, 20, 30.
 * @param rgbw Light RGBW. E.g: 255 255 255 255.
 * @param light_ctr Light control. E.g: 1.
 * @param mode_ctr Mode control about arm or disarm etc.. E.g: 1.
 * @param reserve0 Reservr0. E.g: 0.
 * @param reserve1 Reservr1. E.g: 0.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_dance_info_send(mavlink_channel_t chan, uint16_t serial_num, uint32_t dance_id, const float *position, const uint8_t *rgbw, uint8_t light_ctr, uint8_t mode_ctr, uint8_t reserve0, uint8_t reserve1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint16_t(buf, 16, serial_num);
    _mav_put_uint8_t(buf, 22, light_ctr);
    _mav_put_uint8_t(buf, 23, mode_ctr);
    _mav_put_uint8_t(buf, 24, reserve0);
    _mav_put_uint8_t(buf, 25, reserve1);
    _mav_put_float_array(buf, 4, position, 3);
    _mav_put_uint8_t_array(buf, 18, rgbw, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE_INFO, buf,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
#else
    mavlink_formation_dance_info_t packet;
    packet.dance_id = dance_id;
    packet.serial_num = serial_num;
    packet.light_ctr = light_ctr;
    packet.mode_ctr = mode_ctr;
    packet.reserve0 = reserve0;
    packet.reserve1 = reserve1;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.rgbw, rgbw, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE_INFO, (const char *)&packet,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
#endif
}

/**
 * @brief Send a formation_dance_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_dance_info_send_struct(mavlink_channel_t chan, const mavlink_formation_dance_info_t* formation_dance_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_dance_info_send(chan, formation_dance_info->serial_num, formation_dance_info->dance_id, formation_dance_info->position, formation_dance_info->rgbw, formation_dance_info->light_ctr, formation_dance_info->mode_ctr, formation_dance_info->reserve0, formation_dance_info->reserve1);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE_INFO, (const char *)formation_dance_info,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_dance_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t serial_num, uint32_t dance_id, const float *position, const uint8_t *rgbw, uint8_t light_ctr, uint8_t mode_ctr, uint8_t reserve0, uint8_t reserve1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint16_t(buf, 16, serial_num);
    _mav_put_uint8_t(buf, 22, light_ctr);
    _mav_put_uint8_t(buf, 23, mode_ctr);
    _mav_put_uint8_t(buf, 24, reserve0);
    _mav_put_uint8_t(buf, 25, reserve1);
    _mav_put_float_array(buf, 4, position, 3);
    _mav_put_uint8_t_array(buf, 18, rgbw, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE_INFO, buf,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
#else
    mavlink_formation_dance_info_t *packet = (mavlink_formation_dance_info_t *)msgbuf;
    packet->dance_id = dance_id;
    packet->serial_num = serial_num;
    packet->light_ctr = light_ctr;
    packet->mode_ctr = mode_ctr;
    packet->reserve0 = reserve0;
    packet->reserve1 = reserve1;
    mav_array_memcpy(packet->position, position, sizeof(float)*3);
    mav_array_memcpy(packet->rgbw, rgbw, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE_INFO, (const char *)packet,  MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_DANCE_INFO UNPACKING


/**
 * @brief Get field serial_num from formation_dance_info message
 *
 * @return The serilal number of Aircraft. E.g: 13.
 */
static inline uint16_t mavlink_msg_formation_dance_info_get_serial_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field dance_id from formation_dance_info message
 *
 * @return The formation dance number. E.g: 36.
 */
static inline uint32_t mavlink_msg_formation_dance_info_get_dance_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  2);
}

/**
 * @brief Get field position from formation_dance_info message
 *
 * @return Distance between the start points of x, y, z. E.g: 10, 20, 30.
 */
static inline uint16_t mavlink_msg_formation_dance_info_get_position(const mavlink_message_t* msg, float *position)
{
    return _MAV_RETURN_float_array(msg, position, 3,  6);
}

/**
 * @brief Get field rgbw from formation_dance_info message
 *
 * @return Light RGBW. E.g: 255 255 255 255.
 */
static inline uint16_t mavlink_msg_formation_dance_info_get_rgbw(const mavlink_message_t* msg, uint8_t *rgbw)
{
    return _MAV_RETURN_uint8_t_array(msg, rgbw, 4,  18);
}

/**
 * @brief Get field light_ctr from formation_dance_info message
 *
 * @return Light control. E.g: 1.
 */
static inline uint8_t mavlink_msg_formation_dance_info_get_light_ctr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field mode_ctr from formation_dance_info message
 *
 * @return Mode control about arm or disarm etc.. E.g: 1.
 */
static inline uint8_t mavlink_msg_formation_dance_info_get_mode_ctr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field reserve0 from formation_dance_info message
 *
 * @return Reservr0. E.g: 0.
 */
static inline uint8_t mavlink_msg_formation_dance_info_get_reserve0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field reserve1 from formation_dance_info message
 *
 * @return Reservr1. E.g: 0.
 */
static inline uint8_t mavlink_msg_formation_dance_info_get_reserve1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Decode a formation_dance_info message into a struct
 *
 * @param msg The message to decode
 * @param formation_dance_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_dance_info_decode(const mavlink_message_t* msg, mavlink_formation_dance_info_t* formation_dance_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    formation_dance_info->dance_id = mavlink_msg_formation_dance_info_get_dance_id(msg);
    mavlink_msg_formation_dance_info_get_position(msg, formation_dance_info->position);
    formation_dance_info->serial_num = mavlink_msg_formation_dance_info_get_serial_num(msg);
    mavlink_msg_formation_dance_info_get_rgbw(msg, formation_dance_info->rgbw);
    formation_dance_info->light_ctr = mavlink_msg_formation_dance_info_get_light_ctr(msg);
    formation_dance_info->mode_ctr = mavlink_msg_formation_dance_info_get_mode_ctr(msg);
    formation_dance_info->reserve0 = mavlink_msg_formation_dance_info_get_reserve0(msg);
    formation_dance_info->reserve1 = mavlink_msg_formation_dance_info_get_reserve1(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN;
        memset(formation_dance_info, 0, MAVLINK_MSG_ID_FORMATION_DANCE_INFO_LEN);
    memcpy(formation_dance_info, _MAV_PAYLOAD(msg), len);
#endif
}
