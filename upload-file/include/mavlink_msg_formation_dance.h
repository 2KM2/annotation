#pragma once
// MESSAGE FORMATION_DANCE PACKING

#define MAVLINK_MSG_ID_FORMATION_DANCE 177

#pragma pack(1)
typedef struct __mavlink_formation_dance_t {
 uint32_t dance_id; /*< The formation dance number. E.g: 36.*/
 uint8_t dance_data[250]; /*< Dance data.*/
} mavlink_formation_dance_t;
#pragma pack()

#define MAVLINK_MSG_ID_FORMATION_DANCE_LEN 254
#define MAVLINK_MSG_ID_FORMATION_DANCE_MIN_LEN 254
#define MAVLINK_MSG_ID_177_LEN 254
#define MAVLINK_MSG_ID_177_MIN_LEN 254

#define MAVLINK_MSG_ID_FORMATION_DANCE_CRC 21
#define MAVLINK_MSG_ID_177_CRC 21

#define MAVLINK_MSG_FORMATION_DANCE_FIELD_DANCE_DATA_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_DANCE { \
    177, \
    "FORMATION_DANCE", \
    2, \
    {  { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_dance_t, dance_id) }, \
         { "dance_data", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_formation_dance_t, dance_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_DANCE { \
    "FORMATION_DANCE", \
    2, \
    {  { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_dance_t, dance_id) }, \
         { "dance_data", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_formation_dance_t, dance_data) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_dance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dance_id The formation dance number. E.g: 36.
 * @param dance_data Dance data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_dance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t dance_id, const uint8_t *dance_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t_array(buf, 4, dance_data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_DANCE_LEN);
#else
    mavlink_formation_dance_t packet;
    packet.dance_id = dance_id;
    mav_array_memcpy(packet.dance_data, dance_data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_DANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_DANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
}

/**
 * @brief Pack a formation_dance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dance_id The formation dance number. E.g: 36.
 * @param dance_data Dance data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_dance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t dance_id,const uint8_t *dance_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t_array(buf, 4, dance_data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_DANCE_LEN);
#else
    mavlink_formation_dance_t packet;
    packet.dance_id = dance_id;
    mav_array_memcpy(packet.dance_data, dance_data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_DANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_DANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
}

/**
 * @brief Encode a formation_dance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_dance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_dance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_dance_t* formation_dance)
{
    return mavlink_msg_formation_dance_pack(system_id, component_id, msg, formation_dance->dance_id, formation_dance->dance_data);
}

/**
 * @brief Encode a formation_dance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_dance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_dance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_dance_t* formation_dance)
{
    return mavlink_msg_formation_dance_pack_chan(system_id, component_id, chan, msg, formation_dance->dance_id, formation_dance->dance_data);
}

/**
 * @brief Send a formation_dance message
 * @param chan MAVLink channel to send the message
 *
 * @param dance_id The formation dance number. E.g: 36.
 * @param dance_data Dance data.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_dance_send(mavlink_channel_t chan, uint32_t dance_id, const uint8_t *dance_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_DANCE_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t_array(buf, 4, dance_data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE, buf, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
#else
    mavlink_formation_dance_t packet;
    packet.dance_id = dance_id;
    mav_array_memcpy(packet.dance_data, dance_data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE, (const char *)&packet, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
#endif
}

/**
 * @brief Send a formation_dance message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_dance_send_struct(mavlink_channel_t chan, const mavlink_formation_dance_t* formation_dance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_dance_send(chan, formation_dance->dance_id, formation_dance->dance_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE, (const char *)formation_dance, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_DANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_dance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t dance_id, const uint8_t *dance_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t_array(buf, 4, dance_data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE, buf, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
#else
    mavlink_formation_dance_t *packet = (mavlink_formation_dance_t *)msgbuf;
    packet->dance_id = dance_id;
    mav_array_memcpy(packet->dance_data, dance_data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_DANCE, (const char *)packet, MAVLINK_MSG_ID_FORMATION_DANCE_LEN, MAVLINK_MSG_ID_FORMATION_DANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_DANCE UNPACKING


/**
 * @brief Get field dance_id from formation_dance message
 *
 * @return The formation dance number. E.g: 36.
 */
static inline uint32_t mavlink_msg_formation_dance_get_dance_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field dance_data from formation_dance message
 *
 * @return Dance data.
 */
static inline uint16_t mavlink_msg_formation_dance_get_dance_data(const mavlink_message_t* msg, uint8_t *dance_data)
{
    return _MAV_RETURN_uint8_t_array(msg, dance_data, 250,  4);
}

/**
 * @brief Decode a formation_dance message into a struct
 *
 * @param msg The message to decode
 * @param formation_dance C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_dance_decode(const mavlink_message_t* msg, mavlink_formation_dance_t* formation_dance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    formation_dance->dance_id = mavlink_msg_formation_dance_get_dance_id(msg);
    mavlink_msg_formation_dance_get_dance_data(msg, formation_dance->dance_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_DANCE_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_DANCE_LEN;
        memset(formation_dance, 0, MAVLINK_MSG_ID_FORMATION_DANCE_LEN);
    memcpy(formation_dance, _MAV_PAYLOAD(msg), len);
#endif
}
