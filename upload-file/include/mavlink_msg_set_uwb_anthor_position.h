#pragma once
// MESSAGE SET_UWB_ANTHOR_POSITION PACKING

#define MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION 178

#pragma pack(1)
typedef struct __mavlink_set_uwb_anthor_position_t {
 int32_t anthor_position_x[8]; /*< Anthor position x.*/
 int32_t anthor_position_y[8]; /*< Anthor position y.*/
 int32_t anthor_position_z[8]; /*< Anthor position z.*/
 uint8_t cmd_flag; /*< Cmd. E.g: 0, get uwb anthor position; 1, set uwb anthor position.*/
} mavlink_set_uwb_anthor_position_t;
#pragma pack()

#define MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN 97
#define MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_MIN_LEN 97
#define MAVLINK_MSG_ID_178_LEN 97
#define MAVLINK_MSG_ID_178_MIN_LEN 97

#define MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC 154
#define MAVLINK_MSG_ID_178_CRC 154

#define MAVLINK_MSG_SET_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_X_LEN 8
#define MAVLINK_MSG_SET_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_Y_LEN 8
#define MAVLINK_MSG_SET_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_Z_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_UWB_ANTHOR_POSITION { \
    178, \
    "SET_UWB_ANTHOR_POSITION", \
    4, \
    {  { "cmd_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 96, offsetof(mavlink_set_uwb_anthor_position_t, cmd_flag) }, \
         { "anthor_position_x", NULL, MAVLINK_TYPE_INT32_T, 8, 0, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_x) }, \
         { "anthor_position_y", NULL, MAVLINK_TYPE_INT32_T, 8, 32, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_y) }, \
         { "anthor_position_z", NULL, MAVLINK_TYPE_INT32_T, 8, 64, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_UWB_ANTHOR_POSITION { \
    "SET_UWB_ANTHOR_POSITION", \
    4, \
    {  { "cmd_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 96, offsetof(mavlink_set_uwb_anthor_position_t, cmd_flag) }, \
         { "anthor_position_x", NULL, MAVLINK_TYPE_INT32_T, 8, 0, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_x) }, \
         { "anthor_position_y", NULL, MAVLINK_TYPE_INT32_T, 8, 32, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_y) }, \
         { "anthor_position_z", NULL, MAVLINK_TYPE_INT32_T, 8, 64, offsetof(mavlink_set_uwb_anthor_position_t, anthor_position_z) }, \
         } \
}
#endif

/**
 * @brief Pack a set_uwb_anthor_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd_flag Cmd. E.g: 0, get uwb anthor position; 1, set uwb anthor position.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cmd_flag, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint8_t(buf, 96, cmd_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN);
#else
    mavlink_set_uwb_anthor_position_t packet;
    packet.cmd_flag = cmd_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
}

/**
 * @brief Pack a set_uwb_anthor_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_flag Cmd. E.g: 0, get uwb anthor position; 1, set uwb anthor position.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cmd_flag,const int32_t *anthor_position_x,const int32_t *anthor_position_y,const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint8_t(buf, 96, cmd_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN);
#else
    mavlink_set_uwb_anthor_position_t packet;
    packet.cmd_flag = cmd_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
}

/**
 * @brief Encode a set_uwb_anthor_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_uwb_anthor_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_uwb_anthor_position_t* set_uwb_anthor_position)
{
    return mavlink_msg_set_uwb_anthor_position_pack(system_id, component_id, msg, set_uwb_anthor_position->cmd_flag, set_uwb_anthor_position->anthor_position_x, set_uwb_anthor_position->anthor_position_y, set_uwb_anthor_position->anthor_position_z);
}

/**
 * @brief Encode a set_uwb_anthor_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_uwb_anthor_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_uwb_anthor_position_t* set_uwb_anthor_position)
{
    return mavlink_msg_set_uwb_anthor_position_pack_chan(system_id, component_id, chan, msg, set_uwb_anthor_position->cmd_flag, set_uwb_anthor_position->anthor_position_x, set_uwb_anthor_position->anthor_position_y, set_uwb_anthor_position->anthor_position_z);
}

/**
 * @brief Send a set_uwb_anthor_position message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd_flag Cmd. E.g: 0, get uwb anthor position; 1, set uwb anthor position.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_uwb_anthor_position_send(mavlink_channel_t chan, uint8_t cmd_flag, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint8_t(buf, 96, cmd_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION, buf, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
#else
    mavlink_set_uwb_anthor_position_t packet;
    packet.cmd_flag = cmd_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION, (const char *)&packet, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
#endif
}

/**
 * @brief Send a set_uwb_anthor_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_uwb_anthor_position_send_struct(mavlink_channel_t chan, const mavlink_set_uwb_anthor_position_t* set_uwb_anthor_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_uwb_anthor_position_send(chan, set_uwb_anthor_position->cmd_flag, set_uwb_anthor_position->anthor_position_x, set_uwb_anthor_position->anthor_position_y, set_uwb_anthor_position->anthor_position_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION, (const char *)set_uwb_anthor_position, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_uwb_anthor_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cmd_flag, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 96, cmd_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION, buf, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
#else
    mavlink_set_uwb_anthor_position_t *packet = (mavlink_set_uwb_anthor_position_t *)msgbuf;
    packet->cmd_flag = cmd_flag;
    mav_array_memcpy(packet->anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet->anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet->anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION, (const char *)packet, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_UWB_ANTHOR_POSITION UNPACKING


/**
 * @brief Get field cmd_flag from set_uwb_anthor_position message
 *
 * @return Cmd. E.g: 0, get uwb anthor position; 1, set uwb anthor position.
 */
static inline uint8_t mavlink_msg_set_uwb_anthor_position_get_cmd_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  96);
}

/**
 * @brief Get field anthor_position_x from set_uwb_anthor_position message
 *
 * @return Anthor position x.
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_get_anthor_position_x(const mavlink_message_t* msg, int32_t *anthor_position_x)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_x, 8,  0);
}

/**
 * @brief Get field anthor_position_y from set_uwb_anthor_position message
 *
 * @return Anthor position y.
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_get_anthor_position_y(const mavlink_message_t* msg, int32_t *anthor_position_y)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_y, 8,  32);
}

/**
 * @brief Get field anthor_position_z from set_uwb_anthor_position message
 *
 * @return Anthor position z.
 */
static inline uint16_t mavlink_msg_set_uwb_anthor_position_get_anthor_position_z(const mavlink_message_t* msg, int32_t *anthor_position_z)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_z, 8,  64);
}

/**
 * @brief Decode a set_uwb_anthor_position message into a struct
 *
 * @param msg The message to decode
 * @param set_uwb_anthor_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_uwb_anthor_position_decode(const mavlink_message_t* msg, mavlink_set_uwb_anthor_position_t* set_uwb_anthor_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_uwb_anthor_position_get_anthor_position_x(msg, set_uwb_anthor_position->anthor_position_x);
    mavlink_msg_set_uwb_anthor_position_get_anthor_position_y(msg, set_uwb_anthor_position->anthor_position_y);
    mavlink_msg_set_uwb_anthor_position_get_anthor_position_z(msg, set_uwb_anthor_position->anthor_position_z);
    set_uwb_anthor_position->cmd_flag = mavlink_msg_set_uwb_anthor_position_get_cmd_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN? msg->len : MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN;
        memset(set_uwb_anthor_position, 0, MAVLINK_MSG_ID_SET_UWB_ANTHOR_POSITION_LEN);
    memcpy(set_uwb_anthor_position, _MAV_PAYLOAD(msg), len);
#endif
}
