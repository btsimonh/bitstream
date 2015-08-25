#ifndef __BITSTREAM_IETF_RTCP_FB_H__
# define __BITSTREAM_IETF_RTCP_FB_H__

# include <inttypes.h>

# define RTCP_PT_RTPFB             205
# define RTCP_PT_PSFB              206

static inline void rtcp_fb_set_fmt(uint8_t *p_rtcp, uint8_t fmt)
{
    p_rtcp[0] |= fmt & 0x1f;
}

static inline void rtcp_fb_set_ssrc_pkt_sender(uint8_t *p_rtcp_fb,
                                               uint32_t ssrc)
{
    p_rtcp_fb[0] = (ssrc >> 24) & 0xff;
    p_rtcp_fb[1] = (ssrc >> 16) & 0xff;
    p_rtcp_fb[2] = (ssrc >> 8) & 0xff;
    p_rtcp_fb[3] = ssrc & 0xff;
}

static inline void rtcp_fb_set_ssrc_media_src(uint8_t *p_rtcp_fb,
                                              uint32_t ssrc)
{
    p_rtcp_fb[4] = (ssrc >> 24) & 0xff;
    p_rtcp_fb[5] = (ssrc >> 16) & 0xff;
    p_rtcp_fb[6] = (ssrc >> 8) & 0xff;
    p_rtcp_fb[7] = ssrc & 0xff;
}

static inline void rtcp_fb_nack_set_packet_id(uint8_t *p_rtcp_fb_nack,
                                              uint16_t packet_id)
{
    p_rtcp_fb_nack[0] = (packet_id >> 8) & 0xff;
    p_rtcp_fb_nack[1] = packet_id & 0xff;
}

static inline void rtcp_fb_nack_set_bitmask_lost(uint8_t *p_rtcp_fb_nack,
                                                 uint16_t bitmask)
{
    p_rtcp_fb_nack[2] = (bitmask >> 8) & 0xff;
    p_rtcp_fb_nack[3] = bitmask & 0xff;
}

#endif /* !__BITSTREAM_IETF_RTCP_FB_H__ */
