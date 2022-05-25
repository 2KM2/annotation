#pragma once
// MESSAGE RETURN_UWB_ANTHOR_POSITION PACKING

#define MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION 179

#pragma pack(1)
typedef struct __mavlink_return_uwb_anthor_position_t {
 int32_t anthor_position_x[8]; /*< Anthor position x.*/
 int32_t anthor_position_y[8]; /*< Anthor position y.*/
 int32_t anthor_position_z[8]; /*< Anthor position z.*/
 uint16_t id; /*< Drone ID. E.g: 0.*/
 uint8_t result_flag; /*< Result. E.g: 0, failed; 1, succesed; 2, answer.*/
} mavlink_return_uwb_anthor_position_t;
#pragma pack()

#define MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN 99
#define MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_MIN_LEN 99
#define MAVLINK_MSG_ID_179_LEN 99
#define MAVLINK_MSG_ID_179_MIN_LEN 99

#define MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC 235
#define MAVLINK_MSG_ID_179_CRC 235

#define MAVLINK_MSG_RETURN_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_X_LEN 8
#define MAVLINK_MSG_RETURN_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_Y_LEN 8
#define MAVLINK_MSG_RETURN_UWB_ANTHOR_POSITION_FIELD_ANTHOR_POSITION_Z_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RETURN_UWB_ANTHOR_POSITION { \
    179, \
    "RETURN_UWB_ANTHOR_POSITION", \
    5, \
    {  { "result_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_return_uwb_anthor_position_t, result_flag) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_return_uwb_anthor_position_t, id) }, \
         { "anthor_position_x", NULL, MAVLINK_TYPE_INT32_T, 8, 0, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_x) }, \
         { "anthor_position_y", NULL, MAVLINK_TYPE_INT32_T, 8, 32, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_y) }, \
         { "anthor_position_z", NULL, MAVLINK_TYPE_INT32_T, 8, 64, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RETURN_UWB_ANTHOR_POSITION { \
    "RETURN_UWB_ANTHOR_POSITION", \
    5, \
    {  { "result_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_return_uwb_anthor_position_t, result_flag) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_return_uwb_anthor_position_t, id) }, \
         { "anthor_position_x", NULL, MAVLINK_TYPE_INT32_T, 8, 0, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_x) }, \
         { "anthor_position_y", NULL, MAVLINK_TYPE_INT32_T, 8, 32, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_y) }, \
         { "anthor_position_z", NULL, MAVLINK_TYPE_INT32_T, 8, 64, offsetof(mavlink_return_uwb_anthor_position_t, anthor_position_z) }, \
         } \
}
#endif

