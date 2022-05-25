#pragma once
// MESSAGE RECORD PACKING

#define MAVLINK_MSG_ID_RECORD 220


typedef struct __mavlink_record_t {
 int8_t run; /*<  start :0x01, stop :0x02*/
 int8_t status; /*<  status: 0x00:okay 0x01:no check sd card*/
} mavlink_record_t;

#define MAVLINK_MSG_ID_RECORD_LEN 2
#define MAVLINK_MSG_ID_RECORD_MIN_LEN 2
#define MAVLINK_MSG_ID_220_LEN 2
#define MAVLINK_MSG_ID_220_MIN_LEN 2

#define MAVLINK_MSG_ID_RECORD_CRC 166
#define MAVLINK_MSG_ID_220_CRC 166



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RECORD { \
    220, \
    "RECORD", \
    2, \
    {  { "run", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_record_t, run) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_record_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RECORD { \
    "RECORD", \
    2, \
    {  { "run", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_record_t, run) }, \
         { "status", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_record_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a record message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param run  start :0x01, stop :0x02
 * @param status  status: 0x00:okay 0x01:no check sd card
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_record_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RECORD_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RECORD_LEN);
#else
    mavlink_record_t packet;
    packet.run = run;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RECORD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RECORD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
}

/**
 * @brief Pack a record message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param run  start :0x01, stop :0x02
 * @param status  status: 0x00:okay 0x01:no check sd card
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_record_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t run,int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RECORD_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RECORD_LEN);
#else
    mavlink_record_t packet;
    packet.run = run;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RECORD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RECORD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
}

/**
 * @brief Encode a record struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_record_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_record_t* record)
{
    return mavlink_msg_record_pack(system_id, component_id, msg, record->run, record->status);
}

/**
 * @brief Encode a record struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_record_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_record_t* record)
{
    return mavlink_msg_record_pack_chan(system_id, component_id, chan, msg, record->run, record->status);
}

/**
 * @brief Send a record message
 * @param chan MAVLink channel to send the message
 *
 * @param run  start :0x01, stop :0x02
 * @param status  status: 0x00:okay 0x01:no check sd card
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_record_send(mavlink_channel_t chan, int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RECORD_LEN];
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RECORD, buf, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
#else
    mavlink_record_t packet;
    packet.run = run;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RECORD, (const char *)&packet, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
#endif
}

/**
 * @brief Send a record message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_record_send_struct(mavlink_channel_t chan, const mavlink_record_t* record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_record_send(chan, record->run, record->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RECORD, (const char *)record, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
#endif
}

#if MAVLINK_MSG_ID_RECORD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_record_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t run, int8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, run);
    _mav_put_int8_t(buf, 1, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RECORD, buf, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
#else
    mavlink_record_t *packet = (mavlink_record_t *)msgbuf;
    packet->run = run;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RECORD, (const char *)packet, MAVLINK_MSG_ID_RECORD_MIN_LEN, MAVLINK_MSG_ID_RECORD_LEN, MAVLINK_MSG_ID_RECORD_CRC);
#endif
}
#endif

#endif

// MESSAGE RECORD UNPACKING


/**
 * @brief Get field run from record message
 *
 * @return  start :0x01, stop :0x02
 */
static inline int8_t mavlink_msg_record_get_run(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field status from record message
 *
 * @return  status: 0x00:okay 0x01:no check sd card
 */
static inline int8_t mavlink_msg_record_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Decode a record message into a struct
 *
 * @param msg The message to decode
 * @param record C-struct to decode the message contents into
 */
static inline void mavlink_msg_record_decode(const mavlink_message_t* msg, mavlink_record_t* record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    record->run = mavlink_msg_record_get_run(msg);
    record->status = mavlink_msg_record_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RECORD_LEN? msg->len : MAVLINK_MSG_ID_RECORD_LEN;
        memset(record, 0, MAVLINK_MSG_ID_RECORD_LEN);
    memcpy(record, _MAV_PAYLOAD(msg), len);
#endif
}
