#pragma once
// MESSAGE HOLLOW_SET PACKING

#define MAVLINK_MSG_ID_HOLLOW_SET 186

#pragma pack(1)
typedef struct __mavlink_hollow_set_t {
 int32_t x[4]; /*<  The x position of Aircraft. E.g: 36.*/
 int32_t y[4]; /*<  The y position of Aircraft. E.g: 36.*/
 uint32_t start_time; /*<  The start time of hollow (ms). E.g: 3000.*/
} mavlink_hollow_set_t;
#pragma pack()

#define MAVLINK_MSG_ID_HOLLOW_SET_LEN 36
#define MAVLINK_MSG_ID_HOLLOW_SET_MIN_LEN 36
#define MAVLINK_MSG_ID_186_LEN 36
#define MAVLINK_MSG_ID_186_MIN_LEN 36

#define MAVLINK_MSG_ID_HOLLOW_SET_CRC 69
#define MAVLINK_MSG_ID_186_CRC 69

#define MAVLINK_MSG_HOLLOW_SET_FIELD_X_LEN 4
#define MAVLINK_MSG_HOLLOW_SET_FIELD_Y_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HOLLOW_SET { \
    186, \
    "HOLLOW_SET", \
    3, \
    {  { "x", NULL, MAVLINK_TYPE_INT32_T, 4, 0, offsetof(mavlink_hollow_set_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 4, 16, offsetof(mavlink_hollow_set_t, y) }, \
         { "start_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_hollow_set_t, start_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HOLLOW_SET { \
    "HOLLOW_SET", \
    3, \
    {  { "x", NULL, MAVLINK_TYPE_INT32_T, 4, 0, offsetof(mavlink_hollow_set_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 4, 16, offsetof(mavlink_hollow_set_t, y) }, \
         { "start_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_hollow_set_t, start_time) }, \
         } \
}
#endif

