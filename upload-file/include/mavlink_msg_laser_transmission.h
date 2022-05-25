#pragma once
// MESSAGE laser_transmission PACKING

#define MAVLINK_MSG_ID_laser_transmission 219


typedef struct __mavlink_laser_transmission_t {
 uint16_t hit_all_count; /*<  hit_all_count*/
 uint16_t hit_id_counts[50]; /*<  hit_id_counts*/
 uint8_t hit_id; /*<  hit_id*/
 uint8_t hit_id_values[50]; /*<  hit_id_values*/
} mavlink_laser_transmission_t;

#define MAVLINK_MSG_ID_laser_transmission_LEN 153
#define MAVLINK_MSG_ID_laser_transmission_MIN_LEN 153
#define MAVLINK_MSG_ID_219_LEN 153
#define MAVLINK_MSG_ID_219_MIN_LEN 153

#define MAVLINK_MSG_ID_laser_transmission_CRC 191
#define MAVLINK_MSG_ID_219_CRC 191

#define MAVLINK_MSG_laser_transmission_FIELD_HIT_ID_COUNTS_LEN 50
#define MAVLINK_MSG_laser_transmission_FIELD_HIT_ID_VALUES_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_laser_transmission { \
    219, \
    "laser_transmission", \
    4, \
    {  { "hit_all_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_laser_transmission_t, hit_all_count) }, \
         { "hit_id_counts", NULL, MAVLINK_TYPE_UINT16_T, 50, 2, offsetof(mavlink_laser_transmission_t, hit_id_counts) }, \
         { "hit_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 102, offsetof(mavlink_laser_transmission_t, hit_id) }, \
         { "hit_id_values", NULL, MAVLINK_TYPE_UINT8_T, 50, 103, offsetof(mavlink_laser_transmission_t, hit_id_values) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_laser_transmission { \
    "laser_transmission", \
    4, \
    {  { "hit_all_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_laser_transmission_t, hit_all_count) }, \
         { "hit_id_counts", NULL, MAVLINK_TYPE_UINT16_T, 50, 2, offsetof(mavlink_laser_transmission_t, hit_id_counts) }, \
         { "hit_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 102, offsetof(mavlink_laser_transmission_t, hit_id) }, \
         { "hit_id_values", NULL, MAVLINK_TYPE_UINT8_T, 50, 103, offsetof(mavlink_laser_transmission_t, hit_id_values) }, \
         } \
}
#endif

/**
 * @brief Pack a laser_transmission message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param hit_all_count  hit_all_count
 * @param hit_id_counts  hit_id_counts
 * @param hit_id  hit_id
 * @param hit_id_values  hit_id_values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_laser_transmission_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t hit_all_count, const uint16_t *hit_id_counts, uint8_t hit_id, const uint8_t *hit_id_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_laser_transmission_LEN];
    _mav_put_uint16_t(buf, 0, hit_all_count);
    _mav_put_uint8_t(buf, 102, hit_id);
    _mav_put_uint16_t_array(buf, 2, hit_id_counts, 50);
    _mav_put_uint8_t_array(buf, 103, hit_id_values, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_laser_transmission_LEN);
#else
    mavlink_laser_transmission_t packet;
    packet.hit_all_count = hit_all_count;
    packet.hit_id = hit_id;
    mav_array_memcpy(packet.hit_id_counts, hit_id_counts, sizeof(uint16_t)*50);
    mav_array_memcpy(packet.hit_id_values, hit_id_values, sizeof(uint8_t)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_laser_transmission_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_laser_transmission;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
}

/**
 * @brief Pack a laser_transmission message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hit_all_count  hit_all_count
 * @param hit_id_counts  hit_id_counts
 * @param hit_id  hit_id
 * @param hit_id_values  hit_id_values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_laser_transmission_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t hit_all_count,const uint16_t *hit_id_counts,uint8_t hit_id,const uint8_t *hit_id_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_laser_transmission_LEN];
    _mav_put_uint16_t(buf, 0, hit_all_count);
    _mav_put_uint8_t(buf, 102, hit_id);
    _mav_put_uint16_t_array(buf, 2, hit_id_counts, 50);
    _mav_put_uint8_t_array(buf, 103, hit_id_values, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_laser_transmission_LEN);
#else
    mavlink_laser_transmission_t packet;
    packet.hit_all_count = hit_all_count;
    packet.hit_id = hit_id;
    mav_array_memcpy(packet.hit_id_counts, hit_id_counts, sizeof(uint16_t)*50);
    mav_array_memcpy(packet.hit_id_values, hit_id_values, sizeof(uint8_t)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_laser_transmission_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_laser_transmission;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
}

/**
 * @brief Encode a laser_transmission struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param laser_transmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_laser_transmission_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_laser_transmission_t* laser_transmission)
{
    return mavlink_msg_laser_transmission_pack(system_id, component_id, msg, laser_transmission->hit_all_count, laser_transmission->hit_id_counts, laser_transmission->hit_id, laser_transmission->hit_id_values);
}

/**
 * @brief Encode a laser_transmission struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param laser_transmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_laser_transmission_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_laser_transmission_t* laser_transmission)
{
    return mavlink_msg_laser_transmission_pack_chan(system_id, component_id, chan, msg, laser_transmission->hit_all_count, laser_transmission->hit_id_counts, laser_transmission->hit_id, laser_transmission->hit_id_values);
}

/**
 * @brief Send a laser_transmission message
 * @param chan MAVLink channel to send the message
 *
 * @param hit_all_count  hit_all_count
 * @param hit_id_counts  hit_id_counts
 * @param hit_id  hit_id
 * @param hit_id_values  hit_id_values
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_laser_transmission_send(mavlink_channel_t chan, uint16_t hit_all_count, const uint16_t *hit_id_counts, uint8_t hit_id, const uint8_t *hit_id_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_laser_transmission_LEN];
    _mav_put_uint16_t(buf, 0, hit_all_count);
    _mav_put_uint8_t(buf, 102, hit_id);
    _mav_put_uint16_t_array(buf, 2, hit_id_counts, 50);
    _mav_put_uint8_t_array(buf, 103, hit_id_values, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_laser_transmission, buf, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
#else
    mavlink_laser_transmission_t packet;
    packet.hit_all_count = hit_all_count;
    packet.hit_id = hit_id;
    mav_array_memcpy(packet.hit_id_counts, hit_id_counts, sizeof(uint16_t)*50);
    mav_array_memcpy(packet.hit_id_values, hit_id_values, sizeof(uint8_t)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_laser_transmission, (const char *)&packet, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
#endif
}

/**
 * @brief Send a laser_transmission message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_laser_transmission_send_struct(mavlink_channel_t chan, const mavlink_laser_transmission_t* laser_transmission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_laser_transmission_send(chan, laser_transmission->hit_all_count, laser_transmission->hit_id_counts, laser_transmission->hit_id, laser_transmission->hit_id_values);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_laser_transmission, (const char *)laser_transmission, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
#endif
}

#if MAVLINK_MSG_ID_laser_transmission_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_laser_transmission_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t hit_all_count, const uint16_t *hit_id_counts, uint8_t hit_id, const uint8_t *hit_id_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, hit_all_count);
    _mav_put_uint8_t(buf, 102, hit_id);
    _mav_put_uint16_t_array(buf, 2, hit_id_counts, 50);
    _mav_put_uint8_t_array(buf, 103, hit_id_values, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_laser_transmission, buf, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
#else
    mavlink_laser_transmission_t *packet = (mavlink_laser_transmission_t *)msgbuf;
    packet->hit_all_count = hit_all_count;
    packet->hit_id = hit_id;
    mav_array_memcpy(packet->hit_id_counts, hit_id_counts, sizeof(uint16_t)*50);
    mav_array_memcpy(packet->hit_id_values, hit_id_values, sizeof(uint8_t)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_laser_transmission, (const char *)packet, MAVLINK_MSG_ID_laser_transmission_MIN_LEN, MAVLINK_MSG_ID_laser_transmission_LEN, MAVLINK_MSG_ID_laser_transmission_CRC);
#endif
}
#endif

#endif

// MESSAGE laser_transmission UNPACKING


/**
 * @brief Get field hit_all_count from laser_transmission message
 *
 * @return  hit_all_count
 */
static inline uint16_t mavlink_msg_laser_transmission_get_hit_all_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field hit_id_counts from laser_transmission message
 *
 * @return  hit_id_counts
 */
static inline uint16_t mavlink_msg_laser_transmission_get_hit_id_counts(const mavlink_message_t* msg, uint16_t *hit_id_counts)
{
    return _MAV_RETURN_uint16_t_array(msg, hit_id_counts, 50,  2);
}

/**
 * @brief Get field hit_id from laser_transmission message
 *
 * @return  hit_id
 */
static inline uint8_t mavlink_msg_laser_transmission_get_hit_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  102);
}

