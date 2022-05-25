#pragma once
// MESSAGE file_reponse_info PACKING

#define MAVLINK_MSG_ID_file_reponse_info 213


typedef struct __mavlink_file_reponse_info_t {
 uint32_t plane_id; /*<  plane_id*/
 uint8_t target_info; /*<  target_info*/
} mavlink_file_reponse_info_t;

#define MAVLINK_MSG_ID_file_reponse_info_LEN 5
#define MAVLINK_MSG_ID_file_reponse_info_MIN_LEN 5
#define MAVLINK_MSG_ID_213_LEN 5
#define MAVLINK_MSG_ID_213_MIN_LEN 5

#define MAVLINK_MSG_ID_file_reponse_info_CRC 165
#define MAVLINK_MSG_ID_213_CRC 165



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_file_reponse_info { \
    213, \
    "file_reponse_info", \
    2, \
    {  { "target_info", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_file_reponse_info_t, target_info) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_reponse_info_t, plane_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_file_reponse_info { \
    "file_reponse_info", \
    2, \
    {  { "target_info", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_file_reponse_info_t, target_info) }, \
         { "plane_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_file_reponse_info_t, plane_id) }, \
         } \
}
#endif

/**
 * @brief Pack a file_reponse_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_info  target_info
 * @param plane_id  plane_id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_reponse_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_info, uint32_t plane_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_reponse_info_LEN];
    _mav_put_uint32_t(buf, 0, plane_id);
    _mav_put_uint8_t(buf, 4, target_info);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_file_reponse_info_LEN);
#else
    mavlink_file_reponse_info_t packet;
    packet.plane_id = plane_id;
    packet.target_info = target_info;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_file_reponse_info_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_file_reponse_info;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
}

/**
 * @brief Pack a file_reponse_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_info  target_info
 * @param plane_id  plane_id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_file_reponse_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_info,uint32_t plane_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_reponse_info_LEN];
    _mav_put_uint32_t(buf, 0, plane_id);
    _mav_put_uint8_t(buf, 4, target_info);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_file_reponse_info_LEN);
#else
    mavlink_file_reponse_info_t packet;
    packet.plane_id = plane_id;
    packet.target_info = target_info;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_file_reponse_info_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_file_reponse_info;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
}

/**
 * @brief Encode a file_reponse_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param file_reponse_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_reponse_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_file_reponse_info_t* file_reponse_info)
{
    return mavlink_msg_file_reponse_info_pack(system_id, component_id, msg, file_reponse_info->target_info, file_reponse_info->plane_id);
}

/**
 * @brief Encode a file_reponse_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param file_reponse_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_file_reponse_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_file_reponse_info_t* file_reponse_info)
{
    return mavlink_msg_file_reponse_info_pack_chan(system_id, component_id, chan, msg, file_reponse_info->target_info, file_reponse_info->plane_id);
}

/**
 * @brief Send a file_reponse_info message
 * @param chan MAVLink channel to send the message
 *
 * @param target_info  target_info
 * @param plane_id  plane_id
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_file_reponse_info_send(mavlink_channel_t chan, uint8_t target_info, uint32_t plane_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_file_reponse_info_LEN];
    _mav_put_uint32_t(buf, 0, plane_id);
    _mav_put_uint8_t(buf, 4, target_info);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_reponse_info, buf, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
#else
    mavlink_file_reponse_info_t packet;
    packet.plane_id = plane_id;
    packet.target_info = target_info;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_reponse_info, (const char *)&packet, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
#endif
}

/**
 * @brief Send a file_reponse_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_file_reponse_info_send_struct(mavlink_channel_t chan, const mavlink_file_reponse_info_t* file_reponse_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_file_reponse_info_send(chan, file_reponse_info->target_info, file_reponse_info->plane_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_reponse_info, (const char *)file_reponse_info, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
#endif
}

#if MAVLINK_MSG_ID_file_reponse_info_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_file_reponse_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_info, uint32_t plane_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, plane_id);
    _mav_put_uint8_t(buf, 4, target_info);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_reponse_info, buf, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
#else
    mavlink_file_reponse_info_t *packet = (mavlink_file_reponse_info_t *)msgbuf;
    packet->plane_id = plane_id;
    packet->target_info = target_info;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_file_reponse_info, (const char *)packet, MAVLINK_MSG_ID_file_reponse_info_MIN_LEN, MAVLINK_MSG_ID_file_reponse_info_LEN, MAVLINK_MSG_ID_file_reponse_info_CRC);
#endif
}
#endif

#endif

// MESSAGE file_reponse_info UNPACKING


/**
 * @brief Get field target_info from file_reponse_info message
 *
 * @return  target_info
 */
static inline uint8_t mavlink_msg_file_reponse_info_get_target_info(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field plane_id from file_reponse_info message
 *
 * @return  plane_id
 */
static inline uint32_t mavlink_msg_file_reponse_info_get_plane_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a file_reponse_info message into a struct
 *
 * @param msg The message to decode
 * @param file_reponse_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_file_reponse_info_decode(const mavlink_message_t* msg, mavlink_file_reponse_info_t* file_reponse_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    file_reponse_info->plane_id = mavlink_msg_file_reponse_info_get_plane_id(msg);
    file_reponse_info->target_info = mavlink_msg_file_reponse_info_get_target_info(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_file_reponse_info_LEN? msg->len : MAVLINK_MSG_ID_file_reponse_info_LEN;
        memset(file_reponse_info, 0, MAVLINK_MSG_ID_file_reponse_info_LEN);
    memcpy(file_reponse_info, _MAV_PAYLOAD(msg), len);
#endif
}
