#pragma once
// MESSAGE TAKEPHOTO PACKING

#define MAVLINK_MSG_ID_TAKEPHOTO 221


typedef struct __mavlink_takephoto_t {
 int8_t run; /*<  start :0x01*/
 int8_t status; /*<  status: 0x00:okay 0x01:no check sd card*/
} mavlink_takephoto_t;

#define MAVLINK_MSG_ID_TAKEPHOTO_LEN 2
#define MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN 2
#define MAVLINK_MSG_ID_221_LEN 2
#define MAVLINK_MSG_ID_221_MIN_LEN 2

#define MAVLINK_MSG_ID_TAKEPHOTO_CRC 57
#define MAVLINK_MSG_ID_221_CRC 57



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TAKEPHOTO { \
    221, \
    "TAKEPHOTO", \
    2, \
    {  { "run", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_takephoto_t, run) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_takephoto_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TAKEPHOTO { \
    "TAKEPHOTO", \
    2, \
    {  { "run", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_takephoto_t, run) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_takephoto_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a takephoto message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param run  start :0x01
 * @param status  status: 0x00:okay 0x01:no check sd card
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_takephoto_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAKEPHOTO_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TAKEPHOTO_LEN);
#else
    mavlink_takephoto_t packet;
    packet.run = run;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TAKEPHOTO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TAKEPHOTO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
}

/**
 * @brief Pack a takephoto message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param run  start :0x01
 * @param status  status: 0x00:okay 0x01:no check sd card
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_takephoto_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t run,int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAKEPHOTO_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TAKEPHOTO_LEN);
#else
    mavlink_takephoto_t packet;
    packet.run = run;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TAKEPHOTO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TAKEPHOTO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
}

/**
 * @brief Encode a takephoto struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param takephoto C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_takephoto_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_takephoto_t* takephoto)
{
    return mavlink_msg_takephoto_pack(system_id, component_id, msg, takephoto->run, takephoto->status);
}

/**
 * @brief Encode a takephoto struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param takephoto C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_takephoto_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_takephoto_t* takephoto)
{
    return mavlink_msg_takephoto_pack_chan(system_id, component_id, chan, msg, takephoto->run, takephoto->status);
}

/**
 * @brief Send a takephoto message
 * @param chan MAVLink channel to send the message
 *
 * @param run  start :0x01
 * @param status  status: 0x00:okay 0x01:no check sd card
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_takephoto_send(mavlink_channel_t chan, int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TAKEPHOTO_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAKEPHOTO, buf, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
#else
    mavlink_takephoto_t packet;
    packet.run = run;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAKEPHOTO, (const char *)&packet, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
#endif
}

/**
 * @brief Send a takephoto message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_takephoto_send_struct(mavlink_channel_t chan, const mavlink_takephoto_t* takephoto)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_takephoto_send(chan, takephoto->run, takephoto->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAKEPHOTO, (const char *)takephoto, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
#endif
}

#if MAVLINK_MSG_ID_TAKEPHOTO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_takephoto_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAKEPHOTO, buf, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
#else
    mavlink_takephoto_t *packet = (mavlink_takephoto_t *)msgbuf;
    packet->run = run;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TAKEPHOTO, (const char *)packet, MAVLINK_MSG_ID_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_TAKEPHOTO_LEN, MAVLINK_MSG_ID_TAKEPHOTO_CRC);
#endif
}
#endif

#endif

// MESSAGE TAKEPHOTO UNPACKING


/**
 * @brief Get field run from takephoto message
 *
 * @return  start :0x01
 */
static inline int8_t mavlink_msg_takephoto_get_run(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field status from takephoto message
 *
 * @return  status: 0x00:okay 0x01:no check sd card
 */
static inline int8_t mavlink_msg_takephoto_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Decode a takephoto message into a struct
 *
 * @param msg The message to decode
 * @param takephoto C-struct to decode the message contents into
 */
static inline void mavlink_msg_takephoto_decode(const mavlink_message_t* msg, mavlink_takephoto_t* takephoto)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    takephoto->run = mavlink_msg_takephoto_get_run(msg);
    takephoto->status = mavlink_msg_takephoto_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TAKEPHOTO_LEN? msg->len : MAVLINK_MSG_ID_TAKEPHOTO_LEN;
        memset(takephoto, 0, MAVLINK_MSG_ID_TAKEPHOTO_LEN);
    memcpy(takephoto, _MAV_PAYLOAD(msg), len);
#endif
}
