#pragma once
// MESSAGE COMMAND_LONG2 PACKING

#define MAVLINK_MSG_ID_COMMAND_LONG2 226


typedef struct __mavlink_command_long2_t {
 float param1; /*<  param1*/
 float param2; /*<  param2*/
 float param3; /*<  param3*/
 float param4; /*<  param4*/
 float param5; /*<  param5*/
 float param6; /*<  param6*/
 float param7; /*<  param7*/
 uint16_t command; /*<  command*/
 uint8_t target_system; /*<  target_system*/
 uint8_t target_component; /*<  target_component*/
 uint8_t confirmation; /*<  confirmation*/
} mavlink_command_long2_t;

#define MAVLINK_MSG_ID_COMMAND_LONG2_LEN 33
#define MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN 33
#define MAVLINK_MSG_ID_226_LEN 33
#define MAVLINK_MSG_ID_226_MIN_LEN 33

#define MAVLINK_MSG_ID_COMMAND_LONG2_CRC 219
#define MAVLINK_MSG_ID_226_CRC 219



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG2 { \
    226, \
    "COMMAND_LONG2", \
    11, \
    {  { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long2_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long2_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long2_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long2_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long2_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long2_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long2_t, param7) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long2_t, command) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long2_t, target_component) }, \
         { "confirmation", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_command_long2_t, confirmation) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG2 { \
    "COMMAND_LONG2", \
    11, \
    {  { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long2_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long2_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long2_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long2_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long2_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long2_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long2_t, param7) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long2_t, command) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long2_t, target_component) }, \
         { "confirmation", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_command_long2_t, confirmation) }, \
         } \
}
#endif

/**
 * @brief Pack a command_long2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param param1  param1
 * @param param2  param2
 * @param param3  param3
 * @param param4  param4
 * @param param5  param5
 * @param param6  param6
 * @param param7  param7
 * @param command  command
 * @param target_system  target_system
 * @param target_component  target_component
 * @param confirmation  confirmation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float param1, float param2, float param3, float param4, float param5, float param6, float param7, uint16_t command, uint8_t target_system, uint8_t target_component, uint8_t confirmation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG2_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG2_LEN);
#else
    mavlink_command_long2_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
}

/**
 * @brief Pack a command_long2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param1  param1
 * @param param2  param2
 * @param param3  param3
 * @param param4  param4
 * @param param5  param5
 * @param param6  param6
 * @param param7  param7
 * @param command  command
 * @param target_system  target_system
 * @param target_component  target_component
 * @param confirmation  confirmation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float param1,float param2,float param3,float param4,float param5,float param6,float param7,uint16_t command,uint8_t target_system,uint8_t target_component,uint8_t confirmation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG2_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG2_LEN);
#else
    mavlink_command_long2_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
}

/**
 * @brief Encode a command_long2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_long2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_long2_t* command_long2)
{
    return mavlink_msg_command_long2_pack(system_id, component_id, msg, command_long2->param1, command_long2->param2, command_long2->param3, command_long2->param4, command_long2->param5, command_long2->param6, command_long2->param7, command_long2->command, command_long2->target_system, command_long2->target_component, command_long2->confirmation);
}

/**
 * @brief Encode a command_long2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_long2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_long2_t* command_long2)
{
    return mavlink_msg_command_long2_pack_chan(system_id, component_id, chan, msg, command_long2->param1, command_long2->param2, command_long2->param3, command_long2->param4, command_long2->param5, command_long2->param6, command_long2->param7, command_long2->command, command_long2->target_system, command_long2->target_component, command_long2->confirmation);
}

/**
 * @brief Send a command_long2 message
 * @param chan MAVLink channel to send the message
 *
 * @param param1  param1
 * @param param2  param2
 * @param param3  param3
 * @param param4  param4
 * @param param5  param5
 * @param param6  param6
 * @param param7  param7
 * @param command  command
 * @param target_system  target_system
 * @param target_component  target_component
 * @param confirmation  confirmation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_long2_send(mavlink_channel_t chan, float param1, float param2, float param3, float param4, float param5, float param6, float param7, uint16_t command, uint8_t target_system, uint8_t target_component, uint8_t confirmation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG2_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG2, buf, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
#else
    mavlink_command_long2_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.confirmation = confirmation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG2, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
#endif
}

/**
 * @brief Send a command_long2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_long2_send_struct(mavlink_channel_t chan, const mavlink_command_long2_t* command_long2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_long2_send(chan, command_long2->param1, command_long2->param2, command_long2->param3, command_long2->param4, command_long2->param5, command_long2->param6, command_long2->param7, command_long2->command, command_long2->target_system, command_long2->target_component, command_long2->confirmation);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG2, (const char *)command_long2, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_LONG2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_long2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float param1, float param2, float param3, float param4, float param5, float param6, float param7, uint16_t command, uint8_t target_system, uint8_t target_component, uint8_t confirmation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, target_component);
    _mav_put_uint8_t(buf, 32, confirmation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG2, buf, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
#else
    mavlink_command_long2_t *packet = (mavlink_command_long2_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->param5 = param5;
    packet->param6 = param6;
    packet->param7 = param7;
    packet->command = command;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->confirmation = confirmation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG2, (const char *)packet, MAVLINK_MSG_ID_COMMAND_LONG2_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_LEN, MAVLINK_MSG_ID_COMMAND_LONG2_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND_LONG2 UNPACKING


/**
 * @brief Get field param1 from command_long2 message
 *
 * @return  param1
 */
