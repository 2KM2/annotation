#pragma once
// MESSAGE FILE_HEADS PACKING

#define MAVLINK_MSG_ID_FILE_HEADS 211


typedef struct __mavlink_file_heads_t {
 uint32_t file_size; /*<  file_size*/
 float info[4]; /*<  info*/
 float array[6]; /*<  array*/
 uint16_t plane_id; /*<  plane_id*/
 uint8_t file_type; /*<  file_type*/
 uint8_t version[3]; /*<  version*/
 uint8_t md5[16]; /*<  md5*/
 char file_name[50]; /*<  file_name*/
} mavlink_file_heads_t;

#define MAVLINK_MSG_ID_FILE_HEADS_LEN 116
#define MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN 116
#define MAVLINK_MSG_ID_211_LEN 116
#define MAVLINK_MSG_ID_211_MIN_LEN 116

#define MAVLINK_MSG_ID_FILE_HEADS_CRC 58
#define MAVLINK_MSG_ID_211_CRC 58

#define MAVLINK_MSG_FILE_HEADS_FIELD_INFO_LEN 4
#define MAVLINK_MSG_FILE_HEADS_FIELD_ARRAY_LEN 6
#define MAVLINK_MSG_FILE_HEADS_FIELD_VERSION_LEN 3
#define MAVLINK_MSG_FILE_HEADS_FIELD_MD5_LEN 16
#define MAVLINK_MSG_FILE_HEADS_FIELD_FILE_NAME_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FILE_HEADS { \
    211, \
    "FILE_HEADS", \
    8, \
    {  { "file_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_file_heads_t, file_type) }, \
         { "file_size", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_heads_t, file_size) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_file_heads_t, plane_id) }, \
         { "info", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_file_heads_t, info) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 20, offsetof(mavlink_file_heads_t, array) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 3, 47, offsetof(mavlink_file_heads_t, version) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 50, offsetof(mavlink_file_heads_t, md5) }, \
         { "file_name", NULL, MAVLINK_TYPE_CHAR, 50, 66, offsetof(mavlink_file_heads_t, file_name) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FILE_HEADS { \
    "FILE_HEADS", \
    8, \
    {  { "file_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_file_heads_t, file_type) }, \
         { "file_size", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_heads_t, file_size) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_file_heads_t, plane_id) }, \
         { "info", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_file_heads_t, info) }, \
         { "array", NULL, MAVLINK_TYPE_FLOAT, 6, 20, offsetof(mavlink_file_heads_t, array) }, \
         { "version", NULL, MAVLINK_TYPE_UINT8_T, 3, 47, offsetof(mavlink_file_heads_t, version) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 50, offsetof(mavlink_file_heads_t, md5) }, \
         { "file_name", NULL, MAVLINK_TYPE_CHAR, 50, 66, offsetof(mavlink_file_heads_t, file_name) }, \
         } \
}
#endif

