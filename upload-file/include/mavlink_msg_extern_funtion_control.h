#pragma once
// MESSAGE EXTERN_FUNTION_CONTROL PACKING

#define MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL 13

MAVPACKED(
typedef struct __mavlink_extern_funtion_control_t {
 float position[3]; /*< */
 float yaw; /*< Yaw control.*/
 uint8_t token; /*< token.*/
 uint8_t cmd; /*< 0:idle. 1. arm. 2. disarm. 3:takeoff. 4:land entry. 5.land exit. 6. control*/
 uint8_t result; /*< 1: success. 2:fail.*/
}) mavlink_extern_funtion_control_t;

#define MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN 19
#define MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN 19
#define MAVLINK_MSG_ID_13_LEN 19
#define MAVLINK_MSG_ID_13_MIN_LEN 19

#define MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC 48
#define MAVLINK_MSG_ID_13_CRC 48

#define MAVLINK_MSG_EXTERN_FUNTION_CONTROL_FIELD_POSITION_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXTERN_FUNTION_CONTROL { \
    13, \
    "EXTERN_FUNTION_CONTROL", \
    5, \
    {  { "token", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_extern_funtion_control_t, token) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_extern_funtion_control_t, cmd) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_extern_funtion_control_t, position) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_extern_funtion_control_t, yaw) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_extern_funtion_control_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXTERN_FUNTION_CONTROL { \
    "EXTERN_FUNTION_CONTROL", \
    5, \
    {  { "token", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_extern_funtion_control_t, token) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_extern_funtion_control_t, cmd) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_extern_funtion_control_t, position) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_extern_funtion_control_t, yaw) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_extern_funtion_control_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a extern_funtion_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param token token.
 * @param cmd 0:idle. 1. arm. 2. disarm. 3:takeoff. 4:land entry. 5.land exit. 6. control
 * @param position 
 * @param yaw Yaw control.
 * @param result 1: success. 2:fail.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extern_funtion_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t token, uint8_t cmd, const float *position, float yaw, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN];
    _mav_put_float(buf, 12, yaw);
    _mav_put_uint8_t(buf, 16, token);
    _mav_put_uint8_t(buf, 17, cmd);
    _mav_put_uint8_t(buf, 18, result);
    _mav_put_float_array(buf, 0, position, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN);
#else
    mavlink_extern_funtion_control_t packet;
    packet.yaw = yaw;
    packet.token = token;
    packet.cmd = cmd;
    packet.result = result;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
}

