#pragma once
// MESSAGE FORMATION_HEADS_INFO PACKING

#define MAVLINK_MSG_ID_FORMATION_HEADS_INFO 174
#pragma pack(1)
typedef struct __mavlink_formation_heads_info_t {
 uint16_t serial_num; /*< The serilal number of Aircraft. E.g: 13.*/
 uint8_t version[8]; /*< The formation version. E.g: V1.1.0.x.*/
 float total_time; /*< Total time required time for flying. E.g: 500*/
 uint16_t frames; /*< Flying points in one second. E.g: 30*/
 uint16_t total_aircraft; /*< The total number of aircraft needed. E.g: 300.*/
 uint16_t total_dance_id; /*< The total number of dance id. E.g: 10000.*/
 uint8_t param_step_num; /*< The param of step num. E.g: 8.*/
 float array[6]; /*< Thr boundary point. E.g: -114.695086 53.390628 -23.742391.*/
 uint8_t md5[16]; /*< The file md5.*/
} mavlink_formation_heads_info_t;
#pragma pack()

#define MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN 61
#define MAVLINK_MSG_ID_FORMATION_HEADS_INFO_MIN_LEN 61
#define MAVLINK_MSG_ID_174_LEN 61
#define MAVLINK_MSG_ID_174_MIN_LEN 61

#define MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC 84
#define MAVLINK_MSG_ID_174_CRC 84

#define MAVLINK_MSG_FORMATION_HEADS_INFO_FIELD_ARRAY_LEN 6
#define MAVLINK_MSG_FORMATION_HEADS_INFO_FIELD_VERSION_LEN 8
#define MAVLINK_MSG_FORMATION_HEADS_INFO_FIELD_MD5_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_HEADS_INFO { \
    174, \
    "FORMATION_HEADS_INFO", \
    9, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_formation_heads_info_t, serial_num) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 8, 36, offsetof(mavlink_formation_heads_info_t, version) }, \
         { "total_time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_formation_heads_info_t, total_time) }, \
         { "frames", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_formation_heads_info_t, frames) }, \
         { "total_aircraft", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_formation_heads_info_t, total_aircraft) }, \
         { "total_dance_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_formation_heads_info_t, total_dance_id) }, \
         { "param_step_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_formation_heads_info_t, param_step_num) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 4, offsetof(mavlink_formation_heads_info_t, array) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 45, offsetof(mavlink_formation_heads_info_t, md5) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_HEADS_INFO { \
    "FORMATION_HEADS_INFO", \
    9, \
    {  { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_formation_heads_info_t, serial_num) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 8, 36, offsetof(mavlink_formation_heads_info_t, version) }, \
         { "total_time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_formation_heads_info_t, total_time) }, \
         { "frames", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_formation_heads_info_t, frames) }, \
         { "total_aircraft", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_formation_heads_info_t, total_aircraft) }, \
         { "total_dance_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_formation_heads_info_t, total_dance_id) }, \
         { "param_step_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_formation_heads_info_t, param_step_num) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 4, offsetof(mavlink_formation_heads_info_t, array) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 45, offsetof(mavlink_formation_heads_info_t, md5) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_heads_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_time Total time required time for flying. E.g: 500
 * @param frames Flying points in one second. E.g: 30
 * @param total_aircraft The total number of aircraft needed. E.g: 300.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param param_step_num The param of step num. E.g: 8.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_heads_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t serial_num, const uint8_t *version, float total_time, uint16_t frames, uint16_t total_aircraft, uint16_t total_dance_id, uint8_t param_step_num, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN];
    _mav_put_float(buf, 0, total_time);
    _mav_put_uint16_t(buf, 28, serial_num);
    _mav_put_uint16_t(buf, 30, frames);
    _mav_put_uint16_t(buf, 32, total_aircraft);
    _mav_put_uint16_t(buf, 34, total_dance_id);
    _mav_put_uint8_t(buf, 44, param_step_num);
    _mav_put_float_array(buf, 4, array, 6);
    _mav_put_uint8_t_array(buf, 36, version, 8);
    _mav_put_uint8_t_array(buf, 45, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN);
#else
    mavlink_formation_heads_info_t packet;
    packet.total_time = total_time;
    packet.serial_num = serial_num;
    packet.frames = frames;
    packet.total_aircraft = total_aircraft;
    packet.total_dance_id = total_dance_id;
    packet.param_step_num = param_step_num;
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_HEADS_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
}

