#pragma once
// MESSAGE file_data PACKING

#define MAVLINK_MSG_ID_file_data 212


typedef struct __mavlink_file_data_t {
 uint32_t package_id; /*<  package_id*/
 uint8_t file_data[250]; /*<  file_data*/
} mavlink_file_data_t;

#define MAVLINK_MSG_ID_file_data_LEN 254
#define MAVLINK_MSG_ID_file_data_MIN_LEN 254
#define MAVLINK_MSG_ID_212_LEN 254
#define MAVLINK_MSG_ID_212_MIN_LEN 254

#define MAVLINK_MSG_ID_file_data_CRC 227
#define MAVLINK_MSG_ID_212_CRC 227

#define MAVLINK_MSG_file_data_FIELD_FILE_DATA_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_file_data { \
    212, \
    "file_data", \
    2, \
    {  { "package_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_data_t, package_id) }, \
         { "file_data", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_file_data_t, file_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_file_data { \
    "file_data", \
    2, \
    {  { "package_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_data_t, package_id) }, \
         { "file_data", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_file_data_t, file_data) }, \
         } \
}
#endif

/**
 * @brief Pack a file_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param package_id  package_id
 * @param file_data  file_data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t package_id, const uint8_t *file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_data_LEN];
    _mav_put_uint32_t(buf, 0, package_id);
    _mav_put_uint8_t_array(buf, 4, file_data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_file_data_LEN);
#else
    mavlink_file_data_t packet;
    packet.package_id = package_id;
    mav_array_memcpy(packet.file_data, file_data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_file_data_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_file_data;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
}

/**
 * @brief Pack a file_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param package_id  package_id
 * @param file_data  file_data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t package_id,const uint8_t *file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_data_LEN];
    _mav_put_uint32_t(buf, 0, package_id);
    _mav_put_uint8_t_array(buf, 4, file_data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_file_data_LEN);
#else
    mavlink_file_data_t packet;
    packet.package_id = package_id;
    mav_array_memcpy(packet.file_data, file_data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_file_data_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_file_data;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
}

/**
 * @brief Encode a file_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param file_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_file_data_t* file_data)
{
    return mavlink_msg_file_data_pack(system_id, component_id, msg, file_data->package_id, file_data->file_data);
}

/**
 * @brief Encode a file_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param file_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_file_data_t* file_data)
{
    return mavlink_msg_file_data_pack_chan(system_id, component_id, chan, msg, file_data->package_id, file_data->file_data);
}

/**
 * @brief Send a file_data message
 * @param chan MAVLink channel to send the message
 *
 * @param package_id  package_id
 * @param file_data  file_data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_file_data_send(mavlink_channel_t chan, uint32_t package_id, const uint8_t *file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_data_LEN];
    _mav_put_uint32_t(buf, 0, package_id);
    _mav_put_uint8_t_array(buf, 4, file_data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_data, buf, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
#else
    mavlink_file_data_t packet;
    packet.package_id = package_id;
    mav_array_memcpy(packet.file_data, file_data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_data, (const char *)&packet, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
#endif
}

/**
 * @brief Send a file_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_file_data_send_struct(mavlink_channel_t chan, const mavlink_file_data_t* file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_file_data_send(chan, file_data->package_id, file_data->file_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_data, (const char *)file_data, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
#endif
}

#if MAVLINK_MSG_ID_file_data_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_file_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t package_id, const uint8_t *file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, package_id);
    _mav_put_uint8_t_array(buf, 4, file_data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_data, buf, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
#else
    mavlink_file_data_t *packet = (mavlink_file_data_t *)msgbuf;
    packet->package_id = package_id;
    mav_array_memcpy(packet->file_data, file_data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_data, (const char *)packet, MAVLINK_MSG_ID_file_data_MIN_LEN, MAVLINK_MSG_ID_file_data_LEN, MAVLINK_MSG_ID_file_data_CRC);
#endif
}
#endif

#endif

// MESSAGE file_data UNPACKING


/**
 * @brief Get field package_id from file_data message
 *
 * @return  package_id
 */
static inline uint32_t mavlink_msg_file_data_get_package_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field file_data from file_data message
 *
 * @return  file_data
 */
static inline uint16_t mavlink_msg_file_data_get_file_data(const mavlink_message_t* msg, uint8_t *file_data)
{
    return _MAV_RETURN_uint8_t_array(msg, file_data, 250,  4);
}

/**
 * @brief Decode a file_data message into a struct
 *
 * @param msg The message to decode
 * @param file_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_file_data_decode(const mavlink_message_t* msg, mavlink_file_data_t* file_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    file_data->package_id = mavlink_msg_file_data_get_package_id(msg);
    mavlink_msg_file_data_get_file_data(msg, file_data->file_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_file_data_LEN? msg->len : MAVLINK_MSG_ID_file_data_LEN;
        memset(file_data, 0, MAVLINK_MSG_ID_file_data_LEN);
    memcpy(file_data, _MAV_PAYLOAD(msg), len);
#endif
}