/**
 * @brief Pack a extern_funtion_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param token token.
 * @param cmd 0:idle. 1. arm. 2. disarm. 3:takeoff. 4:land entry. 5.land exit. 6. control
 * @param position 
 * @param yaw Yaw control.
 * @param result 1: success. 2:fail.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extern_funtion_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t token,uint8_t cmd,const float *position,float yaw,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN];
    _mav_put_float(buf, 12, yaw);
    _mav_put_uint8_t(buf, 16, token);
    _mav_put_uint8_t(buf, 17, cmd);
    _mav_put_uint8_t(buf, 18, result);
    _mav_put_float_array(buf, 0, position, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN);
#else
    mavlink_extern_funtion_control_t packet;
    packet.yaw = yaw;
    packet.token = token;
    packet.cmd = cmd;
    packet.result = result;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
}

/**
 * @brief Encode a extern_funtion_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param extern_funtion_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extern_funtion_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_extern_funtion_control_t* extern_funtion_control)
{
    return mavlink_msg_extern_funtion_control_pack(system_id, component_id, msg, extern_funtion_control->token, extern_funtion_control->cmd, extern_funtion_control->position, extern_funtion_control->yaw, extern_funtion_control->result);
}

/**
 * @brief Encode a extern_funtion_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param extern_funtion_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extern_funtion_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_extern_funtion_control_t* extern_funtion_control)
{
    return mavlink_msg_extern_funtion_control_pack_chan(system_id, component_id, chan, msg, extern_funtion_control->token, extern_funtion_control->cmd, extern_funtion_control->position, extern_funtion_control->yaw, extern_funtion_control->result);
}

/**
 * @brief Send a extern_funtion_control message
 * @param chan MAVLink channel to send the message
 *
 * @param token token.
 * @param cmd 0:idle. 1. arm. 2. disarm. 3:takeoff. 4:land entry. 5.land exit. 6. control
 * @param position 
 * @param yaw Yaw control.
 * @param result 1: success. 2:fail.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_extern_funtion_control_send(mavlink_channel_t chan, uint8_t token, uint8_t cmd, const float *position, float yaw, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN];
    _mav_put_float(buf, 12, yaw);
    _mav_put_uint8_t(buf, 16, token);
    _mav_put_uint8_t(buf, 17, cmd);
    _mav_put_uint8_t(buf, 18, result);
    _mav_put_float_array(buf, 0, position, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL, buf, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
#else
    mavlink_extern_funtion_control_t packet;
    packet.yaw = yaw;
    packet.token = token;
    packet.cmd = cmd;
    packet.result = result;
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
#endif
}

/**
 * @brief Send a extern_funtion_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_extern_funtion_control_send_struct(mavlink_channel_t chan, const mavlink_extern_funtion_control_t* extern_funtion_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_extern_funtion_control_send(chan, extern_funtion_control->token, extern_funtion_control->cmd, extern_funtion_control->position, extern_funtion_control->yaw, extern_funtion_control->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL, (const char *)extern_funtion_control, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_extern_funtion_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t token, uint8_t cmd, const float *position, float yaw, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 12, yaw);
    _mav_put_uint8_t(buf, 16, token);
    _mav_put_uint8_t(buf, 17, cmd);
    _mav_put_uint8_t(buf, 18, result);
    _mav_put_float_array(buf, 0, position, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL, buf, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
#else
    mavlink_extern_funtion_control_t *packet = (mavlink_extern_funtion_control_t *)msgbuf;
    packet->yaw = yaw;
    packet->token = token;
    packet->cmd = cmd;
    packet->result = result;
    mav_array_memcpy(packet->position, position, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL, (const char *)packet, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_MIN_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE EXTERN_FUNTION_CONTROL UNPACKING


/**
 * @brief Get field token from extern_funtion_control message
 *
 * @return token.
 */
static inline uint8_t mavlink_msg_extern_funtion_control_get_token(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field cmd from extern_funtion_control message
 *
 * @return 0:idle. 1. arm. 2. disarm. 3:takeoff. 4:land entry. 5.land exit. 6. control
 */
static inline uint8_t mavlink_msg_extern_funtion_control_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field position from extern_funtion_control message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_extern_funtion_control_get_position(const mavlink_message_t* msg, float *position)
{
    return _MAV_RETURN_float_array(msg, position, 3,  0);
}

/**
 * @brief Get field yaw from extern_funtion_control message
 *
 * @return Yaw control.
 */
static inline float mavlink_msg_extern_funtion_control_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field result from extern_funtion_control message
 *
 * @return 1: success. 2:fail.
 */
static inline uint8_t mavlink_msg_extern_funtion_control_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Decode a extern_funtion_control message into a struct
 *
 * @param msg The message to decode
 * @param extern_funtion_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_extern_funtion_control_decode(const mavlink_message_t* msg, mavlink_extern_funtion_control_t* extern_funtion_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_extern_funtion_control_get_position(msg, extern_funtion_control->position);
    extern_funtion_control->yaw = mavlink_msg_extern_funtion_control_get_yaw(msg);
    extern_funtion_control->token = mavlink_msg_extern_funtion_control_get_token(msg);
    extern_funtion_control->cmd = mavlink_msg_extern_funtion_control_get_cmd(msg);
    extern_funtion_control->result = mavlink_msg_extern_funtion_control_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN;
        memset(extern_funtion_control, 0, MAVLINK_MSG_ID_EXTERN_FUNTION_CONTROL_LEN);
    memcpy(extern_funtion_control, _MAV_PAYLOAD(msg), len);
#endif
}
