

#ifndef _OLSRD_CFGPARSER_H
#define _OLSRD_CFGPARSER_H


#include "olsr_protocol.h"

struct olsr_msg_params
{
  float                    emission_interval;
  float                    validity_time;
};

struct if_config_options
{
  char                     *name;
  union olsr_ip_addr       ipv4_broadcast;
  int                      ipv6_addrtype;
  union olsr_ip_addr       ipv6_multi_site;
  union olsr_ip_addr       ipv6_multi_glbl;
  struct olsr_msg_params   hello_params;
  struct olsr_msg_params   tc_params;
  struct olsr_msg_params   mid_params;
  struct olsr_msg_params   hna_params;
  struct if_config_options *next;
};

struct olsr_if
{
  char                     *name;
  char                     *config;
  struct if_config_options *if_options;
  struct olsr_if           *next;
};

struct hna4_entry
{
  olsr_u32_t               net;
  olsr_u32_t               netmask;
  struct hna4_entry        *next;
};

struct hna6_entry
{
  union olsr_ip_addr       net;
  olsr_u16_t               prefix_len;
  struct hna6_entry        *next;
};

struct hyst_param
{
  float                    scaling;
  float                    thr_high;
  float                    thr_low;
};

struct plugin_entry
{
  char                     *name;
  struct plugin_entry      *next;
};

/*
 * The config struct
 */

struct olsrd_config
{
  olsr_u8_t                debug_level;
  olsr_u8_t                ip_version;
  olsr_u8_t                allow_no_interfaces;
  olsr_u16_t               tos;
  olsr_u8_t                auto_willingness;
  olsr_u8_t                fixed_willingness;
  olsr_u8_t                open_ipc;
  olsr_u8_t                use_hysteresis;
  struct hyst_param        hysteresis_param;
  float                    pollrate;
  olsr_u8_t                tc_redundancy;
  olsr_u8_t                mpr_coverage;
  struct plugin_entry      *plugins;
  struct hna4_entry        *hna4_entries;
  struct hna6_entry        *hna6_entries;
  struct olsr_if           *interfaces;
  struct if_config_options *if_options;
};


/*
 * Interface to parser
 */

struct olsrd_config *
olsrd_parse_cnf(char *);

void
olsrd_free_cnf(struct olsrd_config *);

void
olsrd_print_cnf(struct olsrd_config *);

int
olsrd_write_cnf(struct olsrd_config *, char *);

#endif
