#pragma once
// MESSAGE FORMATION_CMD PACKING

#define MAVLINK_MSG_ID_FORMATION_CMD 208

#pragma pack(1)
typedef struct __mavlink_formation_cmd_t {
 uint64_t utc; /*< Unix Timestamp in milliseconds*/
 uint32_t token; /*< Command token*/
 uint16_t data; /*< Data*/
 uint16_t start_id; /*< Data*/
 uint16_t end_id; /*< Data*/
 uint8_t cmd; /*< Command 1-Takeoff 2-Land 3-Prepare 4-Arm 5-Disarm 6-TimeSync 7-CalMag*/
 uint8_t ack; /*< Ack 0-NoAck 1-Ack*/
 uint8_t type; /*< Broadcast or point to point 0-Broadcast 1-Point to Point*/
} mavlink_formation_cmd_t;
#pragma pack()


#define MAVLINK_MSG_ID_FORMATION_CMD_LEN 21
#define MAVLINK_MSG_ID_FORMATION_CMD_MIN_LEN 21
#define MAVLINK_MSG_ID_208_LEN 21
#define MAVLINK_MSG_ID_208_MIN_LEN 21

#define MAVLINK_MSG_ID_FORMATION_CMD_CRC 85
#define MAVLINK_MSG_ID_208_CRC 85



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_CMD { \
    208, \
    "FORMATION_CMD", \
    8, \
    {  { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_formation_cmd_t, cmd) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_formation_cmd_t, ack) }, \
         { "utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_formation_cmd_t, utc) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_formation_cmd_t, type) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_formation_cmd_t, token) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_formation_cmd_t, data) }, \
         { "start_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_formation_cmd_t, start_id) }, \
         { "end_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_formation_cmd_t, end_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_CMD { \
    "FORMATION_CMD", \
    8, \
    {  { "cmd", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_formation_cmd_t, cmd) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_formation_cmd_t, ack) }, \
         { "utc", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_formation_cmd_t, utc) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_formation_cmd_t, type) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_formation_cmd_t, token) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_formation_cmd_t, data) }, \
         { "start_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_formation_cmd_t, start_id) }, \
         { "end_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_formation_cmd_t, end_id) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd Command 1-Takeoff 2-Land 3-Prepare 4-Arm 5-Disarm 6-TimeSync 7-CalMag
 * @param ack Ack 0-NoAck 1-Ack
 * @param utc Unix Timestamp in milliseconds
 * @param type Broadcast or point to point 0-Broadcast 1-Point to Point
 * @param token Command token
 * @param data Data
 * @param start_id Data
 * @param end_id Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cmd, uint8_t ack, uint64_t utc, uint8_t type, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_CMD_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_CMD_LEN);
#else
    mavlink_formation_cmd_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FORMATION_CMD_LEN,MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
}

