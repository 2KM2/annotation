#pragma once
// MESSAGE DRONE_POS_ATT PACKING

#define MAVLINK_MSG_ID_DRONE_POS_ATT 51

MAVPACKED(
typedef struct __mavlink_drone_pos_att_t {
 uint64_t timestamp; /*< Timestamp milliseconds(UNIX)*/
 float x; /*< */
 float y; /*< */
 float z; /*< */
 float vx; /*< */
 float vy; /*< */
 float vz; /*< */
 float roll; /*< */
 float pitch; /*< */
 float yaw; /*< */
 float rollspeed; /*< */
 float pitchspeed; /*< */
 float yawspeed; /*< */
 float ground_distance; /*< */
}) mavlink_drone_pos_att_t;

#define MAVLINK_MSG_ID_DRONE_POS_ATT_LEN 60
#define MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN 60
#define MAVLINK_MSG_ID_51_LEN 60
#define MAVLINK_MSG_ID_51_MIN_LEN 60

#define MAVLINK_MSG_ID_DRONE_POS_ATT_CRC 5
#define MAVLINK_MSG_ID_51_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DRONE_POS_ATT { \
    51, \
    "DRONE_POS_ATT", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_drone_pos_att_t, timestamp) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_drone_pos_att_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_drone_pos_att_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_drone_pos_att_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_drone_pos_att_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_drone_pos_att_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_drone_pos_att_t, vz) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_drone_pos_att_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_drone_pos_att_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_drone_pos_att_t, yaw) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_drone_pos_att_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_drone_pos_att_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_drone_pos_att_t, yawspeed) }, \
         { "ground_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_drone_pos_att_t, ground_distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DRONE_POS_ATT { \
    "DRONE_POS_ATT", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_drone_pos_att_t, timestamp) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_drone_pos_att_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_drone_pos_att_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_drone_pos_att_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_drone_pos_att_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_drone_pos_att_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_drone_pos_att_t, vz) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_drone_pos_att_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_drone_pos_att_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_drone_pos_att_t, yaw) }, \
         { "rollspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_drone_pos_att_t, rollspeed) }, \
         { "pitchspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_drone_pos_att_t, pitchspeed) }, \
         { "yawspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_drone_pos_att_t, yawspeed) }, \
         { "ground_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_drone_pos_att_t, ground_distance) }, \
         } \
}
#endif

/**
 * @brief Pack a drone_pos_att message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp milliseconds(UNIX)
 * @param x 
 * @param y 
 * @param z 
 * @param vx 
 * @param vy 
 * @param vz 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param rollspeed 
 * @param pitchspeed 
 * @param yawspeed 
 * @param ground_distance 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_drone_pos_att_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed, float ground_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DRONE_POS_ATT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);
    _mav_put_float(buf, 20, vx);
    _mav_put_float(buf, 24, vy);
    _mav_put_float(buf, 28, vz);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, rollspeed);
    _mav_put_float(buf, 48, pitchspeed);
    _mav_put_float(buf, 52, yawspeed);
    _mav_put_float(buf, 56, ground_distance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN);
#else
    mavlink_drone_pos_att_t packet;
    packet.timestamp = timestamp;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.ground_distance = ground_distance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DRONE_POS_ATT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
}

/**
 * @brief Pack a drone_pos_att message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp milliseconds(UNIX)
 * @param x 
 * @param y 
 * @param z 
 * @param vx 
 * @param vy 
 * @param vz 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param rollspeed 
 * @param pitchspeed 
 * @param yawspeed 
 * @param ground_distance 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_drone_pos_att_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,float x,float y,float z,float vx,float vy,float vz,float roll,float pitch,float yaw,float rollspeed,float pitchspeed,float yawspeed,float ground_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DRONE_POS_ATT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);
    _mav_put_float(buf, 20, vx);
    _mav_put_float(buf, 24, vy);
    _mav_put_float(buf, 28, vz);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, rollspeed);
    _mav_put_float(buf, 48, pitchspeed);
    _mav_put_float(buf, 52, yawspeed);
    _mav_put_float(buf, 56, ground_distance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN);
#else
    mavlink_drone_pos_att_t packet;
    packet.timestamp = timestamp;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.ground_distance = ground_distance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DRONE_POS_ATT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
}

/**
 * @brief Encode a drone_pos_att struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param drone_pos_att C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_drone_pos_att_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_drone_pos_att_t* drone_pos_att)
{
    return mavlink_msg_drone_pos_att_pack(system_id, component_id, msg, drone_pos_att->timestamp, drone_pos_att->x, drone_pos_att->y, drone_pos_att->z, drone_pos_att->vx, drone_pos_att->vy, drone_pos_att->vz, drone_pos_att->roll, drone_pos_att->pitch, drone_pos_att->yaw, drone_pos_att->rollspeed, drone_pos_att->pitchspeed, drone_pos_att->yawspeed, drone_pos_att->ground_distance);
}

/**
 * @brief Encode a drone_pos_att struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param drone_pos_att C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_drone_pos_att_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_drone_pos_att_t* drone_pos_att)
{
    return mavlink_msg_drone_pos_att_pack_chan(system_id, component_id, chan, msg, drone_pos_att->timestamp, drone_pos_att->x, drone_pos_att->y, drone_pos_att->z, drone_pos_att->vx, drone_pos_att->vy, drone_pos_att->vz, drone_pos_att->roll, drone_pos_att->pitch, drone_pos_att->yaw, drone_pos_att->rollspeed, drone_pos_att->pitchspeed, drone_pos_att->yawspeed, drone_pos_att->ground_distance);
}

/**
 * @brief Send a drone_pos_att message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp milliseconds(UNIX)
 * @param x 
 * @param y 
 * @param z 
 * @param vx 
 * @param vy 
 * @param vz 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param rollspeed 
 * @param pitchspeed 
 * @param yawspeed 
 * @param ground_distance 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_drone_pos_att_send(mavlink_channel_t chan, uint64_t timestamp, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed, float ground_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DRONE_POS_ATT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);
    _mav_put_float(buf, 20, vx);
    _mav_put_float(buf, 24, vy);
    _mav_put_float(buf, 28, vz);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, rollspeed);
    _mav_put_float(buf, 48, pitchspeed);
    _mav_put_float(buf, 52, yawspeed);
    _mav_put_float(buf, 56, ground_distance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DRONE_POS_ATT, buf, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
#else
    mavlink_drone_pos_att_t packet;
    packet.timestamp = timestamp;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.rollspeed = rollspeed;
    packet.pitchspeed = pitchspeed;
    packet.yawspeed = yawspeed;
    packet.ground_distance = ground_distance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DRONE_POS_ATT, (const char *)&packet, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
#endif
}

/**
 * @brief Send a drone_pos_att message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_drone_pos_att_send_struct(mavlink_channel_t chan, const mavlink_drone_pos_att_t* drone_pos_att)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_drone_pos_att_send(chan, drone_pos_att->timestamp, drone_pos_att->x, drone_pos_att->y, drone_pos_att->z, drone_pos_att->vx, drone_pos_att->vy, drone_pos_att->vz, drone_pos_att->roll, drone_pos_att->pitch, drone_pos_att->yaw, drone_pos_att->rollspeed, drone_pos_att->pitchspeed, drone_pos_att->yawspeed, drone_pos_att->ground_distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DRONE_POS_ATT, (const char *)drone_pos_att, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
#endif
}

#if MAVLINK_MSG_ID_DRONE_POS_ATT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_drone_pos_att_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float x, float y, float z, float vx, float vy, float vz, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed, float ground_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, z);
    _mav_put_float(buf, 20, vx);
    _mav_put_float(buf, 24, vy);
    _mav_put_float(buf, 28, vz);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, rollspeed);
    _mav_put_float(buf, 48, pitchspeed);
    _mav_put_float(buf, 52, yawspeed);
    _mav_put_float(buf, 56, ground_distance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DRONE_POS_ATT, buf, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
#else
    mavlink_drone_pos_att_t *packet = (mavlink_drone_pos_att_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->rollspeed = rollspeed;
    packet->pitchspeed = pitchspeed;
    packet->yawspeed = yawspeed;
    packet->ground_distance = ground_distance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DRONE_POS_ATT, (const char *)packet, MAVLINK_MSG_ID_DRONE_POS_ATT_MIN_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN, MAVLINK_MSG_ID_DRONE_POS_ATT_CRC);
#endif
}
#endif

#endif

// MESSAGE DRONE_POS_ATT UNPACKING


/**
 * @brief Get field timestamp from drone_pos_att message
 *
 * @return Timestamp milliseconds(UNIX)
 */
static inline uint64_t mavlink_msg_drone_pos_att_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field x from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field z from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vx from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field vy from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field vz from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field roll from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pitch from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field rollspeed from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_rollspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitchspeed from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_pitchspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yawspeed from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_yawspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field ground_distance from drone_pos_att message
 *
 * @return 
 */
static inline float mavlink_msg_drone_pos_att_get_ground_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Decode a drone_pos_att message into a struct
 *
 * @param msg The message to decode
 * @param drone_pos_att C-struct to decode the message contents into
 */
static inline void mavlink_msg_drone_pos_att_decode(const mavlink_message_t* msg, mavlink_drone_pos_att_t* drone_pos_att)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    drone_pos_att->timestamp = mavlink_msg_drone_pos_att_get_timestamp(msg);
    drone_pos_att->x = mavlink_msg_drone_pos_att_get_x(msg);
    drone_pos_att->y = mavlink_msg_drone_pos_att_get_y(msg);
    drone_pos_att->z = mavlink_msg_drone_pos_att_get_z(msg);
    drone_pos_att->vx = mavlink_msg_drone_pos_att_get_vx(msg);
    drone_pos_att->vy = mavlink_msg_drone_pos_att_get_vy(msg);
    drone_pos_att->vz = mavlink_msg_drone_pos_att_get_vz(msg);
    drone_pos_att->roll = mavlink_msg_drone_pos_att_get_roll(msg);
    drone_pos_att->pitch = mavlink_msg_drone_pos_att_get_pitch(msg);
    drone_pos_att->yaw = mavlink_msg_drone_pos_att_get_yaw(msg);
    drone_pos_att->rollspeed = mavlink_msg_drone_pos_att_get_rollspeed(msg);
    drone_pos_att->pitchspeed = mavlink_msg_drone_pos_att_get_pitchspeed(msg);
    drone_pos_att->yawspeed = mavlink_msg_drone_pos_att_get_yawspeed(msg);
    drone_pos_att->ground_distance = mavlink_msg_drone_pos_att_get_ground_distance(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DRONE_POS_ATT_LEN? msg->len : MAVLINK_MSG_ID_DRONE_POS_ATT_LEN;
        memset(drone_pos_att, 0, MAVLINK_MSG_ID_DRONE_POS_ATT_LEN);
    memcpy(drone_pos_att, _MAV_PAYLOAD(msg), len);
#endif
}
