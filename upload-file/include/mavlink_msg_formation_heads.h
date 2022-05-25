#pragma once
// MESSAGE FORMATION_HEADS PACKING

#define MAVLINK_MSG_ID_FORMATION_HEADS 176

#pragma pack(1)
typedef struct __mavlink_formation_heads_t {
 float info[4]; /*< The formation info.*/
 float array[6]; /*< Thr boundary point. E.g: -114.695086 53.390628 -23.742391.*/
 uint16_t serial_num; /*< The serilal number of Aircraft. E.g: 13.*/
 uint16_t total_dance_id; /*< The total number of dance id. E.g: 10000.*/
 uint8_t version[3]; /*< The formation version. E.g: V1.1.0.x.*/
 uint8_t md5[16]; /*< The file md5.*/
} mavlink_formation_heads_t;
#pragma pack()

#define MAVLINK_MSG_ID_FORMATION_HEADS_LEN 63
#define MAVLINK_MSG_ID_FORMATION_HEADS_MIN_LEN 63
#define MAVLINK_MSG_ID_176_LEN 63
#define MAVLINK_MSG_ID_176_MIN_LEN 63

#define MAVLINK_MSG_ID_FORMATION_HEADS_CRC 52
#define MAVLINK_MSG_ID_176_CRC 52

#define MAVLINK_MSG_FORMATION_HEADS_FIELD_INFO_LEN 4
#define MAVLINK_MSG_FORMATION_HEADS_FIELD_ARRAY_LEN 6
#define MAVLINK_MSG_FORMATION_HEADS_FIELD_VERSION_LEN 3
#define MAVLINK_MSG_FORMATION_HEADS_FIELD_MD5_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_HEADS { \
    176, \
    "FORMATION_HEADS", \
    6, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_formation_heads_t, serial_num) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 3, 44, offsetof(mavlink_formation_heads_t, version) }, \
         { "total_dance_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_formation_heads_t, total_dance_id) }, \
         { "info", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_formation_heads_t, info) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 16, offsetof(mavlink_formation_heads_t, array) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 47, offsetof(mavlink_formation_heads_t, md5) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_HEADS { \
    "FORMATION_HEADS", \
    6, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_formation_heads_t, serial_num) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 3, 44, offsetof(mavlink_formation_heads_t, version) }, \
         { "total_dance_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_formation_heads_t, total_dance_id) }, \
         { "info", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_formation_heads_t, info) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 16, offsetof(mavlink_formation_heads_t, array) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 47, offsetof(mavlink_formation_heads_t, md5) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_heads message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param info The formation info.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_heads_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t serial_num, const uint8_t *version, uint16_t total_dance_id, const float *info, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_LEN];
    _mav_put_uint16_t(buf, 40, serial_num);
    _mav_put_uint16_t(buf, 42, total_dance_id);
    _mav_put_float_array(buf, 0, info, 4);
    _mav_put_float_array(buf, 16, array, 6);
    _mav_put_uint8_t_array(buf, 44, version, 3);
    _mav_put_uint8_t_array(buf, 47, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_HEADS_LEN);
#else
    mavlink_formation_heads_t packet;
    packet.serial_num = serial_num;
    packet.total_dance_id = total_dance_id;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_HEADS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
}