/**
 * @brief Pack a return_uwb_anthor_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param result_flag Result. E.g: 0, failed; 1, succesed.
 * @param id Drone ID. E.g: 0.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t result_flag, uint16_t id, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint16_t(buf, 96, id);
    _mav_put_uint8_t(buf, 98, result_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN);
#else
    mavlink_return_uwb_anthor_position_t packet;
    packet.id = id;
    packet.result_flag = result_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
}

/**
 * @brief Pack a return_uwb_anthor_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param result_flag Result. E.g: 0, failed; 1, succesed.
 * @param id Drone ID. E.g: 0.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t result_flag,uint16_t id,const int32_t *anthor_position_x,const int32_t *anthor_position_y,const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint16_t(buf, 96, id);
    _mav_put_uint8_t(buf, 98, result_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN);
#else
    mavlink_return_uwb_anthor_position_t packet;
    packet.id = id;
    packet.result_flag = result_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
}

/**
 * @brief Encode a return_uwb_anthor_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param return_uwb_anthor_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_return_uwb_anthor_position_t* return_uwb_anthor_position)
{
    return mavlink_msg_return_uwb_anthor_position_pack(system_id, component_id, msg, return_uwb_anthor_position->result_flag, return_uwb_anthor_position->id, return_uwb_anthor_position->anthor_position_x, return_uwb_anthor_position->anthor_position_y, return_uwb_anthor_position->anthor_position_z);
}

/**
 * @brief Encode a return_uwb_anthor_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param return_uwb_anthor_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_return_uwb_anthor_position_t* return_uwb_anthor_position)
{
    return mavlink_msg_return_uwb_anthor_position_pack_chan(system_id, component_id, chan, msg, return_uwb_anthor_position->result_flag, return_uwb_anthor_position->id, return_uwb_anthor_position->anthor_position_x, return_uwb_anthor_position->anthor_position_y, return_uwb_anthor_position->anthor_position_z);
}

/**
 * @brief Send a return_uwb_anthor_position message
 * @param chan MAVLink channel to send the message
 *
 * @param result_flag Result. E.g: 0, failed; 1, succesed.
 * @param id Drone ID. E.g: 0.
 * @param anthor_position_x Anthor position x.
 * @param anthor_position_y Anthor position y.
 * @param anthor_position_z Anthor position z.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_return_uwb_anthor_position_send(mavlink_channel_t chan, uint8_t result_flag, uint16_t id, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN];
    _mav_put_uint16_t(buf, 96, id);
    _mav_put_uint8_t(buf, 98, result_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION, buf, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
#else
    mavlink_return_uwb_anthor_position_t packet;
    packet.id = id;
    packet.result_flag = result_flag;
    mav_array_memcpy(packet.anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet.anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION, (const char *)&packet, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
#endif
}

/**
 * @brief Send a return_uwb_anthor_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_return_uwb_anthor_position_send_struct(mavlink_channel_t chan, const mavlink_return_uwb_anthor_position_t* return_uwb_anthor_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_return_uwb_anthor_position_send(chan, return_uwb_anthor_position->result_flag, return_uwb_anthor_position->id, return_uwb_anthor_position->anthor_position_x, return_uwb_anthor_position->anthor_position_y, return_uwb_anthor_position->anthor_position_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION, (const char *)return_uwb_anthor_position, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_return_uwb_anthor_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t result_flag, uint16_t id, const int32_t *anthor_position_x, const int32_t *anthor_position_y, const int32_t *anthor_position_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 96, id);
    _mav_put_uint8_t(buf, 98, result_flag);
    _mav_put_int32_t_array(buf, 0, anthor_position_x, 8);
    _mav_put_int32_t_array(buf, 32, anthor_position_y, 8);
    _mav_put_int32_t_array(buf, 64, anthor_position_z, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION, buf, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
#else
    mavlink_return_uwb_anthor_position_t *packet = (mavlink_return_uwb_anthor_position_t *)msgbuf;
    packet->id = id;
    packet->result_flag = result_flag;
    mav_array_memcpy(packet->anthor_position_x, anthor_position_x, sizeof(int32_t)*8);
    mav_array_memcpy(packet->anthor_position_y, anthor_position_y, sizeof(int32_t)*8);
    mav_array_memcpy(packet->anthor_position_z, anthor_position_z, sizeof(int32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION, (const char *)packet, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE RETURN_UWB_ANTHOR_POSITION UNPACKING


/**
 * @brief Get field result_flag from return_uwb_anthor_position message
 *
 * @return Result. E.g: 0, failed; 1, succesed.
 */
static inline uint8_t mavlink_msg_return_uwb_anthor_position_get_result_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  98);
}

/**
 * @brief Get field id from return_uwb_anthor_position message
 *
 * @return Drone ID. E.g: 0.
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  96);
}

/**
 * @brief Get field anthor_position_x from return_uwb_anthor_position message
 *
 * @return Anthor position x.
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_get_anthor_position_x(const mavlink_message_t* msg, int32_t *anthor_position_x)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_x, 8,  0);
}

/**
 * @brief Get field anthor_position_y from return_uwb_anthor_position message
 *
 * @return Anthor position y.
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_get_anthor_position_y(const mavlink_message_t* msg, int32_t *anthor_position_y)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_y, 8,  32);
}

/**
 * @brief Get field anthor_position_z from return_uwb_anthor_position message
 *
 * @return Anthor position z.
 */
static inline uint16_t mavlink_msg_return_uwb_anthor_position_get_anthor_position_z(const mavlink_message_t* msg, int32_t *anthor_position_z)
{
    return _MAV_RETURN_int32_t_array(msg, anthor_position_z, 8,  64);
}

/**
 * @brief Decode a return_uwb_anthor_position message into a struct
 *
 * @param msg The message to decode
 * @param return_uwb_anthor_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_return_uwb_anthor_position_decode(const mavlink_message_t* msg, mavlink_return_uwb_anthor_position_t* return_uwb_anthor_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_return_uwb_anthor_position_get_anthor_position_x(msg, return_uwb_anthor_position->anthor_position_x);
    mavlink_msg_return_uwb_anthor_position_get_anthor_position_y(msg, return_uwb_anthor_position->anthor_position_y);
    mavlink_msg_return_uwb_anthor_position_get_anthor_position_z(msg, return_uwb_anthor_position->anthor_position_z);
    return_uwb_anthor_position->id = mavlink_msg_return_uwb_anthor_position_get_id(msg);
    return_uwb_anthor_position->result_flag = mavlink_msg_return_uwb_anthor_position_get_result_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN? msg->len : MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN;
        memset(return_uwb_anthor_position, 0, MAVLINK_MSG_ID_RETURN_UWB_ANTHOR_POSITION_LEN);
    memcpy(return_uwb_anthor_position, _MAV_PAYLOAD(msg), len);
#endif
}