static inline float mavlink_msg_command_long2_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from command_long2 message
 *
 * @return  param2
 */
static inline float mavlink_msg_command_long2_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from command_long2 message
 *
 * @return  param3
 */
static inline float mavlink_msg_command_long2_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from command_long2 message
 *
 * @return  param4
 */
static inline float mavlink_msg_command_long2_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field param5 from command_long2 message
 *
 * @return  param5
 */
static inline float mavlink_msg_command_long2_get_param5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field param6 from command_long2 message
 *
 * @return  param6
 */
static inline float mavlink_msg_command_long2_get_param6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field param7 from command_long2 message
 *
 * @return  param7
 */
static inline float mavlink_msg_command_long2_get_param7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field command from command_long2 message
 *
 * @return  command
 */
static inline uint16_t mavlink_msg_command_long2_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field target_system from command_long2 message
 *
 * @return  target_system
 */
static inline uint8_t mavlink_msg_command_long2_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field target_component from command_long2 message
 *
 * @return  target_component
 */
static inline uint8_t mavlink_msg_command_long2_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field confirmation from command_long2 message
 *
 * @return  confirmation
 */
static inline uint8_t mavlink_msg_command_long2_get_confirmation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a command_long2 message into a struct
 *
 * @param msg The message to decode
 * @param command_long2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_long2_decode(const mavlink_message_t* msg, mavlink_command_long2_t* command_long2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command_long2->param1 = mavlink_msg_command_long2_get_param1(msg);
    command_long2->param2 = mavlink_msg_command_long2_get_param2(msg);
    command_long2->param3 = mavlink_msg_command_long2_get_param3(msg);
    command_long2->param4 = mavlink_msg_command_long2_get_param4(msg);
    command_long2->param5 = mavlink_msg_command_long2_get_param5(msg);
    command_long2->param6 = mavlink_msg_command_long2_get_param6(msg);
    command_long2->param7 = mavlink_msg_command_long2_get_param7(msg);
    command_long2->command = mavlink_msg_command_long2_get_command(msg);
    command_long2->target_system = mavlink_msg_command_long2_get_target_system(msg);
    command_long2->target_component = mavlink_msg_command_long2_get_target_component(msg);
    command_long2->confirmation = mavlink_msg_command_long2_get_confirmation(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_LONG2_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_LONG2_LEN;
        memset(command_long2, 0, MAVLINK_MSG_ID_COMMAND_LONG2_LEN);
    memcpy(command_long2, _MAV_PAYLOAD(msg), len);
#endif
}
