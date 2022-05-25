#pragma once
// MESSAGE INSPECTION PACKING

#define MAVLINK_MSG_ID_INSPECTION 224


typedef struct __mavlink_inspection_t {
 int16_t year; /*<  year*/
 int8_t month; /*<  month*/
 int8_t day; /*<  day*/
 int8_t hour; /*<  hour*/
 int8_t minute; /*<  minute*/
 int8_t second; /*<  second*/
 int8_t inspection; /*<  inspection*/
} mavlink_inspection_t;

#define MAVLINK_MSG_ID_INSPECTION_LEN 8
#define MAVLINK_MSG_ID_INSPECTION_MIN_LEN 8
#define MAVLINK_MSG_ID_224_LEN 8
#define MAVLINK_MSG_ID_224_MIN_LEN 8

#define MAVLINK_MSG_ID_INSPECTION_CRC 128
#define MAVLINK_MSG_ID_224_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_INSPECTION { \
    224, \
    "INSPECTION", \
    7, \
    {  { "year", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_inspection_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_inspection_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_inspection_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_inspection_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_INT8_T, 0, 5, offsetof(mavlink_inspection_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_INT8_T, 0, 6, offsetof(mavlink_inspection_t, second) }, \
         { "inspection", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_inspection_t, inspection) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_INSPECTION { \
    "INSPECTION", \
    7, \
    {  { "year", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_inspection_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_inspection_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_inspection_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_INT8_T, 0, 4, offsetof(mavlink_inspection_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_INT8_T, 0, 5, offsetof(mavlink_inspection_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_INT8_T, 0, 6, offsetof(mavlink_inspection_t, second) }, \
         { "inspection", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_inspection_t, inspection) }, \
         } \
}
#endif

/**
 * @brief Pack a inspection message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param minute  minute
 * @param second  second
 * @param inspection  inspection
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_inspection_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t year, int8_t month, int8_t day, int8_t hour, int8_t minute, int8_t second, int8_t inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSPECTION_LEN];
    _mav_put_int16_t(buf, 0, year);
    _mav_put_int8_t(buf, 2, month);
    _mav_put_int8_t(buf, 3, day);
    _mav_put_int8_t(buf, 4, hour);
    _mav_put_int8_t(buf, 5, minute);
    _mav_put_int8_t(buf, 6, second);
    _mav_put_int8_t(buf, 7, inspection);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INSPECTION_LEN);
#else
    mavlink_inspection_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;
    packet.inspection = inspection;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INSPECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INSPECTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
}

/**
 * @brief Pack a inspection message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param minute  minute
 * @param second  second
 * @param inspection  inspection
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_inspection_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t year,int8_t month,int8_t day,int8_t hour,int8_t minute,int8_t second,int8_t inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSPECTION_LEN];
    _mav_put_int16_t(buf, 0, year);
    _mav_put_int8_t(buf, 2, month);
    _mav_put_int8_t(buf, 3, day);
    _mav_put_int8_t(buf, 4, hour);
    _mav_put_int8_t(buf, 5, minute);
    _mav_put_int8_t(buf, 6, second);
    _mav_put_int8_t(buf, 7, inspection);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INSPECTION_LEN);
#else
    mavlink_inspection_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;
    packet.inspection = inspection;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INSPECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INSPECTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
}

/**
 * @brief Encode a inspection struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param inspection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_inspection_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_inspection_t* inspection)
{
    return mavlink_msg_inspection_pack(system_id, component_id, msg, inspection->year, inspection->month, inspection->day, inspection->hour, inspection->minute, inspection->second, inspection->inspection);
}

/**
 * @brief Encode a inspection struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param inspection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_inspection_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_inspection_t* inspection)
{
    return mavlink_msg_inspection_pack_chan(system_id, component_id, chan, msg, inspection->year, inspection->month, inspection->day, inspection->hour, inspection->minute, inspection->second, inspection->inspection);
}

/**
 * @brief Send a inspection message
 * @param chan MAVLink channel to send the message
 *
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param minute  minute
 * @param second  second
 * @param inspection  inspection
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_inspection_send(mavlink_channel_t chan, int16_t year, int8_t month, int8_t day, int8_t hour, int8_t minute, int8_t second, int8_t inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSPECTION_LEN];
    _mav_put_int16_t(buf, 0, year);
    _mav_put_int8_t(buf, 2, month);
    _mav_put_int8_t(buf, 3, day);
    _mav_put_int8_t(buf, 4, hour);
    _mav_put_int8_t(buf, 5, minute);
    _mav_put_int8_t(buf, 6, second);
    _mav_put_int8_t(buf, 7, inspection);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSPECTION, buf, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
#else
    mavlink_inspection_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;
    packet.inspection = inspection;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSPECTION, (const char *)&packet, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
#endif
}

/**
 * @brief Send a inspection message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_inspection_send_struct(mavlink_channel_t chan, const mavlink_inspection_t* inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_inspection_send(chan, inspection->year, inspection->month, inspection->day, inspection->hour, inspection->minute, inspection->second, inspection->inspection);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSPECTION, (const char *)inspection, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_INSPECTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_inspection_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t year, int8_t month, int8_t day, int8_t hour, int8_t minute, int8_t second, int8_t inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, year);
    _mav_put_int8_t(buf, 2, month);
    _mav_put_int8_t(buf, 3, day);
    _mav_put_int8_t(buf, 4, hour);
    _mav_put_int8_t(buf, 5, minute);
    _mav_put_int8_t(buf, 6, second);
    _mav_put_int8_t(buf, 7, inspection);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSPECTION, buf, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
#else
    mavlink_inspection_t *packet = (mavlink_inspection_t *)msgbuf;
    packet->year = year;
    packet->month = month;
    packet->day = day;
    packet->hour = hour;
    packet->minute = minute;
    packet->second = second;
    packet->inspection = inspection;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSPECTION, (const char *)packet, MAVLINK_MSG_ID_INSPECTION_MIN_LEN, MAVLINK_MSG_ID_INSPECTION_LEN, MAVLINK_MSG_ID_INSPECTION_CRC);
#endif
}
#endif

#endif

// MESSAGE INSPECTION UNPACKING


/**
 * @brief Get field year from inspection message
 *
 * @return  year
 */
static inline int16_t mavlink_msg_inspection_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field month from inspection message
 *
 * @return  month
 */
static inline int8_t mavlink_msg_inspection_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field day from inspection message
 *
 * @return  day
 */
static inline int8_t mavlink_msg_inspection_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Get field hour from inspection message
 *
 * @return  hour
 */
static inline int8_t mavlink_msg_inspection_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  4);
}

/**
 * @brief Get field minute from inspection message
 *
 * @return  minute
 */
static inline int8_t mavlink_msg_inspection_get_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  5);
}

