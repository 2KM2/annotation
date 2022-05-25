#pragma once
// MESSAGE plane_ack PACKING

#define MAVLINK_MSG_ID_plane_ack 210


typedef struct __mavlink_plane_ack_t {
 uint32_t token; /*<  token*/
 uint16_t plane_id; /*<  plane_id*/
 uint8_t cmd; /*<  cmd*/
 uint8_t result; /*<  result*/
 uint8_t type; /*<  type*/
} mavlink_plane_ack_t;

#define MAVLINK_MSG_ID_plane_ack_LEN 9
#define MAVLINK_MSG_ID_plane_ack_MIN_LEN 9
#define MAVLINK_MSG_ID_210_LEN 9
#define MAVLINK_MSG_ID_210_MIN_LEN 9

#define MAVLINK_MSG_ID_plane_ack_CRC 211
#define MAVLINK_MSG_ID_210_CRC 211



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_plane_ack { \
    210, \
    "plane_ack", \
    5, \
    {  { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_plane_ack_t, token) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_plane_ack_t, plane_id) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_plane_ack_t, cmd) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_plane_ack_t, result) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_plane_ack_t, type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_plane_ack { \
    "plane_ack", \
    5, \
    {  { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_plane_ack_t, token) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_plane_ack_t, plane_id) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_plane_ack_t, cmd) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_plane_ack_t, result) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_plane_ack_t, type) }, \
         } \
}
#endif

/**
 * @brief Pack a plane_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param token  token
 * @param plane_id  plane_id
 * @param cmd  cmd
 * @param result  result
 * @param type  type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_plane_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t token, uint16_t plane_id, uint8_t cmd, uint8_t result, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_ack_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, plane_id);
    _mav_put_uint8_t(buf, 6, cmd);
    _mav_put_uint8_t(buf, 7, result);
    _mav_put_uint8_t(buf, 8, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_plane_ack_LEN);
#else
    mavlink_plane_ack_t packet;
    packet.token = token;
    packet.plane_id = plane_id;
    packet.cmd = cmd;
    packet.result = result;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_plane_ack_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_plane_ack;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
}

/**
 * @brief Pack a plane_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param token  token
 * @param plane_id  plane_id
 * @param cmd  cmd
 * @param result  result
 * @param type  type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_plane_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t token,uint16_t plane_id,uint8_t cmd,uint8_t result,uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_ack_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, plane_id);
    _mav_put_uint8_t(buf, 6, cmd);
    _mav_put_uint8_t(buf, 7, result);
    _mav_put_uint8_t(buf, 8, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_plane_ack_LEN);
#else
    mavlink_plane_ack_t packet;
    packet.token = token;
    packet.plane_id = plane_id;
    packet.cmd = cmd;
    packet.result = result;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_plane_ack_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_plane_ack;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
}

/**
 * @brief Encode a plane_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param plane_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_plane_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_plane_ack_t* plane_ack)
{
    return mavlink_msg_plane_ack_pack(system_id, component_id, msg, plane_ack->token, plane_ack->plane_id, plane_ack->cmd, plane_ack->result, plane_ack->type);
}

/**
 * @brief Encode a plane_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param plane_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_plane_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_plane_ack_t* plane_ack)
{
    return mavlink_msg_plane_ack_pack_chan(system_id, component_id, chan, msg, plane_ack->token, plane_ack->plane_id, plane_ack->cmd, plane_ack->result, plane_ack->type);
}

/**
 * @brief Send a plane_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param token  token
 * @param plane_id  plane_id
 * @param cmd  cmd
 * @param result  result
 * @param type  type
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_plane_ack_send(mavlink_channel_t chan, uint32_t token, uint16_t plane_id, uint8_t cmd, uint8_t result, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_ack_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, plane_id);
    _mav_put_uint8_t(buf, 6, cmd);
    _mav_put_uint8_t(buf, 7, result);
    _mav_put_uint8_t(buf, 8, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_ack, buf, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
#else
    mavlink_plane_ack_t packet;
    packet.token = token;
    packet.plane_id = plane_id;
    packet.cmd = cmd;
    packet.result = result;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_ack, (const char *)&packet, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
#endif
}

/**
 * @brief Send a plane_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_plane_ack_send_struct(mavlink_channel_t chan, const mavlink_plane_ack_t* plane_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_plane_ack_send(chan, plane_ack->token, plane_ack->plane_id, plane_ack->cmd, plane_ack->result, plane_ack->type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_ack, (const char *)plane_ack, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
#endif
}

#if MAVLINK_MSG_ID_plane_ack_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_plane_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t token, uint16_t plane_id, uint8_t cmd, uint8_t result, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, plane_id);
    _mav_put_uint8_t(buf, 6, cmd);
    _mav_put_uint8_t(buf, 7, result);
    _mav_put_uint8_t(buf, 8, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_ack, buf, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
#else
    mavlink_plane_ack_t *packet = (mavlink_plane_ack_t *)msgbuf;
    packet->token = token;
    packet->plane_id = plane_id;
    packet->cmd = cmd;
    packet->result = result;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_ack, (const char *)packet, MAVLINK_MSG_ID_plane_ack_MIN_LEN, MAVLINK_MSG_ID_plane_ack_LEN, MAVLINK_MSG_ID_plane_ack_CRC);
#endif
}
#endif

#endif

// MESSAGE plane_ack UNPACKING


/**
 * @brief Get field token from plane_ack message
 *
 * @return  token
 */
static inline uint32_t mavlink_msg_plane_ack_get_token(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field plane_id from plane_ack message
 *
 * @return  plane_id
 */
static inline uint16_t mavlink_msg_plane_ack_get_plane_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field cmd from plane_ack message
 *
 * @return  cmd
 */
static inline uint8_t mavlink_msg_plane_ack_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field result from plane_ack message
 *
 * @return  result
 */
static inline uint8_t mavlink_msg_plane_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field type from plane_ack message
 *
 * @return  type
 */
static inline uint8_t mavlink_msg_plane_ack_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a plane_ack message into a struct
 *
 * @param msg The message to decode
 * @param plane_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_plane_ack_decode(const mavlink_message_t* msg, mavlink_plane_ack_t* plane_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    plane_ack->token = mavlink_msg_plane_ack_get_token(msg);
    plane_ack->plane_id = mavlink_msg_plane_ack_get_plane_id(msg);
    plane_ack->cmd = mavlink_msg_plane_ack_get_cmd(msg);
    plane_ack->result = mavlink_msg_plane_ack_get_result(msg);
    plane_ack->type = mavlink_msg_plane_ack_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_plane_ack_LEN? msg->len : MAVLINK_MSG_ID_plane_ack_LEN;
        memset(plane_ack, 0, MAVLINK_MSG_ID_plane_ack_LEN);
    memcpy(plane_ack, _MAV_PAYLOAD(msg), len);
#endif
}