/**
 * @brief Pack a formation_heads message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param info The formation info.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_heads_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t serial_num,const uint8_t *version,uint16_t total_dance_id,const float *info,const float *array,const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_LEN];
    _mav_put_uint16_t(buf, 40, serial_num);
    _mav_put_uint16_t(buf, 42, total_dance_id);
    _mav_put_float_array(buf, 0, info, 4);
    _mav_put_float_array(buf, 16, array, 6);
    _mav_put_uint8_t_array(buf, 44, version, 3);
    _mav_put_uint8_t_array(buf, 47, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_HEADS_LEN);
#else
    mavlink_formation_heads_t packet;
    packet.serial_num = serial_num;
    packet.total_dance_id = total_dance_id;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_HEADS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
}

/**
 * @brief Encode a formation_heads struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_heads_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_heads_t* formation_heads)
{
    return mavlink_msg_formation_heads_pack(system_id, component_id, msg, formation_heads->serial_num, formation_heads->version, formation_heads->total_dance_id, formation_heads->info, formation_heads->array, formation_heads->md5);
}

/**
 * @brief Encode a formation_heads struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_heads_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_heads_t* formation_heads)
{
    return mavlink_msg_formation_heads_pack_chan(system_id, component_id, chan, msg, formation_heads->serial_num, formation_heads->version, formation_heads->total_dance_id, formation_heads->info, formation_heads->array, formation_heads->md5);
}

/**
 * @brief Send a formation_heads message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param info The formation info.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_heads_send(mavlink_channel_t chan, uint16_t serial_num, const uint8_t *version, uint16_t total_dance_id, const float *info, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_LEN];
    _mav_put_uint16_t(buf, 40, serial_num);
    _mav_put_uint16_t(buf, 42, total_dance_id);
    _mav_put_float_array(buf, 0, info, 4);
    _mav_put_float_array(buf, 16, array, 6);
    _mav_put_uint8_t_array(buf, 44, version, 3);
    _mav_put_uint8_t_array(buf, 47, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS, buf, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
#else
    mavlink_formation_heads_t packet;
    packet.serial_num = serial_num;
    packet.total_dance_id = total_dance_id;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS, (const char *)&packet, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
#endif
}

/**
 * @brief Send a formation_heads message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_heads_send_struct(mavlink_channel_t chan, const mavlink_formation_heads_t* formation_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_heads_send(chan, formation_heads->serial_num, formation_heads->version, formation_heads->total_dance_id, formation_heads->info, formation_heads->array, formation_heads->md5);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS, (const char *)formation_heads, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_HEADS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_heads_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t serial_num, const uint8_t *version, uint16_t total_dance_id, const float *info, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 40, serial_num);
    _mav_put_uint16_t(buf, 42, total_dance_id);
    _mav_put_float_array(buf, 0, info, 4);
    _mav_put_float_array(buf, 16, array, 6);
    _mav_put_uint8_t_array(buf, 44, version, 3);
    _mav_put_uint8_t_array(buf, 47, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS, buf, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
#else
    mavlink_formation_heads_t *packet = (mavlink_formation_heads_t *)msgbuf;
    packet->serial_num = serial_num;
    packet->total_dance_id = total_dance_id;
    mav_array_memcpy(packet->info, info, sizeof(float)*4);
    mav_array_memcpy(packet->array, array, sizeof(float)*6);
    mav_array_memcpy(packet->version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet->md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS, (const char *)packet, MAVLINK_MSG_ID_FORMATION_HEADS_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_HEADS UNPACKING


/**
 * @brief Get field serial_num from formation_heads message
 *
 * @return The serilal number of Aircraft. E.g: 13.
 */
static inline uint16_t mavlink_msg_formation_heads_get_serial_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field version from formation_heads message
 *
 * @return The formation version. E.g: V1.1.0.x.
 */
static inline uint16_t mavlink_msg_formation_heads_get_version(const mavlink_message_t* msg, uint8_t *version)
{
    return _MAV_RETURN_uint8_t_array(msg, version, 3,  44);
}

/**
 * @brief Get field total_dance_id from formation_heads message
 *
 * @return The total number of dance id. E.g: 10000.
 */
static inline uint16_t mavlink_msg_formation_heads_get_total_dance_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field info from formation_heads message
 *
 * @return The formation info.
 */
static inline uint16_t mavlink_msg_formation_heads_get_info(const mavlink_message_t* msg, float *info)
{
    return _MAV_RETURN_float_array(msg, info, 4,  0);
}

/**
 * @brief Get field array from formation_heads message
 *
 * @return Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 */
static inline uint16_t mavlink_msg_formation_heads_get_array(const mavlink_message_t* msg, float *array)
{
    return _MAV_RETURN_float_array(msg, array, 6,  16);
}

/**
 * @brief Get field md5 from formation_heads message
 *
 * @return The file md5.
 */
static inline uint16_t mavlink_msg_formation_heads_get_md5(const mavlink_message_t* msg, uint8_t *md5)
{
    return _MAV_RETURN_uint8_t_array(msg, md5, 16,  47);
}

/**
 * @brief Decode a formation_heads message into a struct
 *
 * @param msg The message to decode
 * @param formation_heads C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_heads_decode(const mavlink_message_t* msg, mavlink_formation_heads_t* formation_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_heads_get_info(msg, formation_heads->info);
    mavlink_msg_formation_heads_get_array(msg, formation_heads->array);
    formation_heads->serial_num = mavlink_msg_formation_heads_get_serial_num(msg);
    formation_heads->total_dance_id = mavlink_msg_formation_heads_get_total_dance_id(msg);
    mavlink_msg_formation_heads_get_version(msg, formation_heads->version);
    mavlink_msg_formation_heads_get_md5(msg, formation_heads->md5);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_HEADS_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_HEADS_LEN;
        memset(formation_heads, 0, MAVLINK_MSG_ID_FORMATION_HEADS_LEN);
    memcpy(formation_heads, _MAV_PAYLOAD(msg), len);
#endif
}