/**
 * @brief Get field second from inspection message
 *
 * @return  second
 */
static inline int8_t mavlink_msg_inspection_get_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  6);
}

/**
 * @brief Get field inspection from inspection message
 *
 * @return  inspection
 */
static inline int8_t mavlink_msg_inspection_get_inspection(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  7);
}

/**
 * @brief Decode a inspection message into a struct
 *
 * @param msg The message to decode
 * @param inspection C-struct to decode the message contents into
 */
static inline void mavlink_msg_inspection_decode(const mavlink_message_t* msg, mavlink_inspection_t* inspection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    inspection->year = mavlink_msg_inspection_get_year(msg);
    inspection->month = mavlink_msg_inspection_get_month(msg);
    inspection->day = mavlink_msg_inspection_get_day(msg);
    inspection->hour = mavlink_msg_inspection_get_hour(msg);
    inspection->minute = mavlink_msg_inspection_get_minute(msg);
    inspection->second = mavlink_msg_inspection_get_second(msg);
    inspection->inspection = mavlink_msg_inspection_get_inspection(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_INSPECTION_LEN? msg->len : MAVLINK_MSG_ID_INSPECTION_LEN;
        memset(inspection, 0, MAVLINK_MSG_ID_INSPECTION_LEN);
    memcpy(inspection, _MAV_PAYLOAD(msg), len);
#endif
}
