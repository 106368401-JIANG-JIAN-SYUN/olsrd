/*
 * OLSR ad-hoc routing table management protocol
 * Copyright (C) 2003 Andreas T�nnesen (andreto@ifi.uio.no)
 *
 * This file is part of the olsr.org OLSR daemon.
 *
 * olsr.org is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * olsr.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with olsr.org; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * 
 * $Id: generate_msg.h,v 1.11 2004/11/10 14:40:37 kattemat Exp $
 *
 */

#ifndef _OLSR_GEN_MSG
#define _OLSR_GEN_MSG

#include "interfaces.h"

#define STDOUT_PULSE_INT 0.6

/* Functions */

void
generate_hello(void *);

void
generate_mid(void *);

void
generate_hna(void *);

void
generate_tc(void *);

void
generate_stdout_pulse(void *);

#endif