/**
 * @brief Pack a formation_heads_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_time Total time required time for flying. E.g: 500
 * @param frames Flying points in one second. E.g: 30
 * @param total_aircraft The total number of aircraft needed. E.g: 300.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param param_step_num The param of step num. E.g: 8.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_heads_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t serial_num,const uint8_t *version,float total_time,uint16_t frames,uint16_t total_aircraft,uint16_t total_dance_id,uint8_t param_step_num,const float *array,const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN];
    _mav_put_float(buf, 0, total_time);
    _mav_put_uint16_t(buf, 28, serial_num);
    _mav_put_uint16_t(buf, 30, frames);
    _mav_put_uint16_t(buf, 32, total_aircraft);
    _mav_put_uint16_t(buf, 34, total_dance_id);
    _mav_put_uint8_t(buf, 44, param_step_num);
    _mav_put_float_array(buf, 4, array, 6);
    _mav_put_uint8_t_array(buf, 36, version, 8);
    _mav_put_uint8_t_array(buf, 45, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN);
#else
    mavlink_formation_heads_info_t packet;
    packet.total_time = total_time;
    packet.serial_num = serial_num;
    packet.frames = frames;
    packet.total_aircraft = total_aircraft;
    packet.total_dance_id = total_dance_id;
    packet.param_step_num = param_step_num;
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_HEADS_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
}

/**
 * @brief Encode a formation_heads_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_heads_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_heads_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_heads_info_t* formation_heads_info)
{
    return mavlink_msg_formation_heads_info_pack(system_id, component_id, msg, formation_heads_info->serial_num, formation_heads_info->version, formation_heads_info->total_time, formation_heads_info->frames, formation_heads_info->total_aircraft, formation_heads_info->total_dance_id, formation_heads_info->param_step_num, formation_heads_info->array, formation_heads_info->md5);
}

/**
 * @brief Encode a formation_heads_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_heads_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_heads_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_heads_info_t* formation_heads_info)
{
    return mavlink_msg_formation_heads_info_pack_chan(system_id, component_id, chan, msg, formation_heads_info->serial_num, formation_heads_info->version, formation_heads_info->total_time, formation_heads_info->frames, formation_heads_info->total_aircraft, formation_heads_info->total_dance_id, formation_heads_info->param_step_num, formation_heads_info->array, formation_heads_info->md5);
}

/**
 * @brief Send a formation_heads_info message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @param version The formation version. E.g: V1.1.0.x.
 * @param total_time Total time required time for flying. E.g: 500
 * @param frames Flying points in one second. E.g: 30
 * @param total_aircraft The total number of aircraft needed. E.g: 300.
 * @param total_dance_id The total number of dance id. E.g: 10000.
 * @param param_step_num The param of step num. E.g: 8.
 * @param array Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 * @param md5 The file md5.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_heads_info_send(mavlink_channel_t chan, uint16_t serial_num, const uint8_t *version, float total_time, uint16_t frames, uint16_t total_aircraft, uint16_t total_dance_id, uint8_t param_step_num, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN];
    _mav_put_float(buf, 0, total_time);
    _mav_put_uint16_t(buf, 28, serial_num);
    _mav_put_uint16_t(buf, 30, frames);
    _mav_put_uint16_t(buf, 32, total_aircraft);
    _mav_put_uint16_t(buf, 34, total_dance_id);
    _mav_put_uint8_t(buf, 44, param_step_num);
    _mav_put_float_array(buf, 4, array, 6);
    _mav_put_uint8_t_array(buf, 36, version, 8);
    _mav_put_uint8_t_array(buf, 45, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO, buf, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
#else
    mavlink_formation_heads_info_t packet;
    packet.total_time = total_time;
    packet.serial_num = serial_num;
    packet.frames = frames;
    packet.total_aircraft = total_aircraft;
    packet.total_dance_id = total_dance_id;
    packet.param_step_num = param_step_num;
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO, (const char *)&packet, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
#endif
}

/**
 * @brief Send a formation_heads_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_heads_info_send_struct(mavlink_channel_t chan, const mavlink_formation_heads_info_t* formation_heads_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_heads_info_send(chan, formation_heads_info->serial_num, formation_heads_info->version, formation_heads_info->total_time, formation_heads_info->frames, formation_heads_info->total_aircraft, formation_heads_info->total_dance_id, formation_heads_info->param_step_num, formation_heads_info->array, formation_heads_info->md5);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO, (const char *)formation_heads_info, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_heads_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t serial_num, const uint8_t *version, float total_time, uint16_t frames, uint16_t total_aircraft, uint16_t total_dance_id, uint8_t param_step_num, const float *array, const uint8_t *md5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, total_time);
    _mav_put_uint16_t(buf, 28, serial_num);
    _mav_put_uint16_t(buf, 30, frames);
    _mav_put_uint16_t(buf, 32, total_aircraft);
    _mav_put_uint16_t(buf, 34, total_dance_id);
    _mav_put_uint8_t(buf, 44, param_step_num);
    _mav_put_float_array(buf, 4, array, 6);
    _mav_put_uint8_t_array(buf, 36, version, 8);
    _mav_put_uint8_t_array(buf, 45, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO, buf, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
#else
    mavlink_formation_heads_info_t *packet = (mavlink_formation_heads_info_t *)msgbuf;
    packet->total_time = total_time;
    packet->serial_num = serial_num;
    packet->frames = frames;
    packet->total_aircraft = total_aircraft;
    packet->total_dance_id = total_dance_id;
    packet->param_step_num = param_step_num;
    mav_array_memcpy(packet->array, array, sizeof(float)*6);
    mav_array_memcpy(packet->version, version, sizeof(uint8_t)*8);
    mav_array_memcpy(packet->md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_HEADS_INFO, (const char *)packet, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_HEADS_INFO UNPACKING


/**
 * @brief Get field serial_num from formation_heads_info message
 *
 * @return The serilal number of Aircraft. E.g: 13.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_serial_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field version from formation_heads_info message
 *
 * @return The formation version. E.g: V1.1.0.x.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_version(const mavlink_message_t* msg, uint8_t *version)
{
    return _MAV_RETURN_uint8_t_array(msg, version, 8,  36);
}

/**
 * @brief Get field total_time from formation_heads_info message
 *
 * @return Total time required time for flying. E.g: 500
 */
