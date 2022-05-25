#pragma once
// MESSAGE FIRMWARE_DATAS PACKING

#define MAVLINK_MSG_ID_FIRMWARE_DATAS 185

#pragma pack(1)
typedef struct __mavlink_firmware_datas_t {
 uint32_t id; /*< The id of firmware. E.g: 36.*/
 uint8_t data[248]; /*< The data of firmware.*/
} mavlink_firmware_datas_t;
#pragma pack()

#define MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN 252
#define MAVLINK_MSG_ID_FIRMWARE_DATAS_MIN_LEN 252
#define MAVLINK_MSG_ID_185_LEN 252
#define MAVLINK_MSG_ID_185_MIN_LEN 252

#define MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC 122
#define MAVLINK_MSG_ID_185_CRC 122

#define MAVLINK_MSG_FIRMWARE_DATAS_FIELD_DATA_LEN 248

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FIRMWARE_DATAS { \
    185, \
    "FIRMWARE_DATAS", \
    2, \
    {  { "id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_firmware_datas_t, id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 248, 4, offsetof(mavlink_firmware_datas_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FIRMWARE_DATAS { \
    "FIRMWARE_DATAS", \
    2, \
    {  { "id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_firmware_datas_t, id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 248, 4, offsetof(mavlink_firmware_datas_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a firmware_datas message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id The id of firmware. E.g: 36.
 * @param data The data of firmware.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_firmware_datas_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN];
    _mav_put_uint32_t(buf, 0, id);
    _mav_put_uint8_t_array(buf, 4, data, 248);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN);
#else
    mavlink_firmware_datas_t packet;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*248);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FIRMWARE_DATAS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
}

/**
 * @brief Pack a firmware_datas message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id The id of firmware. E.g: 36.
 * @param data The data of firmware.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_firmware_datas_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t id,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN];
    _mav_put_uint32_t(buf, 0, id);
    _mav_put_uint8_t_array(buf, 4, data, 248);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN);
#else
    mavlink_firmware_datas_t packet;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*248);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FIRMWARE_DATAS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
}

/**
 * @brief Encode a firmware_datas struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param firmware_datas C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_firmware_datas_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_firmware_datas_t* firmware_datas)
{
    return mavlink_msg_firmware_datas_pack(system_id, component_id, msg, firmware_datas->id, firmware_datas->data);
}

/**
 * @brief Encode a firmware_datas struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param firmware_datas C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_firmware_datas_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_firmware_datas_t* firmware_datas)
{
    return mavlink_msg_firmware_datas_pack_chan(system_id, component_id, chan, msg, firmware_datas->id, firmware_datas->data);
}

/**
 * @brief Send a firmware_datas message
 * @param chan MAVLink channel to send the message
 *
 * @param id The id of firmware. E.g: 36.
 * @param data The data of firmware.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_firmware_datas_send(mavlink_channel_t chan, uint32_t id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN];
    _mav_put_uint32_t(buf, 0, id);
    _mav_put_uint8_t_array(buf, 4, data, 248);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_DATAS, buf, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
#else
    mavlink_firmware_datas_t packet;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*248);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_DATAS, (const char *)&packet, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
#endif
}

/**
 * @brief Send a firmware_datas message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_firmware_datas_send_struct(mavlink_channel_t chan, const mavlink_firmware_datas_t* firmware_datas)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_firmware_datas_send(chan, firmware_datas->id, firmware_datas->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_DATAS, (const char *)firmware_datas, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
#endif
}

#if MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_firmware_datas_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, id);
    _mav_put_uint8_t_array(buf, 4, data, 248);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_DATAS, buf, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
#else
    mavlink_firmware_datas_t *packet = (mavlink_firmware_datas_t *)msgbuf;
    packet->id = id;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*248);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FIRMWARE_DATAS, (const char *)packet, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN, MAVLINK_MSG_ID_FIRMWARE_DATAS_CRC);
#endif
}
#endif

#endif

// MESSAGE FIRMWARE_DATAS UNPACKING


/**
 * @brief Get field id from firmware_datas message
 *
 * @return The id of firmware. E.g: 36.
 */
static inline uint32_t mavlink_msg_firmware_datas_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field data from firmware_datas message
 *
 * @return The data of firmware.
 */
static inline uint16_t mavlink_msg_firmware_datas_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 248,  4);
}

/**
 * @brief Decode a firmware_datas message into a struct
 *
 * @param msg The message to decode
 * @param firmware_datas C-struct to decode the message contents into
 */
static inline void mavlink_msg_firmware_datas_decode(const mavlink_message_t* msg, mavlink_firmware_datas_t* firmware_datas)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    firmware_datas->id = mavlink_msg_firmware_datas_get_id(msg);
    mavlink_msg_firmware_datas_get_data(msg, firmware_datas->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN? msg->len : MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN;
        memset(firmware_datas, 0, MAVLINK_MSG_ID_FIRMWARE_DATAS_LEN);
    memcpy(firmware_datas, _MAV_PAYLOAD(msg), len);
#endif
}
