#pragma once
// MESSAGE plane_command PACKING

#define MAVLINK_MSG_ID_plane_command 218

typedef enum MAV_PLANE_CMD
{
    MAV_BATTERY =1,// 电量,data:当前电量剩余百分比 end_id:低点警告通知
    MAV_SHUTDOWN =2,
    MAV_PLANE_CMD_WIFI_RATE =3,
    MAV_PLANE_CMD_WIFI_MODE = 4,
    MAV_PLANE_CMD_TAKE_PHOTO = 5,
    MAVK_PLANE_CMD_TAKE_VIDEO = 6
}MAV_PLANE_CMD;


typedef struct __mavlink_plane_command_t {
 uint64_t utc; /*<  utc*/
 uint32_t token; /*<  token*/
 uint16_t data; /*<  data*/
 uint16_t start_id; /*<  start_id*/
 uint16_t end_id; /*<  end_id*/
 uint8_t cmd; /*<  cmd*/
 uint8_t ack; /*<  ack*/
 uint8_t type; /*<  type*/
} mavlink_plane_command_t;

#define MAVLINK_MSG_ID_plane_command_LEN 21
#define MAVLINK_MSG_ID_plane_command_MIN_LEN 21
#define MAVLINK_MSG_ID_218_LEN 21
#define MAVLINK_MSG_ID_218_MIN_LEN 21

#define MAVLINK_MSG_ID_plane_command_CRC 183
#define MAVLINK_MSG_ID_218_CRC 183



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_plane_command { \
    218, \
    "plane_command", \
    8, \
    {  { "utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_plane_command_t, utc) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_plane_command_t, token) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_plane_command_t, data) }, \
         { "start_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_plane_command_t, start_id) }, \
         { "end_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_plane_command_t, end_id) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_plane_command_t, cmd) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_plane_command_t, ack) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_plane_command_t, type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_plane_command { \
    "plane_command", \
    8, \
    {  { "utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_plane_command_t, utc) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_plane_command_t, token) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_plane_command_t, data) }, \
         { "start_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_plane_command_t, start_id) }, \
         { "end_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_plane_command_t, end_id) }, \
         { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_plane_command_t, cmd) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_plane_command_t, ack) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_plane_command_t, type) }, \
         } \
}
#endif

/**
 * @brief Pack a plane_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param utc  utc
 * @param token  token
 * @param data  data
 * @param start_id  start_id
 * @param end_id  end_id
 * @param cmd  cmd
 * @param ack  ack
 * @param type  type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_plane_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t utc, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id, uint8_t cmd, uint8_t ack, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_command_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_plane_command_LEN);
#else
    mavlink_plane_command_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_plane_command_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_plane_command;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
}

/**
 * @brief Pack a plane_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param utc  utc
 * @param token  token
 * @param data  data
 * @param start_id;  start_id
 * @param end_id  end_id
 * @param cmd  cmd
 * @param ack  ack
 * @param type  type
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_plane_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t utc,uint32_t token,uint16_t data,uint16_t start_id,uint16_t end_id,uint8_t cmd,uint8_t ack,uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_command_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_plane_command_LEN);
#else
    mavlink_plane_command_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_plane_command_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_plane_command;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
}

/**
 * @brief Encode a plane_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param plane_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_plane_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_plane_command_t* plane_command)
{
    return mavlink_msg_plane_command_pack(system_id, component_id, msg, plane_command->utc, plane_command->token, plane_command->data, plane_command->start_id, plane_command->end_id, plane_command->cmd, plane_command->ack, plane_command->type);
}

/**
 * @brief Encode a plane_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param plane_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_plane_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_plane_command_t* plane_command)
{
    return mavlink_msg_plane_command_pack_chan(system_id, component_id, chan, msg, plane_command->utc, plane_command->token, plane_command->data, plane_command->start_id, plane_command->end_id, plane_command->cmd, plane_command->ack, plane_command->type);
}

/**
 * @brief Send a plane_command message
 * @param chan MAVLink channel to send the message
 *
 * @param utc  utc
 * @param token  token
 * @param data  data
 * @param start_id  start_id
 * @param end_id  end_id
 * @param cmd  cmd
 * @param ack  ack
 * @param type  type
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_plane_command_send(mavlink_channel_t chan, uint64_t utc, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id, uint8_t cmd, uint8_t ack, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_plane_command_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_command, buf, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
#else
    mavlink_plane_command_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_command, (const char *)&packet, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
#endif
}

/**
 * @brief Send a plane_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_plane_command_send_struct(mavlink_channel_t chan, const mavlink_plane_command_t* plane_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_plane_command_send(chan, plane_command->utc, plane_command->token, plane_command->data, plane_command->start_id;, plane_command->end_id, plane_command->cmd, plane_command->ack, plane_command->type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_command, (const char *)plane_command, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
#endif
}

#if MAVLINK_MSG_ID_plane_command_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_plane_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t utc, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id, uint8_t cmd, uint8_t ack, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_command, buf, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
#else
    mavlink_plane_command_t *packet = (mavlink_plane_command_t *)msgbuf;
    packet->utc = utc;
    packet->token = token;
    packet->data = data;
    packet->start_id = start_id;
    packet->end_id = end_id;
    packet->cmd = cmd;
    packet->ack = ack;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_plane_command, (const char *)packet, MAVLINK_MSG_ID_plane_command_MIN_LEN, MAVLINK_MSG_ID_plane_command_LEN, MAVLINK_MSG_ID_plane_command_CRC);
#endif
}
#endif

#endif

// MESSAGE plane_command UNPACKING


/**
 * @brief Get field utc from plane_command message
 *
 * @return  utc
 */
static inline uint64_t mavlink_msg_plane_command_get_utc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field token from plane_command message
 *
 * @return  token
 */
static inline uint32_t mavlink_msg_plane_command_get_token(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field data from plane_command message
 *
 * @return  data
 */
static inline uint16_t mavlink_msg_plane_command_get_data(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field start_id from plane_command message
 *
 * @return  start_id
 */
static inline uint16_t mavlink_msg_plane_command_get_start_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field end_id from plane_command message
 *
 * @return  end_id
 */
static inline uint16_t mavlink_msg_plane_command_get_end_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field cmd from plane_command message
 *
 * @return  cmd
 */
static inline uint8_t mavlink_msg_plane_command_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field ack from plane_command message
 *
 * @return  ack
 */
static inline uint8_t mavlink_msg_plane_command_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field type from plane_command message
 *
 * @return  type
 */
static inline uint8_t mavlink_msg_plane_command_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a plane_command message into a struct
 *
 * @param msg The message to decode
 * @param plane_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_plane_command_decode(const mavlink_message_t* msg, mavlink_plane_command_t* plane_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    plane_command->utc = mavlink_msg_plane_command_get_utc(msg);
    plane_command->token = mavlink_msg_plane_command_get_token(msg);
    plane_command->data = mavlink_msg_plane_command_get_data(msg);
    plane_command->start_id = mavlink_msg_plane_command_get_start_id(msg);
    plane_command->end_id = mavlink_msg_plane_command_get_end_id(msg);
    plane_command->cmd = mavlink_msg_plane_command_get_cmd(msg);
    plane_command->ack = mavlink_msg_plane_command_get_ack(msg);
    plane_command->type = mavlink_msg_plane_command_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_plane_command_LEN? msg->len : MAVLINK_MSG_ID_plane_command_LEN;
        memset(plane_command, 0, MAVLINK_MSG_ID_plane_command_LEN);
    memcpy(plane_command, _MAV_PAYLOAD(msg), len);
#endif
}