/**
 * @brief Get field hit_id_values from laser_transmission message
 *
 * @return  hit_id_values
 */
static inline uint16_t mavlink_msg_laser_transmission_get_hit_id_values(const mavlink_message_t* msg, uint8_t *hit_id_values)
{
    return _MAV_RETURN_uint8_t_array(msg, hit_id_values, 50,  103);
}

/**
 * @brief Decode a laser_transmission message into a struct
 *
 * @param msg The message to decode
 * @param laser_transmission C-struct to decode the message contents into
 */
static inline void mavlink_msg_laser_transmission_decode(const mavlink_message_t* msg, mavlink_laser_transmission_t* laser_transmission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    laser_transmission->hit_all_count = mavlink_msg_laser_transmission_get_hit_all_count(msg);
    mavlink_msg_laser_transmission_get_hit_id_counts(msg, laser_transmission->hit_id_counts);
    laser_transmission->hit_id = mavlink_msg_laser_transmission_get_hit_id(msg);
    mavlink_msg_laser_transmission_get_hit_id_values(msg, laser_transmission->hit_id_values);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_laser_transmission_LEN? msg->len : MAVLINK_MSG_ID_laser_transmission_LEN;
        memset(laser_transmission, 0, MAVLINK_MSG_ID_laser_transmission_LEN);
    memcpy(laser_transmission, _MAV_PAYLOAD(msg), len);
#endif
}
