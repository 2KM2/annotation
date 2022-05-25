#pragma once
// MESSAGE FORMATION_REQUEST_INFO PACKING

#define MAVLINK_MSG_ID_FORMATION_REQUEST_INFO 173

#pragma pack(1)
typedef struct __mavlink_formation_request_info_t {
 uint8_t target_info; /*< Request of target info. E.g: 1, Request heads info; 2, Request dance info.*/
 uint32_t dance_id; /*< The formation dance number. E.g: 36.*/
} mavlink_formation_request_info_t;
#pragma pack()

#define MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN 5
#define MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_MIN_LEN 5
#define MAVLINK_MSG_ID_173_LEN 5
#define MAVLINK_MSG_ID_173_MIN_LEN 5

#define MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC 172
#define MAVLINK_MSG_ID_173_CRC 172



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FORMATION_REQUEST_INFO { \
    173, \
    "FORMATION_REQUEST_INFO", \
    2, \
    {  { "target_info", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_formation_request_info_t, target_info) }, \
         { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_request_info_t, dance_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FORMATION_REQUEST_INFO { \
    "FORMATION_REQUEST_INFO", \
    2, \
    {  { "target_info", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_formation_request_info_t, target_info) }, \
         { "dance_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_formation_request_info_t, dance_id) }, \
         } \
}
#endif

/**
 * @brief Pack a formation_request_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_info Request of target info. E.g: 1, Request heads info; 2, Request dance info.
 * @param dance_id The formation dance number. E.g: 36.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_request_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_info, uint32_t dance_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t(buf, 4, target_info);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN);
#else
    mavlink_formation_request_info_t packet;
    packet.dance_id = dance_id;
    packet.target_info = target_info;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_REQUEST_INFO;
    return mavlink_finalize_message(msg, system_id, component_id , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
}

/**
 * @brief Pack a formation_request_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_info Request of target info. E.g: 1, Request heads info; 2, Request dance info.
 * @param dance_id The formation dance number. E.g: 36.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_formation_request_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_info,uint32_t dance_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t(buf, 4, target_info);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN);
#else
    mavlink_formation_request_info_t packet;
    packet.dance_id = dance_id;
    packet.target_info = target_info;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FORMATION_REQUEST_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
}

/**
 * @brief Encode a formation_request_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param formation_request_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_request_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_formation_request_info_t* formation_request_info)
{
    return mavlink_msg_formation_request_info_pack(system_id, component_id, msg, formation_request_info->target_info, formation_request_info->dance_id);
}

/**
 * @brief Encode a formation_request_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param formation_request_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_formation_request_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_formation_request_info_t* formation_request_info)
{
    return mavlink_msg_formation_request_info_pack_chan(system_id, component_id, chan, msg, formation_request_info->target_info, formation_request_info->dance_id);
}

/**
 * @brief Send a formation_request_info message
 * @param chan MAVLink channel to send the message
 *
 * @param target_info Request of target info. E.g: 1, Request heads info; 2, Request dance info.
 * @param dance_id The formation dance number. E.g: 36.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_formation_request_info_send(mavlink_channel_t chan, uint8_t target_info, uint32_t dance_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN];
    _mav_put_uint32_t(buf, 1, dance_id);
    _mav_put_uint8_t(buf, 0, target_info);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO, buf , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
#else
    mavlink_formation_request_info_t packet;
    packet.dance_id = dance_id;
    packet.target_info = target_info;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO, (const char *)&packet , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
#endif
}

/**
 * @brief Send a formation_request_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_formation_request_info_send_struct(mavlink_channel_t chan, const mavlink_formation_request_info_t* formation_request_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_formation_request_info_send(chan, formation_request_info->target_info, formation_request_info->dance_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO, (const char *)formation_request_info , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_formation_request_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_info, uint32_t dance_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dance_id);
    _mav_put_uint8_t(buf, 4, target_info);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO, buf , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
#else
    mavlink_formation_request_info_t *packet = (mavlink_formation_request_info_t *)msgbuf;
    packet->dance_id = dance_id;
    packet->target_info = target_info;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO, (const char *)packet , MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE FORMATION_REQUEST_INFO UNPACKING


/**
 * @brief Get field target_info from formation_request_info message
 *
 * @return Request of target info. E.g: 1, Request heads info; 2, Request dance info.
 */
static inline uint8_t mavlink_msg_formation_request_info_get_target_info(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field dance_id from formation_request_info message
 *
 * @return The formation dance number. E.g: 36.
 */
static inline uint32_t mavlink_msg_formation_request_info_get_dance_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a formation_request_info message into a struct
 *
 * @param msg The message to decode
 * @param formation_request_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_formation_request_info_decode(const mavlink_message_t* msg, mavlink_formation_request_info_t* formation_request_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    formation_request_info->dance_id = mavlink_msg_formation_request_info_get_dance_id(msg);
    formation_request_info->target_info = mavlink_msg_formation_request_info_get_target_info(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN? msg->len : MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN;
        memset(formation_request_info, 0, MAVLINK_MSG_ID_FORMATION_REQUEST_INFO_LEN);
    memcpy(formation_request_info, _MAV_PAYLOAD(msg), len);
#endif
}
