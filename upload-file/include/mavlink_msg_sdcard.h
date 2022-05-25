#pragma once
// MESSAGE SDCARD PACKING

#define MAVLINK_MSG_ID_SDCARD 222


typedef struct __mavlink_sdcard_t {
 int32_t total; /*<  total capacity*/
 int32_t available; /*<  available capacity*/
 int8_t status; /*<  status: 0x00:okay 0x01:no check sdcard*/
} mavlink_sdcard_t;

#define MAVLINK_MSG_ID_SDCARD_LEN 9
#define MAVLINK_MSG_ID_SDCARD_MIN_LEN 9
#define MAVLINK_MSG_ID_222_LEN 9
#define MAVLINK_MSG_ID_222_MIN_LEN 9

#define MAVLINK_MSG_ID_SDCARD_CRC 206
#define MAVLINK_MSG_ID_222_CRC 206



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SDCARD { \
    222, \
    "SDCARD", \
    3, \
    {  { "total", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sdcard_t, total) }, \
         { "available", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_sdcard_t, available) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 8, offsetof(mavlink_sdcard_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SDCARD { \
    "SDCARD", \
    3, \
    {  { "total", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sdcard_t, total) }, \
         { "available", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_sdcard_t, available) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 8, offsetof(mavlink_sdcard_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a sdcard message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param total  total capacity
 * @param available  available capacity
 * @param status  status: 0x00:okay 0x01:no check sdcard
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sdcard_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t total, int32_t available, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDCARD_LEN];
    _mav_put_int32_t(buf, 0, total);
    _mav_put_int32_t(buf, 4, available);
    _mav_put_int8_t(buf, 8, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SDCARD_LEN);
#else
    mavlink_sdcard_t packet;
    packet.total = total;
    packet.available = available;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SDCARD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SDCARD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
}

/**
 * @brief Pack a sdcard message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param total  total capacity
 * @param available  available capacity
 * @param status  status: 0x00:okay 0x01:no check sdcard
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sdcard_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t total,int32_t available,int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDCARD_LEN];
    _mav_put_int32_t(buf, 0, total);
    _mav_put_int32_t(buf, 4, available);
    _mav_put_int8_t(buf, 8, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SDCARD_LEN);
#else
    mavlink_sdcard_t packet;
    packet.total = total;
    packet.available = available;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SDCARD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SDCARD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
}

/**
 * @brief Encode a sdcard struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sdcard C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sdcard_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sdcard_t* sdcard)
{
    return mavlink_msg_sdcard_pack(system_id, component_id, msg, sdcard->total, sdcard->available, sdcard->status);
}

/**
 * @brief Encode a sdcard struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sdcard C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sdcard_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sdcard_t* sdcard)
{
    return mavlink_msg_sdcard_pack_chan(system_id, component_id, chan, msg, sdcard->total, sdcard->available, sdcard->status);
}

/**
 * @brief Send a sdcard message
 * @param chan MAVLink channel to send the message
 *
 * @param total  total capacity
 * @param available  available capacity
 * @param status  status: 0x00:okay 0x01:no check sdcard
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sdcard_send(mavlink_channel_t chan, int32_t total, int32_t available, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDCARD_LEN];
    _mav_put_int32_t(buf, 0, total);
    _mav_put_int32_t(buf, 4, available);
    _mav_put_int8_t(buf, 8, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDCARD, buf, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
#else
    mavlink_sdcard_t packet;
    packet.total = total;
    packet.available = available;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDCARD, (const char *)&packet, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
#endif
}

/**
 * @brief Send a sdcard message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sdcard_send_struct(mavlink_channel_t chan, const mavlink_sdcard_t* sdcard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sdcard_send(chan, sdcard->total, sdcard->available, sdcard->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDCARD, (const char *)sdcard, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
#endif
}

#if MAVLINK_MSG_ID_SDCARD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sdcard_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t total, int32_t available, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, total);
    _mav_put_int32_t(buf, 4, available);
    _mav_put_int8_t(buf, 8, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDCARD, buf, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
#else
    mavlink_sdcard_t *packet = (mavlink_sdcard_t *)msgbuf;
    packet->total = total;
    packet->available = available;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDCARD, (const char *)packet, MAVLINK_MSG_ID_SDCARD_MIN_LEN, MAVLINK_MSG_ID_SDCARD_LEN, MAVLINK_MSG_ID_SDCARD_CRC);
#endif
}
#endif

#endif

// MESSAGE SDCARD UNPACKING


/**
 * @brief Get field total from sdcard message
 *
 * @return  total capacity
 */
static inline int32_t mavlink_msg_sdcard_get_total(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field available from sdcard message
 *
 * @return  available capacity
 */
static inline int32_t mavlink_msg_sdcard_get_available(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field status from sdcard message
 *
 * @return  status: 0x00:okay 0x01:no check sdcard
 */
static inline int8_t mavlink_msg_sdcard_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  8);
}

/**
 * @brief Decode a sdcard message into a struct
 *
 * @param msg The message to decode
 * @param sdcard C-struct to decode the message contents into
 */
static inline void mavlink_msg_sdcard_decode(const mavlink_message_t* msg, mavlink_sdcard_t* sdcard)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sdcard->total = mavlink_msg_sdcard_get_total(msg);
    sdcard->available = mavlink_msg_sdcard_get_available(msg);
    sdcard->status = mavlink_msg_sdcard_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SDCARD_LEN? msg->len : MAVLINK_MSG_ID_SDCARD_LEN;
        memset(sdcard, 0, MAVLINK_MSG_ID_SDCARD_LEN);
    memcpy(sdcard, _MAV_PAYLOAD(msg), len);
#endif
}
