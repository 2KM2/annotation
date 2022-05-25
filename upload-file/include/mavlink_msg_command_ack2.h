#pragma once
// MESSAGE COMMAND_ACK2 PACKING

#define MAVLINK_MSG_ID_COMMAND_ACK2 225


typedef struct __mavlink_command_ack2_t {
 uint16_t command; /*<  Command ID, as defined by MAV_CMD2 enum.*/
 uint8_t result; /*<  See MAV_RESULT2 enum*/
} mavlink_command_ack2_t;

#define MAVLINK_MSG_ID_COMMAND_ACK2_LEN 3
#define MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN 3
#define MAVLINK_MSG_ID_225_LEN 3
#define MAVLINK_MSG_ID_225_MIN_LEN 3

#define MAVLINK_MSG_ID_COMMAND_ACK2_CRC 250
#define MAVLINK_MSG_ID_225_CRC 250



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK2 { \
    225, \
    "COMMAND_ACK2", \
    2, \
    {  { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_command_ack2_t, command) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_command_ack2_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK2 { \
    "COMMAND_ACK2", \
    2, \
    {  { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_command_ack2_t, command) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_command_ack2_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a command_ack2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command  Command ID, as defined by MAV_CMD2 enum.
 * @param result  See MAV_RESULT2 enum
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t command, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_uint16_t(buf, 0, command);
    _mav_put_uint8_t(buf, 2, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#else
    mavlink_command_ack2_t packet;
    packet.command = command;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
}

/**
 * @brief Pack a command_ack2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command  Command ID, as defined by MAV_CMD2 enum.
 * @param result  See MAV_RESULT2 enum
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t command,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_uint16_t(buf, 0, command);
    _mav_put_uint8_t(buf, 2, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#else
    mavlink_command_ack2_t packet;
    packet.command = command;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
}

/**
 * @brief Encode a command_ack2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_ack2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_ack2_t* command_ack2)
{
    return mavlink_msg_command_ack2_pack(system_id, component_id, msg, command_ack2->command, command_ack2->result);
}

/**
 * @brief Encode a command_ack2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_ack2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_ack2_t* command_ack2)
{
    return mavlink_msg_command_ack2_pack_chan(system_id, component_id, chan, msg, command_ack2->command, command_ack2->result);
}

/**
 * @brief Send a command_ack2 message
 * @param chan MAVLink channel to send the message
 *
 * @param command  Command ID, as defined by MAV_CMD2 enum.
 * @param result  See MAV_RESULT2 enum
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_ack2_send(mavlink_channel_t chan, uint16_t command, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_ACK2_LEN];
    _mav_put_uint16_t(buf, 0, command);
    _mav_put_uint8_t(buf, 2, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, buf, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#else
    mavlink_command_ack2_t packet;
    packet.command = command;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}

/**
 * @brief Send a command_ack2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_ack2_send_struct(mavlink_channel_t chan, const mavlink_command_ack2_t* command_ack2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_ack2_send(chan, command_ack2->command, command_ack2->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)command_ack2, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_ACK2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_ack2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t command, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, command);
    _mav_put_uint8_t(buf, 2, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, buf, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#else
    mavlink_command_ack2_t *packet = (mavlink_command_ack2_t *)msgbuf;
    packet->command = command;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_ACK2, (const char *)packet, MAVLINK_MSG_ID_COMMAND_ACK2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_LEN, MAVLINK_MSG_ID_COMMAND_ACK2_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND_ACK2 UNPACKING


/**
 * @brief Get field command from command_ack2 message
 *
 * @return  Command ID, as defined by MAV_CMD2 enum.
 */
static inline uint16_t mavlink_msg_command_ack2_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field result from command_ack2 message
 *
 * @return  See MAV_RESULT2 enum
 */
static inline uint8_t mavlink_msg_command_ack2_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a command_ack2 message into a struct
 *
 * @param msg The message to decode
 * @param command_ack2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_ack2_decode(const mavlink_message_t* msg, mavlink_command_ack2_t* command_ack2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command_ack2->command = mavlink_msg_command_ack2_get_command(msg);
    command_ack2->result = mavlink_msg_command_ack2_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_ACK2_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_ACK2_LEN;
        memset(command_ack2, 0, MAVLINK_MSG_ID_COMMAND_ACK2_LEN);
    memcpy(command_ack2, _MAV_PAYLOAD(msg), len);
#endif
}
