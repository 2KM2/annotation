#pragma once
// MESSAGE FIRMWARE_HEADS PACKING

#define MAVLINK_MSG_ID_FIRMWARE_HEADS 184

#pragma pack(1)
typedef struct __mavlink_firmware_heads_t {
 uint32_t lenth; /*< The byte lenth of firmware. E.g: 10000.*/
 uint16_t serial_num; /*< The serilal number of Aircraft. E.g: 13.*/
 uint8_t version[4]; /*< The version of firmware. E.g: V1.2.4.4.*/
 uint8_t md5[16]; /*< The md5 of firmware.*/
} mavlink_firmware_heads_t;
#pragma pack()

#define MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN 26
#define MAVLINK_MSG_ID_FIRMWARE_HEADS_MIN_LEN 26
#define MAVLINK_MSG_ID_184_LEN 26
#define MAVLINK_MSG_ID_184_MIN_LEN 26

#define MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC 156
#define MAVLINK_MSG_ID_184_CRC 156

#define MAVLINK_MSG_FIRMWARE_HEADS_FIELD_VERSION_LEN 4
#define MAVLINK_MSG_FIRMWARE_HEADS_FIELD_MD5_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FIRMWARE_HEADS { \
    184, \
    "FIRMWARE_HEADS", \
    4, \
    {  { "version", NULL, MAVLINK_TYPE_UINT8_T, 4, 6, offsetof(mavlink_firmware_heads_t, version) }, \
         { "lenth", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_firmware_heads_t, lenth) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 10, offsetof(mavlink_firmware_heads_t, md5) }, \
         { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_firmware_heads_t, serial_num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FIRMWARE_HEADS { \
    "FIRMWARE_HEADS", \
    4, \
    {  { "version", NULL, MAVLINK_TYPE_UINT8_T, 4, 6, offsetof(mavlink_firmware_heads_t, version) }, \
         { "lenth", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_firmware_heads_t, lenth) }, \
         { "md5", NULL, MAVLINK_TYPE_UINT8_T, 16, 10, offsetof(mavlink_firmware_heads_t, md5) }, \
         { "serial_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_firmware_heads_t, serial_num) }, \
         } \
}
#endif

/**
 * @brief Pack a firmware_heads message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param version The version of firmware. E.g: V1.2.4.4.
 * @param lenth The byte lenth of firmware. E.g: 10000.
 * @param md5 The md5 of firmware.
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_firmware_heads_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *version, uint32_t lenth, const uint8_t *md5, uint16_t serial_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, lenth);
    _mav_put_uint16_t(buf, 4, serial_num);
    _mav_put_uint8_t_array(buf, 6, version, 4);
    _mav_put_uint8_t_array(buf, 10, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN);
#else
    mavlink_firmware_heads_t packet;
    packet.lenth = lenth;
    packet.serial_num = serial_num;
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*4);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FIRMWARE_HEADS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
}

/**
 * @brief Pack a firmware_heads message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param version The version of firmware. E.g: V1.2.4.4.
 * @param lenth The byte lenth of firmware. E.g: 10000.
 * @param md5 The md5 of firmware.
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_firmware_heads_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *version,uint32_t lenth,const uint8_t *md5,uint16_t serial_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, lenth);
    _mav_put_uint16_t(buf, 4, serial_num);
    _mav_put_uint8_t_array(buf, 6, version, 4);
    _mav_put_uint8_t_array(buf, 10, md5, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN);
#else
    mavlink_firmware_heads_t packet;
    packet.lenth = lenth;
    packet.serial_num = serial_num;
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*4);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FIRMWARE_HEADS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
}

/**
 * @brief Encode a firmware_heads struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param firmware_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_firmware_heads_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_firmware_heads_t* firmware_heads)
{
    return mavlink_msg_firmware_heads_pack(system_id, component_id, msg, firmware_heads->version, firmware_heads->lenth, firmware_heads->md5, firmware_heads->serial_num);
}

/**
 * @brief Encode a firmware_heads struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param firmware_heads C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_firmware_heads_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_firmware_heads_t* firmware_heads)
{
    return mavlink_msg_firmware_heads_pack_chan(system_id, component_id, chan, msg, firmware_heads->version, firmware_heads->lenth, firmware_heads->md5, firmware_heads->serial_num);
}

/**
 * @brief Send a firmware_heads message
 * @param chan MAVLink channel to send the message
 *
 * @param version The version of firmware. E.g: V1.2.4.4.
 * @param lenth The byte lenth of firmware. E.g: 10000.
 * @param md5 The md5 of firmware.
 * @param serial_num The serilal number of Aircraft. E.g: 13.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_firmware_heads_send(mavlink_channel_t chan, const uint8_t *version, uint32_t lenth, const uint8_t *md5, uint16_t serial_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN];
    _mav_put_uint32_t(buf, 0, lenth);
    _mav_put_uint16_t(buf, 4, serial_num);
    _mav_put_uint8_t_array(buf, 6, version, 4);
    _mav_put_uint8_t_array(buf, 10, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_HEADS, buf, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
#else
    mavlink_firmware_heads_t packet;
    packet.lenth = lenth;
    packet.serial_num = serial_num;
    mav_array_memcpy(packet.version, version, sizeof(uint8_t)*4);
    mav_array_memcpy(packet.md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_HEADS, (const char *)&packet, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
#endif
}

/**
 * @brief Send a firmware_heads message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_firmware_heads_send_struct(mavlink_channel_t chan, const mavlink_firmware_heads_t* firmware_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_firmware_heads_send(chan, firmware_heads->version, firmware_heads->lenth, firmware_heads->md5, firmware_heads->serial_num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_HEADS, (const char *)firmware_heads, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
#endif
}

#if MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_firmware_heads_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *version, uint32_t lenth, const uint8_t *md5, uint16_t serial_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, lenth);
    _mav_put_uint16_t(buf, 4, serial_num);
    _mav_put_uint8_t_array(buf, 6, version, 4);
    _mav_put_uint8_t_array(buf, 10, md5, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_HEADS, buf, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
#else
    mavlink_firmware_heads_t *packet = (mavlink_firmware_heads_t *)msgbuf;
    packet->lenth = lenth;
    packet->serial_num = serial_num;
    mav_array_memcpy(packet->version, version, sizeof(uint8_t)*4);
    mav_array_memcpy(packet->md5, md5, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_HEADS, (const char *)packet, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN, MAVLINK_MSG_ID_FIRMWARE_HEADS_CRC);
#endif
}
#endif

#endif

// MESSAGE FIRMWARE_HEADS UNPACKING


/**
 * @brief Get field version from firmware_heads message
 *
 * @return The version of firmware. E.g: V1.2.4.4.
 */
static inline uint16_t mavlink_msg_firmware_heads_get_version(const mavlink_message_t* msg, uint8_t *version)
{
    return _MAV_RETURN_uint8_t_array(msg, version, 4,  6);
}

/**
 * @brief Get field lenth from firmware_heads message
 *
 * @return The byte lenth of firmware. E.g: 10000.
 */
static inline uint32_t mavlink_msg_firmware_heads_get_lenth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field md5 from firmware_heads message
 *
 * @return The md5 of firmware.
 */
static inline uint16_t mavlink_msg_firmware_heads_get_md5(const mavlink_message_t* msg, uint8_t *md5)
{
    return _MAV_RETURN_uint8_t_array(msg, md5, 16,  10);
}

/**
 * @brief Get field serial_num from firmware_heads message
 *
 * @return The serilal number of Aircraft. E.g: 13.
 */
static inline uint16_t mavlink_msg_firmware_heads_get_serial_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a firmware_heads message into a struct
 *
 * @param msg The message to decode
 * @param firmware_heads C-struct to decode the message contents into
 */
static inline void mavlink_msg_firmware_heads_decode(const mavlink_message_t* msg, mavlink_firmware_heads_t* firmware_heads)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    firmware_heads->lenth = mavlink_msg_firmware_heads_get_lenth(msg);
    firmware_heads->serial_num = mavlink_msg_firmware_heads_get_serial_num(msg);
    mavlink_msg_firmware_heads_get_version(msg, firmware_heads->version);
    mavlink_msg_firmware_heads_get_md5(msg, firmware_heads->md5);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN? msg->len : MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN;
        memset(firmware_heads, 0, MAVLINK_MSG_ID_FIRMWARE_HEADS_LEN);
    memcpy(firmware_heads, _MAV_PAYLOAD(msg), len);
#endif
}
