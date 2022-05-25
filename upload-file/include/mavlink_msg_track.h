#pragma once
// MESSAGE TRACK PACKING

#define MAVLINK_MSG_ID_TRACK 223


typedef struct __mavlink_track_t {
 float x1; /*<  x1*/
 float y1; /*<  y1*/
 float x2; /*<  x2*/
 float y2; /*<  y2*/
 int8_t enable; /*<  status: 0x01:start 0x02:stop*/
 int8_t status; /*<  status: 0x00:runing 0x01:stoping*/
} mavlink_track_t;

#define MAVLINK_MSG_ID_TRACK_LEN 18
#define MAVLINK_MSG_ID_TRACK_MIN_LEN 18
#define MAVLINK_MSG_ID_223_LEN 18
#define MAVLINK_MSG_ID_223_MIN_LEN 18

#define MAVLINK_MSG_ID_TRACK_CRC 217
#define MAVLINK_MSG_ID_223_CRC 217



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRACK { \
    223, \
    "TRACK", \
    6, \
    {  { "enable", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_track_t, enable) }, \
         { "x1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_track_t, x1) }, \
         { "y1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_track_t, y1) }, \
         { "x2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_track_t, x2) }, \
         { "y2", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_track_t, y2) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 17, offsetof(mavlink_track_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRACK { \
    "TRACK", \
    6, \
    {  { "enable", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_track_t, enable) }, \
         { "x1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_track_t, x1) }, \
         { "y1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_track_t, y1) }, \
         { "x2", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_track_t, x2) }, \
         { "y2", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_track_t, y2) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 17, offsetof(mavlink_track_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param enable  status: 0x01:start 0x02:stop
 * @param x1  x1
 * @param y1  y1
 * @param x2  x2
 * @param y2  y2
 * @param status  status: 0x00:runing 0x01:stoping
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_track_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t enable, float x1, float y1, float x2, float y2, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACK_LEN];
    _mav_put_float(buf, 0, x1);
    _mav_put_float(buf, 4, y1);
    _mav_put_float(buf, 8, x2);
    _mav_put_float(buf, 12, y2);
    _mav_put_int8_t(buf, 16, enable);
    _mav_put_int8_t(buf, 17, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACK_LEN);
#else
    mavlink_track_t packet;
    packet.x1 = x1;
    packet.y1 = y1;
    packet.x2 = x2;
    packet.y2 = y2;
    packet.enable = enable;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
}

/**
 * @brief Pack a track message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param enable  status: 0x01:start 0x02:stop
 * @param x1  x1
 * @param y1  y1
 * @param x2  x2
 * @param y2  y2
 * @param status  status: 0x00:runing 0x01:stoping
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_track_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t enable,float x1,float y1,float x2,float y2,int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACK_LEN];
    _mav_put_float(buf, 0, x1);
    _mav_put_float(buf, 4, y1);
    _mav_put_float(buf, 8, x2);
    _mav_put_float(buf, 12, y2);
    _mav_put_int8_t(buf, 16, enable);
    _mav_put_int8_t(buf, 17, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACK_LEN);
#else
    mavlink_track_t packet;
    packet.x1 = x1;
    packet.y1 = y1;
    packet.x2 = x2;
    packet.y2 = y2;
    packet.enable = enable;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
}

/**
 * @brief Encode a track struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_track_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_track_t* track)
{
    return mavlink_msg_track_pack(system_id, component_id, msg, track->enable, track->x1, track->y1, track->x2, track->y2, track->status);
}

/**
 * @brief Encode a track struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_track_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_track_t* track)
{
    return mavlink_msg_track_pack_chan(system_id, component_id, chan, msg, track->enable, track->x1, track->y1, track->x2, track->y2, track->status);
}

/**
 * @brief Send a track message
 * @param chan MAVLink channel to send the message
 *
 * @param enable  status: 0x01:start 0x02:stop
 * @param x1  x1
 * @param y1  y1
 * @param x2  x2
 * @param y2  y2
 * @param status  status: 0x00:runing 0x01:stoping
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_track_send(mavlink_channel_t chan, int8_t enable, float x1, float y1, float x2, float y2, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACK_LEN];
    _mav_put_float(buf, 0, x1);
    _mav_put_float(buf, 4, y1);
    _mav_put_float(buf, 8, x2);
    _mav_put_float(buf, 12, y2);
    _mav_put_int8_t(buf, 16, enable);
    _mav_put_int8_t(buf, 17, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACK, buf, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
#else
    mavlink_track_t packet;
    packet.x1 = x1;
    packet.y1 = y1;
    packet.x2 = x2;
    packet.y2 = y2;
    packet.enable = enable;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACK, (const char *)&packet, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
#endif
}

/**
 * @brief Send a track message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_track_send_struct(mavlink_channel_t chan, const mavlink_track_t* track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_track_send(chan, track->enable, track->x1, track->y1, track->x2, track->y2, track->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACK, (const char *)track, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_track_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t enable, float x1, float y1, float x2, float y2, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x1);
    _mav_put_float(buf, 4, y1);
    _mav_put_float(buf, 8, x2);
    _mav_put_float(buf, 12, y2);
    _mav_put_int8_t(buf, 16, enable);
    _mav_put_int8_t(buf, 17, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACK, buf, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
#else
    mavlink_track_t *packet = (mavlink_track_t *)msgbuf;
    packet->x1 = x1;
    packet->y1 = y1;
    packet->x2 = x2;
    packet->y2 = y2;
    packet->enable = enable;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACK, (const char *)packet, MAVLINK_MSG_ID_TRACK_MIN_LEN, MAVLINK_MSG_ID_TRACK_LEN, MAVLINK_MSG_ID_TRACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TRACK UNPACKING


/**
 * @brief Get field enable from track message
 *
 * @return  status: 0x01:start 0x02:stop
 */
static inline int8_t mavlink_msg_track_get_enable(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  16);
}

/**
 * @brief Get field x1 from track message
 *
 * @return  x1
 */
static inline float mavlink_msg_track_get_x1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y1 from track message
 *
 * @return  y1
 */
static inline float mavlink_msg_track_get_y1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field x2 from track message
 *
 * @return  x2
 */
static inline float mavlink_msg_track_get_x2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y2 from track message
 *
 * @return  y2
 */
static inline float mavlink_msg_track_get_y2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field status from track message
 *
 * @return  status: 0x00:runing 0x01:stoping
 */
static inline int8_t mavlink_msg_track_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  17);
}

/**
 * @brief Decode a track message into a struct
 *
 * @param msg The message to decode
 * @param track C-struct to decode the message contents into
 */
static inline void mavlink_msg_track_decode(const mavlink_message_t* msg, mavlink_track_t* track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    track->x1 = mavlink_msg_track_get_x1(msg);
    track->y1 = mavlink_msg_track_get_y1(msg);
    track->x2 = mavlink_msg_track_get_x2(msg);
    track->y2 = mavlink_msg_track_get_y2(msg);
    track->enable = mavlink_msg_track_get_enable(msg);
    track->status = mavlink_msg_track_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRACK_LEN? msg->len : MAVLINK_MSG_ID_TRACK_LEN;
        memset(track, 0, MAVLINK_MSG_ID_TRACK_LEN);
    memcpy(track, _MAV_PAYLOAD(msg), len);
#endif
}