/**
 * @brief Pack a file_heads message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param file_type  file_type
 * @param file_size  file_size
 * @param plane_id  plane_id
 * @param info  info
 * @param array  array
 * @param version  version
 * @param md5  md5
 * @param file_name  file_name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_heads_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t file_type, uint32_t file_size, uint16_t plane_id, const float *info, const float *array, const uint8_t *version, const uint8_t *md5, const char *file_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FILE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, file_size);
    _mav_put_uint16_t(buf, 44, plane_id);
    _mav_put_uint8_t(buf, 46, file_type);
    _mav_put_float_array(buf, 4, info, 4);
    _mav_put_float_array(buf, 20, array, 6);
    _mav_put_uint8_t_array(buf, 47, version, 3);
    _mav_put_uint8_t_array(buf, 50, md5, 16);
    _mav_put_char_array(buf, 66, file_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FILE_HEADS_LEN);
#else
    mavlink_file_heads_t packet;
    packet.file_size = file_size;
    packet.plane_id = plane_id;
    packet.file_type = file_type;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.file_name, file_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FILE_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FILE_HEADS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
}

/**
 * @brief Pack a file_heads message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param file_type  file_type
 * @param file_size  file_size
 * @param plane_id  plane_id
 * @param info  info
 * @param array  array
 * @param version  version
 * @param md5  md5
 * @param file_name  file_name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_heads_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t file_type,uint32_t file_size,uint16_t plane_id,const float *info,const float *array,const uint8_t *version,const uint8_t *md5,const char *file_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FILE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, file_size);
    _mav_put_uint16_t(buf, 44, plane_id);
    _mav_put_uint8_t(buf, 46, file_type);
    _mav_put_float_array(buf, 4, info, 4);
    _mav_put_float_array(buf, 20, array, 6);
    _mav_put_uint8_t_array(buf, 47, version, 3);
    _mav_put_uint8_t_array(buf, 50, md5, 16);
    _mav_put_char_array(buf, 66, file_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FILE_HEADS_LEN);
#else
    mavlink_file_heads_t packet;
    packet.file_size = file_size;
    packet.plane_id = plane_id;
    packet.file_type = file_type;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.file_name, file_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FILE_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FILE_HEADS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
}

/**
 * @brief Encode a file_heads struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param file_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_heads_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_file_heads_t* file_heads)
{
    return mavlink_msg_file_heads_pack(system_id, component_id, msg, file_heads->file_type, file_heads->file_size, file_heads->plane_id, file_heads->info, file_heads->array, file_heads->version, file_heads->md5, file_heads->file_name);
}

/**
 * @brief Encode a file_heads struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param file_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_heads_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_file_heads_t* file_heads)
{
    return mavlink_msg_file_heads_pack_chan(system_id, component_id, chan, msg, file_heads->file_type, file_heads->file_size, file_heads->plane_id, file_heads->info, file_heads->array, file_heads->version, file_heads->md5, file_heads->file_name);
}

/**
 * @brief Send a file_heads message
 * @param chan MAVLink channel to send the message
 *
 * @param file_type  file_type
 * @param file_size  file_size
 * @param plane_id  plane_id
 * @param info  info
 * @param array  array
 * @param version  version
 * @param md5  md5
 * @param file_name  file_name
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_file_heads_send(mavlink_channel_t chan, uint8_t file_type, uint32_t file_size, uint16_t plane_id, const float *info, const float *array, const uint8_t *version, const uint8_t *md5, const char *file_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FILE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, file_size);
    _mav_put_uint16_t(buf, 44, plane_id);
    _mav_put_uint8_t(buf, 46, file_type);
    _mav_put_float_array(buf, 4, info, 4);
    _mav_put_float_array(buf, 20, array, 6);
    _mav_put_uint8_t_array(buf, 47, version, 3);
    _mav_put_uint8_t_array(buf, 50, md5, 16);
    _mav_put_char_array(buf, 66, file_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FILE_HEADS, buf, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
#else
    mavlink_file_heads_t packet;
    packet.file_size = file_size;
    packet.plane_id = plane_id;
    packet.file_type = file_type;
    mav_array_memcpy(packet.info, info, sizeof(float)*4);
    mav_array_memcpy(packet.array, array, sizeof(float)*6);
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.file_name, file_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FILE_HEADS, (const char *)&packet, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
#endif
}

/**
 * @brief Send a file_heads message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_file_heads_send_struct(mavlink_channel_t chan, const mavlink_file_heads_t* file_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_file_heads_send(chan, file_heads->file_type, file_heads->file_size, file_heads->plane_id, file_heads->info, file_heads->array, file_heads->version, file_heads->md5, file_heads->file_name);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FILE_HEADS, (const char *)file_heads, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
#endif
}

#if MAVLINK_MSG_ID_FILE_HEADS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_file_heads_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t file_type, uint32_t file_size, uint16_t plane_id, const float *info, const float *array, const uint8_t *version, const uint8_t *md5, const char *file_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, file_size);
    _mav_put_uint16_t(buf, 44, plane_id);
    _mav_put_uint8_t(buf, 46, file_type);
    _mav_put_float_array(buf, 4, info, 4);
    _mav_put_float_array(buf, 20, array, 6);
    _mav_put_uint8_t_array(buf, 47, version, 3);
    _mav_put_uint8_t_array(buf, 50, md5, 16);
    _mav_put_char_array(buf, 66, file_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FILE_HEADS, buf, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
#else
    mavlink_file_heads_t *packet = (mavlink_file_heads_t *)msgbuf;
    packet->file_size = file_size;
    packet->plane_id = plane_id;
    packet->file_type = file_type;
    mav_array_memcpy(packet->info, info, sizeof(float)*4);
    mav_array_memcpy(packet->array, array, sizeof(float)*6);
    mav_array_memcpy(packet->version, version, sizeof(uint8_t)*3);
    mav_array_memcpy(packet->md5, md5, sizeof(uint8_t)*16);
    mav_array_memcpy(packet->file_name, file_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FILE_HEADS, (const char *)packet, MAVLINK_MSG_ID_FILE_HEADS_MIN_LEN, MAVLINK_MSG_ID_FILE_HEADS_LEN, MAVLINK_MSG_ID_FILE_HEADS_CRC);
#endif
}
#endif

#endif

// MESSAGE FILE_HEADS UNPACKING


/**
 * @brief Get field file_type from file_heads message
 *
 * @return  file_type
 */