/**
 * @brief Pack a formation_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd Command 1-Takeoff 2-Land 3-Prepare 4-Arm 5-Disarm 6-TimeSync 7-CalMag
 * @param ack Ack 0-NoAck 1-Ack
 * @param utc Unix Timestamp in milliseconds
 * @param type Broadcast or point to point 0-Broadcast 1-Point to Point
 * @param token Command token
 * @param data Data
 * @param start_id Data
 * @param end_id Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cmd,uint8_t ack,uint64_t utc,uint8_t type,uint32_t token,uint16_t data,uint16_t start_id,uint16_t end_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_CMD_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_CMD_LEN);
#else
    mavlink_formation_cmd_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FORMATION_CMD_LEN,MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
}

/**
 * @brief Encode a formation_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_cmd_t* formation_cmd)
{
    return mavlink_msg_formation_cmd_pack(system_id, component_id, msg, formation_cmd->cmd, formation_cmd->ack, formation_cmd->utc, formation_cmd->type, formation_cmd->token, formation_cmd->data, formation_cmd->start_id, formation_cmd->end_id);
}

/**
 * @brief Encode a formation_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_cmd_t* formation_cmd)
{
    return mavlink_msg_formation_cmd_pack_chan(system_id, component_id, chan, msg, formation_cmd->cmd, formation_cmd->ack, formation_cmd->utc, formation_cmd->type, formation_cmd->token, formation_cmd->data, formation_cmd->start_id, formation_cmd->end_id);
}

/**
 * @brief Send a formation_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd Command 1-Takeoff 2-Land 3-Prepare 4-Arm 5-Disarm 6-TimeSync 7-CalMag
 * @param ack Ack 0-NoAck 1-Ack
 * @param utc Unix Timestamp in milliseconds
 * @param type Broadcast or point to point 0-Broadcast 1-Point to Point
 * @param token Command token
 * @param data Data
 * @param start_id Data
 * @param end_id Data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_cmd_send(mavlink_channel_t chan, uint8_t cmd, uint8_t ack, uint64_t utc, uint8_t type, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_CMD_LEN];
    _mav_put_uint64_t(buf, 0, utc);
    _mav_put_uint32_t(buf, 8, token);
    _mav_put_uint16_t(buf, 12, data);
    _mav_put_uint16_t(buf, 14, start_id);
    _mav_put_uint16_t(buf, 16, end_id);
    _mav_put_uint8_t(buf, 18, cmd);
    _mav_put_uint8_t(buf, 19, ack);
    _mav_put_uint8_t(buf, 20, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_CMD, buf, MAVLINK_MSG_ID_FORMATION_CMD_LEN,MAVLINK_MSG_ID_FORMATION_CMD_LEN,MAVLINK_MSG_ID_FORMATION_CMD_CRC);
#else
    mavlink_formation_cmd_t packet;
    packet.utc = utc;
    packet.token = token;
    packet.data = data;
    packet.start_id = start_id;
    packet.end_id = end_id;
    packet.cmd = cmd;
    packet.ack = ack;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_CMD, (const char *)&packet, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
#endif
}

/**
 * @brief Send a formation_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_cmd_send_struct(mavlink_channel_t chan, const mavlink_formation_cmd_t* formation_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_cmd_send(chan, formation_cmd->cmd, formation_cmd->ack, formation_cmd->utc, formation_cmd->type, formation_cmd->token, formation_cmd->data, formation_cmd->start_id, formation_cmd->end_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_CMD, (const char *)formation_cmd, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cmd, uint8_t ack, uint64_t utc, uint8_t type, uint32_t token, uint16_t data, uint16_t start_id, uint16_t end_id)
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_CMD, buf, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
#else
    mavlink_formation_cmd_t *packet = (mavlink_formation_cmd_t *)msgbuf;
    packet->utc = utc;
    packet->token = token;
    packet->data = data;
    packet->start_id = start_id;
    packet->end_id = end_id;
    packet->cmd = cmd;
    packet->ack = ack;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_CMD, (const char *)packet, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_LEN, MAVLINK_MSG_ID_FORMATION_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_CMD UNPACKING


/**
 * @brief Get field cmd from formation_cmd message
 *
 * @return Command 1-Takeoff 2-Land 3-Prepare 4-Arm 5-Disarm 6-TimeSync 7-CalMag
 */
static inline uint8_t mavlink_msg_formation_cmd_get_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field ack from formation_cmd message
 *
 * @return Ack 0-NoAck 1-Ack
 */
static inline uint8_t mavlink_msg_formation_cmd_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field utc from formation_cmd message
 *
 * @return Unix Timestamp in milliseconds
 */
static inline uint64_t mavlink_msg_formation_cmd_get_utc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field type from formation_cmd message
 *
 * @return Broadcast or point to point 0-Broadcast 1-Point to Point
 */
static inline uint8_t mavlink_msg_formation_cmd_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field token from formation_cmd message
 *
 * @return Command token
 */
static inline uint32_t mavlink_msg_formation_cmd_get_token(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field data from formation_cmd message
 *
 * @return Data
 */
static inline uint16_t mavlink_msg_formation_cmd_get_data(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field start_id from formation_cmd message
 *
 * @return Data
 */
static inline uint16_t mavlink_msg_formation_cmd_get_start_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field end_id from formation_cmd message
 *
 * @return Data
 */
static inline uint16_t mavlink_msg_formation_cmd_get_end_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Decode a formation_cmd message into a struct
 *
 * @param msg The message to decode
 * @param formation_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_cmd_decode(const mavlink_message_t* msg, mavlink_formation_cmd_t* formation_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    formation_cmd->utc = mavlink_msg_formation_cmd_get_utc(msg);
    formation_cmd->token = mavlink_msg_formation_cmd_get_token(msg);
    formation_cmd->data = mavlink_msg_formation_cmd_get_data(msg);
    formation_cmd->start_id = mavlink_msg_formation_cmd_get_start_id(msg);
    formation_cmd->end_id = mavlink_msg_formation_cmd_get_end_id(msg);
    formation_cmd->cmd = mavlink_msg_formation_cmd_get_cmd(msg);
    formation_cmd->ack = mavlink_msg_formation_cmd_get_ack(msg);
    formation_cmd->type = mavlink_msg_formation_cmd_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_CMD_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_CMD_LEN;
        memset(formation_cmd, 0, MAVLINK_MSG_ID_FORMATION_CMD_LEN);
    memcpy(formation_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