/**
 * @brief Pack a hollow_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x  The x position of Aircraft. E.g: 36.
 * @param y  The y position of Aircraft. E.g: 36.
 * @param start_time  The start time of hollow (ms). E.g: 3000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hollow_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const int32_t *x, const int32_t *y, uint32_t start_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HOLLOW_SET_LEN];
    _mav_put_uint32_t(buf, 32, start_time);
    _mav_put_int32_t_array(buf, 0, x, 4);
    _mav_put_int32_t_array(buf, 16, y, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HOLLOW_SET_LEN);
#else
    mavlink_hollow_set_t packet;
    packet.start_time = start_time;
    mav_array_memcpy(packet.x, x, sizeof(int32_t)*4);
    mav_array_memcpy(packet.y, y, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HOLLOW_SET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HOLLOW_SET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
}

/**
 * @brief Pack a hollow_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x  The x position of Aircraft. E.g: 36.
 * @param y  The y position of Aircraft. E.g: 36.
 * @param start_time  The start time of hollow (ms). E.g: 3000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hollow_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const int32_t *x,const int32_t *y,uint32_t start_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HOLLOW_SET_LEN];
    _mav_put_uint32_t(buf, 32, start_time);
    _mav_put_int32_t_array(buf, 0, x, 4);
    _mav_put_int32_t_array(buf, 16, y, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HOLLOW_SET_LEN);
#else
    mavlink_hollow_set_t packet;
    packet.start_time = start_time;
    mav_array_memcpy(packet.x, x, sizeof(int32_t)*4);
    mav_array_memcpy(packet.y, y, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HOLLOW_SET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HOLLOW_SET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
}

/**
 * @brief Encode a hollow_set struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hollow_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hollow_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hollow_set_t* hollow_set)
{
    return mavlink_msg_hollow_set_pack(system_id, component_id, msg, hollow_set->x, hollow_set->y, hollow_set->start_time);
}

/**
 * @brief Encode a hollow_set struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hollow_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hollow_set_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hollow_set_t* hollow_set)
{
    return mavlink_msg_hollow_set_pack_chan(system_id, component_id, chan, msg, hollow_set->x, hollow_set->y, hollow_set->start_time);
}

/**
 * @brief Send a hollow_set message
 * @param chan MAVLink channel to send the message
 *
 * @param x  The x position of Aircraft. E.g: 36.
 * @param y  The y position of Aircraft. E.g: 36.
 * @param start_time  The start time of hollow (ms). E.g: 3000.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hollow_set_send(mavlink_channel_t chan, const int32_t *x, const int32_t *y, uint32_t start_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HOLLOW_SET_LEN];
    _mav_put_uint32_t(buf, 32, start_time);
    _mav_put_int32_t_array(buf, 0, x, 4);
    _mav_put_int32_t_array(buf, 16, y, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HOLLOW_SET, buf, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
#else
    mavlink_hollow_set_t packet;
    packet.start_time = start_time;
    mav_array_memcpy(packet.x, x, sizeof(int32_t)*4);
    mav_array_memcpy(packet.y, y, sizeof(int32_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HOLLOW_SET, (const char *)&packet, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
#endif
}

/**
 * @brief Send a hollow_set message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hollow_set_send_struct(mavlink_channel_t chan, const mavlink_hollow_set_t* hollow_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hollow_set_send(chan, hollow_set->x, hollow_set->y, hollow_set->start_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HOLLOW_SET, (const char *)hollow_set, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
#endif
}

#if MAVLINK_MSG_ID_HOLLOW_SET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hollow_set_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int32_t *x, const int32_t *y, uint32_t start_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 32, start_time);
    _mav_put_int32_t_array(buf, 0, x, 4);
    _mav_put_int32_t_array(buf, 16, y, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HOLLOW_SET, buf, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
#else
    mavlink_hollow_set_t *packet = (mavlink_hollow_set_t *)msgbuf;
    packet->start_time = start_time;
    mav_array_memcpy(packet->x, x, sizeof(int32_t)*4);
    mav_array_memcpy(packet->y, y, sizeof(int32_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HOLLOW_SET, (const char *)packet, MAVLINK_MSG_ID_HOLLOW_SET_LEN, MAVLINK_MSG_ID_HOLLOW_SET_CRC);
#endif
}
#endif

#endif

// MESSAGE HOLLOW_SET UNPACKING


/**
 * @brief Get field x from hollow_set message
 *
 * @return  The x position of Aircraft. E.g: 36.
 */
static inline uint16_t mavlink_msg_hollow_set_get_x(const mavlink_message_t* msg, int32_t *x)
{
    return _MAV_RETURN_int32_t_array(msg, x, 4,  0);
}

/**
 * @brief Get field y from hollow_set message
 *
 * @return  The y position of Aircraft. E.g: 36.
 */
static inline uint16_t mavlink_msg_hollow_set_get_y(const mavlink_message_t* msg, int32_t *y)
{
    return _MAV_RETURN_int32_t_array(msg, y, 4,  16);
}

/**
 * @brief Get field start_time from hollow_set message
 *
 * @return  The start time of hollow (ms). E.g: 3000.
 */
static inline uint32_t mavlink_msg_hollow_set_get_start_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Decode a hollow_set message into a struct
 *
 * @param msg The message to decode
 * @param hollow_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_hollow_set_decode(const mavlink_message_t* msg, mavlink_hollow_set_t* hollow_set)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hollow_set_get_x(msg, hollow_set->x);
    mavlink_msg_hollow_set_get_y(msg, hollow_set->y);
    hollow_set->start_time = mavlink_msg_hollow_set_get_start_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HOLLOW_SET_LEN? msg->len : MAVLINK_MSG_ID_HOLLOW_SET_LEN;
        memset(hollow_set, 0, MAVLINK_MSG_ID_HOLLOW_SET_LEN);
    memcpy(hollow_set, _MAV_PAYLOAD(msg), len);
#endif
}
