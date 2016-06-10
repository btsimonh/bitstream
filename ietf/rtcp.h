#ifndef __BITSTREAM_IETF_RTCP_H__
# define __BITSTREAM_IETF_RTCP_H__

# include <inttypes.h>

# define RTCP_RTP_VERSION       2

static inline void rtcp_set_rtp_version(uint8_t *p_rtcp)
{
    p_rtcp[0] = RTCP_RTP_VERSION << 6;
}

static inline void rtcp_set_pt(uint8_t *p_rtcp, uint8_t pt)
{
    p_rtcp[1] = pt;
}

static inline void rtcp_set_length(uint8_t *p_rtcp,
                                      uint16_t length)
{
    p_rtcp[2] = length >> 8;
    p_rtcp[3] = length & 0xff;
}

#endif /* !__BITSTREAM_IETF_RTCP_H__ */
