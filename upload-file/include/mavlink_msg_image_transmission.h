#pragma once
// MESSAGE image_transmission PACKING

#define MAVLINK_MSG_ID_image_transmission 236


typedef struct __mavlink_image_transmission_t {
 int16_t client_port; /*<  client_port*/
 char client_ip[32]; /*<  client_ip*/
} mavlink_image_transmission_t;

#define MAVLINK_MSG_ID_image_transmission_LEN 34
#define MAVLINK_MSG_ID_image_transmission_MIN_LEN 34
#define MAVLINK_MSG_ID_236_LEN 34
#define MAVLINK_MSG_ID_236_MIN_LEN 34

#define MAVLINK_MSG_ID_image_transmission_CRC 175
#define MAVLINK_MSG_ID_236_CRC 175

#define MAVLINK_MSG_image_transmission_FIELD_CLIENT_IP_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_image_transmission { \
    236, \
    "image_transmission", \
    2, \
    {  { "client_ip", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_image_transmission_t, client_ip) }, \
         { "client_port", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_image_transmission_t, client_port) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_image_transmission { \
    "image_transmission", \
    2, \
    {  { "client_ip", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_image_transmission_t, client_ip) }, \
         { "client_port", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_image_transmission_t, client_port) }, \
         } \
}
#endif

/**
 * @brief Pack a image_transmission message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param client_ip  client_ip
 * @param client_port  client_port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_image_transmission_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *client_ip, int16_t client_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_image_transmission_LEN];
    _mav_put_int16_t(buf, 0, client_port);
    _mav_put_char_array(buf, 2, client_ip, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_image_transmission_LEN);
#else
    mavlink_image_transmission_t packet;
    packet.client_port = client_port;
    mav_array_memcpy(packet.client_ip, client_ip, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_image_transmission_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_image_transmission;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
}

/**
 * @brief Pack a image_transmission message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param client_ip  client_ip
 * @param client_port  client_port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_image_transmission_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *client_ip,int16_t client_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_image_transmission_LEN];
    _mav_put_int16_t(buf, 0, client_port);
    _mav_put_char_array(buf, 2, client_ip, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_image_transmission_LEN);
#else
    mavlink_image_transmission_t packet;
    packet.client_port = client_port;
    mav_array_memcpy(packet.client_ip, client_ip, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_image_transmission_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_image_transmission;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
}

/**
 * @brief Encode a image_transmission struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param image_transmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_image_transmission_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_image_transmission_t* image_transmission)
{
    return mavlink_msg_image_transmission_pack(system_id, component_id, msg, image_transmission->client_ip, image_transmission->client_port);
}

/**
 * @brief Encode a image_transmission struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param image_transmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_image_transmission_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_image_transmission_t* image_transmission)
{
    return mavlink_msg_image_transmission_pack_chan(system_id, component_id, chan, msg, image_transmission->client_ip, image_transmission->client_port);
}

/**
 * @brief Send a image_transmission message
 * @param chan MAVLink channel to send the message
 *
 * @param client_ip  client_ip
 * @param client_port  client_port
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_image_transmission_send(mavlink_channel_t chan, const char *client_ip, int16_t client_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_image_transmission_LEN];
    _mav_put_int16_t(buf, 0, client_port);
    _mav_put_char_array(buf, 2, client_ip, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_image_transmission, buf, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
#else
    mavlink_image_transmission_t packet;
    packet.client_port = client_port;
    mav_array_memcpy(packet.client_ip, client_ip, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_image_transmission, (const char *)&packet, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
#endif
}

/**
 * @brief Send a image_transmission message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_image_transmission_send_struct(mavlink_channel_t chan, const mavlink_image_transmission_t* image_transmission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_image_transmission_send(chan, image_transmission->client_ip, image_transmission->client_port);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_image_transmission, (const char *)image_transmission, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
#endif
}

#if MAVLINK_MSG_ID_image_transmission_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_image_transmission_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *client_ip, int16_t client_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, client_port);
    _mav_put_char_array(buf, 2, client_ip, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_image_transmission, buf, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
#else
    mavlink_image_transmission_t *packet = (mavlink_image_transmission_t *)msgbuf;
    packet->client_port = client_port;
    mav_array_memcpy(packet->client_ip, client_ip, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_image_transmission, (const char *)packet, MAVLINK_MSG_ID_image_transmission_MIN_LEN, MAVLINK_MSG_ID_image_transmission_LEN, MAVLINK_MSG_ID_image_transmission_CRC);
#endif
}
#endif

#endif

// MESSAGE image_transmission UNPACKING


/**
 * @brief Get field client_ip from image_transmission message
 *
 * @return  client_ip
 */
static inline uint16_t mavlink_msg_image_transmission_get_client_ip(const mavlink_message_t* msg, char *client_ip)
{
    return _MAV_RETURN_char_array(msg, client_ip, 32,  2);
}

/**
 * @brief Get field client_port from image_transmission message
 *
 * @return  client_port
 */
static inline int16_t mavlink_msg_image_transmission_get_client_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a image_transmission message into a struct
 *
 * @param msg The message to decode
 * @param image_transmission C-struct to decode the message contents into
 */
static inline void mavlink_msg_image_transmission_decode(const mavlink_message_t* msg, mavlink_image_transmission_t* image_transmission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    image_transmission->client_port = mavlink_msg_image_transmission_get_client_port(msg);
    mavlink_msg_image_transmission_get_client_ip(msg, image_transmission->client_ip);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_image_transmission_LEN? msg->len : MAVLINK_MSG_ID_image_transmission_LEN;
        memset(image_transmission, 0, MAVLINK_MSG_ID_image_transmission_LEN);
    memcpy(image_transmission, _MAV_PAYLOAD(msg), len);
#endif
}