static inline uint8_t mavlink_msg_file_heads_get_file_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  46);
}

/**
 * @brief Get field file_size from file_heads message
 *
 * @return  file_size
 */
static inline uint32_t mavlink_msg_file_heads_get_file_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field plane_id from file_heads message
 *
 * @return  plane_id
 */
static inline uint16_t mavlink_msg_file_heads_get_plane_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  44);
}

/**
 * @brief Get field info from file_heads message
 *
 * @return  info
 */
static inline uint16_t mavlink_msg_file_heads_get_info(const mavlink_message_t* msg, float *info)
{
    return _MAV_RETURN_float_array(msg, info, 4,  4);
}

/**
 * @brief Get field array from file_heads message
 *
 * @return  array
 */
static inline uint16_t mavlink_msg_file_heads_get_array(const mavlink_message_t* msg, float *array)
{
    return _MAV_RETURN_float_array(msg, array, 6,  20);
}

/**
 * @brief Get field version from file_heads message
 *
 * @return  version
 */
static inline uint16_t mavlink_msg_file_heads_get_version(const mavlink_message_t* msg, uint8_t *version)
{
    return _MAV_RETURN_uint8_t_array(msg, version, 3,  47);
}

/**
 * @brief Get field md5 from file_heads message
 *
 * @return  md5
 */
static inline uint16_t mavlink_msg_file_heads_get_md5(const mavlink_message_t* msg, uint8_t *md5)
{
    return _MAV_RETURN_uint8_t_array(msg, md5, 16,  50);
}

/**
 * @brief Get field file_name from file_heads message
 *
 * @return  file_name
 */
static inline uint16_t mavlink_msg_file_heads_get_file_name(const mavlink_message_t* msg, char *file_name)
{
    return _MAV_RETURN_char_array(msg, file_name, 50,  66);
}

/**
 * @brief Decode a file_heads message into a struct
 *
 * @param msg The message to decode
 * @param file_heads C-struct to decode the message contents into
 */
static inline void mavlink_msg_file_heads_decode(const mavlink_message_t* msg, mavlink_file_heads_t* file_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    file_heads->file_size = mavlink_msg_file_heads_get_file_size(msg);
    mavlink_msg_file_heads_get_info(msg, file_heads->info);
    mavlink_msg_file_heads_get_array(msg, file_heads->array);
    file_heads->plane_id = mavlink_msg_file_heads_get_plane_id(msg);
    file_heads->file_type = mavlink_msg_file_heads_get_file_type(msg);
    mavlink_msg_file_heads_get_version(msg, file_heads->version);
    mavlink_msg_file_heads_get_md5(msg, file_heads->md5);
    mavlink_msg_file_heads_get_file_name(msg, file_heads->file_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FILE_HEADS_LEN? msg->len : MAVLINK_MSG_ID_FILE_HEADS_LEN;
        memset(file_heads, 0, MAVLINK_MSG_ID_FILE_HEADS_LEN);
    memcpy(file_heads, _MAV_PAYLOAD(msg), len);
#endif
}