static inline float mavlink_msg_formation_heads_info_get_total_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field frames from formation_heads_info message
 *
 * @return Flying points in one second. E.g: 30
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_frames(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field total_aircraft from formation_heads_info message
 *
 * @return The total number of aircraft needed. E.g: 300.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_total_aircraft(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field total_dance_id from formation_heads_info message
 *
 * @return The total number of dance id. E.g: 10000.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_total_dance_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field param_step_num from formation_heads_info message
 *
 * @return The param of step num. E.g: 8.
 */
static inline uint8_t mavlink_msg_formation_heads_info_get_param_step_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field array from formation_heads_info message
 *
 * @return Thr boundary point. E.g: -114.695086 53.390628 -23.742391.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_array(const mavlink_message_t* msg, float *array)
{
    return _MAV_RETURN_float_array(msg, array, 6,  4);
}

/**
 * @brief Get field md5 from formation_heads_info message
 *
 * @return The file md5.
 */
static inline uint16_t mavlink_msg_formation_heads_info_get_md5(const mavlink_message_t* msg, uint8_t *md5)
{
    return _MAV_RETURN_uint8_t_array(msg, md5, 16,  45);
}

/**
 * @brief Decode a formation_heads_info message into a struct
 *
 * @param msg The message to decode
 * @param formation_heads_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_heads_info_decode(const mavlink_message_t* msg, mavlink_formation_heads_info_t* formation_heads_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    formation_heads_info->total_time = mavlink_msg_formation_heads_info_get_total_time(msg);
    mavlink_msg_formation_heads_info_get_array(msg, formation_heads_info->array);
    formation_heads_info->serial_num = mavlink_msg_formation_heads_info_get_serial_num(msg);
    formation_heads_info->frames = mavlink_msg_formation_heads_info_get_frames(msg);
    formation_heads_info->total_aircraft = mavlink_msg_formation_heads_info_get_total_aircraft(msg);
    formation_heads_info->total_dance_id = mavlink_msg_formation_heads_info_get_total_dance_id(msg);
    mavlink_msg_formation_heads_info_get_version(msg, formation_heads_info->version);
    formation_heads_info->param_step_num = mavlink_msg_formation_heads_info_get_param_step_num(msg);
    mavlink_msg_formation_heads_info_get_md5(msg, formation_heads_info->md5);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN;
        memset(formation_heads_info, 0, MAVLINK_MSG_ID_FORMATION_HEADS_INFO_LEN);
    memcpy(formation_heads_info, _MAV_PAYLOAD(msg), len);
#endif
}
