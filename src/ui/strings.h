/*
 * strings.c: default UI strings
 *
 * Copyright (C) 2017 Frank Morgner <frankmorgner@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _SC_STRINGS_H
#define _SC_STRINGS_H

#include "libopensc/pkcs15.h"

#ifdef ENABLE_NLS
#include <libintl.h>
#include <locale.h>
#define _(string) gettext(string)
#ifndef LOCALEDIR
#define LOCALEDIR "/usr/share/locale"
#endif
#else
#define _(string) string
#endif

#ifdef __cplusplus
extern "C" {
#endif

const char *ui_get_config_str(struct sc_context *ctx,
		struct sc_atr *atr, const char *flag_name, const char *ret_default);
void ui_localize_str(const char *preferred);

#ifdef __cplusplus
}
#endif

#endif
